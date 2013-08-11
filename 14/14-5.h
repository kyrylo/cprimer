#define CSIZE 4
#define GRADES 3

struct name {
	char first[32];
	char surname[32];
};

struct student {
	struct name name;
	float grades[GRADES];
	float avg;
};

void clear(void);
