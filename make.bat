@echo off
cd /d %~dp0
::::::::::::::::::::::::::::::::::::::::::::::::
del /f /s /q *.o > nul 2> nul
del /f /s /q *.h.ghc > nul 2> nul
del /f /s /q *.tmp.* > nul 2> nul
::::::::::::::::::::::::::::::::::::::::::::::::
if "%1" == "clean" exit
echo makeing...
echo.
::::::::::::::::::::::::::::::::::::::::::::::::
set cc="gcc.exe"
set output="odyink_server.exe"
::::::::::::::::::::::::::::::::::::::::::::::::
echo %cc% ^^> link.tmp.bat
for /f %%o in (make.ini) do (
	echo CC %%o
	%cc% -c -O2 -Wall -W -pedantic -std=c99 -I./include -idirafter ./lap/include %%o
)
for %%o in ("*.o") do echo %%o ^^>> link.tmp.bat
echo -o %output%>> link.tmp.bat
echo goto :eof >> link.tmp.bat
echo LD
call link.tmp.bat
::::::::::::::::::::::::::::::::::::::::::::::::
echo.
echo clean
del /f /s /q *.o > nul 2> nul
del /f /s /q *.h.ghc > nul 2> nul
del /f /s /q *.tmp.* > nul 2> nul
echo finish!
pause
%output%