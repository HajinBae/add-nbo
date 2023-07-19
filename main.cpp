#include <stdio.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t open_bin(uint8_t *arr, FILE *fp) {
	fread(arr, sizeof(char), 4, fp);
        uint32_t* p = reinterpret_cast<uint32_t*>(arr);
        uint32_t n = ntohl(*p);
	return n;
}

void print_binsum(uint32_t a, uint32_t b) {
	uint32_t result = a + b;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, result, result);
}


int main(int argc, char* argv[]) {
	FILE *f1, *f2;
	uint8_t arr1[4];
	uint8_t arr2[4];

	if (argc != 3) {
		printf("usage: ./add-nbo <file1> <file2>\n");
		exit(-1);
	}

	if ((f1 = fopen(argv[1], "rb")) == NULL) {
		perror("argv[1] open error\n");
		exit(-1);
	}

	if ((f2 = fopen(argv[2], "rb")) == NULL) {
                perror("argv[2] open error\n");
		exit(-1);
        }
	
	print_binsum(open_bin(arr1, f1), open_bin(arr2, f2));

	fclose(f1);
	fclose(f2);
}
