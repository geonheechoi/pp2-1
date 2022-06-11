#ifndef NOTATIONCONVERTER_H
#define NOTATIONCONVERTER_H

#include <iostream>
#include <algorithm>
#include <cctype>

#include "NotationConverterInterface.hpp"
#include "Deck.hpp"

class NotationConverter:public NotationConverterInterface
{
public:
    std::string postfixToInfix(std::string inStr);
    std::string postfixToPrefix(std::string inStr);
    std::string infixToPostfix(std::string inStr);
    std::string infixToPrefix(std::string inStr);
    std::string prefixToInfix(std::string inStr);
    std::string prefixToPostfix(std::string inStr);
    std::string toString();
    bool isValid(std::string inStr);
    bool isOperator(char ch);
    bool isOperand(char ch);
    int precedence(char ch); 
private:
    Deck op;
   Deck op1; // Operand
    Deck op2; // Operator
    Deck deckOperands;
    Deck Operators;

};

#endif

/*
Author:Geonhee Choi && Hyunjung Lee: This code convert notation to use deque and doubly linked list
Method in mentioned under 
std::string postfixToInfix(std::string inStr)
This method takes in a string of postfix notation and returns a string in the infix notation
std::string postfixToPrefix(std::string inStr)
This method takes in a string of postfix notation and returns a string in the prefix notation
std::string infixToPostfix(std::string inStr)
This method takes in a string of infix notation and returns a string in the postfix notation
std::string infixToPrefix(std::string inStr)
This method takes in a string of infix notation and returns a string in the prefix notation
std::string prefixToInfix(std::string inStr)
This method takes in a string of prefix notation and returns a string in the postfix notation
std::string prefixToPostfix(std::string inStr)
This method takes in a string of prefix notation and returns a string in the postfix notation 
This file is hppfile for NotationConverter.cpp


*/


