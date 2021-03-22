#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int get_next_line(char **line)
{
	char buf[2];
	int nread;
	char *tmp;

	if (line ==NULL)
		return -1;
	*line = ft_strdup("");
	while ((nread = read(0, buf, 1))>0)
	{
		buf[nread] = 0;
		if (buf[0] == '\n')
			return (1);
		tmp = *line;
		*line = ft_strjoin(tmp, buf);
		free(tmp);
	}
	return (nread == 0? 0 : -1);
}

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strdup(char *s)
{
	char *result;
	int size;
	int i;

	size = ft_strlen(s);
	if (!(result = malloc(sizeof(char) * size + 1)))
		return 0;
	i = 0;
	while (i < size)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char *ft_strjoin(char *s1, char *s2)
{
	int len1, len2;
	int i;
	char *result;

	if (!s1 || !s2)
		return 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(result = malloc(sizeof(char) * (len1 + len2 + 1))))
		return 0;
	i = 0;
	while (i < len1)
	{
		result[i] = *s1++;
		i++;
	}
	while (i < len1 + len2)
	{
		result[i] = *s2++;
		i++;
	}
	result[i] = 0;
	return result;
}
