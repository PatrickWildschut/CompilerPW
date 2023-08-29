#define atoa(x) #x

// char* makeSyscall(Instruction instruction)
// {
// 	char newline = '\n';
// 	char* buff = (char*)malloc(100 * sizeof(char));

// 	// set rax
// 	strcat(buff, "mov $rax, ");
// 	char rax_string[4];
// 	sprintf(rax_string, "%d", (int)instruction.tokens[0].tokenType);
// 	strcat(buff, rax_string);

// 	// int i = 1;
// 	// while(instruction.tokens[i])
// 	// {
// 	// 	if(i == 1)
// 	// 	{

// 	// 	}

// 	// 	i++;
// 	// }

// 	strcat(buff, "\n\t");

// 	return buff;
// }

char* MakeAssembly(Instruction* instructions)
{
	char* buff = (char*)malloc(25 * sizeof(char));
	//strcpy(buff, "global .start\n.start:\n\t");
	//unsigned int size = strlen(buff);

	// for(int i = 0; i < 5; i++)
	// {
	// 	char* syscall = makeSyscall(instructions[i]);
	// 	size += strlen(syscall);
	// 	buff = realloc(buff, size * sizeof(char));

	// 	strcat(buff, syscall);
	// }

	return buff;
}