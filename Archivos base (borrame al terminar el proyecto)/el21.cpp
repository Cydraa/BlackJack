// el21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdlib>
#include<cctype>
#include <ctime>
using namespace std;

//Function to make string inputs uppercase
string uppercase(string s)
{
    for (int i = 0; i < s.size(); i++)
        s[i] = toupper(s[i]);
    return s;
}

//Function to pull a card and determine value for game sum
int card_pull(int deck[52][2], int hand[52][2], bool isPlayerTurn, int sumCPU, int blackjack)
{
    // Pulling a card
    int card, aceValue, cardValue;

    do
    {
        card = (rand() % 51) + 1;
    } while (deck[card][1] == hand[card][1]);

    hand[card][1] = deck[card][1];

    switch (deck[card][0])
    {
     case 1:
        cout << "\n> Tu carta es " << deck[card][1] << " de diamantes.\n"; break;
     case 2:
        cout << "\n> Tu carta es " << deck[card][1] << " de corazones.\n"; break;
     case 3:
        cout << "\n> Tu carta es " << deck[card][1] << " de trebol.\n"; break;
     case 4:
        cout << "\n> Tu carta es " << deck[card][1] << " de picas.\n"; 
        
        if (deck[card][1] == 39 || deck[card][1] == 49 || deck[card][1] == 50 || deck[card][1] == 51 || deck[card][1] == 52)
        {
            blackjack++;
        }

        break;
     }

    //Assigning the value of the card
    if (deck[card][1] == 1)
    {
        if (isPlayerTurn == true)
        {
            do
            {
                cout << "\nComo quieres usar el AS? Escribe 1 o 11.\n";
                cin >> aceValue;

                while (cin.fail())
                  {
                      cin.clear();
                      cin.ignore();
                      cout << "\nComo quieres usar el AS? Escribe 1 o 11.\n";
                      cin >> aceValue;
                  }

            } while (!(aceValue == 1 || aceValue == 11));
            cardValue = aceValue;
        }
        else
        {
            if (sumCPU + 11 > 21)
            {
                cardValue = 1;
            }
            else
            {
                cardValue = 11;
            }
        }
    }
    else if (deck[card][1] == 11 || deck[card][1] == 12 || deck[card][1] == 13)
    {
        cardValue = 10;
    }
    else
    {
        cardValue = deck[card][1];
    }

    cout << "Valor de la carta: " << cardValue << "\n";
    return cardValue;
}

int main()
{
    int deck[52][2];
    int hand[52][2];
    int i, j, k, blackjack, sumCPU, sumPlayer, capital{}, bet{};
    bool isPlayerTurn, playerWin;
    string s, answer, answer1, answer2;

    k = 0;
    sumPlayer = 0;
    sumCPU = 0;
    isPlayerTurn = true;
    blackjack = 0;
    srand((unsigned)time(0));


    // Create the card deck
    for (i = 1; i <= 4; i++)
    {
        for (j = 1; j <= 13; j++)
        {
            deck[k][0] = i;
            deck[k][1] = j;
            k++;
        };
    };

    k = 0;
    for (i = 1; i <= 4; i++)
    {
        for (j = 1; j <= 13; j++)
        {
            hand[k][0] = 0;
            hand[k][1] = 0;
            k++;
        };
    };

   // Print deck
   // for (i = 0; i < 52; i++)
   // {
   //     cout << deck[i][0] << " | " << deck[i][1] << "\n";
   // };
   // cout << "-------------------------------------------------------- \n \n";

   // GAME START
    cout << "=== BLACKJACK ===";

    while (!(answer == "S" || answer == "N"))
    {
        cout << "\nBienvenido al juego de BLACKJACK o el 21, deseas iniciar una partida?\n";
        cout << "S = Si, N = No\n";
        cin >> answer;
        answer = uppercase(answer);
    }

    if (answer == "S")
    {
        do 
        {
            sumPlayer = 0;
            sumCPU = 0;
            blackjack = 0;
            isPlayerTurn = false;
            playerWin = false;

            // Re-initialize hand array
            k = 1;
            for (i = 1; i <= 4; i++)
            {
                for (j = 1; j <= 13; j++)
                {
                    hand[k][0] = i;
                    hand[k][1] = j;
                    k++;
                };
            };

            //-------------------------------

            if (capital == 0);
            {
                while (capital <= 0)
                {
                    cout << "Cual es tu capital?\n";
                    cin >> capital;
                }
            }

            do
            {
                cout << "Cuanto apuestas?\n";
                cin >> bet;
            } while (bet <= 0 || bet > capital);

            cout << "\n\n";

            cout << "Capital: " << capital << "\n";
            cout << "Apuesta: " << bet << "\n";

            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "==== JUGADOR ====\n";
            isPlayerTurn = true;

            for (i = 1; i <= 2; i++)
            {
                sumPlayer = sumPlayer + card_pull(deck, hand, isPlayerTurn, sumCPU, blackjack);
            }


            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "==== MESA ====\n";
            isPlayerTurn = false;

            sumCPU = sumCPU + card_pull(deck, hand, isPlayerTurn, sumCPU, blackjack);


            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "==== JUGADOR ====\n";
            isPlayerTurn = true;

            if (sumPlayer == 21 || blackjack == 2)
            {
                playerWin = true;
            }
            else if (sumPlayer > 21)
            {
                playerWin = false;
            }
            else
            {

                do
                {
                    cout << "Suma del JUGADOR: " << sumPlayer << "\n";
                    cout << "Suma de la MESA: " << sumCPU << "\n\n";

                    do
                    {
                        cout << "Deseas sacar otra carta?\n";
                        cin >> answer1;
                        answer1 = uppercase(answer1);
                    } while (!(answer1 == "S" || answer1 == "N"));

                    if (answer1 == "S")
                    {
                        sumPlayer = sumPlayer + card_pull(deck, hand, isPlayerTurn, sumCPU, blackjack);
                    }

                } while (answer1 == "S" && sumPlayer < 21);

                if (sumPlayer > 21)
                {
                    playerWin = false;
                }
                else
                {
                    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                    cout << "==== MESA ====\n";
                    isPlayerTurn = false;

                    while (sumCPU < 21)
                    {
                        sumCPU = sumCPU + card_pull(deck, hand, isPlayerTurn, sumCPU, blackjack);
                        cout << "Suma de la MESA: " << sumCPU << "\n";
                    };


                    if (sumCPU == 21)
                    {
                        playerWin = false;
                    }
                    else if (sumCPU > 21)
                    {
                        playerWin = true;
                    }
                    else if (sumCPU < 21 && sumCPU > sumPlayer)
                    {
                        playerWin = false;
                    }
                }

            }

            cout << "\n*************************************************\n";
            if (playerWin == true)
            {
                if (blackjack == 2)
                {
                    cout << "BLACKJACK!!\n";
                    cout << "Has ganado el TRIPLE de tu apuesta: " << bet * 3 << "\n";
                    capital = capital + bet * 3;
                    cout << "Tu capital ahora: " << capital << "\n";
                }
                else
                {
                    cout << "GANASTE!!\n";
                    cout << "Has ganado tu apuesta de: " << bet << "\n";
                    capital = capital + bet;
                    cout << "Tu capital ahora: " << capital << "\n";
                }
            }
            else
            {
                cout << "PERDISTE!!\n";
                cout << "Has perdido tu apuesta de: " << bet << "\n";
                capital = capital - bet;
                cout << "Tu capital ahora: " << capital << "\n";
            }

            do
            {
                cout << "Deseas apostar otra vez?\n";
                cin >> answer2;
                answer2 = uppercase(answer2);
            } while (capital != 0 && !(answer2 == "S" || answer2 == "N"));


        } while (!(capital == 0) && (answer2 == "S"));
        
    }

    if (capital == 0 && answer == "S")
    {
        cout << "Has perdido todo tu dinero, fuera de aqui!\n";
    }
    else
    {
        cout << "Nos vemos pronto...\n";
    }

    return 0;
}


