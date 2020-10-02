//Scaueru Eduard 313CD

#include <stdio.h>

		unsigned int CONVERSION_IP_TO_INT(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
	unsigned int aux;

	aux = 0;
	aux = aux | (a << 24) | (b << 16) | (c << 8) | d;

	return aux;
}

void IP_PRINT_10(unsigned int IP)
{
	unsigned int i, ok = 0;
	unsigned char byte = 0, k;

	k = 7;

	for(i = 1 << 31; i > 0; i = i / 2)
	{
		ok++;
		if(IP & i)
		{
			byte = byte | (1 << k);
		}

		k--;

		if(ok % 8 == 0 && ok != 32)
		{
			printf("%hhu.", byte);

			byte = 0;
			k = 7;
		}
		if(ok == 32)
		{
			printf("%hhu", byte);
		}
	}
}

void IP_PRINT_8(unsigned int IP)
{
	unsigned int i, ok = 0;
	unsigned char byte = 0, k;

	k = 7;

	for(i = 1 << 31; i > 0; i = i / 2)
	{
		ok++;
		if(IP & i)
		{
			byte = byte | (1 << k);
		}

		k--;

		if(ok % 8 == 0 && ok != 32)
		{
			printf("%o.", byte);

			byte = 0;
			k = 7;
		}
		if(ok == 32)
		{
			printf("%o", byte);
		}
	}
}

void IP_PRINT_16(unsigned int IP)
{
	unsigned int i, ok = 0;
	unsigned char byte = 0, k;

	k = 7;

	for(i = 1 << 31; i > 0; i = i / 2)
	{
		ok++;
		if(IP & i)
		{
			byte = byte | (1 << k);
		}

		k--;

		if(ok % 8 == 0 && ok != 32)
		{
			printf("%X.", byte);

			byte = 0;
			k = 7;
		}
		if(ok == 32)
		{
			printf("%X", byte);
		}
	}
}

unsigned int CONVERSION_INT_TO_MASK(int mask)
{
	unsigned int x = 0;
	int i;

	for(i = 31; i > 31 - mask; i--)
	{
		x = x | (1 << i);
	}

	return x;
}

void task_0(unsigned int IP_1, unsigned int MASK_2)
{
	printf("-0 ");
	IP_PRINT_10(IP_1);
	printf("/%u\n", MASK_2);
}

void task_1(unsigned int mask)
{
	printf("-1 ");
	IP_PRINT_10(CONVERSION_INT_TO_MASK(mask));
	printf("\n");
}

void task_2(unsigned int MASK_1)
{
	printf("-2 ");
	IP_PRINT_8(MASK_1);
	printf(" ");
	IP_PRINT_16(MASK_1);
	printf("\n");
}

void task_3(unsigned int IP_1, unsigned int MASK_2)
{
	unsigned int IP;

	IP = IP_1 & CONVERSION_INT_TO_MASK(MASK_2);
	printf("-3 ");
	IP_PRINT_10(IP);
	printf("\n");
}

void task_4(unsigned int IP_1, unsigned int MASK_2)
{
	unsigned int IP;

	IP = IP_1 | ~(CONVERSION_INT_TO_MASK(MASK_2));
	printf("-4 ");
	IP_PRINT_10(IP);
	printf("\n");
}

void task_5(unsigned int IP_1, unsigned int IP_2, unsigned int MASK_2)
{
	if((IP_1 & CONVERSION_INT_TO_MASK(MASK_2)) == (IP_2 & CONVERSION_INT_TO_MASK(MASK_2)))
	{
		printf("-5 DA\n");
	}
	else
	{
		printf("-5 NU\n");
	}
}

void task_6(unsigned int MASK_1)
{
	unsigned int x, msk = 0, y;
	int i, j, poz_bit, ok = 0;

	x = MASK_1;

	for(i = 31; i >= 0; i--)
	{
		msk = 0;
		msk = 1 << i;
		if((msk & x) != msk)
		{
			poz_bit = i;
			ok = 1;
		}
		else
		{
			if(ok == 1)
			{
				printf("-6 NU\n");

				ok = 2;
				y = MASK_1;

				for(j = poz_bit - 1; j >= 0; j--)
				{
					y = y & (~(1<<j));
				}
				printf("-7 ");
				IP_PRINT_10(y);
				printf("\n");
				break;
			}
		}
	}

	if(ok == 1)
	{
		printf("-6 DA\n");
		printf("-7 ");
		IP_PRINT_10(MASK_1);
		printf("\n");
	}
}

void task_8(unsigned int IP_1)
{
	unsigned int x, i, ok = 0;

	x = IP_1;

	printf("-8 ");

	for(i = 1 << 31; i > 0; i = i / 2)
	{
		ok++;
		if(x & i)
		{
			printf("1");
		}
		else
		{	
			printf("0");
		}
		if(ok % 8 == 0 && ok != 32)
		{
			printf(".");
		}
	}

	printf("\n");
}

void task_9(unsigned int IP_2, unsigned int ADRESE_RETEA[], unsigned int MASK[], int N)
{
	int i;
	unsigned int x, network_1, network_2;

	printf("-9 ");

	for(i = 0; i < N; i++)
	{
		x = CONVERSION_INT_TO_MASK(MASK[i]);
		network_1 = IP_2 & x;
		network_2 = ADRESE_RETEA[i] & x;

		if(network_1 == network_2)
		{
			printf("%d ", i);
		}
	}

	printf("\n");
	
}

int main()
{
	unsigned char a, b, c, d;
	unsigned int MASK_2, MASK_1, IP_1, IP_2, ADRESE_RETEA[1004], MASK[1004];
	int t, N, i, mask;

	scanf("%d", &t);

	while(t)
	{
		scanf("%hhu.%hhu.%hhu.%hhu", &a, &b, &c, &d);		
		MASK_1 = CONVERSION_IP_TO_INT(a, b, c, d);
		scanf("%u", &MASK_2);
		scanf("%hhu.%hhu.%hhu.%hhu", &a, &b, &c, &d);
		IP_1 = CONVERSION_IP_TO_INT(a, b, c, d);
		scanf("%hhu.%hhu.%hhu.%hhu", &a, &b, &c, &d);
		IP_2 = CONVERSION_IP_TO_INT(a, b, c, d);
		scanf("%d", &N);
		
		for(i=0;i<N;i++)
		{
			
			scanf("%hhu.%hhu.%hhu.%hhu/%d", &a, &b, &c, &d, &mask);

			ADRESE_RETEA[i] = CONVERSION_IP_TO_INT(a, b, c, d);
			MASK[i] = mask;
		}

		printf("%d\n", t);

		task_0(IP_1, MASK_2);
		task_1(MASK_2);
		task_2(MASK_1);
		task_3(IP_1, MASK_2);
		task_4(IP_1, MASK_2);
		task_5(IP_1, IP_2, MASK_2);
		task_6(MASK_1);
		//task_7 este inclus in task_6 pentru a evita utilizarea variabilelor globale		
		task_8(IP_1);
		task_9(IP_2, ADRESE_RETEA, MASK, N);

		t--;
	}

	return 0;
}