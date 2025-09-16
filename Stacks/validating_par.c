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

bool isValidParentheses (char parentheses[]) {
    // Implementation here...
    Stack list;
    init(&list);

    int i = 0;
    for(i = 0; parentheses[i] != '\0'; i++){
        char c = parentheses[i];

        switch(c){
            case '(': case '{': case '[':
                if(!isFull(list)){
                    push(&list, c);
                }
                break;

            case ')': case '}': case ']':
                if(!isEmpty(list)){
                    char t = top(list);

                    bool pair = (t == '(' && c == ')') || (t == '{' && c == '}') || (t == '[' && c == ']');
                    if(!pair){
                        return false;
                    }

                    pop(&list);
                } else {
                    return false;
                }
                break;
                
            default:
                break;
        }
    }
    if(!isEmpty(list)){
        return false;
    }
    
    return true;
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