#include <stdio.h>

// function prototype no.1
int most_freq_letter(char *file, char *op);

int main() {
    
    char menu; //initialing the input from the user
    //menu for user to choose which option they want to pick
    printf("Enter 'a' for caesar cipher encryption\nEnter 'b' for caesar cipher decryption\nEnter 'c' for caesar cipher decryption without a key\n");
    scanf("%c", &menu); //readng the input from the user on which option they want
    
    if(menu == 'a'){//if the user enters 'a', this section of code will run
    
        int key;// initialising the key entered by the user
        printf("Enter key ");
        scanf("%d", &key); 
        
        FILE *input;//creating a pointer to the file input
    
        input = fopen("input.txt", "r"); //opening the file 'input.txt'
    
        while(feof(input) == 0){//while loop to read each character separately in the file
            char c; //initialising the imput from the file
            fscanf(input, "%c", &c);//reading each charater in file
       
        
       
      
            if(c > 96 && c < 123){
                c = c - 32; //converts all lowercase inputs into upercase inputs
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
    
        printf("Enter key ");
        scanf("%d", &key);
    
    

        FILE *input;


    
        input = fopen("input.txt", "r"); //opening the file input
    
        while(feof(input) == 0){
        char c; //initialising the imput from the user
        fscanf(input, "%c", &c);
        
        
      
            if(c > 96 && c < 123){
                c = c - 32; //converts all lowercase imputs into upercase inputs
            }
            if(c > 64 && c < 91){
                c = c + key; //roatates the ascii code of each character up by entered key
                if(c > 90){
                    c = c - 26;
                }
            }
                printf("%c", c);
        }
   }
   if(menu == 'c'){
       
    int ret = 0;//declaring the most frequent letter with a numer between 0 and 25
    int freq = 0;//declaring ascii value of the most frequent letter
    int key = 0;//declaring the key for the rotation cipher
    char x;//declaring the input from the user
    
    ret = most_freq_letter("input.txt", "r");//calling fuction no.1

    
    freq = ret + 65;//makes most common value an ascii character
   
    printf("Enter a letter to substitute for decryption: ");//enter letter in order of commonality
    scanf("%c", &x);
    
    if(x > 96 && x < 123){
        x = x - 32;//convert input from user to capital letters 
    }   
    
    key = freq - x;
    key = 26 - key;//gets the value for the decription key
     if(key > 25){
        key = key - 26;
    }
    if(key < 0){
        key = 0 - key;
    }
   
    
    printf("freq = '%d'\n", freq); 
    printf("key is %d\n", key);
    
    FILE *input;
    input = fopen("input.txt", "r"); //opening the file input
    
        while(feof(input) == 0){
        char c; //initialising the input from the user
        fscanf(input, "%c", &c);//scan input from file
        
        
      
            if(c > 96 && c < 123){
                c = c - 32; //converts all lowercase inputs into uppercase inputs
            }
            if(c > 64 && c < 91){
                c = c + key; //roatates the ascii code of each character up by entered key
                if(c > 90){
                    c = c - 26;//moves letters to the front that fall off the back
                }
            }
                printf("%c", c);
        }
    }

    return 0;
    
}
   

int most_freq_letter(char *file, char *op) {
   
    int letter[25];
    int count;
    for(count = 0; count < 26; count ++){    //initialise array  
        letter[count] = 0;
    }

    FILE *input;

    input = fopen(file, op); //opening the file input
        
    char c = 0; //initialise the input from the user
    int a = 0; //initialise array variable index
    
    while(feof(input) == 0){        //parse input text by incrementing
                                    //each letter on each occurrence
        fscanf(input, "%c", &c);
        if(c > 96 && c < 123){
            c = c - 32;
        }
        if(c > 64 && c < 91){
            c = c - 65;
            a = c; //move char type into an int type
            letter[a]++; //increment count of this letter
        }
    
    
    
    }
        
    int max = 0;//intitialise index for most frequent letter
    
    for(count = 1; count < 26; count++){//loop through all 26 uppercase letter
        if(letter[max] < letter[count]){//test current max against next letter
            max = count;//if condition is true, current letter is new max frequency
        }
    }
    
return max;
}