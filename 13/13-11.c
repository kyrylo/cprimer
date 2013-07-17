#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	static const int LINESZ = 256;

	FILE *fp;
	char line[LINESZ];

	if ((fp = fopen(argv[2], "r")) == NULL) {
		fprintf(stderr, "Can't open %s file.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, LINESZ, fp) != NULL) {
		if (strstr(line, argv[1]))
			printf(line);
	}

	if (fclose(fp) != 0) {
		fprintf(stderr, "Can't close %s file.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	return 0;
}
