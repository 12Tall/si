#pragma once
#ifndef __LEXER_HPP__
#define __LEXER_HPP__

#include<iostream>
#include"../filereader/filereader.hpp"
#include"token.hpp"

namespace si{
    class Lexer
    {
        private:
            FileReader * reader;
            int pos;
            char ch;
            char* str;
            std::string temp;
            void ReadChar();
        public:
            Token * GetToken();
            Lexer(const char* file);
            ~Lexer();
        };    
}


#endif