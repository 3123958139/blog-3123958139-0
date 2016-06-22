"""
用于测试 my_py_class 内函数
"""
import sys

import my_py_class_

# 模块初始化
sys.path.append('D:\\360data\\Clion2016.1.3')
class_ = my_py_class_.myPyClass_()

# 运行 socket client
while True:
    print(class_.run_socket_client_())
