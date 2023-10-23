/*

* main.c
* Created on: Oct 21, 2023

*

* * * * * * NUMBER GUESSING GAME * * * * * *

*

* IS AN APPLICATION BASED ON THE USER GUESSING THE NUMBER 

* THE COMPUTER IS KEEPING. THE COMPUTER HOLDS A NUMBER AND 

* THE USER IS ASKED TO ENTER A NUMBER TO GUESS THE NUMBER 

* HELD BY THE COMPUTER. IF THE NUMBERS ARE EQUAL, 

* "CONGRATULATIONS" IS WRITTEN. IF NOT, "SORRY, 

* YOUR GUESS WAS WRONG!". IN BOTH CASES, THE NUMBER 

* GUESSED BY THE COMPUTER AND THE NUMBER GUESSED 

* BY THE USER ARE DISPLAYED ON THE SCREEN.

*/


#include <stdio.h> /* printf() - scanf() */

#include <stdlib.h> /* srand() - rand() */

#include <time.h> /* time() */

#include <unistd.h> /* time() */


#define CLEAR_SCREEN printf("\033[2J\033[1;1H")


/* 

* STARTS THE GAME BY COUNTING BACKWARDS FROM FOUR 

*/
void start_game(void);


/*

* THIS FUNCTION GENERATES A NUMBER, COMPARE IT WITH THE NUMBER 

* RECEIVED FROM THE USER AND WRITES THE ANSWER TO THE SCREEN

*/
int guess(void);


/* 

* IT ASKS THE USER TO GUESS A NUMBER BETWEEN 0 AND 101 AND ENTER IT.

* IT RETURNS THE NUMBER GUESSED BY THE USER

*/
int get_user_guess(void);



void start_game(void)
{

	int i;

	for (i = 4; i > -1; i--) {

	printf("\rThe game start in %d seconds...", i);

	fflush(stdout);

	sleep(1);

	}

	CLEAR_SCREEN;

}


int guess(void)
{
	int pc_guess, user_guess;
	
	srand(time(NULL)); 
	pc_guess = rand() % 101; 

	start_game();
	user_guess = get_user_guess();

	if (user_guess == -1) {
		printf("Oyun sonlandı!\n");
		return -1;
	} else {
		if (user_guess != pc_guess) {
			CLEAR_SCREEN;
			printf("Üzgünüm, yanlış tahmin! \n\nPc tahmini: \t%d\n"
				"Tahmininiz: \t%d\n\n", pc_guess, user_guess);
		} else {
			printf("TEBRİKLER! \n\nPc tahmini: \t%d\n"
				"Tahmininiz\t%d\n\n", pc_guess, user_guess);
		}
	}

	return 0;
}


/* ASK THE USER FOR A GUESS AND RETURN THE ANSWER */
int get_user_guess(void)
{
	int guess;
	
	printf("Tahmininizi giriniz\n \r[0-100] [ÇIKIŞ İÇİN -1]: ");
	scanf("%d", &guess);
	
	if (guess < -1 || guess > 100) {
		CLEAR_SCREEN;
		printf("Hatalı giriş yaptiniz.\n\n");
		guess = get_user_guess();
	} else if (guess == -1) {
		CLEAR_SCREEN;
	}

	return guess;
}


/* MAIN FUNCTION */
int main(void)
{
	int cntrl = 0;
	while ((cntrl = guess()) != -1) {}

	return 0;
}

