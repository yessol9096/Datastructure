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

		printf("¡¬«•∏¶ ¿‘∑¬«œΩ√ø¿:");
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
	printf("------------------∞°∑Œ----------------------\n");
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
		printf("\n%2dπ¯¬∞ ¡Ÿ ∞À¿∫µπ ∞πºˆ:%d »Úµπ ∞πºˆ:%d  \n  ", i + 1, black, white);
		MAX1(p, i);
		black = 0;
		white = 0;

	}
}
void COLUMN(char(*p)[20])
{
	int black = 0;
	int white = 0;
	printf("-----------------ºº∑Œ----------------------\n");
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (p[j][i] == '#')
				++black;
			else if (p[j][i] == '@')
				++white;
		}
		printf("%2dπ¯¬∞ ¡Ÿ ∞À¿∫µπ ∞πºˆ:%d »Úµπ ∞πºˆ:%d\n ", i + 1, black, white);
		MAX2(p, i);
		black = 0;
		white = 0;
	}
};
void DIA(char(*p)[20], int x, int y)
{
	int black = 0;
	int white = 0;
	printf("-------------------øﬁ¬ ¥Î∞¢º±---------------------\n");
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
			printf("%2dπ¯¬∞ ¡Ÿ ∞À¿∫µπ ∞πºˆ:%d »Úµπ ∞πºˆ:%d\n ", 19 - i, black, white);
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
			printf("%2dπ¯¬∞ ¡Ÿ ∞À¿∫µπ ∞πºˆ:%d »Úµπ ∞πºˆ:%d\n ", 19 + i, black, white);
			MAX3(p, i);
			black = 0;
			white = 0;
		}
	}
	printf("-------------------ø¿∏•¬ ¥Î∞¢º±---------------------\n");
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (p[j][i - j] == '#')
				++black;
			else if (p[j][i - j] == '@')
				++white;
		}
		printf("%2dπ¯¬∞ ¡Ÿ ∞À¿∫µπ ∞πºˆ:%d »Úµπ ∞πºˆ:%d\n ", i + 1, black, white);
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
		printf("%2dπ¯¬∞ ¡Ÿ ∞À¿∫µπ ∞πºˆ:%d »Úµπ ∞πºˆ:%d\n ", i + 1, black, white);
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
	int count = 0;
	int white[19];
	int black[19];
	int white4[19];
	int black4[19];
	int b = 0;
	int w = 0;
	int b1 = 0;
	int w1 = 0;
	for (int j = 0; j < 19; ++j)
	{
		if (p[i][j] == '#')
		{
			black[b] = j + 1;
			while (j < 19)
			{
				if (p[i][j] == p[i][j + 1])
				{
					++black2;
					++j;
					++b;
					black[b] = j + 1;

				}
				else
				{
					if (p[i][j] == p[i][j + 2])
					{
						++black2;
						j += 2;
						++b;
						black[b] = j + 1;

					}
					else
					{
						count = j;
						j = 20;
					}
				}
			}
		}
	}
	for (int j = count; j < 19; ++j)
	{
		if (p[i][j] == '#')
		{
			black4[b1] = j;
			while (j < 19)
			{
				if (p[i][j] == p[i][j + 1])
				{
					++black3;
					++j;
					++b1;
					black4[b1] = j + 1;

				}
				else
				{
					if (p[i][j] == p[i][j + 2])
					{
						++black3;
						j += 2;
						++b1;
						black4[b1] = j + 1;

					}
					else
					{
						count = j;
						j = 20;
					}
				}
			}
		}
	}
	if (black2 < black3)
	{
		black2 = black3;
		black3 = 0;
		for (int i = 0; i < b1 + 1; ++i)
			black[i] = black4[i];
		b = b1 + 1;
	}
	for (int j = 0; j < 19; ++j)
	{
		if (p[i][j] == '@')
		{
			white[w] = j + 1;
			while (j < 19)
			{
				if (p[i][j] == p[i][j + 1])
				{
					++white2;
					++j;
					++w;
					white[w] = j + 1;
				}
				else
				{
					if (p[i][j] == p[i][j + 2])
					{
						++white2;
						j += 2;
						++w;
						white[w] = j + 1;
					}
					else
					{
						count = j;
						j = 20;
					}
				}
			}
		}
	}
	for (int j = count; j < 19; ++j)
	{
		if (p[i][j] == '@')
		{
			white4[w1] = j;
			while (j < 19)
			{
				if (p[i][j] == p[i][j + 1])
				{
					++white3;
					++j;
					++w1;
					white4[w1] = j + 1;
				}
				else
				{
					if (p[i][j] == p[i][j + 2])
					{
						++white3;
						j += 2;
						++w1;
						white4[w1] = j + 1;
					}
					else
					{
						count = j;
						j = 20;
					}
				}
			}

		}
	}
	if (white2 < white3)
	{
		white2 = white3;
		white3 = 0;
		for (int i = 0; i < w1 + 1; ++i)
			white[i] = white4[i];
		w = w1 + 1;
	}
	if (black2 > white2)
	{
		max = black2 + 1;
		printf("√÷¥Î: ∞À ");
		for (int i = 0; i < b + 1; ++i)
			printf("(1,%d)", black[i]);
		if (b > 2 && p[i][b + 1] == '+')
		{
			p[i][b + 1] = '*';
		}
	}
	else if (black2 < white2)
	{
		max = white2 + 1;
		printf("√÷¥Î: »Ú ");
		for (int i = 0; i < w + 1; ++i)
			printf("(1,%d)", white[i]);
		if (w > 2 && p[i][w + 1] == '+')
		{
			p[i][w + 1] = '*';
		}
	}

	else
		max = 0;
	printf("√÷¥Î : %d ", max);
	max = 0;
	black2 = 0;
	white2 = 0;
};