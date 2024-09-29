# Kiwi

## Building

For detailed info for unlisted platforms, please refer to [vulkan development environment guide](https://vulkan-tutorial.com/Development_environment)

### Visual Studio 2017+ (Windows) x64

- Make sure your system supports Vulkan.
- Install dependencies by vcpkg or optionally install and link them manually
  - Install(Optional) x64 [GLFW](https://www.glfw.org/download.html) binaries
  - Install(Optional) [GLM](https://github.com/g-truc/glm/releases)
  - Install(Optional) [VulkanSDK](https://vulkan.lunarg.com/)
  - Install(Optional) [GLAD](https://glad.dav1d.de/#language=c&specification=gl&api=gl%3D4.6&api=gles1%3Dnone&api=gles2%3Dnone&api=glsc2%3Dnone&profile=core&loader=on)

  - Make sure C/C++ > Language > C++ Language Standard is set to `/std:c++17` or latest
  - Make sure you're building in x64 mode
