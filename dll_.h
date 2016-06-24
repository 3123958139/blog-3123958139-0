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

// 导出函数为标准 c 格式，确保导出函数名不改变
extern "C" {

// 该函数用于声明函数调用方法
IO_DLL_ void hello_(void);

// 该函数综合计算 ma 值
IO_DLL_ int w_rate_ma_(
        // double stock_index_[],
        // char *stock_date_[],
                       double stock_open_[],
                       double stock_high_[],
                       double stock_low_[],
                       double stock_close_[],
        // double stock_volume[],
                       int stock_len_,
                       int ma_len_);
}
