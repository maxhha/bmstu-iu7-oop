#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#include <GLES2/gl2.h>

class Engine
{

public:
    explicit Engine(std::string canvas);
    void render();

private:
    EMSCRIPTEN_WEBGL_CONTEXT_HANDLE context;
};

#endif // __MANAGER_H__