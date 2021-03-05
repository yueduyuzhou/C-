#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>

typedef struct {
    int* queval;
    int front, rear;
    int maxsize, quesize;
} MyCircularDeque;

/** Initialize your data structure here. Set the size of the deque to be k. */

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    assert(obj);
    obj->front = obj->rear = obj->quesize = 0;
    obj->maxsize = k;
    obj->queval = (int*)malloc(sizeof(int) * k);
    assert(obj->queval);
    int tmp = 0;
    while (tmp < k)
        obj->queval[tmp++] = 0;
    return obj;
}

bool myCircularDequeIsFull();
bool myCircularDequeIsEmpty();

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj))
        return false;
    obj->front -= 1;
    if (obj->front == -1)
        obj->front = obj->maxsize - 1;
    obj->queval[obj->front] = value;
    obj->quesize++;
    return true;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj))
        return false;
    if (obj->queval[obj->rear] != 0)
        obj->rear = (obj->rear + 1) % obj->maxsize;

    obj->queval[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->maxsize;
    obj->quesize++;
    return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj))
        return false;
    obj->queval[obj->front] = 0;
    obj->front = (obj->front + 1) % obj->maxsize;
    obj->quesize--;
    return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj))
        return false;
    obj->rear -= 1;
    if (obj->rear == -1)
        obj->rear = obj->maxsize - 1;
    obj->queval[obj->rear] = 0;
    obj->quesize--;
    return true;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj))
        return -1;
    return obj->queval[obj->front];
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj))
        return -1;
    return obj->queval[obj->rear - 1 == -1 ? obj->maxsize - 1 : obj->rear - 1];
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if (obj->quesize == 0)
        return true;
    else
        return false;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if (obj->quesize == obj->maxsize)
        return true;
    else
        return false;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->queval);
    obj->queval = NULL;
    free(obj);
    obj = NULL;
}

int main()
{
	return 0;
}