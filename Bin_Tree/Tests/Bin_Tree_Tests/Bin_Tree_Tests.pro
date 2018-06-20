CONFIG += console c++14

INCLUDEPATH += "gtest/include"
INCLUDEPATH += "gtest/"
INCLUDEPATH += "../../"

HEADERS += \
    ../../queue.h \
    ../../bin_tree.h

SOURCES += \
    main.cpp \
    gtest/src/gtest-test-part.cc \
    gtest/src/gtest.cc \
    gtest/src/gtest-typed-test.cc \
    gtest/src/gtest-printers.cc \
    gtest/src/gtest-port.cc \
    gtest/src/gtest-filepath.cc \
    gtest/src/gtest-death-test.cc \
    gtest/src/gtest-all.cc
