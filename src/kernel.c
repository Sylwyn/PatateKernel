#include "../headers/output.h"
#include "../headers/types.h"

void patate_main(void){
	
	initialize_output();

	*((uint16_t *)0xB80A0) = 0x4047;
	*((uint16_t *)0xB809E) = 0x4047;
	*((uint16_t *)0xB80A2) = 0x4047;
	//print_string("UwU");
	print_string("a");
	//*((uint16_t *)0xB8140) = 0x4045;

	while(1){}
}
