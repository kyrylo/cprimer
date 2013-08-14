/*
 * WARNING: This implementation is half-assed. I got bored writing this.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

size_t trim(char *out, size_t len, const char *str);
void clear(void);

int main(void)
{
	char ch, str[32];
	int count, col, i, index, filecount, size, chosen, action;
	FILE *pbooks, *psource, *tempstream;
	struct book library[MAXBKS];

	size = sizeof(struct book);
	count = col = i = 0;

	if ((pbooks = fopen("book14-7.dat", "r+b")) == NULL) {
		fputs("Can't open book14-7.dat file\n",stderr);
		exit(1);
	}

	rewind(pbooks);
	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1) {
		if (count == 0)
			puts("Current contents of book14-7.dat:");
		printf("%s by %s: $%.2f\n",library[count].title,
		       library[count].author, library[count].value);
		count++;
	}
	filecount = count;
	if (count == MAXBKS) {
		fputs("The book.dat file is full.\n", stderr);
		exit(2);
	}

	if ((psource = fopen("14-7.txt", "r")) == NULL) {
		fputs("Can't open 14-7.txt file\n", stderr);
		exit(3);
	}

	while ((ch = fgetc(psource)) != EOF)
		if (ch == '|' || ch == '\n') {
			ch == '|' ? col++ : (col = 0);
			str[i] = '\0';

			trim(str, 32, str);
			tempstream = fmemopen(str, strlen(str), "r");

			switch (col) {
			case 0:
				fgets(str, sizeof(str), tempstream);
				sscanf(str, "%f", &library[count].value);
				count++;
				break;
			case 1:
				fgets(library[count].title, MAXTITL, tempstream);
				break;
			case 2:
				fgets(library[count].author, MAXAUTL, tempstream);
				break;
			}

			i = 0;
			memset(str, '\0', sizeof(str));
		} else
			str[i++] = ch;

	if (count > 0) {
		puts("Here is the list of your books:");
		for (index = 0; index < count; index++)
			printf("%d %s by %s: $%.2f\n", index,
			       library[index].title, library[index].author,
			       library[index].value);
		puts("Choose a book (enter number):");
		scanf("%d", &chosen);

		printf("Choose action for %s (1 - delete, 2 - modify)\n",
		       library[chosen].title);
		scanf("%d", &action);

		switch (action) {
		case 1:
			strcpy(library[chosen].title, "nothing");
			strcpy(library[chosen].author, "no-one");
			library[chosen].value = 0.0;
			break;
		case 2:
			puts("Nice, what would you like to modify?");
			puts("1 - title, 2 - author, 3 - value");
			scanf("%d", &action);
			clear();
			switch (action) {
			case 1:
				printf("Enter the new title: ");
				fgets(library[chosen].title, MAXTITL, stdin);
				break;
			case 2:
				printf("Enter the new author: ");
				fgets(library[chosen].author, MAXAUTL, stdin);
				break;
			case 3:
				printf("Enter the new value: ");
				scanf("%f", &library[chosen].value);
				clear();
				break;
			}
			break;
		}

		fwrite(&library[filecount], size, count - filecount, pbooks);
	} else
		puts("No books? Too bad.\n");

	puts("Bye.\n");
	fclose(pbooks);
	fclose(psource);
	fclose(tempstream);

	return 0;
}

size_t trim(char *out, size_t len, const char *str)
{
	const char *end;
	size_t out_size;

	if(len == 0)
		return 0;

	while(isspace(*str))
		str++;

	if(*str == 0) {
		*out = 0;
		return 1;
	}

	end = str + strlen(str) - 1;
	while(end > str && isspace(*end))
		end--;
	end++;

	out_size = (end - str) < len-1 ? (end - str) : len-1;

	memcpy(out, str, out_size);
	out[out_size] = '\0';

	return out_size;
}

void clear(void)
{
	while (getchar() != '\n')
		continue;
}
