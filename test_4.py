"""
用于测试 class_.py 内函数
"""
import sys
from ctypes import *

import class_

# 模块初始化
sys.path.append('D:\\360data\\blog-3123958139')
class_ = class_.class_()
h_dll_ = class_.import_dll_()

#
code_, data_frame_ = class_.get_sql_data_()
open_ = data_frame_['open'].values
open_len_ = len(open_)

# 数据格式转换
array_ = (c_double * open_len_)(*open_)
array_len_ = open_len_

# 调用函数2
h_dll_.w_ma_(array_, array_len_, 5)
