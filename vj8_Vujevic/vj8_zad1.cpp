#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Enemy {
private:
	string name;
	int health;
	int damage;

public:
	Enemy(string name, int health = 0, int damage = 0) : name(name), health(health), damage(damage) {
		if (health == NULL || damage == NULL) {
			throw invalid_argument("nisu uneseni svi parametri protivnika");
		}
	}

	void attack() {
		cout << "neprijatelj " << name <<  " napadnut" << endl;
		health -= 10;
	}

	void displayInfo() {
		cout << name << " Health-> " << health << " Damage-> " << damage << endl;
	}
};

class Boss : public Enemy {
private:
	string dodatnoOruzje;
public:
	Boss(string name, int health, int damage, string dodatnoOruzje = "") : Enemy(name, health, damage), dodatnoOruzje(dodatnoOruzje) {
		if (dodatnoOruzje == "") {
			throw invalid_argument("nisu uneseni svi parametri protivnika");
		}
	}
};

class Monster : public Enemy {
private:
	string posebneSposobnosti;
public:
	Monster(string name, int health, int damage, string posebnesposobnosti = "") : Enemy(name, health, damage), posebneSposobnosti(posebnesposobnosti) {
		if (posebnesposobnosti == "") {
			throw invalid_argument("nisu uneseni svi parametri protivnika");
		}
	}
};

int main() {
	vector<Enemy*> enemies;

	try {
		enemies.push_back(new Enemy("perislav", 100, 80));
		enemies.push_back(new Boss("milan", 70, 60, "kalas"));
		enemies.push_back(new Monster("venom", 70, 90, "puhanje"));

		for (const auto& enemy : enemies) {
			enemy->attack();
			enemy->displayInfo();
			cout << endl;
		}
	}
	catch (const invalid_argument& a) {
		cerr << a.what();
	}
	
	for (const auto& enemy : enemies) {
		delete enemy;
	}

	return 0;
}