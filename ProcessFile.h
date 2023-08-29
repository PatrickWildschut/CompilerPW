typedef enum TokenType
{
	ret = 60, val = 420, semi = 421
} TokenType;

typedef struct Token
{
	char* value;
	TokenType tokenType;

} Token;

typedef struct Instruction
{
	Token tokens[7];
} Instruction;

void freeBuff(char* buff, int* index)
{	
	for(int i = 0; i < *index; i++)
	{
		buff[i] = '\0';
	}

	*index = 0;
}

void removeSpaces(char* buff, int* index)
{
	for(int i = *index; i >= 0; i--)
	{
		if(isspace(buff[i]))
		{
			buff[i] = '\0';
			*index -= 1;
		}
	}
}

enum TokenType GetTokenType(char* name)
{
	if(strcmp(name, "return") == 0)
	{
		DEBUG("%s is return.\n", name);

		return ret;
	}
	else if(isdigit(*name))
	{
		DEBUG("%s is digit.\n", name);

		return val;
	}
	else if(strcmp(name, ";") == 0)
	{
		DEBUG("%s is semi.\n", name);

		return semi;
	}

	DEBUG("%s is not defined.\n", name);

	return -1;
}

void AddToken(Token* tokens, int* tokenIndex, char* buff, int* buffIndex)
{
	removeSpaces(buff, buffIndex);

	if(*buffIndex <= 0)
		return;

	// tokens[*tokenIndex].value = (char*)malloc(10 * sizeof(char));

	// strncpy(tokens[*tokenIndex].value, buff, 10);	
	tokens[*tokenIndex].tokenType = GetTokenType(buff);

	(*tokenIndex)++;
	tokens = (Token*)realloc(tokens, *tokenIndex * 14);

	freeBuff(buff, buffIndex);
}

Token* Tokenize(char* fileContents)
{
	int* tokenIndex = (int*)malloc(sizeof(int));
	Token* tokens = (Token*)malloc(1 * 14);

	int* buffIndex = (int*)malloc(sizeof(int));
	char* buff = (char*)calloc(1, sizeof(char));
	int fileLen = strlen(fileContents);

	for(int i = 0; i < fileLen; i++)
	{
		// add current char to buffer
		buff[*buffIndex] = fileContents[i];
		(*buffIndex)++;
		buff = realloc(buff, (*buffIndex + 1) * sizeof(char));
		

		if(isspace(fileContents[i]))
		{
			AddToken(tokens, tokenIndex, 
					buff, buffIndex);
		}
		else if(fileContents[i] == ';')
		{
			// add everything before semi
			(*buffIndex)--;
			buff[*buffIndex] = '\0';
			
			AddToken(tokens, tokenIndex, 
					buff, buffIndex);

			// add semi
			freeBuff(buff, buffIndex);
			buff[0] = ';';
			(*buffIndex)++;
			AddToken(tokens, tokenIndex, 
					buff, buffIndex);
		}
	}

	//free(fileContents);
	free(buff);

	return tokens;
}

Instruction* Instructionize(Token* tokens)
{
	// get total amount of instructions
	int amount = 0;
	for(int i = 0; i < sizeof(tokens); i++)
	{
		if(tokens[i].tokenType == 421)
			amount++;
	}

	DEBUG("\nAmount of instructions: %d\n", amount);

	Instruction* instructions = (Instruction*)malloc(amount * sizeof(Instruction));
	int curIn = 0;
	int curTok = 0;
	for(int i = 0; i < sizeof(tokens); i++)
	{
		if(tokens[i].tokenType == 421)
		{
			curIn++;
			curTok = 0;
		}
		else
		{
			instructions[curIn].tokens[curTok] = tokens[i];
			curTok++;
		}
	}

	//free(tokens);

	return instructions;

}