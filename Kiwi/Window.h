#pragma once

#include "Common.h"

namespace Kiwi {

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

			void SetWindowSize(uint16 height, uint16 width) override;

		public:
			bool inline ShouldClose() const override { return glfwWindowShouldClose(WindowHandle); }

			void ServeBuffer() override;

			void Update() override;

			void Initialize() override;

			GLWindow(uint16 width, uint16 height, const char* title);
	};

}