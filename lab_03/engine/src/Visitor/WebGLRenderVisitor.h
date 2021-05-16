#pragma once

#include <string>
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#include <GLES2/gl2.h>

#include "RenderVisitor.h"

class WebGLRenderVisitor : public RenderVisitor
{
public:
    explicit WebGLRenderVisitor(std::string canvas);

    void visitSceneTree(SceneTree &sceneTree) override;
    void visitCamera(Camera &camera) override;
    void visitModel(Model &model) override;
    void render() override;
private:
    EMSCRIPTEN_WEBGL_CONTEXT_HANDLE context;
};
