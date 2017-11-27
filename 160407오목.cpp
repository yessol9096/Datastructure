#include <stdio.h>
#include <Windows.h>
#include <string.h>
void DRAW(char(*p)[20]);
void ROW(char(*p)[20]);
void COLUMN(char(*p)[20]);
void DIA(char(*p)[20], int x, int y);
void MAX1(char(*p)[20], int i);
void MAX2(char(*p)[20], int i);
void MAX3(char(*p)[20], int i);
void MAX4(char(*p)[20], int i);
void MAX5(char(*p)[20], int i);
void MAX6(char(*p)[20], int i);
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
		DIA(MAP, x, y);


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

		printf("\n%2d번째 줄 검은돌 갯수:%d 흰돌 갯수:%d  \n  ", i + 1, black, white);
		MAX1(p, i);
		black = 0;
		white = 0;


	}
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
void DIA(char(*p)[20], int x, int y)
{
	int black = 0;
	int white = 0;
	printf("-------------------왼쪽대각선---------------------\n");
	{
		for (int i = 18; i > -1; --i)
		{
			for (int j = 0; j + i < 20; ++j)
			{
				if (p[j + i][j] == '#')
					++black;
				else if (p[j + i][j] == '@')
					++white;
			}
			printf("%2d번째 줄 검은돌 갯수:%d 흰돌 갯수:%d\n ", 19 - i, black, white);
			MAX4(p, i);
			black = 0;
			white = 0;
		}
		for (int i = 1; i < 19; ++i)
		{
			for (int j = 0; j + i < 20; ++j)
			{
				if (p[j][j + i] == '#')
					++black;
				else if (p[j][j + i] == '@')
					++white;
			}
			printf("%2d번째 줄 검은돌 갯수:%d 흰돌 갯수:%d\n ", 19 + i, black, white);
			MAX3(p, i);
			black = 0;
			white = 0;
		}
	}
	printf("-------------------오른쪽대각선---------------------\n");
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (p[j][i - j] == '#')
				++black;
			else if (p[j][i - j] == '@')
				++white;
		}
		printf("%2d번째 줄 검은돌 갯수:%d 흰돌 갯수:%d\n ", i + 1, black, white);
		MAX5(p, i);
		black = 0;
		white = 0;
	}
	for (int i = 19; i < 37; ++i)
	{
		for (int j = 1; j < 19; ++j)
		{
			if (p[j][i - j] == '#')
				++black;
			else if (p[j][i - j] == '@')
				++white;
		}
		printf("%2d번째 줄 검은돌 갯수:%d 흰돌 갯수:%d\n ", i + 1, black, white);
		MAX6(p, i);
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
	int one = 0;
	int two = 0;
	int k = 0;
	int w = 0;

	for (int j = 0; j < 19; ++j)
	{
		if (p[i][j] == '#')
		{
			while (p[i][j] == p[i][j + 1])
			{
				if (one == 0)
					one = j;
				++black2;
				++j;
				++k;
			}
			j = 20;
		}
	}
	for (int j = black2; j < 19; ++j)
	{
		if (p[i][j] == '#')
		{
			while (p[i][j] == p[i][j + 1])
			{
				if (two == 0)
					two = j;
				++black3;
				++j;
				w += 1;
			}
		}
	}
	if (black2 < black3)
	{
		one = two;
		black2 = black3;
		black3 = 0;
	}

	for (int j = 0; j < 19; ++j)
	{
		if (p[i][j] == '@')
		{
			while (p[i][j] == p[i][j + 1])
			{
				if (one == 0)
					one = j;
				++white2;
				++j;
			}
			j = 20;
		}
	}
	for (int j = white2; j < 19; ++j)
	{
		if (p[i][j] == '@')
		{
			while (p[i][j] == p[i][j + 1])
			{
				if (two == 0)
					two = j;
				++white3;
				++j;
			}
			if (white2 < white3)
			{
				one = two;
				white2 = white3;
				white3 = 0;
			}
		}
	}
	if (black2 > white2)
	{
		max = black2 + 1;
		printf("최대: 검 ");
		for (int u = 1; u < black2; ++u)
			printf("(%d,%d)", i, one + u);
	}
	else if (black2 < white2)
	{
		max = white2 + 1;
		printf("최대: 흰 ");
		for (int u = 1; u < white2; ++u)
			printf("(%d,%d)", i, one + u);
	}
	else
		max = 0;
	printf("최대 : %d ", max);

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
			while (p[j][i] == p[j + 1][i])
			{
				++black2;
				++j;
			}
			j = 20;
		}
	}
	for (int j = black2; j < 19; ++j)
	{
		if (p[j][i] == '#')
		{
			while (p[j][i] == p[j + 1][i])
			{
				++black3;
				++j;
			}
			if (black2 < black3)
			{
				black2 = black3;
				black3 = 0;
			}
		}
	}
	for (int j = 0; j < 19; ++j)
	{
		if (p[j][i] == '@')
		{
			while (p[j][i] == p[j + 1][i])
			{
				++white2;
				++j;
			}
			j = 20;
		}
	}
	for (int j = white2; j < 19; ++j)
	{
		if (p[j][i] == '@')
		{
			while (p[j][i] == p[j + 1][i])
			{
				++white3;
				++j;
			}
			if (white2 < white3)
			{
				white2 = white3;
				white3 = 0;
			}
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
void MAX3(char(*p)[20], int i)
{
	int black2 = 0;
	int white2 = 0;
	int black3 = 0;
	int white3 = 0;
	int max = 0;
	char str[5] = {};

	for (int j = 0; j < 19; ++j)
	{
		if (p[j][j + i] == '#')
		{
			while (p[j][j + i] == p[j + 1][j + 1 + i])
			{
				++black2;
				++j;
			}
			j = 20;
		}
	}
	for (int j = black2; j < 19; ++j)
	{
		if (p[j][j + i] == '#')
		{
			while (p[j][j + i] == p[j + 1][j + 1 + i])
			{
				++black3;
				++j;
			}
			if (black2 < black3)
			{
				black2 = black3;
				black3 = 0;
			}
		}
	}
	for (int j = 0; j < 19; ++j)
	{
		if (p[j][j + i] == '@')
		{
			while (p[j][j + i] == p[j + 1][j + 1 + i])
			{
				++white2;
				++j;
			}
			j = 20;
		}
	}
	for (int j = white2; j < 19; ++j)
	{
		if (p[j][j + i] == '@')
		{
			while (p[j][j + i] == p[j + 1][j + 1 + i])
			{
				++white3;
				++j;
			}
			if (white2 < white3)
			{
				white2 = white3;
				white3 = 0;
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
void MAX4(char(*p)[20], int i)
{
	int black2 = 0;
	int white2 = 0;
	int black3 = 0;
	int white3 = 0;
	int max = 0;
	char str[5] = {};

	for (int j = 0; j < 19; ++j)
	{
		if (p[j + i][j] == '#')
		{
			while (p[j + i][j] == p[j + i + 1][j + 1])
			{
				++black2;
				++j;
			}
			j = 20;
		}
		for (int j = black2; j < 19; ++j)
		{
			if (p[j + i][j] == '#')
			{
				while (p[j + i][j] == p[j + i + 1][j + 1])
				{
					++black3;
					++j;
				}
				if (black2 < black3)
				{
					black2 = black3;
					black3 = 0;
				}
			}
		}
		for (int j = 0; j < 19; ++j)
		{
			if (p[j + i][j] == '@')
			{
				while (p[j + i][j] == p[j + i + 1][j + 1])
				{
					++white2;
					++j;
				}
				j = 20;
			}
		}
		for (int j = white2; j < 19; ++j)
		{
			if (p[j + i][j] == '@')
			{
				while (p[j + i][j] == p[j + i + 1][j + 1])
				{
					++white3;
					++j;
				}
				if (white2 < white3)
				{
					white2 = white3;
					white3 = 0;
				}
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
void MAX5(char(*p)[20], int i)
{
	int black2 = 0;
	int white2 = 0;
	int black3 = 0;
	int white3 = 0;
	int max = 0;
	char str[5] = {};

	for (int j = 0; j < i + 1; ++j)
	{
		if (p[j][i - j] == '#')
		{
			while (p[j][i - j] == p[j + 1][i - j - 1])
			{
				++black2;
				++j;
			}
			j = 20;
		}
	}
	for (int j = black2; j < i + 1; ++j)
	{
		if (p[j][i - j] == '#')
		{
			while (p[j][i - j] == p[j + 1][i - j - 1])
			{
				++black3;
				++j;
			}
			if (black2 < black3)
			{
				black2 = black3;
				black3 = 0;
			}
		}
	}
	for (int j = 0; j < i + 1; ++j)
	{
		if (p[j][i - j] == '@')
		{
			while (p[j][i - j] == p[j + 1][i - j - 1])
			{
				++white2;
				++j;
			}
			j = 20;
		}
	}
	for (int j = white2; j < i + 1; ++j)
	{
		if (p[j][i - j] == '@')
		{
			while (p[j][i - j] == p[j + 1][i - j - 1])
			{
				++white3;
				++j;
			}
			if (white2 < white3)
			{
				white2 = white3;
				white3 = 0;
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
void MAX6(char(*p)[20], int i)
{
	int black2 = 0;
	int white2 = 0;
	int black3 = 0;
	int white3 = 0;
	int max = 0;
	char str[5] = {};

	for (int j = 1; j < 19; ++j)
	{
		if (p[j][i - j] == '#')
		{
			while (p[j][i - j] == p[j + 1][i - j - 1])
			{
				++black2;
				++j;
			}
			j = 20;
		}
	}
	for (int j = black2; j < 19; ++j)
	{
		if (p[j][i - j] == '#')
		{
			while (p[j][i - j] == p[j + 1][i - j - 1])
			{
				++black3;
				++j;
			}
			if (black2 < black3)
			{
				black2 = black3;
				black3 = 0;
			}
		}
	}
	for (int j = 1; j < 19; ++j)
	{
		if (p[j][i - j] == '@')
		{
			while (p[j][i - j] == p[j + 1][i - j - 1])
			{
				++white2;
				++j;
			}
			j = 20;
		}
	}
	for (int j = white2; j < i + 1; ++j)
	{
		if (p[j][i - j] == '@')
		{
			while (p[j][i - j] == p[j + 1][i - j - 1])
			{
				++white3;
				++j;
			}
			if (white2 < white3)
			{
				white2 = white3;
				white3 = 0;
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