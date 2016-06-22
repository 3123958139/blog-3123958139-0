// 标志为导出
#define BUILD_MY_CPP_DLL_

#include "my_cpp_dll_.h"
#include <iostream>
#include <fstream>

using namespace std;

IO_MY_CPP_DLL_ void hello_(void) {
    cout << "函数调用方法如下：" << endl;
    cout << "调用函数@0：void hello_(void)" << endl;
    cout << "调用函数@1：int w_ma_(double array_[], int array_len_, int n_)" << endl;
}

IO_MY_CPP_DLL_ int w_ma_(double array_[], int array_len_, int n_) {
    cout << "调用函数@1：int w_ma_(double array_[], int array_len_, int n_)" << endl;
    cout << "开始计算..." << endl;
    int m_ = n_;
    double w_ma_[array_len_];
    if (array_len_ >= n_ && n_ >= 0) {
        switch (n_) {
            case 0: {
                cout << "长度为零..." << endl;
                for (int i = 0; i < m_; i++) {
                    w_ma_[i] = 0;
                }
                break;
            }
            default: {
                for (int i = 0; i < m_ - 1; i++) {
                    w_ma_[i] = 0;
                }
                while (array_len_ >= m_) {
                    double temp = 0;
                    for (int i = m_ - n_, j = 0; i < m_; i++, j++) {
                        temp += array_[i] * j;
                    }
                    w_ma_[m_ - 1] = temp / n_;
                    m_++;
                }
                break;
            }
        }
    }
    else {
        cout << "长度错误..." << endl;
        return -1;
    }
    cout << "存入文件..." << endl;
    ofstream f_w_ma_("c:\\w_ma_.csv");
    if (!f_w_ma_) {
        cout << "打开错误..." << endl;
        return -1;
    }
    else {
        f_w_ma_ << "index_" << "," << "price_" << "," << "w_ma_" << "," << endl;
        for (int i = 0; i < array_len_; i++) {
            f_w_ma_ << i << "," << array_[i] << "," << w_ma_[i] << "," << endl;
        }
        cout << "完成写入..." << endl;
        f_w_ma_.close();
        cout << "查看文件...\nc:\\w_ma_.csv" << endl;
        return 1;
    }
}
