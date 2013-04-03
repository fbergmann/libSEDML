@echo off 
SET BASE_DIR=%~dp0
SET PYTHON=C:\Python27\python.exe
SET PYTHONPATH=%BASE_DIR%\dev

cd /d %BASE_DIR%\out
%PYTHON% ..\dev\run.py

cd /d %BASE_DIR%
