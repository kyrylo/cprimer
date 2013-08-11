#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "14-6.h"

int main(void)
{
	player team[TEAMSZ];
	player *pl;
	size_t teamsize;
	unsigned short team_otbs, team_hits, team_walks, team_rbis;

	init_team(TEAMSZ, team);
	seed_team(team);
	calculate_avg(team);

	team_otbs = team_hits = team_walks = team_rbis = teamsize = 0;
	for (int i = 0; i < TEAMSZ; i++) {
		pl = &team[i];
		if (pl->num == 0)
			continue;
		printf("%.2hu - %-8s %-15s [%-2hu %-2hu %-2hu %hu] (avg = %.2f)\n",
		       pl->num, pl->name, pl->surname, pl->otbs, pl->hits,
		       pl->walks, pl->rbis, pl->batting_avg);
		team_otbs += pl->num;
		team_hits += pl->hits;
		team_walks += pl->walks;
		team_rbis += pl->rbis;
		teamsize++;
	}

	puts("--------------");
	printf("[%hu %hu %hu %hu] (avg = %.2f)\n",
	       team_otbs, team_hits, team_walks, team_rbis,
	       (team_otbs + team_hits +
		team_walks + team_rbis) / (float) teamsize);

	return 0;
}

void init_team(const size_t size, player team[size])
{
	player *pl;

	for (int i = 0; i < size; i++) {
		pl = &team[i];

		pl->name[0] = pl->surname[0] = '\0';
		pl->num = pl->otbs = pl->hits = pl->walks = pl->rbis = 0U;
		pl->batting_avg = 0;
	}
}

void seed_team(player team[])
{
	unsigned short tempnum, tempotbs, temphits, tempwalks, temprbis;
	char tempstr[32];
	player *pl;
	FILE *fp;
	char ch;

	if ((fp = fopen(TEAMFILE, "r")) == NULL) {
		fprintf(stderr, "Can't open %s file!\n", TEAMFILE);
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(fp)) != EOF) {
		ungetc(ch, fp);
		fscanf(fp, "%hu", &tempnum);
		pl = &team[tempnum - 1];
		if (pl->num == 0)
			pl->num = tempnum;

		fscanf(fp, "%s", tempstr);
		if (pl->name[0] == '\0')
			strncpy(pl->name, tempstr, NAMESZ);

		fscanf(fp, "%s", tempstr);
		if (pl->surname[0] == '\0')
			strncpy(pl->surname, tempstr, NAMESZ);

		if (pl->num != 0) {
			fscanf(fp, "%hu %hu %hu %hu",
			       &tempotbs, &temphits, &tempwalks, &temprbis);
			pl->otbs += tempotbs;
			pl->hits += temphits;
			pl->walks += tempwalks;
			pl->rbis += temprbis;
		}

		clear(fp);
	}

	if (fclose(fp) != 0) {
		fprintf(stderr, "Can't close %s!\n", TEAMFILE);
		exit(EXIT_FAILURE);
	}
}


void clear(FILE *fp)
{
	int ch;

	while ((ch = fgetc(fp)) != '\n')
		continue;
}

void calculate_avg(player team[])
{
	player *pl;
	for (int i = 0; i < TEAMSZ; i++)
		if ((pl = &team[i])->num != 0)
			pl->batting_avg = (pl->otbs +
					   pl->hits +
					   pl->walks +
					   pl->rbis) / 4.0;
}
