#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <errno.h>

typedef struct {
	long left;
	unsigned short right;
} Fixed_format; 


void print_byte_as_bits(char val) {
  for (int i = 7; 0 <= i; i--) {
    printf("%c", (val & (1 << i)) ? '1' : '0');
  }
}

void print_bits(char * ty, char * val, unsigned char * bytes, size_t num_bytes) {
  printf("(%*s) %*s = [ ", 15, ty, 16, val);
  for (size_t i = 0; i < num_bytes; i++) {
    print_byte_as_bits(bytes[i]);
    printf(" ");
  }
  printf("]\n");
}

#define SHOW(T,V) do { T x = V; print_bits(#T, #V, (unsigned char*) &x, sizeof(x)); } while(0)

int main() {
	Fixed_format fixed_format;
	fixed_format.left = 16;
	fixed_format.right = 1;
	printf("Float should be: %d.%d\n", fixed_format.left, fixed_format.right);

	SHOW(long, fixed_format.left);
	SHOW(unsigned short, fixed_format.right);
	int i = 0;
	SHOW(float, 2.0);
	SHOW(float, 2.1);
	SHOW(float, 1.0);
	SHOW(float, 1.1);
	for (i = 0; i < 10; i++) {
		SHOW(float, (float)i + 0.1);
	}

	return 0;
}