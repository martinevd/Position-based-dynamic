#include "particle.h"
#include "StaticConstraint.h"
#include "constants.h"

Particle::Particle(Vec2 pos,Vec2 vel, float rad,float mass):pos(pos),expected_pos(pos),velocity(vel),fext(Vec2 (0,0)),radius(rad),mass(mass){}

const Vec2& Particle::getPos() const{
    return pos;
}

void Particle::changePos(const Vec2& newPos){
    pos = newPos;
}

const Vec2& Particle::getExpectedPos() const{
    return expected_pos;
}

void Particle::changeExpectedPos(const Vec2& newExpectedPos){
    expected_pos = newExpectedPos;
}

const Vec2& Particle::getVelocity() const{
    return velocity;
}

void Particle::changeVelocity(const Vec2& newVelocity){
    if (newVelocity.norm() > max_speed){
        velocity = newVelocity.normalize() * max_speed;
        return;
    }
    velocity = newVelocity;
}

const Vec2& Particle::getFext() const{
    return fext;
}

void Particle::resetFext(){
    fext = Vec2(0,0);
}

void Particle::changeFext(const Vec2& newFext){
    fext = newFext;
}

//Pour la gravité, on recrée un vecteur donc pour éviter les copies
//inutiles, on privéligie une RValue ref
void Particle::changeFext(Vec2&& newFext){
    fext = newFext;
}

float Particle::getRadius() const{
    return radius;
}

float Particle::getMass() const{
    return mass;
}

void Particle::draw(QPainter& p) const{
    QRectF target(pos.getx() - radius,
                  pos.gety() - radius,
                  radius * 2, radius * 2);
    p.setPen(Qt::white);
    p.setBrush(QBrush(Qt::white));
    p.drawEllipse(target);
}

std::optional<StaticConstraint> Particle::checkContact(Particle& other){
    Vec2 xji = expected_pos - other.expected_pos;
    float C = xji.norm() - (radius + other.radius);
    if (C<0){
        float sigmai = 1/mass * 1/(1/mass + 1/other.mass) * C;
        Vec2 delta = xji * (-sigmai) / (xji.norm() + 0.001); // + 0.001 pour éviter la division par zero !
        StaticConstraint constraint (delta,this);
        return std::optional<StaticConstraint>(constraint);
    }
    return std::nullopt;
}
