#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack penuh!\n");
    } else {
        stack[++top] = value;
        printf("%d berhasil ditambahkan ke stack.\n", value);
    }
}
int pop() {
    if (top == -1) {
        printf("Stack kosong!\n");
        return -1;
    } else {
        return stack[top--];
    }
}
int peek() {
    if (top == -1) {
        printf("Stack kosong!\n");
        return -1;
    } else {
        return stack[top];
    }
}
void display() {
    if (top == -1) {
        printf("Stack kosong.\n");
    } else {
        printf("Isi stack: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    printf("Elemen di top: %d\n", peek());
    printf("Pop: %d\n", pop());
    display();

    return 0;
}
