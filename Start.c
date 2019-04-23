#include <stdio.h>

int main() {
    
    char menu; //initialing the input from the user
    //menu for user to choose which option they want to pick
    printf("enter 'a' for caesar cipher encryption\nenter 'b' for caesar cipher decryption\n");
    scanf("%c", &menu); //readng the input from the user on which option they want
    
    if(menu == 'a'){//if the user enters 'a', this section of code will run
    
        int key;// initialising the key entered by the user
        printf("enter key ", key);
        scanf("%d", &key); 
        
        FILE *input;//creating a pointer to the file input
    
        input = fopen("input.txt", "r"); //opening the file 'input.txt'
    
        while(feof(input) == 0){//while loop to read each character separately in the file
            char c; //initialising the imput from the file
            fscanf(input, "%c", &c);//reading each charater in file
       
        
       
      
            if(c > 96){
                c = c - 32; //converts all lowercase imputs into upercase imputs
            }
            if(c > 64 && c < 91){
                c = c - key; //roatates the ascii code of each character down by the given key
                if(c < 65){
                    c = c + 26;//all characters the go bellow 'A' get pushed back to the end of the alphabet
                }
            }
            
            printf("%c", c); //printing the result of each character rotation after each loop
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
