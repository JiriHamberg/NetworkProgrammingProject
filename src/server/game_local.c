#include "game.h"

bool is_empty_square(uint32_t x, uint32_t y, struct ocean *my_ocean) {
	int i, j;
	uint32_t w = my_ocean -> height;
	uint32_t h = my_ocean -> width;
	struct ship *cur_ship;

	for(for i=0; i < NUM_SHIPS; i++) {
		cur_ship = my_ocean -> ships[i];
		
		if(cur_ship -> orientation == VERTICAL) {
			if(ship -> x == x) {
				for(j = ship->y - 1; j <= ship->y + 1; j++) {
					if(j % h  == y) {
						return true;
					}
				}
			}
		} else if(cur_ship -> orientation == HORIZONTAL) {
			if(ship -> y == y) {
				for(j = ship->x - 1; j <= ship->x + 1; j++) {
					if(j % h  == x) {
						return true;
					}
				}
			}
		}
	}
	return false;
}