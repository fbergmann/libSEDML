@echo off 
SET BASE_DIR=%~dp0
SET PYTHON=C:\Anaconda2_64\python.exe
SET PYTHONPATH=%BASE_DIR%\dev

if not exist  %BASE_DIR%\out mkdir %BASE_DIR%\out
cd /d %BASE_DIR%\out
%PYTHON% ..\dev\run.py

cd /d %BASE_DIR%
