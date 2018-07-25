

#include <iostream>
#include <vector>
#include <conio.h> 
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	int Playerplace = 20;
	char playfield[150];
	char save;
	
	char* last_place;
	bool lose = false, foodexists = true;
	for (int i = 0; i < 150; i++)
	{
		playfield[i] = '_';
	}
	vector<char*> snake;
	char* s;
	
	s = &playfield[Playerplace];
	save = *s;
	*s = 'X';
	char choice;
	snake.push_back(s);
	playfield[55] = '0';

	cout << "Set speed: 1 - very slow, 0.1 - very fast, a numbers in between are avalible\n";
	double speed;
	cin >> speed;
	time_t t = time(NULL);
	do
	{
	if (time(NULL) == t + speed)
		{
			system("cls");
			for (int i = 0; i < 150; i++)
			{
				cout << playfield[i];

				if ((i + 1) % 15 == 0)
				{
					cout << endl;
				}
			}
		
			if (_kbhit() == true)
			{
				choice = _getch();
				char flush = _getch();
			
			}
			switch (choice)
			{
			case 'w':
			{
				if (Playerplace == 0 || Playerplace == 1 || Playerplace == 2 || Playerplace == 3 || Playerplace == 4 || Playerplace == 5 || Playerplace == 6 || Playerplace == 7 || Playerplace == 8 || Playerplace == 9 || Playerplace == 10 || Playerplace == 11 || Playerplace == 12 || Playerplace == 13 || Playerplace == 14)
				{
					Playerplace += 135;
				}
				else
				{
					Playerplace -= 15;
				}
				*snake[0] = save;
				for (int i = snake.size() - 1; i > 0; i--)
				{
					if (i == snake.size() - 1)
					{
						*snake[i] = save;
						last_place = snake[i];
					}
					snake[i] = snake[i - 1];
					*snake[i] = 'X';
				}
				if (snake.size() == 1)
				{
					last_place = snake[0];
				}
				snake[0] = &playfield[Playerplace];
				save = *snake[0];
				*snake[0] = 'X';
				break;
			}
			case 'a':
			{
			if (Playerplace == 0 || Playerplace == 15 || Playerplace == 30 || Playerplace == 45 || Playerplace == 60 || Playerplace == 75 || Playerplace == 90 || Playerplace == 105 || Playerplace == 120 || Playerplace == 135)
			{
				Playerplace += 14;
			}
			else
			{
				Playerplace -= 1;
			}
			*snake[0] = save;
			for (int i = snake.size() - 1; i > 0; i--)
			{
				if (i == snake.size() - 1)
				{
					*snake[i] = save;
					last_place = snake[i];
				}
				snake[i] = snake[i - 1];
				*snake[i] = 'X';
			}
			if (snake.size() == 1)
			{
				last_place = snake[0];
			}
			snake[0] = &playfield[Playerplace];
			save = *snake[0];
			*snake[0] = 'X';
			break;
			}
			case 's':
			{
				if (Playerplace == 135 || Playerplace == 136 || Playerplace == 137 || Playerplace == 138 || Playerplace == 139 || Playerplace == 140 || Playerplace == 141 || Playerplace == 142 || Playerplace == 143 || Playerplace == 144 || Playerplace == 145 || Playerplace == 146 || Playerplace == 147 || Playerplace == 148 || Playerplace == 149)
				{
					Playerplace -= 135;
				}

				else
				{
					Playerplace += 15;
				}
				*snake[0] = save;
				for (int i = snake.size() - 1; i > 0; i--)
				{
					if (i == snake.size() - 1)
					{
						*snake[i] = save;
						last_place = snake[i];
					}
					snake[i] = snake[i - 1];
					*snake[i] = 'X';
				}

				if (snake.size() == 1)
				{
					last_place = snake[0];
				}
				snake[0] = &playfield[Playerplace];
				save = *snake[0];
				*snake[0] = 'X';
				break;
			}
			case 'd':
			{
				if (Playerplace == 14 || Playerplace == 29 || Playerplace == 44 || Playerplace == 59 || Playerplace == 74 || Playerplace == 89 || Playerplace == 204 || Playerplace == 119 || Playerplace == 134 || Playerplace == 149)
				{
					Playerplace -= 14;
				}
				else
				{
					Playerplace += 1;
				}
				*snake[0] = save;
				for (int i = snake.size() - 1; i > 0; i--)
				{
					if (i == snake.size() - 1)
					{
						*snake[i] = save;
						last_place = snake[i];
					}
					snake[i] = snake[i - 1];
					*snake[i] = 'X';
				}
				if (snake.size() == 1)
				{
					last_place = snake[0];
				}
				snake[0] = &playfield[Playerplace];
				save = *snake[0];
				*snake[0] = 'X';
				break;
			}
			}
			if (save == '0')
			{
				foodexists = false;
				save = '_';
				switch (choice)
				{
				case 'w':
				{
					*last_place = 'X';
					snake.push_back(last_place);
					break;
				}
				case 'a':
				{
					*last_place = 'X';
					snake.push_back(last_place);
					break;
				}
				case 's':
				{
					*last_place = 'X';
					snake.push_back(last_place);
					break;
				}
				case 'd':
				{
					*last_place = 'X';
					snake.push_back(last_place);
					break;
				}
				}
			}
			if (foodexists == false)
			{
				do
				{
					int d = rand() % 150;
					if (playfield[d] != 'X')
					{
						playfield[d] = '0';
						foodexists = true;
					}
				} while (foodexists == false);

			}
			if (save == 'X')
			{
				lose = true;
			}
			t = time(NULL);
		}
	} while (lose != true);


	cout << endl;
	cout << "You lost, your snake is " << snake.size() << " points long" << endl;
	cin.get();
	return 0;
}
