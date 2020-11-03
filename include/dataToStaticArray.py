from math import sin, cos, atan, tan

def dataToStaticArray(flattening, radius):
    with open("../assets/data/fy20_adc_data_file_88_degrees.csv") as datafile:
        for line in datafile.readlines():
            data = [float(i) for i in line.strip().split(',')]
            lat = data[0]
            lon = data[1]
            alt = data[2]
            ls = atan((1 - flattening) ** 2 * tan(alt))
            x = radius * cos(ls) * cos(lon) + alt * cos(lat) * cos(lon)
            y = radius * cos(ls) * sin(lon) + alt * cos(lat) * sin(lon)
            z = radius * sin(ls) + alt * sin(lat)
            print("{{" + "{}, {}, {}".format(x, y, z) + "}, {0.0, " + str(data[3] / 360) + ", 0.0}, {0.0, 0.0}" + "},")


dataToStaticArray(0, 100)
