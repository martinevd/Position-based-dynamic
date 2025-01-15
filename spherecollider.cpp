#include "spherecollider.h"

SphereCollider::SphereCollider(Vec2 center, float radius):center(center),radius(radius){}

void SphereCollider::draw(QPainter& p) const{
    QRectF target(center.getx() - radius,
                  center.gety() - radius,
                  radius * 2, radius * 2);
    p.setPen(Qt::white);
    p.setBrush(QBrush(Qt::black));
    p.drawEllipse(target);
}

std::optional<StaticConstraint> SphereCollider::checkContact(Particle& particle) const{
    float sdf = (particle.getExpectedPos() - center).norm() - radius;
    float C = sdf - particle.getRadius();
    if (C <0){
        Vec2 nc = (particle.getExpectedPos() - center).normalize();
        Vec2 delta = nc * (-C);
        StaticConstraint constraint (delta,&particle);
        return std::optional<StaticConstraint>(constraint);
    }
    return std::nullopt;
}
