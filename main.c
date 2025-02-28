#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MCP 512

int D[30000];
int Index = 0;

int initilaz(int j, char C[MCP]);

int ride(char C[MCP], int isDebuge);

int main(int argc, char *argv[]) {
	char N[MCP];
	
	int repid;

	int isDebuge = 0;
	
	if (argc >= 3) {
		if (!strcmp("-g", argv[2])){
			isDebuge = 1;
		}
	}

	FILE *file;
	file = fopen(argv[1], "r");

	if (!file) {
		printf("\n\tno file\n");
		fflush(stdout);
		exit(EXIT_FAILURE);
	}

	while (fgets(N, sizeof(N), file)) {
		int B = ride(N, isDebuge);

		if (B <= -1) {
			fclose(file);
			printf("\n\tsyntex error %d\n", B);
			exit(EXIT_FAILURE);
		}

	}

	fclose(file);

	return 0;
}

int ride(char C[MCP], int isDebuge) {

	for (int j = 0; j < strlen(C)+1; j++) {
		if (C[j] == ':') {
			if (C[j+2] == ' ' && j+2 < strlen(C)){
			if (initilaz(j, C) != 0) {
				return initilaz(j,C);
			}
			} else if ( C[j+2] != ' ' && j+3 < strlen(C)){
				return -3;
			}
			if (C[j+1] == 'O') {
				if (isDebuge) {
					printf("cell %d :%c\n", Index, (char)(D[Index]));
					fflush(stdout);
				} else {
					printf("%c", (char)(D[Index]));
				}
			}
		}
		else if (C[j] == '@') {
			return 0;
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
		case 'D':
			D[Index] += 10;
		break;
		case 'l':
			D[Index] -= 1;
		break;
		case '(':
			D[Index] -= 5;
		break;
		case 'C':
			D[Index] -= 10;
		break;
		case ',':
			usleep(100000);
		break;
		case '<':
			Index--;
		break;
		case '>':
			Index++;
		break;
		case '[':
			Index-= 5;
		break;
		case ']':
			Index+= 5;
		break;
		case 'O':
			return 0;
		break;
		case 'J':
			D[Index+D[Index+1]] = D[Index-D[Index]];
		break;
		default:
			return -1;
		break;
	}
	return 0;
}
