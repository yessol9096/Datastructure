#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct champion
{
	char name[10];
	char position[10];
	double hp, mp, speed, range;
};
typedef struct Node
{
	char *name;
	char *position;
	double hp, mp, speed, range;
	struct Node *next;
}NodeStruct;
typedef struct list
{
	int countIndex;
	NodeStruct* tail;    // ��������Ʈ�� head�� �ƴ� tail��带 ������.
}List;
void PrintNode(List* list);
void _reverse(List* list);// ����Ʈ�� �ִ� Node���� ��� 
void InsertNode(List* list, struct champion s[]);
void _search(List* list, struct champion s[]);
void _delete(List* list, struct champion s[]);
void _deleteall(List* list, struct champion s[]);
void _findmaxhp(List* list, struct champion s[]);
void _reverse(List* list)
{
	int i;
	NodeStruct* pCurrentNode;
	for (pCurrentNode = list->tail, i = list->countIndex; i > 0; i--)
	{
		printf("%s %s %g %g %g %g\n", pCurrentNode->name, pCurrentNode->position, pCurrentNode->hp, pCurrentNode->mp, pCurrentNode->speed, pCurrentNode->range);
		for (int j = 0; j < list->countIndex - 1; ++j)
			pCurrentNode = pCurrentNode->next;
	}
};
void _findmaxhp(List* list, struct champion s[])
{
	int i;
	NodeStruct* max = list->tail->next;
	NodeStruct* pCurrentNode;
	for (pCurrentNode = list->tail->next, i = 0; i < list->countIndex; ++i)
	{
		if (max->hp <  pCurrentNode->hp)
			max = pCurrentNode;
		pCurrentNode = pCurrentNode->next;
	}
	printf("%s %s %g %g %g %g\n", max->name, max->position, max->hp, max->mp, max->speed, max->range);
};
void _delete(List* list, struct champion s[])
{
	int count = 0;
	char sName[10];
	printf("è�Ǿ��̸��� �Է��Ͻÿ�: ");
	scanf_s("%s", sName, 10);
	int i;
	NodeStruct* pCurrentNode;
	NodeStruct* delNode = list->tail;
	for (pCurrentNode = list->tail->next, i = 0; i < list->countIndex; i++)
	{
		delNode = pCurrentNode;
		pCurrentNode = pCurrentNode->next;
		if (strcmp(sName, pCurrentNode->name) == 0)
		{
			count++;
			delNode->next = pCurrentNode->next;
			free(pCurrentNode);
			pCurrentNode = delNode;
			if (i == list->countIndex - 2)
			{
				list->tail = delNode;
			}
			break;
		}
	}

	list->countIndex = list->countIndex - count;
};
void _deleteall(List* list, struct champion s[])
{
	char sName[10];
	printf("�������� �Է��Ͻÿ�: ");
	scanf_s("%s", sName, 10);
	int i, count = 0;
	NodeStruct* pCurrentNode;
	NodeStruct* delNode = list->tail;
	for (pCurrentNode = list->tail->next, i = 0; i < list->countIndex; i++)
	{
		delNode = pCurrentNode;
		pCurrentNode = pCurrentNode->next;
		if (strcmp(sName, pCurrentNode->position) == 0)
		{
			count++;
			delNode->next = pCurrentNode->next;
			free(pCurrentNode);
			if (i == list->countIndex - 2)
			{
				list->tail = delNode;
			}
			pCurrentNode = delNode;
		}
	}
	list->countIndex = list->countIndex - count;
};
void _search(List* list, struct champion s[])
{
	char sName[10];
	printf("è�Ǿ��̸��� �Է��Ͻÿ�: ");
	scanf_s("%s", sName, 10);
	int i;
	NodeStruct* pCurrentNode;
	for (pCurrentNode = list->tail->next, i = 0; i < list->countIndex; i++, pCurrentNode = pCurrentNode->next)
	{
		if (strcmp(sName, pCurrentNode->name) == 0)
		{
			printf("%s %s %g %g %g %g\n", pCurrentNode->name, pCurrentNode->position, pCurrentNode->hp, pCurrentNode->mp, pCurrentNode->speed, pCurrentNode->range);
			pCurrentNode = pCurrentNode->next;
			break;
		}
	}
};
void InsertNode(List* list, struct champion s[])
{
	for (int i = 0; i < 20; i++)
	{
		NodeStruct *preNode = list->tail;
		NodeStruct* pNewNode;
		pNewNode = (NodeStruct*)malloc(sizeof(NodeStruct));
		pNewNode->name = s[i].name;
		pNewNode->position = s[i].position; // ȭ��ǥ �����ڸ� ���ؼ��� �� ���� ����
		pNewNode->hp = s[i].hp;
		pNewNode->mp = s[i].mp;
		pNewNode->speed = s[i].speed;
		pNewNode->range = s[i].range;
		pNewNode->next = NULL;
		if (list->countIndex == 0)
		{
			pNewNode->next = pNewNode;
			list->tail = pNewNode;
		}
		else
		{
			pNewNode->next = preNode->next;
			preNode->next = pNewNode;
			list->tail = pNewNode;
			preNode = pNewNode;
		}
		list->countIndex++;
	}
};
void PrintNode(List* list)
{
	int i;
	NodeStruct* pCurrentNode;
	for (pCurrentNode = list->tail->next, i = 0; i < list->countIndex; i++)
	{
		printf("%s %s %g %g %g %g\n", pCurrentNode->name, pCurrentNode->position, pCurrentNode->hp, pCurrentNode->mp, pCurrentNode->speed, pCurrentNode->range);
		pCurrentNode = pCurrentNode->next;
	}
};
int main()
{
	List* list = (List*)malloc(sizeof(List));
	list->countIndex = 0;
	list->tail = NULL;
	struct champion ch[30] =
	{
		{ "������", "top", 576.16, 302.2, 335, 125 },
		{ "����",   "top", 616.28, 0, 340, 175 },
		{ "������", "top", 577.8, 369, 335, 125 },
		{ "������", "top", 561.2, 325.6, 350, 125 },
		{ "����", "sup", 598.28, 283.56, 350, 125 },
		{ "�ϴ޸�", "sup", 541.2, 295.6, 335, 525 },
		{ "����"  , "sup", 489.32, 377.24, 335, 550 },
		{ "�Ҷ�ī", "sup", 529.04, 350.8, 325, 550 },
		{ "����"  , "jun", 582.8, 273.8, 345, 125 },
		{ "��¥��", "jun", 591.16, 273.8, 345, 175 },
		{ "ī����", "jun", 572.8, 327.2, 350, 125 },
		{ "����", "jun", 586.2, 5, 345, 125 },
		{ "�巹�̺�", "one", 557.76, 360.56, 330, 550 },
		{ "����", "one", 540, 100, 325, 150 },
		{ "�츣��", "one", 586.52, 312.4, 335, 425 },
		{ "���̽�", "one", 571.2, 357.2, 335, 125 },
		{ "���", "mid", 552.76, 292.4, 325, 550 },
		{ "���ֳ̾�","mid", 589.2, 297.2, 345, 150 },
		{ "������", "mid", 507.68, 375.6, 340, 525 },
		{ "�ƽ���", "mid", 517.76, 60, 345, 175 },
	};
	char order[10];
	while (1)
	{
		printf("��ɾ �Է��Ͻÿ�: ");
		scanf_s("%s", order, 10);

		if (strcmp(order, "array") == 0)
		{
			InsertNode(list, ch);
		}
		else if (strcmp(order, "printall") == 0)
		{
			PrintNode(list);
		}
		else if (strcmp(order, "search") == 0)
		{
			_search(list, ch);
		}
		else if (strcmp(order, "delete") == 0)
		{
			_delete(list, ch);
		}
		else if (strcmp(order, "deleteall") == 0)
		{
			_deleteall(list, ch);
		}
		else if (strcmp(order, "findmaxhp") == 0)
		{
			_findmaxhp(list, ch);
		}
		else if (strcmp(order, "reverse") == 0)
		{
			_reverse(list);
		}
		else
			continue;
	}
}