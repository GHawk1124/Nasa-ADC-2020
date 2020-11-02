#include "glm/glm.hpp"
#include <vector>
#include <fstream>
#include <string>

std::vector<glm::vec3> dataToSphere(float radius, float flattening) {
    std::vector<glm::vec3> data;
    std::ifstream file("../data/fy_nasa_adc_88_degrees.csv", std::ios::in);

    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            std::stringstream stream(line);
            std::string tmp;
            std::vector<float> info;
            while (std::getline(stream, tmp, ',')) {
                info.push_back(std::stod(tmp));
            }
            float lat = info[0];
            float lon = info[1];
            float alt = info[2];
            float ls = atan((1 - flattening) ** 2 * tan(lat))
            float x = radius * cos(ls) * cos(lon) + alt * cos(lat) * cos(lon);
            float y = radius * cos(ls) * sin(lon) + alt * cos(lat) * sin(lon);
            float z = rad * sin(ls) + alt * sin(lat);
            data.push_back(glm::vec3(x, y, z));
        }
    }
    file.close();
    return data;
}

