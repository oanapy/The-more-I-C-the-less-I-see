//chestii cu sizeof 

int main(void) {
    printf("Pe acest calculator avem:\n");
    printf("%d bytes pentru char \n",sizeof(char));
    printf("%d bytes pentru short \n",sizeof(short int));
    printf("%d bytes pentru int \n",sizeof(int));
    printf("%d bytes pentru long \n",sizeof(long int));
    printf("%d bytes pentru long long \n",sizeof(long long int));
    printf("%d bytes pentru float \n",sizeof(float));
    printf("%d bytes pentru double \n",sizeof(double));
    printf("%d bytes pentru pointeri \n",sizeof(int *));
    return 0;
}