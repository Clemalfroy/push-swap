#include "checker.h"

#define BUF_SIZE 4

static void swap(t_list *a, t_list *b)
{
	(void)a;
	(void)b;
}

static void initsort(t_sort *sort)
{
	sort[0] = (t_sort){ "sa", swap };
	sort[1] = (t_sort){ "sa", swap };
	sort[2] = (t_sort){ "sa", swap };
	sort[3] = (t_sort){ "sa", swap };
	sort[4] = (t_sort){ "sa", swap };
	sort[5] = (t_sort){ "sa", swap };
	sort[6] = (t_sort){ "sa", swap };
	sort[7] = (t_sort){ "sa", swap };
	sort[8] = (t_sort){ "sa", swap };
	sort[9] = (t_sort){ "sa", swap };
	sort[10] = (t_sort){ "sa", swap };
	sort[11] = (t_sort){ NULL, NULL };
}

inline int getactions(t_list *a, t_list *b)
{
	char	buf[BUF_SIZE];
	ssize_t	rd;
	ssize_t i;
	t_sort  sort[12];

	initsort(sort);
	while ((rd = read(STDIN_FILENO, buf, BUF_SIZE)) > 0)
	{
		buf[rd - 1] = '\0';
		i = -1;
		while (sort[++i].sort != NULL)
			if (!ft_strcmp(sort[i].sort, buf))
			{
				sort[i].func(a, b);
				break;
			}
		if (i == 11)
			return (FALSE);
	}
	return (TRUE);
}
