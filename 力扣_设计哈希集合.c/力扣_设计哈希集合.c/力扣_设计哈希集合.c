#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

//力扣上跑不过
typedef struct {
    bool val[1000001];
} MyHashSet;

/** Initialize your data structure here. */

MyHashSet* myHashSetCreate() {
    MyHashSet* set = (MyHashSet*)malloc(sizeof(MyHashSet));
    //MyHashSet* obj = set;
    assert(set);
    for (int i = 0; i < 1000001; i++)
        set->val[i] = false;
    return set;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    obj->val[key] = true;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    if (obj->val[key] == true)
        obj->val[key] == false;
}

/** Returns true if this set contains the specified element */
bool* myHashSetContains(MyHashSet* obj, int key) {

    return &(obj->val[key]);
}

void myHashSetFree(MyHashSet* obj) {
    free(obj);
    obj = NULL;
}

/************************************************************************************************************************************************************/
//力扣跑过了
typedef struct {
    bool val[1000001];
} MyHashSet;

/** Initialize your data structure here. */

MyHashSet* myHashSetCreate() {
    MyHashSet* set = (MyHashSet*)calloc(sizeof(MyHashSet), 1);
    //MyHashSet* obj = set;
    assert(set);
    //for (int i = 0; i < 1000001; i++)
    //    set->val[i] = false;
    return set;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    obj->val[key] = true;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    obj->val[key] = false;
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {

    return obj->val[key];
}

void myHashSetFree(MyHashSet* obj) {
    free(obj);
    obj = NULL;
}

int main()
{
    MyHashSet* obj = myHashSetCreate();
    myHashSetAdd(obj, 1);
    myHashSetAdd(obj, 2);
    bool* t = myHashSetContains(obj, 1);
    t = myHashSetContains(obj, 3);



	return 0;
}