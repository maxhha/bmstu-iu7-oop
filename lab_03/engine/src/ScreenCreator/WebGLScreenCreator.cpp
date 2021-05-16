#include "WebGLScreenCreator.h"
#include "Visitor/WebGLRenderVisitor.h"

std::shared_ptr<Screen> WebGLScreenCreator::createScreen(int x, int y, int width, int height)
{
    auto renderVisitor = std::shared_ptr<RenderVisitor>(new WebGLRenderVisitor(canvas));
    return std::shared_ptr<Screen>(new Screen(
        renderVisitor,
        x,
        y,
        width,
        height));
}
