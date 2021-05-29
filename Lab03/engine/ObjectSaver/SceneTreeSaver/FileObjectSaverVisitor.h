#pragma once

#include <ostream>
#include <yaml-cpp/emitter.h>
#include <engine/Visitor/ObjectSaverVisitor.h>

class FileObjectSaverVisitor : public ObjectSaverVisitor
{
public:
    FileObjectSaverVisitor() = delete;
    FileObjectSaverVisitor(std::ostream &_out) : out(_out){};

    void visitSceneTree(SceneTree &sceneTree) override;
    void visitCamera(Camera &camera) override;
    void visitModel(Model &model) override;

private:
    YAML::Emitter out;
};