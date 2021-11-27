#include <stdio.h>
#include <string.h>
#include <ctype.h>
void flipSides(char *firstSide, int firstSize, char *secondSide, int secondSize){
	
}
char findVariable(char *a, int size){
	printf("%d",size);
	char ch;
	for(int i = 0; i < size; i++) if(a[i] >= 97 && a[i] <=122>
	return ch;
}
void removeSpaces(char *s){
	int size = *(&s + 1) - s;
	for(int i = 0; s[i] != 0; i++){
		int j = i;
		while(isspace(s[j])) j++;
		if(i == j) continue;
		for(int k = 0; j+k < size; k++) s[i+k] = s[j+k];
	}
}
int main(int argc, char *argv[]){
	char* sides[2];
	char equation[100];
	char copy[100];
	int sizes[2];
	// char firstX;
	// char secondX;
	if(argc < 2){
		printf("Type your equation and hit enter\n");
		scanf("%s",equation);
	}
	else strcpy(equation, argv[1]);
	strcpy(copy, equation);
	sides[0] = strtok(copy,"=");
	sides[1] = strtok(NULL,"=");
	removeSpaces(sides[0]);
	removeSpaces(sides[1]);
	sizes[0] = *(&sides[0] + 1) - sides[0];
	sizes[1] = *(&sides[1] + 1) - sides[1];
	if()
}
