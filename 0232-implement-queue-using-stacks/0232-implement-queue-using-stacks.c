struct Stack {
    int data;
    struct Stack* next;
};

typedef struct {
    struct Stack* inputStack;
    struct Stack* outputStack;
} MyQueue;

struct Stack* newStack() {
    return NULL;
}

void push(struct Stack** stack, int x) {
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    newNode->data = x;
    newNode->next = *stack;
    *stack = newNode;
}

int pop(struct Stack** stack) {
    if (*stack == NULL) {
        fprintf(stderr, "Error: Stack is empty.\n");
        exit(EXIT_FAILURE);
    }

    int topElement = (*stack)->data;
    struct Stack* temp = *stack;
    *stack = (*stack)->next;
    free(temp);

    return topElement;
}

int isEmpty(struct Stack* stack) {
    return stack == NULL;
}

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->inputStack = newStack();
    queue->outputStack = newStack();
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    push(&(obj->inputStack), x);
}

int myQueuePop(MyQueue* obj) {
    if (isEmpty(obj->outputStack)) {
        while (!isEmpty(obj->inputStack)) {
            push(&(obj->outputStack), pop(&(obj->inputStack)));
        }
    }

    return pop(&(obj->outputStack));
}

int myQueuePeek(MyQueue* obj) {
    if (isEmpty(obj->outputStack)) {
        while (!isEmpty(obj->inputStack)) {
            push(&(obj->outputStack), pop(&(obj->inputStack)));
        }
    }

    return obj->outputStack->data;
}

int myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj->inputStack) && isEmpty(obj->outputStack);
}

void myQueueFree(MyQueue* obj) {
    while (!isEmpty(obj->inputStack)) {
        pop(&(obj->inputStack));
    }

    while (!isEmpty(obj->outputStack)) {
        pop(&(obj->outputStack));
    }

    free(obj);
}