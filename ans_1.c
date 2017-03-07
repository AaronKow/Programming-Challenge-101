#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define RANGE_INT 1000000000 // define your integer range here  // 1000000000
#define RANGE_FLOAT 1000 // define your float range here    // 1000
#define LOOPING_NUM 614010 // define your looping times   // 614010 for 10MB

const char alphabetical[] = "abcdefghijklmnopqrstuvwxyz";   // total 26
const char alphanumeric[] = "0123456789abcdefghijklmnopqrstuvwxyz";   // total 36


/* Get random alphabetical strings */
char *alphaGenerator(char *str, int size){
  for(int i=0; i<size; i++){
      str[i] = alphabetical[rand() % ((int) sizeof(alphabetical)-1)];

      if(size == (i+1)){
        str[i+1] = '\0';   // places the '\0' at the end of the string when it initializes the array
      }
  }
  return str;
}

char *alphaNumGenerator(char *str, int size){
  for(int i=0; i<size; i++){
      str[i] = alphanumeric[rand() % ((int) sizeof(alphanumeric)-1)];

      if(size == (i+1)){
        str[i+1] = '\0';   // places the '\0' at the end of the string when it initializes the array
      }
  }
  return str;
}

int integerGenerator(){
  return rand() % RANGE_INT;
}

float floatGenerator(){
  return (float)rand()/(float)(RAND_MAX) * RANGE_FLOAT;
}

static char *rand_string(char *str, size_t size)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJK...";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}

void main(){
    srand(time(NULL));  // setting for random number
    FILE *f = fopen("file.txt", "w");   // create your file

    char loop[LOOPING_NUM];
    for(int i=0; i<sizeof(loop); i++){
        int choice = rand() % 4;  // set the choice randomly 0-3

        char strings[20];
        char stringsAlphaNum[20];
        int integer = integerGenerator();
        float realNumbers = floatGenerator();


        switch(choice){
            /* Get random alphabetical strings */
            case 0:
              alphaGenerator(strings, sizeof(strings));
              fprintf(f, "%s", strings);
              break;

            /* Get random alphanumeric strings */
            case 1:
              alphaNumGenerator(stringsAlphaNum, sizeof(stringsAlphaNum));
              for(int j=0; j<rand()%10; j++){
                  fprintf(f, " ");
              }
              fprintf(f, "%s", stringsAlphaNum);
              for(int j=0; j<rand()%10; j++){
                  fprintf(f, " ");
              }
              break;

            /* Get the random integer */
            case 2:
              fprintf(f, "%d", integer);
              break;

            /* Get the random real numbers */
            case 3:
              fprintf(f, "%f", realNumbers);
              break;
        }

        if(i != (sizeof(loop)-1)){
          fprintf(f, ", ");
        }
        else if(i == (sizeof(loop)-1)){
          fprintf(f, " ");
        }
    }

    fclose(f);      // close to end the writing
}
