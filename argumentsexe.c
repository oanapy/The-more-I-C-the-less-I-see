/*find out the arguments with which 
the main function was called in the terminal*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;

	if (argc == 1) {
		printf("You only have one argument.\n");
	} else if (argc > 1 && argc < 4){
		printf("Here's your arguments:\n");
			for (i = 0; i < argc; i++){
				printf("%s ", argv[i]);
			}
			printf("\n");
	} else {
		printf("You have too many arguments. You suck.\n");
	}
	return 0;
}
