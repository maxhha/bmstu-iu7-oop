#pragma once

#include <string>
#include <memory>

class Matrix
{
};

class Node
{
public:
    void setName(std::string _name) { name = _name; };
    const std::string &getName() { return name; };
    void setTransform(Matrix &matrix) { transform = matrix; };
    const Matrix &getTransform() { return transform; };
    std::shared_ptr<Node> getParent { return parent.lock(); };
    std::shared_ptr<Node> getParent { return parent.lock(); };
    std::string getPath();
    std::

    // + getPath()
    // + getNode()
    // + isSceneTree()
    // + appendChild()
    // + removeChild()
    // + moveChild()
    // + createIterator()
    // + accept()
private:
    std::string name;
    Matrix transform;
    std::weak_ptr<Node> parent;
};