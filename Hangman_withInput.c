#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 20
void GameTitle(){
    printf("\n-----------------------");
    printf("\n|                     |");
    printf("\n|       HANGMAN       |");
    printf("\n|                     |");
    printf("\n-----------------------");

}
//Selects one of the given names, that has to be guessed
int SelectWord(){
    srand(time(NULL));
    int upper = 4;
    int lower = 0;
    int i = (rand() % (upper - lower + 1)) + lower;
    return i;
}
/* counts the length of the word
    plus also spaces in between those words*/
int WordLength(char *arr){
    int count = 0;
    char *pointer = arr;
    for(int i = 0; i < pointer[i] != 0; i++){
            count++;    
    }
    return count;
}
/* Takes a word and turns every char of the word 
    into a '-' */
void HiddenWord(char *arr){
    printf("\n");
    char *ptr = arr;
    for(int i = 0; i < WordLength(arr); i++){
        if(ptr[i] != ' '){
            printf(" - ");
        }else{
            printf("  ");
        } 
    }
    printf("\n");
}

void GuessingGameStart(){
    printf("\n\n");
    printf("\n-----------------------");
    printf("\n|                     |");
    printf("\n|     Guess the       |");
    printf("\n|     following       |");
    printf("\n|       word:         |");
    printf("\n|                     |");
    printf("\n-----------------------");
    printf("\n\n");
}
/* counts the same letters in a word
    such as London - SameChar = 1*/
int SameChars(char *arr, int length){
    int count = 0;
    //points to the first letter of the string
    /*
    int the example *arr = "Boston"
    char *ptr = arr;
    *ptr points to the B
    ptr[0] = 'B'
    */
    char *ptr = arr;
    char num[20];
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            if(ptr[i] == ptr[j] && i != j && ptr[i] != num[j]){
                count++;
                //saves the already checked letters
                num[i] = ptr[i];
        }
        }
    }
    if(ptr[0] == ptr[length-1]){
        count++;
    }
    return count;
}
/* Checks if the chosen letter is in the word or not and
    then returns back an array that fills it self up slowly
    if the letter was corret*/
char * Guessing(char guess, char *arr, char *reArr){
    char *ptr = arr;
    //First letter should always be capital 
    if(ptr[0] == guess || ptr[0] == (guess -32)){
                reArr[0] = guess - 32;
            }
    for(int i = 1; i < WordLength(arr); i++){
        if(ptr[i] == guess && ptr[i - 1] != ' '){
            reArr[i] = guess;
        }else if(ptr[i] == (guess - 32) && ptr[i - 1] == ' '){
            reArr[i] = guess - 32;
        }
        else if(reArr[i] != '-' && ptr[i] != ' '){
            reArr[i] = reArr[i];
        }else if(ptr[i] == ' ' || reArr[i] == ' '){
            reArr[i] = ' ';
        }else{
            reArr[i] = '-';
        }
    }
    return reArr;

}
/* counts the number of underscores in the array of 
    the Guessing function */
int CountUnderscore(char *arr){
    char *ptr = arr;
    int count = 0;
    for(int i = 0; i < WordLength(arr); i++){
        if(ptr[i] == '-'){
            count++;
        }
    }
    return count;
}

void win(){
    printf("\n");
    printf("\n-----------------------");
    printf("\n|                     |");
    printf("\n|      You Won!       |");
    printf("\n|                     |");
    printf("\n-----------------------");
    printf("\n");
}

void lost(){
    printf("\n");
    printf("\n-----------------------");
    printf("\n|                     |");
    printf("\n|      You Lost!      |");
    printf("\n|                     |");
    printf("\n-----------------------");
    printf("\n");
}
/* basically just a true or false function
    if the guess was correct and the letter
    does appear in the word then this function
    will return a number with the value 1, else
    with a value of 0 */
int GoodGuess(char guess, char * arr){
    char *ptr = arr;
    int reVal = 0;
    for(int i = 0; i < WordLength(arr); i++){
        if(ptr[i] == guess || ptr[i] == (guess - 32)){
            reVal = 1;
            return reVal;
        }else{
            reVal = 0;
        }
    }
    return reVal;
}
/* A function to make every word that will be input
    by the user look essentially the same - that means e.g.
    always capitalizing the word */
char * EqualDesign(char *arr){
    char * ptr = arr;
    int i = 1;
    if((ptr[0] >= 'a') && (ptr[0] <= 'z')){
            ptr[0] = ptr[0] - 32;
        }else{
            ptr[0] = ptr[0];
        }
    while(ptr[i] != 0){
        if(((ptr[i] >= 'a') && (ptr[i] <= 'z')) && ptr[i - 1] == ' '){
            ptr[i] = ptr[i] - 32;
        }else if(((ptr[i] >= 'A') && (ptr[i] <= 'Z')) && ptr[i - 1] != ' '){
            ptr[i] = ptr[i] + 32;
        }
        i++;
    }
}

void BuildTree(int life, char guess, char * arr){
    switch(life){
        case 4:
        if(GoodGuess(guess, arr) == 0){
            printf("\n");
             printf("\n-----------------------");
             printf("\n|       |------|       |");
             printf("\n|       0      |       |");
             printf("\n|              |       |");
             printf("\n|              |       |");
             printf("\n|              |       |");
             printf("\n-----------------------");
             printf("\n");
        }
        break;
        case 3:
        if(GoodGuess(guess, arr) == 0){
             printf("\n");
             printf("\n-----------------------");
             printf("\n|       |------|       |");
             printf("\n|       0      |       |");
             printf("\n|      \\|      |       |");
             printf("\n|              |       |");
             printf("\n|              |       |");
             printf("\n-----------------------");
             printf("\n");
        }
        break;
        case 2:
        if(GoodGuess(guess, arr) == 0){
             printf("\n");
             printf("\n-----------------------");
             printf("\n|       |------|       |");
             printf("\n|       0      |       |");
             printf("\n|      \\|/     |       |");
             printf("\n|              |       |");
             printf("\n|              |       |");
             printf("\n-----------------------");
             printf("\n");
        }
        break;
        case 1:
        if(GoodGuess(guess, arr) == 0){
             printf("\n");
             printf("\n-----------------------");
             printf("\n|       |------|       |");
             printf("\n|       0      |       |");
             printf("\n|      \\|/     |       |");
             printf("\n|      /       |       |");
             printf("\n|              |       |");
             printf("\n-----------------------");
             printf("\n");
             break;
        }
        case 0:
        if(GoodGuess(guess, arr) == 0){
            printf("\n");
             printf("\n-----------------------");
             printf("\n|       |------|       |");
             printf("\n|       0      |       |");
             printf("\n|      \\|/     |       |");
             printf("\n|      / \\     |       |");
             printf("\n|              |       |");
             printf("\n-----------------------");
             printf("\n");
            break;
        }  
}
/* Game if option: use random word is chosen */
}
void HangmanGame(){
   //allocating the memory for each word
   char * a = malloc(256);
   char * b = malloc(256);
   char * c = malloc(256);
   char * d = malloc(256);
   char * e = malloc(256);
   char * f = malloc(256);
   char * g = malloc(256);
   //copying the String to the variable in the array
   strcpy(a, "London");
   strcpy(b, "Boston");
   strcpy(c, "Munich");
   strcpy(d, "Berlin");
   strcpy(e, "New York City");
   strcpy(f, "New Hampshire");
   strcpy(g, "Sri Lanka");
   //array of words that can be randomly selected
   char *words[7] = {a, b, c, d, e, f, g};
   char *Selected[1];
   Selected[0] = words[SelectWord()];
   GuessingGameStart();
   HiddenWord(Selected[0]);
   /*Guessing part of the game*/
   int lifes = 5;
   char Guess;
   char *n;
   int p = WordLength(Selected[0]);
   char tempArr[p];
   //fill tempArr with '-':
  
   int length = WordLength(Selected[0]);
    for(int m = 0; m < length; m++){
       tempArr[m] = '-';
   }
   int same = SameChars(Selected[0], WordLength(Selected[0]));
   //Number of letters the user has to guess:
   int quit = length - same;
   do{
    printf("\n\nEnter a letter: \n");
    scanf(" %c", &Guess);
    printf("\n");
    n = Guessing(Guess, Selected[0], tempArr);
    printf("\n");
    for(int j = 0; j < length; j++){
        printf(" %c ", n[j]);
    }
    if(GoodGuess(Guess, Selected[0]) == 0){
        lifes--;
    } 
    BuildTree(lifes, Guess, Selected[0]);
    
   }while(lifes > 0 && CountUnderscore(n) > 0);


   /*print final image of the game*/
   if(CountUnderscore(tempArr) == 0){
       win();
   }else{
       lost();
   }
    
//free the allocated memory, after the program is finished
  free(a);
  free(b);
  free(c);
  free(d);
  free(e);
  free(f);
  free(g);
}
/* Game if option: own word is chosen */
void HangmanGameOwnWord(char * arr){
   GuessingGameStart();
   //Make every String have the same overall design
   EqualDesign(arr);
   HiddenWord(arr);
   //Guessing part of the game
   int lifes = 5;
   char Guess;
   char *n;
   int length = WordLength(arr);
   int p = length;
   char tempArr[p];
   //fill tempArr with '-':
    for(int m = 0; m < length; m++){
       tempArr[m] = '-';
   }
   int same = SameChars(arr,length);
   //Number of letters the user has to guess:
   int quit = length - same;
   do{
    printf("\n\nEnter a lowercased letter: \n");
    scanf(" %c", &Guess);
    printf("\n");
    n = Guessing(Guess, arr, tempArr);
    printf("\n");
    for(int j = 0; j < length; j++){
        printf(" %c ", n[j]);
    }
    if(GoodGuess(Guess, arr) == 0){
        lifes--;
    } 
    
    BuildTree(lifes, Guess, arr);
    
   }while(lifes > 0 && CountUnderscore(n) > 0);


   //print final image of the game
   if(CountUnderscore(tempArr) == 0){
       win();
   }else{
       lost();
   }
}
void main(){
    //First print the titel of the game:
    GameTitle();
    //Ask user if he wants to enter a word or use a random one:
    int choice;
    printf("\n\nDo you want to use a random word or enter your own word? random = 1, own = 0\n");
    scanf("%d", &choice);
    /* Common problem with scanf that is followed by a fgets
       to solve this problem add a new line after scanf
       - best way I found by using getchar()
       */
    getchar();
    if(choice == 1){
         HangmanGame();
    }else if(choice == 0){
         char str[MAX];
         printf("\nEnter a word (Max Length = 20): \n");
         /* stdin means standard input stream where data
            is sent to and read by a program */
         fgets(str, MAX, stdin);
         /* REMOVE THE REDUNDANT NEW LINE CHARACTER 
            OF fgets()
            */
         str[strcspn(str, "\n")] = 0;
         HangmanGameOwnWord(str);
    }else{
        printf("\nWrong input - Restart the Game!\n");
    }

}