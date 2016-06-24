// 标志为导出
#define BUILD_DLL_

#include "dll_.h"
#include <iostream>
#include <fstream>

using namespace std;

IO_DLL_ void hello_(void) {
    cout << "函数调用方法如下：" << endl;
    cout << "函数格式@0：void hello_(void)" << endl;
    cout << "函数格式@1：int w_price_rate_ma_(// double stock_index_[], \n"
            "                                 // char *stock_date_[], \n"
            "                                 double stock_open_[], \n"
            "                                 double stock_high_[], \n"
            "                                 double stock_low_[], \n"
            "                                 double stock_close_[], \n"
            "                                 // double stock_volume[], \n"
            "                                 int stock_len_, \n"
            "                                 int ma_len_)" << endl;
}

IO_DLL_ int w_price_rate_ma_(
        // double stock_index_[],
        // char *stock_date_[],
                       double stock_open_[],
                       double stock_high_[],
                       double stock_low_[],
                       double stock_close_[],
        // double stock_volume[],
                       int stock_len_,
                       int ma_len_) {

    // 计算加权价
    cout << "计算 w_price_ ..." << endl;
    double w_price_[stock_len_];
    for (int i = 0; i < stock_len_; ++i) {
        w_price_[i] = stock_open_[i] * 2
                      + stock_high_[i]
                      + stock_low_[i]
                      + stock_close_[i] * 3;
        w_price_[i] = w_price_[i] / 7;
    }

    // 计算涨跌幅
    cout << "计算 w_price_rate_ ..." << endl;
    double w_price_rate_[stock_len_];
    w_price_rate_[0] = 0;
    for (int i = 1; i < stock_len_; ++i) {
        w_price_rate_[i] = (w_price_[i] - w_price_[i - 1]) / w_price_[i - 1];
    }

    // 计算平均值
    cout << "计算 w_price_rate_ma_ ..." << endl;
    double w_price_rate_ma_[stock_len_];
    int n_ = ma_len_;
    for (int i = 0; i < ma_len_ - 1; ++i) {
        w_price_rate_ma_[i] = 0;
    }
    while (n_ <= stock_len_) {
        double temp = 0;
        for (int i = n_ - ma_len_; i < n_; ++i) {
            temp += w_price_rate_[i];
        }
        w_price_rate_ma_[n_ - 1] = temp / ma_len_;
        n_++;
    }

    // 存入文件
    cout << "存档 c:\\w_price_rate_ma_.csv ..." << endl;
    ofstream f_w_price_rate_ma_("c:\\w_price_rate_ma_.csv");
    f_w_price_rate_ma_
    << "index" << ","
    << "date" << ","
    << "open" << ","
    << "high" << ","
    << "low" << ","
    << "close" << ","
    << "volume" << ","
    << "w_price_" << ","
    << "w_price_rate_" << ","
    << "w_price_rate_ma_" << "," << endl;
    for (int i = 0; i < stock_len_; i++) {
        f_w_price_rate_ma_
        << i << ","
        << 0 << ","
        << stock_open_[i] << ","
        << stock_high_[i] << ","
        << stock_low_[i] << ","
        << stock_close_[i] << ","
        << 0 << ","
        << w_price_[i] << ","
        << w_price_rate_[i] << ","
        << w_price_rate_ma_[i] << "," << endl;
    }
    f_w_price_rate_ma_.close();
    return 0;
}
