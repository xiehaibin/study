echo off

set publish_url="dabao\project\sg\frameworks\runtime-src\proj.android"
set target_res_url="dabao\project\sg\frameworks\runtime-src\proj.android\assets\sg"
set res_url="common\client_publish\37wan_3\sg1"
set sdk_res_url="sdkworkspace\sdk\37wan"
set sdkproxy_url="sdkworkspace\sysdkproxy"

echo 打包目录：%publish_url%
echo 打包资源：%target_res_url%
echo 资源目录：%res_url%
echo SDK目录：%sdk_res_url%
echo 中间目录：%sdkproxy_url%

goto start
:start

rd /s/q %publish_url%\assets\
md %publish_url%\assets\

md %target_res_url%

xcopy /y /e %res_url% %target_res_url%


del /q /s %publish_url%\AndroidManifest.xml

rd /s/q %publish_url%\res\
md %publish_url%\res\

rd /s/q %publish_url%\libs\
md %publish_url%\libs\

xcopy /y /e %sdk_res_url%\res    %publish_url%\res
xcopy /y /e %sdk_res_url%\libs   %publish_url%\libs
xcopy /y /e %sdk_res_url%\assets %publish_url%\assets

copy /y %sdk_res_url%\assets\sy\adChannel.png %publish_url%\assets\sg\adChannel.png

rd /s/q %sdkproxy_url%\src\com\sy\proxy\sdk\channel\

xcopy /y /e %sdk_res_url%\java %sdkproxy_url%\src

del /q /s %sdkproxy_url%\project.properties

copy /y %sdk_res_url%\properties\project.properties %publish_url%\project.properties
copy /y %sdk_res_url%\manifest\AndroidManifest.xml  %publish_url%\AndroidManifest.xml

pause
exit 
