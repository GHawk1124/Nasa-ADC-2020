from urllib.request import urlopen
from zipfile import ZipFile
import os


if __name__ == '__main__':
    if not os.path.exists("./assets"):
        print("Creating Asset Directories")
        os.mkdir("./assets")
        os.mkdir("./assets/data")
        os.mkdir("./assets/textures")
    print("Checking if data has been downloaded...")
    if os.path.isfile("./assets/data/fy20_adc_data_file_88_degrees.csv"):
        print("Data Already Downloaded")
    else:
        try:
            print("Data not downloaded.")
            zipurl = 'https://www.nasa.gov/sites/default/files/atoms/files/fy20_adc_data_file_88_degrees.zip'
            print("Url: ", zipurl)
            print("Opening Url...")
            zipresp = urlopen(zipurl)
            print("Writing to temporary file...")
            tempzip = open("/tmp/tempfile.zip", "wb")
            tempzip.write(zipresp.read())
            tempzip.close()
            print("Extracting file...")
            zf = ZipFile("/tmp/tempfile.zip")
            zf.extractall(path='./assets/data')
            print("File Written.")
            zf.close()
            print("Done.")
        except error as e:
            print(e)

    print("Checking if texture has been downloaded...")
    if os.path.isfile("./assets/textures/texture.png"):
        print("Texture already Downloaded")
    else:
        try:
            print("Texture not downloaded.")
            pngurl = 'https://www.nasa.gov/sites/default/files/thumbnails/image/fy20_adc_lunar_terrain_texture.png'
            print("Url: ", pngurl)
            print("Opening Url...")
            file = urlopen(pngurl)
            print("Writing to png file...")
            png = open("./assets/textures/texture.png", "wb")
            png.write(file.read())
            png.close()
            print("File Written.")
            print("Done")
        except error as e:
            print(e)

    print("Program Successful")
