/*only the basic poker card handing code. 
This is a preliminary code and usage of functions can definitely
shorten the code significantly.
calculation of the pot (how much each people bet, raise mechanics,etc) and
winning hand calculation is not made yet. 
*/

//edit: Winner function is added into the build to calculate the winning hand
// royal flush and straight flush has not been implemented yet

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int** calc_point(double dummycards[][10], double dummycommon[], int people);

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
    double cards[7][10];
    // maximum 10 players
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
        for (int e = 1; e <= 2; e++)
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
    cout << "will you continue or fold? (Y/N)" << endl;
    cin >> answer;
    if (N == answer)
    {
        cout << "game over, you folded" << endl;
        return 0;
    }

    i = 4;
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
    cout << "will you continue or fold? (Y/N)" << endl;
    cin >> answer;
    if (N == answer)
    {
        cout << "game over, you folded" << endl;
        return 0;
    }

    //last card
    i = 5;
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
    cout << "will you continue or fold? (Y/N)" << endl;
    cin >> answer;
    if (N == answer)
    {
        cout << "game over, you folded" << endl;
        return 0;
    }

    // funciton to caclualte the point

    int** win = calc_point(cards, commoncards, pe);

    cout << win <<".\n";

    return 0;   
}





//function to calculate the points
// should be noted that only 10 maximum players can play
int** calc_point(double dummycards[][10], double dummycommon[], int people)
{
    double points[people];

    // including common cards into the 7cards for each person calculation
    // two personal + five common cards for calculation
    for (int j = 1; j <= people; j++)
    {
        for (int k = 3; k <= 7; k++)
        {
            dummycards[k][j] = dummycommon[k - 2];
        }
    }

    /* each poker card will be given points per its strength 
royal flush = 10
straight flush = 9
four of a kind = 8
full house = 7
flush = 6
straight = 5
triple = 4
two pair = 3
pair = 2
high card = 1 */

    for (int i = 1; i <= people; i++)
    {
        int count = 0;
        int count_straight = 0;
        for (int d = 1; d <= 7; d++)
            for (int e = 1; e <= 7; e++)
            {

                // looking for pairs
                if (e > d || e < d)
                {
                    if ((dummycards[d][i] - dummycards[e][i]) < 1)
                    {
                        count++;
                    }
                }
            }
        // mathematically, for a single pair, count =2
        // for two pair, count = 4
        // for triple, count = 6
        // for full house, count = 10
        // for four of a kind, count = 12
        if (count == 2)
        {
            points[i] = 2;
        }
        if (count == 4)
        {
            points[i] = 3;
        }
        if (count == 6)
        {
            points[i] = 4;
        }
        if (count == 10)
        {
            points[i] = 7;
        }
        if (count == 12)
        {
            points[i] = 8;
        }
        else
        {
            points[i] = 1;
        }

        //search for straight
        double indi[7];
        for (int de = 1; de <= 7; de++)
        {
            indi[de] = dummycards[de][i];
        }

        size_t size = sizeof(indi) / sizeof(indi[0]);
        sort(indi, indi + size);
        for (int n = 1; n <= 3; n++)
            for (int m = n; m <= 4; m++)
            {
                if (indi[m + 1] - indi[m] < 1)
                {
                    count_straight++;
                }
            }
        //mathematically, if there is a straight, count_straight >(4+3+2)
        //therefore
        if (count_straight >= 9)
        {
            points[i] = 5;
        }

        // searching for flush
        int count_1 = 0;
        int count_2 = 0;
        int count_3 = 0;
        int count_4 = 0;
        for (int b = 1; b <= 7; b++)
        {
            if (fmod((indi[b] * 10), 10) == 1)
            {
                count_1 = count_1 + 1;
            }
            if (fmod(indi[b] * 10, 10) == 2)
            {
                count_2 = count_2 + 1;
            }
            if (fmod((indi[b] * 10), 10) == 3)
            {
                count_3 = count_3 + 1;
            }
            if (fmod((indi[b] * 10), 10) == 4)
            {
                count_4 = count_4 + 1;
            }
        }
        if (count_1 >= 4 || count_2 >= 4 || count_3 >= 4 || count_4 >= 4)
        {
            points[i] = 6;
        }
    }

    //calculate winner
    int** winner = 0;
    for (int je = 1; je <= people; je++)
    {
        for (int pe = 1; pe <= people; pe++)
        {
            if (points[je] > points[pe])
            {
                **winner = je;
            }
        }
    }
    return winner;
}
