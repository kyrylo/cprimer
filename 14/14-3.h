#define MAXTITL   40
#define MAXAUTL   40
#define MAXBKS   100

typedef struct {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
} book;

typedef void (*sm)(book *, book, int, int);

void print_library(const book *library, int count);
void sort(book *library, int count, sm sorting_method);
void alphabetically(book *library, book temp, int, int);
void by_value(book *library, book temp, int, int);
void print_delim(void);
int fltcmp(const float, const float);
