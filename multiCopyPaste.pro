QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += include/
VPATH += src/

SOURCES += \
    aboutmedialog.cpp \
    copypastecell.cpp \
    main.cpp \
    copypaste.cpp \
    newtabdialog.cpp \
    tabnew.cpp

HEADERS += \
    include/aboutmedialog.h \
    include/copypaste.h \
    include/copypastecell.h \
    include/newtabdialog.h \
    include/tabnew.h

FORMS += \
    ui/aboutmedialog.ui \
    ui/copypaste.ui \
    ui/copypastecell.ui \
    ui/newtabdialog.ui \
    ui/tabnew.ui

RC_ICONS = img/paste.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    json_examples.qrc \
    resource.qrc

DISTFILES += \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/gradle.properties \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/res/values/libs.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

