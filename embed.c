#include "header.h"
#include <stdint.h>

//configures the xadc to sample the given channel
void xadc_select_ch(uint32_t ch, uint32_t inp)
{
	uint32_t reg_temp;
	//mask to only get 5 bits
	ch&=0x1F;
	reg_temp = XADC_CTL;
	//set [4:0] to the channel bits given
	reg_temp &= 0xFFE0;
	reg_temp |= ch;
	XADC_CTL = reg_temp;

	int i=0;
	int j=0;
	uint32_t temp=0;
    //set display enabled in standard (hex) mode
	SEG_CTL = 1;

	for(i=0;i<4;i++)
	{
	    temp |= (inp&0xF)<<(i*8); //put digit data in appropriate bitfield
		inp>>=4; //shift out least significant digit
	}
	for(j=3;j<=5;j++)
			RGB_EN(j) = 1; //enable RGB LED 1 Channels G and B)

	// RGB_PERIOD(0) = 256; // original 256
	RGB_PERIOD(3) = 5; // 4  //5
	RGB_PERIOD(4) = 4; // 12 //4
	RGB_PERIOD(5) = 4; // 22 //4

	//set the pulse width half of each window
	// RGB_WIDTH(0) = temp; // used to be temp here
	RGB_WIDTH(3) = temp<<7; // temp
	RGB_WIDTH(4) = temp<<6; // 4, new config 5
	RGB_WIDTH(5) = temp<<5; // 5, new config 15
	/*
	//set the window for each channel double of the last
	RGB_PERIOD(0) = 256; // original 256
	RGB_PERIOD(1) = 512;
	RGB_PERIOD(3) = 1024;
	RGB_PERIOD(4) = 2056;

	//set the pulse width half of each window
	RGB_WIDTH(0) = temp; // used to be temp here
	RGB_WIDTH(1) = temp/2;
	RGB_WIDTH(3) = temp/4;
	RGB_WIDTH(4) = temp/8;
	// LED_DATA = inp&0xF;
	*/

	//disable all decimal points
	temp|=0x80808080;
	SEG_DATA = temp;
}


// sort of translates
int main(void){
	for(;;) {
		LED_DATA = pot_register&0xFFF;
		xadc_select_ch(3, pot_register&0xF000); // displayed number correctly on the left
	}
    return 1;
}


/*
int main(void)
{
	LED_DATA = 0b1001; // defined binary value
	for(;;);
	return 1;
}
*/

