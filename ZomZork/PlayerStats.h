#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H

// this is for the future development of the game
class PlayerStats
{
public:
    PlayerStats();

    enum class attackType {
        MELEE,
        RANGED,
        MAGIC
    };

    void setMeleeAttack(int damage);
    void setRangeAttack(float damage);
    void setMagicAttack(char spell);

private:
    attackType current;

    union Attack {
        int meleeDmg;
        float rangedDmg;
        char magicSpell;

        Attack() {}
        ~Attack() {}
    } attack;

};

#endif // PLAYERSTATS_H
