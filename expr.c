#include <stdio.h>
#include <stdlib.h>

#define NUM 1
#define ADD 2
#define SUB 3
#define MUL 4
#define DIV 5
#define FUN 6

#define SUCCESS 0
#define FAILURE 1
#define MAXNUMS 100

int getop(char *s);
void push(double val);
double pop(void);

int main(int argc, char *argv[])
{
	int c;
	int type, op2;
	
	if (argc > 3) {
		while((--argc > 0) && (type = getop(*++argv)))  {
			//printf("%s", *argv);
			
			switch(type) {
			case NUM:
				push(atof(*argv));
				//printf("::%d\n", pop());
				break;
			case FUN:
				//printf("function found %s\n", *argv);
				break;
			case ADD:
				push(pop() + pop());
				//printf("exe\n");
				break;
			case SUB:
				op2 = pop();
				push(pop() - op2);
				break;
			case MUL:
				push(pop() * pop());
				break;
			case DIV:
				op2 = pop();
				if (op2)
					push(pop() / op2);
				else
					printf("FUNC_MAIN: ZERO-DIVISOR");
				break;
			default:
				printf("FUNC_MAIN: CANNOT HANDLE THE INPUT [ASCII:%d] (%c)\n", type, type);
				break;
			}
			
		}
	} else {
		printf("USAGE: expr <num1> <num2> <num3> ... <+-x/> <+-x/> ...\n");
		return FAILURE;
	}
	
	
	printf("OUTPUT : %.6f\n", pop());
	
	return SUCCESS;
}

#include <ctype.h>

int getop(char *arg)
{
	int i, j;
	char c = *arg;
	/*
	for(i = 0; isdigit(*arg++); i++)
		;
	*/
	if (isdigit(*arg)) {
		for(j = 0; isdigit(*arg++); j++)
			;
		if (j > 0)
			return NUM;
	} else if (isupper(*arg)) {
		return FUN;
	} else {
		switch(c) {
		case '+':
			return ADD;
		case '-':
			return SUB;
		case 'x':
			return MUL;
		case '/':
			return DIV;
		default:
			return c;
		}
	}
}


#define MAXBUF 100

double buff[MAXBUF];
double *bufp = buff;

void push(double val)
{
	if (bufp < buff + MAXBUF)
		*bufp++ = val;
	else
		printf("FUNC_PUSH: BUFFER FULL\n");
}

double pop(void)
{
	if (bufp >= buff)
		return *--bufp;
	else {
		printf("FUNC_POP: BUFFR EMPTY\n");
		return 0;
	}
}