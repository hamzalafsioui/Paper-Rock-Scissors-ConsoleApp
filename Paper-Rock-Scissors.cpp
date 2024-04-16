
#include <iostream>
#include <cstdlib>

using namespace std;

int ComputerScore = 0, UserScore = 0, DrawTimes = 0;

enum enOdds { Rock = 1, Paper = 2, Scissor = 3 };

int ReedPositiveNumber(string Message)
{
    int num;

    do
    {
        cout << Message;
        cin >> num;

    } while (num < 0);

    return num;
}

int RandomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}



enOdds ComputerChoice() {
    int Computer_Choice = RandomNumber(1, 3);

    return enOdds(Computer_Choice);
}

enOdds UserChoice() {
    int User_Choice = ReedPositiveNumber("Enter [1]Rock [2]Paper [3]Scissor\n");
    return enOdds(User_Choice);
}

void Result(enOdds ComputerChoice, enOdds UserChoice, int& ComputerScore, int& UserScore, int& DrawTimes) {

    if (ComputerChoice == enOdds::Rock) {
        switch (UserChoice)
        {
        case enOdds::Rock:
            DrawTimes++;
            cout << "No one win ";
            system("color 8f");
            break;
        case enOdds::Paper:
            UserScore++;
            cout << "You win.";
            system("color 2f");
            break;
        case enOdds::Scissor:
            ComputerScore++;
            cout << "Computer won.\a";
            system("color 4f");
            break;

        }
    }

    if (ComputerChoice == enOdds::Paper) {
        switch (UserChoice)
        {
        case enOdds::Rock:
            ComputerScore++;
            cout << "computer won.\a ";
            system("color 4f");
            break;
        case enOdds::Paper:
            DrawTimes++;
            cout << "No one win.";
            system("color 8f");
            break;
        case enOdds::Scissor:
            cout << "You win";
            system("color 2f");
            UserScore++;
            break;

        }
    }

    if (ComputerChoice == enOdds::Scissor) {
        switch (UserChoice)
        {
        case enOdds::Rock:
            UserScore++;
            cout << "You win. ";
            system("color 2f");
            break;
        case enOdds::Paper:
            ComputerScore++;
            cout << "Computer won.\a";
            system("color 4f");
            break;
        case enOdds::Scissor:
            cout << "No one win.";
            system("color 8f");
            DrawTimes++;
            break;

        }
    }



}




string enumToString(enOdds choice) {
    switch (choice)
    {
    case enOdds::Rock:
        return "Rock";
        break;
    case enOdds::Paper:
        return "Paper";
        break;
    case enOdds::Scissor:
        return "Scissor";
        break;
    default:
        break;
    }
}

void Rounds(int Round)
{
    enOdds Computer_Choice;
    enOdds User_Choice;

    for (int i = 0; i < Round; i++)
    {
        cout << "\n=============== Round [" << i + 1 << "] Begin ===============\n\n";

        Computer_Choice = ComputerChoice();
        User_Choice = UserChoice();

        cout << "Player Choice   : " + enumToString(User_Choice) << endl;
        cout << "Computer Choice : " + enumToString(Computer_Choice) << endl;
        cout << "Round Winner    : [ ";
        Result(Computer_Choice, User_Choice, ComputerScore, UserScore, DrawTimes);
        cout << " ]\n";

        cout << "================================================\n\n";
    }
}


void PrintScoreResult(int rounds)
{
    cout << "\n\t\t\t\t---------------------------------------------\n";
    cout << "\t\t\t\t\t   +++ G A M E  O V E R +++\n";
    cout << "\t\t\t\t---------------------------------------------\n";

    cout << "\n\t\t\t\t===============[ Game Result ]==================\n\n";
    cout << "\t\t\t\tGame rounds : " << rounds << endl;
    cout << "\t\t\t\tComputer Score : " << ComputerScore << endl;
    cout << "\t\t\t\tUser Score     : " << UserScore << endl;
    cout << "\t\t\t\tDraw times     : " << DrawTimes << endl;

    if (ComputerScore > UserScore)
        cout << "\t\t\t\tFinal Result: Computer Won.\n";
    else if (ComputerScore < UserScore)
        cout << "\t\t\t\tFinal Result: You Win.\n";
    else if (ComputerScore == UserScore)
        cout << "\t\t\t\tFinal Result: No Winner.\n";

    cout << "\n\t\t\t\t====================================================\n";
}



bool FunctionCheck() {
    cout << "Do you want to play again ? Y/N\n";
    char YorN;
    cin >> YorN;
    if (YorN == 'Y' || YorN == 'y')

        return true;
    else if (YorN == 'N' || YorN == 'n')
        return false;
}

void startGame() {
    int Round;
    bool Check = true;
    while (Check)
    {
        Round = ReedPositiveNumber("How much Round do you want to play?\n");
        Rounds(Round);

        PrintScoreResult(Round);


        Check = FunctionCheck();
        if (Check == true) {
            system("cls");
            system("color 0f");
            UserScore = 0;
            ComputerScore = 0;
            DrawTimes = 0;
        }

    }
}





int main()
{
    srand((unsigned)time(NULL));

    startGame();

    return 0;
}