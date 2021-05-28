#include "QtEngineCreator.h"
#include "QtEngine.h"

std::shared_ptr<Engine> QtEngineCreator::create(const VecStr &loaders, const VecStr &savers)
{
    return std::make_shared<QtEngine>(loaders, savers, widget);
}
