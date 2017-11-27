#include <stdio.h>
#include <Windows.h>
#include <string.h>
void DRAW(char(*p)[20]);
void ROW(char(*p)[20]);
void COLUMN(char(*p)[20]);
void MAX1(char(*p)[20], int i);
void MAX2(char(*p)[20], int i);
void MAX3(char(*p)[20]);
int main()
{
	char MAP[20][20];
	int x = 30, y = 30;
	int turn = 0;
	int white = 0, black = 0;
	while (1)
	{
		system("cls");
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

		DRAW(MAP);
		ROW(MAP);
		COLUMN(MAP);


		printf("좌표를 입력하시오:");
		scanf_s("%d %d", &x, &y);
		x = x - 1;
		y = y - 1;
	}
}
void DRAW(char(*p)[20])
{
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			printf("%2c", p[i][j]);
		}
		printf("\n");
	}
}
void ROW(char(*p)[20])
{
	int black = 0;
	int black2 = 0;
	int white = 0;
	int white2 = 0;
	int max = 0;
	char str[10] = {};
	printf("------------------가로----------------------\n");
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (p[i][j] == '#')
			{
				++black;
			}
			else if (p[i][j] == '@')
			{
				++white;
			}
		}

		printf("%2d번째 줄 검은돌 갯수:%d 흰돌 갯수:%d  \n  ", i + 1, black, white);
		MAX1(p, i);
		black = 0;
		white = 0;


	}
	MAX3(p);
}
void COLUMN(char(*p)[20])
{
	int black = 0;
	int white = 0;
	printf("-----------------세로----------------------\n");
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (p[j][i] == '#')
				++black;
			else if (p[j][i] == '@')
				++white;
		}
		printf("%2d번째 줄 검은돌 갯수:%d 흰돌 갯수:%d\n ", i + 1, black, white);
		MAX2(p, i);
		black = 0;
		white = 0;
	}
};
void MAX1(char(*p)[20], int i)
{
	int black2 = 0;
	int black3 = 0;
	int white2 = 0;
	int white3 = 0;
	int max = 0;

	for (int j = 0; j < 19; ++j)
	{
		if (p[i][j] == '#')
		{
			if (p[i][j] == p[i][j + 1])
				++black2;
			break;
		}
	}
	for (int j = black2; j < 19; ++j)
	{
		if (p[i][j] == '#')
		{
			if (p[i][j] == p[i][j + 1])
				++black3;
			if (black2 < black3)
				black2 = black3;
		}
	}
	for (int j = 0; j < 19; ++j)
	{
		if (p[i][j] == '@')
		{
			if (p[i][j] == p[i][j + 1])
				++white2;
			break;
		}
	}
	for (int j = black2; j < 19; ++j)
	{
		if (p[i][j] == '@')
		{
			if (p[i][j] == p[i][j + 1])
				++white3;
			if (white2 < white3)
				white2 = white3;
		}
	}
	if (black2 > white2)
	{
		max = black2 + 1;
		printf("최대: 검 ");
	}
	else if (black2 < white2)
	{
		max = white2 + 1;
		printf("최대: 흰 ");
	}
	else
		max = 0;
	printf("최대 : %d\n", max);
	max = 0;
	black2 = 0;
	white2 = 0;
};

void MAX2(char(*p)[20], int i)
{
	int black2 = 0;
	int black3 = 0;
	int white2 = 0;
	int white3 = 0;
	int max = 0;
	char str[5] = {};
	for (int j = 0; j < 19; ++j)
	{
		if (p[j][i] == '#')
		{
			if (p[j][i] == p[j][i + 1])
				++black2;
			break;
		}
	}
	for (int j = black2; j < 19; ++j)
	{
		if (p[j][i] == '#')
		{
			if (p[j][i] == p[j][i + 1])
				++black3;
			if (black2 < black3)
				black2 = black3;
		}
	}
	for (int j = 0; j < 19; ++j)
	{
		if (p[j][i] == '@')
		{
			if (p[j][i] == p[j][i + 1])
				++white2;
			break;
		}
	}
	for (int j = black2; j < 19; ++j)
	{
		if (p[j][i] == '@')
		{
			if (p[j][i] == p[j][i + 1])
				++white3;
			if (white2 < white3)
				white2 = white3;
		}
	}
	if (black2 > white2)
	{
		max = black2 + 1;
		printf("최대: 검 ");
	}
	else if (black2 < white2)
	{
		max = white2 + 1;
		printf("최대: 흰 ");
	}
	else
		max = 0;
	printf("최대 : %d  \n", max);
	max = 0;
	black2 = 0;
	white2 = 0;
};
void MAX3(char(*p)[20])
{
	int black2 = 0;
	int white2 = 0;
	int max = 0;
	char str[5] = {};
	for (int i = 0; i < 17; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (p[j][j + i] == '#')
			{
				if (p[j][j + i] == p[j + 1][j + 1 + i])
					++black2;
			}
			else if (p[j][j + i] == '@')
			{
				if (p[j][j + i] == p[j + 1][j + 1 + i])
					++white2;
			}
		}
	}
	if (black2 > white2)
	{
		max = black2 + 1;
		printf("대각선 최대: 검 ");
	}
	else if (black2 < white2)
	{
		max = white2 + 1;
		printf("대각선 최대: 흰 ");
	}
	else if (black2 == 1 && white2 == 1)
		max = 0;
	else
		max = 0;
	printf("대각선 최대 : %d  \n", max);
	max = 0;
	black2 = 0;
	white2 = 0;
};