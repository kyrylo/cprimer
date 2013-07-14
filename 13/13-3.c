#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	static const int FILENAMESZ = 64;

	FILE *src_fp, *dest_fp;
	char ch;
	char src_fn[FILENAMESZ], dest_fn[FILENAMESZ];

	puts("Enter source filename:");
	scanf("%s", src_fn);
	puts("Enter destination filename:");
	scanf("%s", dest_fn);

	if ((src_fp = fopen(src_fn, "r")) == NULL) {
		fprintf(stderr, "Can't open %s file.\n", src_fn);
		exit(EXIT_FAILURE);
	}

	if ((dest_fp = fopen(dest_fn, "w")) == NULL) {
		fprintf(stderr, "Can't open %s file.\n", dest_fn);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(src_fp)) != EOF)
		putc(toupper(ch), dest_fp);

	if (fclose(src_fp) != 0 || fclose(dest_fp) != 0) {
		fprintf(stderr, "Can't close one of the files: %s or %s.\n",
			src_fn, dest_fn);
		exit(EXIT_FAILURE);
	}

	return 0;
}
