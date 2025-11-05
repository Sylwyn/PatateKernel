#include "../headers/output.h"
#include "../headers/types.h"

#define VGA_MEMORY  0xB8000
#define VGA_WIDTH   80
#define VGA_HEIGHT  25

static uint8_t x;
static uint8_t y;

void initialize_output(){
	x = 1;
	y = 1;
}

void print_char(char c){
	uint16_t *buffer = (uint16_t *) 0xB8000;

	buffer[VGA_WIDTH * y + x] = (buffer[VGA_WIDTH * y + x] & 0xFF00) | c;
	//buffer[166] = (buffer[166] & 0xFF00) | c;
}

void print_string(char * s){
	
	uint16_t *buffer = (uint16_t *) 0xB8000;
	//buffer[2] = 0x4047 ;
	//return ;
	//buffer[84] = 0x4047 ;
	//buffer[2] = 0x4047 ;
	

	int n = 0;

	/*if (s[n] ==  '\0')
		buffer[162] = 0x4047; // G
	else if (s[n] == 'a' ){
		buffer[162] = 0x4048; // H
		buffer[166] = (buffer[166] & 0xFF00) | s[0];
	}
	else if (s[n] == 'n' ){
		buffer[162] = 0x4049; // I
		buffer[166] = (buffer[166] & 0xFF00) | s[0];
	}
	else {
	        buffer[162] = 0x4046; // F 	
		//buffer[165] = (buffer[165] & 0xFF00) | s[n];
		//buffer[166] = (buffer[166] & 0xFF00) | 'a';
		buffer[164] = (buffer[164] & 0xFF00) | s[n];
	}
	return;*/
	while (s[n] != '\0'){
		switch(s[n]){
			/*case '\n':
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
				buffer[4] = 0x4045;
				break;*/
			default:
				/*if (x == VGA_WIDTH - 1){
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
					//buffer[2] = 0x4047;
				}*/
				//buffer[x + VGA_WIDTH * y] = s[n] | (buffer[x + VGA_WIDTH * y] & 0xFF00);
				buffer[n] = 0x4047;
				print_char(s[n]);
		}
	}
}

void print_int(int n);

void print_long(long n);

void print_float(float f);

void clear();
