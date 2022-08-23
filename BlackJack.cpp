#include <bits/stdc++.h>
using namespace std;

/*
    Theory
    BlackJack Game
    It is a 2 player game, where one of the player is CPU dealer and other is the user.
    In this game, some amount of money is their with the user. There is a deck of cards. User always starts
    first in the game. User and CPU have 2 cards each initially. 
    Every player (user or CPU) has to make 2 choices
        1. Hit (picks up a card from the deck)
        2. Stay (do not pick up)
    Both the players try to bring their cards sum closer to 21 (but less than 21 only)

    Now as user starts the turn, user decides whether to pick up a card or not .
    If the user cards sum went over 21 while picking, then user loses.
    If user stays, then now is the turn of CPU
    CPU picks the cards until it either beat the player or busts.

    In the end, the player with the sum closest to 21 (<=21) wins.
    If any player has sum over 21, that player is busted and the other player wins
    If user loses, then the user loses all the money the user bets
    If dealer loses, then user recieves double the bet money and wins
    
    Note that ace can be either considered as 11 or 1 according to the requirement 
    Jack Queen King are considered as 10

    In our simpler version of BlackJack, on the dealer's turn, dealer always pick until dealer busts,
    or dealer beats the player
*/
bool isNumber(string &s){
    for(int i=0;i<s.length();i++){
        if(!isdigit(s[i]))
            return false;
    }
    return true;
}
pair<string, int> get_a_card(unordered_map<string,int> &deck, int x){
    pair<string, int> ans;
    int temp=1;
    for(auto p:deck){
        if(temp==x){
            ans={p.first,p.second};
            break;
        }
        else
            temp++;
    }   
    deck.erase(ans.first);
    return ans;
}
void printCards(vector<string> &dealerCards, vector<string> &playerCards, string &name){
    cout<<"\nDealers's Cards: \n";
    cout<<"\tHidden\n";
    for(int i=1;i<dealerCards.size();i++){
        cout<<"\t"<<dealerCards[i]<<"\n";
    }
    cout<<endl;
    
    cout<<name<<"'s Cards: \n";
    for(int i=0;i<playerCards.size();i++){
        cout<<"\t"<<playerCards[i]<<"\n";
    }
    cout<<endl;
}
int main()
{
    // code
    srand (time(NULL));
    cout<<"\n\t\t\t\tWelcome to the game => BlackJack"<<endl;
    cout<<"Here are some basic information for the game:\n";
    cout<<"It is a single player game. There is one player and other is the CPU dealer"<<endl;
    cout<<"You initially have 100 chips and you can play the game until you have chips in your hand"<<endl;
    cout<<"If you win the game, you will get double the chips you bet"<<endl;

    cout<<"\nRules to play the game\n";
    cout<<"Player and the dealer will be initially 2 cards each. Dealer will have one card face up and other face down.\n";
    cout<<"You will be able to see your 2 cards\n";
    cout<<"Then you are asked, either to hit(take a new card) or stay(dealer's turn)\n";
    cout<<"You have to hit or stay keeping in mind that you have to get sum closest to 21 but less than it\n";
    cout<<"Same dealer will do\n";

    cout<<"If your sum exceed 21, you lose. If dealer sum exceed 21, dealer lose else the one having sum closest to 21 but less than it wins\n";
    //heart, spade, club, diamond
    unordered_map<string, int> mp;
    mp["Two of Hearts"]=2;    
    mp["Two of Spade"]=2;
    mp["Two of Club"]=2;
    mp["Two of Diamond"]=2;
    mp["Three of Hearts"]=3;
    mp["Three of Spade"]=3;
    mp["Three of Club"]=3;
    mp["Three of Diamond"]=3;
    mp["Four of Hearts"]=4;
    mp["Four of Spade"]=4;
    mp["Four of Club"]=4;
    mp["Four of Diamond"]=4;
    mp["Five of Hearts"]=5;
    mp["Five of Spade"]=5;
    mp["Five of Club"]=5;
    mp["Five of Diamond"]=5;
    mp["Six of Hearts"]=6;
    mp["Six of Spade"]=6;
    mp["Six of Club"]=6;
    mp["Six of Diamond"]=6;
    mp["Seven of Hearts"]=7;
    mp["Seven of Spade"]=7;
    mp["Seven of Club"]=7;
    mp["Seven of Diamond"]=7;
    mp["Eight of Hearts"]=8;
    mp["Eight of Spade"]=8;
    mp["Eight of Club"]=8;
    mp["Eight of Diamond"]=8;
    mp["Nine of Hearts"]=9;
    mp["Nine of Spade"]=9;
    mp["Nine of Club"]=9;
    mp["Nine of Diamond"]=9;
    mp["Ten of Hearts"]=10;
    mp["Ten of Spade"]=10;
    mp["Ten of Club"]=10;
    mp["Ten of Diamond"]=10;
    mp["Jack of Hearts"]=10;
    mp["Jack of Spade"]=10;
    mp["Jack of Club"]=10;
    mp["Jack of Diamond"]=10;
    mp["Queen of Hearts"]=10;
    mp["Queen of Spade"]=10;
    mp["Queen of Club"]=10;
    mp["Queen of Diamond"]=10;
    mp["King of Hearts"]=10;
    mp["King of Spade"]=10;
    mp["King of Club"]=10;
    mp["King of Diamond"]=10;
    mp["Ace of Hearts"]=11;
    mp["Ace of Spade"]=11;
    mp["Ace of Club"]=11;
    mp["Ace of Diamond"]=11;

    int total_chips=100;
    unordered_map<string , int> deck;

    while(1)  // playing loop
    {
        deck=mp;
        cout<<"Enter your name"<<endl;
        string name;
        cin>>name;

        cout<<"Enter the amount of the chips you want to bet: (You have "<<total_chips<<" left)"<<endl;
        string bet_chips;
        while(1){
            cin>>bet_chips;
            if(!isNumber(bet_chips))
            {
                cout<<"Enter valid number of chips"<<endl;
                continue;
            }
            else if(stoi(bet_chips)>total_chips)
            {
                cout<<"You do not have sufficient chips"<<endl;
                continue;
            }
            else{
                total_chips-=stoi(bet_chips);
                break;
            }
        }
        
        // tell the dealer cards and your cards;
        vector<string> dealerCards;
        vector<string> playerCards;

        int remainingCards=52;
        int playerSum=0, dealerSum=0;

        auto pp=get_a_card(deck, rand()%remainingCards+1); //string and number
        dealerCards.push_back(pp.first);
        dealerSum+=pp.second;
        remainingCards--;

        pp=get_a_card(deck, rand()%remainingCards+1);
        dealerCards.push_back(pp.first);
        if(dealerSum+pp.second == 22)
            dealerSum+=1;
        else
            dealerSum+=pp.second;
        remainingCards--;

        pp=get_a_card(deck, rand()%remainingCards+1);
        playerCards.push_back(pp.first);
        playerSum+=pp.second;
        remainingCards--;

        pp=get_a_card(deck, rand()%remainingCards+1);
        playerCards.push_back(pp.first);
        if(playerSum+pp.second == 22)
            playerSum+=1;
        else
            playerSum+=pp.second;
        remainingCards--;
        
        printCards(dealerCards, playerCards, name);

        cout<<name<<"'s turn"<<endl;
        cout<<"Choose Hit(h) or Stay(s)"<<endl;
        char choice;

        while(1)
        {
            while(1)
            {
                cin>>choice;
                if(choice!='h' and choice!='s'){
                    cout<<"Enter a valid input (h/s)"<<endl;
                    continue;
                }
                else{
                    break;
                }
            }
            if(choice == 'h'){
                pp=get_a_card(deck, rand()%remainingCards+1);
                playerCards.push_back(pp.first);
                playerSum+=pp.second;
                if(pp.second==11 and playerSum>21){
                    playerSum-=(11-1);
                }
                remainingCards--;

                printCards(dealerCards, playerCards, name);
                if(playerSum>21){
                    cout<<name<<" lost (Sum went over 21)\n";
                    break;
                }

                cout<<"Choose Hit(h) or Stay(s)"<<endl;
                continue;
            }
            else{
                cout<<"\nDealer's Turn";
                while(dealerSum<=playerSum and dealerSum<=21){
                    pp=get_a_card(deck, rand()%remainingCards+1);
                    dealerCards.push_back(pp.first);
                    dealerSum+=pp.second;
                    if(pp.second==11 and dealerSum>21){
                        dealerSum-=(11-1);
                    }
                    remainingCards--;
                }
                // printCards(dealerCards, playerCards, name);
                if(dealerSum>21){
                    cout<<"\nDealers's Cards: \n";
                    for(int i=0;i<dealerCards.size();i++){
                        cout<<"\t"<<dealerCards[i]<<"\n";
                    }
                    cout<<endl;
                    
                    cout<<name<<"'s Cards: \n";
                    for(int i=0;i<playerCards.size();i++){
                        cout<<"\t"<<playerCards[i]<<"\n";
                    }
                    cout<<endl;
                    cout<<"Dealer Busted, "<<name<<" wins\n";
                    total_chips+=2*stoi(bet_chips);
                    break;
                }
                else if(dealerSum>playerSum){
                    cout<<"\nDealers's Cards: \n";
                    for(int i=0;i<dealerCards.size();i++){
                        cout<<"\t"<<dealerCards[i]<<"\n";
                    }
                    cout<<endl;
                    
                    cout<<name<<"'s Cards: \n";
                    for(int i=0;i<playerCards.size();i++){
                        cout<<"\t"<<playerCards[i]<<"\n";
                    }
                    cout<<endl;
                    cout<<name<<" lost\n";
                    break;
                }
            }
        }
        cout<<name<<" has "<<total_chips<<" chips left\n";
        cout<<"Do you want to play again (Y/N) ??\n";

        string out;
        while(1){
            cin>>out;
            if(out!="Y" and out!="N"){
                cout<<"Enter a Valid Input"<<endl;
            }
            else{
                break;
            }
        }

        if(out=="Y" and total_chips<=0){
            cout<<"You do not have sufficient chips to play further. Come back tomorrow\n";
            break;
        }
        else if(out=="Y"){
            cout<<"-------------------------------------------------\n";
            continue;
        }
        else{
            cout<<"Thanks for Playing\n";
            break;
        }
    }
    return 0;
}