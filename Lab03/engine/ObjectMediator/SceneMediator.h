#pragma once

#include "ObjectMediator.h"

class SceneMediator : public ObjectMediator
{
public:
    SceneMediator()
        : ObjectMediator(std::make_shared<SceneTree>("root")){};

    std::shared_ptr<Object> get(const std::string &name) override;
    void rename(const std::string &target, const std::string &newName) override;
    void remove(const std::string &target) override;
    void transform(const std::string &target, const Transformation &transform) override;

    void appendChild(const std::string &target, const std::shared_ptr<Object> &object) override;

    ~SceneMediator() override = default;
};
