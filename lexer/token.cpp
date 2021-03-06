#include<iostream>
#include"token.hpp"
namespace si{

    TokenType Token::GetType(){
        return type;
    }

    std::string Token::GetValue(){
        return value;
    }

    int Token::GetIntValue(){
        return atoi(value.c_str());
    }

    double Token::GetDblValue(){
        return atof(value.c_str());
    }

    std::string Token::ToString(){
        std::string val;
        if (type == INTEGER || type==DOUBLE)
        {
            val = value;
        }else{
            val = "\""+value+"\"";
        }
        
        return "token("+(std::to_string(type))+","+val+")";
    }

    Token::Token(TokenType _type,std::string val){
        type = _type;
        value = val;
        std::cout<<"创建Token："<<ToString()<<std::endl;
    }

    Token::~Token(){
        std::cout<<"销毁Token："<<ToString()<<std::endl;
    }
}