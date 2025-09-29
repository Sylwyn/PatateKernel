#include "../headers/output.h"
#include "../headers/types.h"

#define VGA_MEMORY 0xB8000
#define VGA_WIDTH   80
#define VGA_HEIGHT  25

static uint8_t x;
static uint8_t y;
uint16_t *buffer;

void initialize_output(){
	x = 0;
	y = 0;
	buffer = (uint16_t *)VGA_MEMORY;
}

void print_string(char *s){
	return;
	/*int n = 0;
	while (s[n] != '0'){
		switch(s[n]){
			case '\n':
				if (y == VGA_HEIGHT - 1){
					for (int i = 0; i < VGA_HEIGHT - 1; i += 1){
						for (int j = 0; j < VGA_WIDTH; j += 1){
							buffer[j + VGA_WIDTH * i] = buffer[j + VGA_WIDTH * (i + 1)]; 
						}
					}
				}else{
					y += 1;
				}
				x = 0;
				break;
			default:
				if (x == VGA_WIDTH - 1){
					if (y == VGA_HEIGHT - 1){
						for (int i = 0; i < VGA_HEIGHT - 1; i += 1){
							for (int j = 0; j < VGA_WIDTH; j += 1){
								buffer[j + VGA_WIDTH * i] = buffer[j + VGA_WIDTH * (i + 1)]; 
							}
						}
					}else{
						y += 1;
					}
					x=0;
				}
				buffer[x + VGA_WIDTH * y] = s[n] | (buffer[x + VGA_WIDTH * y] & 0xFF00);
		}
	*/
	buffer[x] = 0x4045;
	x = 1;
//	*((uint16_t *)0xB8000) = 0x4045;

	//if (((uint16_t* )0xB8000) == (uint16_t *)buffer){
//		*((uint16_t *)0xB8140) = 0x4045;
	//}
	//}


}

void print_int(int n);

void print_long(long n);

void print_float(float f);

void clear();
