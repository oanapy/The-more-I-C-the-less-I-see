#include <stdio.h>
#include <string.h>

void main(int argc, char *argv[]){
	//char array[][7] = {"first","second","third","fourth","fifth"};
	int length;
	int lengtha;
	length = 0;

	for(int i = 0; i < argc; i++) {
		lengtha = strlen(argv[i]);
		
		length += lengtha;

	printf("the %d-th element is %s\n",i, argv[i]);
	}

	
printf("the length of the whole array without the ending character is: %d\n", length);
}

