#include <iostream>
using namespace std;

#define SIZE 100

class Stack {
	int top;

public:
	int arr[SIZE];

	Stack() {
		 top = -1; 
	};
	void push(int x);
	void pop();
	int peek();
	bool isEmpty();
	bool isPalindrome();
};


void Stack::push(int x){
	if (top >= (SIZE - 1)) {
		cout << "Stack is full" << endl;
	}
	else {
		top++;
		arr[top] = x;
		cout << x << " added into stack" << endl;
	}
}
void Stack::pop(){
	if (!(top == -1)) {
		int x = arr[top--];
	}
}
int Stack::peek(){
	if (top == -1) {
		cout << "Stack is Empty";
		return -1;
	}
	else {
		return arr[top];
	}
}
bool Stack::isEmpty() { return (top == -1); }

Stack reverse_stack(Stack array) {
	Stack tempStack;
	while (!array.isEmpty()) {
		int item = array.peek();
		array.pop();
		tempStack.push(item);
	}
	return tempStack;
}

// question 5
Stack merge_stack(Stack& first, Stack& second) {
	Stack newStack;

	first = reverse_stack(first);
	while (!first.isEmpty()) {
		newStack.push(first.peek());
		first.pop();
	}
	while (!second.isEmpty()){
		newStack.push(second.peek());
		second.pop();
	}
	return newStack;
}

//question 7
Stack merge_step_by_step(Stack& first_stack, Stack& second_stack) {
	Stack new_stack;

	while (!first_stack.isEmpty() && !second_stack.isEmpty()) {
		new_stack.push(first_stack.peek());
		first_stack.pop();
		new_stack.push(second_stack.peek());
		second_stack.pop();
	}

	while (!first_stack.isEmpty()) {
		new_stack.push(first_stack.peek());
		first_stack.pop();
	}

	while (!second_stack.isEmpty()) {
		new_stack.push(second_stack.peek());
		second_stack.pop();
	}

	return new_stack;

}

// question 9
bool Stack::isPalindrome() {
	Stack newStack = *this;
	Stack temp = reverse_stack(newStack);
	bool is_palindrome = true;
	for (int i = 0; i < (this->top + 1) / 2; i++) {
		if (newStack.peek() != temp.peek()) {
			is_palindrome = false;
			break;
		}
		else {
			newStack.pop();
			temp.pop();
		}
	}
	return is_palindrome;
}
	

void print_stack(Stack array) {
	Stack tempStack = array;
	while (!tempStack.isEmpty()) {
		cout << tempStack.peek() << " ";
		tempStack.pop();
	}
	cout << endl;
}



int main() {

	Stack m;

	m.push(1);
	m.push(2);
	m.push(3);

	Stack a;

	a.push(4);
	a.push(5);
	a.push(6);
	a.push(7);
	a.push(8);
	a.push(9);

/*
	//question 5
	m = reverse_stack(m);
	print_stack(m);
	cout << m.peek() << endl;
	print_stack(a);
	cout << a.peek() << endl;
	
	cout << endl << "- - - - - - - - - - - - - - - - - - - - - - - -" << endl;

	Stack thired = merge_stack(m, a);
	print_stack(thired);
*/
/*
	//question 7
	Stack my_stack;
	my_stack = merge_step_by_step(m,a);
	print_stack(my_stack);
*/


	//question 9
	Stack abc;

	abc.push(1);
	abc.push(1);
	abc.push(2);
	abc.push(3);
	abc.push(4);
	abc.push(2);
	abc.push(1);
	abc.push(1);

	cout << abc.isPalindrome();

	return 0;
}