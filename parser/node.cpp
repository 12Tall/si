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
        left = _left;
    }

    void Node::SetRight(Node * _right){
        right = _right;
    }




    Node::Node(Token * _token){
        std::cout<<"创建Node"<<std::endl;
        token = _token;
    }
    Node::~Node(){
        delete token;
        token = nullptr;
        std::cout<<"销毁Node"<<std::endl;
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