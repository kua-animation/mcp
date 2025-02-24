#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MCP 256

int D[30000];
int Index = 0;

int initilaz(int j, char C[MCP]);

int ride(char C[MCP]);

int main() {
	char N[MCP];
	
	char *file_name = malloc(100);

	int repid;

	printf("set the file name: ");

	scanf("%s", file_name);

	FILE *file;
	file = fopen(file_name, "r");

	if (!file) {
		printf("\n\tno file\n");
		fflush(stdout);
		exit(EXIT_FAILURE);
	}

	while (fgets(N, sizeof(N), file)) {
		int B = ride(N);
		
		if (B <= -1) {
			fclose(file);
			printf("\n\tsyntex error %d\n", B);
			exit(EXIT_FAILURE);
		}

	}

	fclose(file);

	return 0;
}

int ride(char C[MCP]) {

	for (int j = 0; j < strlen(C)+1; j++) {
		if (C[j] == ':') {
			if (C[j+2] == ' ' && j+2 < strlen(C)){
			if (initilaz(j, C) != 0) {
				return initilaz(j,C);
			}
			} else if ( C[j+2] != ' ' && j+3 < strlen(C)){
				return -3;
			}
			else if (C[j+1] == 'O') {
				printf("%c", (char)(D[Index]));
				fflush(stdout);
				Index++;
				return 0;
			}
		}
	}	
	return -2;
}

int initilaz(int j, char C[MCP]) {
	switch (C[j+1]) {
		case 'I':
			D[Index] += 1;
		break;
		case ')':
			D[Index] += 5;
		break;
		case ']':
			D[Index] += 10;
		break;
		case '/':
			D[Index] -= 1;
		break;
		case '(':
			D[Index] -= 5;
		break;
		case '[':
			D[Index] -= 5;
		break;
		case '|':
			usleep(100000);
		break;
		case '<':
			Index--;
		break;
		case '>':
			Index++;
		break;
		case 'O':
			return 0;
		break;
		default:
			return -1;
		break;
	}
	return 0;
}
