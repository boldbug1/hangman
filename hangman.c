#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define MAX 100


int main(){
  srand((unsigned)time(NULL));
  printf("Welcome to the hangman game ");

  char words[][MAX] = {
    "apple","computer","fruit","Art","Egg"
  };

  size_t current_arr_size = sizeof(words)/sizeof(words[0]);
  
  if(current_arr_size > 0){
  
      int random_index = rand() % current_arr_size;
      int tries = strlen(words[random_index]) + 4;//very generous tries lol
      int word_len = strlen(words[random_index]);

      char *blank_word = malloc(word_len + 1);
      if(!blank_word){
        printf("Malloc failed");
        return 1;
      }

      int current_index;
      for (current_index = 0; current_index < word_len; current_index++)
      {
        blank_word[current_index] = '-';
      }
      blank_word[current_index] = '\0';
      

      while (tries > 0)
      {
        char letter;
        printf("\nEnter the letter : ");
        scanf(" %c",&letter);

        int isWordFound = 0;
        int isAllWordsFound = 0;

        for(int i = 0;i < word_len;i++){
            if(words[random_index][i] == letter && blank_word[i] != letter){
              blank_word[i] = letter;
              isWordFound = 1;
            }
        }

            if(isWordFound){
              printf("letter found\n");
              printf("\n%s",blank_word);
            }else{
              tries--;
              printf("\nletter not found in word\n");
              printf("%d tries left",tries);
            }

          int blanks_symbol_count = 0;
          for(int i = 0;i < word_len;i++){
            if(blank_word[i] == '-'){
              blanks_symbol_count++;
            }
          }

          if(blanks_symbol_count == 0){
            isAllWordsFound = 1;
          }
          
          if(isAllWordsFound){
            printf("You winnn!!!\nWord was %s\n",words[random_index]);
            free(blank_word);
            return 0;
          }

          if(tries == 0){
                printf("\nGame over\nWord was %s",words[random_index]);
                free(blank_word);
                return 0;
              }
      }
      
  }

}
