#pragma once
#ifndef __FILEREADER_HPP__
#define __FILE_READER_HPP__

#include<iostream>

namespace si{
    class FileReader
    {
    private:
        FILE * file;  // 文件指针
        char * buffer;  // 字符缓冲区
        bool isEOF;  // 是否读完文件
        int readNum;  // 实际读取的字符数
    public:
        const int bufferSize = 1024;  // 缓冲区大小
        char * Read();  // 读取
        FileReader(const char * filename);  // 构造函数
        ~FileReader();
    };    
}

#endif