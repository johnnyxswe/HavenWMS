#include "Core/Application.h"

#include "ScriptingModule.h"
#include "UILayer.h"


int main(int argc, char* argv[]) {
    Core::Application app(argc, argv);

    // Push layers in order (bottom to top)
    app.pushLayer(std::make_shared<App::ScriptingModule>());
    app.pushLayer(std::make_shared<App::UILayer>());

    app.run();

    return 0;
}
