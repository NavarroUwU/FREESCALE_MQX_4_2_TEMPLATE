@echo OFF
set NOPAUSE=%1
SET CWD=%CD%
cd ../../../../../../build/make/bsp_twrk70f120m
mingw32-make TOOL=cw10gcc CONFIG=debug build
if errorlevel 1 if NOT "%NOPAUSE%" == "nopause" (pause)
cd %CWD%
SET CWD=%CD%
cd ../../../../../../build/make/psp_twrk70f120m
mingw32-make TOOL=cw10gcc CONFIG=debug build
if errorlevel 1 if NOT "%NOPAUSE%" == "nopause" (pause)
cd %CWD%
mingw32-make TOOL=cw10gcc CONFIG=debug LOAD=intflash_sramdata build
if errorlevel 1 if NOT "%NOPAUSE%" == "nopause" (pause)
SET CWD=%CD%
cd ../../../../../../build/make/bsp_twrk70f120m
mingw32-make TOOL=cw10gcc CONFIG=release build
if errorlevel 1 if NOT "%NOPAUSE%" == "nopause" (pause)
cd %CWD%
SET CWD=%CD%
cd ../../../../../../build/make/psp_twrk70f120m
mingw32-make TOOL=cw10gcc CONFIG=release build
if errorlevel 1 if NOT "%NOPAUSE%" == "nopause" (pause)
cd %CWD%
mingw32-make TOOL=cw10gcc CONFIG=release LOAD=intflash_sramdata build
if errorlevel 1 if NOT "%NOPAUSE%" == "nopause" (pause)
SET CWD=%CD%
cd ../../../../../../build/make/bsp_twrk70f120m
mingw32-make TOOL=cw10gcc CONFIG=debug build
if errorlevel 1 if NOT "%NOPAUSE%" == "nopause" (pause)
cd %CWD%
SET CWD=%CD%
cd ../../../../../../build/make/psp_twrk70f120m
mingw32-make TOOL=cw10gcc CONFIG=debug build
if errorlevel 1 if NOT "%NOPAUSE%" == "nopause" (pause)
cd %CWD%
mingw32-make TOOL=cw10gcc CONFIG=debug LOAD=intflash_ddrdata build
if errorlevel 1 if NOT "%NOPAUSE%" == "nopause" (pause)
SET CWD=%CD%
cd ../../../../../../build/make/bsp_twrk70f120m
mingw32-make TOOL=cw10gcc CONFIG=release build
if errorlevel 1 if NOT "%NOPAUSE%" == "nopause" (pause)
cd %CWD%
SET CWD=%CD%
cd ../../../../../../build/make/psp_twrk70f120m
mingw32-make TOOL=cw10gcc CONFIG=release build
if errorlevel 1 if NOT "%NOPAUSE%" == "nopause" (pause)
cd %CWD%
mingw32-make TOOL=cw10gcc CONFIG=release LOAD=intflash_ddrdata build
if errorlevel 1 if NOT "%NOPAUSE%" == "nopause" (pause)

if not "%NOPAUSE%" == "nopause" (pause)
