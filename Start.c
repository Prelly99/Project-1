#include <stdio.h>

int main() {
    
    char menu;
    printf("enter 'a' for ceaser cipher encription\nenter 'b' for ceaser cipher decription\n");
    scanf("%c", &menu);
    
    if(menu == 'a'){
    
        int key;
        printf("enter key ", key);
        scanf("%d", &key); 
        
        FILE *input;
    
        input = fopen("input.txt", "r"); //opening the file 'input.txt'
    
        while(feof(input) == 0){
            char c; //initialising the imput from the user
            fscanf(input, "%c", &c);
       
        
       
      
            if(c > 96){
                c = c - 32; //converts all lowercase imputs into upercase imputs
            }
            if(c > 64 && c < 91){
                c = c - key; //roatates the ascii code of each character down by 1
                if(c < 65){
                    c = c + 26;
                }
            }
            
            printf("%c", c);
        }
        
   }
   if(menu == 'b'){
       
       int key;
    
        printf("enter key ", key);
        scanf("%d", &key);
    
    

        FILE *input;


    
        input = fopen("input.txt", "r"); //opening the file input
    
        while(feof(input) == 0){
        char c; //initialising the imput from the user
        fscanf(input, "%c", &c);
        
        
      
            if(c > 96){
                c = c - 32; //converts all lowercase imputs into upercase inputs
            }
            if(c > 64 && c < 91){
                c = c + key; //roatates the ascii code of each character down by entered key
                if(c > 90){
                    c = c - 26;
                }
            }
                printf("%c", c);
        }
   }
    
    return 0;
    
}
