from downloadAssets import *
from generateSphere import *
import os

if __name__ == '__main__':
    if not (os.path.exists("./assets")):
        downloadAssets()
    if not (os.path.exists("./include/verts.hpp")):
        generateSphere()
    if ((os.path.exists("./shaders/vert.spv")) and (os.path.exists("./shaders/frag.spv"))):
        os.remove("./shaders/vert.spv")
        os.remove("./shaders/frag.spv")
        os.system("glslc ./shaders/shader.vert -o ./shaders/vert.spv")
        os.system("glslc ./shaders/shader.frag -o ./shaders/frag.spv")
    else:
        os.system("glslc ./shaders/shader.vert -o shaders/vert.spv")
        os.system("glslc ./shaders/shader.frag -o shaders/frag.spv")
    if os.path.exists("./build"):
        os.chdir("./build")
        if os.path.exists("./build/CMakeFiles"):
            os.system("make")
        else:
            os.system("cmake -DCMAKE_BUILD_TYPE=debug ..")
            os.system("make")
        os.system("./bin/apc")
        os.chdir("..")
    else:
        os.mkdir("build")
        os.chdir("./build")
        os.system("cmake -DCMAKE_BUILD_TYPE=debug ..")
        os.system("make")
        os.system("./bin/apc")
        os.chdir("..")
