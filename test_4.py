"""
用于测试 class_.py 内函数
"""
import sys
from ctypes import *

import matplotlib.pyplot as pyplot
import pandas

import class_

# 模块初始化
sys.path.append('D:\\360data\\blog-3123958139')
class_ = class_.class_()
h_dll_ = class_.import_dll_()

# 提取数据
code_, data_frame_ = class_.get_sql_data_()
open_ = data_frame_['open'].values
open_len_ = len(open_)

# 数据格式转换
array_ = (c_double * open_len_)(*open_)
array_len_ = open_len_

# 调用函数2
h_dll_.w_ma_(array_, array_len_, 5)

# 把结果存入数据库
csv_file_ = pandas.read_csv('c:\\w_ma_.csv')
csv_file_ = csv_file_.drop(['Unnamed: 3'], axis=1)
csv_file_ = pandas.DataFrame(csv_file_)
csv_file_.to_sql(code_ + '_wma_', class_.engine_, if_exists='replace', index=True, index_label='index')
print(csv_file_)

# 画个图看看
pyplot.plot(csv_file_['price'])
pyplot.plot(csv_file_['wma'])
pyplot.show()
