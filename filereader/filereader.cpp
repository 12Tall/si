#include<iostream>
#include<stdexcept>
#include<memory.h>
#include"filereader.hpp"

namespace si{
    char * FileReader::Read(){
        if(isEOF){
            return nullptr;
        }

        memset(buffer,0,bufferSize+1);

        readNum = fread(buffer,sizeof(char),bufferSize,file);

        if(readNum < bufferSize){
            isEOF = true;
        }

        return buffer;
    }

    FileReader::FileReader(const char * filename){
        std::cout<< "创建filereader" << std::endl;

        file = fopen(filename,"r");
        if(file == nullptr){
            // 异常机制还不熟悉，后面待修改
            throw std::invalid_argument("无法打开源文件");
        }
        std::cout<<"打开源文件"<<std::endl;

        // 多开1个字节，末尾填0，保证字符串正常结尾
        buffer = (char *)calloc(bufferSize+1,sizeof(char));
        if(buffer == nullptr){
            fclose(file);
            throw std::invalid_argument("创建缓冲区失败");
        }
        std::cout<<"创建缓冲区"<<std::endl;

        isEOF = false;
        readNum = 0;
    }

    FileReader::~FileReader(){
        free(buffer);
        std::cout<<"销毁缓冲区"<<std::endl;
        fclose(file);
        std::cout<<"关闭源文件"<<std::endl;
        buffer = nullptr;
        file = nullptr;
        std::cout<< "销毁filereader" << std::endl;
    }
}