#define PLANESZ 12
#define NAMESZ 16

typedef struct {
	int id;
	int is_assigned;
	char holder_surname[16];
	char holder_name[16];
} seat;

void eatline(void);
void display_menu(void);
void show_empty_seats_num(size_t size, seat plane[size]);
void show_empty_seats(size_t size, seat plane[size]);
void show_seats_sorted_alphabetically(size_t size, seat plane[size]);
void assign_customer(size_t size, seat plane[size]);
void delete_reservation(size_t size, seat plane[size]);
void refresh_seat(seat *s);
size_t count_empty_seats(size_t size, seat plane[size]);
void init_seat(seat *s, int id, char *name, char *surname);
void load_plane(size_t size, seat plane[size]);
