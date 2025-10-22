//
// Created by Johnny Gonzales on 10/22/25.
//

#pragma once


#include <QVector>
#include <memory>
#include "Layer.h"

namespace Core {
    class LayerStack
    {
    public:
        LayerStack() = default;
        ~LayerStack();

        void pushLayer(std::shared_ptr<Core::Layer> layer);
        void pushOverlay(std::shared_ptr<Core::Layer> overlay);
        void popLayer(std::shared_ptr<Core::Layer> layer);
        void popOverlay(std::shared_ptr<Core::Layer> overlay);

        auto begin() { return layers_.begin(); }
        auto end() { return layers_.end(); }
        auto rbegin() { return layers_.rbegin(); }
        auto rend() { return layers_.rend(); }

    private:
        QVector<std::shared_ptr<Layer> > layers_;
        int layerInsertIndex_ = 0;
    };
}
