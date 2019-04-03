#include <stdio.h>

int main() {
    char a; //initialising the imput from the user
    
    printf("text to encrypt: ");
    scanf("%s", &a);
    
    if(a > 97){
    a = a-32; //converts all lowercase imputs into upercase imputs
    }

    printf("read: %c\n", a);

   
    
    return 0;
}
