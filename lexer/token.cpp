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
            val = value.sValue;
            break;
        }

        return "token("+(std::to_string(type))+","+val+")";
    }

    Token::Token(TokenType _type,pTokenValue val){
        type = _type;
        switch (type)
        {
            case INTEGER:
                value.iValue = val->iValue;
                break;
            case DOUBLE:
                value.fValue = val->fValue;
                break;
            case STRING:
                value.sValue = val->sValue;
                break;
            default:
                value.sValue = keywords[type];
                break;
        }
    }

    Token::~Token(){

    }
}