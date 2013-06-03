#include <stdio.h>
#include <string.h>

#define LIM 4

char * k00_strncpy(char *dest, const char *src, int n);

int main(void)
{
	char dest[LIM];
	char src[LIM];
	
	while (1) {
		printf("Enter dest(4): ");
		fgets(dest, LIM+1, stdin);
		
		printf("Enter src(4): ");
		fgets(src, LIM+1, stdin);
		
		k00_strncpy(dest, src, LIM);
		printf("Result:\n");
		puts(dest);
	}
	
	return 0;
}

char * k00_strncpy(char *dest, const char *src, int n)
{
	int i;
	
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for ( ; i < n; i++)
		dest[i] = '\0';
	
	return dest;
}
