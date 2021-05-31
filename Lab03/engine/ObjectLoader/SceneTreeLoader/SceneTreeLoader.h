#pragma once

#include "../ObjectLoader.h"
#include <engine/ObjectBuilder/SceneTreeBuilder/SceneTreeBuilder.h>
#include <engine/ObjectBuilder/ModelBuilder/ModelBuilder.h>
#include <engine/ObjectBuilder/CameraBuilder/CameraBuilder.h>

class SceneTreeLoader : public ObjectLoader
{
public:
    std::shared_ptr<Object> load(const std::string &source) override;
    ~SceneTreeLoader() override = default;

protected:
    virtual void open(const std::string &source) = 0;
    virtual void close() = 0;

    virtual void loadObjectInfo() = 0;
    virtual bool hasMoreChildren() = 0;
    virtual void loadChild() = 0;

    SceneTreeBuilder builder;
};