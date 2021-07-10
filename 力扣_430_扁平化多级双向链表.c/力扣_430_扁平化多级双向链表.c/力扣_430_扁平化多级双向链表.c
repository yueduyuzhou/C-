/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

Node* getend(Node* head)
{
    Node* cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    return cur;
}

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) { return head; }

        Node* cur = head;
        while (cur != NULL)
        {
            if (cur->child != NULL)
            {
                //记录下一个节点
                Node* tmp = cur->next;
                //递归
                Node* child = flatten(cur->child);
                //获得递归结果的尾
                Node* childend = getend(child);

                //连接
                childend->next = tmp;
                child->prev = cur;
                cur->next = child;
                if (tmp != NULL) { tmp->prev = childend; }

                cur->child = NULL;
                cur = tmp;
            }
            else
            {
                cur = cur->next;
            }
        }

        return head;
    }
};