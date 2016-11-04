@echo off

SET BASE_DIR=%~dp0
SET ASTYLE=%BASE_DIR%\dev\tools\AStyle.exe

FOR %%F IN (%BASE_DIR%\sedml\*.h ^
 %BASE_DIR%\sedml\*.cpp ^
 %BASE_DIR%\sedml\common\*.h ^
 %BASE_DIR%\sedml\common\*.cpp ) DO %ASTYLE% ^
        --break-blocks  ^
        --convert-tabs ^
        --indent-preprocessor ^
        --indent-switches ^
        --indent=spaces=2 ^
        --keep-one-line-blocks ^
        --keep-one-line-statements ^
        --min-conditional-indent=0 ^
        --mode=c ^
        --pad-header ^
        --pad-oper ^
        --quiet ^
        --style=gnu ^
        --suffix=none ^
        --unpad-paren ^
        %%F
