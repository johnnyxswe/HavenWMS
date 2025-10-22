#include "Application.h"
#include <iostream>
#include <QTimer>

namespace Core {
    Application *Application::instance_ = nullptr;

    Application::Application(int &argc, char **argv)
        : QApplication(argc, argv)
    {
        instance_ = this;
        timer_.start();
    }

    void Application::pushLayer(std::shared_ptr<Layer> layer)
    {
        layerStack_.pushLayer(layer);
    }

    void Application::pushOverlay(std::shared_ptr<Layer> overlay)
    {
        layerStack_.pushOverlay(overlay);
    }

    void Application::run()
    {
        // Set up a timer for continuous updates
        QTimer *updateTimer = new QTimer(this);
        connect(updateTimer, &QTimer::timeout, this, [this]()
        {
            qint64 currentTime = timer_.elapsed();
            float deltaTime = (currentTime - lastFrameTime_) / 1000.0f;
            lastFrameTime_ = currentTime;

            updateLayers(deltaTime);
            onUpdate(deltaTime);
        });
        updateTimer->start(16); // ~60 FPS

        exec();
    }

    void Application::updateLayers(float deltaTime)
    {
        for (auto &layer: layerStack_)
        {
            if (layer->isEnabled())
            {
                layer->onUpdate(deltaTime);
            }
        }
    }

    bool Application::event(QEvent *event)
    {
        // Propagate events through layers in reverse order
        for (auto it = layerStack_.rbegin(); it != layerStack_.rend(); ++it)
        {
            if ((*it)->isEnabled() && (*it)->onEvent(event))
            {
                return true; // Event was handled
            }
        }

        return QApplication::event(event);
    }

    void Application::onUpdate(float deltaTime)
    {
        // Override this in your derived application class
    }
}
