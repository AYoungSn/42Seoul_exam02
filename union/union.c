#include <unistd.h>

void ft_union(char *s1, char *s2)
{
	int asci[256];
	int i;

	i = 0;
	while (i < 256)
		asci[i++] = 0;
	i = 0;
	while (s1[i])
	{
		if (asci[(int)s1[i]] == 0)
		{
			asci[(int)s1[i]] = 1;
			write(1, s1 + i, 1);
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (asci[(int)s2[i]] == 0)
		{
			asci[(int)s2[i]] = 1;
			write(1, s2 + i, 1);
		}
		i++;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
}
