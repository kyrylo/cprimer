/*
 * WARNING: I'm not sure about the correctness of this program. The deglitch()
 *          function seems to be wrong. Furthermore, the original "image" doesn't
 *          even make any sense to me.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static void deglitch(size_t rows, size_t cols, int map[rows][cols]);

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
	deglitch(ROWS, COLS, map);

	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++)
			printf("%d ", map[i][j]);
		putchar('\n');
	}
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

static void deglitch(size_t rows, size_t cols, int map[rows][cols])
{
	int i, j, n, s, w, e;
	int neighbors, val;

	n = s = w = e = 0;

	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++) {
			neighbors = 0;
			if (i > 0) {
				n = map[i - 1][j];
				neighbors++;
			}
			if (i < rows - 1) {
				s = map[i + 1][j];
				neighbors++;
			}
			if (j > 0) {
				w = map[i][j - 1];
				neighbors++;
			}
			if (j < cols - 1) {
				e = map[i][j + 1];
				neighbors++;
			}

			val = map[i][j];
			if (abs(val - n) > 1 || abs(val - s) > 1 ||
			    abs(val - w) > 1 || abs(val - e) > 1)
				map[i][j] = ((n + s + w + e) / neighbors) % 9;
		}
}
