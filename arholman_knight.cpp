#include<iostream>

using namespace std;




class Knight

{

public:


  bool valid_pos (int row, int col, int size);

  void display_board(int size);

  void recursive (int row, int col, int size, int count);

  int check_board(int size);


};


//Global vars                                                                                                                                                                     

const int size=8;//Board size                                                                                                                                                     

int board[size][size];  //Create board                                                                                                                                            




int main()

{

  Knight check;

  int row, col, count=0;



  for(int a=0;a<=size;a++) //clear board to 0                                                                                                                                     

    {

      for(int b=0;b<=size;b++)

        {

          board[a][b]=0;

        }

    }


  //Take input                                                                                                                                                                    

  cout<<"Enter the start row of the knight: ";

  cin>>row;

  cout<<"Enter the starting column of the knight: ";

  cin>>col;


  check.valid_pos (row, col, size);


  //Output results                                                                                                                                                                


  check.recursive(row, col, size, count);

  check.display_board(size);


  return 0;

}


bool Knight::valid_pos (int row, int col, int size){

  if(row>=size || col>=size ||  row<0 || col<0){//Test for chosen location being within board dimensions                                                                          

    return 1;


  }

  else{//Check to see if location was not previously visited                                                                                                                      

    if((board[row][col]) == 0){

      return 0;


    }

    else{//returns 1 if location previously visited                                                                                                                               

      return 1;


    }

  }

}


void Knight::display_board(int size)

{

  for(int c=0;c<size;c++)

    {

      for(int d=0;d<size;d++)

        {

          if(d==size-1)

            {

              cout<<"| "<<board[c][d]<<" |"<<endl;

            }

          else

{

              cout<<"| "<<board[c][d]<<" ";

            }

        }

    }

}



int Knight::check_board(int size)

{

  int rows, cols, checker;


  for(rows=0;rows<size;rows++)

    {

      for(cols=0;cols<size;cols++)

        {

          if(valid_pos(rows,cols,size)!=1)

            {

              checker=0;

            }

        }

    }

  return(checker);

}


void Knight::recursive(int row, int col, int size, int count)

{


  int checked;


  board[row][col]=count;


  if(valid_pos (row+2, col+1, size)!=1){

    count++;

    recursive(row+2, col+1, size, count);

    checked=check_board(size);

    if(checked==0){

      board[row+2][col+1]=0;

      count--;

    }

  }

  if(valid_pos (row+2, col-1, size)!=1){

    count++;

    recursive(row+2, col-1, size, count);

    checked=check_board(size);

    if(checked==0){

      board[row+2][col-1]=0;

      count--;


    }

  }

if(valid_pos (row+1, col+2, size)!=1){

    count++;

    recursive(row+1, col+2, size, count);

    checked=check_board(size);

    if(checked==0){

      board[row+1][col+2]=0;

      count--;

    }

  }

  if(valid_pos (row+1, col-2, size)!=1){

    count++;

    recursive(row+1, col-2, size, count);

    checked=check_board(size);

    if(checked==0){

      board[row+1][col-2]=0;

      count--;

    }

  }

  if(valid_pos(row-2, col+1, size)!=1){

    count++;

    recursive(row-2, col+1, size, count);

    checked=check_board(size);

    if(checked==0){

      board[row-2][col+1]=0;

      count--;

    }

  }


if(valid_pos (row-2, col-1, size)!=1){

    count++;

    recursive(row-2, col-1, size, count);

    checked=check_board(size);

    if(checked==0){

      board[row-2][col-1]=0;

      count--;

    }

  }

  if(valid_pos (row-1, col+2, size)!=1){

    count++;

    recursive(row-1, col+2, size, count);

    checked=check_board(size);

    if(checked==0){

      board[row-1][col+2]=0;

      count--;

    }

  }

  if(valid_pos (row-1, col-2, size)!=1){

    count++;

    recursive(row-1, col-2, size, count);

    checked=check_board(size);

    if(checked==0){

      board[row-1][col-2]=0;

      count--;

    }

  }


checked=check_board(size);

  if(checked==0){

    board[row][col]=0;

    count--;

  }

}
