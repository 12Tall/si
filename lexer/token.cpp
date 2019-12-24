#include<iostream>
#include"token.hpp"
namespace si{

    TokenType Token::GetType(){
        return type;
    }

    const pTokenValue Token::GetValue(){
        return &value;
    }

    std::string Token::ToString(){
        std::string val;
        switch (type)
        {
        case INTEGER:
            val = std::to_string(value.iValue);
            break;
        case DOUBLE:
            val = std::to_string(value.fValue);
            break;        
        default:
            val = std::string(value.sValue);
            break;
        }

        return "token("+(std::to_string(type))+","+val+")";
    }

    Token::Token(TokenType _type,std::string val){
        type = _type;
        switch (_type)
        {
            case INTEGER:
                value.iValue = atoi(val.c_str());
                break;
            case DOUBLE:
                value.fValue = atof(val.c_str());
                break;
            case STRING:
                value.sValue = std::string(val);
                break;
            default:
                value.sValue = keywords[type];
                break;
        }
    }

    Token::~Token(){

    }
}