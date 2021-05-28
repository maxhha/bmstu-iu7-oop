#pragma once

#include <string>
#include <memory>

#include <engine/Object/Object.h>

class ObjectBuilder
{
public:
    void setName(const std::string &_name) { name = _name; };

    virtual std::shared_ptr<Object> build() = 0;

    virtual ~ObjectBuilder() = default;

protected:
    std::string name;
};