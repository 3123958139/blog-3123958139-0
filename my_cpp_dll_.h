// 预编译只运行一次
#pragma once

#ifndef MY_CPP_DLL__H_
#define MY_CPP_DLL__H_
#endif

// 导入导出宏定义
#ifdef BUILD_MY_CPP_DLL_
#define IO_MY_CPP_DLL_ __declspec(export)
#else
#define IO_MY_CPP_DLL_ __declspec(import)
#endif

// 导出函数为标准 c 格式
extern "C" {
IO_MY_CPP_DLL_ void hello_(void);
IO_MY_CPP_DLL_ int w_ma_(double array_[], int array_len_, int n_);
}
