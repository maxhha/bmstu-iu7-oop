#pragma once

#include <vector>
#include "../ObjectBuilder.h"

class SceneTreeBuilder : public ObjectBuilder
{
public:
    void appendChild(const std::shared_ptr<Object> &child) { children.push_back(child); }
    std::shared_ptr<Object> build() override;

    ~SceneTreeBuilder() = default;

private:
    std::vector<std::shared_ptr<Object>> children;
};