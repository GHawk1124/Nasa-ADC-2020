#pragma once

#include "./data.hpp"
#include <vector>
#include <cmath>

std::vector<float[2]> deleteInvalidNodes(float maxSlope) {
	std::vector<float[2]> newData;
	for (int i = 0; i < 1630729; i++) {
		if (originalData[i][2] <= maxSlope) {
			newData.push_back({originalData[i][0], originalData[i][1]});
		}
	}

	return newData;
}

bool floatEqual(float one[2], float two[2]) {
	return (fabs(one[0] - two[1]) <= 0.00000001) && (fabs(one[1] - two[1]) <= 0.00000001);
}

float distance(float one[2], float two[2]) {
	return sqrt((two[0] - one[0]) * (two[0] - one[0]) + (two[1] - one[1]) * (two[1] - one[1]));
}

// A* Pathfinding, the data is relatively grid shaped so it should work well
std::vector<float[2]> pathfind(float start[2], float end[2], float maxSlope) {
	std::vector<float[2]> validNodes = deleteInvalidNodes(maxSlope);
	float currentNode[2] = {start[0], start[1]};
	float currentG = 0;

	std::vector<float[2]> finalPath;

	while (!floatEqual(currentNode, end)) {
		// Get the closest nodes to the current node. This data isn't a grid
		std::vector<float[2]> closestNodes;
		// Yes I know it's inneficient
		for (int i = 0; i < validNodes.size(); i++) {
			for (int j = 0; j < closestNodes.size(); j++) {
				if (distance(validNodes[i], currentNode) < distance(closestNodes[j], currentNode)) {
					closestNodes.push_front({validNodes[i][0], validNodes[i][1]});
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
		currentNode = closestNodes[bestNodeIndex];
	}

	return finalPath;
}
