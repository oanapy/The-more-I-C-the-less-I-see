#include <stdio.h>

//playful poointers 
//an array is a pointer!!!!

int main(int argc, char *argv[]) 
{
    /*create an array of ints - ages*/
    int ages[] = {23, 43, 12, 89};

    //printf("the address of the newly created pointer to ages is %p\n", agesptr);
    printf("the address of the newly created pointer to ages is %p\n\n", ages);

    /*create an array of strings in a variable of type pointer - names*/

    char *names[] = {"Alan", "Frank", "Mary", "Lisa"};

    /*prints the memory address of the pointer*/
    //printf("the memory address of names is %p\n", names);


    /*find out the length of the array by diving the total bytes of the array ages (16) to 
    the size of an int (4 bytes on most systems) --> useful to find out the length of an array*/
    int count = sizeof(ages)/sizeof(int);
    //printf("size of ages is %i\n", sizeof(ages));
    
    int i;
    
    for (i = 0; i < count; i++)
    {
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }
    
    printf("---\n");

    //creates two pointers, one that points to an array of type int and the other one
    //it points to a pointer, to names
    
    int *curent_age = ages;
    char **curent_name = names;
    
    for (i = 0;  i < count; i++) 
    {
        printf("%s is %d years old.\n", *(curent_name + i), *(curent_age + i));
    }
    
    printf("---\n");
    
    for (i=0; i<count; i++)
    {
        printf("%s is %d years old again.\n", curent_name[i], curent_age[i]);
    }
    
    printf("---\n");
    
    return 0;
}
