#include <stdio.h>
#include <string.h>

#define MAX 7

void initQueue(int *f, int *r, char queue[]) {
    *f = *r = -1;
    for (int i = 0; i < MAX; i++) {
        queue[i] = '\0';
    }
}

int isEmpty(int f) {
    return (f == -1);
}

int isFull(int f, int r) {
    return ((r + 1) % MAX == f);
}

void insert(char queue[], int *f, int *r, char color) {
    if (isFull(*f, *r)) {
        printf("Overflow! Cannot insert %c.\n", color);
        return;
    }
    if (isEmpty(*f)) {
        *f = *r = 0;
    } else {
        *r = (*r + 1) % MAX;
    }
    queue[*r] = color;
    printf("Inserted %c.\n", color);
}

void delete(char queue[], int *f, int *r) {
    if (isEmpty(*f)) {
        printf("Underflow! Queue is empty.\n");
        return;
    }
    char color = queue[*f];
    if (*f == *r) {
        *f = *r = -1; // Queue becomes empty
    } else {
        *f = (*f + 1) % MAX;
    }
    printf("Deleted %c.\n", color);
}

void display(char queue[], int f, int r) {
    if (isEmpty(f)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    int i = f;
    do {
        printf("%c ", queue[i]);
        i = (i + 1) % MAX;
    } while (i != (r + 1) % MAX);
    printf("\n");
}

int main() {
    char queue[MAX];
    int f, r;
    initQueue(&f, &r, queue);

    char colors[] = "VIBGOYR";

    // Insert all rainbow colors
    for (int i = 0; i < strlen(colors); i++) {
        insert(queue, &f, &r, colors[i]);
        display(queue, f, r);
    }

    // Perform deletions
    delete(queue, &f, &r);
    display(queue, f, r);

    delete(queue, &f, &r);
    display(queue, f, r);

    return 0;
}
