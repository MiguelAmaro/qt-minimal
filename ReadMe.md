## Questions

**What are .qrc files?**

dunno but you have to spec it in the .pro file. qmake uses it's meta programming tool
to generate qrc_application.cpp file with all the associated resources like images, 
ect.. defined as static c++ arrays.


**What is this $$ operator?**

qmake has a language and this is one of the defined operators. It allows
you to access a variable's data.


**What are these symbols e.g. target.path, core, ect.. ?**

core, gui ect.. are just options that are added to a list to let qmake know what 
packagest to get. target.path is target, an object allow by qmakes object style. 
.path is just one of the members. Those object can be filled out and passed as options
to qt prdefined variables.

## Resouces
**Project Files Information** 
https://doc.qt.io/qt-5/qmake-project-files.html
https://doc.qt.io/qt-5/qmake-language.html

**Qmake Variable List:**

Depending on the project some of these variables must be defined. For example
SOURCES, HEADERS, ANDROID_
https://doc.qt.io/qt-5/qmake-variable-reference.html
Details on Qt Object Style API:
https://doc.qt.io/qt-5/qmake-advanced-usage.html#installing-files
Qmake CL Options:
https://doc.qt.io/qt-5/qmake-running.html