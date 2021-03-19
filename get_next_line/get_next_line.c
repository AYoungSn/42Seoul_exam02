#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int		get_next_line(char **line)
{
	char	buf[2];
	char	*tmp;
	int		nread;

	if (line == NULL)
		return (-1);
	*line = ft_strdup("");
	while ((nread = read(0, buf, 1)) > 0)
	{
		buf[nread] = 0;
		if (buf[0] == '\n')
			return 1;
		tmp = *line;
		*line = ft_strjoin(tmp, buf);
		free(tmp);
	}
	return (nread == 0 ? 0 : -1);
}

char	*ft_strdup(char *s)
{
	char *str;
	int size;
	int i;

	size = ft_strlen(s);
	if (!(str = malloc(sizeof(char) * size + 1)))
		return 0;
	i = 0;
	while (i < size)
		str[i++] = *s++;
	str[i] = 0;
	return str;
}

int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int i;

	i = 0;
	if (!src)
		return (0);
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (i);
}

int	ft_strlcat(char *dst, char *src, int dstsize)
{
	int dst_len;
	int src_len;
	int j;
	int i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = dst_len;
	j = 0;
	while (src[j] && j < dstsize - dst_len - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (src_len + dst_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char *result;
	int len1, len2;

	if (!s1 || !s2)
		return 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(result = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (0);
	ft_strlcpy(result, s1, len1 + 1);
	ft_strlcat(result, s2, len2 + len1 + 1);
	return result;
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
