#include <stdio.h>
#include <unistd.h>

int ft_printf(const char *str, ...);

int main()
{
	int n = 10;
	char c = 'a';
/*
	printf("====printf====\n");
//	printf("%05%\n");
//	printf("%-05%\n");
	printf("%5c\n", 'a');
	printf("%05c\n", 'b');
	printf("%4.6c\n", 'a');
	printf("%-4.6c\n", 'a');
	printf("%04.6c\n", 'a');
	printf("1 >%*c<\n", n, c);
	printf("2 >%-*c<\n", n, c);
	printf("3 >%*.c<\n", n, c);
	printf("4 >%-c<\n", c);
	printf("5 >%-.c<\n", c);
	printf("6 >%.c<\n", c);
	printf("7 >%10.4c<\n", c);   // .뒤에 숫자 warning
	printf("8 >%.4c<\n", c);     // .뒤에 숫자, warning
	printf("9 >%.c<\n", c);
	printf("10>%0.0c<\n", c);    // warning
	printf("11>%0.c<\n", c);     // warning
	printf("12>%0c<\n", c);

	printf("\n====ft_printf====\n");
	fflush(stdout);
//	ft_printf("%05%\n");
//	ft_printf("%-05%\n");
	ft_printf("%5c\n", 'a');
	ft_printf("%05c\n", 'b');
	ft_printf("%4.6c\n", 'a');
	ft_printf("%-4.6c\n", 'a');
	ft_printf("%04.6c\n", 'a');
	ft_printf("1 >%*c<\n", n, c);
	ft_printf("2 >%-*c<\n", n, c);
	ft_printf("3 >%*.c<\n", n, c);
	ft_printf("4 >%-c<\n", c);
	ft_printf("5 >%-.c<\n", c);
	ft_printf("6 >%.c<\n", c);
	ft_printf("7 >%10.4c<\n", c);   // .뒤에 숫자 warning
	ft_printf("8 >%.4c<\n", c);     // .뒤에 숫자, warning
	ft_printf("9 >%.c<\n", c);
	ft_printf("10>%0.0c<\n", c);    // warning
	ft_printf("11>%0.c<\n", c);     // warning
	ft_printf("12>%0c<\n", c);

	printf("\n====printf====\n");
	printf("%3s\n", "hello");
	printf("%010s\n", "hello");
	printf("%0*.*s\n", 10, 3, "hello");
	printf("%*.*s\n", 2, 3, "hello");
	printf("%-010.3s\n", NULL);
	printf("%010.3s\n", NULL);

	printf("\n====ft_printf====\n");
	fflush(stdout);
	ft_printf("%3s\n", "hello");
	ft_printf("%010s\n", "hello");
	ft_printf("%0*.*s\n", 10, 3, "hello");
	ft_printf("%*.*s\n", 2, 3, "hello");
	ft_printf("%-010.3s\n", NULL);
	ft_printf("%010.3s\n", NULL);

	int *p;
	int num = 9;
	*/
	/*write(1, &num, 16);
	write(1, &p, 16);
	printf("%p\n", p);

	printf("%06d\n", -25);
	*/
	/*
	printf("printf: %.p\n", NULL);
	fflush(stdout);
	ft_printf("ft_printf: %.p\n", NULL);
	*/
	ft_printf("10.0s |%10.0s\n", "Hello");
	ft_printf("10.s  |%10.s\n", "Hello");
	ft_printf("10s   |%10s\n", "Hello");
	ft_printf("10.4s |%10.4s\n", "HEllo");
	ft_printf("10.7s |%10.7s\n", "HEllo");
	ft_printf(".7s   |%.7s\n", "HEllo");
	ft_printf(".3s   |%.3s\n", "HEllo");
	return (0);
}
