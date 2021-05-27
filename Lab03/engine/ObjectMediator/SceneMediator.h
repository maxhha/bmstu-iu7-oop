#pragma once

#include "ObjectMediator.h"

class SceneMediator : public ObjectMediator
{
public:
    SceneMediator()
        : ObjectMediator(std::make_shared<SceneTree>("root", Transformation())){};
    void appendChild(const std::string &target, const std::shared_ptr<Object> &object) override;
    ~SceneMediator() override = default;
};