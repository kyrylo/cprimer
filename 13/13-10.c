#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	static const int FNSZ = 64;
	static const int LINESZ = 256;

	FILE *fp;
	long lineno, pos;
	char filename[FNSZ];
	char line[LINESZ];

	puts("Which file should I open?");
	scanf("%s", filename);

	if ((fp = fopen(filename, "r")) == NULL) {
		fprintf(stderr, "Can't open %s file.\n", filename);
		exit(EXIT_FAILURE);
	}

	puts("Enter the line and the position of the file: ");
	while (scanf("%ld %ld", &lineno, &pos) == 2) {
		while (lineno-- > 1)
			fgets(line, LINESZ, fp);
		while (pos-- > 1)
			fseek(fp, pos, SEEK_CUR);
		fgets(line, LINESZ, fp);
		puts(line);
		rewind(fp);
		printf("Enter the line and the position of %s:\n", filename);
	}


	if (fclose(fp) != 0) {
		fprintf(stderr, "Can't close %s file.\n", filename);
		exit(EXIT_FAILURE);
	}

	return 0;
}
