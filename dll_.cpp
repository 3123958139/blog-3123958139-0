// 标志为导出
#define BUILD_DLL_

#include "dll_.h"
#include <iostream>
#include <fstream>

using namespace std;

IO_DLL_ void hello_(void) {
    cout << "函数调用方法如下：" << endl;
    cout << "函数格式@0：void hello_(void)" << endl;
    cout << "函数格式@1：int w_ma_(double array_[], int array_len_, int n_)" << endl;
}

IO_DLL_ int w_ma_(double array_[], int array_len_, int n_) {
    cout << "调用函数@1：int w_ma_(double array_[], int array_len_, int n_)" << endl;
    cout << "开始计算..." << endl;

    // 后面长度会移动，先保存为常量
    int m_ = n_;
    double w_ma_[array_len_];
    if (array_len_ >= n_ && n_ >= 0) {
        switch (n_) {
            case 0: {
                cout << "长度为零..." << endl;

                // 长度为 0，则所有赋 0 值
                for (int i = 0; i < m_; i++) {
                    w_ma_[i] = 0;
                }
                break;
            }
            default: {

                // 从第 n 天起算，则前 n - 1 天赋 0 值
                for (int i = 0; i < m_ - 1; i++) {
                    w_ma_[i] = 0;
                }
                while (array_len_ >= m_) {
                    double temp = 0;
                    for (int i = m_ - n_, j = 0; i < m_; i++, j++) {

                        // j 为权重，我的想法是根据数理统计得到一个权重序列再加权
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
    cout << "新建文件..." << endl;
    ofstream f_w_ma_("c:\\w_ma_.csv");
    if (!f_w_ma_) {
        cout << "新建文件错误..." << endl;
        return -1;
    }
    else {
        cout << "开始写入..." << endl;

        // 列名
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
