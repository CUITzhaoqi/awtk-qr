#!/usr/bin/python
# -*- coding: UTF-8 -*-

import os
from os import path   
import sys
import fnmatch
import tempfile
import time
import importlib
import shutil

AWTK_ROOT_DIR='E:\\awtk-qr\\awtk\\'

def copy_file(dst_dir,src_dir):
    shutil.copy(src_dir,dst_dir);

def copy_files(dst_dir,src_dir,name_pattern = '*'):
    if not os.path.exists(dst_dir):
        os.makedirs(dst_dir);
    all_files = os.listdir(src_dir);

    for file in all_files:
        src_file_path = src_dir + os.path.sep + file;
        if os.path.isfile(src_file_path) :
            if fnmatch.fnmatch(file,name_pattern):
                dst_file_path = dst_dir + os.path.sep + file;
                copy_file(dst_file_path,src_file_path);
        else :
            dst_sub_dir_path = dst_dir + os.path.sep + file
            copy_files(dst_sub_dir_path,src_file_path,name_pattern)
    return None

#获取当前路径
APP_ROOT = os.path.join(os.getcwd(), '../')
    
if os.path.exists(AWTK_ROOT_DIR):
    copy_files(AWTK_ROOT_DIR + 'src/ext_widgets/qr', APP_ROOT + 'src/qr');
    copy_files(AWTK_ROOT_DIR + '3rd/qrencode', APP_ROOT + 'src/lib/qrencode', '*.[!obj]');
    copy_files(AWTK_ROOT_DIR + 'demo_qr', APP_ROOT + 'demo_qr', '*.[!bin]');
else :
    print 'AWTK not exist!'
