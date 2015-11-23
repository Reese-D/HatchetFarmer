#include "Unit.hpp"

void Unit::attack(std::shared_ptr<Unit> b){
  b->takeDamage(damage);
}

bool Unit::takeDamage(int damageRecieved){
  health -= damageRecieved;
  if(health < 0){
    delete this;
    return false;
  }
  return true;
}
