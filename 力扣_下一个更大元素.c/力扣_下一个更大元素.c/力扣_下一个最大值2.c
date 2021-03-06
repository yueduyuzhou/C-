typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* front;
} Node;

typedef struct hashNode
{
    int data;
    int nextmax;
    struct hashNode* next;
}hashNode;

Node* InitNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    assert(newNode);
    newNode->data = data;
    newNode->next = NULL;
    newNode->front = NULL;
    return newNode;
}

hashNode* InithaNode(int data, int nextmax)
{
    hashNode* newNode = (hashNode*)malloc(sizeof(hashNode));
    assert(newNode);
    newNode->data = data;
    newNode->nextmax = nextmax;
    newNode->next = NULL;
    return newNode;
}

void InsertNode(Node* newNode, Node* head, Node* top)
{
    newNode->front = top;
    top->next = newNode;
    top = newNode;
}

void Inserthash(hashNode* newNode, hashNode* head, hashNode* fail)
{
    fail->next = newNode;
    fail = newNode;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    if (nums1Size == 0)
        return NULL;
    //设置数组头节点
    hashNode* hahead = (hashNode*)malloc(sizeof(hashNode));
    assert(hahead);
    hahead->next = NULL;
    hashNode* fail = (hashNode*)malloc(sizeof(hashNode));
    assert(fail);
    fail->next = NULL;
    fail = hahead;
    //设置栈头节点
    Node* sthead = (Node*)malloc(sizeof(Node));
    assert(sthead);
    sthead->next = NULL;
    sthead->front = NULL;
    Node* top = (Node*)malloc(sizeof(Node));
    assert(top);
    top->next = NULL;
    top->front = NULL;
    top = sthead;

    int hashsize = 0;
    int i = 0;
    for (i = 0; i < nums2Size; i++)
    {
        Node* newNode = InitNode(nums2[i]);

        while (top != sthead && top->data < newNode->data)
        {
            hashNode* hanode = InithaNode(top->data, newNode->data);
            Inserthash(hanode, hahead, fail);
            hashsize++;
            Node* tmp = top;
            top = top->front;
            top->next = NULL;
            free(tmp);
            tmp = NULL;
        }
        InsertNode(newNode, sthead, top);
    }
    while (top != sthead)
    {
        hashNode* hanode = InithaNode(top->data, -1);
        Inserthash(hanode, hahead, fail);
        hashsize++;
        Node* tmp = top;
        top = top->front;
        top->next = NULL;
        free(tmp);
        tmp = NULL;
    }
    int* tmparr = (int*)malloc(sizeof(int) * nums1Size);
    assert(tmparr);
    for (i = 0; i < nums1Size; i++)
    {
        hashNode* move = (hashNode*)malloc(sizeof(hashNode));
        assert(move);
        move = hahead->next;
        while (move != NULL)
        {
            if (move->data == nums1[i])
                tmparr[i] = move->nextmax;
            move = move->next;
        }
        move = hahead->next;
    }
    *returnSize = i;
    return tmparr;
}