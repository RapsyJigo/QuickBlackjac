#include <iostream>
#include "deck.h"

using namespace std;

int main()
{
    initializer();
    shuffleDeck();
int playerDecision;
    int i = 0;
playerDecision = 1;
    while (playerDecision)
    {int playerValue = 0, dealerValue = 0, secretDealerValue = 0;


    if (i >= 52)
    {
        i = 0;
        shuffleDeck();
    }

    playerValue = 0;

    cout << codeToCard(cards[i]) << endl;

    if (cards[i] % 13 == 0)
    {
        cout << "Alege valoarea asului: \n";
        cout << "1 sau 11\n";
        cin >> playerDecision;
        if (playerDecision > 1)
            playerValue += 11;
        else
            playerValue += 1;
    }
    else
        if (cards[i] % 13 < 10)
            playerValue += cards[i]%13 + 1;
        else
            playerValue += 10;

    i++;
    if (i >= 52)
    {
        i = 0;
        shuffleDeck();
    }

    secretDealerValue += cards[i];
    cout << "Dealerul are: " << codeToCard(cards[i] ) << " si o carde ascunsa\n";
    i++;
    if (i >= 52)
    {
        i = 0;
        shuffleDeck();
    }

    secretDealerValue += cards[i];
    i++;
    if (i >= 52)
    {
        i = 0;
        shuffleDeck();
    }


    cout << "Hit (1) or Stay (0)\n";
    cin >> playerDecision;


    while (playerDecision)
    {

    if (playerDecision == 1)
    {
        cout << codeToCard(cards[i]) << endl;
        i++;
        if (i >= 52)
    {
        i = 0;
        shuffleDeck();
    }
    cout << "Hit (1) or Stay (0)\n";
    cin >> playerDecision;

    }

    if (playerDecision == 0)
    {
        cout << "Tu ai: " << playerValue << " si dealerul are " << secretDealerValue << endl;
        if (playerValue == 21)
            cout << "Blackjack!!\n";
        if (playerValue > 21)
            cout << "Bust!\n";
        if (playerValue < secretDealerValue)
            cout << "Dealer wins!\n";
        else
            cout << "You win!\n";
    }
    }

    cout << "Continua? da (1) nu (0)";
    cin >> playerDecision;
    }
}
