#include <stdio.h>

int main() {
    
        
        FILE *input;
    
        input = fopen("input.txt", "r"); //opening the file input
    
        while(feof(input) == 0){
        char c; //initialising the imput from the user
        fscanf(input, "%c", &c);
       
        
       
      
            if(c > 96){
                c = c-32; //converts all lowercase imputs into upercase imputs
            }
            if(c > 65 && c < 91){
                c = c - 1; //roatates the ascii code of each character down by 1
            }
            else if(c == 65){
                c = c + 25;
            }
            printf("%c", c);
        }
        
   
    
    return 0;
    
}
