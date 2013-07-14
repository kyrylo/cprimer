#include <stdio.h>
#include <stdlib.h>

#define LINESZ 256

int main(int argc, char *argv[])
{
	FILE *src_fp, *src_copy_fp;
	char line[LINESZ];

	if (argc != 3) {
		fprintf(stderr, "Usage: %s src src_copy\n", argv[0]);
		exit(1);
	}

	if ((src_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s.\n", argv[1]);
		exit(2);
	}

	if ((src_copy_fp = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Can't open %s.\n", argv[2]);
		exit(3);
	}

	while (fgets(line, LINESZ, src_fp) != NULL)
		fputs(line, src_copy_fp);

	fclose(src_fp);
	fclose(src_copy_fp);

	return 0;
}
