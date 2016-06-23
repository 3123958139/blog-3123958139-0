// 预编译只运行一次
#pragma once

#ifndef DLL__H
#define DLL__H
#endif

// 导入导出宏定义
#ifdef BUILD_DLL_
#define IO_DLL_ __declspec(export)
#else
#define IO_DLL_ __declspec(import)
#endif

// 导出函数为标准 c 格式
extern "C" {

// 该函数用于声明函数调用方法
IO_DLL_ void hello_(void);

// 该函数用于计算加权平均值
IO_DLL_ int w_ma_(double array_[], int array_len_, int n_);
///////////////////////////////////////////////////////////////////////////////////////////////
// 该函数用于加载 open，high，low，close 数组
IO_DLL_ int w_rate_ma_(// char *stock_date_[],
                       double stock_open_[],
                       double stock_high_[],
                       double stock_low_[],
                       double stock_close_[],
        // double stock_volume[],
                       int stock_len_,
                       int ma_len_);
}
