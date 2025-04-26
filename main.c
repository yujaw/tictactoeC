#include <stdio.h>
#include <stdlib.h>

void drawBoard(int board[3][3]) {
    printf("Current Board:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                printf(" . ");
            } else if (board[i][j] == 1) {
                printf(" X ");
            } else if(board[i][j] == 2) {
                printf(" O ");
            } else {
                printf(" ? ");
            }
        }
        printf("\n");
    }
}

int checkWin(int board[3][3], int player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }

    return 0;
}

int placeMove(int board[3][3], int i, int j, int player) {
    if (board[i][j] == 0) {
        board[i][j] = player;
        return 1;
    } else {
        printf("Invalid move! Cell already occupied.\n");
        return 0;
    }
}

int main () {
    int board[3][3];
    char *player1 = malloc(20 * sizeof(char));
    char *player2 = malloc(20 * sizeof(char));
    int game = 1;
    
    printf("Enter 1st player's name : ");
    scanf("%s", player1);
    printf("Enter 2nd player's name : ");
    scanf("%s", player2);
    printf("Welcome %s and %s to the Tic Tac Toe game!\n", player1, player2);
    
    int move = 0;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = 0;
        }
    }
    
    while(game) {
        int i, j;

        if(move % 2 == 0) {
            printf("%s's turn (X)\n", player1);
        } else {
            printf("%s's turn (O)\n", player2);
        }


        printf("Enter player 1's move (row, column): ");
        scanf("%d %d", &i, &j);

        if(i < 1 || i > 3 || j < 1 || j > 3) {
            printf("Invalid move! Please enter row and column between 1 and 3.\n");
            continue;
        }

        if(!placeMove(board, i - 1, j - 1, move % 2 + 1)) {
            continue;
        }

        if(checkWin(board, move % 2 + 1)) {
            printf("%s wins!\n", move % 2 == 0 ? player1 : player2);
            game = 0;
            break;
        }

        move++;
        drawBoard(board);
        getchar();

    }

    return 0;
}