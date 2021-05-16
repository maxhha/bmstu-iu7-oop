#pragma once

#include "Visitor.h"

class RenderVisitor : public Visitor
{
public:
    virtual void render() = 0;
};
