# -*- coding:utf-8 -*-
# coding=utf-8
# !/usr/bin/python
# python 2.7以上

import time
import json
import os
import sys
import base64
import string
import glob
import zipfile
import shutil
import urllib2
import json
import mimetools
import mimetypes
import itertools
from collections import OrderedDict

# 工作空间
workspace = os.getenv("WORKSPACE") #'D:/work/fish_wx/Client_branch'
# 项目工程目录
projectDir = workspace

# 构建模式
buildMode = os.environ['buildMode']
# 平台
platform = os.environ['platform']
# 自动版构建本号
visible = os.environ['BUILD_VERSION']
# appid
appId = os.environ['appId'] #0
# app版本
appVisible = os.environ['appVisible']
# 资源版本
resVisible = os.environ['resVisible']
# 构建类型
buildType = os.environ['buildType']

def arrangeSDK():
    print ("部署sdk")

#剪切app到CDN下载目录
def shearAppCDN():
    print ('-------------------- 剪切app到CDN下载目录 ---------------------')
    #<img width="150" height="150" src="https://api.pwmqr.com/qrcode/create/?url=http://192.168.0.60:88/android_fish_branch/${buildMode}/fish-${buildMode}-${platform}-${visible}.apk" />
    # platform = 'default'
    # visible = '1.0.0'
    # buildMode = 'release'
    # projectDir = 'E:/cocos/wx_fish_branch/build/'

    sourceAppDir = projectDir + 'jsb-default/frameworks/runtime-src/proj.android-studio/app/build/outputs/apk/%(buildMode)s/' % {
        'buildMode': buildMode}
    sourceAppName = 'fish-%(buildMode)s.apk' % {'buildMode': buildMode}
    destiAppDir = 'D:/nodejs/work/android_fish_branch/%(buildMode)s/' % {'buildMode': buildMode}
    destAppName = 'fish-%(buildMode)s-%(platform)s-%(visible)s.apk' % {'buildMode': buildMode, 'platform': platform,
                                                                       'visible': visible}
    sourceAppPath1 = sourceAppDir + sourceAppName
    sourceAppPath2 = sourceAppDir + destAppName
    destAppPath = destiAppDir + destAppName

    print ('sourceAppPath1: ', sourceAppPath1)
    print ('sourceAppPath2: ', sourceAppPath2)
    print ('destAppPath: ', destAppPath)
    if os.path.exists(sourceAppPath1):
        os.rename(sourceAppPath1, sourceAppPath2)
        try:
            shutil.copy(sourceAppPath2, destAppPath)
            os.remove(sourceAppPath2)
            print ('----> cutting success')
        except:
            print('----> Error cutting file：', sourceAppPath2)
    else:
        print('----> file non-existent: ', sourceAppPath1)

# 发布热更资源
def publishHotUpdateRes():
    print ('-------------------- 发布热更资源 ---------------------')

# cocoscreae构建-编译
def buildCompile():
    isDebug = 'True'
    if 'release' == buildMode:
        isDebug = 'False'

    if 'res' == buildType:
        os.system('C:/CocosDashboard_1.0.11/resources/.editors/Creator/2.4.3/CocosCreator.exe --path ' + projectDir + ' --build platform=android;debug=' + isDebug)
        print ('-------------------- 构建完成 ---------------------')
        publishHotUpdateRes()
    else:
        os.system('C:/CocosDashboard_1.0.11/resources/.editors/Creator/2.4.3/CocosCreator.exe --path ' + projectDir + ' --build "autoCompile=true";platform=android;debug=' + isDebug)
        print ('-------------------- 编译完成 ---------------------')
        shearAppCDN()


def start():
    print ('=============projectDir: ', projectDir)
    print ('=============isDebug: ', buildMode)
    print ('=============appVisible: ', appVisible)
    print ('=============resVisible: ', resVisible)
    print ('=============buildType: ', buildType)

    if 'default' != platform:
        arrangeSDK()

    buildCompile()

if __name__ == '__main__':
    start()