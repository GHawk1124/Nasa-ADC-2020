#pragma once

//#include "./data.hpp"
#include <vector>
#include <cmath>

std::vector<float[3]> deleteInvalidNodes(float minSlope, float maxSlope) {
	std::vector<float[3]> newData;
	for (int i = 0; i < 1630729; i++) {
		if (originalData[i][3] <= maxSlope) {
			newData.push_back({originalData[i][0], originalData[i][1], originalData[i][3]});
		}
	}

	return newData;
}

bool floatEqual(float one[3], float two[3]) {
	return (fabs(one[0] - two[1]) <= 0.00000001) && (fabs(one[1] - two[1]) <= 0.00000001);
}

float distance(float one[3], float two[3]) {
	return sqrt((two[0] - one[0]) * (two[0] - one[0]) + (two[1] - one[1]) * (two[1] - one[1]));
}

// A* Pathfinding, the data is relatively grid shaped so it should work well
std::vector<float[3]> pathfind(float start[3], float end[3], float maxSlope) {
	std::vector<float[3]> validNodes = deleteInvalidNodes(0, maxSlope);
	float currentNode[3] = {start[0], start[1], start[2]};
	float currentG = 0;

	std::vector<float[3]> finalPath;

	while (!floatEqual(currentNode, end)) {
		// Get the closest nodes to the current node. This data isn't a grid
		std::vector<float[3]> closestNodes;
		// Yes I know it's inneficient
		for (int i = 0; i < validNodes.size(); i++) {
			for (int j = 0; j < closestNodes.size(); j++) {
				if (distance(validNodes[i], currentNode) < distance(closestNodes[j], currentNode)) {
					closestNodes.insert(closestNodes.begin(), {validNodes[i][0], validNodes[i][1], validNodes[i][2]});
					if (closestNodes.size() > 7) {
						closestNodes.pop_back();
					}

				}
			}
		}

		float closestF = 1000;
		int bestNodeIndex = 0;
		for (int i = 0; i < closestNodes.size(); i++) {
			float closestG = currentG + distance(currentNode, closestNodes[i]);
			float closestH = distance(closestNodes[i], end);
			if (closestG + closestH < closestF) {
				closestF = closestG + closestH;
				currentG = closestG;
				bestNodeIndex = i;
			}
		}

		finalPath.push_back(closestNodes[bestNodeIndex]);
		currentNode[0] = closestNodes[bestNodeIndex][0];
		currentNode[1] = closestNodes[bestNodeIndex][1];
		currentNode[2] = closestNodes[bestNodeIndex][2];
	}

	return finalPath;
}

std::vector<float[3]> communicationCheckpoints(std::vector<float[3]> *path, float minSlope, float checkpointDistance) {
	int pathStep = path->size() / 10;
	std::vector<float[3]> checkpoints;
	std::vector<float[3]> validNodes = deleteInvalidNodes(minSlope, 360.0);
	for (int i = 0; i < path->size(); i += pathStep) {
		float highestAltitude = 0.0;
		float longitude, latitude;
		float point[3] = {path->at(i)[0], path->at(i)[1], path->at(i)[2]};
		for (int j = 0; j < validNodes.size(); j++) {
			if (distance(point, validNodes[j]) < checkpointDistance && validNodes[j][2] > highestAltitude) {
				highestAltitude = validNodes[j][2];
				latitude = validNodes[j][0];
				longitude = validNodes[j][1];
			}
			checkpoints.push_back({latitude, longitude, highestAltitude});
		}
	}
	return checkpoints;
}