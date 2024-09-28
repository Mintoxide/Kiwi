# Kiwi

## Building

For detailed info for unlisted platforms, please refer to [vulkan development environment guide](https://vulkan-tutorial.com/Development_environment)

### Visual Studio 2017+ (Windows) x64

- Make sure your system supports Vulkan.
-  Install x64 [GLFW](https://www.glfw.org/download.html) binaries
- Install [GLM](https://github.com/g-truc/glm/releases)
- Install [VulkanSDK](https://vulkan.lunarg.com/)
- In Visual Studio project properties for *all configurations*:
  - C/C++ > General > Additional Include Directories:
    - Add reference to VulkanSDK `Include` folder
    - Add reference to `glm` folder
    - Add reference to glfw `include` folder
  - Linker > General > Additional Library Directories:
    - Add reference to VulkanSDK `Lib` folder
    - Add reference to glfw `lib-vcXXXX` folder, where `XXXX` is your VS version
  - Make sure C/C++ > Language > C++ Language Standard is set to `/std:c++17` or latest
  - Make sure you're building in x64 mode
