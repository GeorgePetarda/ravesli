#include <iostream>
#include <string>

using namespace std;

enum class TypesOfMonsters {
    OGRE,
    GOBLIN,
    SKELETON,
    ORC,
    TROLL
};
struct Monster {
    TypesOfMonsters type;
    string name;
    int health;
};

void printMonsters(Monster a) {
    if (a.type == TypesOfMonsters::TROLL) {
        cout << "This Troll is named " << a.name << " and has " << a.health << " health" << endl;
    }
    if (a.type == TypesOfMonsters::ORC) {
        cout << "This Orc is named " << a.name << " and has " << a.health << " health" << endl;
    }
    if (a.type == TypesOfMonsters::SKELETON) {
        cout << "This Skeleton is named " << a.name << " and has " << a.health << " health" << endl;
    }
    if (a.type == TypesOfMonsters::GOBLIN) {
        cout << "This Goblin is named " << a.name << " and has " << a.health << " health" << endl;
    }
    if (a.type == TypesOfMonsters::OGRE) {
        cout << "This Ogre is named " << a.name << " and has " << a.health << " health" << endl;
    }
}

int main() {
    Monster a { TypesOfMonsters::GOBLIN, "John", 170 };
    Monster b { TypesOfMonsters::ORC, "James", 35 };
    printMonsters(a);
    printMonsters(b);
}
