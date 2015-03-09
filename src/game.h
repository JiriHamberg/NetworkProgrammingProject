#include "common.h"

#define NUM_SHIPS 5
#define SHIP_SIZE 3

typedef enum {VERTICAL, HORIZONTAL} orientation;

typedef enum {UP, DOWN, LEFT, RIGHT} direction;

struct ship {
	//x-coordinate of the middle-section of this ship
	uint32_t x;
	//y-coordinate of the middle-section of this ship
	uint32_t y;
	bool[SHIP_SIZE] hit_box;
	orientation ship_orientation;
};
 

/* player spesific part of the ocean
   - contains only user's ships */
struct ocean {
	uint32_t height;
	uint32_t width;
	//list of all ships
	struct ship *ships; 
};
