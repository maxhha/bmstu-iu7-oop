#pragma once

#include "../ObjectLoader.h"
#include <engine/ObjectBuilder/ModelBuilder/ModelBuilder.h>

class ModelLoader : public ObjectLoader
{
public:
    std::shared_ptr<Object> load(const std::string &source) override;
    virtual ~ModelLoader() = default;

protected:
    ModelBuilder builder;

private:
    virtual void open(const std::string &source) = 0;
    virtual void close() = 0;

    virtual void loadObjectInfo() = 0;
    virtual void loadPoints() = 0;
    virtual void loadEdges() = 0;
};