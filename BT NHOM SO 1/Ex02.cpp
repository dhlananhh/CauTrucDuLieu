#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define max 100


struct Stack {
	int stack[max];
	int top;
};


void init (Stack &s);
int isEmpty (Stack s);
int isFull (Stack s);
void push (Stack &s, int x);
int pop (Stack &s);
int top (Stack &s);
void cal (char exp[]);

int main() {
	char postfix[max];
	
	printf("\nEnter a postfix expression: ");
	scanf("%s",postfix);
	cal(postfix);
	return 0;
}


void init (Stack &s) {
	s.top = -1;
}


int isEmpty (Stack s) {
	if (s.top == -1)
		return 1;
	else
		return 0;
}


int isFull (Stack s) {
	if (s.top == max-1)
		return 1;
	else
		return 0;
}


void push (Stack &s, int x) {
	if (isFull(s)==0) {
		s.top++;
		s.stack[s.top] = x;
	}
}


int pop (Stack &s) {
	int x;
	if (!isEmpty(s)) {
		x = s.stack[s.top];
		s.top--;
	}
	return x;
}


int top (Stack &s) {
	int x;
	if (!isEmpty(s)) {
		x = s.stack[s.top];
		return x;
	} else {
		return NULL;
	}
}


void cal (char exp[]) {
	char ch;
	int result, pEval;
	Stack s;
	init(s);
	for (int i=0; i<=strlen(exp); i++) {
		ch = exp[i];
		if (isdigit(ch)) {
			push(s,ch-'0');
		} else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^') {
			int b = pop(s);
			int a = pop(s);
			switch (ch) {
				case '+': result = a+b;
					  break;
				case '-': result = a-b;
					  break;
				case '*': result = a*b;
					  break;
				case '/': result = a/b;
					  break;
				case '%':result = a%b;
					  break;
				case '^':result = pow(a,b);
					  break;
			}
			push(s,result);
		}
	}
	
	pEval = pop(s);
	printf("\nThe postfix evaluation is: %d\n",pEval);
}
