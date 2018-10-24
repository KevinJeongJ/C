/*only the basic poker card handing code. 
This is a preliminary code and usage of functions can definitely
shorten the code significantly.
calculation of the pot (how much each people bet, raise mechanics,etc) and
winning hand calculation is not made yet. 
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    cout << "Let's play some Texas Holdem" << endl;

    double deck[16][4];
    int i;
    int j;
    double k;

    //intializing the decks, number after decimal represents suite (heart =1, spade =2, etc.)

    for (i = 1.; i <= 16.; i++)
    {
        for (j = 1.; j <= 4.; j++)
        {
            k = i + j / 10.;
            deck[i][j] = k;
        }
    }

    int pe;
    cout << "number of particiapnts? ";
    cin >> pe;
    cout << "number of participant is " << pe << ".\n";

// cards is 7 for 2 individual cards + 5 common cards
    double cards[7][pe];
    int c1;
    int cd1;

    for (int d = 1; d <= pe; d++)
        for (int e = 1; e <= 2; e++)
        {
            // randomly drawing cards
            c1 = rand() % 16 + 1;
            cd1 = rand() % 4 + 1;
            double cr1 = c1 + cd1 / 10.;

            /* every time one of the cards are drawn, it's corresponding 
card at the deck is turned into == 0 to indicate the card is 
already taken */

            while (deck[c1][cd1] == 0)
            {
                c1 = rand() % 16 + 1;
                cd1 = rand() % 4 + 1;
                cr1 = c1 + cd1 / 10.;
                if (deck[c1][cd1] != 0)
                {
                    deck[c1][cd1] = 0;
                }
            }

            cards[e][d] = cr1;
        }

    //outputting cards each player obtained
    for (int d = 1; d <= pe; d++)
    {
        cout << "player " << d << " has following cards" << endl;
        for (int e = 1; e <= 3; e++)
        {
            cout << cards[e][d] << endl;
        }
    }

    //common cards = first 3
    double commoncards[5];
    int cc1;
    int ccd1;

    for (int i = 1; i <= 3; i++)
    {
        cc1 = rand() % 16 + 1;
        ccd1 = rand() % 4 + 1;
        double ccr1 = cc1 + ccd1 / 10.;
        // randomly drawing cards

        while (deck[cc1][ccd1] == 0)
        {
            cc1 = rand() % 16 + 1;
            ccd1 = rand() % 4 + 1;
            ccr1 = cc1 + ccd1 / 10.;
            if (deck[cc1][ccd1] != 0)
            {
                deck[cc1][ccd1] = 0;
            }
        }
        commoncards[i] = ccr1;
    }

    //printing first 3 common cards
    cout << "First 3 common cards are:" << endl;
    for (int i = 1; i <= 3; i++)
    {
        cout << commoncards[i] << ".\n"
             << endl;
    }

    //indicate whether to continue or not
    char Y = 'Y';
    char N = 'N';
    char answer;
    cout << "will you continue or fold? (Y/N)"<<endl;
    cin >> answer;
    if (N == answer ){
        cout << "game over, you folded"<<endl;
        return 0;
    }

    i =4;
    {
        cc1 = rand() % 16 + 1;
        ccd1 = rand() % 4 + 1;
        double ccr1 = cc1 + ccd1 / 10.;
        // randomly drawing cards

        while (deck[cc1][ccd1] == 0)
        {
            cc1 = rand() % 16 + 1;
            ccd1 = rand() % 4 + 1;
            ccr1 = cc1 + ccd1 / 10.;
            if (deck[cc1][ccd1] != 0)
            {
                deck[cc1][ccd1] = 0;
            }
        }
        commoncards[i] = ccr1;
    }

    //printing first 3 common cards
    cout << "4th common card is:" << endl;
    i = 4;
    {
        cout << commoncards[i] << ".\n"
             << endl;
    }

    //ask for the last time 
        cout << "will you continue or fold? (Y/N)"<<endl;
    cin >> answer;
    if (N == answer ){
        cout << "game over, you folded"<<endl;
        return 0;
    }

    //last card
        i =5;
    {
        cc1 = rand() % 16 + 1;
        ccd1 = rand() % 4 + 1;
        double ccr1 = cc1 + ccd1 / 10.;
        // randomly drawing cards

        while (deck[cc1][ccd1] == 0)
        {
            cc1 = rand() % 16 + 1;
            ccd1 = rand() % 4 + 1;
            ccr1 = cc1 + ccd1 / 10.;
            if (deck[cc1][ccd1] != 0)
            {
                deck[cc1][ccd1] = 0;
            }
        }
        commoncards[i] = ccr1;
    }

    //printing first 3 common cards
    cout << "last card is:" << endl;
    i = 5;
    {
        cout << commoncards[i] << ".\n"
             << endl;
    }

    //final ask (Y/N)
    cout << "will you continue or fold? (Y/N)"<<endl;
    cin >> answer;
    if (N == answer ){
        cout << "game over, you folded"<<endl;
        return 0;
    }

    return 0;
}
