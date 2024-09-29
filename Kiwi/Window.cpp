#include "Window.h"

namespace Kiwi {

	void GLWindow::SetWindowSize(uint16 height, uint16 width) {
		SetWidth(width); SetHeight(height);
		glViewport(0, 0, width, height);
	}

	void GLWindow::ServeBuffer() {
		glfwSwapBuffers(WindowHandle);
	}

	void GLWindow::Update() {
		ServeBuffer();
		glfwPollEvents();
	}

	void GLWindow::Initialize() {
		WindowHandle = glfwCreateWindow(GetWidth(), GetHeight(), GetTitle(), nullptr, nullptr);
		if (WindowHandle == nullptr) {
			glfwTerminate();
			throw std::runtime_error("OpenGL window initialization failure");
		}
		FocusedWindow = this;
		glfwMakeContextCurrent(WindowHandle);
		glfwSetFramebufferSizeCallback(WindowHandle, ResizeCallback);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			throw std::runtime_error("glad initialization failure");
		}

		glViewport(0, 0, GetWidth(), GetHeight());
	}

	GLWindow::GLWindow(uint16 width, uint16 height, const char* title) {
		SetWidth(width);
		SetHeight(height);
		SetTitle(title);

		Initialize();
	}
}
