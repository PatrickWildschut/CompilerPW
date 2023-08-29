#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// enable and disable debugging
#ifndef ANYTHING
#define DEBUG(s1, s2) printf(s1, s2);
#else
#define DEBUG(s1, s2)
#endif

#include "ReadFile.h"
#include "ProcessFile.h"
#include "Assembly.h"

int main(int argc, char* argv[])
{
	char* Contents = GetContents(argv[1]);

	Token* tokens = Tokenize(Contents);

	Instruction* instructions = Instructionize(tokens);

	char* Assembly = MakeAssembly(instructions);

	//printf("Assembly:\n%s\n", Assembly);

	// save to .o file
	// FILE* f_write;

	// f_write = fopen("./assembly.o", "w");

	// fprintf(f_write, "%s\n", Assembly);
	
	return 0;
}