typedef struct {
	unsigned short id;
	char name[16];
	char abbr[3];
	unsigned short days;
} MONTH;

void clear(void);
void get_day(unsigned short *day);
const MONTH *get_month(char *input_mon, const MONTH months[12]);
void get_year(unsigned short *year);
const MONTH *strfind_mon(const char *substr, const MONTH months[12]);
