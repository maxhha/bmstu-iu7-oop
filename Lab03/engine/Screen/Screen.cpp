#include "Screen.h"

void Screen::render(const SceneTree &tree)
{
    renderer->render(tree);
}