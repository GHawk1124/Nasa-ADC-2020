from downloadAssets import *
from generateSphere import *
import os
import shutil

if __name__ == '__main__':
    if not (os.path.exists("./assets") and os.path.exists("./include/verts.hpp")):
        downloadAssets()
    generateSphere()
    if os.path.exists("./build"):
        shutil.rmtree("./build")
    os.mkdir("build")
    os.chdir("./build")
    os.system("cmake ..")
    os.system("make")
    os.system("./bin/apc")
    os.chdir("..")
