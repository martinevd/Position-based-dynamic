#include "plancollider.h"
#include <math.h>

PlanCollider::PlanCollider(Vec2 point,Vec2 normal):point(point),normal(normal.normalize()){}

void PlanCollider::draw(QPainter& p) const{
    Vec2 tangent(-normal.gety(), normal.getx());

    Vec2 startPoint = point + tangent * 1000;
    Vec2 endPoint   = point - tangent * 1000;
    p.setPen(Qt::white);
    p.drawLine(QPointF(startPoint.getx(), startPoint.gety()), QPointF(endPoint.getx(), endPoint.gety()));
}

std::optional<StaticConstraint> PlanCollider::checkContact(Particle& particle) const{
    float sdf = (particle.getExpectedPos() - point).dot(normal);
    float C = sdf - particle.getRadius();
    if(C < 0){
        Vec2 delta = normal * (-C);
        StaticConstraint constraint (delta,&particle);
        return std::optional<StaticConstraint>(constraint);
    }
    return std::nullopt;
}

/*    //Vec2 pc = normal*((particle.expected_pos-point).dot(normal) - particle.radius);
    Vec2 pc = particle.expected_pos + normal*(-particle.radius);
    Vec2 nc = normal;

    if((particle.expected_pos - pc).dot(nc) - particle.radius < 0){
        Vec2 qc = particle.expected_pos - nc*(particle.expected_pos - pc).dot(nc);
        float C =  (particle.expected_pos - qc).dot(nc) - particle.radius;
        Vec2 delta = nc * (-C);
        StaticConstraint constraint (delta,&particle);
        return std::optional<StaticConstraint>(constraint);
    }
*/
