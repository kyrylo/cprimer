#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char ch;
	size_t ct = 0;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s char [file1 file2 fileN...]\n",
			argv[0]);
		exit(EXIT_FAILURE);
	} else if (argc > 3)
		for (int i = 2; i < argc; i++) {
			if ((fp = fopen(argv[i], "r")) == NULL) {
				fprintf(stderr, "Can't open %s.\n", argv[i]);
				continue;
			}

			while ((ch = getc(fp)) != EOF)
				if (ch == *argv[1])
					ct++;

			printf("I found %d occurrences of \"%c\" in %s file.\n",
			       ct, *argv[1], argv[i]);

			if (fclose(fp) != 0) {
				fprintf(stderr, "Can't close %s.\n", argv[i]);
				continue;
			}
		}
	else if (argc == 2) {
		while ((ch = getc(stdin)) != EOF)
			if (ch == *argv[1])
				ct++;
		printf("I found %d occurrences of \"%c\".\n", ct, *argv[1]);

	}

	return 0;
}
