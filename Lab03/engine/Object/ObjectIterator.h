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

protected:
    const std::shared_ptr<std::vector<std::shared_ptr<Object>>> getChildren(const SceneTree &tree);
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

class PathObjectIterator : public ObjectIterator
{
public:
    PathObjectIterator(){};
    explicit PathObjectIterator(const SceneTree &tree);
    bool hasNext() override { return stack.size() > 1; };
    std::shared_ptr<Object> getNext() override;

private:
    std::vector<std::stack<std::shared_ptr<Object>>> stack;
    void process();
    int pathI;
};