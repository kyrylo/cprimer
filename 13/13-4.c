#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	static const int LINESZ = 256;

	FILE *fp;
	char line[LINESZ];

	for (int i = 1; i < argc; i++) {
		printf("\n---\n%s\n---\n\n", argv[i]);
		if ((fp = fopen(argv[i], "r")) == NULL) {
			fprintf(stderr, "Can't open %s.\n", argv[i]);
			exit(EXIT_FAILURE);
		}
		while (fgets(line, LINESZ, fp) != NULL)
			fputs(line, stdout);
		if (fclose(fp) != 0) {
			fprintf(stderr, "Can't close %s.\n", argv[i]);
			exit(EXIT_FAILURE);
		}
	}

	return 0;
}
