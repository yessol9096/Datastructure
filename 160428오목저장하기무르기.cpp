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
			printf("저장하려면 '1',나가기 '2' 저장불러오기'3':");
			scanf_s("%d", &order);
			if (order == 1)
			{
				fopen_s(&fp, "array.txt", "w");
				for (int i = 0; i < 19; ++i)
					for (int j = 0; j < 19; ++j)
						fprintf(fp, "2%c ", MAP[i][j]);//data[i]를 fp에 쓴다. 스페이스 추가
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
		printf("무르기6,무르기취소7,저장하러가기5,계속하기4:");
		scanf_s("%d", &order);

		if (order == 4)
		{
			printf("좌표를 입력하시오:");
			scanf_s("%d %d", &x, &y);
			x = x - 1;
			y = y - 1;
			pushX(x);
			pushY(y);
		}
		else if (order == 6)
		{
			if (topX < 0 || topY < 0)
				printf("무를게 없습니다.");
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
				printf("무를게 없습니다.");
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
		printf("스택이꽉찾잖아!!!\n");
	}
	// 현재스택포인터에값을저장한다음스택포인터를하나증가시킨다
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
		printf("스택이꽉찾잖아!!!\n");
	}
	// 현재스택포인터에값을저장한다음스택포인터를하나증가시킨다
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
		printf("넣은게없는데뭘뺄려는겨? 에러났다.\n");
	}
	else
	{
		// 스택포인터를하나감소시키고값을뺀다
		--topX;
	}
};
void popY()
{
	if (topY < 0)
	{
		printf("넣은게없는데뭘뺄려는겨? 에러났다.\n");
	}
	else
	{
		// 스택포인터를하나감소시키고값을뺀다
		--topY;
	}
};
void rpushX(int n)
{
	if (rtopX > MAX)
	{
		printf("스택이꽉찾잖아!!!\n");
	}
	else
	{
		// 현재스택포인터에값을저장한다음스택포인터를하나증가시킨다
		rStackX[rtopX] = n;
		rtopX++;
	}
};
void rpushY(int n)
{
	if (rtopY > MAX)
	{
		printf("스택이꽉찾잖아!!!\n");
	}
	else
	{
		// 현재스택포인터에값을저장한다음스택포인터를하나증가시킨다
		rStackY[rtopY] = n;
		rtopY++;
	}
};
void rpopX()
{
	if (rtopX < 0)
	{
		printf("넣은게없는데뭘뺄려는겨? 에러났다.\n");
	}
	else
	{
		// 스택포인터를하나감소시키고값을뺀다
		--rtopX;
	}
};
void rpopY()
{
	if (rtopY < 0)
	{
		printf("넣은게없는데뭘뺄려는겨? 에러났다.\n");
	}
	else
	{
		// 스택포인터를하나감소시키고값을뺀다
		--rtopY;
	}
};