#include "Window.h"

#include <iostream>
#include <utility>
#include <assert.h>
#include <QLabel>
#include <QBoxLayout>
#include <QPushButton>
#include <QMainWindow>
#include <QApplication>

namespace Core {

	Window::Window(WindowSpecification  specification, QWidget *parent)
		:  m_Specification(std::move(specification)), QMainWindow(parent)
	{
		create();
	}

	Window::~Window()
	{
		destroy();
	}

	void Window::create()
	{
		// Create central widget
		auto centralWidget = new QWidget(this);
		setCentralWidget(centralWidget);

		handle_ = std::make_unique<QWidget>(centralWidget);
		if (!handle_)
		{
			std::cerr << "Failed to create Qt window!\n";
			assert(false);
		}

		// Create layout
		auto *layout = new QVBoxLayout(centralWidget);

		// Create widgets
		auto label = new QLabel("Hello from CLion!", this);
		auto *button = new QPushButton("Click Me", this);

		// Add widgets to layout
		layout->addWidget(label);
		layout->addWidget(button);

		// Connect signal to slot
		connect(button, &QPushButton::clicked, this, &Window::handleButtonClick);

		// Window properties
		setWindowTitle("Qt with CLion");
		resize(400, 300);
	}

	void Window::destroy()
	{
		if (handle_)
			handle_->close();

		handle_ = nullptr;
	}

	void Window::update()
	{
	}

	glm::vec2 Window::getFramebufferSize()
	{
		// int width, height;
		// glfwGetFramebufferSize(m_Handle, &width, &height);
		// return { width, height };
	}

	bool Window::shouldClose() const
	{
		// return glfwWindowShouldClose(m_Handle) != 0;
	}

	void Window::handleButtonClick() {
		// Handle button click
		setWindowTitle("Button Clicked!");
	}

}