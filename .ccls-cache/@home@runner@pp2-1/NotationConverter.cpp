#include "NotationConverter.hpp"

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
  
    if (isValid(inStr)) {
        for (int i = 0; inStr[i] != '\0'; i++) {
          if (inStr[i] == ' ')
            throw inStr;
          else if (isOperand(inStr[i]))
            // push operand
            op1.insertBack(inStr[i]);
          else
            // push operator
            op2.insertBack(inStr[i]);
        }
    } else {
    throw inStr;
  }

  if (op1.size() - 1 != op2.size()) {
    throw inStr;
  }

  op.insertBack('(');

  for (int i = 1; i < op2.size() - 1; i++) {
    op.insertBack('(');
  }
  while (op1.empty() == 0) {
    op.insertBack(op1.front());
    op1.removeFront();

    if (op2.empty() == 0) {
      if (op2.size() == 2) {
        op.insertBack(')');
        op.insertBack(op2.back());
        op2.removeBack();
        op.insertBack('(');
      } else {
        op.insertBack(op2.front());
        op2.removeFront();
      }
    }
  }
  op.insertBack(')');

  for (int i = 1; i < op2.size()-1; i++) {
    op.insertBack(')');
  }

  return toString();
}

// Convert postfix notation to prefix notation
std::string NotationConverter::postfixToPrefix(std::string inStr) {
  return infixToPrefix(postfixToInfix(inStr));
}

// Convert infix notation to postfix notation
std::string NotationConverter::infixToPostfix(std::string inStr) {

  /*
  if (!isOperator(inStr[0])) {
    throw std::runtime_error("not a valid operation");
  }

  while (deckOperands.size() != 0) {
    deckOperands.removeFront();
  }

  int n = inStr.size();
  //  std::string  letter;
  std::string convertedString;

  for (int i = 0; i < n; i++) {
    inStr = "";

    inStr.push_back(inStr[i]);

    if (isOperand(inStr[i])) {
      convertedString += inStr[i];
    } else if (inStr[i] == '(') {
      deckOperands.insertFront(inStr[i]);
    } else if (inStr[i] == ')') {
      // while(deckOperands.front() != "(" && !(deckOperands.empty()) ) {
      convertedString += deckOperands.front();
      deckOperands.removeBack();
    }
    // remove the head
    if (inStr.front() == '(') {
      deckOperands.removeFront();
    }

    // if the letter is an operator
    if (isOperator(inStr[i])) {
      if (deckOperands.empty()) {
        deckOperands.insertFront(inStr[i]);
      } else {
        char tempChar;
        char x = deckOperands.front();
        tempChar = x;

        if (precedence(inStr[i]) > precedence(tempChar)) {
          deckOperands.insertFront(inStr[i]);
        } else if ((precedence(inStr[i]) == precedence(tempChar)) &&
                   inStr[i] == '^') {
          deckOperands.insertFront(inStr[i]);
        } else {
          while ((!deckOperands.empty()) &&
                 (precedence(inStr[i]) <= precedence(tempChar))) {
            convertedString += deckOperands.front();
            deckOperands.removeBack();
          }
          std::string y = "";
          y.push_back(inStr[i]);
          deckOperands.insertFront(inStr[i]);
        }
      }
    }
  }

  while (!deckOperands.empty()) {
    convertedString += deckOperands.front();
    deckOperands.removeFront();
  }

  std::string spacedString = "";

  int z = convertedString.size();
  for (int i = 0; i < z; i++) {
    spacedString += convertedString[i];
    if (i < z - 1) {
      spacedString += " ";
    }
  }

  return spacedString;
 */
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

// Convert infix notation to prefix notation
std::string NotationConverter::infixToPrefix(std::string inStr) {
  if (inStr[0] != '(') {
    throw inStr;
  }
  for (unsigned int i = 0; i < inStr.size(); i++) {
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
    
    for (int i = 0; i < inStr.size(); i++) {
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
