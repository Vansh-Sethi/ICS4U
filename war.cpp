#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>


using namespace std;

class Card {
    public:
        int cardNumber;
        string suit;
};

int main() {
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

    auto rng = default_random_engine {};
    shuffle(begin(cards), end(cards), rng);

    vector<Card> p1Cards(26);
    copy(cards.begin(), cards.begin()+26, p1Cards);

    for (Card i: p1Cards) {
        cout << i.cardNumber << " of " << i.suit + "\n";
    }
}



