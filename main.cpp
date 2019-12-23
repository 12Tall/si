#include<iostream>
#include"./filereader/filereader.hpp"

int main(void){
    std::cout<<"Hello World!"<<std::endl;

    si::FileReader * rd = new si::FileReader("test.txt");

    std::cout<<rd->Read()<<std::endl;
    delete rd;
    return 0;
}