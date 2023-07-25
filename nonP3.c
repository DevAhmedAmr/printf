#include "main.h"


int nonPrintAscii(va_list arg) {
	int i, j, byets;
	char* upStr;
HexChar hexCharA[] = {
    {0, "00"}, {1, "01"}, {2, "02"}, {3, "03"}, {4, "04"},
    {5, "05"}, {6, "06"}, {7, "07"}, {8, "08"}, {9, "09"},
    {10, "0A"}, {11, "0B"}, {12, "0C"}, {13, "0D"}, {14, "0E"}, {15, "0F"},
    {16, "10"}, {17, "11"}, {18, "12"}, {19, "13"}, {20, "14"},
    {21, "15"}, {22, "16"}, {23, "17"}, {24, "18"}, {25, "19"},
    {26, "1A"}, {27, "1B"}, {28, "1C"}, {29, "1D"}, {30, "1E"},
    {31, "1F"}, {32, "20"}, {127, "7F"}
};
upStr = va_arg(arg, char*);
	if (upStr == NULL)
		upStr = "(null)";
	for (i = 0; upStr[i] !='\0'; i++) {
		if ((upStr[i] > 0 && upStr[i] < 32) || upStr[i] >= 127) {
			_putchar('\\');
			_putchar('x');
			byets += 2;
			for (j = 0; j <= 15; j++) {
				if (upStr[i] == hexCharA[j].N) {
					_putchar(hexCharA[j].C[0]);
					_putchar(hexCharA[j].C[1]);
					byets+=2;
					break;
				}
			}
		} else {
			_putchar(upStr[i]);
			byets++;
		}
		fflush(stdout);
	}
	return (byets);
}
