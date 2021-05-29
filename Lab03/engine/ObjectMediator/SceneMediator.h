#pragma once

#include "ObjectMediator.h"

class SceneMediator : public ObjectMediator
{
public:
    SceneMediator()
        : ObjectMediator(std::make_shared<SceneTree>("root")){};
    const std::shared_ptr<Object> &getNode(const std::string &name) override;
    void appendChild(const std::string &target, const std::shared_ptr<Object> &object) override;
    ~SceneMediator() override = default;
};
