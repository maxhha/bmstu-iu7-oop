#pragma once

#include "../ObjectSaver.h"
#include <engine/Visitor/ObjectSaverVisitor.h>

class SceneTreeSaver : public ObjectSaver
{
public:
    void save(
        const std::string &target,
        const Object &obj) override;

protected:
    virtual void open(const std::string &target) = 0;
    virtual std::shared_ptr<ObjectSaverVisitor> createObjectSaverVisitor() = 0;
    virtual void close() = 0;
};