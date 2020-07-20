#include <stdio.h>
#include <netinet/in.h>
#include <stdint.h> // for uint8_t

int main(int argc, char* argv[]){

	FILE *fp1 = fopen(argv[1], "rb");
	FILE *fp2 = fopen(argv[2], "rb");

	uint32_t a,b;
	uint32_t sum = 0;

	fread(&a, sizeof(uint32_t), 1, fp1);
	fread(&b, sizeof(uint32_t), 1, fp2);

	a = htonl(a);
	b = htonl(b);

	sum = a + b;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, sum, sum);

	fclose(fp1);
	fclose(fp2);

	return 0;
}