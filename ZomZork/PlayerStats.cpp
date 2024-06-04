#include "PlayerStats.h"

PlayerStats::PlayerStats() {
    //initialize to a default value (the plaer starts w melee and can then decide to change)
    setMeleeAttack(5);
}

void PlayerStats::setMeleeAttack(int dmg) {
    attack.meleeDmg = dmg;
    current = attackType::MELEE;
}
void PlayerStats::setRangeAttack(float dmg) {
    attack.rangedDmg = dmg;
    current = attackType::RANGED;
}
void PlayerStats::setMagicAttack(char spell) {
    attack.magicSpell = spell;
    current = attackType::MAGIC;
}
