import os

def generateHeightmap():
    if os.path.exists("./assets/data/fy20_adc_data_file_88_degrees.csv"):
        vertices = []
        with open("./assets/data/fy20_adc_data_file_88_degrees.csv") as f:
            count = 0
            for line in f:
                if count%100000 == 0:
                    temp = []
                    for value in line.rstrip().split(",")[0:3]:
                        temp.append(float(value))
                    vertices.append(temp)
                    
                count += 1
                
        string = "pragma once\n\nconst std::vector<Vertex> = {"
        for vertice in vertices:
            string += "{" + str(vertice[0]) + ", " + str(vertice[1]) + ", " + str(vertice[2]) + "}, "
            string += "{0.0f, 0.0f, 0.0f}, "
            string += "{0.0f" ", " + "0.0f}"
        string = string[:-2]
        string += "}\n"
        file = open("./include/heightmap.hpp", "w")
        file.write(string)
        file.close()

if __name__ == '__main__':
    generateHeightmap()
