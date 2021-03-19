#include <unistd.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void inter(char *s1, char *s2);

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	inter(argv[1], argv[2]);
	write(1, "\n", 1);
}

void inter(char *s1, char *s2)
{
	int asci[256];
	int i, j;
	
	i = 0;
	while (i < 256)
		asci[i++] = 0;
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j] && s1[i] != s2[j])
			j++;
		if (s1[i] == s2[j] && asci[(int)s1[i]] == 0)
		{
			asci[(int)s1[i]] = 1;
			write(1, s1 + i, 1);
		}
		i++;
	}
}
