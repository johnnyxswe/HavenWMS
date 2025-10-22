#pragma once

#include <QMainWindow>
#include <glm/glm.hpp>
#include <string>

namespace Core {

	struct WindowSpecification
	{
		std::string Title;
		uint32_t Width = 1280;
		uint32_t Height = 720;
		bool IsResizeable = true;
		bool VSync = true;
	};

	class Window : public QMainWindow
	{
		Q_OBJECT

	public:
		explicit Window(WindowSpecification  specification = WindowSpecification(), QWidget *parent = nullptr);
		~Window() override;

		void create();
		void destroy();

		void update();

		glm::vec2 getFramebufferSize();

		bool shouldClose() const;
		void handleButtonClick();

		[[nodiscard]] QWidget* GetHandle() const { return handle_.get(); }

		glm::ivec2 GetFramebufferSize() const;
		glm::ivec2 GetWindowSize() const;

	private:
		WindowSpecification m_Specification;
		std::unique_ptr<QWidget> handle_ = nullptr;

	};

}