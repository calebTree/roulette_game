//revised command console roulette game

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void showInstructions();
int number_Bet(int, int);
int makeABet(int, int);
int showTheMoney(int);
int bet_Type(int);
int spinTheWheel(int);
int figureWinnings(int, int, int, int, int);

int main()
{
    srand(time(0));
    int playerMoney = 500;
    int bet, spin, betType, numberBet, resetMoney;
    char again;

    do
    {
    system("cls");
    showInstructions();
    showTheMoney(playerMoney);
    bet = makeABet(bet, playerMoney);
    betType = bet_Type(betType);
    numberBet = number_Bet(numberBet, betType);
    spin = spinTheWheel(spin);
    playerMoney = figureWinnings(playerMoney, bet, betType, spin, numberBet);

    if (playerMoney != 0)
    {
    cout << "\nWould you like to continue? (y/n) ";
    cin >> again;
    }

    if (playerMoney == 0)
    {
        cout << "Game over.\n\n";
        cout << "Would you like to start again? (y,n) ";
        cin >> again;
        playerMoney = 500;
    }

    }while (again == 'y');

    system("pause");
    return 0;
}
    void showInstructions()
    {
                      cout << "Welcom to Roulette\n\n";
                      cout << "You will place a bet then guess odd, even, or on any number between 0 and 36.\n";
                      cout << "If you bet on odd or even numbers you will win double your bet.\nIf you bet on a number between 0 and 36 you will win 36 times your bet.\n\n";
    }

    int showTheMoney(int playerMoney)
    {
        cout << "You have $" << playerMoney << endl;
    }

    int bet_Type(int betType)
    {
              cout << "Thank you, what would like to bet on?\n";
              cout << "1 - Odd numbers\n";
              cout << "2 - Even numbers\n";
              cout << "3 - Between 0 and 36\n";
              cout << "(1, 2, 3)? ";
              cin >> betType;

              switch (betType)
              {
                     case 1:
                          cout << "You chose to bet on odd numbers.\n";
                          break;
                     case 2:
                          cout << "You chose to bet on even numbers.\n";
                          break;
                     case 3:
                          cout << "You chose to bet on a number between 0 and 36.\n";
                          break;
                     default:
                             cout << "You made an illegal choice.\n";
              }
              return betType;
    }

    int number_Bet(int numberBet, int betType)
    {
        if (betType == 3)
        {
                    cout << "What number would you like to bet on? ";
                    cin >> numberBet;
        }
        return numberBet;
    }

    int makeABet(int bet, int playerMoney)
    {
        cout << "How much money would you like to bet? $";
        cin >> bet;

        do
        {
        if (bet > playerMoney)
        {
                cout << "You do not have enough money to place that bet.\n";
                cout << "Please enter a bet equal to or under $" << playerMoney << "." << endl;
                cout << "Bet? ";
                cin >> bet;
        }
        }while(bet > playerMoney);
        return bet;
    }

    int spinTheWheel(int spin)
    {
                  spin = rand() % 36;
                  return spin;
    }

    int figureWinnings(int playerMoney, int bet, int betType, int spin, int numberBet)
    {
                     if (betType == 3 && numberBet == spin)
                     {
                                   cout << "The wheel spun a " << spin << " so you WIN!!!\n";
                                   cout << "You bet $" << bet << " and you had $" << playerMoney;
                                   playerMoney = playerMoney + bet * 36;
                                   cout << ". So you now have $" << playerMoney << "!!!" << endl;
                     }

                     if (betType == 3 && numberBet != spin)
                     {
                                 cout << "The wheel spun a " << spin << " so you lose.\n";
                                 cout << "You bet $" << bet << " and you had $" << playerMoney;
                                 playerMoney = playerMoney - bet;
                                 cout << ". So you now have $" << playerMoney << endl;
                     }

                     if (betType == 1 && spin % 2 == 1)
                     {
                                cout << "The wheel spun a " << spin << " so you WIN!!!\n";
                                cout << "You bet $" << bet << " and you had $" << playerMoney;
                                playerMoney = playerMoney + bet * 2;
                                cout << ". So you now have $" << playerMoney << "!!!" << endl;
                     }

                     if (betType == 2 && spin % 2 == 0)
                     {
                                cout << "The wheel spun a " << spin << " so you WIN!!!\n";
                                cout << "You bet $" << bet << " and you had $" << playerMoney;
                                playerMoney = playerMoney + bet * 2;
                                cout << ". So you now have $" << playerMoney << "!!!" << endl;
                     }

                     if (betType == 1 && spin % 2 != 1)
                     {
                                cout << "The wheel spun a " << spin;
                                cout << " so you lose.\nYou bet $" << bet << " and you had $" << playerMoney;
                                playerMoney = playerMoney - bet;
                                cout << ". So you now have $" << playerMoney << endl;
                     }

                     if (betType == 2 && spin % 2 != 0)
                     {
                                 cout << "The wheel spun a " << spin;
                                 cout << " so you lose.\nYou bet $" << bet << " and you had $" << playerMoney;
                                 playerMoney = playerMoney - bet;
                                 cout << ". So you now have $" << playerMoney << endl;
                     }

                     return playerMoney;
    }



