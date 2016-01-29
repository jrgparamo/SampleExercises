/*
* Author: KELLEY A BOOK ON C
* File: stack.c
* Description: A stack implementation in C
*				teaching Abstract Data Types (ADT)
* Student Name: Jorge Paramo
* Student UT EID: JP33534
* Course Name: CS 429
* Unique Number: 53695 after semester
* Date Created: 5.23.14
* Date Last Modified: 5.23.14
*/

/* An implementation of type stack. */

#define	 MAX_LEN 1000
#define	 EMPTY -1
#define  FULL (MAX_LEN - 1)

//Use typedef to give a new name boolean
typedef  enum boolean {false, true} boolean;

// Declares the structure type struct stack and at the same time
// uses a typedef to give "struct stack" the new name stack
// char array (String) with integer top
typedef struct stack
{
	char s[MAX_LEN];
	int top;
} stack;

// To reset or initilize a stack
void reset(stack * stk) 
{ 
	stk -> top = EMPTY; 
}

// Pushes element into stack *Assumes stack is not full 
void push(char c, stack *stk)
{
	stk -> top++;
	stk -> s[stk -> top] = c;
}

// Pops element from stack *Assumes stack is not empty
char pop(stack *stk) 
{ 
	return (stk -> s[stk -> top--]); 
}

// Returns top element from stack
char top(const stack *stk) 
{ 
	return (stk -> s[stk -> top]); 
}

// Returns casted boolean 1(true) or 0(false) if stack is empty
boolean empty(const stack *stk)
{
	return ((boolean) (stk -> top == EMPTY));
}

// Returns casted boolean 1(true) or 0(false) if stack is full
boolean full(const stack *stk)
{
	return ((boolean) (stk -> top == FULL));
}

/* Test of the stack implementation */
/* By reversing a string */

#include <stdio.h>

int main(void)
{
	// Initilized variables
	char str[] = "I love God.";
	int i; 
	stack s;
	// Initialized stack s
	reset(&s);

	printf("In the string: %s\n", str);

	// Pushes a char from str into the stack
	for (int i = 0; str[i] != '\0'; ++i)
	{
		// Condition check stack is not full
		if (!full(&s))
		{
			push(str[i], &s);
		}
		else
		{
			printf("Error: Stack is Full!\n");
		}
	}

	printf("From the stack: ");

	// Pops a char from str off the stack
	// Condition checks the stack is not empty
	while(!empty(&s))
	{
		// Puts char on user screen
		putchar(pop(&s));
	}
	putchar('\n');
	return 0;
}