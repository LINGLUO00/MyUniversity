#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{

	float hl = 0.0;
	float sum = 0.0;
	int i = 0;
	while (i < 5)
	{
		scanf("%f", &hl);
		sum += hl;
		i++;
	}
	printf("%.2f", sum / 5);

	return 0;
}