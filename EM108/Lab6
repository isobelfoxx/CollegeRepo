#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ans;
    int mode;
    int player1, computer;
    int player1score, computerscore;
    int sum;
    
    player1score=0;
    computerscore=0;
    printf("Hello and Welcome to Morra - Odds and Evens Game!\n");
    ans=1;
    while (ans==1)
    
    {
    printf("Good Luck! May the best player win!\n");
    printf("Please select if Odd or Even wins the game (1 for Odd and 0 for even)\n");
    scanf("%d", &mode);
    
    printf("Please enter your chosen number of fingers (between 1-10)\n");
    scanf("%d", &player1);
    
    printf("The computer is generating it's number of fingers (between 1-10)\n");
    computer = rand()%10+1;
    
    printf("Player one's input = %d\n", player1);
    printf("Computer's input = %d\n", computer);
    
    sum = player1 + computer;
    
    if(sum%2 == mode) {
    player1score = player1score + 1;
    printf("Player one Wins, and gets one point!\n");
    }
    else {
    computerscore = computerscore + 1;
    printf("Computer Wins, and gets one point!\n");
    }
    printf ("Computer score = %d\n", computerscore);
    printf ("Player one's score= %d\n", player1score);
    
    if(computerscore == 6) {
    printf("**COMPUTER WINS**");
    return 0;
    }
    else if(player1score == 6){
    printf("**PLAYER ONE WINS**");
    return 0;
    }
    
    printf("\n");
    printf("Do you still want to play (1 for yes or 0 for no)\n");
    scanf("%d", &ans)%10;
    

}
    return 0;
}
