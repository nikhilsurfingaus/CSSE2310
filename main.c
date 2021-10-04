#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqoai.h>

//CSSE2310 AT1 This is the BARK FILEm
void gameTurn(Boolean turn);
Boolean nextTurn(Boolean flip);
void gameManager(void);
void getInput(void);
void printGrid(void);
int width;
int height;
int main(int argc, char* argv[]) {
        //Task 1 return a grid with height and width
        //Task 2 have a player 1 and player 2
        //turn false or true
        //deck file contains numbers and cards
        // go ./bark(exe) d1.deck(this is arg[1]) 3 4 a a
        //dimensions between 3 and 100
        //do errror checking only in main

    char *filename;
    filename = argv[1];
    //printf("%s\n",filename);
    FILE *fPointer;
    fPointer = fopen(filename,"r");
    char deckLine[20];
    while(!feof(fPointer)){
        fgets(deckLine,20,fPointer);
    }
    //printf("%c\n",deckLine[1]);
    fclose(fPointer);
    char *playerOne = argv[4];
    char *playerTwo = argv[5];

    printf("%s %s \n", playerOne,playerTwo);

     width = atoi(argv[2]);
     height = atoi(argv[3]);

    if(width*height <3 || width*height >100){
        fprintf(stderr,"Incorrect arg types \n");
    }

    if((strcmp(argv[4],"a") != 0) && (strcmp(argv[4],"h") != 0)) {
        fprintf(stderr,"Incorrect arg types \n");
    }

    if((strcmp(argv[5],"a") != 0) && (strcmp(argv[5],"h") != 0)) {
        fprintf(stderr,"Incorrect arg types \n");
    }

    if(argc < 4) {
        fprintf(stderr,"ERROR arg types \n");
    }

    for (int k = 0; k < height; k++){
        for (int i = 0; i < width; i++) {
            printf(".");
        }
        printf("\n");
    }

    gameManager();


    return 0;
}
void gameTurn(Boolean turn){
    if(turn) {
        printf("Hand(1): 1A 2A 3A 4A 5A 6C \n");

    }else {
        printf("Hand(2): 1A 2A 3A 4A 5A 6C \n");
    }
}
Boolean nextTurn(Boolean flip){
    return !flip;
}

void gameManager(void){
    //game is infinite atm needs to end
    Boolean endGame = FALSE;
    Boolean playerTurn = TRUE;
    int count = 5;

    //while(!endGame){
    while(count > -1){
        if(playerTurn){
            gameTurn(playerTurn);
            getInput();
            playerTurn = nextTurn(playerTurn);
            count = count -1;
            printf("Count %i\n",count);
            printGrid();
        }else{
            gameTurn(playerTurn);
            getInput();
            playerTurn = nextTurn(playerTurn);
            count = count -1;
            printf("Count %i\n",count);
            printGrid();
        }
    }



}
void getInput(void){
    char string[256];
    printf("Move? ");
    fgets(string,256,stdin);
    fputs(string,stdout);
}
void printGrid(void) {
    for (int k = 0; k < height; k++){
        for (int i = 0; i < width; i++) {
            printf(".");
        }
        printf("\n");
    }
}
