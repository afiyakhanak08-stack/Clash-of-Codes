#include<stdio.h>
#include<stdlib.h>//for rand,srand
#include<time.h>
int game(char you,char computer);
int main(){
    
    char you,computer;
    int score_computer = 0,score_you = 0;
    int n;

    printf("*****************************************\n");
    printf("---R.O.C.K---P.A.P.E.R---S.C.I.S.S.O.R---\n");
    printf("**************Best out of 3**************\n");
    printf("*****************************************\n");

    for(int i =1 ; i<= 3 ; i++){
    
    srand(time(NULL));
    n = rand() % 100;
    // If number < 33 - computer chooses Stone (s)
    // If number < 66 - computer chooses Paper (p)
    // Else - computer chooses Scissor (r)
    if(n<33)
        computer = 's';
    else if(n<66)
        computer = 'p';
    else
        computer = 'r';
    

    printf("Enter r for rock , p for paper , s for scissor : ");
    scanf(" %c", &you);

    int result = game(you,computer);
    if(result == -1){
        printf("You choose : %c\nComputer choose : %c\n\t\t\t Hence DRAW\n",you, computer);
    }
    else if(result == 0){
        printf("You choose : %c\nComputer choose : %c\n\t\t\t Hence YOU LOST\n",you, computer);
        score_computer+=1;
    }
    else if(result == 1){
        printf("You choose : %c\nComputer choose : %c\n\t\t\t Hence YOU WON\n",you, computer);
        score_you+=1;
    }   
}
    printf("\n\t**********SCORE**********\n You : %d\n Computer : %d\n",score_you,score_computer);
    if(score_computer > score_you){
        printf("\t----- BAD LUCK YOU LOST-----\n");
        }
    else if(score_computer < score_you){
        printf("\t-----CONGRADULATION YOU WON-----\n");
        }
    else{
        printf("\t-----DRAW-----\n");
    }  
    return 0;   
}
    int game(char you,char computer){
    if(you=='s' && computer=='p' || you=='p' && computer=='r' || you=='r' && computer=='s' )
        return 1;
    else if(you=='s'&& computer=='r' || you=='p' && computer=='s' || you=='r' && computer=='p')
        return 0;
    else if(you == computer)
        return -1;
    }