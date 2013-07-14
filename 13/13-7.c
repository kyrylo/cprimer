#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	static const int LINESZ = 256;

	FILE *fp1, *fp2;
	int fp1_not_empty, fp2_not_empty = 1;
	char line1[LINESZ];
	char line2[LINESZ];
	size_t len;

	if ((fp1 = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can't open %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((fp2 = fopen(argv[2], "r")) == NULL) {
		fprintf(stderr, "Can't open %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while (fp1_not_empty || fp2_not_empty) {
		if (fgets(line1, LINESZ, fp1) == NULL)
			fp1_not_empty = 0;
		if (fgets(line2, LINESZ, fp2) == NULL)
			fp2_not_empty = 0;

		if (fp1_not_empty) {
			if (fp2_not_empty) {
				len = strlen(line1) - 1;
				if (line1[len] == '\n')
					line1[len] = '\0';
			}
			printf(line1);
		}
		if (fp2_not_empty)
			printf(line2);
	}

	if (fclose(fp1) != 0 || fclose(fp2) != 0) {
		fputs("Can't close some files!", stderr);
		exit(EXIT_FAILURE);
	}

	return 0;
}
