#include<iostream>
#include"../lexer/token.hpp"
#include"node.hpp"

namespace si{
    double Node::GetValue(){
        TokenType type = token->GetType();
        if ((type & VALUE) > 0 )
        { 
            return token->GetDblValue();
        }

        if((type & OP) > 0){
            double _left = left->GetValue();
            double _right = right->GetValue();
            switch (type)
            {
                case OP_PLUS:
                    return _left + _right;
                case OP_MINUS:
                    return _left - _right;
                case OP_MUL:
                    return _left * _right;
                case OP_DIV:
                    return _left / _right;
                case OP_MOD:
                    // 取余运算暂不考虑了
                    return (int)_left % (int)_right;                
                default:
                    return 0;
            }
        }

        throw std::invalid_argument("不可取值的节点："+token->ToString());
        
    }

    void Node::SetLeft(Node * _left){
        // std::cout<<ToString()<<" 添加左节点："<<std::endl;
        left = _left;        
        // std::cout<<ToString()<<std::endl;
    }

    void Node::SetRight(Node * _right){
        // std::cout<<ToString()<<" 添加右节点："<<std::endl;
        right = _right;
        // std::cout<<ToString()<<std::endl;
    }

    std::string Node::ToString(){
        return "<"+(left==nullptr?"":left->ToString()+",")+token->ToString()+(right==nullptr?"":","+right->ToString())+">";
    }



    Node::Node(Token * _token){
        token = _token;
        std::cout<<"创建Node："<<ToString()<<std::endl;
    }
    Node::~Node(){
        std::cout<<"销毁Node"<<ToString()<<std::endl;
        delete token;
        token = nullptr;
        if (left != nullptr)
        {
            delete left;
            left = nullptr;
        }

        if (right != nullptr)
        {
            delete right;
            right = nullptr;
        }
        
        
    }
}