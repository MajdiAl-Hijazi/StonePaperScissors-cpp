#include<iostream>
#include<ctime>
#include<string>

using namespace std;

enum enStonePaperScissor { Stone = 1 ,Paper = 2 ,Scissor = 3 };

int RandomNumber(int From ,int To) {

	return rand() % (To - From + 1) + From;
}

enStonePaperScissor ComputerChoice() {

		int RandomChoice = 0;
		RandomChoice = RandomNumber(1 ,3);

		if (RandomChoice == 1)
			return enStonePaperScissor::Stone;
		else if (RandomChoice == 2)
			return enStonePaperScissor::Paper;
		else if (RandomChoice == 3)
			return enStonePaperScissor::Scissor;

}

string ProcessRound(enStonePaperScissor PlayerChoice , enStonePaperScissor ComputerChoice1 ,int& ScorePlayer ,int& ScoreComputer ,int& DrawTimes) {
	
	if (PlayerChoice == enStonePaperScissor::Stone && ComputerChoice1 == enStonePaperScissor::Stone) {
	
		system("color E0");
		DrawTimes++;
		return "No Winner";
	}

	else if (PlayerChoice == enStonePaperScissor::Stone && ComputerChoice1 == enStonePaperScissor::Paper) {
	
		system("color CF");
		ScoreComputer++;
		cout << "\a";
		return "Computer";
	}

	else if (PlayerChoice == enStonePaperScissor::Stone && ComputerChoice1 == enStonePaperScissor::Scissor) {

		system("color AF");
		ScorePlayer++;
		return "Player1";
	}

	else if (PlayerChoice == enStonePaperScissor::Paper && ComputerChoice1 == enStonePaperScissor::Stone) {

		system("color AF");
		ScorePlayer++;
		return "Player1";
	}

	else if (PlayerChoice == enStonePaperScissor::Paper && ComputerChoice1 == enStonePaperScissor::Paper) {
	
		system("color E0");
		DrawTimes++;
		return "No Winner";
	}

	else if (PlayerChoice == enStonePaperScissor::Paper && ComputerChoice1 == enStonePaperScissor::Scissor) {

		system("color CF");
		ScoreComputer++;
		cout << "\a";
		return "Computer";
	}

	else if (PlayerChoice == enStonePaperScissor::Scissor && ComputerChoice1 == enStonePaperScissor::Stone) {

		system("color CF");
		ScoreComputer++;
		cout << "\a";

		return "Computer";
	}

	else if (PlayerChoice == enStonePaperScissor::Scissor && ComputerChoice1 == enStonePaperScissor::Paper) {

		system("color AF");
		ScorePlayer++;
		return "Player1";
	}

	else if (PlayerChoice == enStonePaperScissor::Scissor && ComputerChoice1 == enStonePaperScissor::Scissor) {
	
		system("color E0");
		DrawTimes++;
		return "No Winner";
	}
}

string PrintChoice(enStonePaperScissor Choice) {

	switch (Choice) {
	
	case enStonePaperScissor::Stone:
		return "Stone";
	case enStonePaperScissor::Paper:
		return "Paper";
	case enStonePaperScissor::Scissor:
		return "Scissor";
	}
}

void DisplayRound(int Round ,enStonePaperScissor PlayerChoice ,int& ScorePlayer ,int& ScoreComputer ,int& DrawTimes) {

	enStonePaperScissor ComputerChoice1 = ComputerChoice();

	cout << "\n__________________________Round [" << Round << "]__________________________\n" << endl;
	cout << "Player   Choice:  " << PrintChoice(PlayerChoice) << endl;
	cout << "Computer Choice:  " << PrintChoice(ComputerChoice1) << endl;
	cout << "Round Winner   :  [" << ProcessRound(PlayerChoice ,ComputerChoice1 ,ScorePlayer ,ScoreComputer ,DrawTimes) << "]\n" << endl;
	cout << "_____________________________________________________________\n\n" << endl;
}

int AskPlayerHowManyRounds() {

	int NumberOfRounds;

	do
	{

		cout << "How many rounds (1 - 10) you want to play ? ";
		cin >> NumberOfRounds;
		cout << "\n";

	} while (NumberOfRounds < 1 || NumberOfRounds > 10);

	return NumberOfRounds;
}

string WhoWinner(int ScorePlayer ,int ScoreComputer) {

	if (ScorePlayer > ScoreComputer)
		return "Player1";
	else if (ScoreComputer > ScorePlayer)
		return "Computer";
	return "No Winner";
}

void GamePlay(int NumberOfRounds) {

	int PlayerChoice;
	int ScorePlayer = 0;
	int ScoreComputer = 0;
	int DrawTimes = 0;


	for (int i = 1; i <= NumberOfRounds; i++) {
	
		cout << "Round [" << i << "] begins :\n" << endl;
		
		do
		{

			cout << "Your Choice : [1]:Stone ,[2]:Paper ,[3]:Scissor ? ";
			cin >> PlayerChoice;

		} while (PlayerChoice < 1 || PlayerChoice > 3);

		if (PlayerChoice == 1)
			DisplayRound(i, enStonePaperScissor::Stone ,ScorePlayer ,ScoreComputer  ,DrawTimes);
		else if (PlayerChoice == 2)
			DisplayRound(i, enStonePaperScissor::Paper ,ScorePlayer ,ScoreComputer ,DrawTimes);
		else if (PlayerChoice == 3)
			DisplayRound(i, enStonePaperScissor::Scissor, ScorePlayer, ScoreComputer ,DrawTimes);

	}

	cout << "                           ______________________________________________________________\n" << endl;
	cout << "                                              +++ G a m e  O v e r +++                   \n" << endl;
	cout << "                           ______________________________________________________________\n" << endl;
	cout << "                           ________________________[ Game Result ]_______________________\n" << endl;
	cout << "                           Game Rounds             : " << NumberOfRounds << "\n" << endl;
	cout << "                           Player1 wom times       : " << ScorePlayer << "\n" << endl;
	cout << "                           Computer won times      : " << ScoreComputer << "\n" << endl;
	cout << "                           Draw times              : " << DrawTimes << "\n" << endl;
	cout << "                           Final Winner            : " << WhoWinner(ScorePlayer ,ScoreComputer) << "\n" << endl;
	cout << "                           ______________________________________________________________\n" << endl;
}

void StartGame() {

	char StartGame;

	do {
		system("cls");
		system("color 0F");
		GamePlay(AskPlayerHowManyRounds());
		cout << "Do you want to play again (Y ,N) ? ";
		cin >> StartGame;
		cout << endl;

	} while (StartGame == 'Y' || StartGame == 'y');


}

int main() {

	srand((unsigned)time(NULL));
	StartGame();

	return 0;
}