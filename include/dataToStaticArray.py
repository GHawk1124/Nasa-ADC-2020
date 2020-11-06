total_lines = 0
with open("../assets/data/fy20_adc_data_file_high_precision.csv") as datafile:
	final = []
	for line in datafile.readlines():
		intermediary = []
		for i in line.strip().split(','):
			intermediary.append(float(i))
		final.append(intermediary)
		total_lines += 1

string = "#pragma once\n\nconst float originalData[" + str(total_lines) + "][4] = {\n"
for datapoint in final:
	string += "\t{" + "{}, {}, {}, {}".format(datapoint[0], datapoint[1], datapoint[2], datapoint[3]) + "},\n"
string += "};"

with open("data.hpp", "w") as output:
	output.write(string)
