#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
// Intialisation for final answer
const int x = 3;
const int y = 3;
int ans[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, -1}};
int choice_Array[3][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
void display(int a[x][y]);
int answer_check(int a[x][y]);         // compare the model with main answer
void display(int a[x][y]);             // display the 2d array
int chk(int a[x][y], int pos);         // blank sahi position pr hai na chk krega
void swap(int *a, int *b);             // swap the space
int chkBlank_Move(int *move, int pos); // chk the  blank movement is valid or not
int movement(int a[x][y], int blank_pos, int blank_next_move)
{
    int move[4] = {-1};
    int row = blank_pos / 3;
    int col = (blank_pos % 3);
    int changed_row = blank_next_move / 3;
    int changed_column = (blank_next_move % 3); // move main sbhi possible movements hai
    move[0] = blank_pos - 1;                    // move left
    move[1] = blank_pos - 3;                    // move up
    move[2] = blank_pos + 3;                    // move down
    move[3] = blank_pos + 1;                    // move right
    for (int i = 0; i < 4; i++)
    {
        if (move[i] >= 0 && move[i] <= 8)
        {
            continue;
        }
        else
        {
            move[i] = -1;
        }
    }
    if (blank_pos == 3 || blank_pos == 6 || blank_pos == 0)
    {
        move[0] = -1; // move left as not possible
    }
    if (blank_pos == 2 || blank_pos == 5 || blank_pos == 8)
    {
        move[3] = -1; // move right is not possible
    }
    // AAGE AB KYA MOVEMENT HOGA VOH FUNCTION AAYEGA
    if (chkBlank_Move(move, blank_next_move))
    {
        swap(&a[row][col], &a[changed_row][changed_column]);
        printf("\n------------------after swapping it looks as--------------------------------\n");
        display(a);
        printf("\nposition choce is \n");
        display(choice_Array);
        return blank_next_move;
    }
    else
    {
        printf("\nWRONG INPUT\nRETRY......\n");
        printf("\nTHIS IS THE CHOICE MATRIX\nFROM WHICH YOU HAVE  TO CHOOSE THE POSITION WHERE YOUR BLANK WILL MOVE\n");
        display(choice_Array);
        printf("\n");
        printf("THIS IS QUESTION");
        printf("\n");
        display(a);
        return blank_pos;
    }
}
void intialisation(int a[x][y], int temp)
{
    int count = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int row = temp / 3;
            int column = temp % 3;
            if (i == row && j == column)
            {
                a[i][j] = -1;
            }
            else
            {
                a[i][j] = count++;
            }
        }
    }
}
int main()
{
    printf("\nWELCOME TO  GAME\n");
    srand(time(NULL));
    int temp = rand() % 10 - 3;
    // int temp =7;
    int a[3][3];
    intialisation(a, temp);
    printf("\nTHIS IS THE CHOICE MATRIX\nFROM WHICH YOU HAVE  TO CHOOSE THE POSITION WHERE YOUR BLANK WILL MOVE\n");
    display(choice_Array);
    printf("\n");
    printf("THIS IS QUESTION");
    printf("\n");
    display(a);
    int n, y = 1;
    printf("\nSTART SOLVING\n");
    while (y == 1)
    {
        printf("Enter the next position of blank");
        scanf("%d", &n);
        temp = movement(a, temp, n);
        if (a[0][2] == 3 && a[1][2] == 6 && a[2][2] == -1)
        {
            y = answer_check(a);
            if (y == 0)
            {
                printf("\n---------------------GAME OVER -----------------\nTHANKS FOR PLAYING\n---------CREATED BY CHIRAG TAK --------");
                exit(1);
            }
        }
    }
    return 0;
}
int answer_check(int a[x][y])
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (a[i][j] == ans[i][j])
            {
                printf("Congratulation you won");
                return 0;
            }
            else
            {
                printf("Not Completed yet\n See the Answer\n");
                display(ans);
                return 1;
            }
        }
        printf("\n");
    }
}
void display(int a[x][y])
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (a[i][j] == -1)
            {
                printf("   ");
            }
            else
            {
                printf("%d  ", a[i][j]);
            }
        }
        printf("\n");
    }
}
int chk(int a[x][y], int pos)
{
    int row = pos / 3;
    int col = (pos % 3);
    if (a[row][col] == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int chkwish(int *a, int n)
{
    for (int i = 0; i < 4; i++)
    {
        if (a[i] == n)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int chkBlank_Move(int *move, int pos)
{
    for (int i = 0; i < 4; i++)
    {
        if (move[i] == pos)
        {
            return 1;
        }
    }
    return 0;
}
