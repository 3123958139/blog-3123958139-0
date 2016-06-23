"""
用于测试 libdll_.dll 函数
"""

# -*- coding: utf-8 -*-
import sys
import class_
import tushare
from ctypes import *

# 加载模块，获得 dll 句柄
sys.path.append('D:\\360data\\blog-3123958139')
h_dll_ = class_.class_().import_dll_()

# 调用函数1
h_dll_.hello_()

# 由调用函数1知道调用方法，所以根据需要下载测试数据
data_frame = tushare.get_hist_data('sh')
open_ = data_frame['open'].values
open_len_ = len(open_)

# 数据格式转换
array_ = (c_double * open_len_)(*open_)
array_len_ = open_len_

# 调用函数2
h_dll_.w_ma_(array_, array_len_, 5)
