#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	const int FNSZ = 64;
	const int ROWS = 20;
	const int COLS = 30;

	FILE *fp;
	char filename[FNSZ];
	char ch;
	int map[ROWS][COLS];
	char img[ROWS][COLS + 1];
	int i, j;

	puts("Which file should I open?");
	scanf("%s", filename);

	if ((fp = fopen(filename, "r")) == NULL) {
		fprintf(stderr, "Can't open %s file.\n", filename);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLS; j++)
			if (isdigit(ch = getc(fp)))
				map[i][j] = ch - '0';
			else
				j--; /* Either space or a newline */

	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++)
			switch (map[i][j]) {
			case 0:
				img[i][j] = ' '; break;
			case 1:
				img[i][j] = '.'; break;
			case 2:
				img[i][j] = '\''; break;
			case 3:
				img[i][j] = ':'; break;
			case 4:
				img[i][j] = '~'; break;
			case 5:
				img[i][j] = '*'; break;
			case 6:
				img[i][j] = '='; break;
			case 8:
				img[i][j] = '%'; break;
			case 9:
				img[i][j] = '#'; break;
			default:
				img[i][j] = map[i][j];
			}
		img[i][j + 1] = '\0';
	}

	puts("\nImage:");
	for (i = 0; i < ROWS; i++)
		puts(img[i]);

	if (fclose(fp) != 0) {
		fprintf(stderr, "Can't close %s file.\n", filename);
		exit(EXIT_FAILURE);
	}

	return 0;
}
