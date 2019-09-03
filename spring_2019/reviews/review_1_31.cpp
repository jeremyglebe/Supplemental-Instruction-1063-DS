#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Move {
    string name;
    string type;
    vector<string> effects;
};

struct Monster {
    int hp;
    int level;
    string name;
    string type;
    vector<Move> moves;
    //Constructor
    Monster(string new_name, string new_type){
        hp = 100;
        level = 50;
        type = new_type;
        name = new_name;
    }
    //Method
    void teach(Move new_move){
        moves.push_back(new_move);
    }
};

void header();
void _damage(const Monster& source, Monster& target, Move move);
void use(Monster& source, Monster& target, Move move);

int main(){
    header();

    //Create the move "Cut"
    Move cut;
    cut.name = "Cut";
    cut.type = "scissors";
    cut.effects.push_back("_damage");

    Monster ply("Player", "rock");
    Monster enmy("Enemy", "paper");
    ply.teach(cut);
    enmy.teach(cut);

    cout << "Battle Commence" << '\n';
    cout << "Player Sent Out: " << ply.name << '\n';
    cout << "Enemy Sent Out: " << enmy.name << '\n';
    cout << "Status Reports:\n"
        << '\t' << ply.name << ": " << ply.hp << "/100 HP\n"
        << '\t' << enmy.name << ": " << enmy.hp << "/100 HP\n";
    use(ply, enmy, cut);
    use(enmy, ply, cut);
    cout << "Status Reports:\n"
        << '\t' << ply.name << ": " << ply.hp << "/100 HP\n"
        << '\t' << enmy.name << ": " << enmy.hp << "/100 HP\n";

    return 0;
}

void header(){
    cout << "\033[31;47m"
        << "╔══════════════════════════════════════╗\n"
        << "║   Topics To Cover (Review 1/31/19)   ║\n"
        << "╚══════════════════════════════════════╝\n"
        << "\033[0;32m"
        << "\t- Structs\n"
        << "\t- Arrays of Structs\n"
        << "\t- Vectors of Structs\n\n"
        << "Join this session: "
        << "https://repl.it/live/qUMsamGfkJUfmg\n";
    return;
}

void _damage(const Monster& source, Monster& target, Move move){
    int damage = source.level / 2;
    if(
    (move.type == "scissors" && target.type == "paper")
    || (move.type == "rock" && target.type == "scissors")
    || (move.type == "paper" && target.type == "rock")
    ){
        damage *= 2;
    }
    target.hp -= damage;
}
void use(Monster& source, Monster& target, Move move){
    for(int i = 0; i < move.effects.size(); i++){
        if(move.effects[i] == "_damage"){
            _damage(source, target, move);
        }
    }
    return;
}