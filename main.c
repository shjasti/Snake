#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
//#include <process.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77


int length;
int bend_no;
int len;
char key;
void record();
void load();
int life;
void Delay(long double);
void Move();
void Food();
int Score();
void Print();
void gotoxy(int x, int y);
void GotoXY(int x,int y);
void Bend();
void Border();
void Down();
void Left();
void Up();
void Right();
void ExitGame();
int Scoreonly();

struct Coordinate {
    int x;
    int y;
    int direction;
};
typedef struct Coordinate Coordinate;
Coordinate head, bend[500], food, body[30];

int main(int argc, const char * argv[]) {
    
    return 0;
}

void Move() {
    int a, i;
    do {
        Food();
        fflush(stdin);
        len = 0;
        for (i = 0; i < 30; ++i) {
            body[i].x=0;
            
            body[i].y=0;
            
            if(i==length) {
                
                break;
            }
        }
        Delay(length);
        Border();
        if (head.direction == RIGHT) {
            Right();
        }
        else if (head.direction == LEFT) {
            Left();
        }
        else if (head.direction == DOWN) {
            Down();
        }
        else if (head.direction == UP) {
            Up();
        }
        ExitGame();
        
    }while (!kbhit());
    a = getch();
    if (a == 27) {
        system("cls");
        exit(0);
    }
    key = getch();
    if ((key == RIGHT && head.direction != LEFT && head.direction != RIGHT) ||
        (key == LEFT && head.direction != RIGHT && head.direction != LEFT) ||
        (key == UP && head.direction != UP && head.direction != DOWN) ||
        (key == DOWN && head.direction != DOWN && head.direction != UP)) {
        
        bend_no++;
        bend[bend_no] = head;
        head.direction = key;
        if (key == UP) {
            head.y--;
        }
        if (key == DOWN) {
            head.y++;
        }
        if (key == RIGHT) {
            head.x++;
        }
        if (key == LEFT) {
            head.x--;
        }
        Move();
    }
    else if (key == 27) {
        system("cls");
        exit(0);
    }
    else {
        printf("\a");
        Move();
        
    }
}

void gotoxy(int x, int y) {
    
    
}


