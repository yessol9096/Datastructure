#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct champion
{
	char name[10];
	char position[10];
	double hp, mp, speed, range;
};
int compare(const void *first, const void *second)
{
	double v1, v2;
	v1 = ((champion*)first)->hp;
	v2 = ((champion*)second)->hp;
	if (v1 < v2)
		return 1;
	else if (v1 > v2)
		return -1;
}
void _search(struct champion s[], int n);
void _insert(struct champion s[], int n);
void _delete(struct champion s[], int n);
void _deleteall(struct champion s[], int n);
void _printall(struct champion s[], int n);
void _findmaxhp(struct champion s[], int n);
void _sortbyhp(struct champion s[], int n);

int main()
{
	int con = 0;
	char order[10];
	struct champion ch[30] =
	{
		{ "레오나", "top", 576.16, 302.2, 335, 125 },
		{ "가렌",   "top", 616.28, 0, 340, 175 },
		{ "갈리오", "top", 577.8, 369, 335, 125 },
		{ "나서스", "top", 561.2, 325.6, 350, 125 },
		{ "누누", "sup", 598.28, 283.56, 350, 125 },
		{ "니달리", "sup", 541.2, 295.6, 335, 525 },
		{ "나미"  , "sup", 489.32, 377.24, 335, 550 },
		{ "소라카", "sup", 529.04, 350.8, 325, 550 },
		{ "녹턴"  , "jun", 582.8, 273.8, 345, 125 },
		{ "신짜오", "jun", 591.16, 273.8, 345, 175 },
		{ "카직스", "jun", 572.8, 327.2, 350, 125 },
		{ "렝가", "jun", 586.2, 5, 345, 125 },
		{ "드레이븐", "one", 557.76, 360.56, 330, 550 },
		{ "나르", "one", 540, 100, 325, 150 },
		{ "우르곳", "one", 586.52, 312.4, 335, 425 },
		{ "제이스", "one", 571.2, 357.2, 335, 125 },
		{ "룰루", "mid", 552.76, 292.4, 325, 550 },
		{ "다이애나","mid", 589.2, 297.2, 345, 150 },
		{ "밸코즈", "mid", 507.68, 375.6, 340, 525 },
		{ "아스오", "mid", 517.76, 60, 345, 175 }
	};
	while (1)
	{
		printf("명령어를 입력하시오: ");
		scanf_s("%s", order, 10);

		if (strcmp(order, "search") == 0)
		{
			_search(ch, 30);
		}
		else if (strcmp(order, "insert") == 0)
		{
			++con;
			int count = 20 + con;
			_insert(ch, count);
		}
		else if (strcmp(order, "delete") == 0)
		{
			_delete(ch, 30);
		}
		else if (strcmp(order, "deleteall") == 0)
		{
			_deleteall(ch, 30);
		}
		else if (strcmp(order, "printall") == 0)
		{
			_printall(ch, 30);
		}
		else if (strcmp(order, "findmaxhp") == 0)
		{
			_findmaxhp(ch, 30);
		}
		else if (strcmp(order, "sortbyhp") == 0)
		{
			_sortbyhp(ch, 30);
		}
		else
			continue;
	}

}
void _search(struct champion s[], int n)
{
	char sName[10];
	printf("챔피언이름을 입력하시오: ");
	scanf_s("%s", sName, 10);
	for (int i = 0; i < n; ++i)
	{
		if (strcmp(sName, s[i].name) == 0)
		{
			printf("%s %g %g %g %g\n", s[i].position, s[i].hp, s[i].mp, s[i].speed, s[i].range);
			break;
		}
	}
};
void _insert(struct champion s[], int n)
{
	printf("챔피언의 정보를 입력하시오: ");
	scanf_s("%s %s %lf %lf %lf %lf", s[n].name, 10, s[n].position, 10, &s[n].hp, &s[n].mp, &s[n].speed, &s[n].range);
};
void _delete(struct champion s[], int n)
{
	char sName[10];
	printf("챔피언이름을 입력하시오: ");
	scanf_s("%s", sName, 10);
	for (int i = 0; i < n; ++i)
	{
		if (strcmp(sName, s[i].name) == 0)
		{
			s[i] = {};
			break;
		}
		else
			continue;
	}
};
void _deleteall(struct champion s[], int n)
{
	char sName[10];
	printf("챔피언포지션을 입력하시오: ");
	scanf_s("%s", sName, 10);
	for (int i = 0; i < n; ++i)
	{
		if (strcmp(sName, s[i].position) == 0)
		{
			s[i] = {};
		}
	}
};
void _printall(struct champion s[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (s[i].hp != 0)
			printf("%s %s %g %g %g %g\n", s[i].name, s[i].position, s[i].hp, s[i].mp, s[i].speed, s[i].range);
	}
};
void _findmaxhp(struct champion s[], int n)
{
	struct champion max = s[0];
	for (int i = 0; i < n; ++i)
	{
		if (max.hp < s[i].hp)
			max = s[i];
	}
	printf("%s %s %g %g %g %g\n", max.name, max.position, max.hp, max.mp, max.speed, max.range);
};
void _sortbyhp(struct champion s[], int n)
{
	qsort(s, n, sizeof(champion), compare);
};
