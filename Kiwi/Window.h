#pragma once

#include "Common.h"

namespace Kiwi {

	class A {

	};

	class AbstractWindow {
	private:
		virtual void SetWindowSize(uint16 height, uint16 width) = 0;
	public:
		uint16 Height;
		uint16 Width;
		const char* Title;

		MProperty(uint16, Height);
		MProperty(uint16, Width);
		MProperty(const char*, Title);

		virtual bool ShouldClose() const = 0;
		virtual void Initialize() = 0;
		virtual void ServeBuffer() = 0;

		virtual void Update() = 0;

		virtual ~AbstractWindow() = default;
	};

	class GLWindow : public AbstractWindow {

		private:
			GLFWwindow* WindowHandle;
			static void ResizeCallback(GLFWwindow* _, int width, int height) {
				FocusedWindow->SetWindowSize(height, width);
			}

			inline static GLWindow* FocusedWindow;

			void SetWindowSize(uint16 height, uint16 width) override {
				SetWidth(width); SetHeight(height);
				glViewport(0, 0, width, height);
			}

		public:
			bool inline ShouldClose() const override { return glfwWindowShouldClose(WindowHandle); }

			void ServeBuffer() override { 
				glClear(GL_COLOR_BUFFER_BIT);
				glfwSwapBuffers(WindowHandle); 
			}

			void Update() override {
				ServeBuffer();
				glfwPollEvents();
			}

			void Initialize() override {
				WindowHandle = glfwCreateWindow(GetWidth(), GetHeight(), GetTitle(), nullptr, nullptr);
				if (WindowHandle == nullptr) {
					glfwTerminate();
					throw std::runtime_error("OpenGL window initialization fault");
				}
				FocusedWindow = this;
				glfwMakeContextCurrent(WindowHandle);
				gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
				glViewport(0, 0, GetWidth(), GetHeight());

				glfwSetFramebufferSizeCallback(WindowHandle, ResizeCallback);

			}

			GLWindow(uint16 width, uint16 height, const char* title) {
				SetWidth(width);
				SetHeight(height);
				SetTitle(title);

				Initialize();
			}
	};

}