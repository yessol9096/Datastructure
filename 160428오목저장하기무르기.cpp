#include <stdio.h>
#include <Windows.h>
#include <string.h>
#define MAX 38
void DRAW(char(*p)[19]);
void pushX(int n);
void popX();
void pushY(int n);
void popY();
int topX, topY;
int StackX[MAX], StackY[MAX];
int rStackX[MAX], rStackY[MAX];
int rtopX, rtopY;
void rpushX(int n);
void rpopX();
void rpushY(int n);
void rpopY();
int main()
{
	char MAP[19][19];
	int x = 30, y = 30;
	int turn = 0;
	int white = 0, black = 0;
	int order = 0;
	FILE *fp;
	topX = topY = 0;
	rtopX = rtopY = 0;

	while (1)
	{
		system("cls");
		if (turn == 0)
		{
			for (int i = 0; i < 19; ++i)
				for (int j = 0; j < 19; ++j)
					if (MAP[i][j] == '#' || MAP[i][j] == '@')
						++turn;
		}


		for (int i = 0; i < 19; ++i)
		{
			for (int j = 0; j < 19; ++j)
			{
				if (turn % 2 == 0 && i == x && j == y && MAP[i][j] != '#' && MAP[i][j] != '@')
				{
					MAP[i][j] = '#';
					++turn;
				}
				else if (turn % 2 == 1 && i == x && j == y && MAP[i][j] != '#' && MAP[i][j] != '@')
				{
					MAP[i][j] = '@';
					++turn;
				}
				else if (MAP[i][j] == '#')
				{
					MAP[i][j] = '#';
				}
				else if (MAP[i][j] == '@')
				{
					MAP[i][j] = '@';
				}
				else
					MAP[i][j] = '+';
			}
		}

		//ROW(MAP);
		//COLUMN(MAP);
		if (order == 5)
		{
			printf("�����Ϸ��� '1',������ '2' ����ҷ�����'3':");
			scanf_s("%d", &order);
			if (order == 1)
			{
				fopen_s(&fp, "array.txt", "w");
				for (int i = 0; i < 19; ++i)
					for (int j = 0; j < 19; ++j)
						fprintf(fp, "2%c ", MAP[i][j]);//data[i]�� fp�� ����. �����̽� �߰�
				fclose(fp);

			}
			else if (order == 3)
			{
				fopen_s(&fp, "array.txt", "r");
				for (int i = 0; i < 19; ++i)
					for (int j = 0; j < 19; ++j)
						//fscanf_s(fp, "2%c ", &MAP[i][j]);
				fclose(fp);
			}
		}



		DRAW(MAP);
		printf("������6,���������7,�����Ϸ�����5,����ϱ�4:");
		scanf_s("%d", &order);

		if (order == 4)
		{
			printf("��ǥ�� �Է��Ͻÿ�:");
			scanf_s("%d %d", &x, &y);
			x = x - 1;
			y = y - 1;
			pushX(x);
			pushY(y);
		}
		else if (order == 6)
		{
			if (topX < 0 || topY < 0)
				printf("������ �����ϴ�.");
			else
			{
				popX();
				popY();
				rpushX(StackX[topX]);
				rpushY(StackY[topY]);
				MAP[StackX[topX]][StackY[topY]] = '+';
				turn -= 1;
				x = 40;
				y = 40;
			}
		}
		else if (order == 7)
		{
			if (rtopX < 1 || rtopY < 1)
				printf("������ �����ϴ�.");
			else
			{
				rpopX();
				rpopY();
				pushX(rStackX[rtopX]);
				pushY(rStackY[rtopY]);
				turn += 1;
				x = 40;
				y = 40;
				if (turn % 2 == 1)
					MAP[rStackX[rtopX]][rStackY[rtopY]] = '#';
				else
					MAP[rStackX[rtopX]][rStackY[rtopY]] = '@';

			}
		}

	}
}
void pushX(int n)
{
	if (topX > MAX)
	{
		printf("�����̲�ã�ݾ�!!!\n");
	}
	// ���罺�������Ϳ����������Ѵ������������͸��ϳ�������Ų��
	else
	{
		StackX[topX] = n;
		topX++;
	}
};
void pushY(int n)
{
	if (topY > MAX)
	{
		printf("�����̲�ã�ݾ�!!!\n");
	}
	// ���罺�������Ϳ����������Ѵ������������͸��ϳ�������Ų��
	else
	{
		StackY[topY] = n;
		topY++;
	}
};
void popX()
{
	if (topX < 0)
	{
		printf("�����Ծ��µ��������°�? ��������.\n");
	}
	else
	{
		// ���������͸��ϳ����ҽ�Ű��������
		--topX;
	}
};
void popY()
{
	if (topY < 0)
	{
		printf("�����Ծ��µ��������°�? ��������.\n");
	}
	else
	{
		// ���������͸��ϳ����ҽ�Ű��������
		--topY;
	}
};
void rpushX(int n)
{
	if (rtopX > MAX)
	{
		printf("�����̲�ã�ݾ�!!!\n");
	}
	else
	{
		// ���罺�������Ϳ����������Ѵ������������͸��ϳ�������Ų��
		rStackX[rtopX] = n;
		rtopX++;
	}
};
void rpushY(int n)
{
	if (rtopY > MAX)
	{
		printf("�����̲�ã�ݾ�!!!\n");
	}
	else
	{
		// ���罺�������Ϳ����������Ѵ������������͸��ϳ�������Ų��
		rStackY[rtopY] = n;
		rtopY++;
	}
};
void rpopX()
{
	if (rtopX < 0)
	{
		printf("�����Ծ��µ��������°�? ��������.\n");
	}
	else
	{
		// ���������͸��ϳ����ҽ�Ű��������
		--rtopX;
	}
};
void rpopY()
{
	if (rtopY < 0)
	{
		printf("�����Ծ��µ��������°�? ��������.\n");
	}
	else
	{
		// ���������͸��ϳ����ҽ�Ű��������
		--rtopY;
	}
};