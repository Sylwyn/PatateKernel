
void patate_main(void){
	*((int *)0xB8000) = 0x0400;
	while(1){}
}
