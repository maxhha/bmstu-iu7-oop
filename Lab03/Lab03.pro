QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    engine/EngineSolution/EngineSolution.cpp \
    engine/Exception/Exception.cpp \
    engine/Engine/Engine.cpp \
    qt/QtEngine.cpp \
    engine/ObjectLoaderSolution/ObjectLoaderSolution.cpp \
    engine/ObjectLoader/ModelLoader/FileModelLoader.cpp \
    engine/ObjectLoader/ModelLoader/ModelLoader.cpp \
    engine/ObjectBuilder/ModelBuilder/ModelBuilder.cpp \
    engine/Transformation/Transformation.cpp \
    engine/ObjectMediator/SceneMediator.cpp \
    engine/Object/ObjectIterator.cpp \
    engine/ScreenManager/ScreenManager.cpp \
    engine/Screen/Screen.cpp \
    qt/QtScreenCreator.cpp \
    qt/QtRenderVisitor.cpp \
    engine/Object/SceneTree/SceneTree.cpp \
    engine/Visitor/Visitor.cpp \
    qt/QtEngineCreator.cpp \
    engine/Command/Commands.cpp \
    engine/ObjectSaver/SceneTreeSaver/SceneTreeSaver.cpp \
    engine/ObjectSaver/SceneTreeSaver/FileSceneTreeSaver.cpp \
    engine/ObjectSaver/SceneTreeSaver/FileObjectSaverVisitor.cpp \
    engine/ObjectSaverSolution/ObjectSaverSolution.cpp \
    libs/yaml-cpp/src/binary.cpp \
    libs/yaml-cpp/src/convert.cpp \
    libs/yaml-cpp/src/depthguard.cpp \
    libs/yaml-cpp/src/directives.cpp \
    libs/yaml-cpp/src/emit.cpp \
    libs/yaml-cpp/src/emitfromevents.cpp \
    libs/yaml-cpp/src/emitter.cpp \
    libs/yaml-cpp/src/emitterstate.cpp \
    libs/yaml-cpp/src/emitterutils.cpp \
    libs/yaml-cpp/src/exceptions.cpp \
    libs/yaml-cpp/src/exp.cpp \
    libs/yaml-cpp/src/memory.cpp \
    libs/yaml-cpp/src/node.cpp \
    libs/yaml-cpp/src/nodebuilder.cpp \
    libs/yaml-cpp/src/nodeevents.cpp \
    libs/yaml-cpp/src/node_data.cpp \
    libs/yaml-cpp/src/null.cpp \
    libs/yaml-cpp/src/ostream_wrapper.cpp \
    libs/yaml-cpp/src/parse.cpp \
    libs/yaml-cpp/src/parser.cpp \
    libs/yaml-cpp/src/regex_yaml.cpp \
    libs/yaml-cpp/src/scanscalar.cpp \
    libs/yaml-cpp/src/scantag.cpp \
    libs/yaml-cpp/src/scanner.cpp \
    libs/yaml-cpp/src/scantoken.cpp \
    libs/yaml-cpp/src/simplekey.cpp \
    libs/yaml-cpp/src/singledocparser.cpp \
    libs/yaml-cpp/src/stream.cpp \
    libs/yaml-cpp/src/tag.cpp \
    libs/yaml-cpp/src/contrib/graphbuilderadapter.cpp \
    libs/yaml-cpp/src/contrib/graphbuilder.cpp \
    libs/fmt/src/format.cc \
    libs/fmt/src/os.cc

HEADERS += \
    mainwindow.h

INCLUDEPATH += \
    libs/yaml-cpp/include \
    libs/fmt/include

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
