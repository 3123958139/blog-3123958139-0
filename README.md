### 备忘录

    1. python 调用 dll 需 32bit 的 python

    2. 64bit 的 mysql 需 64bit 的 python

    3. 量化交易策略
        * 输入数据 - 只取最原始可靠的，如
        * index
        * date
        * open
        * high
        * low
        * close
        * volume
        * 输出数据 - 根据数理统计取权重，如
        * w_price_ = open * 2 + high * 1 + low * 1 + close * 3
        * w_price_ = w_price_ / 7
        * w_price_rate_[0] = 0
        * w_price_rate_[i] = w_price_[i] / w_price_[i - 1]
        * w_price_rate_ma_[0], ..., w_price_rate_ma_[i - 2] = 0
        * w_price_rate_ma_[i - 1] = (w_price_rate[0] * ? + ...) / ?
        * 画出上图 - 把大盘指数，板块指数，个股权价叠加在同一图表内
        * 画出下图 - 把大盘涨跌幅，板块涨跌幅，个股涨跌幅叠加

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

    1. 命名习惯：
        * aaa_bbb_ccc_
        * aaa_bbb_ccc_1, aaa_bbb_ccc_2

    2. 编写习惯：
        * 注释在语句前，注释前空一行

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

    5. test_dll_w_price_rate_ma_.py
        * 用于测试 dll 中的 w_price_rate_ma_ 函数

    6. test_class_run_socket_server.py
        * 用于运行 socket 服务器

    7. test_class_run_socket_client.py
        * 用于运行 socket 客户端

    8. test_.py
        * 测试其他
