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