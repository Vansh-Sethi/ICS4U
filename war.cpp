/*
=============================
ICS4U
Title: Game of War
Author: Vansh Sethi
=============================
*/

#include <iostream> // Getting User Input
#include <vector> // Storing Card Data
#include <string> // *Better than char arrays 
#include<string.h> // String Algos 
#include <map> // Map used for Tie Breaks
#include <algorithm> 
#include <random> // Used for Generating Random Numbers
#include <time.h> // Truly Random Numbers
using namespace std;


// Defining Custom Data Type 
class Card {
    public:
      int cardNumber; // Card Number
      string suit; // Suit
};

vector<Card> p1Cards; // Global Vector of Player 1 Cards
vector<Card> p2Cards; // Global Vector of Player 2 Cards
vector<Card> p1DiscardPile; // Global Vector of Player 1 Discard Pile
vector<Card> p2DiscardPile; // Global Vector of Player 2 Discard Pile

bool gameRunning = true; // Game Boolean Control
string Player1; // Player 1 Name
string Player2; // Player 2 Name

// Turns Card Numbers into Face Card (eg. 11 -> Jack)
string numberToCardNumber(int num) {
  if (num == 1) {
    return "Ace";
  }
  if (num == 11) {
    return "Jack";
  }
  if (num == 12) {
    return "Queen";
  } 
  if (num == 13) {
    return "King";
  }
  if (num == 14) {
    return "Ace";
  }
  else {
    return to_string(num);
  }
}

// Checking if the user already selected a card or puts a crazy number
int userCardSelection(int chosen[4]) {
  // Keep looping until they put in a valid selection
  while (true) {
    int a;
    cin >> a;
    // Checking if already selected
    bool chosenAlready = false;
    for (int i = 0; i < 4; i++) {
      if (chosen[i] == a) {
        chosenAlready = true;
      }
    }

    // If number is not between 1 - 4, not a valid selection
    if (a < 1 || a > 4) {
      cout << "Please Pick a number between 1 and 4: ";
    }
    // If number was already chosen, alert them
    else if (chosenAlready) {
      cout << "That number was already chosen: ";
    }
    // Return selection if Valid
    else {
      return a;
    }
  }
}

// Shuffle Deck of Cards Function
vector<Card> shuffleDeck(vector<Card> deck) {
  srand(time(NULL));
  for (int i = 0; i < deck.size(); i++) {
    int rand_num1 = (rand() % deck.size());
    int rand_num2 = (rand() % deck.size());
    Card temp = deck[rand_num1];
    deck[rand_num1] = deck[rand_num2];
    deck[rand_num2] = temp;
  }
  return deck;
}

// Function that Ends Game
void endGame(string Winner, string Loser) {
   // Print Player's Current Number of Cards
    cout << "\n" << Player1 << "'s Current Deck Cards: " << p1Cards.size() << "\n";

    cout << Player2 << "'s Current Deck Cards: " << p2Cards.size() << "\n";

  // Print Player's Current Number of Cards in Discard Pile
    cout << Player1 << "'s Discard Pile Cards: " << p1DiscardPile.size() << "\n";

    cout << Player2 << "'s Discard Pile Cards: " << p2DiscardPile.size() << "\n\n";

  cout << "\n" << "Unfortunately, " << Loser << " has less than 4 cards left." << "\n" << "Therefore, " << Winner << " is your winner! 🏆";
}

// Run Game Function
void runGame() {

  int roundNumber = 1; // Setting current round number to 1
  cout << Player1 << " VS. " << Player2;
  
  // While Game is Running (will stop when one player wins)
  while (gameRunning) {
    cout << "\n\n";
    vector<Card> p1CardsInPlay = {}; // Drawn Cards Vector
    vector<Card> p2CardsInPlay = {}; // Drawn Cards Vector

  // Print Current Round Number
    cout << "=========================" << "\n";
    cout << "         ROUND" << " " << roundNumber << 
    "          " << "\n";

  // Print Player's Current Number of Cards
    cout << Player1 << "'s Current Deck Cards: " << p1Cards.size() << "\n";

    cout << Player2 << "'s Current Deck Cards: " << p2Cards.size() << "\n";

  // Print Player's Current Number of Cards in Discard Pile
    cout << "\n" << Player1 << "'s Discard Pile Cards: " << p1DiscardPile.size() << "\n";

    cout << Player2 << "'s Discard Pile Cards: " << p2DiscardPile.size() << "\n\n";

    // Draw 4 Cards from Player1's Deck
    for (int i = 0; i < 4; i++) {
      p1CardsInPlay.push_back(p1Cards.back());
      p1Cards.erase(p1Cards.end());
    }

    // Draw 4 Cards from Player2's Deck
    for (int i = 0; i < 4; i++) {
      p2CardsInPlay.push_back(p2Cards.back());
      p2Cards.erase(p2Cards.end());
    }

// Player 1 Turn
    cout << Player1 << "'s Turn ⭐" << "\n" << "-------------" << "\n";
    cout << "Please select which cards you would like to play in order:" << "\n";

    // Print each card that was randomly drawn
    int cn = 1;
    for (Card i: p1CardsInPlay) {
      string cardNum = to_string(i.cardNumber);
      if (cardNum == "1") {
        cardNum = "Ace";
      }
      if (cardNum == "11") {
        cardNum = "Jack";
      }
      if (cardNum == "12") {
        cardNum = "Queen";
      }
      if (cardNum == "13") {
        cardNum = "King";
      }
      // Print Card
      cout << cn << ". " << cardNum << " of " << i.suit << "\n";
      cn++;
    }

    // Get User's Selection in What Order to Play Cards in
    int p1Turn[4] = {};
    cout << "First Card: ";
    p1Turn[0] = userCardSelection(p1Turn);
    cout << "Second Card: ";
    p1Turn[1] = userCardSelection(p1Turn);
    cout << "Third Card: ";
    p1Turn[2] = userCardSelection(p1Turn);
    cout << "Fourth Card: ";
    p1Turn[3] = userCardSelection(p1Turn);

// New lines to disallow Player 2 from seeing selections
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

// Player 2 Turn
    cout << Player2 << "'s Turn ⭐" << "\n" << "-------------" << "\n";
    cout << "Please select which cards you would like to play in order:" << "\n";

    // Print each card that was randomly drawn
    cn = 1;
    for (Card i: p2CardsInPlay) {
      string cardNum = to_string(i.cardNumber);
      if (cardNum == "1") {
        cardNum = "Ace";
      }
      if (cardNum == "11") {
        cardNum = "Jack";
      }
      if (cardNum == "12") {
        cardNum = "Queen";
      }
      if (cardNum == "13") {
        cardNum = "King";
      }
      // Print Card
      cout << cn << ". " << cardNum << " of " << i.suit << "\n";
      cn++;
    }

    // Get User's Selection in What Order to Play Cards in
    int p2Turn[4] = {};
    cout << "First Card: ";
    p2Turn[0] = userCardSelection(p2Turn);
    cout << "Second Card: ";
    p2Turn[1] = userCardSelection(p2Turn);
    cout << "Third Card: ";
    p2Turn[2] = userCardSelection(p2Turn);
    cout << "Fourth Card: ";
    p2Turn[3] = userCardSelection(p2Turn);

// "Clear" Screen
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";


// Start the Battle
    cout << "\n" <<"Battle Commencing ⚔️"  << "\n-------------" << "\n";
    

    // Check Winner for Each Selection
    for (int i = 0; i < 4; i++) {
      // Get Selected Cards for Both Players
      int pick1 = p1Turn[i] - 1;
      int pick2 = p2Turn[i] - 1;
      Card p1Card = p1CardsInPlay[pick1];
      Card p2Card = p2CardsInPlay[pick2];
      string winner; // Winner Variable Initalization

      // Dealing with Ace Edge Cases
      if (p1Card.cardNumber == 1) {
        p1Card.cardNumber = 14;
      }
      if (p2Card.cardNumber == 1) {
        p2Card.cardNumber = 14;
      }

    // If numerical tie, determine via Suit
      if (p1Card.cardNumber == p2Card.cardNumber) {
        map<string, int> suitToNum = {{"Clubs" , 4}, {"Diamonds" , 3}, {"Hearts", 2}, {"Spades", 1}};
        int p1SuitNum = suitToNum[p1Card.suit];
        int p2SuitNum = suitToNum[p2Card.suit];

        if (p1SuitNum > p2SuitNum) {
          winner = Player1;
        }
        else {
          winner = Player2;
          cout << "L";
        }
      }

    // If Player 1 Higher Number, Player1 is winner
      else if (p1Card.cardNumber > p2Card.cardNumber) {
        winner = Player1;
      }
    // Otherwise, Playre2 is winner
      else {
        winner = Player2;
      }

      // Turn numbers into face card (Eg. 11 -> Jack)
      string p1CardNumber = numberToCardNumber(p1Card.cardNumber);
      string p2CardNumber = numberToCardNumber(p2Card.cardNumber);

// Print who won that certain battle
      cout << p1CardNumber << " of " << p1Card.suit << " VS. " << p2CardNumber << " of " << p2Card.suit << " (" << winner << " Wins)" <<"\n";

// Put cards into player's discard pile if they won that certain battle
      if (winner == Player1) {
        p1DiscardPile.push_back(p1CardsInPlay[pick1]);
        p1DiscardPile.push_back(p2CardsInPlay[pick2]);
      }
      if (winner == Player2) {
        p2DiscardPile.push_back(p1CardsInPlay[pick1]);
        p2DiscardPile.push_back(p2CardsInPlay[pick2]);
      }
    }

// Check if Player 1 has lost
    if (p1Cards.size() <= 3) {
      p1Cards.insert(p1Cards.end(), p1DiscardPile.begin(), p1DiscardPile.end());
      p1DiscardPile.clear();
      p1Cards = shuffleDeck(p1Cards);
      if (p1Cards.size() <= 3) {
        endGame(Player2, Player1);
        gameRunning = false;
      }
    }

// Check if Player 2 has lost
    if (p2Cards.size() <= 3) {
      p2Cards.insert(p2Cards.end(), p2DiscardPile.begin(), p2DiscardPile.end());
      p2DiscardPile.clear();
      p2Cards = shuffleDeck(p2Cards);

      if (p2Cards.size() <= 3) {
        endGame(Player1, Player2);
        gameRunning = false;
      }

    }
        
// Increment Round Number
    roundNumber++;
   
  }
}

// Initalize Game
int main() {

  // Create Deck of Cards
    vector<Card> cards;
    for (int i = 1; i <= 4; i++) {
        string suit;
        if (i == 1) {
            suit = "Clubs";
        }
        if (i == 2) {
            suit = "Diamonds";
        }
        if (i == 3) {
            suit = "Hearts";
        }
        if (i == 4) {
            suit = "Spades";
        }
        for (int j = 1; j<=13; j++) {
            Card newCard;
            newCard.cardNumber = j;
            newCard.suit = suit;
            cards.push_back(newCard);
        }
    }

  // Shuffle Cards
  cards = shuffleDeck(cards);

  // Split Cards
    for (int i = 0; i < 26; i++) {
      p1Cards.push_back(cards[i]);
    }
    for (int i = 26; i < 52; i++) {
      p2Cards.push_back(cards[i]);
    }

    // Get User's Names
    cout << "Enter Player 1's Name: ";
    cin >> Player1;
    cout << "Enter Player 2's Name: ";
    cin >> Player2;

    // Run Game
    runGame();
}

