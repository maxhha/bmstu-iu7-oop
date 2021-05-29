#include "SceneTreeSaver.h"
#include <fmt/format.h>
#include <engine/Exception/Exceptions.h>

void SceneTreeSaver::save(const std::string &target,
                          const Object &obj)
{
    if (!obj.isSceneTree())
    {
        throw SaveSceneTreeException(
            __FILE__,
            __LINE__,
            fmt::format("Object {} is not a SceneTree", obj.getName()));
    };

    open(target);

    auto saver = createObjectSaverVisitor();
    const_cast<Object &>(obj).accept(*saver);

    close();
}
