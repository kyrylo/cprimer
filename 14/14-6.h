#define NAMESZ 32
#define TEAMSZ 18
#define TEAMFILE "14-6.txt"

typedef struct {
	unsigned short num;
	char name[NAMESZ];
	char surname[NAMESZ];
	unsigned short otbs;
	unsigned short hits;
	unsigned short walks;
	unsigned short rbis;
	float batting_avg;
} player;

void init_team(const size_t size, player team[size]);
void seed_team(player team[]);
void clear(FILE *fp);
void calculate_avg(player team[]);
void calculate_team_avg(player team[]);
