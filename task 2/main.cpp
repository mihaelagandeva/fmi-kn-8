#include <iostream>
using namespace std;

char switchCase(char letter)
{
	if (letter >= 'A' && letter <= 'Z')
	{
		return letter + 32;
	}
	else if (letter >= 'a' && letter <= 'z')
	{
		return letter - 32;
	}
	else
	{
		cout << "Wrong input!";
		return 1;
	}
}

void Weekday(int date)
{
	
}

int countDigits(int number)
{
	int br = 0;
	while (number != 0)
	{
		br++;
		number /= 10;
	}
	return br;
}

int reverseNumb(int number)
{
	int digits = countDigits(number);
	int revNumber=0;
	while (number!=0)
	{
		revNumber = revNumber * 10 + number % 10;
		number /= 10;

	}
	return revNumber;
}

bool Palindrome(int number)
{
	int digits = countDigits(number);
	int reverse = reverseNumb(number);
	
	while (number!=0)
	{
		if (number % 10 == reverse % 10)
		{
			number /= 10;
			reverse /= 10;
		}
		else
		{
			return false;
		}
	}
	return true;
	
} 

int power(int n, int m)
{
	int number = 1;
	while (m!=0)
	{
		number *= n;
		m--;
	}
	return number;
}

void factors(int n, int m)
{
	for (int i = 1; i < n; i++)
	{
		if (i%m == 0)
		{
			cout << i << " ";
		}
	}
}

bool isPrime(int number)
{
	if (number < 2)
		return false;
	for (int i = 2; i <= number / 2; i++) {
		if (number % i == 0)
			return false;
	}
	return true;
}

void printPrime(int number)
{
	for (int i = 2; i < number; i++)
	{
		if (isPrime(i))
		{
			cout << i << " ";
		}
	}
}

int choice()
{
	int choice;
	cout << "Please choose one: " << endl;
	cout << "1 - Rock: " << endl;
	cout << "2 - Paper: " << endl;
	cout << "3 - Scissors: " << endl;
	cin >> choice;
	if (choice < 1 || choice>3)
	{
		do
		{
			cout << "Wrong input! Try again";
			cin >> choice;

		} while (choice < 1 || choice>3);
	}

	switch (choice)
	{
	case 1: cout << "Player has chosen Rock!" << endl;
		return 1;
		break;
	case 2: cout << "Player has chosen Paper!" << endl;
		return 2;
		break;
	case 3: cout << "Player has chosen Scissors!" << endl;
		return 3;
		break;
	default:
		break;
	}
}

void printResult(int player1, int player2)
{
	cout << "Result " << player1 << " - "  << player2 << endl;
}

int winner(int choice1, int choice2)
{
	if (choice1 == 1 && choice2 == 3 || choice1 == 2 && choice2 == 1 || choice1 == 3 && choice2 == 2)
	{
		cout << "Player 1 wins!"<<endl;
		return 1;
	}
	else if(choice1 == choice2)
	{
		cout << "It's a tie!" << endl;
		return 0;
	}
	else
	{
		cout << "Player 2 wins!" << endl;
		return 2;
	}
}

int game(int score1,int score2)
{
	int choice1, choice2;

	cout << "Player 1:" << endl;
	choice1 = choice();

	cout << "Player 2:" << endl;
	choice2 = choice();

	int win = winner(choice1, choice2);

	if (win == 1)
	{
		score1++;
		printResult(score1, score2);
		return 1;
	}

	else if(win==2)
	{
		score2++;
		printResult(score1, score2);
		return 2;
	}
	else
	{
		printResult(score1, score2);
		return 3;
	}


}

int main()
{
	// 7 
	int choice;
	int score1 = 0, score2 = 0;
	int win;
	cout << "Want to play a game?" << endl;
	cout << "1 - YES!" << endl;
	cout << "2 - Hell no" << endl;
	cin >> choice;
	if (choice == 1)
	{
		do
		{
			win = game(score1,score2);
			if (win == 1)
			{
				score1++;
			}
			else if (win == 2)
			{
				score2++;
			}
			cout << "Want to try again?"<<endl;
			cin >> choice;
		} while (choice == 1);
	}
	



	system("pause");
	return 0;
}