/* calculating winning hand, have not been tested yet.
flush, royal flush and straight flush has not been implemented yet
*/


#include <iostream>
#include <string>

using namespace std;

int winner(commoncards, cards, pe)
{
    /* Let's calculate the winning card,
please refer to the file poker_basis.cpp
this could be used as a funciton in addition to the basis file 
*/

    // cards[5][people]

    int winner;
    int l;
    int sum_cards[7][5];

    for (winner = 1; winner <= pe; winner++)
        for (l = 3; l <= 7; l++)
        {
            sum_cards[l][winner] = commoncards[l];
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

    int score[pe];
    int i;
    int j;
    int k;

    //setting up individual card array
    for (i = 1; i <= pe; i++)
    {  
        int count = 0;
        int count_straight = 0;
        for (j = 1; j <= 7; j++)
        { double indi[7];
            indi[j] = sum_cards[j][i];

        for
            k(k = 1; k <= 7; k++)
            {
                for (k != j)
                {
                    //looking for pairs
                    if ((sum_cards[j][i] - sum_cards[k][i]) < 1)
                    {
                        count = count + 1;
                    }
                    // mathematically, for a single pair, count =2
                    // for two pair, count = 4
                    // for triple, count = 6
                    // for full house, count = 10
                    // for four of a kind, count = 12
                    if (count == 2)
                    {
                        score[i] = 2;
                    }
                    if (count == 4)
                    {
                        score[i] = 3;
                    }
                    if (count == 6)
                    {
                        score[i] = 4;
                    }
                    if (count == 10)
                    {
                        score[i] = 7;
                    }
                    if (count == 12)
                    {
                        score[i] = 8;
                    }
                    else
                    {
                        score[i] = 1;
                    }
                }
            }
        }
        // search for straight
        size_t size = sizeof(indi)/sizeof(indi[0]);
        sort(indi, indi + size );
        for(n=1;n<=3;n++)
        for(m=n;m<=4;m++){
           if(indi[m+1]-indi[m] = 1){
                count_straight = count_straight+1;
           }
        }
        //mathematically, if there is a straight, count_straight > (4+3+2)
        //therefore
        if (count_straight >=9){
            score[i] = 5;
        }

    }
}

return 0;
}