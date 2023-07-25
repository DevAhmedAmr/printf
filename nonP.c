int nonPrintAscii(char *upStr)
{

	int i, j, byets;
	if (upStr == NULL)
		upStr = "(null)";
	for (i = 0; upStr[i] !='\0'; i++)
	{
		if((upStr[i] > 0 && upStr[i] < 32) || upStr[i] >= 127)
			{
				putchar('\\');
				putchar('x');
				putchar('0');
				byets+=3;

					if (upStr[i] >0 && upStr[i] <= 15)
					{
						putchar( 'A' + (upStr[i] - 10));
						byets++;
					}


			}
		else
			{
			putchar(upStr[i]);
			byets++;
			}
			fflush(stdout);

	}
	return (byets);
}
