#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
  srand(time(0));
  double score = 1000;
  int guess, level, secret = rand() % 100, shots;

  printf("\n\n***** WELCOME TO THE GUESS GAME!\n\n");
  printf("(1) - EASY\n");
  printf("(2) - MEDIUM\n");
  printf("(3) - HARD\n");
  printf("(4) - INSANE\n");
  printf("\nCHOOSE YOUR DESTINY! ");
  scanf("%d", &level);

  switch (level) {
    case 4:
      shots = 1;
      break;
    case 3:
      shots = 5;
      break;
    case 2:
      shots = 10;
      break;
    default:
      shots = 20;
      break;
  }

  for (int i = 1; i <= shots; i++) {
    printf("\n***** (%d) - TAKE A SHOT! ", i);
    scanf("%d", &guess);

    if (guess < 0) {
      printf("\n***** DO NOT SHOT A NEGATIVE NUMBER!\n");
      i--;
      continue;
    }

    if (guess == secret) {
      printf("\n***** BINGO! YOU HIT THE NUMBER.\n");
      printf("***** YOU DID IT IN %d %s.\n", i, i == 1 ? "SHOT" : "SHOTS");
      printf("***** YOUR SCORE: %.2f.", score);
      break;
    } else {
      printf("***** WRONG! YOU DID NOT HIT THE NUMBER.\n");
      if (guess > secret) {
        printf("***** YOUR NUMBER IS GREATER THAN THE SECRET.\n");
      } else {
        printf("***** YOUR NUMBER IS LOWER THAN THE SECRET.\n");
      }
      score -= (double) abs(guess - secret) / 2;
    }
  }
  printf("\n***** THE GAME IS OVER.\n\n");
}
