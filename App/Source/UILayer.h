#pragma once

#include <QMainWindow>
#include <stdint.h>
#include "HomePage.h"
#include "Core/Layer.h"

namespace App {
    class UILayer : public Core::Layer {
    public:
        UILayer() : Core::Layer("UI Layer") {}

        void onAttach() override {
            qDebug() << "UI Layer attached";
            m_homePage = new HomePage();
            m_homePage->show();
        }

        void onDetach() override {
            qDebug() << "UI Layer detached";
            if (m_homePage) {
                m_homePage->close();
                delete m_homePage;
                m_homePage = nullptr;
            }
        }

        void onUpdate(float deltaTime) override {
            // Update UI logic here if needed
            // For example, you could update animations or poll for state changes
        }

        bool onEvent(QEvent* event) override {
            // Handle UI-specific events
            // The HomePage will handle its own events automatically
            // You can intercept specific events here if needed
            return false;
        }

        HomePage* getHomePage() const { return m_homePage; }

    private:
        HomePage* m_homePage = nullptr;
    };
}
