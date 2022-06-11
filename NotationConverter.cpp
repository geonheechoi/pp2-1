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
This is cpp file for Assignment 2

*/
#include "NotationConverter.hpp"
//#include "catch.hpp"
#include "Deck.hpp"
#include "Deck.cpp"
#include "DL.hpp"
#include "DL.cpp"
//#include "NotationConverterInterface.hpp"

//check the operator
bool NotationConverter::isOperator(char ch) {

  
  if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    return 1;
  else
    return 0;

  
}

bool NotationConverter::isOperand(char ch) {
  // operand denoted by a letter (upper or lower case)
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    return 1;
  else
    return 0;
}
//check the string is valid
bool NotationConverter::isValid(std::string inStr) {
  int result = 0;

  for (int i = 0; inStr[i] != '\0'; i++) {
    if ((inStr[i] >= 'a' && inStr[i] <= 'z') ||
        (inStr[i] >= 'A' && inStr[i] <= 'Z') || (inStr[i] == '(') ||
        (inStr[i] == ')') || (inStr[i] == '+') || (inStr[i] == '-') ||
        (inStr[i] == '*') || (inStr[i] == '/') || (inStr[i] == ' '))
      result = 1;
    else
      result = 0;
  }
  return result;
}

// check operator priority
int NotationConverter::precedence(char ch) {
  if (ch == '*' || ch == '/')
    return 2;
  else if (ch == '+' || ch == '-')
    return 1;
  else
    return 0;
}

// Convert postfix notation to infix notation
std::string NotationConverter::postfixToInfix(std::string inStr) {


    if (!isValid(inStr)) {
        throw inStr;
      }
        for (unsigned int i = 0; i<inStr.size(); i++) {
          if (inStr[i] != ' '){
         //   throw inStr;
           if (isOperator(inStr[i])){
            // push operand
            op2.insertBack(inStr[i]);
             }else{
            // push operator
            op1.insertBack(inStr[i]);
        }
    }
 }

  if (op2.size() != op1.size()-1) {
    throw inStr;
  }

  op.insertBack('(');
  int n=op2.size();
  for ( int i = 1; i < n - 1; i++) {
    op.insertBack('(');
  }
  while (op1.empty() == false) {
    op.insertBack(op1.front());
    op1.removeFront();
    if (op2.empty() == false) {
      if (op2.size() == 2) {
        op.insertBack(')');
        op.insertBack(op2.back());
        op2.removeBack();
        op.insertBack('(');
      } 
      else {
        op.insertBack(op2.front());
        op2.removeFront();
      }
    }
  }
  op.insertBack(')');

  for (int i = 1; i < n-1; i++) {
    op.insertBack(')');
  }

  return toString();




  
}
// Convert infix notation to postfix notation
std::string NotationConverter::infixToPostfix(std::string inStr) {

  
   if (inStr[0] != '(') {
        throw inStr;
    }

    for (unsigned int i = 0; i < inStr.size(); i++) {
        while (inStr[i] != ')' && inStr[i] != *inStr.end()) {
            if (inStr[i] != ' ') {
                if (isOperator(inStr[i])) {
                    op1.insertBack(inStr[i]);
                }
                else if (inStr[i] != '(') {
                    op.insertBack(inStr[i]);
                }
            }
            i++;
        }

        int num = op1.size();
        for (int i = 0; i < num; i++) {
            if (op1.size() == 2) {
                op.insertBack(op1.back());
                op1.removeBack();
            }
            else {
                op.insertBack(op1.front());
                op1.removeFront();
            }
        }
    }
    return toString();

}
// Convert postfix notation to prefix notation
std::string NotationConverter::postfixToPrefix(std::string inStr) {
  return infixToPrefix(postfixToInfix(inStr));
}



// Convert infix notation to prefix notation
std::string NotationConverter::infixToPrefix(std::string inStr) {
  if (inStr[0] != '(') {
    throw inStr;
  }
  for (long unsigned int i = 0; i < inStr.size(); i++) {
    while (inStr[i] != ')' && inStr[i] != *inStr.end()) {
      if (inStr[i] != ' ') {
        if (isOperator(inStr[i])) {
          if (inStr[i - 2] == ')') {
            op.insertFront(inStr[i]);
          } else {
            op.insertBack(inStr[i]);
          }
        } else if (inStr[i] != '(') {
          op1.insertBack(inStr[i]);
        }
      }
      i++;
    }
    int num = op1.size();
    for (int i = 0; i < num; i++) {
      op.insertBack(op1.front());
      op1.removeFront();
    }
  }
  return toString();
}

// Convert prefix notation to postfix notation
std::string NotationConverter::prefixToInfix(std::string inStr) {
    if (!isOperator(inStr[0])) {
        throw inStr;
    }
    bool valid = false;
    int counter = 0;
    
    for (unsigned int i = 0; i < inStr.size(); i++) {
        if (inStr[i] != ' ') {
            if(isOperator(inStr[i]))
            {
                op1.insertBack(inStr[i]);
                op.insertBack('(');
                counter++;
                valid = false;
            }
            else {
                op.insertBack(inStr[i]);
    
                if (valid == true) {
                    op.insertBack(')');
                    counter--;
                }
                  
                if (op1.empty() == false) {
                    op.insertBack(op1.back());
                    op1.removeBack();
                    valid = 1;
                }
            }
       }
    }
      
    if (counter != 0) {
        while (counter != 0) {
        op.insertBack(')');
        counter--;
        }
    }
    return toString();
}

// Convert prefix notation to postfix notation
std::string NotationConverter::prefixToPostfix(std::string inStr) {
  return infixToPostfix(prefixToInfix(inStr));
}

std::string NotationConverter::toString() {
  std::string output;

  if (op.empty() == true) {
    return output;
  }
  int size = op.size();

  for (int i = 0; i < size; i++) {
    if (op.front() == ')') {
      output.pop_back();
    }
    output += op.front();

    if (op.front() != '(') {
      output += ' ';
    }
    op.removeFront();
  }
  output.pop_back();

  return output;
}
