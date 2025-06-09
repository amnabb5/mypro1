#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include <MMsystem.h>

#define MAX_TEAMS 20
#define YELLOW "\033[33m"
#define RESET "\033[0m"


#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_PURPLE  "\x1b[35m"
#define Max_Team 20
#define BLACK_TEXT   "\033[30m"
#define RED_TEXT     "\033[31m"
#define GREEN_TEXT   "\033[32m"
#define YELLOW_TEXT  "\033[33m"
#define BLUE_TEXT    "\033[34m"
#define MAGENTA_TEXT "\033[35m"
#define CYAN_TEXT    "\033[36m"
#define WHITE_TEXT   "\033[37m"
#define RESET_TEXT   "\033[0m"
#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define RESET_COLOR "\x1b[0m"


void hiiii(char team1A[50] ,char team2A[50],int* tm1 ,int* tm2){
    int tm11,tm22;
    printf(GREEN_TEXT " Please enter the result of how much team %s score : \n"RESET_TEXT ,team1A );
    scanf("%d",&tm11);
    printf(GREEN_TEXT " Please enter the result of how much team %s score : \n"RESET_TEXT ,team2A);
scanf("%d",&tm22);
if( tm11 > tm22){
   printf(ANSI_COLOR_BLUE "  %s won this much so he gets 3 points \n" ANSI_COLOR_RESET ,team1A);
   tm11 = 3;
   tm22 =0;
}
else if( tm11 < tm22){
   printf(ANSI_COLOR_BLUE "  %s won this much so he gets 3 points \n" ANSI_COLOR_RESET, team2A);
   tm22 =3;
   tm11 =0;
}
else if( tm11==tm22){
   printf(ANSI_COLOR_RED " so %s and %s win this much so they get 1 point \n" ANSI_COLOR_RESET , team1A , team2A);
   tm11 = 1;
   tm22 =1;
}



*tm1 = tm11;
*tm2 = tm22;


}


typedef struct {
    char name[50];
    int points;
    int place;
} Team;

void printDecorativeTable(int rows, Team* teams) {
    printf(MAGENTA_TEXT"+-----------------+-----------------+-------------------+\n" RESET_TEXT);
    printf("| Team            |        Points   |        Place   |\n");
    printf(MAGENTA_TEXT "+-----------------+-----------------+-------------------+\n" RESET_TEXT);

    for (int i = 0; i < rows; i++) {
        printf("|  %-19s   | %-8d        |        %-5d     |\n", teams[i].name, teams[i].points, teams[i].place);
        printf(MAGENTA_TEXT"+-----------------+-----------------+-------------------+\n" RESET_TEXT);
    }
}
void sortTeams(int rows, Team* teams) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            if (teams[j].points < teams[j + 1].points) {
                Team temp = teams[j];
                teams[j] = teams[j + 1];
                teams[j + 1] = temp;
            }
        }
    }

    
    for (int i = 0; i < rows; i++) {
        teams[i].place = i + 1;
    }
}





struct Team {
    char name[30];
    int wins;
    int goals;
    int d; 
};


void inputteams(struct Team teams[], int y) {
    for (int i = 0; i < y; i++) {
        printf(BLUE_TEXT"\nName of team %d :"RESET_TEXT, i + 1);
        scanf("%s", teams[i].name);
        teams[i].wins = 0;
        teams[i].goals = 0;
        teams[i].d = 0;
    }
}
int match(struct Team teams[], int t1, int t2) {
    int goals_t1 = rand() % 4; 
    int goals_t2 = rand() % 4; 

    teams[t1].goals += goals_t1;
    teams[t2].goals += goals_t2; 

    return goals_t1;  
}




void result(struct Team teams[], int t1, int t2, int goals) {
  usleep(300000);
    printf(GREEN_TEXT"%s vs %s : "RESET_TEXT, teams[t1].name, teams[t2].name);
    printf(WHITE_TEXT"Goals: %d-%d ", goals, 3 - goals);
    usleep(300000);
    if (goals > 1) {
        printf(BLUE_TEXT"(%s wins!)\n"RESET_TEXT, teams[t1].name);
        teams[t1].wins++;
    } else {
        printf(BLUE_TEXT"(%s wins!)\n"RESET_TEXT, teams[t2].name);
        teams[t2].wins++;
    }
    Sleep(1);
}


void mix(struct Team teams[], int y) {
    for (int i = y - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        struct Team te = teams[i];
        teams[i] = teams[j];
        teams[j] = te;
    }
}


void comp(struct Team teams[], int y, int days) {
    int *playedTeams = (int *)malloc(y * sizeof(int));
int j =0;
    for (int d = 1; d <= days; d++) {
        mix(teams, y);
        if(j==0){
        printf(" \n"); printf(" \n"); 
           printf(YELLOW_TEXT"8888888b.        d8888 Y88b   d88P       d888   \n");
    usleep(300000);
    printf("888  \"Y88b      d88888  Y88b d88P       d8888   \n");
    usleep(300000);
    printf("888    888     d88P888   Y88o88P          888   \n");
    usleep(300000);
    printf("888    888    d88P 888    Y888P           888   \n");
    usleep(300000);
    printf("888    888   d88P  888     888            888   \n");
    usleep(300000);
    printf("888    888  d88P   888     888            888   \n");
    usleep(300000);
    printf("888  .d88P d8888888888     888            888   \n");
    usleep(300000);
    printf("8888888P\" d88P     888     888          8888888 \n");
    usleep(300000);
    printf("                                                \n");
    usleep(300000);
    printf("                                                \n"RESET_TEXT);

    usleep(300000);

        }
         else if(j==1){
           printf(" \n"); printf(" \n");
    printf(YELLOW_TEXT"8888888b.        d8888 Y88b   d88P       .d8888b.  \n");
    usleep(300000);
    printf("888  \"Y88b      d88888  Y88b d88P       d88P  Y88b \n");
    usleep(300000);
    printf("888    888     d88P888   Y88o88P               888 \n");
    usleep(300000);
    printf("888    888    d88P 888    Y888P              .d88P \n");
    usleep(300000);
    printf("888    888   d88P  888     888           .od888P\"  \n");
    usleep(300000);
    printf("888    888  d88P   888     888          d88P\"      \n");
    usleep(300000);
    printf("888  .d88P d8888888888     888          888\"       \n");
    usleep(300000);
    printf("8888888P\" d88P     888     888          888888888  \n");
    usleep(300000);
    printf("                                                   \n");
    usleep(300000);
    printf("                                                   \n");
    usleep(300000);
    printf("                                                   \n"RESET_TEXT);


        }
         else if(j==2){
           printf(" \n"); printf(" \n");
          printf(YELLOW_TEXT"8888888b.        d8888 Y88b   d88P       .d8888b.  \n");
    usleep(300000);
    printf("888  \"Y88b      d88888  Y88b d88P       d88P  Y88b \n");
    usleep(300000);
    printf("888    888     d88P888   Y88o88P             .d88P \n");
    usleep(300000);
    printf("888    888    d88P 888    Y888P             8888\"  \n");
    usleep(300000);
    printf("888    888   d88P  888     888               \"Y8b.\n");
    usleep(300000);
    printf("888    888  d88P   888     888          888    888 \n");
    usleep(300000);
    printf("888  .d88P d8888888888     888          Y88b  d88P \n");
    usleep(300000);
    printf("8888888P\" d88P     888     888           \"Y8888P\"  \n");
    usleep(300000);
    printf("                                                   \n");
    usleep(300000);
    printf("                                                   \n");
    usleep(300000);
    printf("                                                   \n"RESET_TEXT);




        }
        else  if(j==3){
           printf(" \n"); printf(" \n");

    printf(YELLOW_TEXT"8888888b.        d8888 Y88b   d88P          d8888  \n");
    usleep(300000);
    printf("888  \"Y88b      d88888  Y88b d88P          d8P888  \n");
    usleep(300000);
    printf("888    888     d88P888   Y88o88P          d8P 888  \n");
    usleep(300000);
    printf("888    888    d88P 888    Y888P          d8P  888  \n");
    usleep(300000);
    printf("888    888   d88P  888     888          d88   888  \n");
    usleep(300000);
    printf("888    888  d88P   888     888          8888888888 \n");
    usleep(300000);
    printf("888  .d88P d8888888888     888                888  \n");
    usleep(300000);
    printf("8888888P\" d88P     888     888                888  \n");
    usleep(300000);
    printf("                                                   \n");
    usleep(300000);
    printf("                                                   \n");
    usleep(300000);
    printf("                                                   \n"RESET_TEXT);





        }
         else if(j==4){
 printf(" \n"); printf(" \n");
    printf(YELLOW_TEXT"8888888b.        d8888 Y88b   d88P      888888888  \n");
    usleep(300000);
    printf("888  \"Y88b      d88888  Y88b d88P       888        \n");
    usleep(300000);
    printf("888    888     d88P888   Y88o88P        888        \n");
    usleep(300000);
    printf("888    888    d88P 888    Y888P         8888888b.  \n");
    usleep(300000);
    printf("888    888   d88P  888     888               \"Y88b \n");
    usleep(300000);
    printf("888    888  d88P   888     888                 888 \n");
    usleep(300000);
    printf("888  .d88P d8888888888     888          Y88b  d88P \n");
    usleep(300000);
    printf("8888888P\" d88P     888     888           \"Y8888P\"  \n");
    usleep(300000);
    printf("                                                   \n");
    usleep(300000);
    printf("                                                   \n");
    usleep(300000);
    printf("                                                   \n"RESET_TEXT);

  

        }
        else  if(j==5){

           printf(" \n"); printf(" \n");
  printf(YELLOW_TEXT"8888888b.        d8888 Y88b   d88P       .d8888b.  \n");
    usleep(300000);
    printf("888  \"Y88b      d88888  Y88b d88P       d88P  Y88b \n");
    usleep(300000);
    printf("888    888     d88P888   Y88o88P        888        \n");
    usleep(300000);
    printf("888    888    d88P 888    Y888P         888d888b.  \n");
    usleep(300000);
    printf("888    888   d88P  888     888          888P \"Y88b \n");
    usleep(300000);
    printf("888    888  d88P   888     888          888    888 \n");
    usleep(300000);
    printf("888  .d88P d8888888888     888          Y88b  d88P \n");
    usleep(300000);
    printf("8888888P\" d88P     888     888           \"Y8888P\"  \n");
    usleep(300000);
    printf("                                                   \n");
    usleep(300000);
    printf("                                                   \n");
    usleep(300000);
    printf("                                                   \n"RESET_TEXT);



        }
        else if(j==6){
           printf(" \n"); printf(" \n");
              printf(YELLOW_TEXT"8888888b.        d8888 Y88b   d88P      888888888  \n");
    usleep(300000);
    printf("888  \"Y88b      d88888  Y88b d88P             d88P \n");
    usleep(300000);
    printf("888    888     d88P888   Y88o88P             d88P  \n");
    usleep(300000);
    printf("888    888    d88P 888    Y888P             d88P   \n");
    usleep(300000);
    printf("888    888   d88P  888     888           88888888  \n");
    usleep(300000);
    printf("888    888  d88P   888     888            d88P     \n");
    usleep(300000);
    printf("888  .d88P d8888888888     888           d88P      \n");
    usleep(300000);
    printf("8888888P\" d88P     888     888          d88P       \n");
    usleep(300000);
    printf("                                                   \n");
    usleep(300000);
    printf("                                                   \n");
    usleep(300000);
    printf("                                                   \n"RESET_TEXT);

        }
         else if(j==7){
          printf(" \n"); printf(" \n"); 
              printf(YELLOW_TEXT"8888888b.        d8888 Y88b   d88P       .d8888b.  \n");
    usleep(300000);
    printf("888  \"Y88b      d88888  Y88b d88P       d88P  Y88b \n");
    usleep(300000);
    printf("888    888     d88P888   Y88o88P        Y88b. d88P \n");
    usleep(300000);
    printf("888    888    d88P 888    Y888P          \"Y88888\"  \n");
    usleep(300000);
    printf("888    888   d88P  888     888          .d8P\"\"Y8b. \n");
    usleep(300000);
    printf("888    888  d88P   888     888          888    888 \n");
    usleep(300000);
    printf("888  .d88P d8888888888     888          Y88b  d88P \n");
    usleep(300000);
    printf("8888888P\" d88P     888     888           \"Y8888P\"  \n");
    usleep(300000);
    printf("                                                   \n");
    usleep(300000);
    printf("                                                   \n");
    usleep(300000);
    printf("                                                   \n"RESET_TEXT);
  }
         else if(j==8){
          printf(" \n"); printf(" \n"); 
             printf(YELLOW_TEXT"8888888b.        d8888 Y88b   d88P       .d8888b.  \n");
    usleep(300000);
    printf("888  \"Y88b      d88888  Y88b d88P       d88P  Y88b \n");
    usleep(300000);
    printf("888    888     d88P888   Y88o88P        888    888 \n");
    usleep(300000);
    printf("888    888    d88P 888    Y888P         Y88b. d888 \n");
    usleep(300000);
    printf("888    888   d88P  888     888           \"Y888P888 \n");
    usleep(300000);
    printf("888    888  d88P   888     888                 888 \n");
    usleep(300000);
    printf("888  .d88P d8888888888     888          Y88b  d88P \n");
    usleep(300000);
    printf("8888888P\" d88P     888     888           \"Y8888P\"  \n");
    usleep(300000);
    printf("                                                   \n");
    usleep(300000);
    printf("                                                   \n");
    usleep(300000);
    printf("                                                   \n"RESET_TEXT);
  }
         else if(j==9){
          printf(" \n"); printf(" \n"); 
              printf(YELLOW_TEXT"8888888b.        d8888 Y88b   d88P       d888   .d8888b.  \n");
    usleep(300000);
    printf("888  \"Y88b      d88888  Y88b d88P       d8888  d88P  Y88b \n");
    usleep(300000);
    printf("888    888     d88P888   Y88o88P          888  888    888 \n");
    usleep(300000);
    printf("888    888    d88P 888    Y888P           888  888    888 \n");
    usleep(300000);
    printf("888    888   d88P  888     888            888  888    888 \n");
    usleep(300000);
    printf("888    888  d88P   888     888            888  888    888 \n");
    usleep(300000);
    printf("888  .d88P d8888888888     888            888  Y88b  d88P \n");
    usleep(300000);
    printf("8888888P\" d88P     888     888          8888888 \"Y8888P\"  \n");
    usleep(300000);
    printf("                                                           \n");
    usleep(300000);
    printf("                                                           \n");
    usleep(300000);
    printf("                                                           \n"RESET_TEXT);
  }
         else if(j==10){
          printf(" \n"); printf(" \n"); 
            printf(YELLOW_TEXT"8888888b.        d8888 Y88b   d88P       d888    d888   \n");
    usleep(300000);
    printf("888  \"Y88b      d88888  Y88b d88P       d8888   d8888   \n");
    usleep(300000);
    printf("888    888     d88P888   Y88o88P          888     888   \n");
    usleep(300000);
    printf("888    888    d88P 888    Y888P           888     888   \n");
    usleep(300000);
    printf("888    888   d88P  888     888            888     888   \n");
    usleep(300000);
    printf("888    888  d88P   888     888            888     888   \n");
    usleep(300000);
    printf("888  .d88P d8888888888     888            888     888   \n");
    usleep(300000);
    printf("8888888P\" d88P     888     888          8888888 8888888 \n");
    usleep(300000);
    printf("                                                         \n");
    usleep(300000);
    printf("                                                         \n");
    usleep(300000);
    printf("                                                         \n"RESET_TEXT);
  }
         else if(j==11){
          printf(" \n"); printf(" \n"); 
            printf(YELLOW_TEXT"8888888b.        d8888 Y88b   d88P       d888    .d8888b.  \n");
    usleep(300000);
    printf("888  \"Y88b      d88888  Y88b d88P       d8888   d88P  Y88b \n");
    usleep(300000);
    printf("888    888     d88P888   Y88o88P          888          888 \n");
    usleep(300000);
    printf("888    888    d88P 888    Y888P           888        .d88P \n");
    usleep(300000);
    printf("888    888   d88P  888     888            888    .od888P\"  \n");
    usleep(300000);
    printf("888    888  d88P   888     888            888   d88P\"      \n");
    usleep(300000);
    printf("888  .d88P d8888888888     888            888   888\"       \n");
    usleep(300000);
    printf("8888888P\" d88P     888     888          8888888 888888888  \n");
    usleep(300000);
    printf("                                                           \n");
    usleep(300000);
    printf("                                                           \n");
    usleep(300000);
    printf("                                                           \n"RESET_TEXT);
  }
         else if(j==12){
          printf(" \n"); printf(" \n"); 
              printf(YELLOW_TEXT"8888888b.        d8888 Y88b   d88P       d888   .d8888b.  \n");
    usleep(300000);
    printf("888  \"Y88b      d88888  Y88b d88P       d8888  d88P  Y88b \n");
    usleep(300000);
    printf("888    888     d88P888   Y88o88P          888       .d88P \n");
    usleep(300000);
    printf("888    888    d88P 888    Y888P           888      8888\"  \n");
    usleep(300000);
    printf("888    888   d88P  888     888            888       \"Y8b. \n");
    usleep(300000);
    printf("888    888  d88P   888     888            888  888    888 \n");
    usleep(300000);
    printf("888  .d88P d8888888888     888            888  Y88b  d88P \n");
    usleep(300000);
    printf("8888888P\" d88P     888     888          8888888 \"Y8888P\"  \n");
    usleep(300000);
    printf("                                                           \n");
    usleep(300000);
    printf("                                                           \n");
    usleep(300000);
    printf("                                                           \n"RESET_TEXT);
  }
         else if(j==13){
          printf(" \n"); printf(" \n"); 
              printf(YELLOW_TEXT"8888888b.        d8888 Y88b   d88P       d888      d8888  \n");
    usleep(300000);
    printf("888  \"Y88b      d88888  Y88b d88P       d8888     d8P888  \n");
    usleep(300000);
    printf("888    888     d88P888   Y88o88P          888    d8P 888  \n");
    usleep(300000);
    printf("888    888    d88P 888    Y888P           888   d8P  888  \n");
    usleep(300000);
    printf("888    888   d88P  888     888            888  d88   888  \n");
    usleep(300000);
    printf("888    888  d88P   888     888            888  8888888888 \n");
    usleep(300000);
    printf("888  .d88P d8888888888     888            888        888  \n");
    usleep(300000);
    printf("8888888P\" d88P     888     888          8888888      888  \n");
    usleep(300000);
    printf("                                                           \n");
    usleep(300000);
    printf("                                                           \n");
    usleep(300000);
    printf("                                                           \n"RESET_TEXT);
  }
         else if(j==14){
          printf(" \n"); printf(" \n"); 
             printf(YELLOW_TEXT"8888888b.        d8888 Y88b   d88P       d888  888888888  \n");
    usleep(300000);
    printf("888  \"Y88b      d88888  Y88b d88P       d8888  888        \n");
    usleep(300000);
    printf("888    888     d88P888   Y88o88P          888  888        \n");
    usleep(300000);
    printf("888    888    d88P 888    Y888P           888  8888888b.  \n");
    usleep(300000);
    printf("888    888   d88P  888     888            888       \"Y88b \n");
    usleep(300000);
    printf("888    888  d88P   888     888            888         888 \n");
    usleep(300000);
    printf("888  .d88P d8888888888     888            888  Y88b  d88P \n");
    usleep(300000);
    printf("8888888P\" d88P     888     888          8888888 \"Y8888P\"  \n");
    usleep(300000);
    printf("                                                           \n");
    usleep(300000);
    printf("                                                           \n");
    usleep(300000);
    printf("                                                           \n"RESET_TEXT);
  }
         else if(j==15){
          printf(" \n"); printf(" \n"); 
              printf(YELLOW_TEXT"8888888b.        d8888 Y88b   d88P       d888   .d8888b.  \n");
    usleep(300000);
    printf("888  \"Y88b      d88888  Y88b d88P       d8888  d88P  Y88b \n");
    usleep(300000);
    printf("888    888     d88P888   Y88o88P          888  888        \n");
    usleep(300000);
    printf("888    888    d88P 888    Y888P           888  888d888b.  \n");
    usleep(300000);
    printf("888    888   d88P  888     888            888  888P \"Y88b \n");
    usleep(300000);
    printf("888    888  d88P   888     888            888  888    888 \n");
    usleep(300000);
    printf("888  .d88P d8888888888     888            888  Y88b  d88P \n");
    usleep(300000);
    printf("8888888P\" d88P     888     888          8888888 \"Y8888P\"  \n");
    usleep(300000);
    printf("                                                           \n");
    usleep(300000);
    printf("                                                           \n");
    usleep(300000);
    printf("                                                           \n"RESET_TEXT);
  }
         else if(j==16){
          printf(" \n"); printf(" \n"); 
              printf(YELLOW_TEXT"8888888b.        d8888 Y88b   d88P       d888   8888888888 \n");
    usleep(300000);
    printf("888  \"Y88b      d88888  Y88b d88P       d8888         d88P \n");
    usleep(300000);
    printf("888    888     d88P888   Y88o88P          888        d88P  \n");
    usleep(300000);
    printf("888    888    d88P 888    Y888P           888       d88P   \n");
    usleep(300000);
    printf("888    888   d88P  888     888            888    88888888  \n");
    usleep(300000);
    printf("888    888  d88P   888     888            888     d88P     \n");
    usleep(300000);
    printf("888  .d88P d8888888888     888            888    d88P      \n");
    usleep(300000);
    printf("8888888P\" d88P     888     888          8888888 d88P       \n");
    usleep(300000);
    printf("                                                           \n");
    usleep(300000);
    printf("                                                           \n");
    usleep(300000);
    printf("                                                           \n"RESET_TEXT);
  }
         else if(j==17){
          printf(" \n"); printf(" \n"); 
              printf(YELLOW_TEXT"8888888b.        d8888 Y88b   d88P       d888   .d8888b.  \n");
    usleep(300000);
    printf("888  \"Y88b      d88888  Y88b d88P       d8888  d88P  Y88b \n");
    usleep(300000);
    printf("888    888     d88P888   Y88o88P          888  Y88b. d88P \n");
    usleep(300000);
    printf("888    888    d88P 888    Y888P           888   \"Y88888\"  \n");
    usleep(300000);
    printf("888    888   d88P  888     888            888  .d8P\"\"Y8b. \n");
    usleep(300000);
    printf("888    888  d88P   888     888            888  888    888 \n");
    usleep(300000);
    printf("888  .d88P d8888888888     888            888  Y88b  d88P \n");
    usleep(300000);
    printf("8888888P\" d88P     888     888          8888888 \"Y8888P\"  \n");
    usleep(300000);
    printf("                                                           \n");
    usleep(300000);
    printf("                                                           \n");
    usleep(300000);
    printf("                                                           \n"RESET_TEXT);
  }
         else if(j==18){
          printf(" \n"); printf(" \n"); 
              printf(YELLOW_TEXT"8888888b.        d8888 Y88b   d88P       d888   .d8888b.  \n");
    usleep(300000);
    printf("888  \"Y88b      d88888  Y88b d88P       d8888  d88P  Y88b \n");
    usleep(300000);
    printf("888    888     d88P888   Y88o88P          888  888    888 \n");
    usleep(300000);
    printf("888    888    d88P 888    Y888P           888  Y88b. d888 \n");
    usleep(300000);
    printf("888    888   d88P  888     888            888   \"Y888P888 \n");
    usleep(300000);
    printf("888    888  d88P   888     888            888         888 \n");
    usleep(300000);
    printf("888  .d88P d8888888888     888            888  Y88b  d88P \n");
    usleep(300000);
    printf("8888888P\" d88P     888     888          8888888 \"Y8888P\"  \n");
    usleep(300000);
    printf("                                                           \n");
    usleep(300000);
    printf("                                                           \n");
    usleep(300000);
    printf("                                                           \n"RESET_TEXT);
  }
         else if(j==19){
          printf(" \n"); printf(" \n"); 
              printf(YELLOW_TEXT"8888888b.        d8888 Y88b   d88P       .d8888b.   .d8888b.  \n");
    usleep(300000);
    printf("888  \"Y88b      d88888  Y88b d88P       d88P  Y88b d88P  Y88b \n");
    usleep(300000);
    printf("888    888     d88P888   Y88o88P               888 888    888 \n");
    usleep(300000);
    printf("888    888    d88P 888    Y888P              .d88P 888    888 \n");
    usleep(300000);
    printf("888    888   d88P  888     888           .od888P\"  888    888 \n");
    usleep(300000);
    printf("888    888  d88P   888     888          d88P\"      888    888 \n");
    usleep(300000);
    printf("888  .d88P d8888888888     888          888\"       Y88b  d88P \n");
    usleep(300000);
    printf("8888888P\" d88P     888     888          888888888   \"Y8888P\"  \n"RESET_TEXT);
  }
 

else{
       printf(YELLOW_TEXT"                                                                                                                 \n");
    usleep(300000);

    printf("                                                                                                                 \n");
    usleep(300000);

    printf("                                                                                                                 \n");
    usleep(300000);

    printf("      @@@@        @@@                                     @@@@@@@@@@@@                                            \n");
    usleep(300000);

    printf("      @@@@@@      @@@                                     @@@      @@@@@                                          \n");
    usleep(300000);

    printf("      @@@@@@@     @@@       @@@@-                         @@@         @@@      @@@@@                             \n");
    usleep(300000);

    printf("      @@@  @@@    @@@    @@@@  @@@@   @@@    @@@     @@@  @@@         @@@@   @@@   @@@@  @@@      @@@            \n");
    usleep(300000);

    printf("      @@@   @@@   @@@   @@@      @@@  @@@   @@@@@   @@@   @@@          @@@          @@@   @@@    @@@             \n");
    usleep(300000);

    printf("      @@@     @@@ @@@   @@@@@@@@@@@@   @@@  @@ @@@  @@    @@@         @@@@   @@@@@@@@@@    @@@   @@              \n");
    usleep(300000);

    printf("      @@@      @@@@@@   @@@             @@ @@@ #@@ @@@    @@@         @@@   @@@     @@@     @@@ @@@              \n");
    usleep(300000);

    printf("      @@@       @@@@@    @@@            @@@@@   @@@@@     @@@@     @@@@@    @@@     @@@      @@@@@               \n");
    usleep(300000);

    printf("      @@@        @@@@     @@@@@@@@@@     @@@     @@@      @@@@@@@@@@@        @@@@@@@@@@      @@@@                \n");
    usleep(300000);

    printf("                                                                                              @@                  \n");
    usleep(300000);

    printf("                                                                                             @@@                  \n");
    usleep(300000);

    printf("                                                                                         @@@@@@                   \n");
    usleep(300000);

    printf("                                                                                                                 \n");
    usleep(300000);

    printf("                                                                                                                 \n" RESET_TEXT);
    usleep(300000);
}
        printf(CYAN_TEXT"\nDay %d :\n"RESET_TEXT, d);

j++;
        
        for (int i = 0; i < y; i++) {
            playedTeams[i] = 0;
        }

        for (int i = 0; i < y / 2; i++) {
            int t1 = i;
            int t2 = y - 1 - i;

            if (!playedTeams[t1] && !playedTeams[t2]) {
                int goals = match(teams, t1, t2);
                result(teams, t1, t2, goals);

                teams[t1].d = d;
                teams[t2].d = d;

                playedTeams[t1] = 1;
                playedTeams[t2] = 1;
            } else {
                printf(CYAN_TEXT"%s vs %s : No Match (Team have to rest)\n"RESET_TEXT, teams[t1].name, teams[t2].name);
            }
        }
    }

    free(playedTeams);
}


void displayScores(struct Team teams[], int y) {
    printf(MAGENTA_TEXT"\nScores:\n"RESET_TEXT);
     usleep(300000);
      printf(MAGENTA_TEXT"+-----------------+-----------------+-------------------+\n" RESET_TEXT);
    printf("| Team            |        wins     |        Goals      |\n");
    printf(MAGENTA_TEXT "+-----------------+-----------------+-------------------+\n" RESET_TEXT);

    for (int i = 0; i < y; i++) {
        usleep(300000);
        printf(BLUE_TEXT"  %s:              |%d wins           |   %d goals\n"RESET_TEXT, teams[i].name, teams[i].wins, teams[i].goals);
          printf(MAGENTA_TEXT"+-----------------+-----------------+-------------------+\n" RESET_TEXT);
        Sleep(1);
    }
}
int winn;

int WinnerFinder(struct Team teams[], int y) {
    int winner = 0;

    for (int i = 1; i < y; i++) {
        if (teams[i].wins > teams[winner].wins ) {
            winner = i;
        }
        else if( teams[i].wins == teams[winner].wins ){
          if(teams[i].goals >= teams[winner].goals){
            winner = i;
          }
        }
    }
    return winner;
}
void idk1(){
  
    
    printf(RED "               . .    ....            .  ... .     .  ..         \n");
    usleep(300000);
    printf("  .   ..        . .:X&$&X:.      .   .:X&$&X;.           . .  . \n");
    usleep(300000);
    printf(".   .+&$&&$$$$$&&&$x;;;;;x&&$xx++xX$&&X;;;;;x$&&&$$X$$&&$&x     \n");
    usleep(300000);
    printf(" . .$&;;;;;;;;;;;;;;xX$X+;;;;;;+++;;;;;xXX+x;;;;;;;;;;;;;;$$.   \n");
    usleep(300000);
    printf("    :&+;+..:;;;. .XXXXXXx  .xxXXXX$$x::XXX::XX;:;$$x;;;+;+&:.   \n");
    usleep(300000);
    printf(" ... .&x;+. ..   .XXXXXXx      .::xXx::XXX::XX;:;XX;::;;+&.    .\n");
    usleep(300000);
    printf("      :&+;x. ..  .XXXXXXx  .   .::xXx::XXX::XX;:;XX;:X;;&:   .. \n");
    usleep(300000);
    printf("       X$;;XxxxxxxXXXXXXXxxxxxxx::xXx::XXX::XX;:;XX;;;;XX    .  \n");
    usleep(300000);
    printf("       ;&;;XXXXXXXXXXXXXXXXXXXXX::xXx::XXX::XX;:;XX;;;;&;    .  \n");
    usleep(300000);
    printf("       :&;;XXXXXXXXXXXXXXXXXXXXX::xXx::XXX::XX;:;XX;+;;&:      .\n");
    usleep(300000);
    printf("       :&;;XXXXXXXXXXXXXXXXXXXXX::xXx::XXX::XX;:;XX;+;;&;       \n");
    usleep(300000);
    printf("    .  x$;;;   . .XXXXXXx      .::xXx::XXX::XX;:;XX;;;;$X       \n");
    usleep(300000);
    printf("     ..&x;x.     .XXXXXXx   .  .::xXx::XXX::XX;:;XX;:x;+&.   .  \n");
    usleep(300000);
    printf("    ..$X;;. .    .XXXXXXx      .::xXx::XXX::XX;:;XX;:;;;X&. ..  \n");
    usleep(300000);
    printf(" .  .&$;;xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+;;$$.    \n");
    usleep(300000);
    printf("  ..&$;;;;;;;;;;;;;;;;&$$$+;;X&$&X;;;&$$&$;;;;;;;;;;;;;;;;$&.   \n");
    usleep(300000);
    printf(" .+&x;;;;;;;;;;;;;;;;;&&$;;;+&+;;;;;;&&&&$;;;;;;;;;;;;;;;;;x&+  \n");
    usleep(300000);
    printf("$&+;;;;;;;;;;;;;;;;;;&;;;;;;&$;$X;;;&+;x&+;;;;;;;;;;;;;;;;;+&$\n");
    usleep(300000);
    printf("  .$$;;;;;;;;;;;;;;;;;;;;;;;;;;x+;;;;++++;;;;;;;;;;;;;;;;;;$$.  \n");
    usleep(300000);
    printf("   .&x;x$$$$$$$$$$$$$X$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$x;x&. .   \n");
    usleep(300000);
    printf(".   &x;x$$$$$$$$$$$$$X$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$x;x&     \n");
    usleep(300000);
    printf("    XX;x$$$$$$$$$$$$$X$$$$$$$+;+;;+$$$$$$$$$$$$$$$$$$$$$x;X$     \n");
    usleep(300000);
    printf("    +&;+$$$$$$$$$$$$$X$$$$$+;;;xxx;;;$$$$$$$$$$$$$$$$$$$;;$x     \n");
    usleep(300000);
    printf("  . :&;;X$$$$$$$$$$$$X$$$$;X;;;+;;;;x;X$$$$$$$$$$$$$$$$X;;&:   .\n");
    usleep(300000);
    printf("    .X$;+$$$$$$$$$$$$X$$$$;+;;;+++x;;;&$$$$$$$$$$$$$$$$;;Xx  .  \n");
    usleep(300000);
    printf("   . .&x;;$$$$$$$$$$$X$$$$;;xxx;;;;+++X$$$$$$$$$$$$$$$;;+&..    \n");
    usleep(300000);
    printf("      .&x;;$$$$$$$$$$X$$$$$;;;;;;X;;;X$$$$$$$$$$$$$$X;;x$       \n");
    usleep(300000);
    printf("       .&$;;+$$$$$$$$X$$$$$$$x;;;;;x$$$$$$$$$$$$$$$+;;$X .     .\n");
    usleep(300000);
    printf("     .  .+&x;;;X$$$$$X$$$$$$$$$$$$$$$$$$$$$$$$$$X;;;x&: .     . \n");
    usleep(300000);
    printf("  .    .  .+&$;;;;+X$X$$$$$$$$$$$$$$$$$$$$$$$x;;;;$$:        .  \n");
    usleep(300000);
    printf("        .. ..x&&+;;;;;;;+xXXXXXXXXXXx+;;;;;;;x&&;.    ..    .   \n");
    usleep(300000);
    printf("           .    ..+$&&$x++;;;;;;;;;;;;++x$&&$+.             .    \n");
    usleep(300000);
    printf("   .  .                ..:;x&x;;;;x&x;:.   .    .    .     .    \n");
    usleep(300000);
    printf("        .                   .;&$X&;.    ..  .                    \n");
    usleep(300000);
    printf(" . .                           ..            .        .      .   \n"  RESET_COLOR);



 printf(YELLOW_TEXT".   .          .       :.  .           .     .   .      \n");
    usleep(300000);
    printf("...... .... ............. .    ;X     .........................\n");
    usleep(300000);
    printf(".......... ..... ....     +&+ +;; &X&     ............... .....\n");
    usleep(300000);
    printf(". ...............   . &&..+++++ +++;; .&&   .  ................\n");
    usleep(300000);
    printf(".... ........    .xx&X;;x     +++     x;;X&;&.    .............\n");
    usleep(300000);
    printf("............  x& +;:..:       :;        : .:;. &&   .. .........\n");
    usleep(300000);
    printf("...........  &;;+:++: &&&&&&&&& &&&&&&&&& :; ;;;;&  ..... .....\n");
    usleep(300000);
    printf(". ....... X ;+&&&&+ :.;&&   &&;&;&&   &&::: ;&&&&x; x ..... ...\n");
    usleep(300000);
    printf(".......  &  &&&&&:    &x.&&     &&.&&    ;&&&&&. &  ..... ...\n");
    usleep(300000);
    printf(". ....... X ;+&&&&+ :.;&&   &&;&;&&   &&::: ;&&&&x; x ..... ...\n");
    usleep(300000);
    printf(".......  &  &&&&&:    &x.&&     &&.&&    ;&&&&&. &  ..... ...\n");
    usleep(300000);
    printf("..... .. x+;.&   &&;&& .:&x  ::.  X&:  &&;&&   &:;+x .........\n");
    usleep(300000);
    printf("......... $  ;&;&&;   .;&&&;.:+&+:.:&&&;.   ;&&+&; .X .........\n");
    usleep(300000);
    printf(".. ......     X:.X&:.&X$;;:;:;:;:;:;;:X$X&.:&& :X     .........\n"RESET_COLOR);
    usleep(300000);
    printf(".........   &; ;:; . XXXXXXXXXXXXX.. ;:; ;&.  ..............\n");
    usleep(300000);
    printf("...........    .XXX&+;;;;::;;;;;::;;;;+&XXX  . ... .......... \n");
    usleep(300000);
    printf("........    XX&;;;:;;++X&&&&&&&&&$x;;;:;;;&XX   ............\n");
    usleep(300000);
    printf("......    $;;;;;;$ .     ..... .... ..      x$;;;;;+$ . ......\n");
    usleep(300000);
    printf(".....   X;;:;;X:xX$$.  .................   X;X:xX;;:;;X   .....\n");
    usleep(300000);
    printf(".. .  X&;;;;X X&;;:;$X   .............   $;;;;;&X X;;;;&X  ....\n");
    usleep(300000);
    printf("..   &;::;X X;;::;:.:;&X               &;;::;;::;&X X;::;&   ..\n");
    usleep(300000);
    printf(".   &;;;&XX&;::;X$X;:::;&&;+++++++++xX;;.:;&XX&;::;&xX&;;;&   .\n");
    usleep(300000);
    printf("  X&::;X X;:.:&$$$XXX;:.:.::;;;+;;:.:::..&X    X&;;;;X X;:;&X  .\n");
    usleep(300000);
    printf("  &::;X X;:.;X$$$$Xx::.:::::XX   X&::::;::;&X  . X;::;X X;::&   .\n");
    usleep(300000);
    printf(" &;.;X &;:.;X$$$$X:...;$X;::;;X $;::;;$&;;:;;& .  X;::;$ $;.;$  .\n");
    usleep(300000);
    printf("X;::&+X;::;$&$$X;::.;XX$$$X:::;;;;;;&.  .&;;;&  .  &;::;Xx&::;$  \n");
    usleep(300000);
    printf(" &:.;X.;:.;X &&$;...&X$$$$$$$&::.::X   .   $&    ..  X;..;X &:.; \n");
    usleep(300000);
    printf(" ;.:x.$;.:&. .:&..:;X$$$$$$$$$X+:&$&&   ..    .....  X;..;X ;::; \n");
    usleep(300000);
    printf("X;.:X $;::& . X;.::X$$$$$$$$$$$$X$$&&&$  ...........  &::;& X;:;X \n");
    usleep(300000);
    printf("X;:;$ &::;& . X;.:;&&$$$$$$$XXXXXXXXX$&&$ . ......... &::;&.X;:;X \n");
    usleep(300000);
    printf("X;:;$ &::;& . X;.:;X&&&$$$$X;::;;;;;;;$&&&x   ......  &::;& X;:;X \n");
    usleep(300000);
    printf("X;.:X.$;::&   x;::;X. &&&$$X;.:;XXXXXX$$$&&&; . ....  &::;& $:.;X \n");
    usleep(300000);
    printf(".:.;& &;.:&.   X;::&X   &&&X;.:;$$$$$$$$$$$&&&   ..  X;..;X &:.; \n");
    usleep(300000);
    printf("&:.;X ;::;X   .&;.:+X  . &&;.:.....:+$$$$$$$&&&     &;::& X;.:& \n");
    usleep(300000);
    printf("X;::& X;::;$  . &;::;&  . ;X.:.;;;;;X$$$X;X$$&&&&  X;::;X &::;$.\n");
    usleep(300000);
    printf(" &;:;$ &;::;X    &;;;;;&X X&.:;XXXXXX$$;:::;:&$$&&$;::;& X;.;&  \n");
    usleep(300000);
    printf("  x+::;X X;::;$  . :$;;.:;;;;.:;XXX&;::::::;X$$$$X;:::;X X;::X.  \n");
    usleep(300000);
    printf("   X;::;&.$;;;;& .    &&;;;::.:::;:..:::;$X$$$$$$X;:;;& &;::&X   \n");
    usleep(300000);
    printf(" .  X;::;$ x&$   ....    X&X;.::;;++&$$$$$$$$$$$$$$X&X $;:;+X  . \n");
    usleep(300000);
    printf(" ..  x&;;;;X.  .........   .&.:;&    $&&&$$$$$$$$&&$ X;;:;&:  .. \n");
    usleep(300000);
    printf(" ...   X;;:;&X   ... ..... x&;+;& .. ..&&&$$$$&&&$ X&;;;;X   ....\n");
    usleep(300000);
    printf(" .....   &;;;;&X.   ......   .    ....   &&&&&&; X&;;;;$   .....\n");
    usleep(300000);
    printf(" ......   +&;;:;;&$      ................  &  XX;;:;;&    ...... \n");
    usleep(300000);
    printf(" ........ .  $&;;;;;X$$        .          XX;;;;;;&$    ........ \n");
    usleep(300000);
    printf(" . .........   xX&;;;;;;+$&&XXXXXXXXX&&$+;;;;;;&X;   .. ........ \n");
    usleep(300000);
    printf(" .............     XX&+;;;:;;;;;;;;;;;:;;;x&XX     .......... .  \n");
    usleep(300000);
    printf(".                 .      XXXXXx. .;XXXXX .      .          .     \n");
    usleep(300000);




    usleep(300000);
    printf(MAGENTA_TEXT"                                                                           &                                                                           \n");
    usleep(300000);
    printf("                                                                         &&&&                                                                         \n");
    usleep(300000);
    printf("                                                                     &&&&&&&                               &&&&                                       \n");
    usleep(300000);
    printf("                                                                &&&&&&&&&&&                               &&&&                                        \n");
    usleep(300000);
    printf("                                                        &&&&&&&&&&&&&&&&                                 &&&&                                         \n");
    usleep(300000);
    printf("                                                 &&&&&&&&&&&&&&&&                                       &&&&     &&                                    \n");
    usleep(300000);
    printf("                                          &&&&&&&&&                                                    &&&&   &&&&&&                                   \n");
    usleep(300000);
    printf("                                    &&&&&&&         &&&&    &&&&                                       &&&&  &   &&                                    \n");
    usleep(300000);
    printf("                                 &&&&&&&          &&&&&   &&&&&                          ;&&   &&&&   &&&&  &   &&X                                    \n");
    usleep(300000);
    printf("                               &&&&&&             &&&&    &&&&                          &&&& &&&&&&   &&&& &   &&                                       \n");
    usleep(300000);
    printf("                               &&&&              &&&&&   &&&&              &&&&  &&&;  &&&& &  &&&&   &&& &   &&                                        \n");
    usleep(300000);
    printf("                               &&&               &&&&    &&&    &&&      &&&&&&&&&&    &&& &  &&&&    &&&&  &                                          \n");
    usleep(300000);
    printf("                                                &&&&&   &&&&  &&&&&&    &&&&   &&&     &&&&   &&&&   &&&&  &&&                                         \n");
    usleep(300000);
    printf("                                                &&&&   &&&&  && &&&X   &&&&    &&&    &&&&   +&&&   &&&&&   &&&&                                       \n");
    usleep(300000);
    printf("                                               &&&&&   &&&& &  &&&&   &&&&    &&&     &&&&   &&&&  && &&      &&&&&                                    \n");
    usleep(300000);
    printf("                                               &&&&    &&& &   &&&&   &&&&    &&&    &&&&     &&& &            &&&&&&                                  \n");
    usleep(300000);
    printf("                                                &&&&&   &&&&&   &&&&    &&&&   &&&&  && &&&      &&         &&&&&  &&&&&&&&&&                            \n");
    usleep(300000);
    printf("                                                &&&&    &&&&&   &&&&   &&&&&.&& &&&&&                      &&&&&      &&&&&&&                            \n");
    usleep(300000);
    printf("                                                &&&&    &&&&    &&&&  &  &&&&                              &&&&                                            \n");
    usleep(300000);
    printf("                                    &&&&&&     &&&&     &&&&    &&&&&&                                    &&&&                                            \n");
    usleep(300000);
    printf("                                &&&&&        &&&      &&&                                               &&&                                             \n");
    usleep(300000);
    printf("                                &&&&        &&&&                                                       &&&&                                             \n");
    usleep(300000);
    printf("                               &&&&        &&&&                                                &&&     &&&                                              \n");
    usleep(300000);
    printf("                                &&       &&&            ;&&&                  &&&&   &&&&      &&&                                              \n");
    usleep(300000);
    printf("                                 &&    &&&&              &&&            &&&& && &&   &&&&   &&&&                                              \n");
    usleep(300000);
    printf("                                   &&&&&                &&&&    &&&&& &&&&& &&   &   &&&&   &&&                                               \n");
    usleep(300000);
    printf("                                                        &&&&    &&&& &&&&   &$  &&  &&&&   &&&&                                                         \n");
    usleep(300000);
    printf("                                                        &&&    &&&&  &&&&   &&  &. &&&&   &;&&&      &&&&                                               \n");
    usleep(300000);
    printf("                                                       &&&&    &&&& &&&&     &&&&&& &&&  &  &&&      &&&&                                               \n");
    usleep(300000);
    printf("                                                       &&&&   &&&&&  $&&&     &&     &&&&                                                               \n");
    usleep(300000);
    printf("                                                      &&&&  &&&&&&   &&&   &&&                                                                        \n");
    usleep(300000);
    printf("                                                      &&&&  & &&&&      &&&&                                                                           \n");
    usleep(300000);
    printf("                                                       &&&& &&&&                                                                              \n");
    usleep(300000);
    printf("                                         &&&&&&             &&&&                                                                              \n");
    usleep(300000);
    printf("                                       &&&&&&              &&&&                                                                               \n");
    usleep(300000);
    printf("                                     &&&&&                 &&&                                                                                \n");
    usleep(300000);
    printf("                                    &&&&&                 &&&                                                                                 \n");
    usleep(300000);
    printf("                                    &&&                  &&&                                                                                  \n");
    usleep(300000);
    printf("                                   &&&                  &&&&                                                                                  \n");
    usleep(300000);
    printf("                                    &&              &&&&                                                                                   \n");
    usleep(300000);
    printf("                                    &&&           &&&&                                                                                    \n");
    usleep(300000);
    printf("                                      &&&       &&&&                                                                                       \n");
    usleep(300000);
    printf("                                         &&&&&&&                                                                                           \n");
    usleep(300000);
    printf("                                                                                                                                                       \n");
    usleep(300000);
    printf("                                                                                                                                                       \n" RESET_COLOR);
    usleep(300000);

}







 int main(void){
  int gh;
    printf("do you wanna continue with auto matches or manual matches  press");
   printf(RED_TEXT " 1 " RESET_TEXT);
  printf( "to manual and" );
    printf( BLUE_TEXT" 0"RESET_TEXT);
    printf(" to auto\n");


scanf("%d", &gh);




while (gh != 0 && gh != 1){
  printf(" i said 0 or 1 =_= \n");
  printf(" try again \n");
  scanf("%d", &gh);
}
if( gh == 1){


    // input the numbers of teams
      int NT,h=0 ,tm1,tm2 ,team1b=0,team2b=0,team3b=0,team4b=0,team5b=0 , team6b=0 , team7b=0, team8b=0, team9b=0, team10b=0 , team11b=0 , team12b=0 , team13b=0 , team14b=0 , team15b=0 , team16b=0 , team17b=0 , team18b=0 , team19b=0 ,team20b,cs[10];
      char    conv[2000] , user[50] , vd[50] ;
          do {    printf("input the number of teams (it must be between 10 and 20) :\n");
             scanf("%d",&NT);
               if (NT>20 || NT<10){
                     printf(ANSI_COLOR_RED "wrong\n" ANSI_COLOR_RESET);
                           }
                 } while(NT>20 || NT<10);

 Team teams[MAX_TEAMS];

// turn of 10 teams

           if (NT==10){    char teamA [50];    char team1A [50];    char team2A [50];    char team3A [50];    char team4A [50];    char team5A [50];    char team6A [50];    char team7A [50];    char team8A [50];    char team9A [50];    char team10A [50];    char team11A [10];    printf("input the name of your teams one by one:\n");
             fgets(teamA,50,stdin);
                fgets(team1A,50,stdin);    fgets(team2A,50,stdin);    fgets(team3A,50,stdin);    fgets(team4A,50,stdin);    fgets(team5A,50,stdin);    fgets(team6A,50,stdin);    fgets(team7A,50,stdin);    fgets(team8A,50,stdin);        int team1 [50];    int team2 [50];    int team3 [50];    int team4 [50];    int team5 [50];    int team6 [50];    int team7 [50];    int team8 [50];    fgets(team9A,50,stdin);    fgets(team10A,50,stdin);   int team9 [50];    int team10 [50];

        printf(" Hello user :)  \n");
   sleep(2);
        printf(" are you feeling good today ? tell me about your day : ^_^ ") ;
         fgets(conv,2000,stdin);
            sleep(2);
        printf(" omg wow, at least you're doing good!!, keep it up \n");
           sleep(2);
printf("btw i am 'MESSI' your assistant into this tournament :) \n");
   sleep(2);
   printf(ANSI_COLOR_YELLOW" we will start this tournament with a LOT of games ,I hope it will be competitive this season \n "ANSI_COLOR_RESET);
     sleep(2);
   printf(" press enter key to start : \n");
   fgets(vd,50,stdin);
      sleep(2);
  printf(ANSI_COLOR_GREEN" LETS START ^o^ \n"ANSI_COLOR_RESET);
   sleep(2);

  //DAY 1     ******************************************************************************************************************

    printf(YELLOW "@@@@@@@                     .,***,,...   ...,,***,.                    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      . . . . .,./,,****,,..   ..,,****,,/.*.    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . .   .    ,*/***,,.. ..,,**//*,.   /      .   .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                 /    .*///**,,....,**///*.    *                %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . . . . ...    ,///**,,...,**////*  . /    . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . . .(   .*///**,...,*//((/.   (. .      .        %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                    ,(, ./((/**,.,*//((/. */.                   %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@  .      . . . . .     ./,/((/****/((((/,. . . .    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      .    ,((/**/((#, . . .          . . .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                              (/*/#                             %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . .   . . .    . . . . (*(    .   . .      . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . .        . . . (*(    . . .     .      . .   .  %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                             ,//,*/.                            %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      .   . . .    .   **#.,,,.,,#*,    . . .    . .   . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      . #%##%,/  ....*,%%#(.. . . .    .  . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                        #%##%,/  .*.%%%(###%(      ...                %@@@@@@@@\n");
     usleep(300000);
    printf(RESET);

    printf("\033[0;34m");  // Code ANSI pour la couleur bleue

    printf("____    __    ____  _______  __        ______   ______   .___  ___.  _______ \n");
     usleep(2000000);
    printf("\\   \\  /  \\  /   / |   ____||  |      /      | /  __  \\  |   \\/   | |   ____|\n");
     usleep(2000000);
    printf(" \\   \\/    \\/   /  |  |__   |  |     |  ,----'|  |  |  | |  \\  /  | |  |__   \n");
     usleep(2000000);
    printf("  \\            /   |   __|  |  |     |  |     |  |  |  | |  |\\/|  | |   __|  \n");
     usleep(2000000);
    printf("   \\    /\\    /    |  |____ |  `----.|  `----.|  `--'  | |  |  |  | |  |____ \n");
     usleep(2000000);
    printf("    \\__/  \\__/     |_______||_______| \\______| \\______/  |__|  |__| |_______|\n");
 usleep(2000000);
    printf("\033[0m");  // Réinitialisation de la couleur




printf(" ************************************ DAY 1************************************ \n");
printf(" Commenatator : Ladies and gentlemen, thank you so much for attending especially our guest of honor  'enter your name' ");
 fgets(user,50,stdin);
   sleep(2);
printf(" sir %s great honor to see you \n" ,user);
  sleep(2);






printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team2A ,team3A ,team4A);
//match 1  
  sleep(2);
printf(ANSI_COLOR_BLUE"* First  match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[0] = tm1;
team2[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[0] = tm1;
team4[0] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[1] = tm1;
team3[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[1] = tm1;
team5[0] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[2] = tm1;
team4[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[1] = tm1;
team5[1] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf(ANSI_COLOR_BLUE"* First  match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[3] = tm1;
team5[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[2] = tm1;
team3[2] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  match *\n"ANSI_COLOR_RESET);

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[3] = tm1;
team4[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[3] = tm1;
team5[3] = tm2;













//DAY 6     ******************************************************************************************************************

printf(" * DAY 6* \n");


printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf(ANSI_COLOR_BLUE"* First  match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[0] = tm1;
team7[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team9A, &tm1 ,&tm2);

team8[0] = tm1;
team9[0] = tm2;





//day7      ******************************************************************************************************************
printf(" * DAY 7* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[1] = tm1;
team8[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team9[1] = tm1;
team10[0] = tm2;

//day8    ******************************************************************************************************************
printf(" * DAY 8* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[2] = tm1;
team9[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[1] = tm1;
team10[1] = tm2;

//day9    ******************************************************************************************************************
printf(" * DAY 9* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[3] = tm1;
team10[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[2] = tm1;
team8[2] = tm2;

//day10    ******************************************************************************************************************
printf(" * DAY 10* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[3] = tm1;
team9[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[3] = tm1;
team10[3] = tm2;



sleep(5);

// final round ***********************************************************************


printf(ANSI_COLOR_YELLOW ANSI_COLOR_YELLOW " ********** The Final Round  ********** \n " ANSI_COLOR_RESET );
printf("* this is the last chance for each team in this tournament * \n");
printf(" so Mr %s Who do you think will win this tournament? \n",user);

fgets(vd,50,stdin);
fgets(vd,50,stdin);


printf(" so team %s we will see\n",vd);
printf(ANSI_COLOR_PURPLE" **********************************************************************************************************\n"ANSI_COLOR_RESET);

//day 1
printf(" commenatator : Ladies and gentleman, thank you so much for attending especially our guest of honor  %s , we heard he was %s  last week we hope he doing better \n" ,user , conv);
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team2A ,team3A ,team4A);
//match 1
printf(ANSI_COLOR_BLUE"* First  match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[4] = tm1;
team2[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[4] = tm1;
team4[4] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2 * \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[5] = tm1;
team3[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[5] = tm1;
team5[4] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf("so today we have 2 matches the fist is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[6] = tm1;
team4[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[5] = tm1;
team5[5] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf(ANSI_COLOR_BLUE"* First  match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[7] = tm1;
team5[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[6] = tm1;
team3[6] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  match *\n"ANSI_COLOR_RESET);

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[7] = tm1;
team4[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[7] = tm1;
team5[7] = tm2;













//DAY 6     ******************************************************************************************************************

printf(" * DAY 6* \n");


printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf(ANSI_COLOR_BLUE"* First  match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[4] = tm1;
team7[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team8[4] = tm1;
team9[4] = tm2;





//day7      ******************************************************************************************************************
printf(" * DAY 7* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[5] = tm1;
team8[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team9A ,team10A, &tm1 ,&tm2);

team9[5] = tm1;
team10[4] = tm2;

//day8    ******************************************************************************************************************
printf(" * DAY 8* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[6] = tm1;
team9[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[5] = tm1;
team10[5] = tm2;

//day9    ******************************************************************************************************************
printf(" * DAY 9* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[7] = tm1;
team10[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[6] = tm1;
team8[6] = tm2;

//day10    ******************************************************************************************************************
printf(" * DAY 10* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[7] = tm1;
team9[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[7] = tm1;
team10[7] = tm2;

for( int i=0 ; i<=7 ; i++ ){
  team1b= team1[i] + team1b;

}

for( int i=0 ; i<=7 ; i++ ){
  team2b= team2[i]+ team2b;

}

for( int i=0 ; i<=7 ; i++ ){
  team3b= team3[i]+ team3b;

}

for( int i=0 ; i<=7 ; i++ ){
  team4b= team4[i]+ team4b;

}

for( int i=0 ; i<=7 ; i++ ){
  team5b= team5[i]+ team5b;

}

for( int i=0 ; i<=7 ; i++ ){
  team6b= team6[i]+ team6b;

}

for( int i=0 ; i<=7 ; i++ ){
  team7b= team7[i]+ team7b;

}

for( int i=0 ; i<=7 ; i++ ){
  team8b= team8[i]+ team8b;

}


for( int i=0 ; i<=7 ; i++ ){
  team9b= team9[i]+ team9b;

}

for( int i=0 ; i<=7 ; i++ ){
  team10b= team10[i]+ team10b;

}
cs[0] = team1b;
cs[1] = team2b;
cs[2] = team3b;
cs[3] = team4b;
cs[4] = team5b;
cs[5] = team6b;
cs[6] = team7b;
cs[7] = team8b;
cs[8] = team9b;
cs[9] = team10b;
int n=10;


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (cs[j] < cs[j + 1]) {
                // Swap cs[j] and cs[j + 1]
                int temp = cs[j];
                cs[j] = cs[j + 1];
                cs[j + 1] = temp;
            }
        }
    }

strcpy(teams[0].name, team1A);
 strcpy(teams[1].name, team2A);
 strcpy(teams[2].name, team3A);
 strcpy(teams[3].name, team4A);
 strcpy(teams[4].name, team5A);
 strcpy(teams[5].name, team6A);
 strcpy(teams[6].name, team7A);
 strcpy(teams[7].name, team8A);
 strcpy(teams[8].name, team9A);
  strcpy(teams[9].name, team10A);
    

teams[0].points = team1b ;
teams[1].points = team2b ;
 teams[2].points = team3b ;
teams[3].points = team4b ;
teams[4].points = team5b ;
teams[5].points = team6b ;
teams[6].points = team7b ;
teams[7].points = team8b ;
teams[8].points = team9b ;
teams[9].points = team10b ;


    
  sortTeams(NT, teams);     
        
    printDecorativeTable(NT, teams);




printf( BLUE_TEXT" so did your team %s win ?" RESET_TEXT ,vd );

























}
            else if (NT==11){  char teamA [50];  char team1A [50];    char team2A [50];    char team3A [50];    char team4A [50];    char team5A [50];    char team6A [50];    char team7A [50];    char team8A [50];    char team9A [50];    char team10A [50];    char team11A [50];    printf("input the name of your teams one by one:\n");   fgets(teamA,50,stdin);   fgets(team1A,50,stdin);    fgets(team2A,50,stdin);    fgets(team3A,50,stdin);    fgets(team4A,50,stdin);    fgets(team5A,50,stdin);    fgets(team6A,50,stdin);    fgets(team7A,50,stdin);    fgets(team8A,50,stdin);    fgets(team9A,50,stdin);    fgets(team10A,50,stdin);    fgets(team11A,50,stdin);    int team1 [50];    int team2 [50];    int team3 [50];    int team4 [50];    int team5 [50];    int team6 [50];    int team7 [50];    int team8 [50];    fgets(team11A,50,stdin);    int team9 [50];    int team10 [50];    int team11 [50];

           
        printf(" Hello user :)  \n");
   sleep(2);
        printf(" are you feeling good today ? tell me about your day : ^_^ ") ;
         fgets(conv,2000,stdin);
            sleep(2);
        printf(" omg wow, at least you're doing good!!, keep it up \n");
           sleep(2);
printf("btw i am 'MESSI' your assistant into this tournament :) \n");
   sleep(2);
   printf(ANSI_COLOR_YELLOW" we will start this tournament with a LOT of games ,I hope it will be competitive this season \n "ANSI_COLOR_RESET);
     sleep(2);
   printf(" press enter key to start : \n");
   fgets(vd,50,stdin);
      sleep(2);
  printf(ANSI_COLOR_GREEN" LETS START ^o^ \n"ANSI_COLOR_RESET);
   sleep(2);

  //DAY 1     ******************************************************************************************************************

    printf(YELLOW "@@@@@@@                     .,***,,...   ...,,***,.                    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      . . . . .,./,,****,,..   ..,,****,,/.*.    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . .   .    ,*/***,,.. ..,,**//*,.   /      .   .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                 /    .*///**,,....,**///*.    *                %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . . . . ...    ,///**,,...,**////*  . /    . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . . .(   .*///**,...,*//((/.   (. .      .        %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                    ,(, ./((/**,.,*//((/. */.                   %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@  .      . . . . .     ./,/((/****/((((/,. . . .    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      .    ,((/**/((#, . . .          . . .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                              (/*/#                             %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . .   . . .    . . . . (*(    .   . .      . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . .        . . . (*(    . . .     .      . .   .  %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                             ,//,*/.                            %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      .   . . .    .   **#.,,,.,,#*,    . . .    . .   . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      . #%##%,/  ....*,%%#(.. . . .    .  . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                        #%##%,/  .*.%%%(###%(      ...                %@@@@@@@@\n");
     usleep(300000);
    printf(RESET);

    printf("\033[0;34m");  // Code ANSI pour la couleur bleue

    printf("____    __    ____  _______  __        ______   ______   .___  ___.  _______ \n");
     usleep(2000000);
    printf("\\   \\  /  \\  /   / |   ____||  |      /      | /  __  \\  |   \\/   | |   ____|\n");
     usleep(2000000);
    printf(" \\   \\/    \\/   /  |  |__   |  |     |  ,----'|  |  |  | |  \\  /  | |  |__   \n");
     usleep(2000000);
    printf("  \\            /   |   __|  |  |     |  |     |  |  |  | |  |\\/|  | |   __|  \n");
     usleep(2000000);
    printf("   \\    /\\    /    |  |____ |  `----.|  `----.|  `--'  | |  |  |  | |  |____ \n");
     usleep(2000000);
    printf("    \\__/  \\__/     |_______||_______| \\______| \\______/  |__|  |__| |_______|\n");
 usleep(2000000);
    printf("\033[0m");  // Réinitialisation de la couleur




printf(" ************************************ DAY 1************************************ \n");
printf(" Commenatator : Ladies and gentlemen, thank you so much for attending especially our guest of honor  'enter your name' ");
 fgets(user,50,stdin);
   sleep(2);
printf(" sir %s great honor to see you \n" ,user);
  sleep(2);







printf(" so today we have 2 matches the first with %s and %s the 2nd between %s and %s so let's start \n",team1A ,team2A ,team3A ,team4A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[0] = tm1;
team2[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[0] = tm1;
team4[0] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2* \n");
printf(" so today we have 2 matches the first with %s and %s the 2nd between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[1] = tm1;
team3[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[1] = tm1;
team5[0] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf(" so today we have 2 matches the first with %s and %s the 2nd between %s and %s so let's start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[2] = tm1;
team4[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[1] = tm1;
team5[1] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[3] = tm1;
team5[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[2] = tm1;
team3[2] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[3] = tm1;
team4[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[3] = tm1;
team5[3] = tm2;













//DAY 6     ******************************************************************************************************************

printf(" * DAY 6* \n");


printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[0] = tm1;
team7[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team9A, &tm1 ,&tm2);

team8[0] = tm1;
team9[0] = tm2;





//day7      ******************************************************************************************************************
printf(" * DAY 7* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[1] = tm1;
team8[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team9[1] = tm1;
team10[0] = tm2;

//day8    ******************************************************************************************************************
printf(" * DAY 8* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[2] = tm1;
team9[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[1] = tm1;
team10[1] = tm2;

//day9    ******************************************************************************************************************
printf(" * DAY 9* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[3] = tm1;
team10[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[2] = tm1;
team8[2] = tm2;

//day10    ******************************************************************************************************************
printf(" * DAY 10* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[3] = tm1;
team9[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[3] = tm1;
team10[3] = tm2;

//day11    ******************************************************************************************************************
printf(" * DAY 11 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team1A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team1A, &tm1 ,&tm2);

team11[0] = tm1;
team1[8] = 0;
//day12    ******************************************************************************************************************
printf(" * DAY 12 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[1] = tm1;
team2[8] = 0;
//day13    ******************************************************************************************************************
printf(" * DAY 13 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team3A, &tm1 ,&tm2);

team11[2] = tm1;
team3[8] = 0;
//day14    ******************************************************************************************************************
printf(" * DAY 14 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team4A, &tm1 ,&tm2);

team11[3] = tm1;
team4[8] = 0;





































 sleep(5);
// final round ***********************************************************************
printf(ANSI_COLOR_YELLOW " ********** The Final Round  ********** \n"ANSI_COLOR_RESET);
printf("* this is the last chance for each team in this tournament * \n");
printf(" so sir %s Who do you think will win this tournament? \n",user);

fgets(vd,50,stdin);
fgets(vd,50,stdin);


printf(" so team %s we will see\n",vd);
printf(" **********************************************************************************************************\n");

//day 1
printf(" commenatator : Ladies and gentleman, thank you so much for attending especially our guest of honor  %s , we heard he was %s  last week we hope he doing better \n" ,user , conv);
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team2A ,team3A ,team4A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[4] = tm1;
team2[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[4] = tm1;
team4[4] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2 * \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[5] = tm1;
team3[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[5] = tm1;
team5[4] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[6] = tm1;
team4[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[5] = tm1;
team5[5] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[7] = tm1;
team5[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[6] = tm1;
team3[6] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[7] = tm1;
team4[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[7] = tm1;
team5[7] = tm2;


//day6    ******************************************************************************************************************
printf(" * DAY 6* \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team1A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team1A, &tm1 ,&tm2);

team11[4] = tm1;
team1[8] = 0;










//DAY 7     ******************************************************************************************************************

printf(" * DAY 7* \n");


printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[4] = tm1;
team7[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team8[4] = tm1;
team9[4] = tm2;


//day8    ******************************************************************************************************************
printf(" * DAY 8 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[5] = tm1;
team2[8] = 0;



//day9      ******************************************************************************************************************
printf(" * DAY 9 * \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[5] = tm1;
team8[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team9A ,team10A, &tm1 ,&tm2);

team9[5] = tm1;
team10[4] = tm2;
//day10    ******************************************************************************************************************
printf(" * DAY 10 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[6] = tm1;
team2[8] = 0;


//day11    ******************************************************************************************************************
printf(" * DAY 11* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[6] = tm1;
team9[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[5] = tm1;
team10[5] = tm2;

//day12    ******************************************************************************************************************
printf(" * DAY 12* \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team3A, &tm1 ,&tm2);

team11[7] = tm1;
team3[8] = 0;

//day13   ******************************************************************************************************************
printf(" * DAY 13* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[7] = tm1;
team10[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[6] = tm1;
team8[6] = tm2;

//day14    ******************************************************************************************************************
printf(" * DAY 14* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[7] = tm1;
team9[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[7] = tm1;
team10[7] = tm2;









for( int i=0 ; i<=7 ; i++ ){
  team1b= team1[i] + team1b;

}

for( int i=0 ; i<=7 ; i++ ){
  team2b= team2[i]+ team2b;

}

for( int i=0 ; i<=7 ; i++ ){
  team3b= team3[i]+ team3b;

}

for( int i=0 ; i<=7 ; i++ ){
  team4b= team4[i]+ team4b;

}

for( int i=0 ; i<=7 ; i++ ){
  team5b= team5[i]+ team5b;

}

for( int i=0 ; i<=7 ; i++ ){
  team6b= team6[i]+ team6b;

}

for( int i=0 ; i<=7 ; i++ ){
  team7b= team7[i]+ team7b;

}

for( int i=0 ; i<=7 ; i++ ){
  team8b= team8[i]+ team8b;

}


for( int i=0 ; i<=7 ; i++ ){
  team9b= team9[i]+ team9b;

}

for( int i=0 ; i<=7 ; i++ ){
  team10b= team10[i]+ team10b;

}
for( int i=0 ; i<=7 ; i++ ){
  team11b= team11[i]+ team11b;

}
int cs[11];
cs[0] = team1b;
cs[1] = team2b;
cs[2] = team3b;
cs[3] = team4b;
cs[4] = team5b;
cs[5] = team6b;
cs[6] = team7b;
cs[7] = team8b;
cs[8] = team9b;
cs[9] = team10b;
cs[10] = team11b;
int n=11;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (cs[j] < cs[j + 1]) {
                // Swap cs[j] and cs[j + 1]
                int temp = cs[j];
                cs[j] = cs[j + 1];
                cs[j + 1] = temp;
            }
        }
    }
   strcpy(teams[0].name, team1A);
 strcpy(teams[1].name, team2A);
 strcpy(teams[2].name, team3A);
 strcpy(teams[3].name, team4A);
 strcpy(teams[4].name, team5A);
 strcpy(teams[5].name, team6A);
 strcpy(teams[6].name, team7A);
 strcpy(teams[7].name, team8A);
 strcpy(teams[8].name, team9A);
  strcpy(teams[9].name, team10A);
    strcpy(teams[10].name, team11A);

teams[0].points = team1b ;
teams[1].points = team2b ;
 teams[2].points = team3b ;
teams[3].points = team4b ;
teams[4].points = team5b ;
teams[5].points = team6b ;
teams[6].points = team7b ;
teams[7].points = team8b ;
teams[8].points = team9b ;
teams[9].points = team10b ;
teams[10].points = team11b ;

    
  sortTeams(NT, teams);     
        
    printDecorativeTable(NT, teams);


printf( BLUE_TEXT" so did your team %s win ?" RESET_TEXT ,vd );

























               }



              else if (NT==12){ char teamA[50];    char team1A [50];    char team2A [50];    char team3A [50];    char team4A [50];    char team5A [50];    char team6A [50];    char team7A [50];    char team8A [50];    char team9A [50];    char team10A [50];    char team11A [50];    char team12A [50];    printf("input the name of your teams one by one:\n");  fgets(teamA,50,stdin);   fgets(team1A,50,stdin);    fgets(team2A,50,stdin);    fgets(team3A,50,stdin);    fgets(team4A,50,stdin);    fgets(team5A,50,stdin);    fgets(team6A,50,stdin);    fgets(team7A,50,stdin);    fgets(team8A,50,stdin);    fgets(team9A,50,stdin);    fgets(team10A,50,stdin);    fgets(team11A,50,stdin);    fgets(team12A,50,stdin);    int team1 [50];    int team2 [50];    int team3 [50];    int team4 [50];    int team5 [50];    int team6 [50];    int team7 [50];    int team8 [50];    int team9 [50];    fgets(team12A,50,stdin);    int team10 [50];    int team11 [50];    int team12 [50];
        
        printf(" Hello user :)  \n");
   sleep(2);
        printf(" are you feeling good today ? tell me about your day : ^_^ ") ;
         fgets(conv,2000,stdin);
            sleep(2);
        printf(" omg wow, at least you're doing good!!, keep it up \n");
           sleep(2);
printf("btw i am 'MESSI' your assistant into this tournament :) \n");
   sleep(2);
   printf(ANSI_COLOR_YELLOW" we will start this tournament with a LOT of games ,I hope it will be competitive this season \n "ANSI_COLOR_RESET);
     sleep(2);
   printf(" press enter key to start : \n");
   fgets(vd,50,stdin);
      sleep(2);
  printf(ANSI_COLOR_GREEN" LETS START ^o^ \n"ANSI_COLOR_RESET);
   sleep(2);

  //DAY 1     ******************************************************************************************************************

    printf(YELLOW "@@@@@@@                     .,***,,...   ...,,***,.                    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      . . . . .,./,,****,,..   ..,,****,,/.*.    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . .   .    ,*/***,,.. ..,,**//*,.   /      .   .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                 /    .*///**,,....,**///*.    *                %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . . . . ...    ,///**,,...,**////*  . /    . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . . .(   .*///**,...,*//((/.   (. .      .        %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                    ,(, ./((/**,.,*//((/. */.                   %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@  .      . . . . .     ./,/((/****/((((/,. . . .    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      .    ,((/**/((#, . . .          . . .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                              (/*/#                             %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . .   . . .    . . . . (*(    .   . .      . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . .        . . . (*(    . . .     .      . .   .  %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                             ,//,*/.                            %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      .   . . .    .   **#.,,,.,,#*,    . . .    . .   . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      . #%##%,/  ....*,%%#(.. . . .    .  . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                        #%##%,/  .*.%%%(###%(      ...                %@@@@@@@@\n");
     usleep(300000);
    printf(RESET);

    printf("\033[0;34m");  // Code ANSI pour la couleur bleue

    printf("____    __    ____  _______  __        ______   ______   .___  ___.  _______ \n");
     usleep(2000000);
    printf("\\   \\  /  \\  /   / |   ____||  |      /      | /  __  \\  |   \\/   | |   ____|\n");
     usleep(2000000);
    printf(" \\   \\/    \\/   /  |  |__   |  |     |  ,----'|  |  |  | |  \\  /  | |  |__   \n");
     usleep(2000000);
    printf("  \\            /   |   __|  |  |     |  |     |  |  |  | |  |\\/|  | |   __|  \n");
     usleep(2000000);
    printf("   \\    /\\    /    |  |____ |  `----.|  `----.|  `--'  | |  |  |  | |  |____ \n");
     usleep(2000000);
    printf("    \\__/  \\__/     |_______||_______| \\______| \\______/  |__|  |__| |_______|\n");
 usleep(2000000);
    printf("\033[0m");  // Réinitialisation de la couleur




printf(" ************************************ DAY 1************************************ \n");
printf(" Commenatator : Ladies and gentlemen, thank you so much for attending especially our guest of honor  'enter your name' ");
 fgets(user,50,stdin);
   sleep(2);
printf(" sir %s great honor to see you \n" ,user);
  sleep(2);







printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team2A ,team3A ,team4A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[0] = tm1;
team2[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[0] = tm1;
team4[0] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[1] = tm1;
team3[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[1] = tm1;
team5[0] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[2] = tm1;
team4[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[1] = tm1;
team5[1] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[3] = tm1;
team5[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[2] = tm1;
team3[2] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[3] = tm1;
team4[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[3] = tm1;
team5[3] = tm2;













//DAY 6     ******************************************************************************************************************

printf(" * DAY 6* \n");


printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[0] = tm1;
team7[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team9A, &tm1 ,&tm2);

team8[0] = tm1;
team9[0] = tm2;





//day7      ******************************************************************************************************************
printf(" * DAY 7* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[1] = tm1;
team8[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team9[1] = tm1;
team10[0] = tm2;

//day8    ******************************************************************************************************************
printf(" * DAY 8* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[2] = tm1;
team9[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[1] = tm1;
team10[1] = tm2;

//day9    ******************************************************************************************************************
printf(" * DAY 9* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[3] = tm1;
team10[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[2] = tm1;
team8[2] = tm2;

//day10    ******************************************************************************************************************
printf(" * DAY 10* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[3] = tm1;
team9[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[3] = tm1;
team10[3] = tm2;

//day11    ******************************************************************************************************************
printf(" * DAY 11 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team1A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team1A, &tm1 ,&tm2);

team11[0] = tm1;
team1[8] = 0;
//day12    ******************************************************************************************************************
printf(" * DAY 12 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[1] = tm1;
team2[8] = 0;
//day13    ******************************************************************************************************************
printf(" * DAY 13 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team3A, &tm1 ,&tm2);

team11[2] = tm1;
team3[8] = 0;
//day14    ******************************************************************************************************************
printf(" * DAY 14 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team4A, &tm1 ,&tm2);

team11[3] = tm1;
team4[8] = 0;
//day15    ******************************************************************************************************************
printf(" * DAY 15 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team3A, &tm1 ,&tm2);

team12[0] = tm1;
team3[8] = 0;
//day16    ******************************************************************************************************************
printf(" * DAY 16 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team4A, &tm1 ,&tm2);

team12[1] = tm1;
team4[8] = 0;
//day17    ******************************************************************************************************************
printf(" * DAY 17 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team5A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team5A, &tm1 ,&tm2);

team12[2] = tm1;
team5[8] = 0;
//day18    ******************************************************************************************************************
printf(" * DAY 18 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team8A, &tm1 ,&tm2);

team12[3] = tm1;
team8[8] = 0;




































 sleep(2);

// final round ***********************************************************************
printf(ANSI_COLOR_YELLOW " ********** The Final Round  ********** \n"ANSI_COLOR_RESET);
printf("* this is the last chance for each team in this tournament * \n");
printf(" so mister %s Who do you think will win this tournament? \n",user);

fgets(vd,50,stdin);
fgets(vd,50,stdin);


printf(" so team %s we will see\n",vd);
printf(" **********************************************************************************************************\n");

//day 1
printf(" commenatator : Ladies and gentleman, thank you so much for attending especially our guest of honor  %s , we heard he was %s  last week we hope he doing better \n" ,user , conv);
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team2A ,team3A ,team4A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[4] = tm1;
team2[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[4] = tm1;
team4[4] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2 * \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[5] = tm1;
team3[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[5] = tm1;
team5[4] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[6] = tm1;
team4[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[5] = tm1;
team5[5] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[7] = tm1;
team5[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[6] = tm1;
team3[6] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[7] = tm1;
team4[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[7] = tm1;
team5[7] = tm2;


//day6    ******************************************************************************************************************
printf(" * DAY 6* \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team1A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team1A, &tm1 ,&tm2);

team11[4] = tm1;
team1[8] = 0;










//DAY 7     ******************************************************************************************************************

printf(" * DAY 7* \n");


printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[4] = tm1;
team7[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team8[4] = tm1;
team9[4] = tm2;


//day8    ******************************************************************************************************************
printf(" * DAY 8 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[5] = tm1;
team2[8] = 0;



//day9      ******************************************************************************************************************
printf(" * DAY 9 * \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[5] = tm1;
team8[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team9A ,team10A, &tm1 ,&tm2);

team9[5] = tm1;
team10[4] = tm2;
//day10    ******************************************************************************************************************
printf(" * DAY 10 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[6] = tm1;
team2[8] = 0;


//day11    ******************************************************************************************************************
printf(" * DAY 11* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[6] = tm1;
team9[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[5] = tm1;
team10[5] = tm2;

//day12    ******************************************************************************************************************
printf(" * DAY 12* \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team3A, &tm1 ,&tm2);

team11[7] = tm1;
team3[8] = 0;

//day13   ******************************************************************************************************************
printf(" * DAY 13* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[7] = tm1;
team10[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[6] = tm1;
team8[6] = tm2;

//day14    ******************************************************************************************************************
printf(" * DAY 14* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[7] = tm1;
team9[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[7] = tm1;
team10[7] = tm2;
//day15    ******************************************************************************************************************
printf(" * DAY 15 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team3A, &tm1 ,&tm2);

team12[4] = tm1;
team3[8] = 0;
//day16    ******************************************************************************************************************
printf(" * DAY 16 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team4A, &tm1 ,&tm2);

team12[5] = tm1;
team4[8] = 0;
//day17    ******************************************************************************************************************
printf(" * DAY 17 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team5A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team5A, &tm1 ,&tm2);

team12[6] = tm1;
team5[8] = 0;
//day18    ******************************************************************************************************************
printf(" * DAY 18 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team8A, &tm1 ,&tm2);

team12[7] = tm1;
team8[8] = 0;








for( int i=0 ; i<=7 ; i++ ){
  team1b= team1[i] + team1b;

}

for( int i=0 ; i<=7 ; i++ ){
  team2b= team2[i]+ team2b;

}

for( int i=0 ; i<=7 ; i++ ){
  team3b= team3[i]+ team3b;

}

for( int i=0 ; i<=7 ; i++ ){
  team4b= team4[i]+ team4b;

}

for( int i=0 ; i<=7 ; i++ ){
  team5b= team5[i]+ team5b;

}

for( int i=0 ; i<=7 ; i++ ){
  team6b= team6[i]+ team6b;

}

for( int i=0 ; i<=7 ; i++ ){
  team7b= team7[i]+ team7b;

}

for( int i=0 ; i<=7 ; i++ ){
  team8b= team8[i]+ team8b;

}


for( int i=0 ; i<=7 ; i++ ){
  team9b= team9[i]+ team9b;

}

for( int i=0 ; i<=7 ; i++ ){
  team10b= team10[i]+ team10b;

}
for( int i=0 ; i<=7 ; i++ ){
  team11b= team11[i]+ team11b;

}
for( int i=0 ; i<=7 ; i++ ){
  team12b= team12[i]+ team12b;

}

int cs[12];
cs[0] = team1b;
cs[1] = team2b;
cs[2] = team3b;
cs[3] = team4b;
cs[4] = team5b;
cs[5] = team6b;
cs[6] = team7b;
cs[7] = team8b;
cs[8] = team9b;
cs[9] = team10b;
cs[10] = team11b;
cs[11] = team12b;
int n=12;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (cs[j] < cs[j + 1]) {
                // Swap cs[j] and cs[j + 1]
                int temp = cs[j];
                cs[j] = cs[j + 1];
                cs[j + 1] = temp;
            }
        }
    }

  strcpy(teams[0].name, team1A);
 strcpy(teams[1].name, team2A);
 strcpy(teams[2].name, team3A);
 strcpy(teams[3].name, team4A);
 strcpy(teams[4].name, team5A);
 strcpy(teams[5].name, team6A);
 strcpy(teams[6].name, team7A);
 strcpy(teams[7].name, team8A);
 strcpy(teams[8].name, team9A);
  strcpy(teams[9].name, team10A);
    strcpy(teams[10].name, team11A);
  strcpy(teams[11].name, team12A);

teams[0].points = team1b ;
teams[1].points = team2b ;
 teams[2].points = team3b ;
teams[3].points = team4b ;
teams[4].points = team5b ;
teams[5].points = team6b ;
teams[6].points = team7b ;
teams[7].points = team8b ;
teams[8].points = team9b ;
teams[9].points = team10b ;
teams[10].points = team11b ;
teams[11].points = team12b ;
    
  sortTeams(NT, teams);     
        
    printDecorativeTable(NT, teams);


printf( BLUE_TEXT" so did your team %s win ?" RESET_TEXT ,vd );
















                 }



















































               else if (NT==13){ char teamA[50];   char team1A [50];    char team2A [50];    char team3A [50];    char team4A [50];    char team5A [50];    char team6A [50];    char team7A [50];    char team8A [50];    char team9A [50];    char team10A [50];    char team11A [50];    char team12A [50];    char team13A [50];    printf("input the name of your teams one by one:\n");fgets(teamA,50,stdin);  fgets(teamA,50,stdin);   fgets(team1A,50,stdin);    fgets(team2A,50,stdin);    fgets(team3A,50,stdin);    fgets(team4A,50,stdin);    fgets(team5A,50,stdin);    fgets(team6A,50,stdin);    fgets(team7A,50,stdin);    fgets(team8A,50,stdin);    fgets(team9A,50,stdin);    fgets(team10A,50,stdin);    fgets(team11A,50,stdin);    fgets(team12A,50,stdin);    fgets(team13A,50,stdin);    int team1 [50];    int team2 [50];    int team3 [50];    int team4 [50];    int team5 [50];    int team6 [50];    int team7 [50];    int team8 [50];    fgets(team13A,50,stdin);    int team9 [50];    int team10 [50];    int team11 [50];    int team12 [50];    int team13 [50];

    
        printf(" Hello user :)  \n");
   sleep(2);
        printf(" are you feeling good today ? tell me about your day : ^_^ ") ;
         fgets(conv,2000,stdin);
            sleep(2);
        printf(" omg wow, at least you're doing good!!, keep it up \n");
           sleep(2);
printf("btw i am 'MESSI' your assistant into this tournament :) \n");
   sleep(2);
   printf(ANSI_COLOR_YELLOW" we will start this tournament with a LOT of games ,I hope it will be competitive this season \n "ANSI_COLOR_RESET);
     sleep(2);
   printf(" press enter key to start : \n");
   fgets(vd,50,stdin);
      sleep(2);
  printf(ANSI_COLOR_GREEN" LETS START ^o^ \n"ANSI_COLOR_RESET);
   sleep(2);

  //DAY 1     ******************************************************************************************************************

    printf(YELLOW "@@@@@@@                     .,***,,...   ...,,***,.                    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      . . . . .,./,,****,,..   ..,,****,,/.*.    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . .   .    ,*/***,,.. ..,,**//*,.   /      .   .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                 /    .*///**,,....,**///*.    *                %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . . . . ...    ,///**,,...,**////*  . /    . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . . .(   .*///**,...,*//((/.   (. .      .        %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                    ,(, ./((/**,.,*//((/. */.                   %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@  .      . . . . .     ./,/((/****/((((/,. . . .    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      .    ,((/**/((#, . . .          . . .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                              (/*/#                             %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . .   . . .    . . . . (*(    .   . .      . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . .        . . . (*(    . . .     .      . .   .  %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                             ,//,*/.                            %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      .   . . .    .   **#.,,,.,,#*,    . . .    . .   . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      . #%##%,/  ....*,%%#(.. . . .    .  . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                        #%##%,/  .*.%%%(###%(      ...                %@@@@@@@@\n");
     usleep(300000);
    printf(RESET);

    printf("\033[0;34m");  // Code ANSI pour la couleur bleue

    printf("____    __    ____  _______  __        ______   ______   .___  ___.  _______ \n");
     usleep(2000000);
    printf("\\   \\  /  \\  /   / |   ____||  |      /      | /  __  \\  |   \\/   | |   ____|\n");
     usleep(2000000);
    printf(" \\   \\/    \\/   /  |  |__   |  |     |  ,----'|  |  |  | |  \\  /  | |  |__   \n");
     usleep(2000000);
    printf("  \\            /   |   __|  |  |     |  |     |  |  |  | |  |\\/|  | |   __|  \n");
     usleep(2000000);
    printf("   \\    /\\    /    |  |____ |  `----.|  `----.|  `--'  | |  |  |  | |  |____ \n");
     usleep(2000000);
    printf("    \\__/  \\__/     |_______||_______| \\______| \\______/  |__|  |__| |_______|\n");
 usleep(2000000);
    printf("\033[0m");  // Réinitialisation de la couleur




printf(" ************************************ DAY 1************************************ \n");
printf(" Commenatator : Ladies and gentlemen, thank you so much for attending especially our guest of honor  'enter your name' ");
 fgets(user,50,stdin);
   sleep(2);
printf(" sir %s great honor to see you \n" ,user);
  sleep(2);









printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team2A ,team3A ,team4A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[0] = tm1;
team2[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[0] = tm1;
team4[0] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[1] = tm1;
team3[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[1] = tm1;
team5[0] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[2] = tm1;
team4[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[1] = tm1;
team5[1] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[3] = tm1;
team5[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[2] = tm1;
team3[2] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf("* First  match *\n");

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[3] = tm1;
team4[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[3] = tm1;
team5[3] = tm2;













//DAY 6     ******************************************************************************************************************

printf(" * DAY 6* \n");


printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf("* First  match *\n");

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[0] = tm1;
team7[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team9A, &tm1 ,&tm2);

team8[0] = tm1;
team9[0] = tm2;





//day7      ******************************************************************************************************************
printf(" * DAY 7* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf("* First  match *\n");

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[1] = tm1;
team8[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team9[1] = tm1;
team10[0] = tm2;

//day8    ******************************************************************************************************************
printf(" * DAY 8* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[2] = tm1;
team9[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[1] = tm1;
team10[1] = tm2;

//day9    ******************************************************************************************************************
printf(" * DAY 9* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[3] = tm1;
team10[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[2] = tm1;
team8[2] = tm2;

//day10    ******************************************************************************************************************
printf(" * DAY 10* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[3] = tm1;
team9[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[3] = tm1;
team10[3] = tm2;

//day11    ******************************************************************************************************************
printf(" * DAY 11 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team1A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team1A, &tm1 ,&tm2);

team11[0] = tm1;
team1[8] = 0;
//day12    ******************************************************************************************************************
printf(" * DAY 12 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[1] = tm1;
team2[8] = 0;
//day13    ******************************************************************************************************************
printf(" * DAY 13 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team3A, &tm1 ,&tm2);

team11[2] = tm1;
team3[8] = 0;
//day14    ******************************************************************************************************************
printf(" * DAY 14 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team4A, &tm1 ,&tm2);

team11[3] = tm1;
team4[8] = 0;
//day15    ******************************************************************************************************************
printf(" * DAY 15 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team3A, &tm1 ,&tm2);

team12[0] = tm1;
team3[8] = 0;
//day16    ******************************************************************************************************************
printf(" * DAY 16 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team4A, &tm1 ,&tm2);

team12[1] = tm1;
team4[8] = 0;
//day17    ******************************************************************************************************************
printf(" * DAY 17 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team5A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team5A, &tm1 ,&tm2);

team12[2] = tm1;
team5[8] = 0;
//day18    ******************************************************************************************************************
printf(" * DAY 18 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team8A, &tm1 ,&tm2);

team12[3] = tm1;
team8[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 19 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team8A, &tm1 ,&tm2);

team13[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 20 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team2A, &tm1 ,&tm2);

team13[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 21 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team7A, &tm1 ,&tm2);

team13[2] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 23 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team6A, &tm1 ,&tm2);




































 sleep(2);
// final round ***********************************************************************
printf(ANSI_COLOR_YELLOW " ********** The Final Round  ********** \n"ANSI_COLOR_RESET);
printf("* this is the last chance for each team in this tournament * \n");
printf(" so mister %s Who do you think will win this tournament? \n",user);

fgets(vd,50,stdin);
fgets(vd,50,stdin);


printf(" so team %s we will see\n",vd);
printf(" **********************************************************************************************************\n");

//day 1
printf(" commenatator : Ladies and gentleman, thank you so much for attending especially our guest of honor  %s , we heard he was %s  last week we hope he doing better \n" ,user , conv);
printf(" so today we have 2 matches the First  withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team2A ,team3A ,team4A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[4] = tm1;
team2[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[4] = tm1;
team4[4] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2 * \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[5] = tm1;
team3[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[5] = tm1;
team5[4] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[6] = tm1;
team4[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[5] = tm1;
team5[5] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[7] = tm1;
team5[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[6] = tm1;
team3[6] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[7] = tm1;
team4[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[7] = tm1;
team5[7] = tm2;


//day6    ******************************************************************************************************************
printf(" * DAY 6* \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team1A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team1A, &tm1 ,&tm2);

team11[4] = tm1;
team1[8] = 0;










//DAY 7     ******************************************************************************************************************

printf(" * DAY 7* \n");


printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[4] = tm1;
team7[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team8[4] = tm1;
team9[4] = tm2;


//day8    ******************************************************************************************************************
printf(" * DAY 8 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[5] = tm1;
team2[8] = 0;



//day9      ******************************************************************************************************************
printf(" * DAY 9 * \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[5] = tm1;
team8[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team9A ,team10A, &tm1 ,&tm2);

team9[5] = tm1;
team10[4] = tm2;
//day10    ******************************************************************************************************************
printf(" * DAY 10 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[6] = tm1;
team2[8] = 0;


//day11    ******************************************************************************************************************
printf(" * DAY 11* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[6] = tm1;
team9[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[5] = tm1;
team10[5] = tm2;

//day12    ******************************************************************************************************************
printf(" * DAY 12* \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team3A, &tm1 ,&tm2);

team11[7] = tm1;
team3[8] = 0;

//day13   ******************************************************************************************************************
printf(" * DAY 13* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[7] = tm1;
team10[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[6] = tm1;
team8[6] = tm2;

//day14    ******************************************************************************************************************
printf(" * DAY 14* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[7] = tm1;
team9[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[7] = tm1;
team10[7] = tm2;
//day15    ******************************************************************************************************************
printf(" * DAY 15 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team3A, &tm1 ,&tm2);

team12[4] = tm1;
team3[8] = 0;
//day16    ******************************************************************************************************************
printf(" * DAY 16 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team4A, &tm1 ,&tm2);

team12[5] = tm1;
team4[8] = 0;
//day17    ******************************************************************************************************************
printf(" * DAY 17 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team5A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team5A, &tm1 ,&tm2);

team12[6] = tm1;
team5[8] = 0;
//day18    ******************************************************************************************************************
printf(" * DAY 18 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team8A, &tm1 ,&tm2);

team12[7] = tm1;
team8[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 19 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team8A, &tm1 ,&tm2);

team13[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 20 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team2A, &tm1 ,&tm2);

team13[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 21 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team7A, &tm1 ,&tm2);

team13[6] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 23 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team6A, &tm1 ,&tm2);

team13[7] = tm1;
team6[8] = 0;








for( int i=0 ; i<=7 ; i++ ){
  team1b= team1[i] + team1b;

}

for( int i=0 ; i<=7 ; i++ ){
  team2b= team2[i]+ team2b;

}

for( int i=0 ; i<=7 ; i++ ){
  team3b= team3[i]+ team3b;

}

for( int i=0 ; i<=7 ; i++ ){
  team4b= team4[i]+ team4b;

}

for( int i=0 ; i<=7 ; i++ ){
  team5b= team5[i]+ team5b;

}

for( int i=0 ; i<=7 ; i++ ){
  team6b= team6[i]+ team6b;

}

for( int i=0 ; i<=7 ; i++ ){
  team7b= team7[i]+ team7b;

}

for( int i=0 ; i<=7 ; i++ ){
  team8b= team8[i]+ team8b;

}


for( int i=0 ; i<=7 ; i++ ){
  team9b= team9[i]+ team9b;

}

for( int i=0 ; i<=7 ; i++ ){
  team10b= team10[i]+ team10b;

}
for( int i=0 ; i<=7 ; i++ ){
  team11b= team11[i]+ team11b;

}
for( int i=0 ; i<=7 ; i++ ){
  team12b= team12[i]+ team12b;

}
for( int i=0 ; i<=7 ; i++ ){
  team13b= team13[i]+ team13b;

}
int cs[13];
cs[0] = team1b;
cs[1] = team2b;
cs[2] = team3b;
cs[3] = team4b;
cs[4] = team5b;
cs[5] = team6b;
cs[6] = team7b;
cs[7] = team8b;
cs[8] = team9b;
cs[9] = team10b;
cs[10] = team11b;
cs[11] = team12b;
cs[12] = team13b;
int n=13;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (cs[j] < cs[j + 1]) {
                // Swap cs[j] and cs[j + 1]
                int temp = cs[j];
                cs[j] = cs[j + 1];
                cs[j + 1] = temp;
            }
        }
    }

  strcpy(teams[0].name, team1A);
 strcpy(teams[1].name, team2A);
 strcpy(teams[2].name, team3A);
 strcpy(teams[3].name, team4A);
 strcpy(teams[4].name, team5A);
 strcpy(teams[5].name, team6A);
 strcpy(teams[6].name, team7A);
 strcpy(teams[7].name, team8A);
 strcpy(teams[8].name, team9A);
  strcpy(teams[9].name, team10A);
    strcpy(teams[10].name, team11A);
  strcpy(teams[11].name, team12A);
strcpy(teams[12].name, team13A);

teams[0].points = team1b ;
teams[1].points = team2b ;
 teams[2].points = team3b ;
teams[3].points = team4b ;
teams[4].points = team5b ;
teams[5].points = team6b ;
teams[6].points = team7b ;
teams[7].points = team8b ;
teams[8].points = team9b ;
teams[9].points = team10b ;
teams[10].points = team11b ;
teams[11].points = team12b ;
    teams[12].points = team13b ;

  sortTeams(NT, teams);     
        
    printDecorativeTable(NT, teams);

printf( BLUE_TEXT" so did your team %s win ?" RESET_TEXT ,vd );




















                 }



















































                 else if (NT==14){ char teamA[50];  char team1A [50];    char team2A [50];    char team3A [50];    char team4A [50];    char team5A [50];    char team6A [50];    char team7A [50];    char team8A [50];    char team9A [50];    char team10A [50];    char team11A [50];    char team12A [50];    char team13A [50];    char team14A [50];    printf("input the name of your teams one by one:\n"); fgets(teamA,50,stdin);    fgets(team1A,50,stdin);    fgets(team2A,50,stdin);    fgets(team3A,50,stdin);    fgets(team4A,50,stdin);    fgets(team5A,50,stdin);    fgets(team6A,50,stdin);    fgets(team7A,50,stdin);    fgets(team8A,50,stdin);    fgets(team9A,50,stdin);    fgets(team10A,50,stdin);    fgets(team11A,50,stdin);    fgets(team12A,50,stdin);    fgets(team13A,50,stdin);    fgets(team14A,50,stdin);    int team1 [50];    int team2 [50];    int team3 [50];    int team4 [50];    int team5 [50];    int team6 [50];    int team7 [50];    int team8 [50];     int team9 [50];    int team10 [50];    int team11 [50];    int team12 [50];    int team13 [50];    int team14 [50];

        printf(" Hello user :)  \n");
   sleep(2);
        printf(" are you feeling good today ? tell me about your day : ^_^ ") ;
         fgets(conv,2000,stdin);
            sleep(2);
        printf(" omg wow, at least you're doing good!!, keep it up \n");
           sleep(2);
printf("btw i am 'MESSI' your assistant into this tournament :) \n");
   sleep(2);
   printf(ANSI_COLOR_YELLOW" we will start this tournament with a LOT of games ,I hope it will be competitive this season \n "ANSI_COLOR_RESET);
     sleep(2);
   printf(" press enter key to start : \n");
   fgets(vd,50,stdin);
      sleep(2);
  printf(ANSI_COLOR_GREEN" LETS START ^o^ \n"ANSI_COLOR_RESET);
   sleep(2);

  //DAY 1     ******************************************************************************************************************

    printf(YELLOW "@@@@@@@                     .,***,,...   ...,,***,.                    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      . . . . .,./,,****,,..   ..,,****,,/.*.    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . .   .    ,*/***,,.. ..,,**//*,.   /      .   .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                 /    .*///**,,....,**///*.    *                %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . . . . ...    ,///**,,...,**////*  . /    . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . . .(   .*///**,...,*//((/.   (. .      .        %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                    ,(, ./((/**,.,*//((/. */.                   %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@  .      . . . . .     ./,/((/****/((((/,. . . .    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      .    ,((/**/((#, . . .          . . .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                              (/*/#                             %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . .   . . .    . . . . (*(    .   . .      . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . .        . . . (*(    . . .     .      . .   .  %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                             ,//,*/.                            %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      .   . . .    .   **#.,,,.,,#*,    . . .    . .   . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      . #%##%,/  ....*,%%#(.. . . .    .  . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                        #%##%,/  .*.%%%(###%(      ...                %@@@@@@@@\n");
     usleep(300000);
    printf(RESET);

    printf("\033[0;34m");  // Code ANSI pour la couleur bleue

    printf("____    __    ____  _______  __        ______   ______   .___  ___.  _______ \n");
     usleep(2000000);
    printf("\\   \\  /  \\  /   / |   ____||  |      /      | /  __  \\  |   \\/   | |   ____|\n");
     usleep(2000000);
    printf(" \\   \\/    \\/   /  |  |__   |  |     |  ,----'|  |  |  | |  \\  /  | |  |__   \n");
     usleep(2000000);
    printf("  \\            /   |   __|  |  |     |  |     |  |  |  | |  |\\/|  | |   __|  \n");
     usleep(2000000);
    printf("   \\    /\\    /    |  |____ |  `----.|  `----.|  `--'  | |  |  |  | |  |____ \n");
     usleep(2000000);
    printf("    \\__/  \\__/     |_______||_______| \\______| \\______/  |__|  |__| |_______|\n");
 usleep(2000000);
    printf("\033[0m");  // Réinitialisation de la couleur




printf(" ************************************ DAY 1************************************ \n");
printf(" Commenatator : Ladies and gentlemen, thank you so much for attending especially our guest of honor  'enter your name' ");
 fgets(user,50,stdin);
   sleep(2);
printf(" sir %s great honor to see you \n" ,user);
  sleep(2);



     






printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team2A ,team3A ,team4A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[0] = tm1;
team2[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[0] = tm1;
team4[0] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[1] = tm1;
team3[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[1] = tm1;
team5[0] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[2] = tm1;
team4[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[1] = tm1;
team5[1] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[3] = tm1;
team5[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[2] = tm1;
team3[2] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[3] = tm1;
team4[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[3] = tm1;
team5[3] = tm2;













//DAY 6     ******************************************************************************************************************

printf(" * DAY 6* \n");


printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[0] = tm1;
team7[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team9A, &tm1 ,&tm2);

team8[0] = tm1;
team9[0] = tm2;





//day7      ******************************************************************************************************************
printf(" * DAY 7* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[1] = tm1;
team8[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team9[1] = tm1;
team10[0] = tm2;

//day8    ******************************************************************************************************************
printf(" * DAY 8* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[2] = tm1;
team9[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[1] = tm1;
team10[1] = tm2;

//day9    ******************************************************************************************************************
printf(" * DAY 9* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[3] = tm1;
team10[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[2] = tm1;
team8[2] = tm2;

//day10    ******************************************************************************************************************
printf(" * DAY 10* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[3] = tm1;
team9[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[3] = tm1;
team10[3] = tm2;

//day11    ******************************************************************************************************************
printf(" * DAY 11 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team1A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team1A, &tm1 ,&tm2);

team11[0] = tm1;
team1[8] = 0;
//day12    ******************************************************************************************************************
printf(" * DAY 12 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[1] = tm1;
team2[8] = 0;
//day13    ******************************************************************************************************************
printf(" * DAY 13 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team3A, &tm1 ,&tm2);

team11[2] = tm1;
team3[8] = 0;
//day14    ******************************************************************************************************************
printf(" * DAY 14 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team4A, &tm1 ,&tm2);

team11[3] = tm1;
team4[8] = 0;
//day15    ******************************************************************************************************************
printf(" * DAY 15 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team3A, &tm1 ,&tm2);

team12[0] = tm1;
team3[8] = 0;
//day16    ******************************************************************************************************************
printf(" * DAY 16 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team4A, &tm1 ,&tm2);

team12[1] = tm1;
team4[8] = 0;
//day17    ******************************************************************************************************************
printf(" * DAY 17 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team5A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team5A, &tm1 ,&tm2);

team12[2] = tm1;
team5[8] = 0;
//day18    ******************************************************************************************************************
printf(" * DAY 18 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team8A, &tm1 ,&tm2);

team12[3] = tm1;
team8[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 19 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team8A, &tm1 ,&tm2);

team13[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 20 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team2A, &tm1 ,&tm2);

team13[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 21 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team7A, &tm1 ,&tm2);

team13[2] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 23 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team6A, &tm1 ,&tm2);

team13[3] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 24 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team8A, &tm1 ,&tm2);

team14[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 25 * \n");
printf(" today we will have 1 matches with %s and %s so let start \n",team14A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team2A, &tm1 ,&tm2);

team14[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 26 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team7A, &tm1 ,&tm2);

team14[2] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 27 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team6A, &tm1 ,&tm2);

team14[3] = tm1;
team6[8] = 0;

































 sleep(2);


// final round ***********************************************************************
printf(ANSI_COLOR_YELLOW " ********** The Final Round  ********** \n"ANSI_COLOR_RESET);
printf("* this is the last chance for each team in this tournament * \n");
printf(" so mister %s Who do you think will win this tournament? \n",user);

fgets(vd,50,stdin);
fgets(vd,50,stdin);


printf(" so team %s we will see\n",vd);
printf(" **********************************************************************************************************\n");

//day 1
printf(" commenatator : Ladies and gentleman, thank you so much for attending especially our guest of honor  %s , we heard he was %s  last week we hope he doing better \n" ,user , conv);
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team2A ,team3A ,team4A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[4] = tm1;
team2[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[4] = tm1;
team4[4] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2 * \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[5] = tm1;
team3[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[5] = tm1;
team5[4] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[6] = tm1;
team4[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[5] = tm1;
team5[5] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[7] = tm1;
team5[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[6] = tm1;
team3[6] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[7] = tm1;
team4[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[7] = tm1;
team5[7] = tm2;


//day6    ******************************************************************************************************************
printf(" * DAY 6* \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team1A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team1A, &tm1 ,&tm2);

team11[4] = tm1;
team1[8] = 0;










//DAY 7     ******************************************************************************************************************

printf(" * DAY 7* \n");


printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[4] = tm1;
team7[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team8[4] = tm1;
team9[4] = tm2;


//day8    ******************************************************************************************************************
printf(" * DAY 8 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[5] = tm1;
team2[8] = 0;



//day9      ******************************************************************************************************************
printf(" * DAY 9 * \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[5] = tm1;
team8[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team9A ,team10A, &tm1 ,&tm2);

team9[5] = tm1;
team10[4] = tm2;
//day10    ******************************************************************************************************************
printf(" * DAY 10 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[6] = tm1;
team2[8] = 0;


//day11    ******************************************************************************************************************
printf(" * DAY 11* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[6] = tm1;
team9[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[5] = tm1;
team10[5] = tm2;

//day12    ******************************************************************************************************************
printf(" * DAY 12* \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team3A, &tm1 ,&tm2);

team11[7] = tm1;
team3[8] = 0;

//day13   ******************************************************************************************************************
printf(" * DAY 13* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[7] = tm1;
team10[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[6] = tm1;
team8[6] = tm2;

//day14    ******************************************************************************************************************
printf(" * DAY 14* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[7] = tm1;
team9[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[7] = tm1;
team10[7] = tm2;
//day15    ******************************************************************************************************************
printf(" * DAY 15 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team3A, &tm1 ,&tm2);

team12[4] = tm1;
team3[8] = 0;
//day16    ******************************************************************************************************************
printf(" * DAY 16 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team4A, &tm1 ,&tm2);

team12[5] = tm1;
team4[8] = 0;
//day17    ******************************************************************************************************************
printf(" * DAY 17 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team5A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team5A, &tm1 ,&tm2);

team12[6] = tm1;
team5[8] = 0;
//day18    ******************************************************************************************************************
printf(" * DAY 18 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team8A, &tm1 ,&tm2);

team12[7] = tm1;
team8[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 19 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team8A, &tm1 ,&tm2);

team13[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 20 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team2A, &tm1 ,&tm2);

team13[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 21 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team7A, &tm1 ,&tm2);

team13[6] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 23 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team6A, &tm1 ,&tm2);

team13[7] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 24 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team8A, &tm1 ,&tm2);

team14[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 25 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team2A, &tm1 ,&tm2);

team14[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 26 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team7A, &tm1 ,&tm2);

team14[6] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 27 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team6A, &tm1 ,&tm2);

team14[7] = tm1;
team6[8] = 0;







for( int i=0 ; i<=7 ; i++ ){
  team1b= team1[i] + team1b;

}

for( int i=0 ; i<=7 ; i++ ){
  team2b= team2[i]+ team2b;

}

for( int i=0 ; i<=7 ; i++ ){
  team3b= team3[i]+ team3b;

}

for( int i=0 ; i<=7 ; i++ ){
  team4b= team4[i]+ team4b;

}

for( int i=0 ; i<=7 ; i++ ){
  team5b= team5[i]+ team5b;

}

for( int i=0 ; i<=7 ; i++ ){
  team6b= team6[i]+ team6b;

}

for( int i=0 ; i<=7 ; i++ ){
  team7b= team7[i]+ team7b;

}

for( int i=0 ; i<=7 ; i++ ){
  team8b= team8[i]+ team8b;

}


for( int i=0 ; i<=7 ; i++ ){
  team9b= team9[i]+ team9b;

}

for( int i=0 ; i<=7 ; i++ ){
  team10b= team10[i]+ team10b;

}
for( int i=0 ; i<=7 ; i++ ){
  team11b= team11[i]+ team11b;

}
for( int i=0 ; i<=7 ; i++ ){
  team12b= team12[i]+ team12b;

}
for( int i=0 ; i<=7 ; i++ ){
  team13b= team13[i]+ team13b;

}
for( int i=0 ; i<=7 ; i++ ){
  team14b= team14[i]+ team14b;

}
int cs[14];
cs[0] = team1b;
cs[1] = team2b;
cs[2] = team3b;
cs[3] = team4b;
cs[4] = team5b;
cs[5] = team6b;
cs[6] = team7b;
cs[7] = team8b;
cs[8] = team9b;
cs[9] = team10b;
cs[10] = team11b;
cs[11] = team12b;
cs[12] = team13b;
cs[13] = team14b;
int n=14;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (cs[j] < cs[j + 1]) {
                // Swap cs[j] and cs[j + 1]
                int temp = cs[j];
                cs[j] = cs[j + 1];
                cs[j + 1] = temp;
            }
        }
    }

  strcpy(teams[0].name, team1A);
 strcpy(teams[1].name, team2A);
 strcpy(teams[2].name, team3A);
 strcpy(teams[3].name, team4A);
 strcpy(teams[4].name, team5A);
 strcpy(teams[5].name, team6A);
 strcpy(teams[6].name, team7A);
 strcpy(teams[7].name, team8A);
 strcpy(teams[8].name, team9A);
  strcpy(teams[9].name, team10A);
    strcpy(teams[10].name, team11A);
  strcpy(teams[11].name, team12A);
strcpy(teams[12].name, team13A);
strcpy(teams[13].name, team14A);

teams[0].points = team1b ;
teams[1].points = team2b ;
 teams[2].points = team3b ;
teams[3].points = team4b ;
teams[4].points = team5b ;
teams[5].points = team6b ;
teams[6].points = team7b ;
teams[7].points = team8b ;
teams[8].points = team9b ;
teams[9].points = team10b ;
teams[10].points = team11b ;
teams[11].points = team12b ;
    teams[12].points = team13b ;
 teams[13].points = team14b ;

  sortTeams(NT, teams);     
        
    printDecorativeTable(NT, teams);

printf( BLUE_TEXT" so did your team %s win ?" RESET_TEXT ,vd );















                     }



















































                  else if (NT==15){  char teamA[50];  char team1A [50];    char team2A [50];    char team3A [50];    char team4A [50];    char team5A [50];    char team6A [50];    char team7A [50];    char team8A [50];    char team9A [50];    char team10A [50];    char team11A [50];    char team12A [50];    char team13A [50];    char team14A [50];    char team15A [50];    printf("input the name of your teams one by one:\n"); fgets(teamA,50,stdin);    fgets(team1A,50,stdin);    fgets(team2A,50,stdin);    fgets(team3A,50,stdin);    fgets(team4A,50,stdin);    fgets(team5A,50,stdin);    fgets(team6A,50,stdin);    fgets(team7A,50,stdin);    fgets(team8A,50,stdin);    fgets(team9A,50,stdin);    fgets(team10A,50,stdin);    fgets(team11A,50,stdin);    fgets(team12A,50,stdin);    fgets(team13A,50,stdin);    fgets(team14A,50,stdin);    fgets(team15A,50,stdin);    int team1 [50];    int team2 [50];    int team3 [50];    int team4 [50];    int team5 [50];    int team6 [50];    int team7 [50];    int team8 [50];    fgets(team15A,50,stdin);    int team9 [50];    int team10 [50];    int team11 [50];    int team12 [50];    int team13 [50];    int team14 [50];    int team15 [50];


        printf(" Hello user :)  \n");
   sleep(2);
        printf(" are you feeling good today ? tell me about your day : ^_^ ") ;
         fgets(conv,2000,stdin);
            sleep(2);
        printf(" omg wow, at least you're doing good!!, keep it up \n");
           sleep(2);
printf("btw i am 'MESSI' your assistant into this tournament :) \n");
   sleep(2);
   printf(ANSI_COLOR_YELLOW" we will start this tournament with a LOT of games ,I hope it will be competitive this season \n "ANSI_COLOR_RESET);
     sleep(2);
   printf(" press enter key to start : \n");
   fgets(vd,50,stdin);
      sleep(2);
  printf(ANSI_COLOR_GREEN" LETS START ^o^ \n"ANSI_COLOR_RESET);
   sleep(2);

  //DAY 1     ******************************************************************************************************************

    printf(YELLOW "@@@@@@@                     .,***,,...   ...,,***,.                    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      . . . . .,./,,****,,..   ..,,****,,/.*.    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . .   .    ,*/***,,.. ..,,**//*,.   /      .   .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                 /    .*///**,,....,**///*.    *                %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . . . . ...    ,///**,,...,**////*  . /    . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . . .(   .*///**,...,*//((/.   (. .      .        %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                    ,(, ./((/**,.,*//((/. */.                   %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@  .      . . . . .     ./,/((/****/((((/,. . . .    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      .    ,((/**/((#, . . .          . . .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                              (/*/#                             %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . .   . . .    . . . . (*(    .   . .      . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . .        . . . (*(    . . .     .      . .   .  %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                             ,//,*/.                            %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      .   . . .    .   **#.,,,.,,#*,    . . .    . .   . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      . #%##%,/  ....*,%%#(.. . . .    .  . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                        #%##%,/  .*.%%%(###%(      ...                %@@@@@@@@\n");
     usleep(300000);
    printf(RESET);

    printf("\033[0;34m");  // Code ANSI pour la couleur bleue

    printf("____    __    ____  _______  __        ______   ______   .___  ___.  _______ \n");
     usleep(2000000);
    printf("\\   \\  /  \\  /   / |   ____||  |      /      | /  __  \\  |   \\/   | |   ____|\n");
     usleep(2000000);
    printf(" \\   \\/    \\/   /  |  |__   |  |     |  ,----'|  |  |  | |  \\  /  | |  |__   \n");
     usleep(2000000);
    printf("  \\            /   |   __|  |  |     |  |     |  |  |  | |  |\\/|  | |   __|  \n");
     usleep(2000000);
    printf("   \\    /\\    /    |  |____ |  `----.|  `----.|  `--'  | |  |  |  | |  |____ \n");
     usleep(2000000);
    printf("    \\__/  \\__/     |_______||_______| \\______| \\______/  |__|  |__| |_______|\n");
 usleep(2000000);
    printf("\033[0m");  // Réinitialisation de la couleur




printf(" ************************************ DAY 1************************************ \n");
printf(" Commenatator : Ladies and gentlemen, thank you so much for attending especially our guest of honor  'enter your name' ");
 fgets(user,50,stdin);
   sleep(2);
printf(" sir %s great honor to see you \n" ,user);
  sleep(2);


      





printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team2A ,team3A ,team4A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[0] = tm1;
team2[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[0] = tm1;
team4[0] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[1] = tm1;
team3[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[1] = tm1;
team5[0] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[2] = tm1;
team4[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[1] = tm1;
team5[1] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[3] = tm1;
team5[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[2] = tm1;
team3[2] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[3] = tm1;
team4[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[3] = tm1;
team5[3] = tm2;













//DAY 6     ******************************************************************************************************************

printf(" * DAY 6* \n");


printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[0] = tm1;
team7[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team9A, &tm1 ,&tm2);

team8[0] = tm1;
team9[0] = tm2;





//day7      ******************************************************************************************************************
printf(" * DAY 7* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf("* First  match *\n");

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[1] = tm1;
team8[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team9[1] = tm1;
team10[0] = tm2;

//day8    ******************************************************************************************************************
printf(" * DAY 8* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[2] = tm1;
team9[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[1] = tm1;
team10[1] = tm2;

//day9    ******************************************************************************************************************
printf(" * DAY 9* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[3] = tm1;
team10[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[2] = tm1;
team8[2] = tm2;

//day10    ******************************************************************************************************************
printf(" * DAY 10* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[3] = tm1;
team9[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[3] = tm1;
team10[3] = tm2;

//day11    ******************************************************************************************************************
printf(" * DAY 11 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team1A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team1A, &tm1 ,&tm2);

team11[0] = tm1;
team1[8] = 0;
//day12    ******************************************************************************************************************
printf(" * DAY 12 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[1] = tm1;
team2[8] = 0;
//day13    ******************************************************************************************************************
printf(" * DAY 13 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team3A, &tm1 ,&tm2);

team11[2] = tm1;
team3[8] = 0;
//day14    ******************************************************************************************************************
printf(" * DAY 14 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team4A, &tm1 ,&tm2);

team11[3] = tm1;
team4[8] = 0;
//day15    ******************************************************************************************************************
printf(" * DAY 15 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team3A, &tm1 ,&tm2);

team12[0] = tm1;
team3[8] = 0;
//day16    ******************************************************************************************************************
printf(" * DAY 16 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team4A, &tm1 ,&tm2);

team12[1] = tm1;
team4[8] = 0;
//day17    ******************************************************************************************************************
printf(" * DAY 17 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team5A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team5A, &tm1 ,&tm2);

team12[2] = tm1;
team5[8] = 0;
//day18    ******************************************************************************************************************
printf(" * DAY 18 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team8A, &tm1 ,&tm2);

team12[3] = tm1;
team8[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 19 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team8A, &tm1 ,&tm2);

team13[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 20 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team2A, &tm1 ,&tm2);

team13[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 21 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team7A, &tm1 ,&tm2);

team13[2] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 23 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team6A, &tm1 ,&tm2);

team13[3] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 24 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team8A, &tm1 ,&tm2);

team14[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 25 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team2A, &tm1 ,&tm2);

team14[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 26 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team7A, &tm1 ,&tm2);

team14[2] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 27 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team6A, &tm1 ,&tm2);

team14[3] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 28 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team8A, &tm1 ,&tm2);

team15[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 29 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team2A, &tm1 ,&tm2);

team15[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 30 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team7A, &tm1 ,&tm2);

team15[2] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 31 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team6A, &tm1 ,&tm2);

team15[3] = tm1;
team6[8] = 0;
































 sleep(2);

// final round ***********************************************************************
printf(ANSI_COLOR_YELLOW " ********** The Final Round  ********** \n"ANSI_COLOR_RESET);
printf("* this is the last chance for each team in this tournament * \n");
printf(" so mister %s Who do you think will win this tournament? \n",user);

fgets(vd,50,stdin);
fgets(vd,50,stdin);


printf(" so team %s we will see\n",vd);
printf(" **********************************************************************************************************\n");

//day 1
printf(" commenatator : Ladies and gentleman, thank you so much for attending especially our guest of honor  %s , we heard he was %s  last week we hope he doing better \n" ,user , conv);
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team2A ,team3A ,team4A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[4] = tm1;
team2[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[4] = tm1;
team4[4] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2 * \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[5] = tm1;
team3[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[5] = tm1;
team5[4] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[6] = tm1;
team4[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[5] = tm1;
team5[5] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[7] = tm1;
team5[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[6] = tm1;
team3[6] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[7] = tm1;
team4[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[7] = tm1;
team5[7] = tm2;


//day6    ******************************************************************************************************************
printf(" * DAY 6* \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team1A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team1A, &tm1 ,&tm2);

team11[4] = tm1;
team1[8] = 0;










//DAY 7     ******************************************************************************************************************

printf(" * DAY 7* \n");


printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[4] = tm1;
team7[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team8[4] = tm1;
team9[4] = tm2;


//day8    ******************************************************************************************************************
printf(" * DAY 8 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[5] = tm1;
team2[8] = 0;



//day9      ******************************************************************************************************************
printf(" * DAY 9 * \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[5] = tm1;
team8[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team9A ,team10A, &tm1 ,&tm2);

team9[5] = tm1;
team10[4] = tm2;
//day10    ******************************************************************************************************************
printf(" * DAY 10 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[6] = tm1;
team2[8] = 0;


//day11    ******************************************************************************************************************
printf(" * DAY 11* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[6] = tm1;
team9[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[5] = tm1;
team10[5] = tm2;

//day12    ******************************************************************************************************************
printf(" * DAY 12* \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team3A, &tm1 ,&tm2);

team11[7] = tm1;
team3[8] = 0;

//day13   ******************************************************************************************************************
printf(" * DAY 13* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[7] = tm1;
team10[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[6] = tm1;
team8[6] = tm2;

//day14    ******************************************************************************************************************
printf(" * DAY 14* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[7] = tm1;
team9[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[7] = tm1;
team10[7] = tm2;
//day15    ******************************************************************************************************************
printf(" * DAY 15 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team3A, &tm1 ,&tm2);

team12[4] = tm1;
team3[8] = 0;
//day16    ******************************************************************************************************************
printf(" * DAY 16 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team4A, &tm1 ,&tm2);

team12[5] = tm1;
team4[8] = 0;
//day17    ******************************************************************************************************************
printf(" * DAY 17 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team5A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team5A, &tm1 ,&tm2);

team12[6] = tm1;
team5[8] = 0;
//day18    ******************************************************************************************************************
printf(" * DAY 18 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team8A, &tm1 ,&tm2);

team12[7] = tm1;
team8[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 19 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team8A, &tm1 ,&tm2);

team13[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 20 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team2A, &tm1 ,&tm2);

team13[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 21 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team7A, &tm1 ,&tm2);

team13[6] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 23 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team6A, &tm1 ,&tm2);

team13[7] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 24 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team8A, &tm1 ,&tm2);

team14[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 25 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team2A, &tm1 ,&tm2);

team14[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 26 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team7A, &tm1 ,&tm2);

team14[6] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 27 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team6A, &tm1 ,&tm2);

team14[7] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 28 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team8A, &tm1 ,&tm2);

team15[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 29 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team2A, &tm1 ,&tm2);

team15[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 30 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team7A, &tm1 ,&tm2);

team15[6] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 31 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team6A, &tm1 ,&tm2);

team15[7] = tm1;
team6[8] = 0;






for( int i=0 ; i<=7 ; i++ ){
  team1b= team1[i] + team1b;

}

for( int i=0 ; i<=7 ; i++ ){
  team2b= team2[i]+ team2b;

}

for( int i=0 ; i<=7 ; i++ ){
  team3b= team3[i]+ team3b;

}

for( int i=0 ; i<=7 ; i++ ){
  team4b= team4[i]+ team4b;

}

for( int i=0 ; i<=7 ; i++ ){
  team5b= team5[i]+ team5b;

}

for( int i=0 ; i<=7 ; i++ ){
  team6b= team6[i]+ team6b;

}

for( int i=0 ; i<=7 ; i++ ){
  team7b= team7[i]+ team7b;

}

for( int i=0 ; i<=7 ; i++ ){
  team8b= team8[i]+ team8b;

}


for( int i=0 ; i<=7 ; i++ ){
  team9b= team9[i]+ team9b;

}

for( int i=0 ; i<=7 ; i++ ){
  team10b= team10[i]+ team10b;

}
for( int i=0 ; i<=7 ; i++ ){
  team11b= team11[i]+ team11b;

}
for( int i=0 ; i<=7 ; i++ ){
  team12b= team12[i]+ team12b;

}
for( int i=0 ; i<=7 ; i++ ){
  team13b= team13[i]+ team13b;

}
for( int i=0 ; i<=7 ; i++ ){
  team14b= team14[i]+ team14b;

}
for( int i=0 ; i<=7 ; i++ ){
  team15b= team15[i]+ team15b;

}
int cs[15];
cs[0] = team1b;
cs[1] = team2b;
cs[2] = team3b;
cs[3] = team4b;
cs[4] = team5b;
cs[5] = team6b;
cs[6] = team7b;
cs[7] = team8b;
cs[8] = team9b;
cs[9] = team10b;
cs[10] = team11b;
cs[11] = team12b;
cs[12] = team13b;
cs[13] = team14b;
cs[14] = team15b;
int n=15;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (cs[j] < cs[j + 1]) {
                // Swap cs[j] and cs[j + 1]
                int temp = cs[j];
                cs[j] = cs[j + 1];
                cs[j + 1] = temp;
            }
        }
    }

  strcpy(teams[0].name, team1A);
 strcpy(teams[1].name, team2A);
 strcpy(teams[2].name, team3A);
 strcpy(teams[3].name, team4A);
 strcpy(teams[4].name, team5A);
 strcpy(teams[5].name, team6A);
 strcpy(teams[6].name, team7A);
 strcpy(teams[7].name, team8A);
 strcpy(teams[8].name, team9A);
  strcpy(teams[9].name, team10A);
    strcpy(teams[10].name, team11A);
  strcpy(teams[11].name, team12A);
strcpy(teams[12].name, team13A);
strcpy(teams[13].name, team14A);
strcpy(teams[14].name, team15A);

teams[0].points = team1b ;
teams[1].points = team2b ;
 teams[2].points = team3b ;
teams[3].points = team4b ;
teams[4].points = team5b ;
teams[5].points = team6b ;
teams[6].points = team7b ;
teams[7].points = team8b ;
teams[8].points = team9b ;
teams[9].points = team10b ;
teams[10].points = team11b ;
teams[11].points = team12b ;
    teams[12].points = team13b ;
 teams[13].points = team14b ;
teams[14].points = team15b ;

  sortTeams(NT, teams);     
        
    printDecorativeTable(NT, teams);

printf( BLUE_TEXT" so did your team %s win ?" RESET_TEXT ,vd );




























                     }



















































                     else if (NT==16){  char teamA[50];  char team1A [50];    char team2A [50];    char team3A [50];    char team4A [50];    char team5A [50];    char team6A [50];    char team7A [50];    char team8A [50];    char team9A [50];    char team10A [50];    char team11A [50];    char team12A [50];    char team13A [50];    char team14A [50];    char team15A [50];    char team16A [50];    printf("input the name of your teams one by one:\n");fgets(teamA,50,stdin);     fgets(team1A,50,stdin);    fgets(team2A,50,stdin);    fgets(team3A,50,stdin);    fgets(team4A,50,stdin);    fgets(team5A,50,stdin);    fgets(team6A,50,stdin);    fgets(team7A,50,stdin);    fgets(team8A,50,stdin);    fgets(team9A,50,stdin);    fgets(team10A,50,stdin);    fgets(team11A,50,stdin);    fgets(team12A,50,stdin);    fgets(team13A,50,stdin);    fgets(team14A,50,stdin);    fgets(team15A,50,stdin);    fgets(team16A,50,stdin);    int team1 [50];    int team2 [50];    int team3 [50];    int team4 [50];    int team5 [50];    int team6 [50];    int team7 [50];    int team8 [50];    fgets(team16A,50,stdin);    int team9 [50];    int team10 [50];    int team11 [50];    int team12 [50];    int team13 [50];    int team14 [50];    int team15 [50];    int team16 [50];
                   
        printf(" Hello user :)  \n");
   sleep(2);
        printf(" are you feeling good today ? tell me about your day : ^_^ ") ;
         fgets(conv,2000,stdin);
            sleep(2);
        printf(" omg wow, at least you're doing good!!, keep it up \n");
           sleep(2);
printf("btw i am 'MESSI' your assistant into this tournament :) \n");
   sleep(2);
   printf(ANSI_COLOR_YELLOW" we will start this tournament with a LOT of games ,I hope it will be competitive this season \n "ANSI_COLOR_RESET);
     sleep(2);
   printf(" press enter key to start : \n");
   fgets(vd,50,stdin);
      sleep(2);
  printf(ANSI_COLOR_GREEN" LETS START ^o^ \n"ANSI_COLOR_RESET);
   sleep(2);

  //DAY 1     ******************************************************************************************************************

    printf(YELLOW "@@@@@@@                     .,***,,...   ...,,***,.                    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      . . . . .,./,,****,,..   ..,,****,,/.*.    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . .   .    ,*/***,,.. ..,,**//*,.   /      .   .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                 /    .*///**,,....,**///*.    *                %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . . . . ...    ,///**,,...,**////*  . /    . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . . .(   .*///**,...,*//((/.   (. .      .        %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                    ,(, ./((/**,.,*//((/. */.                   %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@  .      . . . . .     ./,/((/****/((((/,. . . .    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      .    ,((/**/((#, . . .          . . .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                              (/*/#                             %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . .   . . .    . . . . (*(    .   . .      . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . .        . . . (*(    . . .     .      . .   .  %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                             ,//,*/.                            %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      .   . . .    .   **#.,,,.,,#*,    . . .    . .   . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      . #%##%,/  ....*,%%#(.. . . .    .  . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                        #%##%,/  .*.%%%(###%(      ...                %@@@@@@@@\n");
     usleep(300000);
    printf(RESET);

    printf("\033[0;34m");  // Code ANSI pour la couleur bleue

    printf("____    __    ____  _______  __        ______   ______   .___  ___.  _______ \n");
     usleep(2000000);
    printf("\\   \\  /  \\  /   / |   ____||  |      /      | /  __  \\  |   \\/   | |   ____|\n");
     usleep(2000000);
    printf(" \\   \\/    \\/   /  |  |__   |  |     |  ,----'|  |  |  | |  \\  /  | |  |__   \n");
     usleep(2000000);
    printf("  \\            /   |   __|  |  |     |  |     |  |  |  | |  |\\/|  | |   __|  \n");
     usleep(2000000);
    printf("   \\    /\\    /    |  |____ |  `----.|  `----.|  `--'  | |  |  |  | |  |____ \n");
     usleep(2000000);
    printf("    \\__/  \\__/     |_______||_______| \\______| \\______/  |__|  |__| |_______|\n");
 usleep(2000000);
    printf("\033[0m");  // Réinitialisation de la couleur




printf(" ************************************ DAY 1************************************ \n");
printf(" Commenatator : Ladies and gentlemen, thank you so much for attending especially our guest of honor  'enter your name' ");
 fgets(user,50,stdin);
   sleep(2);
printf(" sir %s great honor to see you \n" ,user);
  sleep(2);








printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team2A ,team3A ,team4A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[0] = tm1;
team2[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[0] = tm1;
team4[0] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[1] = tm1;
team3[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[1] = tm1;
team5[0] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[2] = tm1;
team4[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[1] = tm1;
team5[1] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[3] = tm1;
team5[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[2] = tm1;
team3[2] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[3] = tm1;
team4[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[3] = tm1;
team5[3] = tm2;













//DAY 6     ******************************************************************************************************************

printf(" * DAY 6* \n");


printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[0] = tm1;
team7[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team9A, &tm1 ,&tm2);

team8[0] = tm1;
team9[0] = tm2;





//day7      ******************************************************************************************************************
printf(" * DAY 7* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf("* First  match *\n");

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[1] = tm1;
team8[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team9[1] = tm1;
team10[0] = tm2;

//day8    ******************************************************************************************************************
printf(" * DAY 8* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[2] = tm1;
team9[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[1] = tm1;
team10[1] = tm2;

//day9    ******************************************************************************************************************
printf(" * DAY 9* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[3] = tm1;
team10[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[2] = tm1;
team8[2] = tm2;

//day10    ******************************************************************************************************************
printf(" * DAY 10* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[3] = tm1;
team9[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[3] = tm1;
team10[3] = tm2;

//day11    ******************************************************************************************************************
printf(" * DAY 11 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team1A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team1A, &tm1 ,&tm2);

team11[0] = tm1;
team1[8] = 0;
//day12    ******************************************************************************************************************
printf(" * DAY 12 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[1] = tm1;
team2[8] = 0;
//day13    ******************************************************************************************************************
printf(" * DAY 13 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team3A, &tm1 ,&tm2);

team11[2] = tm1;
team3[8] = 0;
//day14    ******************************************************************************************************************
printf(" * DAY 14 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team4A, &tm1 ,&tm2);

team11[3] = tm1;
team4[8] = 0;
//day15    ******************************************************************************************************************
printf(" * DAY 15 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team3A, &tm1 ,&tm2);

team12[0] = tm1;
team3[8] = 0;
//day16    ******************************************************************************************************************
printf(" * DAY 16 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team4A, &tm1 ,&tm2);

team12[1] = tm1;
team4[8] = 0;
//day17    ******************************************************************************************************************
printf(" * DAY 17 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team5A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team5A, &tm1 ,&tm2);

team12[2] = tm1;
team5[8] = 0;
//day18    ******************************************************************************************************************
printf(" * DAY 18 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team8A, &tm1 ,&tm2);

team12[3] = tm1;
team8[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 19 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team8A, &tm1 ,&tm2);

team13[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 20 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team2A, &tm1 ,&tm2);

team13[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 21 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team7A, &tm1 ,&tm2);

team13[2] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 23 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team6A, &tm1 ,&tm2);

team13[3] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 24 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team8A, &tm1 ,&tm2);

team14[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 25 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team2A, &tm1 ,&tm2);

team14[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 26 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team7A, &tm1 ,&tm2);

team14[2] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 27 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team6A, &tm1 ,&tm2);

team14[3] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 28 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team8A, &tm1 ,&tm2);

team15[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 29 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team2A, &tm1 ,&tm2);

team15[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 30 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team7A, &tm1 ,&tm2);

team15[2] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 31 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team6A, &tm1 ,&tm2);

team15[3] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 28 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team8A, &tm1 ,&tm2);

team16[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 29 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team2A, &tm1 ,&tm2);

team16[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 30 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team7A, &tm1 ,&tm2);

team16[2] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 31 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team6A, &tm1 ,&tm2);

team16[3] = tm1;
team6[8] = 0;






























 sleep(2);



// final round ***********************************************************************
printf(ANSI_COLOR_YELLOW " ********** The Final Round  ********** \n"ANSI_COLOR_RESET);
printf("* this is the last chance for each team in this tournament * \n");
printf(" so mister %s Who do you think will win this tournament? \n",user);

fgets(vd,50,stdin);
fgets(vd,50,stdin);


printf(" so team %s we will see\n",vd);
printf(" **********************************************************************************************************\n");

//day 1
printf(" commenatator : Ladies and gentleman, thank you so much for attending especially our guest of honor  %s , we heard he was %s  last week we hope he doing better \n" ,user , conv);
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team2A ,team3A ,team4A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[4] = tm1;
team2[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[4] = tm1;
team4[4] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2 * \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[5] = tm1;
team3[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[5] = tm1;
team5[4] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[6] = tm1;
team4[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[5] = tm1;
team5[5] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[7] = tm1;
team5[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[6] = tm1;
team3[6] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[7] = tm1;
team4[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[7] = tm1;
team5[7] = tm2;


//day6    ******************************************************************************************************************
printf(" * DAY 6* \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team1A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team1A, &tm1 ,&tm2);

team11[4] = tm1;
team1[8] = 0;










//DAY 7     ******************************************************************************************************************

printf(" * DAY 7* \n");


printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[4] = tm1;
team7[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team8[4] = tm1;
team9[4] = tm2;


//day8    ******************************************************************************************************************
printf(" * DAY 8 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[5] = tm1;
team2[8] = 0;



//day9      ******************************************************************************************************************
printf(" * DAY 9 * \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[5] = tm1;
team8[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team9A ,team10A, &tm1 ,&tm2);

team9[5] = tm1;
team10[4] = tm2;
//day10    ******************************************************************************************************************
printf(" * DAY 10 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[6] = tm1;
team2[8] = 0;


//day11    ******************************************************************************************************************
printf(" * DAY 11* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[6] = tm1;
team9[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[5] = tm1;
team10[5] = tm2;

//day12    ******************************************************************************************************************
printf(" * DAY 12* \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team3A, &tm1 ,&tm2);

team11[7] = tm1;
team3[8] = 0;

//day13   ******************************************************************************************************************
printf(" * DAY 13* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[7] = tm1;
team10[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[6] = tm1;
team8[6] = tm2;

//day14    ******************************************************************************************************************
printf(" * DAY 14* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[7] = tm1;
team9[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[7] = tm1;
team10[7] = tm2;
//day15    ******************************************************************************************************************
printf(" * DAY 15 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team3A, &tm1 ,&tm2);

team12[4] = tm1;
team3[8] = 0;
//day16    ******************************************************************************************************************
printf(" * DAY 16 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team4A, &tm1 ,&tm2);

team12[5] = tm1;
team4[8] = 0;
//day17    ******************************************************************************************************************
printf(" * DAY 17 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team5A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team5A, &tm1 ,&tm2);

team12[6] = tm1;
team5[8] = 0;
//day18    ******************************************************************************************************************
printf(" * DAY 18 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team8A, &tm1 ,&tm2);

team12[7] = tm1;
team8[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 19 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team8A, &tm1 ,&tm2);

team13[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 20 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team2A, &tm1 ,&tm2);

team13[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 21 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team7A, &tm1 ,&tm2);

team13[6] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 23 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team6A, &tm1 ,&tm2);

team13[7] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 24 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team8A, &tm1 ,&tm2);

team14[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 25 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team2A, &tm1 ,&tm2);

team14[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 26 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team7A, &tm1 ,&tm2);

team14[6] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 27 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team6A, &tm1 ,&tm2);

team14[7] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 28 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team8A, &tm1 ,&tm2);

team15[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 29 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team2A, &tm1 ,&tm2);

team15[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 30 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team7A, &tm1 ,&tm2);

team15[6] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 31 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team6A, &tm1 ,&tm2);

team15[7] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 32 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team8A, &tm1 ,&tm2);

team16[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 33 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team2A, &tm1 ,&tm2);

team16[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 34 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team7A, &tm1 ,&tm2);

team16[6] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 35 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team6A, &tm1 ,&tm2);

team16[7] = tm1;
team6[8] = 0;





for( int i=0 ; i<=7 ; i++ ){
  team1b= team1[i] + team1b;

}

for( int i=0 ; i<=7 ; i++ ){
  team2b= team2[i]+ team2b;

}

for( int i=0 ; i<=7 ; i++ ){
  team3b= team3[i]+ team3b;

}

for( int i=0 ; i<=7 ; i++ ){
  team4b= team4[i]+ team4b;

}

for( int i=0 ; i<=7 ; i++ ){
  team5b= team5[i]+ team5b;

}

for( int i=0 ; i<=7 ; i++ ){
  team6b= team6[i]+ team6b;

}

for( int i=0 ; i<=7 ; i++ ){
  team7b= team7[i]+ team7b;

}

for( int i=0 ; i<=7 ; i++ ){
  team8b= team8[i]+ team8b;

}


for( int i=0 ; i<=7 ; i++ ){
  team9b= team9[i]+ team9b;

}

for( int i=0 ; i<=7 ; i++ ){
  team10b= team10[i]+ team10b;

}
for( int i=0 ; i<=7 ; i++ ){
  team11b= team11[i]+ team11b;

}
for( int i=0 ; i<=7 ; i++ ){
  team12b= team12[i]+ team12b;

}
for( int i=0 ; i<=7 ; i++ ){
  team13b= team13[i]+ team13b;

}
for( int i=0 ; i<=7 ; i++ ){
  team14b= team14[i]+ team14b;

}
for( int i=0 ; i<=7 ; i++ ){
  team15b= team15[i]+ team15b;

}
for( int i=0 ; i<=7 ; i++ ){
  team16b= team16[i]+ team16b;

}
int cs[16];
cs[0] = team1b;
cs[1] = team2b;
cs[2] = team3b;
cs[3] = team4b;
cs[4] = team5b;
cs[5] = team6b;
cs[6] = team7b;
cs[7] = team8b;
cs[8] = team9b;
cs[9] = team10b;
cs[10] = team11b;
cs[11] = team12b;
cs[12] = team13b;
cs[13] = team14b;
cs[14] = team15b;
cs[15] = team16b;
int n=16;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (cs[j] < cs[j + 1]) {
                // Swap cs[j] and cs[j + 1]
                int temp = cs[j];
                cs[j] = cs[j + 1];
                cs[j + 1] = temp;
            }
        }
    }

  strcpy(teams[0].name, team1A);
 strcpy(teams[1].name, team2A);
 strcpy(teams[2].name, team3A);
 strcpy(teams[3].name, team4A);
 strcpy(teams[4].name, team5A);
 strcpy(teams[5].name, team6A);
 strcpy(teams[6].name, team7A);
 strcpy(teams[7].name, team8A);
 strcpy(teams[8].name, team9A);
  strcpy(teams[9].name, team10A);
    strcpy(teams[10].name, team11A);
  strcpy(teams[11].name, team12A);
strcpy(teams[12].name, team13A);
strcpy(teams[13].name, team14A);
strcpy(teams[14].name, team15A);
strcpy(teams[15].name, team16A);

teams[0].points = team1b ;
teams[1].points = team2b ;
 teams[2].points = team3b ;
teams[3].points = team4b ;
teams[4].points = team5b ;
teams[5].points = team6b ;
teams[6].points = team7b ;
teams[7].points = team8b ;
teams[8].points = team9b ;
teams[9].points = team10b ;
teams[10].points = team11b ;
teams[11].points = team12b ;
    teams[12].points = team13b ;
 teams[13].points = team14b ;
teams[14].points = team15b ;
teams[15].points = team16b ;

  sortTeams(NT, teams);     
        
    printDecorativeTable(NT, teams);




printf( BLUE_TEXT" so did your team %s win ?" RESET_TEXT ,vd );















                       }



















































                         else if (NT==17){ char teamA[50];   char team1A [50];    char team2A [50];    char team3A [50];    char team4A [50];    char team5A [50];    char team6A [50];    char team7A [50];    char team8A [50];    char team9A [50];    char team10A [50];    char team11A [50];    char team12A [50];    char team13A [50];    char team14A [50];    char team15A [50];    char team16A [50];    char team17A [50];    printf("input the name of your teams one by one:\n");  fgets(teamA,50,stdin);   fgets(team1A,50,stdin);    fgets(team2A,50,stdin);    fgets(team3A,50,stdin);    fgets(team4A,50,stdin);    fgets(team5A,50,stdin);    fgets(team6A,50,stdin);    fgets(team7A,50,stdin);    fgets(team8A,50,stdin);    fgets(team9A,50,stdin);    fgets(team10A,50,stdin);    fgets(team11A,50,stdin);    fgets(team12A,50,stdin);    fgets(team13A,50,stdin);    fgets(team14A,50,stdin);    fgets(team15A,50,stdin);    fgets(team16A,50,stdin);    fgets(team17A,50,stdin);    int team1 [50];    int team2 [50];    int team3 [50];    int team4 [50];    int team5 [50];    int team6 [50];    int team7 [50];    int team8 [50];    fgets(team17A,50,stdin);    int team9 [50];    int team10 [50];    int team11 [50];    int team12 [50];    int team13 [50];    int team14 [50];    int team15 [50];    int team16 [50];    int team17 [50];
                            
        printf(" Hello user :)  \n");
   sleep(2);
        printf(" are you feeling good today ? tell me about your day : ^_^ ") ;
         fgets(conv,2000,stdin);
            sleep(2);
        printf(" omg wow, at least you're doing good!!, keep it up \n");
           sleep(2);
printf("btw i am 'MESSI' your assistant into this tournament :) \n");
   sleep(2);
   printf(ANSI_COLOR_YELLOW" we will start this tournament with a LOT of games ,I hope it will be competitive this season \n "ANSI_COLOR_RESET);
     sleep(2);
   printf(" press enter key to start : \n");
   fgets(vd,50,stdin);
      sleep(2);
  printf(ANSI_COLOR_GREEN" LETS START ^o^ \n"ANSI_COLOR_RESET);
   sleep(2);

  //DAY 1     ******************************************************************************************************************

    printf(YELLOW "@@@@@@@                     .,***,,...   ...,,***,.                    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      . . . . .,./,,****,,..   ..,,****,,/.*.    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . .   .    ,*/***,,.. ..,,**//*,.   /      .   .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                 /    .*///**,,....,**///*.    *                %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . . . . ...    ,///**,,...,**////*  . /    . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . . .(   .*///**,...,*//((/.   (. .      .        %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                    ,(, ./((/**,.,*//((/. */.                   %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@  .      . . . . .     ./,/((/****/((((/,. . . .    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      .    ,((/**/((#, . . .          . . .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                              (/*/#                             %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . .   . . .    . . . . (*(    .   . .      . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . .        . . . (*(    . . .     .      . .   .  %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                             ,//,*/.                            %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      .   . . .    .   **#.,,,.,,#*,    . . .    . .   . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      . #%##%,/  ....*,%%#(.. . . .    .  . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                        #%##%,/  .*.%%%(###%(      ...                %@@@@@@@@\n");
     usleep(300000);
    printf(RESET);

    printf("\033[0;34m");  // Code ANSI pour la couleur bleue

    printf("____    __    ____  _______  __        ______   ______   .___  ___.  _______ \n");
     usleep(2000000);
    printf("\\   \\  /  \\  /   / |   ____||  |      /      | /  __  \\  |   \\/   | |   ____|\n");
     usleep(2000000);
    printf(" \\   \\/    \\/   /  |  |__   |  |     |  ,----'|  |  |  | |  \\  /  | |  |__   \n");
     usleep(2000000);
    printf("  \\            /   |   __|  |  |     |  |     |  |  |  | |  |\\/|  | |   __|  \n");
     usleep(2000000);
    printf("   \\    /\\    /    |  |____ |  `----.|  `----.|  `--'  | |  |  |  | |  |____ \n");
     usleep(2000000);
    printf("    \\__/  \\__/     |_______||_______| \\______| \\______/  |__|  |__| |_______|\n");
 usleep(2000000);
    printf("\033[0m");  // Réinitialisation de la couleur




printf(" ************************************ DAY 1************************************ \n");
printf(" Commenatator : Ladies and gentlemen, thank you so much for attending especially our guest of honor  'enter your name' ");
 fgets(user,50,stdin);
   sleep(2);
printf(" sir %s great honor to see you \n" ,user);
  sleep(2);








printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team2A ,team3A ,team4A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[0] = tm1;
team2[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[0] = tm1;
team4[0] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[1] = tm1;
team3[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[1] = tm1;
team5[0] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[2] = tm1;
team4[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[1] = tm1;
team5[1] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[3] = tm1;
team5[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[2] = tm1;
team3[2] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[3] = tm1;
team4[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[3] = tm1;
team5[3] = tm2;













//DAY 6     ******************************************************************************************************************

printf(" * DAY 6* \n");


printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[0] = tm1;
team7[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team9A, &tm1 ,&tm2);

team8[0] = tm1;
team9[0] = tm2;





//day7      ******************************************************************************************************************
printf(" * DAY 7* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf("* First  match *\n");

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[1] = tm1;
team8[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team9[1] = tm1;
team10[0] = tm2;

//day8    ******************************************************************************************************************
printf(" * DAY 8* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[2] = tm1;
team9[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[1] = tm1;
team10[1] = tm2;

//day9    ******************************************************************************************************************
printf(" * DAY 9* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[3] = tm1;
team10[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[2] = tm1;
team8[2] = tm2;

//day10    ******************************************************************************************************************
printf(" * DAY 10* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[3] = tm1;
team9[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[3] = tm1;
team10[3] = tm2;

//day11    ******************************************************************************************************************
printf(" * DAY 11 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team1A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team1A, &tm1 ,&tm2);

team11[0] = tm1;
team1[8] = 0;
//day12    ******************************************************************************************************************
printf(" * DAY 12 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[1] = tm1;
team2[8] = 0;
//day13    ******************************************************************************************************************
printf(" * DAY 13 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team3A, &tm1 ,&tm2);

team11[2] = tm1;
team3[8] = 0;
//day14    ******************************************************************************************************************
printf(" * DAY 14 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team4A, &tm1 ,&tm2);

team11[3] = tm1;
team4[8] = 0;
//day15    ******************************************************************************************************************
printf(" * DAY 15 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team3A, &tm1 ,&tm2);

team12[0] = tm1;
team3[8] = 0;
//day16    ******************************************************************************************************************
printf(" * DAY 16 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team4A, &tm1 ,&tm2);

team12[1] = tm1;
team4[8] = 0;
//day17    ******************************************************************************************************************
printf(" * DAY 17 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team5A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team5A, &tm1 ,&tm2);

team12[2] = tm1;
team5[8] = 0;
//day18    ******************************************************************************************************************
printf(" * DAY 18 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team8A, &tm1 ,&tm2);

team12[3] = tm1;
team8[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 19 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team8A, &tm1 ,&tm2);

team13[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 20 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team2A, &tm1 ,&tm2);

team13[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 21 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team7A, &tm1 ,&tm2);

team13[2] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 23 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team6A, &tm1 ,&tm2);

team13[3] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 24 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team8A, &tm1 ,&tm2);

team14[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 25 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team2A, &tm1 ,&tm2);

team14[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 26 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team7A, &tm1 ,&tm2);

team14[2] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 27 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team6A, &tm1 ,&tm2);

team14[3] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 28 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team8A, &tm1 ,&tm2);

team15[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 29 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team2A, &tm1 ,&tm2);

team15[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 30 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team7A, &tm1 ,&tm2);

team15[2] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 31 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team6A, &tm1 ,&tm2);

team15[3] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 32 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team8A, &tm1 ,&tm2);

team16[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 33 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team2A, &tm1 ,&tm2);

team16[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 34 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team7A, &tm1 ,&tm2);

team16[2] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 35 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team6A, &tm1 ,&tm2);

team16[3] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 36 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team8A, &tm1 ,&tm2);

team17[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 37 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team2A, &tm1 ,&tm2);

team17[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 38 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team7A, &tm1 ,&tm2);

team17[2] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 39 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team6A, &tm1 ,&tm2);

team17[3] = tm1;
team6[8] = 0;






























 sleep(2);

// final round ***********************************************************************
printf(ANSI_COLOR_YELLOW " ********** The Final Round  ********** \n"ANSI_COLOR_RESET);
printf("* this is the last chance for each team in this tournament * \n");
printf(" so mister %s Who do you think will win this tournament? \n",user);

fgets(vd,50,stdin);
fgets(vd,50,stdin);


printf(" so team %s we will see\n",vd);
printf(" **********************************************************************************************************\n");

//day 1
printf(" commenatator : Ladies and gentleman, thank you so much for attending especially our guest of honor  %s , we heard he was %s  last week we hope he doing better \n" ,user , conv);
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team2A ,team3A ,team4A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[4] = tm1;
team2[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[4] = tm1;
team4[4] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2 * \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[5] = tm1;
team3[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[5] = tm1;
team5[4] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[6] = tm1;
team4[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[5] = tm1;
team5[5] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[7] = tm1;
team5[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[6] = tm1;
team3[6] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[7] = tm1;
team4[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[7] = tm1;
team5[7] = tm2;


//day6    ******************************************************************************************************************
printf(" * DAY 6* \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team1A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team1A, &tm1 ,&tm2);

team11[4] = tm1;
team1[8] = 0;










//DAY 7     ******************************************************************************************************************

printf(" * DAY 7* \n");


printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[4] = tm1;
team7[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team8[4] = tm1;
team9[4] = tm2;


//day8    ******************************************************************************************************************
printf(" * DAY 8 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[5] = tm1;
team2[8] = 0;



//day9      ******************************************************************************************************************
printf(" * DAY 9 * \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[5] = tm1;
team8[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team9A ,team10A, &tm1 ,&tm2);

team9[5] = tm1;
team10[4] = tm2;
//day10    ******************************************************************************************************************
printf(" * DAY 10 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[6] = tm1;
team2[8] = 0;


//day11    ******************************************************************************************************************
printf(" * DAY 11* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[6] = tm1;
team9[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[5] = tm1;
team10[5] = tm2;

//day12    ******************************************************************************************************************
printf(" * DAY 12* \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team3A, &tm1 ,&tm2);

team11[7] = tm1;
team3[8] = 0;

//day13   ******************************************************************************************************************
printf(" * DAY 13* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[7] = tm1;
team10[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[6] = tm1;
team8[6] = tm2;

//day14    ******************************************************************************************************************
printf(" * DAY 14* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[7] = tm1;
team9[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[7] = tm1;
team10[7] = tm2;
//day15    ******************************************************************************************************************
printf(" * DAY 15 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team3A, &tm1 ,&tm2);

team12[4] = tm1;
team3[8] = 0;
//day16    ******************************************************************************************************************
printf(" * DAY 16 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team4A, &tm1 ,&tm2);

team12[5] = tm1;
team4[8] = 0;
//day17    ******************************************************************************************************************
printf(" * DAY 17 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team5A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team5A, &tm1 ,&tm2);

team12[6] = tm1;
team5[8] = 0;
//day18    ******************************************************************************************************************
printf(" * DAY 18 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team8A, &tm1 ,&tm2);

team12[7] = tm1;
team8[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 19 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team8A, &tm1 ,&tm2);

team13[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 20 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team2A, &tm1 ,&tm2);

team13[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 21 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team7A, &tm1 ,&tm2);

team13[6] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 23 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team6A, &tm1 ,&tm2);

team13[7] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 24 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team8A, &tm1 ,&tm2);

team14[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 25 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team2A, &tm1 ,&tm2);

team14[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 26 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team7A, &tm1 ,&tm2);

team14[6] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 27 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team6A, &tm1 ,&tm2);

team14[7] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 28 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team8A, &tm1 ,&tm2);

team15[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 29 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team2A, &tm1 ,&tm2);

team15[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 30 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team7A, &tm1 ,&tm2);

team15[6] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 31 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team6A, &tm1 ,&tm2);

team15[7] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 32 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team8A, &tm1 ,&tm2);

team16[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 33 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team2A, &tm1 ,&tm2);

team16[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 34 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team7A, &tm1 ,&tm2);

team16[6] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 35 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team6A, &tm1 ,&tm2);

team16[7] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 36 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team8A, &tm1 ,&tm2);

team17[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 37 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team2A, &tm1 ,&tm2);

team17[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 38 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team7A, &tm1 ,&tm2);

team17[6] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 39 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team6A, &tm1 ,&tm2);

team17[7] = tm1;
team6[8] = 0;




for( int i=0 ; i<=7 ; i++ ){
  team1b= team1[i] + team1b;

}

for( int i=0 ; i<=7 ; i++ ){
  team2b= team2[i]+ team2b;

}

for( int i=0 ; i<=7 ; i++ ){
  team3b= team3[i]+ team3b;

}

for( int i=0 ; i<=7 ; i++ ){
  team4b= team4[i]+ team4b;

}

for( int i=0 ; i<=7 ; i++ ){
  team5b= team5[i]+ team5b;

}

for( int i=0 ; i<=7 ; i++ ){
  team6b= team6[i]+ team6b;

}

for( int i=0 ; i<=7 ; i++ ){
  team7b= team7[i]+ team7b;

}

for( int i=0 ; i<=7 ; i++ ){
  team8b= team8[i]+ team8b;

}


for( int i=0 ; i<=7 ; i++ ){
  team9b= team9[i]+ team9b;

}

for( int i=0 ; i<=7 ; i++ ){
  team10b= team10[i]+ team10b;

}
for( int i=0 ; i<=7 ; i++ ){
  team11b= team11[i]+ team11b;

}
for( int i=0 ; i<=7 ; i++ ){
  team12b= team12[i]+ team12b;

}
for( int i=0 ; i<=7 ; i++ ){
  team13b= team13[i]+ team13b;

}
for( int i=0 ; i<=7 ; i++ ){
  team14b= team14[i]+ team14b;

}
for( int i=0 ; i<=7 ; i++ ){
  team15b= team15[i]+ team15b;

}
for( int i=0 ; i<=7 ; i++ ){
  team16b= team16[i]+ team16b;

}
for( int i=0 ; i<=7 ; i++ ){
  team17b= team17[i]+ team17b;

}
int cs[17];
cs[0] = team1b;
cs[1] = team2b;
cs[2] = team3b;
cs[3] = team4b;
cs[4] = team5b;
cs[5] = team6b;
cs[6] = team7b;
cs[7] = team8b;
cs[8] = team9b;
cs[9] = team10b;
cs[10] = team11b;
cs[11] = team12b;
cs[12] = team13b;
cs[13] = team14b;
cs[14] = team15b;
cs[15] = team16b;
cs[16] = team17b;
int n=17;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (cs[j] < cs[j + 1]) {
                // Swap cs[j] and cs[j + 1]
                int temp = cs[j];
                cs[j] = cs[j + 1];
                cs[j + 1] = temp;
            }
        }
    }

  strcpy(teams[0].name, team1A);
 strcpy(teams[1].name, team2A);
 strcpy(teams[2].name, team3A);
 strcpy(teams[3].name, team4A);
 strcpy(teams[4].name, team5A);
 strcpy(teams[5].name, team6A);
 strcpy(teams[6].name, team7A);
 strcpy(teams[7].name, team8A);
 strcpy(teams[8].name, team9A);
  strcpy(teams[9].name, team10A);
    strcpy(teams[10].name, team11A);
  strcpy(teams[11].name, team12A);
strcpy(teams[12].name, team13A);
strcpy(teams[13].name, team14A);
strcpy(teams[14].name, team15A);
strcpy(teams[15].name, team16A);
strcpy(teams[16].name, team17A);

teams[0].points = team1b ;
teams[1].points = team2b ;
 teams[2].points = team3b ;
teams[3].points = team4b ;
teams[4].points = team5b ;
teams[5].points = team6b ;
teams[6].points = team7b ;
teams[7].points = team8b ;
teams[8].points = team9b ;
teams[9].points = team10b ;
teams[10].points = team11b ;
teams[11].points = team12b ;
    teams[12].points = team13b ;
 teams[13].points = team14b ;
teams[14].points = team15b ;
teams[15].points = team16b ;
teams[16].points = team17b ;

  sortTeams(NT, teams);     
        
    printDecorativeTable(NT, teams);


printf( BLUE_TEXT" so did your team %s win ?" RESET_TEXT ,vd );






























                            }



















































                           else if (NT==18){  char teamA[50];  char team1A [50];    char team2A [50];    char team3A [50];    char team4A [50];    char team5A [50];    char team6A [50];    char team7A [50];    char team8A [50];    char team9A [50];    char team10A [50];    char team11A [50];    char team12A [50];    char team13A [50];    char team14A [50];    char team15A [50];    char team16A [50];    char team17A [50];    char team18A [50];    printf("input the name of your teams one by one:\n");  fgets(teamA,50,stdin);   fgets(team1A,50,stdin);    fgets(team2A,50,stdin);    fgets(team3A,50,stdin);    fgets(team4A,50,stdin);    fgets(team5A,50,stdin);    fgets(team6A,50,stdin);    fgets(team7A,50,stdin);    fgets(team8A,50,stdin);    fgets(team9A,50,stdin);    fgets(team10A,50,stdin);    fgets(team11A,50,stdin);    fgets(team12A,50,stdin);    fgets(team13A,50,stdin);    fgets(team14A,50,stdin);    fgets(team15A,50,stdin);    fgets(team16A,50,stdin);    fgets(team17A,50,stdin);    fgets(team18A,50,stdin);    int team1 [50];    int team2 [50];    int team3 [50];    int team4 [50];    int team5 [50];    int team6 [50];    int team7 [50];    int team8 [50];    fgets(team18A,50,stdin);    int team9 [50];    int team10 [50];    int team11 [50];    int team12 [50];    int team13 [50];    int team14 [50];    int team15 [50];    int team16 [50];    int team17 [50];    int team18 [50];
                                      
        printf(" Hello user :)  \n");
   sleep(2);
        printf(" are you feeling good today ? tell me about your day : ^_^ ") ;
         fgets(conv,2000,stdin);
            sleep(2);
        printf(" omg wow, at least you're doing good!!, keep it up \n");
           sleep(2);
printf("btw i am 'MESSI' your assistant into this tournament :) \n");
   sleep(2);
   printf(ANSI_COLOR_YELLOW" we will start this tournament with a LOT of games ,I hope it will be competitive this season \n "ANSI_COLOR_RESET);
     sleep(2);
   printf(" press enter key to start : \n");
   fgets(vd,50,stdin);
      sleep(2);
  printf(ANSI_COLOR_GREEN" LETS START ^o^ \n"ANSI_COLOR_RESET);
   sleep(2);

  //DAY 1     ******************************************************************************************************************

    printf(YELLOW "@@@@@@@                     .,***,,...   ...,,***,.                    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      . . . . .,./,,****,,..   ..,,****,,/.*.    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . .   .    ,*/***,,.. ..,,**//*,.   /      .   .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                 /    .*///**,,....,**///*.    *                %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . . . . ...    ,///**,,...,**////*  . /    . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . . .(   .*///**,...,*//((/.   (. .      .        %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                    ,(, ./((/**,.,*//((/. */.                   %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@  .      . . . . .     ./,/((/****/((((/,. . . .    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      .    ,((/**/((#, . . .          . . .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                              (/*/#                             %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . .   . . .    . . . . (*(    .   . .      . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . .        . . . (*(    . . .     .      . .   .  %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                             ,//,*/.                            %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      .   . . .    .   **#.,,,.,,#*,    . . .    . .   . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      . #%##%,/  ....*,%%#(.. . . .    .  . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                        #%##%,/  .*.%%%(###%(      ...                %@@@@@@@@\n");
     usleep(300000);
    printf(RESET);

    printf("\033[0;34m");  // Code ANSI pour la couleur bleue

    printf("____    __    ____  _______  __        ______   ______   .___  ___.  _______ \n");
     usleep(2000000);
    printf("\\   \\  /  \\  /   / |   ____||  |      /      | /  __  \\  |   \\/   | |   ____|\n");
     usleep(2000000);
    printf(" \\   \\/    \\/   /  |  |__   |  |     |  ,----'|  |  |  | |  \\  /  | |  |__   \n");
     usleep(2000000);
    printf("  \\            /   |   __|  |  |     |  |     |  |  |  | |  |\\/|  | |   __|  \n");
     usleep(2000000);
    printf("   \\    /\\    /    |  |____ |  `----.|  `----.|  `--'  | |  |  |  | |  |____ \n");
     usleep(2000000);
    printf("    \\__/  \\__/     |_______||_______| \\______| \\______/  |__|  |__| |_______|\n");
 usleep(2000000);
    printf("\033[0m");  // Réinitialisation de la couleur




printf(" ************************************ DAY 1************************************ \n");
printf(" Commenatator : Ladies and gentlemen, thank you so much for attending especially our guest of honor  'enter your name' ");
 fgets(user,50,stdin);
   sleep(2);
printf(" sir %s great honor to see you \n" ,user);
  sleep(2);







printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team2A ,team3A ,team4A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[0] = tm1;
team2[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[0] = tm1;
team4[0] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[1] = tm1;
team3[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[1] = tm1;
team5[0] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[2] = tm1;
team4[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[1] = tm1;
team5[1] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[3] = tm1;
team5[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[2] = tm1;
team3[2] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[3] = tm1;
team4[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[3] = tm1;
team5[3] = tm2;













//DAY 6     ******************************************************************************************************************

printf(" * DAY 6* \n");


printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[0] = tm1;
team7[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team9A, &tm1 ,&tm2);

team8[0] = tm1;
team9[0] = tm2;





//day7      ******************************************************************************************************************
printf(" * DAY 7* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf("* First  match *\n");

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[1] = tm1;
team8[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team9[1] = tm1;
team10[0] = tm2;

//day8    ******************************************************************************************************************
printf(" * DAY 8* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[2] = tm1;
team9[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[1] = tm1;
team10[1] = tm2;

//day9    ******************************************************************************************************************
printf(" * DAY 9* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[3] = tm1;
team10[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[2] = tm1;
team8[2] = tm2;

//day10    ******************************************************************************************************************
printf(" * DAY 10* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[3] = tm1;
team9[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[3] = tm1;
team10[3] = tm2;

//day11    ******************************************************************************************************************
printf(" * DAY 11 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team1A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team1A, &tm1 ,&tm2);

team11[0] = tm1;
team1[8] = 0;
//day12    ******************************************************************************************************************
printf(" * DAY 12 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[1] = tm1;
team2[8] = 0;
//day13    ******************************************************************************************************************
printf(" * DAY 13 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team3A, &tm1 ,&tm2);

team11[2] = tm1;
team3[8] = 0;
//day14    ******************************************************************************************************************
printf(" * DAY 14 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team4A, &tm1 ,&tm2);

team11[3] = tm1;
team4[8] = 0;
//day15    ******************************************************************************************************************
printf(" * DAY 15 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team3A, &tm1 ,&tm2);

team12[0] = tm1;
team3[8] = 0;
//day16    ******************************************************************************************************************
printf(" * DAY 16 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team4A, &tm1 ,&tm2);

team12[1] = tm1;
team4[8] = 0;
//day17    ******************************************************************************************************************
printf(" * DAY 17 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team5A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team5A, &tm1 ,&tm2);

team12[2] = tm1;
team5[8] = 0;
//day18    ******************************************************************************************************************
printf(" * DAY 18 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team8A, &tm1 ,&tm2);

team12[3] = tm1;
team8[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 19 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team8A, &tm1 ,&tm2);

team13[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 20 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team2A, &tm1 ,&tm2);

team13[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 21 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team7A, &tm1 ,&tm2);

team13[2] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 23 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team6A, &tm1 ,&tm2);

team13[3] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 24 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team8A, &tm1 ,&tm2);

team14[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 25 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team2A, &tm1 ,&tm2);

team14[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 26 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team7A, &tm1 ,&tm2);

team14[2] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 27 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team6A, &tm1 ,&tm2);

team14[3] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 28 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team8A, &tm1 ,&tm2);

team15[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 29 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team2A, &tm1 ,&tm2);

team15[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 30 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team7A, &tm1 ,&tm2);

team15[2] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 31 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team6A, &tm1 ,&tm2);

team15[3] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 32 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team8A, &tm1 ,&tm2);

team16[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 33 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team2A, &tm1 ,&tm2);

team16[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 34 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team7A, &tm1 ,&tm2);

team16[2] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 35 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team6A, &tm1 ,&tm2);

team16[3] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 36 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team8A, &tm1 ,&tm2);

team17[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 37 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team2A, &tm1 ,&tm2);

team17[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 38 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team7A, &tm1 ,&tm2);

team17[2] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 39 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team6A, &tm1 ,&tm2);

team17[3] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 40 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team8A, &tm1 ,&tm2);

team18[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 41 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team2A, &tm1 ,&tm2);

team18[1] = tm1;
team2[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 42 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team7A, &tm1 ,&tm2);

team18[2] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 43 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team6A, &tm1 ,&tm2);

team18[3] = tm1;
team6[8] = 0;


























 sleep(2);




// final round ***********************************************************************
printf(ANSI_COLOR_YELLOW " ********** The Final Round  ********** \n"ANSI_COLOR_RESET);
printf("* this is the last chance for each team in this tournament * \n");
printf(" so mister %s Who do you think will win this tournament? \n",user);

fgets(vd,50,stdin);
fgets(vd,50,stdin);


printf(" so team %s we will see\n",vd);
printf(" **********************************************************************************************************\n");

//day 1
printf(" commenatator : Ladies and gentleman, thank you so much for attending especially our guest of honor  %s , we heard he was %s  last week we hope he doing better \n" ,user , conv);
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team2A ,team3A ,team4A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[4] = tm1;
team2[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[4] = tm1;
team4[4] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2 * \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[5] = tm1;
team3[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[5] = tm1;
team5[4] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[6] = tm1;
team4[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[5] = tm1;
team5[5] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[7] = tm1;
team5[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[6] = tm1;
team3[6] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[7] = tm1;
team4[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[7] = tm1;
team5[7] = tm2;


//day6    ******************************************************************************************************************
printf(" * DAY 6* \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team1A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team1A, &tm1 ,&tm2);

team11[4] = tm1;
team1[8] = 0;










//DAY 7     ******************************************************************************************************************

printf(" * DAY 7* \n");


printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[4] = tm1;
team7[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team8[4] = tm1;
team9[4] = tm2;


//day8    ******************************************************************************************************************
printf(" * DAY 8 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[5] = tm1;
team2[8] = 0;



//day9      ******************************************************************************************************************
printf(" * DAY 9 * \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[5] = tm1;
team8[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team9A ,team10A, &tm1 ,&tm2);

team9[5] = tm1;
team10[4] = tm2;
//day10    ******************************************************************************************************************
printf(" * DAY 10 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[6] = tm1;
team2[8] = 0;


//day11    ******************************************************************************************************************
printf(" * DAY 11* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[6] = tm1;
team9[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[5] = tm1;
team10[5] = tm2;

//day12    ******************************************************************************************************************
printf(" * DAY 12* \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team3A, &tm1 ,&tm2);

team11[7] = tm1;
team3[8] = 0;

//day13   ******************************************************************************************************************
printf(" * DAY 13* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[7] = tm1;
team10[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[6] = tm1;
team8[6] = tm2;

//day14    ******************************************************************************************************************
printf(" * DAY 14* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[7] = tm1;
team9[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[7] = tm1;
team10[7] = tm2;
//day15    ******************************************************************************************************************
printf(" * DAY 15 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team3A, &tm1 ,&tm2);

team12[4] = tm1;
team3[8] = 0;
//day16    ******************************************************************************************************************
printf(" * DAY 16 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team4A, &tm1 ,&tm2);

team12[5] = tm1;
team4[8] = 0;
//day17    ******************************************************************************************************************
printf(" * DAY 17 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team5A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team5A, &tm1 ,&tm2);

team12[6] = tm1;
team5[8] = 0;
//day18    ******************************************************************************************************************
printf(" * DAY 18 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team8A, &tm1 ,&tm2);

team12[7] = tm1;
team8[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 19 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team8A, &tm1 ,&tm2);

team13[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 20 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team2A, &tm1 ,&tm2);

team13[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 21 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team7A, &tm1 ,&tm2);

team13[6] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 23 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team6A, &tm1 ,&tm2);

team13[7] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 24 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team8A, &tm1 ,&tm2);

team14[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 25 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team2A, &tm1 ,&tm2);

team14[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 26 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team7A, &tm1 ,&tm2);

team14[6] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 27 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team6A, &tm1 ,&tm2);

team14[7] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 28 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team8A, &tm1 ,&tm2);

team15[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 29 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team2A, &tm1 ,&tm2);

team15[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 30 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team7A, &tm1 ,&tm2);

team15[6] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 31 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team6A, &tm1 ,&tm2);

team15[7] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 28 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team8A, &tm1 ,&tm2);

team16[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 29 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team2A, &tm1 ,&tm2);

team16[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 30 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team7A, &tm1 ,&tm2);

team16[6] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 31 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team6A, &tm1 ,&tm2);

team16[7] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 36 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team8A, &tm1 ,&tm2);

team17[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 37 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team2A, &tm1 ,&tm2);

team17[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 38 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team7A, &tm1 ,&tm2);

team17[6] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 39 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team6A, &tm1 ,&tm2);

team17[7] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 40 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team8A, &tm1 ,&tm2);

team18[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 41 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team2A, &tm1 ,&tm2);

team18[5] = tm1;
team2[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 42 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team7A, &tm1 ,&tm2);

team18[6] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 43 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team6A, &tm1 ,&tm2);

team18[7] = tm1;
team6[8] = 0;



for( int i=0 ; i<=7 ; i++ ){
  team1b= team1[i] + team1b;

}

for( int i=0 ; i<=7 ; i++ ){
  team2b= team2[i]+ team2b;

}

for( int i=0 ; i<=7 ; i++ ){
  team3b= team3[i]+ team3b;

}

for( int i=0 ; i<=7 ; i++ ){
  team4b= team4[i]+ team4b;

}

for( int i=0 ; i<=7 ; i++ ){
  team5b= team5[i]+ team5b;

}

for( int i=0 ; i<=7 ; i++ ){
  team6b= team6[i]+ team6b;

}

for( int i=0 ; i<=7 ; i++ ){
  team7b= team7[i]+ team7b;

}

for( int i=0 ; i<=7 ; i++ ){
  team8b= team8[i]+ team8b;

}


for( int i=0 ; i<=7 ; i++ ){
  team9b= team9[i]+ team9b;

}

for( int i=0 ; i<=7 ; i++ ){
  team10b= team10[i]+ team10b;

}
for( int i=0 ; i<=7 ; i++ ){
  team11b= team11[i]+ team11b;

}
for( int i=0 ; i<=7 ; i++ ){
  team12b= team12[i]+ team12b;

}
for( int i=0 ; i<=7 ; i++ ){
  team13b= team13[i]+ team13b;

}
for( int i=0 ; i<=7 ; i++ ){
  team14b= team14[i]+ team14b;

}
for( int i=0 ; i<=7 ; i++ ){
  team15b= team15[i]+ team15b;

}
for( int i=0 ; i<=7 ; i++ ){
  team16b= team16[i]+ team16b;

}
for( int i=0 ; i<=7 ; i++ ){
  team17b= team17[i]+ team17b;

}
for( int i=0 ; i<=7 ; i++ ){
  team18b= team18[i]+ team18b;

}
int cs[18];
cs[0] = team1b;
cs[1] = team2b;
cs[2] = team3b;
cs[3] = team4b;
cs[4] = team5b;
cs[5] = team6b;
cs[6] = team7b;
cs[7] = team8b;
cs[8] = team9b;
cs[9] = team10b;
cs[10] = team11b;
cs[11] = team12b;
cs[12] = team13b;
cs[13] = team14b;
cs[14] = team15b;
cs[15] = team16b;
cs[16] = team17b;
cs[17] = team18b;
int n=18;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (cs[j] < cs[j + 1]) {
                // Swap cs[j] and cs[j + 1]
                int temp = cs[j];
                cs[j] = cs[j + 1];
                cs[j + 1] = temp;
            }
        }
    }

  strcpy(teams[0].name, team1A);
 strcpy(teams[1].name, team2A);
 strcpy(teams[2].name, team3A);
 strcpy(teams[3].name, team4A);
 strcpy(teams[4].name, team5A);
 strcpy(teams[5].name, team6A);
 strcpy(teams[6].name, team7A);
 strcpy(teams[7].name, team8A);
 strcpy(teams[8].name, team9A);
  strcpy(teams[9].name, team10A);
    strcpy(teams[10].name, team11A);
  strcpy(teams[11].name, team12A);
strcpy(teams[12].name, team13A);
strcpy(teams[13].name, team14A);
strcpy(teams[14].name, team15A);
strcpy(teams[15].name, team16A);
strcpy(teams[16].name, team17A);
strcpy(teams[17].name, team18A);

teams[0].points = team1b ;
teams[1].points = team2b ;
 teams[2].points = team3b ;
teams[3].points = team4b ;
teams[4].points = team5b ;
teams[5].points = team6b ;
teams[6].points = team7b ;
teams[7].points = team8b ;
teams[8].points = team9b ;
teams[9].points = team10b ;
teams[10].points = team11b ;
teams[11].points = team12b ;
    teams[12].points = team13b ;
 teams[13].points = team14b ;
teams[14].points = team15b ;
teams[15].points = team16b ;
teams[16].points = team17b ;
teams[17].points = team18b ;

  sortTeams(NT, teams);     
        
    printDecorativeTable(NT, teams);







printf( BLUE_TEXT" so did your team %s win ?" RESET_TEXT ,vd );






























                              }



















































                             else if (NT==19){   char teamA[50]; char team1A [50];    char team2A [50];    char team3A [50];    char team4A [50];    char team5A [50];    char team6A [50];    char team7A [50];    char team8A [50];    char team9A [50];    char team10A [50];    char team11A [50];    char team12A [50];    char team13A [50];    char team14A [50];    char team15A [50];    char team16A [50];    char team17A [50];    char team18A [50];    char team19A [50];    printf("input the name of your teams one by one:\n"); fgets(teamA,50,stdin);    fgets(team1A,50,stdin);    fgets(team2A,50,stdin);    fgets(team3A,50,stdin);    fgets(team4A,50,stdin);    fgets(team5A,50,stdin);    fgets(team6A,50,stdin);    fgets(team7A,50,stdin);    fgets(team8A,50,stdin);    fgets(team9A,50,stdin);    fgets(team10A,50,stdin);    fgets(team11A,50,stdin);    fgets(team12A,50,stdin);    fgets(team13A,50,stdin);    fgets(team14A,50,stdin);    fgets(team15A,50,stdin);    fgets(team16A,50,stdin);    fgets(team17A,50,stdin);    fgets(team18A,50,stdin);    fgets(team19A,50,stdin);    int team1 [50];    int team2 [50];    int team3 [50];    int team4 [50];    int team5 [50];    int team6 [50];    int team7 [50];    int team8 [50];    int team9 [50];    fgets(team19A,50,stdin);    int team10 [50];    int team11 [50];    int team12 [50];    int team13 [50];    int team14 [50];    int team15 [50];    int team16 [50];    int team17 [50];    int team18 [50];    int team19 [50];
                  
        printf(" Hello user :)  \n");
   sleep(2);
        printf(" are you feeling good today ? tell me about your day : ^_^ ") ;
         fgets(conv,2000,stdin);
            sleep(2);
        printf(" omg wow, at least you're doing good!!, keep it up \n");
           sleep(2);
printf("btw i am 'MESSI' your assistant into this tournament :) \n");
   sleep(2);
   printf(ANSI_COLOR_YELLOW" we will start this tournament with a LOT of games ,I hope it will be competitive this season \n "ANSI_COLOR_RESET);
     sleep(2);
   printf(" press enter key to start : \n");
   fgets(vd,50,stdin);
      sleep(2);
  printf(ANSI_COLOR_GREEN" LETS START ^o^ \n"ANSI_COLOR_RESET);
   sleep(2);

  //DAY 1     ******************************************************************************************************************

    printf(YELLOW "@@@@@@@                     .,***,,...   ...,,***,.                    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      . . . . .,./,,****,,..   ..,,****,,/.*.    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . .   .    ,*/***,,.. ..,,**//*,.   /      .   .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                 /    .*///**,,....,**///*.    *                %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . . . . ...    ,///**,,...,**////*  . /    . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . . .(   .*///**,...,*//((/.   (. .      .        %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                    ,(, ./((/**,.,*//((/. */.                   %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@  .      . . . . .     ./,/((/****/((((/,. . . .    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      .    ,((/**/((#, . . .          . . .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                              (/*/#                             %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . .   . . .    . . . . (*(    .   . .      . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . .        . . . (*(    . . .     .      . .   .  %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                             ,//,*/.                            %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      .   . . .    .   **#.,,,.,,#*,    . . .    . .   . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      . #%##%,/  ....*,%%#(.. . . .    .  . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                        #%##%,/  .*.%%%(###%(      ...                %@@@@@@@@\n");
     usleep(300000);
    printf(RESET);

    printf("\033[0;34m");  // Code ANSI pour la couleur bleue

    printf("____    __    ____  _______  __        ______   ______   .___  ___.  _______ \n");
     usleep(2000000);
    printf("\\   \\  /  \\  /   / |   ____||  |      /      | /  __  \\  |   \\/   | |   ____|\n");
     usleep(2000000);
    printf(" \\   \\/    \\/   /  |  |__   |  |     |  ,----'|  |  |  | |  \\  /  | |  |__   \n");
     usleep(2000000);
    printf("  \\            /   |   __|  |  |     |  |     |  |  |  | |  |\\/|  | |   __|  \n");
     usleep(2000000);
    printf("   \\    /\\    /    |  |____ |  `----.|  `----.|  `--'  | |  |  |  | |  |____ \n");
     usleep(2000000);
    printf("    \\__/  \\__/     |_______||_______| \\______| \\______/  |__|  |__| |_______|\n");
 usleep(2000000);
    printf("\033[0m");  // Réinitialisation de la couleur




printf(" ************************************ DAY 1************************************ \n");
printf(" Commenatator : Ladies and gentlemen, thank you so much for attending especially our guest of honor  'enter your name' ");
 fgets(user,50,stdin);
   sleep(2);
printf(" sir %s great honor to see you \n" ,user);
  sleep(2);








printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team2A ,team3A ,team4A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[0] = tm1;
team2[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[0] = tm1;
team4[0] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[1] = tm1;
team3[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[1] = tm1;
team5[0] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[2] = tm1;
team4[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[1] = tm1;
team5[1] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[3] = tm1;
team5[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[2] = tm1;
team3[2] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[3] = tm1;
team4[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[3] = tm1;
team5[3] = tm2;













//DAY 6     ******************************************************************************************************************

printf(" * DAY 6* \n");


printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[0] = tm1;
team7[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team9A, &tm1 ,&tm2);

team8[0] = tm1;
team9[0] = tm2;





//day7      ******************************************************************************************************************
printf(" * DAY 7* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf("* First  match *\n");

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[1] = tm1;
team8[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team9[1] = tm1;
team10[0] = tm2;

//day8    ******************************************************************************************************************
printf(" * DAY 8* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[2] = tm1;
team9[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[1] = tm1;
team10[1] = tm2;

//day9    ******************************************************************************************************************
printf(" * DAY 9* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[3] = tm1;
team10[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[2] = tm1;
team8[2] = tm2;

//day10    ******************************************************************************************************************
printf(" * DAY 10* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[3] = tm1;
team9[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[3] = tm1;
team10[3] = tm2;

//day11    ******************************************************************************************************************
printf(" * DAY 11 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team1A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team1A, &tm1 ,&tm2);

team11[0] = tm1;
team1[8] = 0;
//day12    ******************************************************************************************************************
printf(" * DAY 12 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[1] = tm1;
team2[8] = 0;
//day13    ******************************************************************************************************************
printf(" * DAY 13 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team3A, &tm1 ,&tm2);

team11[2] = tm1;
team3[8] = 0;
//day14    ******************************************************************************************************************
printf(" * DAY 14 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team4A, &tm1 ,&tm2);

team11[3] = tm1;
team4[8] = 0;
//day15    ******************************************************************************************************************
printf(" * DAY 15 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team3A, &tm1 ,&tm2);

team12[0] = tm1;
team3[8] = 0;
//day16    ******************************************************************************************************************
printf(" * DAY 16 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team4A, &tm1 ,&tm2);

team12[1] = tm1;
team4[8] = 0;
//day17    ******************************************************************************************************************
printf(" * DAY 17 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team5A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team5A, &tm1 ,&tm2);

team12[2] = tm1;
team5[8] = 0;
//day18    ******************************************************************************************************************
printf(" * DAY 18 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team8A, &tm1 ,&tm2);

team12[3] = tm1;
team8[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 19 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team8A, &tm1 ,&tm2);

team13[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 20 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team2A, &tm1 ,&tm2);

team13[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 21 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team7A, &tm1 ,&tm2);

team13[2] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 23 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team6A, &tm1 ,&tm2);

team13[3] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 24 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team8A, &tm1 ,&tm2);

team14[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 25 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team2A, &tm1 ,&tm2);

team14[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 26 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team7A, &tm1 ,&tm2);

team14[2] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 27 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team6A, &tm1 ,&tm2);

team14[3] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 28 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team8A, &tm1 ,&tm2);

team15[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 29 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team2A, &tm1 ,&tm2);

team15[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 30 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team7A, &tm1 ,&tm2);

team15[2] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 31 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team6A, &tm1 ,&tm2);

team15[3] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 32 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team8A, &tm1 ,&tm2);

team16[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 33 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team2A, &tm1 ,&tm2);

team16[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 34 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team7A, &tm1 ,&tm2);

team16[2] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 35 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team6A, &tm1 ,&tm2);

team16[3] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 36 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team8A, &tm1 ,&tm2);

team17[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 37 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team2A, &tm1 ,&tm2);

team17[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 38 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team7A, &tm1 ,&tm2);

team17[2] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 39 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team6A, &tm1 ,&tm2);

team17[3] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 40 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team8A, &tm1 ,&tm2);

team18[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 41 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team2A, &tm1 ,&tm2);

team18[1] = tm1;
team2[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 42 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team7A, &tm1 ,&tm2);

team18[2] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 43 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team6A, &tm1 ,&tm2);

team18[3] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 44 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team19A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team19A ,team8A, &tm1 ,&tm2);

team19[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 45 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team19A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team19A ,team2A, &tm1 ,&tm2);

team19[1] = tm1;
team2[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 46 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team19A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team19A ,team7A, &tm1 ,&tm2);

team19[2] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 47 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team19A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team19A ,team6A, &tm1 ,&tm2);

team19[3] = tm1;
team6[8] = 0;

























 sleep(2);




// final round ***********************************************************************
printf(ANSI_COLOR_YELLOW " ********** The Final Round  ********** \n"ANSI_COLOR_RESET);
printf("* this is the last chance for each team in this tournament * \n");
printf(" so mister %s Who do you think will win this tournament? \n",user);

fgets(vd,50,stdin);
fgets(vd,50,stdin);


printf(" so team %s we will see\n",vd);
printf(" **********************************************************************************************************\n");

//day 1
printf(" commenatator : Ladies and gentleman, thank you so much for attending especially our guest of honor  %s , we heard he was %s  last week we hope he doing better \n" ,user , conv);
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team2A ,team3A ,team4A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[4] = tm1;
team2[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[4] = tm1;
team4[4] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2 * \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[5] = tm1;
team3[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[5] = tm1;
team5[4] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[6] = tm1;
team4[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[5] = tm1;
team5[5] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[7] = tm1;
team5[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[6] = tm1;
team3[6] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[7] = tm1;
team4[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[7] = tm1;
team5[7] = tm2;


//day6    ******************************************************************************************************************
printf(" * DAY 6* \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team1A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team1A, &tm1 ,&tm2);

team11[4] = tm1;
team1[8] = 0;










//DAY 7     ******************************************************************************************************************

printf(" * DAY 7* \n");


printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[4] = tm1;
team7[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team8[4] = tm1;
team9[4] = tm2;


//day8    ******************************************************************************************************************
printf(" * DAY 8 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[5] = tm1;
team2[8] = 0;



//day9      ******************************************************************************************************************
printf(" * DAY 9 * \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[5] = tm1;
team8[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team9A ,team10A, &tm1 ,&tm2);

team9[5] = tm1;
team10[4] = tm2;
//day10    ******************************************************************************************************************
printf(" * DAY 10 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[6] = tm1;
team2[8] = 0;


//day11    ******************************************************************************************************************
printf(" * DAY 11* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[6] = tm1;
team9[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[5] = tm1;
team10[5] = tm2;

//day12    ******************************************************************************************************************
printf(" * DAY 12* \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team3A, &tm1 ,&tm2);

team11[7] = tm1;
team3[8] = 0;

//day13   ******************************************************************************************************************
printf(" * DAY 13* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[7] = tm1;
team10[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[6] = tm1;
team8[6] = tm2;

//day14    ******************************************************************************************************************
printf(" * DAY 14* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[7] = tm1;
team9[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[7] = tm1;
team10[7] = tm2;
//day15    ******************************************************************************************************************
printf(" * DAY 15 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team3A, &tm1 ,&tm2);

team12[4] = tm1;
team3[8] = 0;
//day16    ******************************************************************************************************************
printf(" * DAY 16 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team4A, &tm1 ,&tm2);

team12[5] = tm1;
team4[8] = 0;
//day17    ******************************************************************************************************************
printf(" * DAY 17 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team5A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team5A, &tm1 ,&tm2);

team12[6] = tm1;
team5[8] = 0;
//day18    ******************************************************************************************************************
printf(" * DAY 18 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team8A, &tm1 ,&tm2);

team12[7] = tm1;
team8[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 19 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team8A, &tm1 ,&tm2);

team13[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 20 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team2A, &tm1 ,&tm2);

team13[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 21 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team7A, &tm1 ,&tm2);

team13[6] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 23 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team6A, &tm1 ,&tm2);

team13[7] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 24 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team8A, &tm1 ,&tm2);

team14[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 25 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team2A, &tm1 ,&tm2);

team14[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 26 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team7A, &tm1 ,&tm2);

team14[6] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 27 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team6A, &tm1 ,&tm2);

team14[7] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 28 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team8A, &tm1 ,&tm2);

team15[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 29 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team2A, &tm1 ,&tm2);

team15[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 30 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team7A, &tm1 ,&tm2);

team15[6] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 31 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team6A, &tm1 ,&tm2);

team15[7] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 28 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team8A, &tm1 ,&tm2);

team16[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 29 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team2A, &tm1 ,&tm2);

team16[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 30 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team7A, &tm1 ,&tm2);

team16[6] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 31 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team6A, &tm1 ,&tm2);

team16[7] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 36 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team8A, &tm1 ,&tm2);

team17[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 37 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team2A, &tm1 ,&tm2);

team17[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 38 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team7A, &tm1 ,&tm2);

team17[6] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 39 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team6A, &tm1 ,&tm2);

team17[7] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 40 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team8A, &tm1 ,&tm2);

team18[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 41 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team2A, &tm1 ,&tm2);

team18[5] = tm1;
team2[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 42 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team7A, &tm1 ,&tm2);

team18[6] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 43 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team6A, &tm1 ,&tm2);

team18[7] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 44 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team19A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team19A ,team8A, &tm1 ,&tm2);

team19[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 45 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team19A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team19A ,team2A, &tm1 ,&tm2);

team19[5] = tm1;
team2[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 46 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team19A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team19A ,team7A, &tm1 ,&tm2);

team19[6] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 47 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team19A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team19A ,team6A, &tm1 ,&tm2);

team19[7] = tm1;
team6[8] = 0;

for( int i=0 ; i<=7 ; i++ ){
  team1b= team1[i] + team1b;

}

for( int i=0 ; i<=7 ; i++ ){
  team2b= team2[i]+ team2b;

}

for( int i=0 ; i<=7 ; i++ ){
  team3b= team3[i]+ team3b;

}

for( int i=0 ; i<=7 ; i++ ){
  team4b= team4[i]+ team4b;

}

for( int i=0 ; i<=7 ; i++ ){
  team5b= team5[i]+ team5b;

}

for( int i=0 ; i<=7 ; i++ ){
  team6b= team6[i]+ team6b;

}

for( int i=0 ; i<=7 ; i++ ){
  team7b= team7[i]+ team7b;

}

for( int i=0 ; i<=7 ; i++ ){
  team8b= team8[i]+ team8b;

}


for( int i=0 ; i<=7 ; i++ ){
  team9b= team9[i]+ team9b;

}

for( int i=0 ; i<=7 ; i++ ){
  team10b= team10[i]+ team10b;

}
for( int i=0 ; i<=7 ; i++ ){
  team11b= team11[i]+ team11b;

}
for( int i=0 ; i<=7 ; i++ ){
  team12b= team12[i]+ team12b;

}
for( int i=0 ; i<=7 ; i++ ){
  team13b= team13[i]+ team13b;

}
for( int i=0 ; i<=7 ; i++ ){
  team14b= team14[i]+ team14b;

}
for( int i=0 ; i<=7 ; i++ ){
  team15b= team15[i]+ team15b;

}
for( int i=0 ; i<=7 ; i++ ){
  team16b= team16[i]+ team16b;

}
for( int i=0 ; i<=7 ; i++ ){
  team17b= team17[i]+ team17b;

}
for( int i=0 ; i<=7 ; i++ ){
  team18b= team18[i]+ team18b;

}
for( int i=0 ; i<=7 ; i++ ){
  team19b= team19[i]+ team19b;

}
int cs[19];
cs[0] = team1b;
cs[1] = team2b;
cs[2] = team3b;
cs[3] = team4b;
cs[4] = team5b;
cs[5] = team6b;
cs[6] = team7b;
cs[7] = team8b;
cs[8] = team9b;
cs[9] = team10b;
cs[10] = team11b;
cs[11] = team12b;
cs[12] = team13b;
cs[13] = team14b;
cs[14] = team15b;
cs[15] = team16b;
cs[16] = team17b;
cs[17] = team18b;
cs[18] = team19b;
int n=19;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (cs[j] < cs[j + 1]) {
                // Swap cs[j] and cs[j + 1]
                int temp = cs[j];
                cs[j] = cs[j + 1];
                cs[j + 1] = temp;
            }
        }
    }


  strcpy(teams[0].name, team1A);
 strcpy(teams[1].name, team2A);
 strcpy(teams[2].name, team3A);
 strcpy(teams[3].name, team4A);
 strcpy(teams[4].name, team5A);
 strcpy(teams[5].name, team6A);
 strcpy(teams[6].name, team7A);
 strcpy(teams[7].name, team8A);
 strcpy(teams[8].name, team9A);
  strcpy(teams[9].name, team10A);
    strcpy(teams[10].name, team11A);
  strcpy(teams[11].name, team12A);
strcpy(teams[12].name, team13A);
strcpy(teams[13].name, team14A);
strcpy(teams[14].name, team15A);
strcpy(teams[15].name, team16A);
strcpy(teams[16].name, team17A);
strcpy(teams[17].name, team18A);
strcpy(teams[18].name, team19A);

teams[0].points = team1b ;
teams[1].points = team2b ;
 teams[2].points = team3b ;
teams[3].points = team4b ;
teams[4].points = team5b ;
teams[5].points = team6b ;
teams[6].points = team7b ;
teams[7].points = team8b ;
teams[8].points = team9b ;
teams[9].points = team10b ;
teams[10].points = team11b ;
teams[11].points = team12b ;
    teams[12].points = team13b ;
 teams[13].points = team14b ;
teams[14].points = team15b ;
teams[15].points = team16b ;
teams[16].points = team17b ;
teams[17].points = team18b ;
teams[18].points = team19b ;

  sortTeams(NT, teams);     
        
    printDecorativeTable(NT, teams);









printf( BLUE_TEXT" so did your team %s win ?" RESET_TEXT ,vd );






















                                }



















































                                else{  char teamA[50];  char team1A [50];    char team2A [50];    char team3A [50];    char team4A [50];    char team5A [50];    char team6A [50];    char team7A [50];    char team8A [50];    char team9A [50];    char team10A [50];    char team11A [50];    char team12A [50];    char team13A [50];    char team14A [50];    char team15A [50];    char team16A [50];    char team17A [50];    char team18A [50];    char team19A [50];    char team20A [50];    printf("input the name of your teams one by one:\n"); fgets(teamA,50,stdin);    fgets(team1A,50,stdin);    fgets(team2A,50,stdin);    fgets(team3A,50,stdin);    fgets(team4A,50,stdin);    fgets(team5A,50,stdin);    fgets(team6A,50,stdin);    fgets(team7A,50,stdin);    fgets(team8A,50,stdin);    fgets(team9A,50,stdin);    fgets(team10A,50,stdin);    fgets(team11A,50,stdin);    fgets(team12A,50,stdin);    fgets(team13A,50,stdin);    fgets(team14A,50,stdin);    fgets(team15A,50,stdin);    fgets(team16A,50,stdin);    fgets(team17A,50,stdin);    fgets(team18A,50,stdin);    fgets(team19A,50,stdin);    fgets(team20A,50,stdin);    int team1 [50];    int team2 [50];    int team3 [50];    int team4 [50];    int team5 [50];    int team6 [50];    int team7 [50];    int team8 [50];    fgets(team20A,50,stdin);    int team9 [50];    int team10 [50];    int team11 [50];    int team12 [50];    int team13 [50];    int team14 [50];    int team15 [50];    int team16 [50];    int team17 [50];    int team18 [50];    int team19 [50];    int team20 [50];
         
        printf(" Hello user :)  \n");
   sleep(2);
        printf(" are you feeling good today ? tell me about your day : ^_^ ") ;
         fgets(conv,2000,stdin);
            sleep(2);
        printf(" omg wow, at least you're doing good!!, keep it up \n");
           sleep(2);
printf("btw i am 'MESSI' your assistant into this tournament :) \n");
   sleep(2);
   printf(ANSI_COLOR_YELLOW" we will start this tournament with a LOT of games ,I hope it will be competitive this season \n "ANSI_COLOR_RESET);
     sleep(2);
   printf(" press enter key to start : \n");
   fgets(vd,50,stdin);
      sleep(2);
  printf(ANSI_COLOR_GREEN" LETS START ^o^ \n"ANSI_COLOR_RESET);
   sleep(2);

  //DAY 1     ******************************************************************************************************************

    printf(YELLOW "@@@@@@@                     .,***,,...   ...,,***,.                    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      . . . . .,./,,****,,..   ..,,****,,/.*.    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . .   .    ,*/***,,.. ..,,**//*,.   /      .   .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                 /    .*///**,,....,**///*.    *                %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . . . . ...    ,///**,,...,**////*  . /    . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . . .(   .*///**,...,*//((/.   (. .      .        %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                    ,(, ./((/**,.,*//((/. */.                   %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@  .      . . . . .     ./,/((/****/((((/,. . . .    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      .    ,((/**/((#, . . .          . . .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                              (/*/#                             %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . .   . . .    . . . . (*(    .   . .      . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . .        . . . (*(    . . .     .      . .   .  %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                             ,//,*/.                            %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      .   . . .    .   **#.,,,.,,#*,    . . .    . .   . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      . #%##%,/  ....*,%%#(.. . . .    .  . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                        #%##%,/  .*.%%%(###%(      ...                %@@@@@@@@\n");
     usleep(300000);
    printf(RESET);

    printf("\033[0;34m");  // Code ANSI pour la couleur bleue

    printf("____    __    ____  _______  __        ______   ______   .___  ___.  _______ \n");
     usleep(2000000);
    printf("\\   \\  /  \\  /   / |   ____||  |      /      | /  __  \\  |   \\/   | |   ____|\n");
     usleep(2000000);
    printf(" \\   \\/    \\/   /  |  |__   |  |     |  ,----'|  |  |  | |  \\  /  | |  |__   \n");
     usleep(2000000);
    printf("  \\            /   |   __|  |  |     |  |     |  |  |  | |  |\\/|  | |   __|  \n");
     usleep(2000000);
    printf("   \\    /\\    /    |  |____ |  `----.|  `----.|  `--'  | |  |  |  | |  |____ \n");
     usleep(2000000);
    printf("    \\__/  \\__/     |_______||_______| \\______| \\______/  |__|  |__| |_______|\n");
 usleep(2000000);
    printf("\033[0m");  // Réinitialisation de la couleur




printf(" ************************************ DAY 1************************************ \n");
printf(" Commenatator : Ladies and gentlemen, thank you so much for attending especially our guest of honor  'enter your name' ");
 fgets(user,50,stdin);
   sleep(2);
printf(" sir %s great honor to see you \n" ,user);
  sleep(2);








printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team2A ,team3A ,team4A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[0] = tm1;
team2[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[0] = tm1;
team4[0] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[1] = tm1;
team3[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[1] = tm1;
team5[0] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[2] = tm1;
team4[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[1] = tm1;
team5[1] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf("* First  match *\n");

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[3] = tm1;
team5[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[2] = tm1;
team3[2] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[3] = tm1;
team4[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[3] = tm1;
team5[3] = tm2;













//DAY 6     ******************************************************************************************************************

printf(" * DAY 6* \n");


printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[0] = tm1;
team7[0] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team9A, &tm1 ,&tm2);

team8[0] = tm1;
team9[0] = tm2;





//day7      ******************************************************************************************************************
printf(" * DAY 7* \n");
printf(" so today we have 2 matches the first withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf("* First  match *\n");

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[1] = tm1;
team8[1] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team9[1] = tm1;
team10[0] = tm2;

//day8    ******************************************************************************************************************
printf(" * DAY 8* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[2] = tm1;
team9[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[1] = tm1;
team10[1] = tm2;

//day9    ******************************************************************************************************************
printf(" * DAY 9* \n");
printf(" so today we have 2 matches the fist withe %s and %s the 2nd between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[3] = tm1;
team10[2] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[2] = tm1;
team8[2] = tm2;

//day10    ******************************************************************************************************************
printf(" * DAY 10* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[3] = tm1;
team9[3] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[3] = tm1;
team10[3] = tm2;

//day11    ******************************************************************************************************************
printf(" * DAY 11 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team1A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team1A, &tm1 ,&tm2);

team11[0] = tm1;
team1[8] = 0;
//day12    ******************************************************************************************************************
printf(" * DAY 12 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[1] = tm1;
team2[8] = 0;
//day13    ******************************************************************************************************************
printf(" * DAY 13 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team3A, &tm1 ,&tm2);

team11[2] = tm1;
team3[8] = 0;
//day14    ******************************************************************************************************************
printf(" * DAY 14 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team4A, &tm1 ,&tm2);

team11[3] = tm1;
team4[8] = 0;
//day15    ******************************************************************************************************************
printf(" * DAY 15 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team3A, &tm1 ,&tm2);

team12[0] = tm1;
team3[8] = 0;
//day16    ******************************************************************************************************************
printf(" * DAY 16 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team4A, &tm1 ,&tm2);

team12[1] = tm1;
team4[8] = 0;
//day17    ******************************************************************************************************************
printf(" * DAY 17 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team5A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team5A, &tm1 ,&tm2);

team12[2] = tm1;
team5[8] = 0;
//day18    ******************************************************************************************************************
printf(" * DAY 18 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team8A, &tm1 ,&tm2);

team12[3] = tm1;
team8[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 19 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team8A, &tm1 ,&tm2);

team13[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 20 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team2A, &tm1 ,&tm2);

team13[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 21 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team7A, &tm1 ,&tm2);

team13[2] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 23 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team6A, &tm1 ,&tm2);

team13[3] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 24 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team8A, &tm1 ,&tm2);

team14[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 25 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team2A, &tm1 ,&tm2);

team14[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 26 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team7A, &tm1 ,&tm2);

team14[2] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 27 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team6A, &tm1 ,&tm2);

team14[3] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 28 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team8A, &tm1 ,&tm2);

team15[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 29 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team2A, &tm1 ,&tm2);

team15[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 30 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team7A, &tm1 ,&tm2);

team15[2] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 31 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team6A, &tm1 ,&tm2);

team15[3] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 32 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team8A, &tm1 ,&tm2);

team16[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 33 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team2A, &tm1 ,&tm2);

team16[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 34 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team7A, &tm1 ,&tm2);

team16[2] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 35 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team6A, &tm1 ,&tm2);

team16[3] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 36 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team8A, &tm1 ,&tm2);

team17[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 37 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team2A, &tm1 ,&tm2);

team17[1] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 38 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team7A, &tm1 ,&tm2);

team17[2] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 39 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team6A, &tm1 ,&tm2);

team17[3] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 40 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team8A, &tm1 ,&tm2);

team18[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 41 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team2A, &tm1 ,&tm2);

team18[1] = tm1;
team2[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 42 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team7A, &tm1 ,&tm2);

team18[2] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 43 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team6A, &tm1 ,&tm2);

team18[3] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 44 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team19A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team19A ,team8A, &tm1 ,&tm2);

team19[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 45 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team19A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team19A ,team2A, &tm1 ,&tm2);

team19[1] = tm1;
team2[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 46 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team19A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team19A ,team7A, &tm1 ,&tm2);

team19[2] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 47 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team19A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team19A ,team6A, &tm1 ,&tm2);

team19[3] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 48 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team20A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team20A ,team8A, &tm1 ,&tm2);

team20[0] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 49 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team20A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team20A ,team2A, &tm1 ,&tm2);

team20[1] = tm1;
team2[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 50 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team20A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team20A ,team7A, &tm1 ,&tm2);

team20[2] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 51 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team20A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team20A ,team6A, &tm1 ,&tm2);

team20[3] = tm1;
team6[8] = 0;




























sleep(2);

// final round ***********************************************************************
printf(ANSI_COLOR_YELLOW " ********** The Final Round  ********** \n"ANSI_COLOR_RESET);
printf("* this is the last chance for each team in this tournament * \n");
printf(" so mister %s Who do you think will win this tournament? \n",user);

fgets(vd,50,stdin);
fgets(vd,50,stdin);


printf(" so team %s we will see\n",vd);
printf(" **********************************************************************************************************\n");

//day 1
printf(" commenatator : Ladies and gentleman, thank you so much for attending especially our guest of honor  %s , we heard he was %s  last week we hope he doing better \n" ,user , conv);
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team2A ,team3A ,team4A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team2A, &tm1 ,&tm2);

team1[4] = tm1;
team2[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team3[4] = tm1;
team4[4] = tm2;





//day2      ******************************************************************************************************************
printf(" * DAY 2 * \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team3A ,team4A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team3A, &tm1 ,&tm2);

team1[5] = tm1;
team3[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team4A ,team5A, &tm1 ,&tm2);

team4[5] = tm1;
team5[4] = tm2;

//day3    ******************************************************************************************************************
printf(" * DAY 3* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team4A ,team2A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team4A, &tm1 ,&tm2);

team1[6] = tm1;
team4[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team5A, &tm1 ,&tm2);

team2[5] = tm1;
team5[5] = tm2;

//day4    ******************************************************************************************************************
printf(" * DAY 4* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team1A ,team5A ,team2A ,team3A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team1A ,team5A, &tm1 ,&tm2);

team1[7] = tm1;
team5[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team2A ,team3A, &tm1 ,&tm2);

team2[6] = tm1;
team3[6] = tm2;

//day5    ******************************************************************************************************************
printf(" * DAY 5* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team2A ,team4A ,team3A ,team5A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team2A ,team4A, &tm1 ,&tm2);

team2[7] = tm1;
team4[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team5A, &tm1 ,&tm2);

team3[7] = tm1;
team5[7] = tm2;


//day6    ******************************************************************************************************************
printf(" * DAY 6* \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team1A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team1A, &tm1 ,&tm2);

team11[4] = tm1;
team1[8] = 0;










//DAY 7     ******************************************************************************************************************

printf(" * DAY 7* \n");


printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team7A ,team8A ,team9A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team7A, &tm1 ,&tm2);

team6[4] = tm1;
team7[4] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team3A ,team4A, &tm1 ,&tm2);

team8[4] = tm1;
team9[4] = tm2;


//day8    ******************************************************************************************************************
printf(" * DAY 8 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[5] = tm1;
team2[8] = 0;



//day9      ******************************************************************************************************************
printf(" * DAY 9 * \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team8A ,team9A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team8A, &tm1 ,&tm2);

team6[5] = tm1;
team8[5] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team9A ,team10A, &tm1 ,&tm2);

team9[5] = tm1;
team10[4] = tm2;
//day10    ******************************************************************************************************************
printf(" * DAY 10 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team2A, &tm1 ,&tm2);

team11[6] = tm1;
team2[8] = 0;


//day11    ******************************************************************************************************************
printf(" * DAY 11* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team9A ,team7A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team9A, &tm1 ,&tm2);

team6[6] = tm1;
team9[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team10A, &tm1 ,&tm2);

team7[5] = tm1;
team10[5] = tm2;

//day12    ******************************************************************************************************************
printf(" * DAY 12* \n");
printf(" today we will have 1 match with %s and %s so let start \n",team11A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team11A ,team3A, &tm1 ,&tm2);

team11[7] = tm1;
team3[8] = 0;

//day13   ******************************************************************************************************************
printf(" * DAY 13* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team6A ,team10A ,team7A ,team8A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team6A ,team10A, &tm1 ,&tm2);

team6[7] = tm1;
team10[6] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team7A ,team8A, &tm1 ,&tm2);

team7[6] = tm1;
team8[6] = tm2;

//day14    ******************************************************************************************************************
printf(" * DAY 14* \n");
printf(" so today we have 2 matches the first is between %s and %s the 2nd is between %s and %s so let start \n",team7A ,team9A ,team8A ,team10A);
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team7A ,team9A, &tm1 ,&tm2);

team7[7] = tm1;
team9[7] = tm2;
//match 2

printf(ANSI_COLOR_BLUE"* 2ND match *\n"ANSI_COLOR_RESET);

hiiii(team8A ,team10A, &tm1 ,&tm2);

team8[7] = tm1;
team10[7] = tm2;
//day15    ******************************************************************************************************************
printf(" * DAY 15 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team3A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team3A, &tm1 ,&tm2);

team12[4] = tm1;
team3[8] = 0;
//day16    ******************************************************************************************************************
printf(" * DAY 16 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team4A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team4A, &tm1 ,&tm2);

team12[5] = tm1;
team4[8] = 0;
//day17    ******************************************************************************************************************
printf(" * DAY 17 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team5A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team5A, &tm1 ,&tm2);

team12[6] = tm1;
team5[8] = 0;
//day18    ******************************************************************************************************************
printf(" * DAY 18 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team12A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team12A ,team8A, &tm1 ,&tm2);

team12[7] = tm1;
team8[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 19 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team8A, &tm1 ,&tm2);

team13[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 20 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team2A, &tm1 ,&tm2);

team13[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 21 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team7A, &tm1 ,&tm2);

team13[6] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 23 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team13A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team13A ,team6A, &tm1 ,&tm2);

team13[7] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 24 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team8A, &tm1 ,&tm2);

team14[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 25 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team2A, &tm1 ,&tm2);

team14[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 26 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team7A, &tm1 ,&tm2);

team14[6] = tm1;
team7[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 27 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team14A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team14A ,team6A, &tm1 ,&tm2);

team14[7] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 28 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team8A, &tm1 ,&tm2);

team15[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 29 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team2A, &tm1 ,&tm2);

team15[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 30 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team7A, &tm1 ,&tm2);

team15[6] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 31 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team15A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team15A ,team6A, &tm1 ,&tm2);

team15[7] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 28 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team8A, &tm1 ,&tm2);

team16[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 29 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team2A, &tm1 ,&tm2);

team16[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 30 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team7A, &tm1 ,&tm2);

team16[6] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 31 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team16A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team16A ,team6A, &tm1 ,&tm2);

team16[7] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 36 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team8A, &tm1 ,&tm2);

team17[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 37 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team2A, &tm1 ,&tm2);

team17[5] = tm1;
team2[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 38 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team7A, &tm1 ,&tm2);

team17[6] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 39 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team17A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team17A ,team6A, &tm1 ,&tm2);

team17[7] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 40 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team8A, &tm1 ,&tm2);

team18[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 41 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team2A, &tm1 ,&tm2);

team18[5] = tm1;
team2[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 42 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team7A, &tm1 ,&tm2);

team18[6] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 43 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team18A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team18A ,team6A, &tm1 ,&tm2);

team18[7] = tm1;
team6[8] = 0;

//day19    ******************************************************************************************************************
printf(" * DAY 44 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team19A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team19A ,team8A, &tm1 ,&tm2);

team19[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 45 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team19A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team19A ,team2A, &tm1 ,&tm2);

team19[5] = tm1;
team2[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 46 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team19A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team19A ,team7A, &tm1 ,&tm2);

team19[6] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 47 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team19A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team19A ,team6A, &tm1 ,&tm2);

team19[7] = tm1;
team6[8] = 0;
//day19    ******************************************************************************************************************
printf(" * DAY 48 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team20A ,team8A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team20A ,team8A, &tm1 ,&tm2);

team20[4] = tm1;
team8[8] = 0;
//day10    ******************************************************************************************************************
printf(" * DAY 49 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team20A ,team2A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team20A ,team2A, &tm1 ,&tm2);

team20[5] = tm1;
team2[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 50 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team20A ,team7A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team20A ,team7A, &tm1 ,&tm2);

team20[6] = tm1;
team7[8] = 0;

//day10    ******************************************************************************************************************
printf(" * DAY 51 * \n");
printf(" today we will have 1 match with %s and %s so let start \n",team20A ,team6A );
//match 1
printf(ANSI_COLOR_BLUE"* First  Match *\n"ANSI_COLOR_RESET);

 hiiii(team20A ,team6A, &tm1 ,&tm2);

team20[7] = tm1;
team6[8] = 0;

for( int i=0 ; i<=7 ; i++ ){
  team1b= team1[i] + team1b;

}

for( int i=0 ; i<=7 ; i++ ){
  team2b= team2[i]+ team2b;

}

for( int i=0 ; i<=7 ; i++ ){
  team3b= team3[i]+ team3b;

}

for( int i=0 ; i<=7 ; i++ ){
  team4b= team4[i]+ team4b;

}

for( int i=0 ; i<=7 ; i++ ){
  team5b= team5[i]+ team5b;

}

for( int i=0 ; i<=7 ; i++ ){
  team6b= team6[i]+ team6b;

}

for( int i=0 ; i<=7 ; i++ ){
  team7b= team7[i]+ team7b;

}

for( int i=0 ; i<=7 ; i++ ){
  team8b= team8[i]+ team8b;

}


for( int i=0 ; i<=7 ; i++ ){
  team9b= team9[i]+ team9b;

}

for( int i=0 ; i<=7 ; i++ ){
  team10b= team10[i]+ team10b;

}
for( int i=0 ; i<=7 ; i++ ){
  team11b= team11[i]+ team11b;

}
for( int i=0 ; i<=7 ; i++ ){
  team12b= team12[i]+ team12b;

}
for( int i=0 ; i<=7 ; i++ ){
  team13b= team13[i]+ team13b;

}
for( int i=0 ; i<=7 ; i++ ){
  team14b= team14[i]+ team14b;

}
for( int i=0 ; i<=7 ; i++ ){
  team15b= team15[i]+ team15b;

}
for( int i=0 ; i<=7 ; i++ ){
  team16b= team16[i]+ team16b;

}
for( int i=0 ; i<=7 ; i++ ){
  team17b= team17[i]+ team17b;

}
for( int i=0 ; i<=7 ; i++ ){
  team18b= team18[i]+ team18b;

}
for( int i=0 ; i<=7 ; i++ ){
  team19b= team19[i]+ team19b;

}
for( int i=0 ; i<=7 ; i++ ){
  team20b= team20[i]+ team20b;

}
int cs[20];
cs[0] = team1b;
cs[1] = team2b;
cs[2] = team3b;
cs[3] = team4b;
cs[4] = team5b;
cs[5] = team6b;
cs[6] = team7b;
cs[7] = team8b;
cs[8] = team9b;
cs[9] = team10b;
cs[10] = team11b;
cs[11] = team12b;
cs[12] = team13b;
cs[13] = team14b;
cs[14] = team15b;
cs[15] = team16b;
cs[16] = team17b;
cs[17] = team18b;
cs[19] = team20b;
int n=20;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (cs[j] < cs[j + 1]) {
                // Swap cs[j] and cs[j + 1]
                int temp = cs[j];
                cs[j] = cs[j + 1];
                cs[j + 1] = temp;
            }
        }
    }

  strcpy(teams[0].name, team1A);
 strcpy(teams[1].name, team2A);
 strcpy(teams[2].name, team3A);
 strcpy(teams[3].name, team4A);
 strcpy(teams[4].name, team5A);
 strcpy(teams[5].name, team6A);
 strcpy(teams[6].name, team7A);
 strcpy(teams[7].name, team8A);
 strcpy(teams[8].name, team9A);
  strcpy(teams[9].name, team10A);
    strcpy(teams[10].name, team11A);
  strcpy(teams[11].name, team12A);
strcpy(teams[12].name, team13A);
strcpy(teams[13].name, team14A);
strcpy(teams[14].name, team15A);
strcpy(teams[15].name, team16A);
strcpy(teams[16].name, team17A);
strcpy(teams[17].name, team18A);
strcpy(teams[18].name, team19A);
strcpy(teams[19].name, team20A);

teams[0].points = team1b ;
teams[1].points = team2b ;
 teams[2].points = team3b ;
teams[3].points = team4b ;
teams[4].points = team5b ;
teams[5].points = team6b ;
teams[6].points = team7b ;
teams[7].points = team8b ;
teams[8].points = team9b ;
teams[9].points = team10b ;
teams[10].points = team11b ;
teams[11].points = team12b ;
    teams[12].points = team13b ;
 teams[13].points = team14b ;
teams[14].points = team15b ;
teams[15].points = team16b ;
teams[16].points = team17b ;
teams[17].points = team18b ;
teams[18].points = team19b ;
teams[19].points = team20b ;

  sortTeams(NT, teams);     
        
    printDecorativeTable(NT, teams);

                                }
printf( BLUE_TEXT" so did your team %s win ?" RESET_TEXT ,vd );


}
else{
  
  char vd[50] ,conv[300];
    printf(" Hello user :)  \n");
   sleep(2);
        printf(" are you feeling good today ? tell me about your day : ^_^ ") ;
         fgets(conv,2000,stdin);
         fgets(conv,2000,stdin);
            sleep(2);
        printf(" omg wow, at least you're doing good!!, keep it up \n");
           sleep(2);
printf("btw i am 'MESSI' your assistant into this tournament :) \n");
   sleep(2);
   printf(ANSI_COLOR_YELLOW" we will start this tournament with a LOT of games ,I hope it will be competitive this season \n "ANSI_COLOR_RESET);
     sleep(2);
   printf(" press enter key to start : \n");
   fgets(vd,50,stdin);
      sleep(2);
  printf(ANSI_COLOR_GREEN" LETS START ^o^ \n"ANSI_COLOR_RESET);
   sleep(2);

  //DAY 1     ******************************************************************************************************************

    printf(YELLOW "@@@@@@@                     .,***,,...   ...,,***,.                    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      . . . . .,./,,****,,..   ..,,****,,/.*.    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . .   .    ,*/***,,.. ..,,**//*,.   /      .   .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                 /    .*///**,,....,**///*.    *                %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . . . . ...    ,///**,,...,**////*  . /    . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . . .(   .*///**,...,*//((/.   (. .      .        %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                    ,(, ./((/**,.,*//((/. */.                   %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@  .      . . . . .     ./,/((/****/((((/,. . . .    . . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      .    ,((/**/((#, . . .          . . .     %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                              (/*/#                             %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .      . .   . . .    . . . . (*(    .   . .      . . .   .    %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@ .        . . . .        . . . (*(    . . .     .      . .   .  %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                             ,//,*/.                            %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@. .      .   . . .    .   **#.,,,.,,#*,    . . .    . .   . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@.      . . . . .      . #%##%,/  ....*,%%#(.. . . .    .  . . . . . %@@@@@@@@\n");
     usleep(300000);
    printf(YELLOW "@@@@@@@                        #%##%,/  .*.%%%(###%(      ...                %@@@@@@@@\n");
     usleep(300000);
    printf(RESET);

    printf("\033[0;34m");  // Code ANSI pour la couleur bleue

    printf("____    __    ____  _______  __        ______   ______   .___  ___.  _______ \n");
     usleep(2000000);
    printf("\\   \\  /  \\  /   / |   ____||  |      /      | /  __  \\  |   \\/   | |   ____|\n");
     usleep(2000000);
    printf(" \\   \\/    \\/   /  |  |__   |  |     |  ,----'|  |  |  | |  \\  /  | |  |__   \n");
     usleep(2000000);
    printf("  \\            /   |   __|  |  |     |  |     |  |  |  | |  |\\/|  | |   __|  \n");
     usleep(2000000);
    printf("   \\    /\\    /    |  |____ |  `----.|  `----.|  `--'  | |  |  |  | |  |____ \n");
     usleep(2000000);
    printf("    \\__/  \\__/     |_______||_______| \\______| \\______/  |__|  |__| |_______|\n");
 usleep(2000000);
    printf("\033[0m");  // Réinitialisation de la couleur





  srand(time(NULL));

    int y, days, location_choice;
    struct Team teams[Max_Team];

    printf(GREEN_TEXT"Choose the Stadium for the tournament:\n"RESET_TEXT);
    printf(GREEN_TEXT"1. Tottenham Hotspur Stadium\n"RESET_TEXT);
    printf(GREEN_TEXT"2. Emirates Stadium\n"RESET_TEXT);
    printf(GREEN_TEXT"3. Old Trafford\n"RESET_TEXT);
    printf(GREEN_TEXT"4. Anfield\n"RESET_TEXT);
    printf(GREEN_TEXT"5. Stamford Bridge\n"RESET_TEXT);
    printf(GREEN_TEXT"6. London Stadium\n"RESET_TEXT);
    printf(GREEN_TEXT"Enter your choice ( number pls): "RESET_TEXT);

    scanf("%d", &location_choice);

    printf(GREEN_TEXT"Enter Number of teams (between 10 and 20) : "RESET_TEXT);
    scanf("%d", &y);

    if (y < 10 || y > 20) {
        printf(GREEN_TEXT"The number of teams has to be between 10 and 20.\n"RESET_TEXT);
        return 1;
    }

    inputteams(teams, y);

    printf(MAGENTA_TEXT"\nEnter Number of Days : "RESET_TEXT);
    scanf("%d", &days);

    comp(teams, y, days);

char oo;
printf("press Enter key to display the winner \n");
scanf("%c" ,&oo);
scanf("%c" ,&oo);
    

    int winner = WinnerFinder(teams, y);

    Sleep(4);

    printf(BLUE_TEXT"T"RESET_COLOR); usleep(700000);printf(BLUE_TEXT"h"RESET_COLOR); usleep(700000);printf(BLUE_TEXT"e"RESET_COLOR); usleep(700000);printf(BLUE_TEXT" "RESET_COLOR); usleep(700000);printf(BLUE_TEXT"w"RESET_COLOR); usleep(700000);printf(BLUE_TEXT"i"RESET_COLOR); usleep(700000);printf(BLUE_TEXT"n"RESET_COLOR); usleep(700000);printf(BLUE_TEXT"n"RESET_COLOR); usleep(700000);printf(BLUE_TEXT"e"RESET_COLOR); usleep(700000);printf(BLUE_TEXT"r "RESET_COLOR); usleep(700000);printf(BLUE_TEXT"i"RESET_COLOR); usleep(700000);printf(BLUE_TEXT"s"RESET_COLOR); usleep(700000);printf(BLUE_TEXT" "RESET_COLOR);
    sleep(2);
      printf(GREEN_TEXT" %s "RESET_TEXT, teams[winner].name);
       usleep(700000);
        printf(BLUE"withe %d wins."RESET_TEXT, teams[winner].wins);
        displayScores(teams, y);
        
    sleep(8);
}
idk1();

       return 0;
       }
