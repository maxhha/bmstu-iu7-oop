#pragma once

#include <iostream>
#include <fstream>
#include "SceneTreeSaver.h"

class FileSceneTreeSaver : public SceneTreeSaver
{
    public:
        ~FileSceneTreeSaver() override = default;

    protected:
        void open(const std::string &target);
        std::shared_ptr<ObjectSaverVisitor> createObjectSaverVisitor() override;
        void close() override;

    private:
        std::ofstream filestream;
};