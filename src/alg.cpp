// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
#include <cctype>
#include <cstdint>

uint8_t prioritet(char ch) {
  if (ch == '*' || ch == '/') return 2;
  if (ch == '+' || ch == '-') return 1;
  return 0;
}
std::string infx2pstfx(const std::string& inf) {
  TStack<char, 100> stack;
  std::string finalInf;
  for (size_t i = 0; i < inf.length(); i++) {
    char cur = inf[i];
    if (isdigit(cur)) {
      while (i < inf.length() && isdigit(inf[i])) {
        finalInf += inf[i];
          i++;
      }
      finalInf += ' ';
      i--;
    }
    else if (cur == '(') stack.push(cur);
    else if (cur == ')') {
      while (!stack.isEmpty() && stack.getTop() != '(') {
        finalInf += stack.pop();
          finalInf += ' ';
      }
      stack.pop();
    }
    else if (cur == '+' || cur == '*' || cur == '-' || cur == '/') {
      while (!stack.isEmpty() && prioritet(stack.getTop()) >= prioritet(cur)) {
        finalInf += stack.pop();
        finalInf += ' ';
      }
      stack.push(cur);
    }
  }
  while (!stack.isEmpty()) {
    finalInf += stack.pop();
    finalInf += ' ';
  }
  if (!finalInf.empty() && finalInf.back() == ' ') {
    finalInf.pop_back();
  }
  return finalInf;
}
int eval(const std::string& pref) {
  TStack<int, 100> stack;
  for (size_t i = 0; i < post.length(); i++) {
    char cur = post[i];
    int digit = 0;
    if (cur == ' ') {
      continue;
    }
    if (isdigit(cur)) {
      while (i < post.length() && isdigit(post[i])) {
        digit = digit * 10 + (post[i] - '0');
        i++;
      }
      stack.push(digit);
      i--;
    }
    else if (cur == '+' || cur == '*' || cur == '-' || cur == '/') {
      int second = stack.pop();
      int first = stack.pop();
      int finalPost = 0;
      switch (cur) {
        case '+':
          finalPost = first + second;
          break;
        case '-':
          finalPost = first - second;
          break;
        case '*':
          finalPost = first * second;
          break;
        case '/':
          finalPost = first / second;
          break;
        default:
          break;
        }
        stack.push(finalPost);
    }
  }
  return stack.pop();
}
