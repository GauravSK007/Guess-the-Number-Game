#include <stdio.h>
#include <stdlib.h>
#include<time.h> //for Random number
#include <windows.h> //for delay in output(for Linux/UNIX use unistd.h)

void Agame (int cNum){
    int chance = 1;
    int userN;
    
    while(chance<=5){
        // making it more interactive
        if(chance==1){
            printf("Please Guess the number, Chance %d of 5: ", chance);
            scanf("%d", &userN);
        }
        else if(chance<=4){
            printf("Please Guess the number again, Chance %d of 5: ", chance);
            scanf("%d", &userN);
        }
        else{
            printf("Please Guess the number again but be careful its your last chance, Chance %d of 5: ", chance);
            scanf("%d", &userN);
        }

        //(number comparison) hint using if-else ladder
        if(userN == cNum){
            printf("Congratulations, you won the game, Chance used = %d; Chance left = %d",chance,5-chance);
            return;
        }
        else if(userN>cNum && userN-cNum>=10){
            printf("Ooops too big... Try again, Chance used = %d; Chance left = %d\n\n",chance,5-chance );
            chance++;
            continue;
        }
        else if(userN>cNum && userN-cNum<10){
            printf("Ohh, that was close, a little smaller!!. Try again, Chance used = %d; Chance left = %d\n\n",chance,5-chance );
            chance++;
            continue;
        }
        else if(userN<cNum && cNum-userN>=10){
            printf("Ooops too small... Try again, Chance used = %d; Chance left = %d\n\n",chance,5-chance );
            chance++;
            continue;
        }
        else if(userN<cNum && cNum-userN<10){
            printf("Ohh, that was close, a little bigger!!. Try again, Chance used = %d; Chance left = %d\n\n",chance,5-chance );
            chance++;
            continue;
        }

    }
    //failed to guess in 5 chance
    printf("GAME OVER\n");
    printf("You loose, No more chances left!!\n");
    printf("The correct number was %d.",cNum);
    return;
}
int main() {
    
    srand(time(0));
    int randomNum = rand()%100 + 1;
    // Introduction and Basic rules of the game(displayed using print statement)

    printf("*******************************************************************\n");
    printf("*****!!!!        Welcome To Guess the Number Game         !!!******\n");
    printf("*****!!!! Before Moving Ahead Please Read the Instructions!!!******\n");
    printf("*****!!!!   You can play it alone or with your Friends    !!!******\n");
    printf("*****!!!!                                                 !!!******\n");
    printf("*****!!!!  If you are playing with your friends, the one  !!!******\n");
    printf("*****!!!!        with less no. of guesses will win        !!!******\n");
    printf("*****!!!!                Let the Game Begin               !!!******\n");
    printf("*******************************************************************\n");
    
    char choice; //Choice for game mode
    
    while (1){
        printf("Please select the mode, for Alone press \"A\" & for playing with friends press \"F\": ");
        scanf(" %c", &choice);
        switch(choice){
            case 'A':
                printf("*******************************************************************\n");
                printf("*****!!!!      So, you are playing this game alone,       !!!******\n");
                printf("*****!!!!  To make it more interesting you have guess the !!!******\n");
                printf("*****!!!!   Number in 5 tries, otherwise you will loose   !!!******\n");
                printf("*******************************************************************\n");
                printf("Starting game..\n\n");
                Sleep(2000); // a delay of 2000 miliseconds, 2 sec
                printf("Computer is choosing a number between 1 and 100..\n\n");
                Sleep(3000);
                printf("A number has been selected..\n\n");
                Sleep(2000);

                Agame(randomNum);
                break;

            case 'F':
                printf("Multiplayer mode is Underdevelopment, Stay Tuned..");
                break;

            default:
                printf("Please enter a correct choice!!\n");
                continue;
        }

        break;
    }
    return 0;
}
