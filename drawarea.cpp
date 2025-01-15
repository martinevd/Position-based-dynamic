#include "drawarea.h"
#include "QPainter"
#include "QPaintEvent"
#include "context.h"
#include "constants.h"

DrawArea::DrawArea(QOpenGLWidget *parent)
    : QOpenGLWidget{parent}, context(std::make_unique<Context>())
{
    this->update();
}

void DrawArea::paintEvent(QPaintEvent *e){
    QPainter p(this);
    p.fillRect(e->rect(), Qt::black);
    animate();
    for(const auto& particle: context->getParticles()){
        particle->draw(p);
    }
    for(const auto& collider: context->getColliders()){
        collider->draw(p);
    }
}

void DrawArea::mouseDoubleClickEvent(QMouseEvent *event) {
    QPointF mousePos = event->position();
    this->context->addParticle(Particle(Vec2(mousePos.x(), mousePos.y()), Vec2(0, 0), 10, 1));
    this->update();
}


void DrawArea::animate(){
    context->updatePhysicalSystem(tau/100);
}

void DrawArea::resetContext(){
    context = std::make_unique<Context>();
}
