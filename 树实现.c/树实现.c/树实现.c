#include <stdio.h>
#include <stdbool.h>

#define MAX_TREE_SIZE 100

//�����ڵ�Ľṹ
typedef struct
{
	int data;    //�ڵ�����
	int parent;    //˫�׽ڵ�λ��
}PTNode;

//���Ľṹ
typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];    //�ڵ�����
	int r, n;    //����λ�ã��ڵ���
}PTree;

//����һ�ſ���
PTree* InitTree()
{
	PTree* tree = (PTree*)malloc(sizeof(PTree));
	tree->nodes->parent = -1;    //�ڵ�˫��λ��
	tree->n = 0;    //�ڵ���
	tree->r = -1;   //��λ��
	return PTree;
}

//������
void DestroyTree(PTree* tree)
{

}

//����tree��Ϊ�գ��������tree
void ClearTree(PTree* tree)
{
	if (tree->n != 0)
	{
		tree->n = 0;
		tree->r = -1;
	}
}

//����Ϊ�շ���true�����շ���false
bool TreeEmpty(PTree* tree)
{
	if (tree->n == 0)
		return true;
	else 
		return false;
}

//������tree�����
int TreeDepth(PTree* tree)
{
	int depth = 0;
	PTNode* pn = tree->nodes[tree->n];
	if (tree->n != 0)
		depth = 1;
	while (1)
	{
		if (pn->parent != -1)
		{
			depth++;
			pn = tree->nodes[pn->parent];
		}
	}
	return depth;
}

//������tree���ڵ�
PTNode* Root(PTree* tree)
{
	return tree->nodes[0];
}



int main()
{

	return 0;
}