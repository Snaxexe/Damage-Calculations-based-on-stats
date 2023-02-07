#include "Character.cpp"

void playerAttack(Player P, Enemy E);

void enemyAttack(Player P, Enemy E);

int main() 
{
	Player player;

	Enemy enemy;

	while(true)
	{
		std::cout << "Welcome to Battle Sim!" << "\n\n" << "Press Any key to continue!" << "\n\n";

		std::cin.get();

		int input = 0;

		std::cout << "Press 1 to start the game" << "\n\n";

		std::cout << "Press 2 to exit the game" << "\n\n";

		std::cin >> input;

		if (input == 1) 
		{
			start:

			while (true)
			{
				int input = 0;

				std::cout << "To change the stats of Player 1, Press 1" << "\n\n";

				std::cout << "To change the stats of Player 2, Press 2" << "\n\n";

				std::cout << "To exit the game, Press 3" << "\n\n";

				std::cout << "To start combat, Press 4" << "\n\n";

				std::cin >> input;

				if (input == 1)
				{
					while (true)
					{
						int input = 0;

						player.print_stats();

						std::cout << "to change hp, press 1" << "\n\n";

						std::cout << "to change atk, press 2" << "\n\n";

						std::cout << "to change spd, press 3" << "\n\n";

						std::cout << "to change def, press 4" << "\n\n";

						std::cout << "to change res, press 5" << "\n\n";

						std::cout << "to return to the main menu, press 6" << "\n\n";
					
						std::cin >> input;

						if (input == 1)
						{
							int hpMod = 0;
							std::cout << "enter a new value for player 1 hp" << "\n\n";
							std::cin >> hpMod;
							player.hp = hpMod;
							std::cout << "\n\n";
						}
						if (input == 2)
						{
							int atkMod = 0;
							std::cout << "enter a new value for player 1 atk" << "\n\n";
							std::cin >> atkMod;
							player.atk = atkMod;
							std::cout << "\n\n";
						}
						if (input == 3)
						{
							int spdMod = 0;
							std::cout << "enter a new value for player 1 spd" << "\n\n";
							std::cin >> spdMod;
							player.spd = spdMod;
							std::cout << "\n\n";
						}
						if (input == 4)
						{
							input = 0;
							std::cout << "enter a new value for player 1 def" << "\n\n";
							std::cin >> input;
							player.def = input;
							std::cout << "\n\n";
						}
						if (input == 5)
						{
							input = 0;
							std::cout << "enter a new value for player 1 res" << "\n\n";
							std::cin >> input;
							player.res = input;
							std::cout << "\n\n";
						}
						if (input == 6)
						{
							goto start;
						}
					}
				}
				if (input == 2)
				{
					while (true)
					{
						int input = 0;

						enemy.print_stats();

						std::cout << "to change hp, press 1" << "\n\n";

						std::cout << "to change atk, press 2" << "\n\n";

						std::cout << "to change spd, press 3" << "\n\n";

						std::cout << "to change def, press 4" << "\n\n";

						std::cout << "to change res, press 5" << "\n\n";

						std::cout << "to return to the main menu, press 6" << "\n\n";

						std::cin >> input;

					
						if (input == 1)
						{
							input = 0;
							std::cout << "enter a new value for player 2 hp" << "\n\n";
							std::cin >> input;
							enemy.hp = input;
							std::cout << "\n\n";
						}
						if (input == 2)
						{
							input = 0;
							std::cout << "enter a new value for player 2 atk" << "\n\n";
							std::cin >> input;
							enemy.atk = input;
							std::cout << "\n\n";
						}
						if (input == 3)
						{
							input = 0;
							std::cout << "enter a new value for player 2 spd" << "\n\n";
							std::cin >> input;
							enemy.spd = input;
							std::cout << "\n\n";
						}
						if (input == 4)
						{
							input = 0;
							std::cout << "enter a new value for player 2 def" << "\n\n";
							std::cin >> input;
							enemy.def = input;
							std::cout << "\n\n";
						}
						if (input == 5)
						{
							input = 0;
							std::cout << "enter a new value for player 2 res" << "\n\n";
							std::cin >> input;
							enemy.res = input;
							std::cout << "\n\n";
						}
						if (input == 6)
						{
							goto start;
						}
					}
				}
				if (input == 3) 
				{
					return 0;
				}
				if (input == 4)
				{
					int input = 0;
					std::cout << "Who attacks first?" << "\n\n" << "Press 1 for player 1 to attack first" << "\n\n" << "Press 2 for player 2 to attack first";
					std::cin >> input;



					//PROBLEMET ÄR ATT VI PRINTAR UT ENEMY OG HP ISTÄLLET FÖR SKILLNADEN MELLAN OG HP OCH HP EFTER DAMAGE
					if (input == 1)
					{
						
						playerAttack(player, enemy);

						std::cout << "Player 1 did " << enemy.hp - enemy.changeHP(0) << " damage" << "\n\n";

					
						enemyAttack(player, enemy);


						if (player.spd - enemy.spd >= 5)
						{
							playerAttack(player, enemy);
						}

						if (enemy.spd - player.spd >= 5)
						{
							enemyAttack(player, enemy);
						}
					}
					if (input == 2)
					{
						enemyAttack(player, enemy);

						playerAttack(player, enemy);

						if (enemy.spd - player.spd >= 5)
						{
							enemyAttack(player, enemy);
						}

						if (player.spd - enemy.spd >= 5)
						{
							playerAttack(player, enemy);
						}

					}
					
				}
			}
			if (input == 3) 
			{
				return 0;
			}

		}
		//If statement that closes the program
		if (input == 2) 
		{
			return 0;

		}
	}
}

void playerAttack(Player P, Enemy E)
{
	E.changeHP((P.atk - E.def) / 2);

}

void enemyAttack(Player P, Enemy E)
{
	P.changeHP((E.atk - P.def) / 2);
}