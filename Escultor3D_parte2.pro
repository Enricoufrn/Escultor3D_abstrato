TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        FiguraGeometrica.cpp \
        Sculptor.cpp \
        cutbox.cpp \
        cutellipsoid.cpp \
        cutsphere.cpp \
        cutvoxel.cpp \
        interpretador.cpp \
        main.cpp \
        putbox.cpp \
        putellipsoid.cpp \
        putsphere.cpp \
        putvoxel.cpp

HEADERS += \
    FiguraGeometrica.h \
    Sculptor.h \
    cutbox.h \
    cutellipsoid.h \
    cutsphere.h \
    cutvoxel.h \
    interpretador.h \
    putbox.h \
    putellipsoid.h \
    putsphere.h \
    putvoxel.h
