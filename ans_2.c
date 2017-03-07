#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void main(){
  FILE *file = fopen("file.txt", "r");
    char *code;
    size_t n = 0;
    int c;

    char storage[128];

    code = malloc(10);

    int i = 0;
    while ((c = fgetc(file)) != EOF)
    {
        char test = (char)c;
        if(test != ',' && test != ' '){
            storage[i] = c;
            i++;
        } else {
          if(i){
            int number = strlen(storage);
            int j;
            int alphaFlag = 0;
            int digitFlag = 0;
            for(j=0; j<number; j++){

                if(isdigit(storage[j])){
                    digitFlag = 1;
                }
                if(isalpha(storage[j])){
                    alphaFlag = 1;
                }

                // check for real numbers
                if(storage[j] == '.'){
                  printf("%s - real numbers", storage);
                  memset(storage,0,strlen(storage));
                  j += number;
                }

                if(number == (j+1)){
                    if(alphaFlag == 1 && digitFlag == 0){
                      printf("%s - alphabetical strings", storage);
                      memset(storage,0,strlen(storage));
                    }
                    else if (digitFlag == 1 && alphaFlag == 0){
                      printf("%s - integer", storage);
                      memset(storage,0,strlen(storage));
                    }
                    else if (alphaFlag == 1 && digitFlag == 1){
                      printf("%s - alphanumeric", storage);
                      memset(storage,0,strlen(storage));
                    }
                }
            }

            printf("%s\n", storage);
            memset(storage,0,strlen(storage));
          }
          i = 0;
        }
    }

    printf("\n\nPRESS ENTER TO EXIT");
    getchar(); // wait for ENTER
}
