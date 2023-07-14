#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char ** argv){
	if (argc == 3){
		FILE * a = fopen(argv[1],"r");
		FILE * b = fopen(argv[2],"r");
		if (!a)
			exit(-1);
		if (!b)
			exit(-1);
		uint32_t num1;
		uint32_t num2;       
		fread(&num1, 4,1, a);
		fread(&num2, 4,1, b);
		num1 = ntohl(num1);
		num2 = ntohl(num2);
		uint32_t res = num1 + num2;
		printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1,num1,num2,num2,res,res);
		fclose(a);
		fclose(b);
	}
	else{
		puts("Usage : add-nbo <file1> <file2>");
	}
	return 0;
}
