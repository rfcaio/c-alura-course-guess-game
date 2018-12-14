#include <stdio.h>

int main () {
  int guess, secret = 47, shots = 1;

  printf("\n\n***** WELCOME TO THE GUESS GAME!\n\n");
  while (1) {
    printf("\n***** TAKE A SHOT! ");
    scanf("%d", &guess);

    if (guess < 0) {
      printf("\n***** DO NOT SHOT A NEGATIVE NUMBER!\n");
      continue;
    }

    if (guess == secret) {
      printf("\n***** BINGO! YOU HIT THE NUMBER.\n");
      printf("***** YOU DID IT IN %d %s.\n", shots, shots == 1 ? "SHOT" : "SHOTS");
      break;
    } else {
      printf("***** WRONG! YOU DID NOT HIT THE NUMBER.\n");
      if (guess > secret) {
        printf("***** YOUR NUMBER IS GREATER THAN THE SECRET.\n");
      } else {
        printf("***** YOUR NUMBER IS LOWER THAN THE SECRET.\n");
      }
      shots++;
    }
  }
  printf("\n***** THE GAME IS OVER.\n\n");
}
