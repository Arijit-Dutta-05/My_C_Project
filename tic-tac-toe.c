#include <stdio.h>
#include <stdbool.h>
char checkboard[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
void displayboard()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %c ", checkboard[i][j]);
            if (j < 2)
                printf("|");
        }
        if (i < 2)
            printf("\n---|---|---\n");
    }
}
bool isValidMove(int row, int column)
{
    if (row < 0 || row > 2 || column < 0 || column > 2)
    {
        printf("Invalid move! ");
        return false;
    }
    if (checkboard[row][column] != ' '){
        printf("Cell already occupied! Please choose another cell.");
        return false;
    }
    return true;
}
bool winCase(int symbol)
{
    int i;
    // Check for horizontal & vertically for a win
    for (i = 0; i < 3; i++)
    {
        if (checkboard[i][0] == symbol && checkboard[i][1] == symbol && checkboard[i][2] == symbol)
            return true;
        if (checkboard[0][i] == symbol && checkboard[1][i] == symbol && checkboard[2][i] == symbol)
            return true;
    }
    if (checkboard[0][0] == symbol && checkboard[1][1] == symbol && checkboard[2][2] == symbol)
        return true;
    if (checkboard[2][0] == symbol && checkboard[1][1] == symbol && checkboard[0][2] == symbol)
        return true;

    return false;
}
bool checkingTie()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (checkboard[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main()
{
    int row, column;
    char symbol = 'X';
    bool gameover = false;
    displayboard();
    while (!gameover)
    {

        printf("\nplayer %c enter your row (1-3) :", symbol);
        scanf("%d", &row);
        row--; // Adjusting for 0-based index
        printf("player %c enter your column (1-3) :", symbol);
        scanf("%d", &column);
        column--; // Adjusting for 0-based index
        if (isValidMove(row, column))
        {
            checkboard[row][column] = symbol;
            displayboard();
            if (winCase(symbol))
            {
                printf("\nplayer %c wins!", symbol);
                gameover = true;
            }
            else if (checkingTie())
            {
                printf("\nmatch is tied");
                gameover = true;
            }
            else
            {
                symbol = (symbol == 'X') ? 'O' : 'X';
            }
        }
    }
    return 0;
}