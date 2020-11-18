# Nasa-ADC-2020-RMHS

Submission to the Nasa ADC 2020

## Description

This project utilizes low level libraries such as the windows api, wayland, vulkan, etc. The point of this was to make the app run as efficiently as possible, while being as small as possible. The moonData given to us is not currently contained in the project because we had some difficulty getting it to the proper format, so for now the texture is random. The data is stored in an rgb ktx texture with red indicating height, making it an extremely efficient storage and loading method for the GPU. The app has a built in GUI with options, sliders, and headers. The first person camera is controlled with W, A, S, and D keys and a mouse Left Click. For now the pathfinding algorithm is in the program but is not being used due to the issue with the texture. We plan to resolve these issues to make the app fully functional.

## Screenshots

## Building

Project files for any IDE can be generated through cmake.
```
git clone --recursive https://github.com/GHawk1124/Nasa-ADC-2020-RMHS.git
cd Nasa-ADC-2020-RMHS/
```

### Windows

Use the provided CMakeLists.txt with [CMake](https://cmake.org) to generate a build configuration for your favorite IDE or compiler, e.g.:
```
cmake . -G "Visual Studio 14 2015 Win64"
```

### Mac

Use the provided CMakeLists.txt with [CMake](https://cmake.org) to generate a build configuration for your favorite IDE or compiler, e.g.:
```
cmake . -G "Xcode"
```

### Linux

Use the provided CMakeLists.txt with [CMake](https://cmake.org) to generate a build configuration for your favorite IDE or compiler, e.g.:
```
cmake .
make
```

## Acknowledgements
Huge thanks to Sascha Williams for providing an amazing place to start with his [Vulkan Examples](https://github.com/SaschaWillems/Vulkan)!
Huge thanks to LunarG for creating this wonderful software for us to use and their helpful [Vulkan Tutorial](https://vulkan-tutorial.com/)!
Thanks to our Mentors for helping us have this opportunity!
Finally, thanks to Nasa for hosting this event to help further our knowledge!