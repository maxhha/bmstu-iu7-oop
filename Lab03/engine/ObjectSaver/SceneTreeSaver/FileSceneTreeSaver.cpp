#include "FileSceneTreeSaver.h"
#include "FileObjectSaverVisitor.h"

void FileSceneTreeSaver::open(const std::string &target)
{
    filestream.open(target, std::ios::out);
}

std::shared_ptr<ObjectSaverVisitor> FileSceneTreeSaver::createObjectSaverVisitor()
{
    return std::make_shared<FileObjectSaverVisitor>(filestream);
}

void FileSceneTreeSaver::close()
{
    filestream.close();
}