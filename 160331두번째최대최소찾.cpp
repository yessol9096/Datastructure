#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct champion
{
	char name[10];
	char position[10];
	double hp, mp, speed, range;
};
//int compare(const void *first, const void *second)
//{
// double v1, v2;
// v1 = ((champion*)first)->hp;
// v2 = ((champion*)second)->hp;
//
// if (v1 < v2)
//  return 1;
// else if (v1 > v2)
//  return -1;
//}
void _search(struct champion s[], int n);
void _search2(struct champion s[], char sName[], int n);
void _insert(struct champion s[], int n);
void _insert2(struct champion s[], struct champion _new, int n);
void _delete(struct champion s[], int n);
void _delete2(struct champion s[], char sName[], int n);
void _deleteall(struct champion s[], int n);
void _deleteall2(struct champion s[], char sName[], int n);
void _printall(struct champion s[], int n);
void _printall2(struct champion s[], int n);
void _findmaxhp(struct champion s[], int n);
void _findmaxhp2(struct champion s[], struct champion _new, int n);
void _sortbyhp(struct champion s[], int n);
void _sortbyhp2(struct champion s[], int left, int right);

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
		{ "아스오", "mid", 517.76, 60, 345, 175 },

	};
	while (1)
	{
		printf("명령어를 입력하시오: ");
		scanf_s("%s", order, 10);

		if (strcmp(order, "search") == 0)
		{
			_search(ch, 0);
		}
		else if (strcmp(order, "insert") == 0)
		{
			_insert(ch, 0);
		}
		else if (strcmp(order, "delete") == 0)
		{
			_delete(ch, 0);
		}
		else if (strcmp(order, "deleteall") == 0)
		{
			_deleteall(ch, 0);
		}
		else if (strcmp(order, "printall") == 0)
		{
			_printall(ch, 0);
		}
		else if (strcmp(order, "findmaxhp") == 0)
		{
			_findmaxhp(ch, 0);
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

	_search2(s, sName, n);
};
void _search2(struct champion s[], char sName[], int n)
{
	if (n < 31)
	{
		if (strcmp(sName, s[n].name) == 0)
		{
			printf("%s %g %g %g %g\n", s[n].position, s[n].hp, s[n].mp, s[n].speed, s[n].range);
		}
		_search2(s, sName, n + 1);
	}
	else
		return;


};
void _insert(struct champion s[], int n)
{
	struct champion _new;
	printf("챔피언의 정보를 입력하시오: ");
	scanf_s("%s %s %lf %lf %lf %lf", _new.name, 10, _new.position, 10, &_new.hp, &_new.mp, &_new.speed, &_new.range);
	_insert2(s, _new, n);
};
void _insert2(struct champion s[], struct champion _new, int n)
{
	if (s[n].hp == 0)
	{
		s[n] = _new;
		return;
	}
	else
	{
		_insert2(s, _new, n + 1);
	}
};
void _delete(struct champion s[], int n)
{
	char sName[10];
	printf("챔피언이름을 입력하시오: ");
	scanf_s("%s", sName, 10);

	_delete2(s, sName, n);
};
void _delete2(struct champion s[], char sName[], int n)
{
	if (n < 31)
	{
		if (strcmp(sName, s[n].name) == 0)
		{
			s[n] = {};
		}
		_delete2(s, sName, n + 1);
	}
	else
		return;

};
void _deleteall(struct champion s[], int n)
{
	char sName[10];
	printf("챔피언포지션을 입력하시오: ");
	scanf_s("%s", sName, 10);
	_deleteall2(s, sName, n);
};
void _deleteall2(struct champion s[], char sName[], int n)
{
	if (n < 31)
	{
		if (strcmp(sName, s[n].position) == 0)
		{
			s[n] = {};
		}
		_deleteall2(s, sName, n + 1);
	}
	else
		return;
};
void _printall(struct champion s[], int n)
{
	_printall2(s, n);
};
void _printall2(struct champion s[], int n)
{
	if (n > 29)
		return;
	else
	{
		if (s[n].hp != 0)
			printf("%s %s %g %g %g %g\n", s[n].name, s[n].position, s[n].hp, s[n].mp, s[n].speed, s[n].range);
		_printall2(s, n + 1);
	}
};
void _findmaxhp(struct champion s[], int n)
{
	struct champion max = s[0];
	_findmaxhp2(s, max, n);

};
void _findmaxhp2(struct champion s[], struct champion _new, int n)
{
	if (n < 30)
	{
		if (_new.hp < s[n].hp)
		{
			_new = s[n];

		}
		_findmaxhp2(s, _new, n + 1);

	}
	else
	{
		printf("%s %s %g %g %g %g\n", _new.name, _new.position, _new.hp, _new.mp, _new.speed, _new.range);
		for (int i = 0; i < 30; i++)
		{
			if (_new.hp == s[i].hp && _new.mp != s[i].mp)
			{
				printf("%s %s %g %g %g %g\n", s[i].name, s[i].position, s[i].hp, s[i].mp, s[i].speed, s[i].range);
			}
		}
		return;
	}
};
void _sortbyhp(struct champion s[], int n)
{
	_sortbyhp2(s, 0, 29);
};
void _sortbyhp2(struct champion s[], int left, int right)
{
	struct champion p, t;
	int i, j;
	if (left < right)
	{
		p = s[left];
		i = left;
		j = right + 1;
		while (1)
		{
			while (s[++i].hp > p.hp);
			while (s[--j].hp < p.hp);
			if (i >= j)
				break;
			t = s[i];
			s[i] = s[j];
			s[j] = t;
		}
		s[left] = s[j];
		s[j] = p;
		_sortbyhp2(s, left, i - 1);
		_sortbyhp2(s, j + 1, right);
	}
};