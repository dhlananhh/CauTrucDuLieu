#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define max 30


struct Stack {
	int items[max];
	int top;
} s;

void init();
void push (char x);
char pop();
int match (char a, char b);
int check (char exp[]);


int main() {
	Stack s;
	char exp[max];
	int valid;
	
	init();
	printf("Enter an algebraic expression: ");
    fflush(stdin);
	gets(exp);
	
	valid = check(exp);
	if (valid == 1)
        printf("\nValid expression");
    else
    	printf("\nInvalid expression");
	
	return 0;
}


int check (char exp[]) {
	char temp;
	int i;
	
	for (i=0; i<strlen(exp); i++) {
		if(exp[i]=='{' || exp[i]=='[' || exp[i]=='(')
	       push(exp[i]);
	    if(exp[i]=='}' || exp[i]==']' || exp[i]==')') {
	    	if (s.top == -1) {
	    		printf("\nRight parentheses are more than left parentheses");
	    		return 0;
			} else {
				temp = pop();
				if (!match(temp, exp[i])) {
					printf("\nMismatched parentheses are : ");
                    printf("%c and %c\n", temp, exp[i]);
                    return 0;
				}
			}
		}
	}
	
	if (s.top == -1) {
		printf("Balanced Parentheses\n");
        return 1;
	} else {
		printf("Left parentheses more than right parentheses\n");
        return 0;
	}
}


void init() {
	s.top = -1;
}


void push (char x) {
	if (s.top == max-1)
		printf("\nOverflow");
	else {
		s.top++;
		s.items[s.top] = x;
	}
}


char pop() {
	if (s.top == -1) {
		printf("\nUnderflow");
		exit(1);
	} else
		return s.items[s.top--];
}


int match (char a, char b) {
	if (a=='{' && b=='}')
		return 1;
	if (a=='[' && b==']')
		return 1;
	if (a=='(' && b==')')
		return 1;
	return 0;
}