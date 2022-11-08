#include <string.h>
#include<stdio.h>

size_t	ft_strlen(const char *str)
{
	const char	*ptr;

	ptr = str;
	while (*ptr)
		ptr++;
	return (ptr - str);
}

int main(void)
{
	char s1[15] = "Hello World";
	char s2[15] = "what s up";
	printf("i = %ld\n",ft_strlen(s1));
	return 0;
}