#pragma once

#include "Layer.h"
#include "Window.h"

#include <glm/glm.hpp>

#include <string>
#include <memory>
#include <QApplication>
#include <QElapsedTimer>
#include "LayerStack.h"

namespace Core {
    struct ApplicationSpecification
    {
        std::string Name = "Application";
        WindowSpecification WindowSpec;
    };


    class Application : public QApplication
    {
        Q_OBJECT

    public:
        Application(int &argc, char **argv);
        virtual ~Application() = default;

        void pushLayer(std::shared_ptr<Layer> layer);
        void pushOverlay(std::shared_ptr<Layer> overlay);

        void run();

        static Application &instance() { return *instance_; }

    protected:
        bool event(QEvent *event) override;
        virtual void onUpdate(float deltaTime);

    private:
        void updateLayers(float deltaTime);

        LayerStack layerStack_;
        QElapsedTimer timer_;
        qint64 lastFrameTime_ = 0;

        static Application *instance_;
    };
}
