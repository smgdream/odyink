@echo oFF
cd /d %~dp0
::::::::::::::::::::::::::::::::::::::::::::::::
del /f /s /q *.o > nul 2> nul
del /f /s /q *.tmp.* > nul 2> nul
::::::::::::::::::::::::::::::::::::::::::::::::
if "%1"=="clean" exit
echo makeing...
::::::::::::::::::::::::::::::::::::::::::::::::
set cc="D:\gcc10\bin\gcc.exe"
echo %cc% ^^> link.tmp.bat
for /f %%o in (make.ini) do (
	echo CC %%o
	%cc% -O2 -Wall -c %%o
)
for %%o in ("*.o") do echo %%o ^^>> link.tmp.bat
echo -o OdyinkServer.exe>> link.tmp.bat
echo goto :eof >> link.tmp.bat
echo LD
call link.tmp.bat
::::::::::::::::::::::::::::::::::::::::::::::::
echo.
echo clean
del /f /s /q *.o > nul 2> nul
del /f /s /q *.tmp.* > nul 2> nul
echo finish!
pause
OdyinkServer.exe