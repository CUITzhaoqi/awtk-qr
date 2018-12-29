import os
import platform
from os import path   
import sys
import fnmatch
import tempfile
import time
import importlib
import shutil

def Install(dst_dir,src_dir):
    shutil.copy(src_dir,dst_dir);

def InstallDir(dst_dir,src_dir,name_pattern = '*'):
    if not os.path.exists(dst_dir):
        os.makedirs(dst_dir);
    all_files = os.listdir(src_dir);

    for file in all_files:
        src_file_path = src_dir + os.path.sep + file;
        if os.path.isfile(src_file_path) :
            if fnmatch.fnmatch(file,name_pattern):
                dst_file_path = dst_dir + os.path.sep + file;
                Install(dst_file_path,src_file_path);
        else :
            dst_sub_dir_path = dst_dir + os.path.sep + file
            InstallDir(dst_sub_dir_path,src_file_path,name_pattern)
    return None


def joinPath(root, subdir):
  return os.path.normpath(os.path.join(root, subdir))
  
OS_NAME=platform.system()

if OS_NAME == 'Windows':
  os.system('cd awtk&scons -j8')

if OS_NAME == 'Linux':
  os.system('cd awtk;scons -j8')

if OS_NAME == 'Darwin':
  os.system('cd awtk;scons -j8')


TK_ROOT = os.path.normpath(os.getcwd()+'/awtk')
APP_ROOT = os.path.normpath(os.getcwd())
APP_3RD_ROOT = joinPath(APP_ROOT, '3rd')
APP_BIN_ROOT=joinPath(APP_ROOT, 'bin')
APP_LIB_DIR=joinPath(APP_ROOT, 'lib')

TK_SRC = joinPath(TK_ROOT, 'src')
TK_3RD_ROOT = joinPath(TK_ROOT, '3rd')
TK_BIN_DIR=joinPath(TK_ROOT, 'bin')
TK_LIB_DIR=joinPath(TK_ROOT, 'lib')
GTEST_ROOT = joinPath(TK_ROOT, '3rd/gtest/googletest')

if OS_NAME == 'Windows':
  TK_ROOT=TK_ROOT.replace('\\', '\\\\');

#INPUT_ENGINE='null'
INPUT_ENGINE='pinyin'

os.environ['APP_ROOT'] = APP_ROOT;
os.environ['LIB_DIR'] = APP_LIB_DIR;
os.environ['BIN_DIR'] = APP_BIN_ROOT;

os.environ['TK_ROOT'] = TK_ROOT;
os.environ['TK_LIB_DIR'] = TK_LIB_DIR;
os.environ['TK_BIN_DIR'] = TK_BIN_DIR;
os.environ['TK_3RD_ROOT'] = TK_3RD_ROOT;
os.environ['GTEST_ROOT'] = GTEST_ROOT;

OS_LIBS=[]
OS_LIBPATH=[]
OS_CPPPATH=[]
OS_LINKFLAGS=''
OS_FLAGS='-g -Wall'
OS_SUBSYSTEM_CONSOLE=''
OS_SUBSYSTEM_WINDOWS=''
OS_PROJECTS=[]

COMMON_CCFLAGS=' -DHAS_STD_MALLOC -DHAS_STDIO -DWITH_SDL -DWITH_FS_RES'


if OS_NAME == 'Darwin':
  OS_LIBS = ['stdc++', 'pthread', 'm', 'dl']
  OS_LINKFLAGS='-framework Cocoa -framework QuartzCore -framework OpenGL -weak_framework Metal -weak_framework MetalKit'
  COMMON_CCFLAGS = COMMON_CCFLAGS + ' -D__APPLE__ -DHAS_PTHREAD -DMACOS -DENABLE_MEM_LEAK_CHECK '
  COMMON_CCFLAGS = COMMON_CCFLAGS + ' -D__STDC_LIMIT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_CONSTANT_MACROS  -DBGFX_CONFIG_RENDERER_METAL=1 '

elif OS_NAME == 'Linux':
  OS_LIBS = ['GL', 'gtk-3','gdk-3','Xext', 'X11', 'sndio','stdc++', 'pthread', 'm', 'dl']
  COMMON_CCFLAGS = COMMON_CCFLAGS + ' -DLINUX -DHAS_PTHREAD'
  COMMON_CCFLAGS = COMMON_CCFLAGS + ' -DSDL_REAL_API -DSDL_TIMER_UNIX -DSDL_VIDEO_DRIVER_X11 -DSDL_VIDEO_DRIVER_X11_SUPPORTS_GENERIC_EVENTS '
  COMMON_CCFLAGS = COMMON_CCFLAGS + ' -DSDL_AUDIO_DRIVER_SNDIO -DSDL_VIDEO_OPENGL_GLX -DSDL_VIDEO_RENDER_OGL '
  COMMON_CCFLAGS = COMMON_CCFLAGS + ' -DSDL_LOADSO_DLOPEN -DSDL_VIDEO_OPENGL_EGL -DSDL_VIDEO_OPENGL_ES2 '
  COMMON_CCFLAGS = COMMON_CCFLAGS + ' -DSDL_REAL_API -DSDL_HAPTIC_DISABLED -DSDL_SENSOR_DISABLED -DSDL_JOYSTICK_DISABLED '
  OS_PROJECTS=['3rd/SDL/SConscript']

elif OS_NAME == 'Windows':
  OS_LIBS=['gdi32', 'user32','winmm.lib','imm32.lib','version.lib','shell32.lib','ole32.lib','Oleaut32.lib','Advapi32.lib','DelayImp.lib','psapi.lib']
  OS_FLAGS='-DWIN32 -D_WIN32 -DWINDOWS /EHsc -D_CONSOLE  /DEBUG /Od  /FS /Z7 '
  COMMON_CCFLAGS = COMMON_CCFLAGS + ' -DSDL_REAL_API -DSDL_HAPTIC_DISABLED -DSDL_SENSOR_DISABLED -DSDL_JOYSTICK_DISABLED '
  COMMON_CCFLAGS = COMMON_CCFLAGS + '-D__STDC_LIMIT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_CONSTANT_MACROS -D_HAS_EXCEPTIONS=0 -D_HAS_ITERATOR_DEBUGGING=0 -D_ITERATOR_DEBUG_LEVEL=0 -D_SCL_SECURE=0'
  COMMON_CCFLAGS = COMMON_CCFLAGS + '-D_SECURE_SCL=0 -D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_DEPRECATE -D_WIN64'
  OS_LINKFLAGS='/MACHINE:X64 /DEBUG'
  OS_SUBSYSTEM_CONSOLE='/SUBSYSTEM:CONSOLE  '
  OS_SUBSYSTEM_WINDOWS='/SUBSYSTEM:WINDOWS  '
  OS_PROJECTS=['3rd/SDL/SConscript']

LIBS=['awtk', 'gpinyin', 'awtk', 'linebreak', 'nanovg', 'SDL2', 'glad'] + OS_LIBS

CCFLAGS=OS_FLAGS + COMMON_CCFLAGS

CPPPATH = [
  APP_ROOT,
  os.path.join(APP_ROOT, 'src'),
  TK_ROOT,
  TK_SRC,
  TK_3RD_ROOT,
  APP_3RD_ROOT,
  os.path.join(TK_SRC, 'ext_widgets'),
]

LIBPATH = [TK_LIB_DIR, APP_LIB_DIR]

DefaultEnvironment(CCFLAGS = CCFLAGS, 
  LIBS = LIBS,
  CPPPATH = CPPPATH,
  LINKFLAGS = OS_LINKFLAGS,
  OS_SUBSYSTEM_CONSOLE=OS_SUBSYSTEM_CONSOLE,
  OS_SUBSYSTEM_WINDOWS=OS_SUBSYSTEM_WINDOWS,
  LIBPATH = LIBPATH + OS_LIBPATH)
  
SConscript(['src/SConscript'] )
SConscript(['demo_qr/SConscript'] )
SConscript(['test/SConscript'] )