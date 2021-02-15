#include <stdio.h>
#include <stdbool.h>

#define MAX_TREE_SIZE 100

//单个节点的结构
typedef struct
{
	int data;    //节点数据
	int parent;    //双亲节点位置
}PTNode;

//树的结构
typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];    //节点数组
	int r, n;    //根的位置，节点数
}PTree;

//创建一颗空树
PTree* InitTree()
{
	PTree* tree = (PTree*)malloc(sizeof(PTree));
	tree->nodes->parent = -1;    //节点双亲位置
	tree->n = 0;    //节点数
	tree->r = -1;   //根位置
	return PTree;
}

//销毁树
void DestroyTree(PTree* tree)
{

}

//若树tree不为空，则清除树tree
void ClearTree(PTree* tree)
{
	if (tree->n != 0)
	{
		tree->n = 0;
		tree->r = -1;
	}
}

//若树为空返回true，不空返回false
bool TreeEmpty(PTree* tree)
{
	if (tree->n == 0)
		return true;
	else 
		return false;
}

//返回树tree的深度
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

//返回树tree根节点
PTNode* Root(PTree* tree)
{
	return tree->nodes[0];
}



int main()
{

	return 0;
}