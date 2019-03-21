import os
import platform
from os import path   
import sys
import fnmatch
import tempfile
import time
import importlib
import shutil
import awtk_config as awtk

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



SConscriptFiles=awtk.NANOVG_BACKEND_PROJS + [
  '3rd/nanovg/SConscript',
  '3rd/glad/SConscript',
  '3rd/gpinyin/SConscript', 
  '3rd/libunibreak/SConscript',
  'src/SConscript',
  'tools/common/SConscript', 
  'tools/theme_gen/SConscript', 
  'tools/font_gen/SConscript', 
  'tools/image_gen/SConscript', 
  'tools/image_resize/SConscript', 
  'tools/res_gen/SConscript', 
  'tools/str_gen/SConscript', 
  'tools/ui_gen/qt_to_xml/SConscript',
  'tools/ui_gen/xml_to_ui/SConscript',
  'tools/svg_gen/SConscript',
  'demos/SConscript', 
  'tests/SConscript'
  ] + awtk.OS_PROJECTS

APP_ROOT = os.path.normpath(os.getcwd())
BIN_DIR = joinPath(APP_ROOT, 'bin')

os.environ['TK_ROOT'] = awtk.TK_ROOT;
os.environ['BIN_DIR'] = BIN_DIR;
os.environ['LIB_DIR'] = awtk.TK_LIB_DIR;
os.environ['APP_ROOT'] = APP_ROOT;

QR_CPPPATH = awtk.CPPPATH
QR_CPPPATH.append(APP_ROOT);
QR_CPPPATH.append(os.path.join(APP_ROOT, 'src'));
QR_CPPPATH.append(os.path.join(APP_ROOT, 'src/lib'));

DefaultEnvironment(CCFLAGS = awtk.CCFLAGS, 
  LIBS = awtk.LIBS,
  LIBPATH = awtk.LIBPATH,
  CPPPATH = QR_CPPPATH,
  LINKFLAGS = awtk.LINKFLAGS,
  TARGET_ARCH=awtk.TARGET_ARCH,
  OS_SUBSYSTEM_CONSOLE=awtk.OS_SUBSYSTEM_CONSOLE,
  OS_SUBSYSTEM_WINDOWS=awtk.OS_SUBSYSTEM_WINDOWS
)


SConscript(['src/SConscript'] )
SConscript(['demo_qr/SConscript'] )
SConscript(['test/SConscript'] )