@echo off
REM Compile the game
gcc src\main.c src\game.c src\map.c -Iinclude -o shadowgrid.exe -Wall

IF %ERRORLEVEL% NEQ 0 (
    echo Compilation failed!
    pause
    exit /b 1
)

echo Compilation successful! Running game...
shadowgrid.exe
pause