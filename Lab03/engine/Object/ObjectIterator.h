#pragma once

#include <memory>
#include <vector>
#include <stack>
class Object;
class SceneTree;

class ObjectIterator
{
public:
    virtual bool hasNext() = 0;
    virtual std::shared_ptr<Object> getNext() = 0;
};

class DepthFirstObjectIterator : public ObjectIterator
{
public:
    DepthFirstObjectIterator(){};
    explicit DepthFirstObjectIterator(const SceneTree &obj);
    bool hasNext() override { return stack.size() > 0; };
    std::shared_ptr<Object> getNext() override;

private:
    std::stack<std::shared_ptr<Object>> stack;
};