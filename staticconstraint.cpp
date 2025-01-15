#include "staticconstraint.h"

StaticConstraint::StaticConstraint(Vec2 delta, Particle* particle): delta(delta), particle(particle) {}

StaticConstraint::StaticConstraint(const StaticConstraint& other): delta(other.delta), particle(other.particle){}

StaticConstraint& StaticConstraint::operator=(const StaticConstraint& other){
    if (this != &other) {
        delta = other.delta;
        particle = other.particle;
    }
    return *this;
}

const Vec2& StaticConstraint::getDelta() const{
    return delta;
}

//Ici on ne retourne pas un pointeur constant puisque la fonction va être utilisé
//dans l'appel de enforceStaticGroundConstraint où il va falloir modifier particle.
Particle* StaticConstraint::getParticle(){
    return particle;
}
