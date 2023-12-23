#include<stdio.h>
#include<string>
#define MAX 200

struct Stack {
	int stack[MAX];
	int top;
};


void init (Stack &s);
int isEmpty (Stack s);
void push (Stack &s, int x);
int top (Stack s);
int pop (Stack &s);
int doUuTien (char x);
void infixSangPostfix (char in[], char post[]);
void tinh (char *Post);


int main() {
	char in[MAX], post[MAX];
	
	printf("Nhap Infix: ");
	gets(in);
	
	infixSangPostfix(in, post);
	printf("Ket qua Postfix: %s\n", post);
	tinh(&post[0]);
	return 0;
	
	// A+(B*C-(D/E^F)*G)*H
	// A*B+C*((D-E)+F)/G
	// 2*((3+4)-(5-6))
}


void init (Stack &s) {
	s.top = -1;
}


int isEmpty (Stack s) {
	if(s.top == -1)
    	return 1;
	else
    	return 0;
}


void push (Stack &s, int x) {
	if (s.top == (MAX - 1)) {
		printf("\nStack is full");
	} else {
		++s.top;
		s.stack[s.top] = x;
	}
}


int top (Stack s) {
	return (s.stack[s.top]);
}


int pop (Stack &s) {
	return s.stack[s.top--];
}


int doUuTien (char x) {
	if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1 ;
	if (x == '*' || x == '/' || x == '%')
		return 2;
	return 3;
}


void infixSangPostfix (char in[], char post[]) {
	Stack s;
	char x, token;
	int i = 0, j = 0;    // i - index of infix, j - index of postfix
	init(s);
	
	for (i = 0; in[i] != '\0'; i++) {
		token = in[i];
		if (isalnum(token))
			post[j++] = token;
		else
			if (token == '(')
				push(s, '(');
			else
				if (token == ')')
					while ((x = pop(s)) != '(')
						post[j++] = x;
				else
				{
					while (doUuTien(token) <= doUuTien(top(s)) && !isEmpty(s))
					{
						x = pop(s);
						post[j++] = x;
					}
					push(s, token);
				}
	}

	while (!isEmpty(s)) {
		x = pop(s);
		post[j++] = x;
	}
	post[j] = '\0';
}


void tinh (char *Post) {
	Stack s;
    int n1,n2,n3,num;
    char *p;
    p = &Post[0];
    
    while (*p != '\0') {
        if(isdigit(*p)) {
            num = *p - 48;
            push(s,num);
        } else {
            n1 = pop(s);
            n2 = pop(s);
            switch(*p) {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(s,n3);
        }
        p++;
    }
    printf("Ket qua =  %d", pop(s));
}