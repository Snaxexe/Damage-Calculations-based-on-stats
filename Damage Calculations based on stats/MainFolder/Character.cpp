#include <string>
#include <iostream>


class character
{
public:
	int hp = 0;
	int atk = 0;
	int spd = 0;
	int def = 0;
	int res = 0;

	virtual void print_stats() 
	{
		std::cout << hp << "hp" << "\n\n";
		std::cout << atk << "atk" << "\n\n";
		std::cout << spd << "spd" << "\n\n";
		std::cout << def << "def"<< "\n\n";
		std::cout << res << "res" << "\n\n";
	}
};


class Enemy : public character
{
public:
	int changeHP(int newHp) 
	{
		hp -= newHp; 
		return newHp;
	};

private:
	
};

class Player: public character
{
public:
	void changeHP(int a) 
	{
		hp -= a;
	};

private:

};

