#include "../headers/output.h"
#include "../headers/types.h"

void patate_main(void){
	
	initialize_output();

	*((uint16_t *)0xB80A0) = 0x4045;
	print_string("a");
	//print_string("UwU");
	*((uint16_t *)0xB8140) = 0x4045;

	while(1){}
}
