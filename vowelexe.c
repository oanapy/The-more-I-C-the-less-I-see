#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2) 
    {
        printf("Error! You need ome argument! \n");
        
        return 1;
        
    }
    int i;
    for (i = 0; argv[1][i] != '\0'; i++)
    {
        char letter = argv[1][i];
        
        switch (letter) 
        {
            case 'a':
            case 'A':
                printf("case %d: 'A'\n", i);
                break;
                
            case 'e':
            case 'E':
                printf("case %d: 'E'\n", i);
                break;
                
            case 'i':
            case 'I':
                printf("case %d: 'I'\n", i);
                break;
                
            case 'o':
            case 'O':
                printf("case %d: 'O'\n", i);
                break;
                
            case 'u':
            case 'U':
                printf("case %d: 'U'\n", i);
                break;
                
            case 'y':
            case 'Y':
                if (i > 2) 
                {
                    printf("case %d: Y\n", i);
                }
                break;
                
            default: 
                printf("%d: %c is not a vowel\n", i, letter);           
        }
    }
    return 0;
}
