typedef struct qNode {
    int time;
    struct qNode* next;
}qNode;

typedef struct {
    qNode* head;
    qNode* front;    //Í·Ö¸Õë
    qNode* rear;    //Î²Ö¸Õë
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* p = (RecentCounter*)malloc(sizeof(RecentCounter));
    assert(p);
    p->front = NULL;
    p->rear = NULL;
    return p;
}

int recentCounterPing(RecentCounter* obj, int t) {
    qNode* newNode = (qNode*)malloc(sizeof(qNode));
    assert(newNode);
    newNode->time = t;
    newNode->next = NULL;

    if (!obj->front)
    {
        obj->front = obj->rear = newNode;
    }
    else
    {
        obj->rear->next = newNode;
        obj->rear = newNode;
    }


    while (obj->front != NULL && t - obj->front->time > 3000)
    {
        qNode* fr = obj->front;
        obj->front = obj->front->next;
        free(fr);
    }

    int len = 0;
    qNode* move = obj->front;
    while (move != NULL)
    {
        len++;
        move = move->next;
    }
    return len;
}

void recentCounterFree(RecentCounter* obj) {

}

