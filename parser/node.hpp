#pragma once
#ifndef __NODE_HPP__
#define __NODE_HPP__

#include<iostream>
#include"../lexer/token.hpp"

namespace si{
    class Node
    {
        private:
            Node * left;
            Node * right;
            Token * token;
        public:
            void SetLeft(Node * _left);
            void SetRight(Node * _right);
            double GetValue();
            Node(Token * _token);
            ~Node();
    };    
}


#endif