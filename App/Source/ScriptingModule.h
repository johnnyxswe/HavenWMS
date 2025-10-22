//
// Created by Johnny Gonzales on 10/22/25.
//

#pragma once
#include "Core/Layer.h"
#include <QMainWindow>
#include <QDebug>

namespace App {
    class ScriptingModule : public Core::Layer
    {
    public:
        ScriptingModule() : Layer("Scripting Module")
        {
        }

        void onAttach() override
        {
            qDebug() << "Scripting Module Layer attached";
        }

        void onUpdate(float deltaTime) override
        {
        }
    };
}
