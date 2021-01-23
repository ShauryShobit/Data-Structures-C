/*all header files*/
#include <time.h>
#include <stdio.h>      //It has the information related to input/output functions.
#include <stdlib.h>     //It has the information of memory allocation/freeing functions.
#include <conio.h>      //contains functions for console input/output
#include<ctype.h>       //declares several functions that are useful for testing and mapping characters
#include <windows.h>    //declarations for all of the functions in the Windows API
#include <process.h>    // needed for working with process and threads

/*define the directions work*/

#define UP 72                   //ascii values
#define DOWN 80                 //ascii values
#define LEFT 75                 //ascii values
#define RIGHT 77                //ascii values

/*all initialization*/

int length;                 //legth of snake
int bend_no;                //number of bend while turning
int len;                    //length
char key;                   //the key that will be pressed
void load();                //it is the screen of Loading after intro part
int life;                   //it will decide and count the number of life
void Scoreboard();          //it will handle to display the score with msg in the end
void Delay(long double);    //it will decide the delay or speed of the snake
void Move();                //it will work with the movement
void Food();                //produce the food for snake
int Score();                //it will count the score
void Print();               //print the intro and instruction part
void gotoxy(int x, int y);  //work with positioning
void GotoXY(int x,int y);   //work with positioning
void Bend();                //it will work with the turning of snake
void Boundary();            //it will handle the boundary of the gaming area
void Down();                //decides the movement of down arrow
void Left();                //decides the movement of left arrow
void Up();                  //decides the movement of up arrow
void Right();               //decides the movement of right arrow
void ExitGame();            //it will display the msg required to be shown
int Scoreonly();            //it will work as counter for score board

/*Setting the axis or coordinates*/

struct coordinate{
    int x;
    int y;
    int direction;
};


typedef struct coordinate coordinate;               //defining stuct
coordinate head, bend[5000],food,body[1000];           //working of all things

/*Main fuction where it is decided how the game will start*/

int main() //Main function
{
    system("COLOR 0A");         //will change the color of console
    char key;
    Print();
    system("cls");              //clear screen
    load();                     //execute the loading screen
    length=5;
    head.x=25;
    head.y=25;
    head.direction=RIGHT;       //direction in which snake will go every time whenever started
    Boundary();
    Food();                     //to generate food coordinates initially
    life=3;                     //number of extra lives
    bend[0]=head;
    Move();                     //initialing initial bend coordinate
    return 0;
}

/*How the movement of snake should work*/

void Move() //Move function
{
    int a,i;
    do{
        Food();                 //call food function
        fflush(stdin);          //fflush(stdin)-typically used for output stream only.flushes the output buffer of a stream
        len=0;
        for(i=0;i<40;i++)
        {
            body[i].x=0;
            body[i].y=0;
            if(i==length)
            break;
        }
        Delay(length);          //calling delay function
        Boundary();             //calling Boundary
        if(head.direction==RIGHT)                   //Directioncs
            Right();                                //Directioncs
        else if(head.direction==LEFT)               //Directioncs
            Left();                                 //Directioncs
        else if(head.direction==DOWN)               //Directioncs
            Down();                                 //Directioncs
        else if(head.direction==UP)                 //Directioncs
            Up();                                   //Directioncs
        ExitGame();             //calling exit game function
    }while(!kbhit());           //!kbhit()-used to determine if a key has been pressed or not
    a=getch();
    if(a==27)
    {
        system("cls");          //clear the screen
        exit(0);
    }
    key=getch();
    if((key==RIGHT&&head.direction!=LEFT&&head.direction!=RIGHT)||(key==LEFT&&head.direction!=RIGHT&&head.direction!=LEFT)||(key==UP&&head.direction!=DOWN&&head.direction!=UP)||(key==DOWN&&head.direction!=UP&&head.direction!=DOWN))
    {
        bend_no++;                      //Giving direction to head when key is pressed
        bend[bend_no]=head;             //Giving direction to head when key is pressed
        head.direction=key;             //Giving direction to head when key is pressed
        if(key==UP)                     //Giving direction to head when up key is pressed
            head.y--;                   //Giving direction to head when up key is pressed
        if(key==DOWN)                   //Giving direction to head when down key is pressed
            head.y++;                   //Giving direction to head when down key is pressed
        if(key==RIGHT)                  //Giving direction to head when right key is pressed
            head.x++;                   //Giving direction to head when right key is pressed
        if(key==LEFT)                   //Giving direction to head when left key is pressed
            head.x--;                   //Giving direction to head when left key is pressed
        Move();
    }
    else if(key==27)
    {
        system("cls");
        exit(0);
    }
    else
    {
        printf("\a");                   //produce a beep sound
        Move();
    }
}

/*Where do we have to print the text or giving positioning*/

void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/*Sets the console cursor point*/

void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
 }

/*Loading screen function*/

void load(){
    system("COLOR 0D");                     //change console color
    int row,col,r,c,q;
    gotoxy(36,14);
    printf("Loading...", 172);                   //print
    gotoxy(30,16);
    for(r=1;r<=20;r++){
    for(q=0;q<=100000000;q++);              //to display the character slowly
    printf("%c",223);}
    getch();
}

/*Down Direction*/

void Down()
{
    int i;
    for(i=0;i<=(head.y-bend[bend_no].y)&&len<length;i++)
    {
        GotoXY(head.x,head.y-i);
        {
            if(len==0)
                printf("v");                        //head will look like v
            else
                printf("%c", 254);                  //rest of the body of snake via a box
        }
        body[len].x=head.x;
        body[len].y=head.y-i;
        len++;
    }
    Bend();             //bend will implement
    if(!kbhit())
        head.y++;
}

/*Delaying function in millisecond*/

void Delay(long double k)
{
    Score();
    long double i;
    for(i=0;i<=(20000000);i++);         //delay value in millisecond
}

/*Conditions for starting of game and the ending screen*/

void ExitGame()
{
    int i,check=0;
    for(i=4;i<length;i++)   //starts with 4 because it needs minimum 4 element to touch its own body
    {
        if(body[0].x==body[i].x&&body[0].y==body[i].y)
        {
            check++;    //check's value increases as the coordinates of head is equal to any other body coordinate
        }
        if(i==length||check!=0)
            break;
    }
    if(head.x<=10||head.x>=70||head.y<=10||head.y>=40||head.x<=50&&head.x>=30&&head.y==15||head.x<=50&&head.x>=30&&head.y==35||head.y<=30&&head.y>=20&&head.x==20||head.y<=30&&head.y>=20&&head.x==60||check!=0)
    {
        life--;                           //life will be decrementing each time
        if(life>=0)                         //loop for if we have left with our life
        {
            head.x=25;
            head.y=25;
            bend_no=0;
            head.direction=RIGHT;           //head direction will be in right side
            Move();
        }
        else
        {
            system("cls");                  //clear screen
            printf("All lives completed\nBetter Luck Next Time!!!\nPress any key to quit the game\n");  //msg
            Scoreboard();                   //in this window it will execute Scoreboard function
            exit(0);
        }
    }
}

/*Creation of food for snake*/

void Food()
{
    if(head.x==food.x&&head.y==food.y&&food.x!=Boundary&&food.y!=Boundary)      //this whole code is for producing food on random area
    {
        length++;
        time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%40;
        if(food.y<=10)

            food.y+=11;
    }
    else if(food.x==0)/*to create food for the first time because global variable are initialized with 0*/
    {
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%40;
        if(food.y<=10)
            food.y+=11;
    }
}

/*Left Direction*/

void Left()
{
    int i;
    for(i=0;i<=(bend[bend_no].x-head.x)&&len<length;i++)
    {
        GotoXY((head.x+i),head.y);
       {
                if(len==0)
                    printf("<");                        //head will look like <
                else
                    printf("%c", 254);                        //rest of the body of snake via a box
        }
        body[len].x=head.x+i;
        body[len].y=head.y;
        len++;
    }
    Bend();                 //implement body fuction
    if(!kbhit())
        head.x--;

}

/*Right direction*/

void Right()
{
    int i;
    for(i=0;i<=(head.x-bend[bend_no].x)&&len<length;i++)
    {
        //GotoXY((head.x-i),head.y);
        body[len].x=head.x-i;
        body[len].y=head.y;
        GotoXY(body[len].x,body[len].y);
        {
            if(len==0)
                printf(">");                            //head will look like >
            else
                printf("%c", 254);                            //rest of the body of snake via box
        }
        body[len].x=head.x-i;
        body[len].y=head.y;
        len++;
    }
    Bend();
    if(!kbhit())
        head.x++;
}

/*How movement should occur*/

void Bend()
{
    int i,j,diff;
    for(i=bend_no;i>=0&&len<length;i--)                 //this whole code is for the reaction of snake when it will turn
            {
            if(bend[i].x==bend[i-1].x)
            {
                diff=bend[i].y-bend[i-1].y;
                if(diff<0)
                    for(j=1;j<=(-diff);j++)             //this loop is for reaction of snake while taking turns
                    {
                        body[len].x=bend[i].x;
                        body[len].y=bend[i].y+j;
                        GotoXY(body[len].x,body[len].y);
                        printf("%c", 254);                    //while turning it will print a box
                        len++;
                        if(len==length)
                            break;
                    }
                else if(diff>0)
                    for(j=1;j<=diff;j++)                //this loop is for reaction of snake while taking up or down turns
                    {
                        body[len].x=bend[i].x;
                        body[len].y=bend[i].y-j;
                        GotoXY(body[len].x,body[len].y);
                        printf("%c", 254);                    //while turning it will print a box
                        len++;
                        if(len==length)
                            break;
                    }
            }
        else if(bend[i].y==bend[i-1].y)
        {
            diff=bend[i].x-bend[i-1].x;
            if(diff<0)
                for(j=1;j<=(-diff)&&len<length;j++)
                {
                    body[len].x=bend[i].x+j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                        printf("%c", 254);
                   len++;
                   if(len==length)
                           break;
               }
           else if(diff>0)
               for(j=1;j<=diff&&len<length;j++)
               {
                   body[len].x=bend[i].x-j;
                   body[len].y=bend[i].y;
                   GotoXY(body[len].x,body[len].y);
                       printf("%c", 254);
                   len++;
                   if(len==length)
                       break;
               }
       }
   }
}

/*Setting limit for the area*/

void Boundary()
{
   system("COLOR  80");
   system("cls");
   int i;
   GotoXY(food.x,food.y);   /*displaying food*/
           printf("%c", 254);
   for(i=10;i<71;i++)           //it is the loop for width of our boundary and printing the box
   {

       GotoXY(i,10);
           printf("%c", 176);
       GotoXY(i,40);
           printf("%c", 176);
   }
   for(i=10;i<41;i++)           //it is the loop for length of our boundary and printing the box
   {
       GotoXY(10,i);
           printf("%c", 176);
       GotoXY(70,i);
       printf("%c", 176);
   }
   for(i=30;i<51;i++)           //it is the loop for width of our inside obstacles and printing the box
   {

       GotoXY(i,15);
           printf("%c", 176);
       GotoXY(i,35);
           printf("%c", 176);
   }
   for(i=20;i<31;i++)           //it is the loop for width of our inside obstacles and printing the box
   {

       GotoXY(20,i);
           printf("%c", 176);
       GotoXY(60,i);
           printf("%c", 176);
   }
}

/*Welcoming Screen with Instructions*/

void Print()
{
   //Intro of Group 17
   printf(" Hello Players,\n Project by Group 17 \n Tribute to the game which made our childhood awesome"
          "\n Implementation using C\n\n Project member's:\n\tShaury Shobit(199126)\n\tShivam Kumar Thakur(199128)\n\tShreya Srivastava(199129)\n\tShubham Kumar(199130)\n\tSiddarth Samal(199131)\n\tSimran Sharma(199133)\n\tSupriya Yadav(199135)\n\tSuraj Kumar(199137)\n\n Submitted to:- Ms. Hina Firdaus.\n Let's Play!!!\n (Press any key to continue)\n");
  getch();          //terminate after any key pressed
   system("cls");
   system("COLOR 0B");          //change color of console screen
   printf(" Keep your console screen maximize\n Game instructions:\n");     //instructions
   printf("\n Nothing new it's a legendary game you should know it\n But\n");
   printf("\n For your reference - \n Up arrow for up\n Down arrow for down\n Right arrow for right\n Left arrow for left\n Don't crash yourself or the boundaries");
   printf("\n\n Press any key to play game...");
   if(getch()==27)                  //if someone pressed esc button so it will exit it
   exit(0);
}

/*Displaying Score at end*/

void Scoreboard(){
     if (Scoreonly()>0)
    {
        if (Scoreonly() <=5)    //if someone score less then 5 so it will display this msg
           printf("Are you kidding!!!\nIt's a legendary game\nImprove your focus\nOnly %d score", Scoreonly());
        else if (Scoreonly() <= 10)//if someone score less then 10 so it will display this msg
            printf("Keep it up!!\nCan do better\nYour score %d", Scoreonly());
        else if(Scoreonly() > 10)//if someone score more than 10 so it will display this msg
            printf("It was a warm up for legends!!\nNow here the legends come\nwith score of %d", Scoreonly());
    }
    //if someone score less then 0 or equal to 0 so it will display this msg
    else printf("Are you kidding!!!\nIt's a legendary game\nImprove your focus\nOnly %d score", Scoreonly());
}

/*Score with Life*/

int Score()         //Display the score with life
{
   int score;
   GotoXY(20,8);
   score=length-5;
   printf("SCORE : %d",(length-5));
   score=length-5;
   GotoXY(50,8);
   printf("Life : %d",life);
   return score;
}

/*Scoreonly*/

int Scoreonly()         //Display the score at the end of the screen
{
int score=Score();
system("cls");          //clear screen
return score;
}

/*UP Direction*/

void Up()
{
   int i;
   for(i=0;i<=(bend[bend_no].y-head.y)&&len<length;i++)
   {
       GotoXY(head.x,head.y+i);
       {
           if(len==0)
               printf("^");                 //the head of the snake will look like ^
           else
               printf("%c", 254);                 //the rest of the body will look like a box
       }
       body[len].x=head.x;
       body[len].y=head.y+i;
       len++;                               //increment of the length
   }
   Bend();
   if(!kbhit())
       head.y--;
}
