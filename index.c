#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void debugString(char* str){
	int i = 0;
	do
	{
		printf("character: %c, isTerminatingString: %s\n",str[i],str[i] == '\0' ? "true" : "false");
		i++;
	} while (str[i-1] != '\0');
	
	printf("side: %s, length: %d\n", str, strlen(str));
}
_Bool isVariable(char ch){
	return ch >= 97 && ch <=122;
}
_Bool isNumber(char ch){
	return ch >= 48 && ch <= 57;
}
void delEl(char* str, int index, int* size){
	for(int i = index; i < *size; i++){
		str[i] = str[i+1];
	}
	*size = *size - 1;
}
void flipSides(char *firstSide, int firstSize, char *secondSide, int secondSize){
	// for(int i = 0; i < secondSize;i++){
	// 	if(isVariable(secondSide[i])) firstSide[firstSize+i] = secondSide[i];
	// }
	printf("before %s\n",firstSide);
	for(int i = 0; i < firstSize; i++){
		if(isVariable(firstSide[i])) continue;
		switch (firstSide[i])
		{
		case '+':
		if(!isNumber(firstSide[i+1])){
			printf("error: invalid statement");
			_Exit(1);
		}
		printf("in +\n");
			delEl(firstSide, i, &firstSize);
			printf("%i",secondSize);
			secondSide[secondSize++] = '-';
			// i++;
			do
			{
				secondSide[secondSize++] = firstSide[i];
				delEl(firstSide, i, &firstSize);
			} while (isNumber(firstSide[i]));
		// debugString(secondSide);
		printf("out of +\n");
			break;
		case '-':
			delEl(firstSide, i, &firstSize);
			secondSide[secondSize+i] = '+';
			for(;firstSide[i+1] >= 48 && firstSide[i+1] <= 57;i++){
				secondSide[secondSize+i+1] = firstSide[i+1];
				delEl(firstSide, i+1, &firstSize);
			}
			break;
		default:
			break;
		}
	}
	printf("after %s\n",firstSide);
}
void removeSpaces(char *s){
	for(int i = 0; s[i] != 0; i++){
		int j = i;
		while(isspace(s[j])) j++;
		if(i == j) continue;
		for(int k = 0;s[j+k] != '\0'; k++) s[i+k] = s[j+k];
	}
}
int main(int argc, char *argv[]){
	char sides[2][100];
	int sizes[2];
	char equation[100];
	char copy[100];
	// char firstX;
	// char secondX;
	if(argc < 2){
		printf("Type your equation and hit enter\n");
		scanf("%s",equation);
	}
	else strcpy(equation, argv[1]);
	strcpy(sides[0],strtok(equation,"="));
	strcpy(sides[1], strtok(NULL,"="));
	// debugString(sides[0]);
	// debugString(sides[1]);
	removeSpaces(sides[0]);
	removeSpaces(sides[1]);
	sizes[0] = strlen(sides[0]);
	sizes[1] = strlen(sides[1]);
	flipSides(sides[0], sizes[0], sides[1], sizes[1]);
	// debugString(sides[0]);
	// debugString(sides[1]);
	printf("first %s \n",sides[0]);
	printf("second %s\n",sides[1]);
	
	// if(findVariable(sides[0], sizes[0])){

	// }
	return 0;
}
