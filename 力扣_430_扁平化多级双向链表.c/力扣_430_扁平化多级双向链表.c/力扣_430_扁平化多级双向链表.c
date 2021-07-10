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
                //��¼��һ���ڵ�
                Node* tmp = cur->next;
                //�ݹ�
                Node* child = flatten(cur->child);
                //��õݹ�����β
                Node* childend = getend(child);

                //����
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