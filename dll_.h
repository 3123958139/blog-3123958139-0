// 预编译只运行一次
#pragma once

#ifndef DLL__H_
#define DLL__H_
#endif

// 导入导出宏定义
#ifdef BUILD_DLL_
#define IO_DLL_ __declspec(export)
#else
#define IO_DLL_ __declspec(import)
#endif

// 导出函数为标准 c 格式
extern "C" {
IO_DLL_ void hello_(void);
IO_DLL_ int w_ma_(double array_[], int array_len_, int n_);
}
