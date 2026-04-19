// Copyright 2026 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
  private:
	T data[size];
	int top;
public:
	TStack() : top(-1) {}
	void push(T value) { if (top < size - 1) data[++top] = value; }
	T pop() {
    if (!isEmpty()) { return data[top--]; }
		return T();
	}
	bool isEmpty() { return top == -1; }
	T getTop() {
		if (!isEmpty()) return data[top];
		return T();
	}
};

#endif  // INCLUDE_TSTACK_H_
