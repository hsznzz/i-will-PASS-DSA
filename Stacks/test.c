#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 50

typedef struct {
    char elem[MAX];
    int top; //index of stack top
} Stack;

/*************************************/
/*         HELPER FUNCTIONS          */
/*************************************/
void init(Stack *s);
bool isEmpty(Stack s);
bool isFull(Stack s);
char top(Stack s);
void pop(Stack *s);
void push(Stack *s, char data);


/*************************************/
/*            YOUR TASK              */
/*************************************/
bool isValidParentheses (char parentheses[]);

int main() {
    char parentheses[256];

    printf("Enter parentheses: ");
    scanf("%s", parentheses);

    printf("The parentheses is %s.", 
        (isValidParentheses(parentheses)) ? "VALID" : "NOT VALID");

    return 0;
}

bool isValidParentheses(char parentheses[]) {
    Stack list;
    init(&list);

    for (int i = 0; parentheses[i] != '\0'; i++) {
        char c = parentheses[i];

        /* Opening brackets → push */
        if (c == '(' || c == '{' || c == '[') {
            if (isFull(list)) return false;   /* too many opens for MAX */
            push(&list, c);
        }
        /* Closing brackets → must match top */
        else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(list)) return false;  /* nothing to match */
            char t = top(list);
            bool same = (c == ')' && t == '(') ||
                        (c == '}' && t == '{') ||
                        (c == ']' && t == '[');
            if (!same) return false;
            pop(&list);
        }
    }

    return isEmpty(list);
}




/*************************************/
/*         HELPER FUNCTIONS          */
/*************************************/
void init(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack s) {
    return (s.top == -1) ? true : false; 
}

bool isFull(Stack s) {
    return (s.top == MAX - 1) ? true : false;
}

char top(Stack s) {
    char d = '\0';
    return (!isEmpty(s)) ? s.elem[s.top] : d;
}

void pop(Stack *s) {
    if(!isEmpty(*s)) {
        s->top--;
    }
}

void push(Stack *s, char data) {
    if(!isFull(*s)) {
        s->elem[++s->top] = data; 
    }
}