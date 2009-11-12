set BUILD=%1

cd %~dp0
cd ..

mkdir lightgame
mkdir lightgame\data
mkdir lightgame\media

xcopy data lightgame\data /E/Y
xcopy media lightgame\media /E/Y

copy bin\%BUILD%\lightgame.exe lightgame
copy scripts\plugins_%BUILD%.cfg lightgame\plugins.cfg

if /i %BUILD% == Debug goto :debug
if /i %BUILD% == Release goto :release

goto :eof

:debug

copy dependencies\ogre\build\bin\%BUILD%\Ogremain_d.dll lightgame
copy dependencies\ogre\build\bin\%BUILD%\RenderSystem_Direct3D9_d.dll lightgame
copy dependencies\ogre\build\bin\%BUILD%\RenderSystem_GL_d.dll lightgame

goto :eof

:release

copy dependencies\ogre\build\bin\%BUILD%\Ogremain.dll lightgame
copy dependencies\ogre\build\bin\%BUILD%\RenderSystem_Direct3D9.dll lightgame
copy dependencies\ogre\build\bin\%BUILD%\RenderSystem_GL.dll lightgame
