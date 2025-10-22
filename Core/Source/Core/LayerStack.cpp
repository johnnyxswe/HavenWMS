//
// Created by Johnny Gonzales on 10/22/25.
//

#include "LayerStack.h"

namespace Core {
    LayerStack::~LayerStack()
    {
        for (auto &layer: layers_)
        {
            layer->onDetach();
        }
    }

    void LayerStack::pushLayer(std::shared_ptr<Layer> layer)
    {
        layers_.insert(layerInsertIndex_, layer);
        layerInsertIndex_++;
        layer->onAttach();
    }

    void LayerStack::pushOverlay(std::shared_ptr<Layer> overlay)
    {
        layers_.push_back(overlay);
        overlay->onAttach();
    }

    void LayerStack::popLayer(std::shared_ptr<Layer> layer)
    {
        auto it = std::find(layers_.begin(), layers_.begin() + layerInsertIndex_, layer);
        if (it != layers_.begin() + layerInsertIndex_)
        {
            layer->onDetach();
            layers_.erase(it);
            layerInsertIndex_--;
        }
    }

    void LayerStack::popOverlay(std::shared_ptr<Layer> overlay)
    {
        auto it = std::find(layers_.begin() + layerInsertIndex_, layers_.end(), overlay);
        if (it != layers_.end())
        {
            overlay->onDetach();
            layers_.erase(it);
        }
    }
}
