/*
Project
ID: U1910046
Name: Vladimir Khvan
ID: U1910100
Name: Farrukh Asatov
Program: Quiz Game (Who wants to be a millionare)
*/

#include<iostream>
#include<string>
using namespace std;

string border = string(72, '='),
		playerName, highScorePlayer = "Khvangene";
string playerChoiceString, againOptionString, answerString, qString;
char playerChoice, againOption, answer, q;
int rightAnswerCheck = 0, secondLifeCounter = 1, helpCheck = 0;
int money = 0, highScore = 0;

string center(string text);									//centralize text
void center(int number);

void headerEditor(string text);
void headerEditor(int number);

void mainMenu();

void answerEditor(string answer1, string answer2,			//print answers
	string answer3, string answer4, char rightAnswer);

void helpFuction();

void scoreRecorder();										//record name and score of high score player

void pointsCalculator(int money);							//add points

void restart();

void scoreMenu();

void nameCatcher();											//catch name of player

void secondLife();											//give 2nd chance to player

void helpRightAnswer(char rightAnswerChar);					//show right answer

void youLostSign();

void header();												//print 'quit' and 'help' in top of each question

int main() {

	Menu:
	mainMenu();
	while (playerChoice != 'p' && playerChoice != 'h'		//stops attribution of wrong value
		&& playerChoice != 'q' && playerChoice != 's') {
		system("CLS");
		goto Menu;
	}
	system("CLS");

	if (playerChoice == 'p') {								//starts game
		Restart:
		rightAnswerCheck = 0;
		  helpCheck = 1;
		  secondLifeCounter = 1;
		  money = 0;
		  nameCatcher();
		  goto Question0;
	}
	else if (playerChoice == 'h') {							//calls help function
		helpFuction();
		goto Menu;	
	}
	else if (playerChoice == 's') {							//calls score function
		scoreMenu();
		system("CLS");
		goto Menu;
	}
	else {													//exit program
		headerEditor("GOODBYE!");
	}

	if (0) {												// if(0) to make sure that this part of code
	Question0:														//will not be called,if it is not nessessary
		header();
		headerEditor("What is the longest that an elephant has lived?(c)");
		answerEditor("A) 17 years", "B) 49 years",
			"C) 86 years", "D) 142 years", 'c');

		while (answer != 'a' && answer != 'b' && answer != 'c'
			 && answer != 'd' && answer != 'h' && answer != 'q') {
			system("CLS");
			goto Question0;
		}

		if (answer == 'q') {
		quitOption0:
			headerEditor("Are you sure?");
			cout << string(20, ' ') << "Press > Y to go to main menu"
				<< string(19, ' ') << "Press > N to stay in game" << endl << endl;
			
			cout<<center("Your choice: ");
			getline(cin, qString);
			q = qString[0];							//way to read only 1st char in string, 
			q = tolower(q);										// if 2 or more were inputed

			while (q != 'n' && q != 'y') {
				system("CLS");
				goto quitOption0;
			}

			if (q == 'y') {
				system("CLS");
				goto Menu;
			}
			else {
				system("CLS");
				goto Question0;
			}
		}

		if (answer == 'h') {					//calls function that shows right answer
			if (helpCheck) {
				helpRightAnswer('c');
				helpCheck = 0;
			}
			goto Question0;
		}

		if (rightAnswerCheck) {
			rightAnswerCheck = 0;
			pointsCalculator(1000);
			goto Question1;
		}
		else {
			if (secondLifeCounter) {			//move user back to current if it has "second life"
				secondLife();
				goto Question0;
			}

			youLostSign();

			restart();
			if (againOption == 'y') {
				system("CLS");
				goto Restart;
			}
			else {
				system("CLS");
				goto Menu;
			}
		}
	}

	if (0) {
	Question1:
		header();
		headerEditor("How many rings are on the Olympic flag?(c)");
		answerEditor("A) None", "B) 4", 
			"C) 5", "D) 7", 'c');

		while (answer != 'a' && answer != 'b' && answer != 'c'
			&& answer != 'd' && answer != 'h' && answer != 'q') {
			system("CLS");
			goto Question1;
		}

		if (answer == 'q') {
		quitOption1:
			headerEditor("Are you sure?");
			cout << string(20, ' ') << "Press > Y to go to main menu"
				<< string(19, ' ') << "Press > N to stay in game" << endl << endl;

			cout << center("Your choice: ");
			getline(cin, qString);
			q = qString[0];
			q = tolower(q);

			while (q != 'n' && q != 'y') {
				system("CLS");
				goto quitOption1;
			}

			if (q == 'y') {
				system("CLS");
				goto Menu;
			}
			else {
				system("CLS");
				goto Question1;
			}
		}

		if (answer == 'h') {
			if(helpCheck){
				helpRightAnswer('c');
				helpCheck = 0;
			}
			goto Question1;
		}

		if (rightAnswerCheck) {
			pointsCalculator(4000);
			rightAnswerCheck = 0;
			goto Question2;
		}
		else {
			if (secondLifeCounter) {
				secondLife();
				goto Question1;
			}

			youLostSign();

			restart();
			if (againOption == 'y') {
				system("CLS");
				goto Restart;
			}
			else {
				system("CLS");
				goto Menu;
			}
		}
	}

	if (0) {
	Question2:
		header();
		headerEditor("What is a tarsier?(a)");
		answerEditor("A) A primate", "B) A rodent",
			"C) A lizard", "D) A bird", 'a');

		while (answer != 'a' && answer != 'b' && answer != 'c'
			&& answer != 'd' && answer != 'h' && answer != 'q') {
			system("CLS");
			goto Question2;
		}

		if (answer == 'q') {
		quitOption2:
			headerEditor("Are you sure?");
			cout << string(20, ' ') << "Press > Y to go to main menu"
				<< string(19, ' ') << "Press > N to stay in game" << endl << endl;

			cout << center("Your choice: ");
			getline(cin, qString);
			q = qString[0];
			q = tolower(q);

			while (q != 'n' && q != 'y') {
				system("CLS");
				goto quitOption2;
			}

			if (q == 'y') {
				system("CLS");
				goto Menu;
			}
			else {
				system("CLS");
				goto Question2;
			}
		}

		if (answer == 'h') {
			if (helpCheck) {
				helpRightAnswer('a');
				helpCheck = 0;
			}
			goto Question2;
		}

		if (rightAnswerCheck) {
			pointsCalculator(8000);
			rightAnswerCheck = 0;
			goto Question3;
		}
		else {
			if (secondLifeCounter) {
				secondLife();
				goto Question2;
			}

			youLostSign();

			restart();
			if (againOption == 'y') {
				system("CLS");
				goto Restart;
			}
			else {
				system("CLS");
				goto Menu;
			}
		}
	}

	if (0) {
	Question3:
		header();
		headerEditor("	Who wrote \"don't count your chickens before they are hatched\"?(a)");
		answerEditor("A) Aesop", "B) Shakespeare",
			"C) Ben Franklin", "D) Chaucer", 'a');

		while (answer != 'a' && answer != 'b' && answer != 'c'
			&& answer != 'd' && answer != 'h' && answer != 'q') {
			system("CLS");
			goto Question3;
		}

		if (answer == 'q') {
		quitOption3:
			headerEditor("Are you sure?");
			cout << string(20, ' ') << "Press > Y to go to main menu"
				<< string(19, ' ') << "Press > N to stay in game" << endl << endl;

			cout << center("Your choice: ");
			getline(cin, qString);
			q = qString[0];
			q = tolower(q);

			while (q != 'n' && q != 'y') {
				system("CLS");
				goto quitOption3;
			}

			if (q == 'y') {
				system("CLS");
				goto Menu;
			}
			else {
				system("CLS");
				goto Question3;
			}
		}

		if (answer == 'h') {
			if (helpCheck) {
				helpRightAnswer('a');
				helpCheck = 0;
			}
			goto Question3;
		}

		if (rightAnswerCheck) {
			pointsCalculator(16000);
			rightAnswerCheck = 0;
			goto Question4;
		}
		else {
			if (secondLifeCounter) {
				secondLife();
				goto Question3;
			}

			youLostSign();

			restart();
			if (againOption == 'y') {
				system("CLS");
				goto Restart;
			}
			else {
				system("CLS");
				goto Menu;
			}
		}
	}

	if (0) {
	Question4:
		header();
		headerEditor("In darts, what's the most points you can score with a single throw?(c)");
		answerEditor("A) 20", "B) 50",
			"C) 60", "D) 100", 'c');

		while (answer != 'a' && answer != 'b' && answer != 'c'
			&& answer != 'd' && answer != 'h' && answer != 'q') {
			system("CLS");
			goto Question4;
		}

		if (answer == 'q') {
		quitOption4:
			headerEditor("Are you sure?");
			cout << string(20, ' ') << "Press > Y to go to main menu"
				<< string(19, ' ') << "Press > N to stay in game" << endl << endl;

			cout << center("Your choice: ");
			getline(cin, qString);
			q = qString[0];
			q = tolower(q);

			while (q != 'n' && q != 'y') {
				system("CLS");
				goto quitOption4;
			}

			if (q == 'y') {
				system("CLS");
				goto Menu;
			}
			else {
				system("CLS");
				goto Question4;
			}
		}

		if (answer == 'h') {
			if (helpCheck) {
				helpRightAnswer('c');
				helpCheck = 0;
			}
			goto Question4;
		}

		if (rightAnswerCheck) {
			pointsCalculator(32000);
			rightAnswerCheck = 0;
			goto Question5;
		}
		else {
			if (secondLifeCounter) {
				secondLife();
				goto Question4;
			}

			youLostSign();

			restart();
			if (againOption == 'y') {
				system("CLS");
				goto Restart;
			}
			else {
				system("CLS");
				goto Menu;
			}
		}
	}

	if (0) {
	Question5:
		header();
		headerEditor("Which of these animals does NOT appear in the Chinese zodiac?(a)");
		answerEditor("A) Bear", "B) Rabbit",
			"C) Dragon", "D) Dog", 'a');

		while (answer != 'a' && answer != 'b' && answer != 'c'
			&& answer != 'd' && answer != 'h' && answer != 'q') {
			system("CLS");
			goto Question5;
		}

		if (answer == 'q') {
		quitOption5:
			headerEditor("Are you sure?");
			cout << string(20, ' ') << "Press > Y to go to main menu"
				<< string(19, ' ') << "Press > N to stay in game" << endl << endl;

			cout << center("Your choice: ");
			getline(cin, qString);
			q = qString[0];
			q = tolower(q);

			while (q != 'n' && q != 'y') {
				system("CLS");
				goto quitOption5;
			}

			if (q == 'y') {
				system("CLS");
				goto Menu;
			}
			else {
				system("CLS");
				goto Question5;
			}
		}

		if (answer == 'h') {
			if (helpCheck) {
				helpRightAnswer('a');
				helpCheck = 0;
			}
			goto Question5;
		}

		if (rightAnswerCheck) {
			pointsCalculator(64000);
			rightAnswerCheck = 0;
			goto Question6;
		}
		else {
			if (secondLifeCounter) {
				secondLife();
				goto Question5;
			}

			youLostSign();

			restart();
			if (againOption == 'y') {
				system("CLS");
				goto Restart;
			}
			else {
				system("CLS");
				goto Menu;
			}
		}
	}

	if (0) {
	Question6:
		header();
		headerEditor("How many holes are on a standard bowling ball?(b)");
		answerEditor("A) 2", "B) 3",
			"C) 4", "D) 5", 'b');

		while (answer != 'a' && answer != 'b' && answer != 'c'
			&& answer != 'd' && answer != 'h' && answer != 'q') {
			system("CLS");
			goto Question6;
		}

		if (answer == 'q') {
		quitOption6:
			headerEditor("Are you sure?");
			cout << string(20, ' ') << "Press > Y to go to main menu"
				<< string(19, ' ') << "Press > N to stay in game" << endl << endl;

			cout << center("Your choice: ");
			getline(cin, qString);
			q = qString[0];
			q = tolower(q);

			while (q != 'n' && q != 'y') {
				system("CLS");
				goto quitOption6;
			}

			if (q == 'y') {
				system("CLS");
				goto Menu;
			}
			else {
				system("CLS");
				goto Question6;
			}
		}

		if (answer == 'h') {
			if (helpCheck) {
				helpRightAnswer('b');
				helpCheck = 0;
			}
			goto Question6;
		}

		if (rightAnswerCheck) {
			pointsCalculator(125000);
			rightAnswerCheck = 0;
			goto Question7;
		}
		else {
			if (secondLifeCounter) {
				secondLife();
				goto Question6;
			}

			youLostSign();

			restart();
			if (againOption == 'y') {
				system("CLS");
				goto Restart;
			}
			else {
				system("CLS");
				goto Menu;
			}
		}
	}

	if (0) {
	Question7:
		header();
		headerEditor("What are the main colors on the flag of Spain?(d)");
		answerEditor("A) Black and yellow", "B) Green and white",
			"C) Blue and white", "D) Red and yellow", 'd');

		while (answer != 'a' && answer != 'b' && answer != 'c'
			&& answer != 'd' && answer != 'h' && answer != 'q') {
			system("CLS");
			goto Question7;
		}

		if (answer == 'q') {
		quitOption7:
			headerEditor("Are you sure?");
			cout << string(20, ' ') << "Press > Y to go to main menu"
				<< string(19, ' ') << "Press > N to stay in game" << endl << endl;

			cout << center("Your choice: ");
			getline(cin, qString);
			q = qString[0];
			q = tolower(q);

			while (q != 'n' && q != 'y') {
				system("CLS");
				goto quitOption7;
			}

			if (q == 'y') {
				system("CLS");
				goto Menu;
			}
			else {
				system("CLS");
				goto Question7;
			}
		}

		if (answer == 'h') {
			if (helpCheck) {
				helpRightAnswer('d');
				helpCheck = 0;
			}
			goto Question7;
		}

		if (rightAnswerCheck) {
			pointsCalculator(250000);
			rightAnswerCheck = 0;
			goto Question8;
		}
		else {
			if (secondLifeCounter) {
				secondLife();
				goto Question7;
			}

			youLostSign();

			restart();
			if (againOption == 'y') {
				system("CLS");
				goto Restart;
			}
			else {
				system("CLS");
				goto Menu;
			}
		}
	}

	if (0) {
	Question8:
		header();
		headerEditor("	Which boxer twice defeated Nigel Benn in 1996?(b)");
		answerEditor("A) Thulani Malinga", "B) Steve Collins", 
			"C) Roy Jones", "D) Gerald McClellan", 'b');

		while (answer != 'a' && answer != 'b' && answer != 'c'
			&& answer != 'd' && answer != 'h' && answer != 'q') {
			system("CLS");
			goto Question8;
		}

		if (answer == 'q') {
		quitOption8:
			headerEditor("Are you sure?");
			cout << string(20, ' ') << "Press > Y to go to main menu"
				<< string(19, ' ') << "Press > N to stay in game" << endl << endl;

			cout << center("Your choice: ");
			getline(cin, qString);
			q = qString[0];
			q = tolower(q);

			while (q != 'n' && q != 'y') {
				system("CLS");
				goto quitOption8;
			}

			if (q == 'y') {
				system("CLS");
				goto Menu;
			}
			else {
				system("CLS");
				goto Question8;
			}
		}

		if (answer == 'h') {
			if (helpCheck) {
				helpRightAnswer('b');
				helpCheck = 0;
			}
			goto Question8;
		}

		if (rightAnswerCheck) {
			cout << center(border) << endl;
			cout << center("You Won") << endl;

			pointsCalculator(500000);

			restart();
			if (againOption == 'y') {
				system("CLS");
				goto Restart;
			}
			else {
				system("CLS");
				goto Menu;
			}
		}
		else {
			if (secondLifeCounter) {
				secondLife();
				goto Question8;
			}

			youLostSign();

			restart();
			if (againOption == 'y') {
				system("CLS");
				goto Restart;
			}
			else if(againOption == 'n')
			{
				system("CLS");
				goto Menu;
			}
		}
	}

system("pause");
return 0;
}


string center(string text) {

	return string((113 - text.length()) / 2, ' ') + text;
}

void center(int number) {
	int counter = 0, numberCopy;
	numberCopy = number;

	while (numberCopy != 0) {
		counter++;
		numberCopy = numberCopy / 10;
	}
	cout << string((113 - counter) / 2, ' ') << number << endl;
}

void headerEditor(string text) {

	cout << center(border) << endl;
	cout << center(text) << endl;
	cout << center(border) << endl << endl;
}

void headerEditor(int number) {

	cout << center(border) << endl;
	center(number);
	cout << center(border) << endl << endl;
}

void mainMenu() {

	headerEditor("Who Wants To Be a Millioner");

	cout << string(28, ' ') + "Press > P to Play"
		<< endl
		<< string(28, ' ') + "Press > H to Help"
		<< endl
		<< string(28, ' ') + "Press > S to Score"
		<< endl
		<< string(28, ' ') + "Press > Q to Quit"
		<< endl << endl
		<< string(28, ' ') + "Your choice: ";

	getline(cin, playerChoiceString);
	playerChoice = playerChoiceString[0];
	playerChoice = tolower(playerChoice);
}

void answerEditor(string answer1, string answer2,
	string answer3, string answer4, char rightAnswer) {

	cout << string(28, ' ') + answer1
		<< string(28 - answer1.length(), ' ') + answer2
		<< endl << endl
		<< string(28, ' ') + answer3
		<< string(28 - answer3.length(), ' ') + answer4
		<< endl << endl
		<< string(28, ' ') + "Your final answer: ";
	getline(cin, answerString);
	answer = answerString[0];
	answer = tolower(answer);

	if (answer == rightAnswer) {
		rightAnswerCheck = 1;
	}

	system("CLS");
}

void helpFuction() {

	cout << center(border) << endl;
	cout << center("Instruction") << endl;
	cout << center(border) << endl << endl;

	cout << string(20, ' ') + "In this game you are given 8 questions with 4 possible anwers." << endl;
	cout << string(20, ' ') + "You have to answer right to move to next question. You have 1" << endl;
	cout << string(20, ' ') + "chance to answer wrong (second life). If you do not know the" << endl;
	cout << string(20, ' ') + "answer or hesitate about it, you can use help option once a" << endl;
	cout << string(20, ' ') + "game by inputing 'h'. After answering question you will recive" << endl;
	cout << string(20, ' ') + "points, that will be calculated in the end of the game." << endl;
	cout << string(20, ' ') + "Good Luck!" << endl << endl;

	system("pause");
	system("CLS");
}

void scoreRecorder() {
	if (money >= highScore) {
		highScore = money;
		highScorePlayer = playerName;
	}
}

void pointsCalculator(int money) {

	::money += money;

	headerEditor(::money);

	scoreRecorder();

	system("pause");
	system("CLS");
}

void restart() {

	headerEditor("Try Again?");
	cout << string(33, ' ') + "Press > Y for Yes"
		<< string(11, ' ') + "Press > N for No" << endl << endl;
	cout <<center("Your choice: ");

	getline(cin, againOptionString);
	againOption = againOptionString[0];
	againOption = tolower(againOption);

	if (againOption != 'y' && againOption != 'n') {
		againOption = 'n';
	}
}

void scoreMenu() {
	int counter = 0, highScoreCopy;
	highScoreCopy = highScore;

	while (highScoreCopy != 0) {
		if (highScoreCopy == 10) {
			counter += 2;
		}
		counter++;
		highScoreCopy = highScoreCopy / 10;
	}


	cout << center(border) << endl
		<< string((89 - counter - highScorePlayer.length())/2 , ' ')
		<< highScorePlayer << " has the highest score: "
		<< highScore << endl
		<< center(border) << endl;

	system("pause");
}

void nameCatcher() {

	headerEditor("Input your nickname!");
	cout << string(28, ' ') + "Your name: ";
	getline(cin, playerName);
	system("CLS");

	if (playerName.length() == 0) {
		playerName = "Player";
		cout << center(border) << endl
			<< string(50, ' ')
			<< "Hello, Player" << endl
			<< center(border) << endl << endl;
	}
	else {
		cout << center(border) << endl
			<< string((106 - playerName.length()) / 2, ' ')
			<< "Hello, "
			<< playerName << endl
			<< center(border) << endl << endl;
	}

	system("pause");
	system("CLS");
}

void secondLife() {
	system("CLS");
	cout << center(border) << endl;
	cout << center("You answered wrong") << endl;
	headerEditor("You used second life");
	secondLifeCounter = 0;

	system("pause");
	system("CLS");
}

void graphForHelpRightAnswer(int percent, int a, int b, int c, int d) {
	string pole = "||||", spaces = "    ";

	if (a >= percent) {
		cout << string(34, ' ') << pole << string(7, ' ');
	}
	else {
		cout << string(34, ' ') << spaces << string(7, ' ');
	}

	if (b >= percent) {
		cout << pole << string(7, ' ');
	}
	else {
		cout << spaces << string(7, ' ');
	}

	if (c >= percent) {
		cout << pole << string(7, ' ');
	}
	else {
		cout << spaces << string(7, ' ');
	}

	if (d >= percent) {
		cout << pole;
	}
	else {
		cout << spaces;
	}

	cout << endl;
}

void helpRightAnswer(char rightAnswerChar) {
	char aAnswer = 'a', bAnswer = 'b', cAnswer = 'c', dAnswer = 'd';
	int biggestPercent, percent2, percent3, percent4;
	int aAnswerPercent, bAnswerPercent, cAnswerPercent, dAnswerPercent;

	biggestPercent = rand() % 50 + 50;
	percent2 = rand() % (100 - biggestPercent);
	percent3 = rand() % (100 - biggestPercent - percent2);
	percent4 = 100 - biggestPercent - percent2 - percent3;

	if (rightAnswerChar == 'a') {
		aAnswerPercent = biggestPercent;
		bAnswerPercent = percent2;
		cAnswerPercent = percent3;
		dAnswerPercent = percent4;
	}
	else if (rightAnswerChar == 'b') {
		aAnswerPercent = percent2;
		bAnswerPercent = biggestPercent;
		cAnswerPercent = percent4;
		dAnswerPercent = percent3;
	}
	else if (rightAnswerChar == 'c') {
		aAnswerPercent = percent4;
		bAnswerPercent = percent2;
		cAnswerPercent = biggestPercent;
		dAnswerPercent = percent3;
	}
	else {
		aAnswerPercent = percent2;
		bAnswerPercent = percent3;
		cAnswerPercent = percent4;
		dAnswerPercent = biggestPercent;
	}

	cout << endl << string(34, ' ') 
		<< "Possibility of right answer in %" << endl<< endl;
	graphForHelpRightAnswer(90, aAnswerPercent, bAnswerPercent, cAnswerPercent, dAnswerPercent);
	graphForHelpRightAnswer(80, aAnswerPercent, bAnswerPercent, cAnswerPercent, dAnswerPercent);
	graphForHelpRightAnswer(70, aAnswerPercent, bAnswerPercent, cAnswerPercent, dAnswerPercent);
	graphForHelpRightAnswer(60, aAnswerPercent, bAnswerPercent, cAnswerPercent, dAnswerPercent);
	graphForHelpRightAnswer(50, aAnswerPercent, bAnswerPercent, cAnswerPercent, dAnswerPercent);
	graphForHelpRightAnswer(40, aAnswerPercent, bAnswerPercent, cAnswerPercent, dAnswerPercent);
	graphForHelpRightAnswer(30, aAnswerPercent, bAnswerPercent, cAnswerPercent, dAnswerPercent);
	graphForHelpRightAnswer(20, aAnswerPercent, bAnswerPercent, cAnswerPercent, dAnswerPercent);
	graphForHelpRightAnswer(10, aAnswerPercent, bAnswerPercent, cAnswerPercent, dAnswerPercent);

	cout << string(34, ' ') << string(45, '=') << endl;

	cout << string(34, ' ') << aAnswer << ": " << aAnswerPercent << "%";
	cout << string(5, ' ') << bAnswer << ": " << bAnswerPercent << "%";
	cout << string(5, ' ') << cAnswer << ": " << cAnswerPercent << "%";
	cout << string(5, ' ') << dAnswer << ": " << dAnswerPercent << "%" << endl;

	system("pause");
	system("CLS");
}

void youLostSign() {
	int counter = 0, moneyCopy;
	moneyCopy = money;

	while (moneyCopy != 0) {
		if (moneyCopy == 10) {
			counter += 2;
		}
		counter++;
		moneyCopy = moneyCopy / 10;
	}
	

	cout << center(border) << endl
		<< string((103 - counter) / 2, ' ')
		<< "You lost" <<": "
		<< money << endl
		<< center(border) << endl;

	system("pause");
	system("CLS");
}

void header() {
	if (helpCheck) {
		cout << endl << string(20, ' ') << "Press > Q to go to main menu"
			<< string(13, ' ') << "Press > H to call help function" << endl << endl;
	}
	else {
		cout << endl << center("Press > Q to go to main menu") << endl << endl;
	}
}