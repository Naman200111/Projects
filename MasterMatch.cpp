#include <bits/stdc++.h>
using namespace std;

bool isValid(string &word)
{
    if(word.length()!=4)
        return false;
    for(int i=0;i<word.length();i++)
    {
        if(word[i]=='r' || word[i]=='b' || word[i]=='g' || word[i]=='v' || word[i]=='p' || word[i]=='w' || word[i]=='o')
            continue;
        else   
            return false;    
    }
    return true;
}

int findCorrectColor(string &code, string &guessedCode)
{
    unordered_map<char, int> mp;
    for(int i=0;i<code.length();i++)
        mp[code[i]]++;

    int ans=0;
    for(int i=0;i<guessedCode.length();i++)
    {
        if(mp.find(guessedCode[i]) != mp.end())
        {
            ans++;
            mp[guessedCode[i]]--;
        }
    }
    return ans;
}

int findCorrectPosColor(string &code, string &guessedCode)
{
    int i=0,j=0;
    int ans=0;
    while(i<code.length())
    {
        if(code[i]==guessedCode[i])
            ans++;
        i++;
    }
    return ans;
}

int main()
{
    // code
    cout<<"\n\t\t\t\tWelcome to the game => MasterMatch"<<endl;
    cout<<"Here are some basic information for the game:\n";
    cout<<"It is a 2 player game."<<endl;
    
    cout<<"There are 7 colours (Red, Blue, Green, Violet, Pink, White, orange), and both of the players are asked to enter their 4 color code (Repeatation is allowed)."<<endl;
    cout<<"After then both the players will get chance one by one and they have to guess the colour combination of theie opponents."<<endl;
    cout<<"After every guess you will be given 2 informations, number of correct colors you chose and the number of places(out of 4) where placed colour and the actual colorare same."<<endl;
    cout<<"Accordingly both player try to guess the pattern of the other and the one whose guessed the code correctly wins !!"<<endl;
    cout<<"If after 10 turns nobody was able to guess the codes then the game will end as DRAW and codes will be revealed."<<endl;

    while(1)
    {
        cout<<"Let's Start !!"<<endl;
        cout<<"Enter the name of first player"<<endl;

        string player1;
        cin>>player1;

        cout<<"\nEnter the name of of second player"<<endl;
        
        string player2;
        cin>>player2;
        
        cout<<player1<<" will set up the 4 color code and "<<player2<<" will face away using r,b,g,v,p,w,o."<<endl;
        string code1;
        while(1)
        {
            cin>>code1;
            if(isValid(code1) == false)
            {
                cout<<"Enter a 4 color valid code made of (r,b,g,v,p,w,o)."<<endl;
                continue;
            }
            break;
        }
        
        for(int i=0;i<=100;i++)
            cout<<"\n";
        cout<<endl;

        cout<<player2<<" will set up the 4 color code and "<<player1<<" will face away using r,b,g,v,p,w,o."<<endl;
        string code2;
        while(1)
        {
            cin>>code2;
            if(!isValid(code2))
            {
                cout<<"Enter a 4 color valid code made of (r,b,g,v,p,w,o)."<<endl;
                continue;
            }
            break;
        }

        for(int i=0;i<=100;i++)
            cout<<"\n";
        cout<<endl;

        int x = rand()%10;
        string playerName, playerCode;

        if(x<5)
        {
            cout<<player1<<" will go first"<<endl;
            playerName=player1;
            playerCode=code2;
        }
        else 
        {
            cout<<player2<<" will go first"<<endl;
            playerName=player2;
            playerCode=code1;
        }

        int turn=1;
        while(turn<11)
        {
            cout<<"\nRound "<<turn<<endl;        
            cout<<playerName<<" enter the guessed pattern: (made of => r,b,g,v,p,w,o)"<<endl;

            string code;
            while(1)
            {
                cin>>code;
                if(!isValid(code))
                {
                    cout<<"Enter a valid code made of (r,b,g,v,p,w,o)."<<endl;
                    continue;
                }
                else
                    break;
            }
            
            if(code == playerCode)
            {
                cout<<playerName<<" wins"<<endl;
                cout<<player1<<" code was: "<<code1<<endl;
                cout<<player2<<" code was: "<<code2<<endl;
                break;
            }

            int correctColor = findCorrectColor(code, playerCode);
            int correctPosColor = findCorrectPosColor(code, playerCode);

            cout<<"There are "<<correctColor<<" colors matching"<<endl;
            cout<<"There are "<<correctPosColor<<" colors at the correct position"<<endl;

            if(playerName == player1)
            {
                playerName = player2;
                playerCode = code1;
            }
            else
            {
                playerName = player1;
                playerCode = code2;
            }

            cout<<"\n"<<playerName<<" enter the guessed pattern: (made of => r,b,g,v,p,w,o)"<<endl;
            while(1)
            {
                cin>>code;
                if(!isValid(code))
                {
                    cout<<"Enter a valid code made of (r,b,g,v,p,w,o)."<<endl;
                    continue;
                }
                else
                    break;
            }
            
            if(code == playerCode)
            {
                cout<<playerName<<" wins"<<endl;
                cout<<player1<<" code was: "<<code1<<endl;
                cout<<player2<<" code was: "<<code2<<endl;
                break;
            }

            correctColor = findCorrectColor(code, playerCode);
            correctPosColor = findCorrectPosColor(code, playerCode);

            cout<<"There are "<<correctColor<<" colors matching"<<endl;
            cout<<"There are "<<correctPosColor<<" colors at the correct position"<<endl;

            if(playerName == player1)
            {
                playerName = player2;
                playerCode = code1;
            }
            else
            {
                playerName = player1;
                playerCode = code2;
            }
            turn++;
        }

        if(turn == 11)
        {
            cout<<"Game ends as Draw !!"<<endl;
            cout<<player1<<" code was: "<<code1<<endl;
            cout<<player2<<" code was: "<<code2<<endl;
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
            cout<<"\n"<<player2<<" denied"<<endl;
            cout<<"Thanks For Playing"<<endl;
            break;
        }        
        else if(out2=='Y'){
            cout<<"\n"<<player1<<" denied"<<endl;
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