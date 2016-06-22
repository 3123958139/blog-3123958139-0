### 备忘录

    1. python 调用 dll 需 32bit 的 python

    2. 64bit 的 mysql 需 64bit 的 python

### 一、通过 clion 搭建 c++/python 混合编程 ide

    1. clion
        * ide 环境

    2. tdmgcc
        * c++ 编译器

    3. winpython
        * python 科学计算环境

    4. mysql
        * sql 数据库

    5. git
        * github 版本控制

### 二、个人编程习惯

    1. 命名习惯：.cpp
        * aaa_bbb_ccc_
        * aaa_bbb_ccc_1, aaa_bbb_ccc_2

    2. 编写习惯：.md
        * 段落开始前前面空一行
        * 一条语句后面空一行

### 三、创建工程

    1. CMakeLists.txt
    2. dll_.h
    3. dll_.cpp
        * 以上三个用于创建 c++ dll 封装那些对计算性能要求高的函数，如
        * w_ma_：计算加权平均值

    4. class_.py
        * 封装那些需要重复调用的 py 代码，如
        * get_url_data_：从 tushare 下载数据
        * get_sql_data_：调用 mysql 本地数据
        * run_socket_server_：建立 socket 服务器
        * run_socket_client_：建立 socket 客户端
        * import_dll_：导入动态链接库

    5. test_1.py
    6. test_2.py
    7. test_3.py
        * 以上三个用于测试代码