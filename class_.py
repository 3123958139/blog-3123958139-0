# -*- coding: utf-8 -*-
import ctypes
import os
import socket
import struct

import pandas
import sqlalchemy
import tushare


class myPyClass_:
    def __init__(self, user_='test', password_='123456', dsn_='odbcdsn', host_='192.168.1.3', port_=12345):

        '''启动 mysql 服务，因为我一般是屏蔽掉了，为了开机快点'''
        os.system('net start mysql')

        '''mysql 连接信息'''
        self.user_ = user_
        self.password_ = password_
        self.dsn_ = dsn_
        self.engine_ = sqlalchemy.create_engine('mysql+pyodbc://' + self.user_ + ':' + self.password_ + '@' + self.dsn_)

        '''socket 网络地址'''
        self.host_ = host_
        self.port_ = port_

    def get_url_data_(self):

        '''从 tushare.org 获取股票市场的代码列表'''
        code_list_ = pandas.DataFrame((tushare.get_today_all())['code'])
        code_list_ = code_list_.sort(columns='code', ascending=True)
        code_list_['index'] = pandas.DataFrame([i for i in range(0, len(code_list_))], code_list_.index)
        code_list_.reindex(index=code_list_['code'])
        code_list_.to_sql('code_list_', self.engine_, if_exists='replace', index=True, index_label='index')
        self.engine_.connect().execute('alter table testdb.code_list_ add primary key(`index`)')

        '''根据上面股票列表逐个获取个股数据'''
        for i in range(0, len(code_list_)):
            stock_data_ = tushare.get_h_data(code_list_['code'][i])
            stock_data_['date'] = pandas.Series(stock_data_.index, stock_data_.index)
            stock_data_ = stock_data_.sort_values(by='date', ascending=True)
            stock_data_['index'] = pandas.DataFrame([i for i in range(0, len(stock_data_))], stock_data_.index)
            stock_data_.to_sql(code_list_['code'][i], self.engine_, if_exists='replace', index=True,
                               index_label='index')
            self.engine_.connect().execute('alter table testdb.' + code_list_['code'][i] + ' add primary key(`index`)')

    def get_sql_data_(self, code_='000886'):

        '''取 mysql 数据'''
        stock_data_ = pandas.read_sql_table(code_, self.engine_)
        return code_, stock_data_

    def run_socket_server_(self):

        socket_ = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        socket_.bind((self.host_, self.port_))
        socket_.listen(5)

        '''服务器从数据库取数据，再一笔笔的发送给客户端，用来模拟实时状态'''
        code_, stock_data_ = self.get_sql_data_()
        i_ = stock_data_['index']
        o_ = stock_data_['open']
        h_ = stock_data_['high']
        l_ = stock_data_['low']
        c_ = stock_data_['close']
        v_ = stock_data_['volume']

        i = 0

        '''服务器不间断循环，出口由客户端发送断链口令激活'''
        while True:
            connection_, address_ = socket_.accept()

            '''设置一个连接的口令 connect'''
            if connection_.recv(1024) == b'connect' and i < len(i_):
                connection_.send(struct.pack('6si5f', code_.encode('utf-8'), i_[i], o_[i], h_[i], l_[i], c_[i], v_[i]))
                i += 1
            else:

                '''断链，反馈一个特征值便于后续处理'''
                connection_.send(struct.pack('6si5f', '888888'.encode('utf-8'), 8, 8, 8, 8, 8, 8))
                connection_.close()
                socket_.close()

    def run_socket_client_(self, message_=b'connect'):

        socket_ = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        socket_.connect((self.host_, self.port_))
        socket_.send(message_)
        code_, i_, o_, h_, l_, c_, v_ = struct.unpack('6si5f', socket_.recv(1024)[:32])
        socket_.close()
        return code_.decode('utf-8'), i_, o_, h_, l_, c_, v_

    def use_cpp_dll_(self,
                     path_='C:\\Users\\Perelman\\.CLion2016.1\\system\\cmake\\generated\\blog-3123958139-44930d3a\\44930d3a\\Debug\\libmy_cpp_dll_.dll'):
        h_dll_ = ctypes.CDLL(path_)
        return h_dll_
