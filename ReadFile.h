#pragma once

int GetCharacterCountInFile(char* fileDestination)
{
	FILE* f_code;

	f_code = fopen(fileDestination, "r");

	if(f_code == NULL)
	{
		printf("Error while opening file!\n");
		exit(-1);
	}
	int count = 0;
	char c;

	for (c = getc(f_code); c != EOF; c = getc(f_code))
        count = count + 1;

    fclose(f_code);

   	return count;
}

char* GetContents(char* fileDestination)
{
	FILE* f_code;

	f_code = fopen(fileDestination, "r");

	if(f_code == NULL)
	{
		printf("Error while opening file!\n");
		exit(-1);
	}

	int charactersInFile = GetCharacterCountInFile(fileDestination);

	char* buff = (char*)malloc(charactersInFile * sizeof(char) + 1);

	// read from file
	fread(buff, charactersInFile, 1, f_code);

	fclose(f_code);

	return buff;
}