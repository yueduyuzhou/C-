#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>

typedef struct {
    int val[100];
    int quesize;
    int front;
    int rear;
} Queue;

typedef struct {
    Queue que1;
    Queue que2;
    int sta;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    assert(stack);
    stack->que1.quesize = 0;
    stack->que1.front = stack->que1.rear = 0;

    stack->que2.quesize = 0;
    stack->que2.front = stack->que2.rear = 0;

    stack->sta = 1;
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (obj->que1.quesize == 0 && obj->sta == 1)
    {
        obj->que1.val[obj->que1.rear++] = x;
        obj->que1.quesize++;
    }
    else if (obj->sta == 1)
    {
        obj->que2.val[obj->que2.rear++] = x;
        obj->que2.quesize++;
        int tmp = 0;
        while (tmp < obj->que1.rear)
        {
            obj->que2.val[obj->que2.rear++] = obj->que1.val[tmp++];
            obj->que2.quesize++;
            obj->que1.quesize--;
        }
        obj->que1.rear = 0;
        obj->sta = 2;
    }
    else if (obj->sta == 2)
    {
        obj->que1.val[obj->que1.rear++] = x;
        obj->que1.quesize++;
        int tmp = 0;
        while (tmp < obj->que2.rear)
        {
            obj->que1.val[obj->que1.rear++] = obj->que2.val[tmp++];
            obj->que1.quesize++;
            obj->que2.quesize--;
        }
        obj->que2.rear = 0;
        obj->sta = 1;
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if (obj->sta == 1)
        if (obj->que1.quesize == 0)
            return 0;
        else {
            obj->que1.quesize--;
            return obj->que1.val[obj->que1.front++];
        }
    else
        if (obj->que2.quesize == 0)
            return 0;
        else {
            obj->que2.quesize--;
            return obj->que2.val[obj->que2.front++];
        }
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if (obj->sta == 1)
        if (obj->que1.quesize == 0)
            return 0;
        else
            return obj->que1.val[obj->que1.front];
    else
        if (obj->que2.quesize == 0)
            return 0;
        else
            return obj->que2.val[obj->que2.front];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if (obj->sta == 1 && obj->que1.quesize == 0)
        return true;
    else if (obj->sta == 2 && obj->que2.quesize == 0)
        return true;
    else
        return false;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

int main()
{
    MyStack* obj = myStackCreate();
    myStackPush(obj, 1);
    myStackPush(obj, 2);
    //myStackPush(obj, 3);
    int num = myStackTop(obj);
    num = myStackPop(obj);
    num = myStackPop(obj);
    bool bo = myStackEmpty(obj);
	return 0;
}