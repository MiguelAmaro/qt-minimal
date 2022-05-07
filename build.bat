@echo off

echo handmade build... [%cd%]

pushd build
F:\Dev_Tools\Qt\6.2.2\msvc2019_64\bin\qmake.exe ^
../qthandmade.pro -spec win32-msvc ^
"CONFIG+=debug"

F:\Dev_Tools\Qt\Tools\QtCreator\bin\jom\jom.exe ^
-NOLOGO -S -j 6 -f Makefile qmake_all

rem The number is the core count that you want to use towards
rem the build process. -s to only output build errors
F:\Dev_Tools\Qt\Tools\QtCreator\bin\jom\jom.exe ^
-NOLOGO -S -j 6 -f Makefile.Debug
popd
goto :eof

rem QT Module DLLs
rem At the end of the build process if you added any qt modules like
rem widget, gui or whatever you'll get an error asking for a dll. Look for
rem the dll in here "QT_DIR\6.2.2\" look for the platform you're targeting
rem like msvc2019 and the dll should be in the bin folder. 
rem e.g "QT_DIR\6.2.2\msvc2019_64\bin>"
rem paste the dll in the directory of the executable
rem QT Platform DLLs