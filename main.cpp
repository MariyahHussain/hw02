#include <iostream>
using namespace std;
//a structure for the player 
struct Player
{   
    int food;
    int health;
    bool alive;
    int x;
    int y;
    Player()
    {
        food = 64;
        health = 10;
        alive = true;
    }
    void loseHealth()
    {
        if(health>0)
            health--;
        if(health==0)
            alive = false;
    }
    void gainHealth()
    {
        if(health<10)
            health++;
    }
};



//the point struct for position of P in the dungeon.
struct Point
{
    int x;
    int y;

    Point(int _x, int _y): x(_x), y(_y)
    {

    }
};
void Combat(Player&,int );
void TrapStatements();
void FoodStatements();
void HitStatements();
void GetHitStatements();
typedef const int cint;     
typedef const Point cPoint;

//for movement of the player to the right
void right(int width, int height, char* dungeon, Point& P, Player& Gay){
  if(dungeon[(P.y*width)+(P.x)+1]=='w'){
    Gay.food=Gay.food-1;
    cout<<"You bumped into a wall"<<endl;
    cout<<"You have food for "<< Gay.food <<" more turns."<<endl;
  }
  else if (dungeon[(P.y*width)+(P.x)+1]==' '){
    dungeon[(P.y*width)+P.x]=' ';
    P.x=P.x+1;
    dungeon[(P.y*width)+P.x]='P';
    Gay.food=Gay.food-1;
    cout<<"You have food for "<< Gay.food <<" more turns."<<endl;
  }

  else if (dungeon[(P.y*width)+(P.x)+1]=='F'){
    dungeon[(P.y*width)+P.x]=' ';
    P.x=P.x+1;
    Gay.food=Gay.food-1;
    dungeon[(P.y*width)+P.x]='P';
    FoodStatements();//call food statements function
    cout<<"You have food for "<< Gay.food <<" more turns."<<endl;
  }
  else if (dungeon[(P.y * width)+P.x +1]=='X'){
    dungeon[(P.y*width)+P.x]=' ';
    P.x=P.x+1;
    dungeon[(P.y*width)+P.x]='P';
    cout<<"You have found the exit. You win."<<endl;
  }
  else if (dungeon[(P.y*width)+(P.x)+1]=='H'){
    dungeon[(P.y*width)+P.x]=' ';
    P.x=P.x+1;
    dungeon[(P.y*width)+P.x]='P';
    Gay.food=Gay.food-1;
    Gay.gainHealth();
    cout<<"You found health. Your health is now "<<Gay.health<<endl;
    cout<<"You have food for "<< Gay.food <<" more turns."<<endl;
  }
  else if (dungeon[(P.y*width)+(P.x)+1]=='E'){
    dungeon[(P.y*width)+P.x]=' ';
    P.x=P.x+1;
    int enemy=2+ rand()%3;
    Gay.food=Gay.food-1;
    Combat(Gay, enemy);
    dungeon[(P.y*width)+P.x]='P';
  }
  else if (dungeon[(P.y*width)+(P.x)+1]=='T'){
    dungeon[(P.y*width)+P.x]=' ';
    P.x=P.x+1;
    int trap=2+ rand()%3;
    Gay.food=Gay.food-1;
    TrapStatements();
    dungeon[(P.y*width)+P.x]='P';
  } 
}
//for movement of the player to the left
void left(int width, int height, char* dungeon, Point& P,Player& Gay){

  if (dungeon[(P.y*width)+P.x-1]==' '){
    dungeon[(P.y*width)+P.x]=' ';
    P.x=P.x-1;
    dungeon[(P.y*width)+P.x]='P';
    Gay.food=Gay.food-1;
    cout<<"You have food for "<< Gay.food <<" more turns."<<endl;

  }
  else if(dungeon[(P.y*width)+(P.x)-1]=='w'){
    Gay.food=Gay.food-1;
    cout<<"You have food for "<< Gay.food <<" more turns."<<endl;
  }
  else if (dungeon[(P.y*width)+(P.x)-1]=='F'){
    dungeon[(P.y*width)+P.x]=' ';
    P.x=P.x-1;
    Gay.food=Gay.food-1;
    dungeon[(P.y*width)+P.x]='P';
    FoodStatements();//calling food statements function
    cout<<"You have food for "<< Gay.food <<" more turns."<<endl;
  }
  else if (dungeon[(P.y * width)+P.x -1]=='X'){
    dungeon[(P.y*width)+P.x]=' ';
    P.x=P.x-1;
    dungeon[(P.y*width)+P.x]='P';
    cout<<"You have found the exit. You win."<<endl;
  }
  else if (dungeon[(P.y*width)+(P.x)-1]=='H'){
    dungeon[(P.y*width)+P.x]=' ';
    P.x=P.x-1;
    dungeon[(P.y*width)+P.x]='P';
    Gay.food=Gay.food-1;
    Gay.gainHealth();
    cout<<"You found health. Your health is now "<<Gay.health<<endl;
    cout<<"You have food for "<< Gay.food <<" more turns."<<endl;
  }
  else if (dungeon[(P.y*width)+(P.x)-1]=='T'){
    dungeon[(P.y*width)+P.x]=' ';
    P.x=P.x-1;
    int trap=2+ rand()%3;
    TrapStatements();
    dungeon[(P.y*width)+P.x]='P';
  } 
}

//for movement of the player downwards.
void down(int width, int height, char* dungeon, Point& P,Player& Gay){
  if (dungeon[((P.y+1) *width)+P.x]==' '){
    dungeon[(P.y*width)+P.x]=' ';
    P.y=P.y+1;
    dungeon[(P.y*width)+P.x]='P';
    Gay.food=Gay.food-1;
    cout<<"You have food for "<< Gay.food <<" more turns."<<endl;
  }
  else if(dungeon[((P.y+1) *width)+P.x]=='w'){
    Gay.food=Gay.food-1;
    cout<<"You bumped into a wall"<<endl;
    cout<<"You have food for "<< Gay.food <<" more turns."<<endl;
  }
  else if (dungeon[((P.y+1) *width)+P.x]=='F'){
    dungeon[(P.y*width)+P.x]=' ';
    P.y=P.y+1;
    Gay.food=Gay.food-1;
    dungeon[(P.y+1*width)+P.x]='P';
    FoodStatements();//call food statements function
    cout<<"You have food for "<< Gay.food <<" more turns."<<endl;
  }
  else if (dungeon[((P.y+1) * width)+P.x]=='X'){
    dungeon[(P.y*width)+P.x]=' ';
    P.y=P.y+1;
    dungeon[(P.y+1*width)+P.x]='P';
    cout<<"You have found the exit. You win."<<endl;
  }
  else if (dungeon[((P.y+1)*width)+P.x ]=='H'){
    dungeon[(P.y*width)+P.x]=' ';
    P.y=P.y+1;
    dungeon[((P.y+1)*width)+P.x]='P';
    Gay.gainHealth();
    Gay.food=Gay.food-1;
    cout<<"You found health. Your health is now "<<Gay.health<<endl;
    cout<<"You have food for "<< Gay.food <<" more turns."<<endl;
  }
  else if (dungeon[(P.y+1*width)+(P.x)]=='E'){
    dungeon[(P.y*width)+P.x]=' ';
    P.y=P.y+1;
    int enemy=2+ rand()%3;
    Gay.food=Gay.food-1;
    Combat(Gay, enemy);
    dungeon[(P.y*width)+P.x]='P';
    cout<<"You have food for "<< Gay.food <<" more turns."<<endl;
  }
  else if (dungeon[((P.y+1)*width)+(P.x)]=='T'){
    dungeon[(P.y*width)+P.x]=' ';
    P.y=P.y+1;
    Gay.food=Gay.food-1;
    int trap=2+ rand()%3;
    TrapStatements();
    dungeon[(P.y*width)+P.x]='P';
    cout<<"You have food for "<< Gay.food <<" more turns."<<endl;
  }
}

//for movement of the player upwards.
void up(int width, int height, char* dungeon, Point& P, Player& Gay){
   if (dungeon[((P.y-1) *width)+P.x]==' '){
    dungeon[(P.y*width)+P.x]=' ';
    P.y=P.y-1;
    dungeon[(P.y*width)+P.x]='P';
    Gay.food=Gay.food-1;
    cout<<"You have food for "<< Gay.food <<" more turns."<<endl;
  }
  else if(dungeon[(P.y-1 *width)+P.x]=='w'){
    Gay.food=Gay.food-1;
    cout<<"You bumped into a wall"<<endl;
    cout<<"You have food for "<< Gay.food <<" more turns."<<endl;
  }
  else if (dungeon[(P.y-1 *width)+P.x]=='F'){
    dungeon[(P.y*width)+P.x]=' ';
    P.y=P.y-1;
    dungeon[(P.y*width)+P.x]='P';
    FoodStatements();//call food statements function
    cout<<"You have food for "<< Gay.food <<" more turns."<<endl;
  }
  else if (dungeon[(P.y-1 * width)+P.x]=='X'){
    dungeon[(P.y*width)+P.x]=' ';
    P.y=P.y-1;
    dungeon[(P.y*width)+P.x]='P';
    cout<<"You have found the exit. You win."<<endl;
  }
  else if (dungeon[(P.y-1*width)+P.x ]=='H'){
    dungeon[(P.y*width)+P.x]=' ';
    P.y=P.y-1;
    dungeon[(P.y*width)+P.x]='P';
    FoodStatements();
    Gay.gainHealth();
    cout<<"You found health. Your health is now "<<Gay.health<<endl;
    cout<<"You have food for "<< Gay.food <<" more turns."<<endl;
  }
  else if (dungeon[(P.y-1*width)+(P.x)]=='E'){
    dungeon[(P.y*width)+P.x]=' ';
    P.y=P.y-1;
    int enemy=2+ rand()%3;
    Combat(Gay, enemy);
    dungeon[(P.y*width)+P.x]='P';
  }
  else if (dungeon[(P.y-1*width)+(P.x)]=='T'){
    dungeon[(P.y*width)+P.x]=' ';
    P.y=P.y-1;
    int trap=2+ rand()%3;
    TrapStatements();
    dungeon[(P.y*width)+P.x]='P';
  }

}
// when player encounters an enemy, the player engages in combat.
void Combat(Player& Gay, int enemy){
  cout<<"You came across"<<enemy<<"enemies"<<endl;
  int attack,hit;
  while (Gay.alive=true && enemy>0){
    attack=rand()%100;
    if (attack <30){
      HitStatements();
      enemy=enemy-1;
      cout<<"killed 1"<<endl;
    }
    for (int i=0;i<enemy;i++){
      hit=rand()%100;
      if (hit<10){
        GetHitStatements();
        Gay.loseHealth();
        cout<<"got hit by enemy"<<endl;
      }
    }
  }


}  //when player falls into a trap represented by T
//3 statements that show at random when the player activates a trap
void TrapStatements(){
  int trap= rand()%3;
  if (trap==0){
    cout<<"You walked into some spikes that sprung out of the floor.\nYou lose a health :("<<endl;
  }
  else if(trap==1){
    cout<<"An arrow flew out of a nearby wall and hit you in the posterior.That will leave a scar!\nYou lose a health :("<<endl;

  }
  else{
    cout<<"You stepped into a bear trap and got yourself injured.\nYou lose a health :("<<endl;
  }

} 
//3 statements that show at random when the player finds food
void FoodStatements(){
  int fodder= 4 + rand()%5;
  if (fodder==4){
    cout<<"You looked at the food and it was a well cooked chicken...well at least looked well."<<endl;
  }
  else if(fodder==5){
    cout<<"Is it a breadroll in this dungeon? Maybe there is a gourmet bakery here"<<endl;
  }
  else{
    cout<<"IT IS A RAT AS BIG AS A RABBIT! It will go down well with a bit of wasp juice."<<endl;
  }

} 
  //3 statements that show at random when the player hits enemy
void HitStatements(){
  int punch=rand()%3;
  if (punch==1){
    cout<<"Your speed is unmatched and delivered a Stone Cold Stunner,\nYou killed an enemy!!."<<endl;
  }
  else if (punch==2){
    cout<<"Your roundhouse kick sent your enemy flying right into a gutter,\nYou killed an enemy!!."<<endl;

  }
  else{
    cout<<"You made an excellent jab that knocked the lights out of your enemy,\nYou killed an enemy!!."<<endl;
  }
}
// when the enemy hits the player back.
void GetHitStatements(){
  int punch=rand()%3;
  if (punch==1){
    cout<<"The enemy avoided your attack and gave you a nasty scratch,\nYou lose one health."<<endl;
  }
  else if (punch==2){
    cout<<"The enemy threw a rock that hit you on the temple and shook you bad,\nYou lose one health."<<endl;

  }
  else{
    cout<<"You were not prepared for a sudden lunging attack that hit you hard,\nYou lose one health."<<endl;
  }
} 

void display_dungeon(int width,int height, char dungeon_array[])
{ 
  int counter=1;
  for (int row=0 ; row< (width* height) ; row++)
  {
    if (counter%width==0)
    {
      cout << dungeon_array[row];
      cout << endl;
    }
    else
    {
      cout << dungeon_array[row] ;
  
    }
    counter++;
  }
}
char* CreateDungeon(int width, int height){
    char* dungeon = new char[width*height];
    srand(time(NULL));
    for (int x=0; x<height; x++){
      for(int y=0;y<width; y++){
        if ((x==0) || (x==height-1)){
        dungeon[(width*x)+y]='w';}
        else{
        if((y==0) || (y==width-1)){
        dungeon[(width*x)+y]='w';}
        else{
        int random_placer= rand()%100;
        if (random_placer>20)
        {
        dungeon[(width*x)+y]=' ';
        }
        else{
        int placer= rand()%100; 

        if(placer<=15){ dungeon[(x*width)+y]='E';}
        else if(placer>15 && placer<=30){dungeon[(x*width)+y]='H';}
        else if(placer>30 && placer<=45){dungeon[(x*width)+y]='T';}
        else if(placer>45 && placer<=60){dungeon[(x*width)+y]='F';}
        else if(placer>60){dungeon[(x*width)+y]='w';}
        }
        }
      }

      }
        }
   return dungeon;
}
char* P_X_placer(int width, int height, char* dungeon, Point& P, Point& X){
  int p_space_count = 0;
  int x_space_count = 0;
  for(int len = 0; len < height*width; len++ ){ //looking for empty spaces in leftmost and right most columns to place P and X.
    if ((len%width==1)&&(dungeon[len]==' ')){
      p_space_count++;
    }
    if ((len%width==width-2)&&(dungeon[len]==' ')){
      x_space_count++;
    }
  }
    if (p_space_count==0){
      dungeon[(1*width)+1]='P';
    }
    if (x_space_count==0){
      dungeon[((width-2)*width)+height-2]='X';
    }
    else{
      int P_placer=rand() % p_space_count+1;
      int X_placer=rand() % x_space_count+1;
      for(int i= 0; i < height; i++){
        if(i==P_placer){
          dungeon[(i*width)+1]='P';
          P.y=i;
          P.x=1;
        }
        if(i==X_placer){
          dungeon[(i*width)+width-2]='X';
          X.y=i;
          X.x=width-2;
        }
        }
      }
  
  return dungeon;
} 

//traversal functions here
void Traversal(char* dungeon, Point& startPoint, cPoint& exitPoint, cint width, cint height)
{
    Player Gay;
    bool won=false;
    char move;
    while(((Gay.food!=0) && (Gay.health!=0)) && ((startPoint.x!=exitPoint.x) || (startPoint.y != exitPoint.y)))
    {
    cout << "In which direction would you like to move?(press 'U' for up, 'D' for down, 'L' for left, 'R' for right, press 'X' to give up and die in the dark abyss that is the dungeon.): ";
    cin >> move;
    if ((move=='r') || (move=='R'))
    { 
      right(width,height, dungeon, startPoint, Gay);
      display_dungeon(width,height, dungeon);
    
    }
    if ((move=='l') || (move=='L'))
    { 
      left(width,height, dungeon, startPoint, Gay);
      display_dungeon(width,height, dungeon);
    }
    if ((move=='d') || (move=='D'))
    { 
      down(width,height, dungeon, startPoint, Gay);
      display_dungeon(width,height, dungeon);
    }
    if ((move=='u') || (move=='U'))
    { 
      up(width,height, dungeon, startPoint, Gay);
      display_dungeon(width,height, dungeon);
    }

    }
}


int main() {
  Point startPoint(0,0);
  Point exitPoint(0,0);
  int height=0;
  int width=0;
  cout << "Height: ";
  cin>>height;
  cout << "Width: ";
  cin >> width;
  char* dungeon=0;
  dungeon=CreateDungeon(width,height);
  dungeon=P_X_placer(width, height, dungeon, startPoint,exitPoint);
 
  display_dungeon(width,height, dungeon);
  Traversal(dungeon, startPoint, exitPoint, width, height);
  return 0;

}
