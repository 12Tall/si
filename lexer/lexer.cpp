#include<iostream>
#include"../filereader/filereader.hpp"
#include"token.hpp"
#include"lexer.hpp"

namespace si{
    void Lexer::ReadChar(){        
        do{
            ch = str[pos++];
        }while ((ch==' ')||(ch=='\n')||(ch=='\r'));
    }

    Token * Lexer::GetToken(){                
        if(pos == FileReader::bufferSize){            
            std::cout<<"从文件中读取字符串"<<std::endl;
            str = reader->Read();
            if (str == nullptr)
            {
                return new Token(ENDOFFILE,nullptr);
            }
            pos = 0;    
        }

        ReadChar();

        temp = std::string("");
        
        TokenType type = INTEGER;
        while ((ch>='0' && ch<='9')||ch=='.')
        {
            if (type==DOUBLE && ch=='.')
            {
                // 其实这里分行读取会更好一些，但是C++ 实在是太难了
                throw std::invalid_argument("不能多个'.'");
            }
            if (ch=='.')
            {
                type = DOUBLE;
            }         
            
            temp += ch;            
            ReadChar();
        }

        if (temp.length() > 0)
        {            
            pos--;  // 为了避免跳过token后面的一位
            return new Token(type,temp);
        }
        
        

        // while((ch>='a' && ch<='z')||(ch>='a' && ch<='z'))
        // {
        //     // todo
        //     // read string
        // }
        
        switch (ch)
        {
            case '+':
                return new Token(OP_PLUS,std::string("+"));
            case '-':
                return new Token(OP_MINUS,"-");
            case '*':
                return new Token(OP_MUL,"*");
            case '/':
                return new Token(OP_DIV,"/");            
            default:
                return new Token(ILLEGAl,"illegal");
        }
        

    }

    Lexer::Lexer(const char* filename){
        std::cout<<"创建Lexer"<<std::endl;
        pos= FileReader::bufferSize;
        reader = new FileReader(filename);
    }
    Lexer::~Lexer(){
        delete reader;
        reader = nullptr;
        std::cout<<"销毁Lexer"<<std::endl;
    }
}