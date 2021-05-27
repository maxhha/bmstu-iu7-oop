#pragma once

#include <memory>
#include <engine/Object/SceneTree.h>
class SceneMediator
{
public:
    SceneMediator()
        : tree(std::make_shared<SceneTree>("root", Transformation())){};
    void appendChild(const std::string &target, std::shared_ptr<Object> object);

private:
    std::shared_ptr<SceneTree> tree;
};