//#include <stdio.h>
//
////1.����ṹ��
//struct Node
//{
//	int data;
//	struct Node* next;
//};
//
////2.��������(ͷ)
//struct Node* createList()
//{
//	struct Node* headNode = (struct Node*) malloc(sizeof(struct Node));    //���ٿռ�
//	//headNode->data = 23;
//	headNode->next = NULL;    //��ʱָ���
//
//	return headNode;
//}                                                                 /*��ȫ����*/
//
////3.�����ڵ�
//struct Node* createNode(int data)
//{
//	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//
//	newNode->data = data;    //�����򸳳�ֵ
//	newNode->next = NULL;    //��ʱָ���
//
//	return newNode;
//}
//
////4.��ӡ����
//void printfList(struct Node* headNode)
//{
//	struct Node* pMove = headNode->next;    
//
//	while (pMove)    //��ͷѰ��Ҫ��ӡ������
//	{
//		printf("%d\t", pMove->data); 
//		pMove = pMove->next;    //�����һλ
//	}
//	printf("\n\n");
//}
//
////5.����ڵ�(ͷ�巨)
//void InsertNodeByHead(struct Node* headNode, int data)
//{
//	struct Node* newNode = createNode(data);    //Ҫ���룬�ȴ����ڵ�
//
//	newNode->next = headNode->next;    //ʹnewNode��ָ����ָ��ԭ��headNode����һ��
//	headNode->next = newNode;    //ʹͷָ��Ҫ����Ľڵ�
//}
//
////6.ɾ���ڵ�
//void DeleteNodeByAppoin(struct Node* headNode, int posData)
//{
//	struct Node* posNode = headNode->next;    //����һ��ָ��ָ����Ԫ��
//	struct Node* posNodeFront = headNode;    //����һ��ָ��ָ��posNodeǰһ��ָ��
//
//	if (posNode == NULL)    //��δ����ʱ���ж������Ƿ�Ϊ��
//	{
//		printf("������Ϊ��\n");
//	}
//	else
//	{
//		while (posNode->data != posData)    //��������
//		{
//			posNodeFront = posNode;
//			posNode = posNode->next;
//
//			if (posNode == NULL)    //�Ҳ���Ҫɾ�������ݣ����������޴�����
//			{
//				printf("������û�и�����\n");
//				return 0;    //����������
//			}
//		}
//		posNodeFront->next = posNode->next;    //ʹposNodeFrontָ��ɾ��Ԫ�ص���һ��Ԫ��
//		free(posNode);    //�黹ɾ��Ԫ�صĿռ�
//	}
//}
//
//
//int main()
//{
//	struct Node* list = createList();    //����������������
//
//	InsertNodeByHead(list, 1);    //����ʹ��ͷ�巨���Ȳ�������ݷ����ں�
//	InsertNodeByHead(list, 2);    //
//	InsertNodeByHead(list, 3);    //����3���ڵ�
//
//	printfList(list);    //��������Ľ��
//
//	DeleteNodeByAppoin(list, 2);    //ɾ��1���ڵ�
//
//	printfList(list);    //��ӡɾ����Ľ��
//
//	return 0;
//}






