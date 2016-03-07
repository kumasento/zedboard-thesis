// parameters for the current design
#include "xparameters.h"
// libraries for handling GPIO operations
#include "xgpio.h"

int main() {
	// GPIO driver instances
	XGpio dip, push;
	int i, psb_check, dip_check;

	// printf utilities for embedded system?
	xil_printf("-- Start of the program --\r\n");

	// Use sw_8bit device to initialize dip
	XGpio_Initialize(&dip, XPAR_SW_8BIT_DEVICE_ID);
	// select one channel and set bit mask
	XGpio_SetDataDirection(&dip, 1, 0xffffffff);

	// So for btns_5bit
	XGpio_Initialize(&push, XPAR_BTNS_5BIT_DEVICE_ID);
	XGpio_SetDataDirection(&push, 1, 0xffffffff);

	while (1) {
		// what is discrete read
		psb_check = XGpio_DiscreteRead(&push, 1);
		xil_printf("Push buttons status %x\r\n", psb_check);
		dip_check = XGpio_DiscreteRead(&dip, 1);
		xil_printf("DIP switch status %x\r\n", dip_check);

		for (i = 0; i < 99999999; i++)
			;
	}

	return 0;
}

