#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int ch;
	FILE *fp;
	char filename[64];
	long count = 0;


	puts("Enter filename:");
	scanf("%s", filename);
	if ((fp = fopen(filename, "r")) == NULL) {
		printf("Can't open %s\n", filename);
		exit(1);
	}

	while ((ch = getc(fp)) != EOF) {
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("File %s has %ld characters\n", filename, count);

	return 0;
}
