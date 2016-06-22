"""
用于测试 class_.py 内函数
"""
import sys

import class_

# 模块初始化
sys.path.append('D:\\360data\\blog-3123958139')
class_ = class_.class_()

# 下载 tushare.org 数据
# class_.get_url_data_()

# 调用 mysql 数据
# print(class_.get_sql_data_(code_='000886'))

# 运行 socket server
class_.run_socket_server_()
