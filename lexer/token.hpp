#pragma once
#ifndef __TOKEN_HPP__
#define __TOKEN_HPP__

#include<iostream>

namespace si{

    const static std::string keywords[] = {"EOF","+","-","*","/"};

    enum TokenType{
        ILLEGAl = -1,
        ENDOFFILE,
        OP_PLUS,
        OP_MINUS,
        OP_MUL,
        OP_DIV,
        OP_MOD,
        INTEGER,
        DOUBLE,
        STRING
    };

    typedef union TokenValue
    {
        int iValue;
        double fValue;
        std::string sValue;
        
        TokenValue(){
            std::cout<<"创建token value"<<std::endl;
        };
        ~TokenValue(){
            std::cout<<"销毁token value"<<std::endl;
        };
    } TokenValue,* pTokenValue;
    

    class Token
    {
    private:
        TokenType type;
        TokenValue value;
    public:
        std::string ToString();
        const pTokenValue GetValue();
        TokenType GetType();
        Token(TokenType type,std::string val);
        ~Token();
    };
    
    
}

#endif