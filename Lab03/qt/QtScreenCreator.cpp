#include "QtScreenCreator.h"
#include "QtRenderVisitor.h"

std::shared_ptr<Screen> QtScreenCreator::createScreen(int x, int y, int width, int height)
{
    return std::make_shared<Screen>(
        x, y, width, height,
        std::make_unique<QtRenderVisitor>(scene));
}