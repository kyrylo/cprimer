#include <stdio.h>
#include <stdlib.h>
#define MAX 40

int main(void)
{
	FILE *fp;
	char words[MAX];
	size_t word_ct = 0;

	if ((fp = fopen("wordy", "a+")) == NULL)
	{
		fprintf(stdout,"Can't open \"words\" file.\n");
		exit(1);
	}

	puts("Enter words to add to the file; press the Enter");
	puts("key at the beginning of a line to terminate.");
	while (gets(words) != NULL  && words[0] != '\0')
		fprintf(fp, "%s ", words);

	puts("File contents:");
	rewind(fp);
	while (fscanf(fp,"%s",words) == 1) {
		printf("%d ", ++word_ct);
		puts(words);
	}

	if (fclose(fp) != 0)
		fprintf(stderr,"Error closing file\n");

	return 0;
}
