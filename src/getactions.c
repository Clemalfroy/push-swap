#include "checker.h"

#define BUF_SIZE 4

inline int getactions()
{
	char	buf[BUF_SIZE + 1];
	int	rd;
	while ((rd = read(STDIN_FILENO, buf, BUF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		if (ft_strncmp("rra", buf, 3))
			return (FALSE);
	}
	return (TRUE);
}
