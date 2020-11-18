#pragma once

#include <math.h>
#include "glm/glm.hpp"
#include <stdio.h>

#define PI 3.141592653589793238462643
#define LUNAR_RADIUS 1737.4

const glm::vec3 posEarth (361000.0f, 0.0f, -42100.0f);

// pos in Lat,Long,Height
float calcElevation(glm::vec3 posA, glm::vec3 posB) {
    const float r = posA.z + LUNAR_RADIUS;
    float x_ab = r*cos(posA.x)*cos(posA.y) - posB.x;
    float y_ab = r*cos(posA.x)*sin(posA.y) - posB.y;
    float z_ab = r*sin(posA.x) - posB.z;
    float range = sqrt(pow(x_ab, 2) + pow(y_ab, 2) + pow(z_ab, 2));
    float rz = x_ab*cos(posA.x)*cos(posA.y)+y_ab*cos(posA.x)*sin(posA.y)+z_ab*sin(posA.x);
    return asin(rz/range);
}

// pos in Lat,Long,Height
float calcZenith(glm::vec3 posA, glm::vec3 posB) {
    return 90 - abs(calcElevation(posA, posB));
}

// pos in Lat/Long
float calcAzimuth(glm::vec2 posA, glm::vec2 posB) {
    return atan2((sin(posB.x-posA.x)*cos(posB.y)), ((cos(posA.y)*sin(posB.y))-(sin(posA.y)*cos(posB.y)*cos(posB.x-posA.x)))) * 180 / PI;
}

// pos xyz
float calcElevationCartesian(glm::vec3 posA, glm::vec3 posB) {
    float dxz = sqrt(pow((posB.x - posA.x), 2) + pow((posB.z - posA.z), 2));
    float dy = abs(posB.y - posA.y);
    return atan(dy/dxz) * 180 / PI;
}

// pos in xyz
float calcZenithCartesian(glm::vec3 posA, glm::vec3 posB) {
    return 90 - abs(calcElevation(posA, posB));
}

// pos in xyz
float calcAzimuthCartesian(glm::vec3 posA, glm::vec3 posB) {
    float dz = abs(posB.z - posA.z);
    float dx = abs(posB.x - posA.x);
    return 360 - (atan(dz/dx) * 180 / PI);
}