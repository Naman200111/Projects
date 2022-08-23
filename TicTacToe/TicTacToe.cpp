#include <bits/stdc++.h>
using namespace std;

/* 
    Welcome to the game of Tic-Tac-Toe
    The game is designed to played by 2 players
    Its a normal TicTacToe game where one player chooses X and the other gets O or vice-versa
    Whenever a player wins, the game is ended and the name of the player is printed
*/

/*
    things to do for easier implementation
    first print welcome to tictactoe
    then ask for the names of the players
    then randomly ask anyone to choose first and assign another automatically
    then the game starts

    ask the first player to make a move by choosing number from 1-9
    if a player chooses occupied position ask the person again to enter valid position
    then ask 2nd player to move
    then 2nd player chooses a position and place the symbol of this player accordingly
    always check for valid positions
    every time a move is made print the resulting board to help next player to move

    once you get 3 similar values in any row,column or diagonal print the corresponding player to have won the game
    and game ends

    ask both the users whether to play or not and both the players should accept for next turn to continue the game
*/

// implementation
void print(vector<vector<char>> &matrix)
{
    for(int i=0;i<3;i++)
    {
        if(i>0){
            cout<<"\t\t\t-----------"<<endl;
        }
        for(int j=0;j<3;j++)
        {
            if(j==0)
                cout<<"\t\t\t "<<matrix[i][j]<<" "<<"|";
            else if(j==1)
                cout<<" "<<matrix[i][j]<<" "<<"|";
            else
                cout<<" "<<matrix[i][j]<<" "<<endl;
        }
    }   
}
bool isFull(vector<vector<char>> &matrix){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(matrix[i][j]==' ')
                return false;
        }
    }
    return true;
}
pair<int, int> findCoor(string &x, vector<vector<char>> &matrix){
    if(x=="1")
        return {2,0};
    else if(x=="2")
        return {2,1};
    else if(x=="3")
        return {2,2};
    else if(x=="4")
        return {1,0};
    else if(x=="5")
        return {1,1};
    else if(x=="6")
        return {1,2};
    else if(x=="7")
        return {0,0};
    else if(x=="8")
        return {0,1};
    else if(x=="9")
        return {0,2};
    else
        return {-1,-1};
}
bool wincheck(vector<vector<char>> &matrix, char c){
    // row or column or diagonal filled with c
    int i,j;

    //row check
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(matrix[i][j]!=c)
                break;
        }
        if(j==3)
            return true;
    } 

    //column check
    for(j=0;j<3;j++){
        for(i=0;i<3;i++){
            if(matrix[i][j]!=c)
                break;
        }
        if(i==3)
            return true;
    } 

    //diagonal check
    if(matrix[0][0]==c and matrix[1][1]==c and matrix[2][2]==c)
        return true;
    if(matrix[0][2]==c and matrix[1][1]==c and matrix[2][0]==c)
        return true;

    return false;
}
int main()
{
    cout<<"\n\t\t\t\tWelcome to the game => Tic-Tac-Toe"<<endl;
    cout<<"Here are some basic information for the game:\n";
    cout<<"It is a co-op game (made for 2 players), one having X as symbol and other has O."<<endl;

    int dummy[3][3];
    dummy[0][0]=7;
    dummy[0][1]=8;
    dummy[0][2]=9;
    dummy[1][0]=4;
    dummy[1][1]=5;
    dummy[1][2]=6;
    dummy[2][0]=1;
    dummy[2][1]=2;
    dummy[2][2]=3;

    cout<<"You have to place X and O keeping in mind the following numbers corresponding to each place in the 3*3 grid of the game.\n\n";
    for(int i=0;i<3;i++)
    {
        if(i>0){
            cout<<"\t\t\t-----------"<<endl;
        }
        for(int j=0;j<3;j++)
        {
            if(j==0)
                cout<<"\t\t\t "<<dummy[i][j]<<" "<<"|";
            else if(j==1)
                cout<<" "<<dummy[i][j]<<" "<<"|";
            else
                cout<<" "<<dummy[i][j]<<" "<<endl;
        }
    }

    while(1)
    {
        cout<<"\nLets Start"<<endl;
        string player1,player2;

        cout<<"Enter the name of the first player"<<endl;
        cin>>player1;
        cout<<"\nEnter the name of the second player"<<endl;
        cin>>player2;

        int x=rand()%10+1;
        string playerName;
        char playerchar;

        if(x<=5)
            playerName=player1;
        else   
            playerName=player2;

        cout<<"\n"<<playerName<<" goes first"<<endl;
        cout<<playerName<<" choose whether to take X or O"<<endl;

        char cplayer1,cplayer2;
        while(1){
            cin>>cplayer1;
            if(cplayer1=='X' || cplayer1=='O'){
                playerchar=cplayer1;
                break;
            }
            else{
                cout<<"Choose a valid symbol ('X' or 'O')"<<endl;
                continue;
            }
        }

        if(cplayer1=='X')
            cplayer2='O';
        else
            cplayer2='X';

        // cout<<cplayer1<<" "<<cplayer2<<endl;
        vector<vector<char>> matrix (3,vector<char>(3));
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                matrix[i][j]=' ';

        cout<<"\nInitially the Board is:\n";
        print(matrix);

        bool full=false;

        while(1)
        {
            if(isFull(matrix)){
                    full=true;
                    break;
            }
            string val;
            cout<<"\n"<<playerName<<" choose a position from (1-9) both included"<<endl;
            pair<int, int> coordinates;

            while(1)
            {    
                cin>>val;
                coordinates=findCoor(val,matrix); 

                if(coordinates.first == -1 and coordinates.second == -1)
                {
                    cout<<"Enter a valid position from (1-9) both included."<<endl;
                    continue;
                }
                else if(matrix[coordinates.first][coordinates.second]!=' ')
                {
                    cout<<"Enter a position which is unoccupied."<<endl;
                    continue;
                }
                else
                    break;
            }

            matrix[coordinates.first][coordinates.second]=playerchar;
            print(matrix);
    
            if(wincheck(matrix, playerchar)) // diagonal
                break;

            if(playerName==player1){
                playerName=player2;
                if(playerchar=='X')
                    playerchar='O';
                else
                    playerchar='X';
            }
            else{
                playerName=player1;
                if(playerchar=='X')
                    playerchar='O';
                else
                    playerchar='X';
            }
        }

        // matrix full or a player wins
        if(full){
            cout<<"Game ended as a draw !!"<<endl;
        }
        else{
            cout<<playerName<<" wins the game"<<endl;
        }
       
        cout<<"\n"<<player1<<" do you want to play again (Y/N)?"<<endl;
        char out1,out2;
        
        while(1){
            cin>>out1;
            if(out1=='Y' || out1=='N')
                break;
            else{
                cout<<player1<<" enter a valid value."<<endl;
                continue;
            }
        }

        cout<<"\n"<<player2<<" do you want to play again (Y/N)?"<<endl;
        while(1){
            cin>>out2;
            if(out2=='Y' || out2=='N')
                break;
            else{
                cout<<player2<<" enter a valid value."<<endl;
                continue;
            }
        }

        if(out1=='Y' and out2=='Y')
        {
            cout<<"--------------------------------------------------------"<<endl;
            continue;
        }
        else if(out1=='Y'){
            cout<<"\n"<<player2<<" rejected to play the game"<<endl;
            cout<<"Thanks For Playing"<<endl;
            break;
        }        
        else if(out2=='Y'){
            cout<<"\n"<<player1<<" rejected to play the game"<<endl;
            cout<<"Thanks For Playing"<<endl;
            break;
        }
        else{
            cout<<"\nThanks For Playing"<<endl;
            break;
        }
    }
    return 0;
}


