#include "context.h"
#include "constants.h"
#include "plancollider.h"
#include "spherecollider.h"

Context::Context() {
    initializeExampleConfiguration();
}

void Context::initializeExampleConfiguration() {
    // Particules
    Vec2 null(0, 0);
    float radius_part = 50;

    particles.push_back(std::make_unique<Particle>(Vec2(50, 100), null, radius_part, 100));
    particles.push_back(std::make_unique<Particle>(Vec2(450, 100), null, radius_part, 100));

    // Plans
    colliders.push_back(std::make_unique<PlanCollider>(Vec2(300, 400), Vec2(0, -1)));
    colliders.push_back(std::make_unique<PlanCollider>(Vec2(0, 300), Vec2(1, -1)));

    // Spheres
    colliders.push_back(std::make_unique<SphereCollider>(Vec2(600, 400), 100));
    colliders.push_back(std::make_unique<SphereCollider>(Vec2(500, 200), 30));
}

const std::vector<std::unique_ptr<Particle>>& Context::getParticles() const{
    return particles;
}
const std::vector<std::unique_ptr<Collider>>& Context::getColliders() const{
    return colliders;
}


void Context::addParticle(Particle&& particle){
    //std::move et pas une R-Value reference en paramètre car dans l'appel
    //de std::make_unique, particle devient une l-value
    particles.push_back(std::make_unique<Particle>(std::move(particle)));
}

void Context::updatePhysicalSystem(float dt){
    applyExternalForce(dt);
    updateVelocity(dt);
    updateExpectedPosition(dt);
    addStaticContactConstraints();
    projectConstraints();
    updateVelocityAndPosition(dt);

}
void Context::applyExternalForce(float dt){
    for (auto& particle: particles){
        //Reinitialisation des forces
        particle->resetFext();

        //Recalcule des forces

            //Gravite
        particle->changeFext(Vec2(0,particle->getFext().gety() + g * particle->getMass()));
    }
}

void Context::updateVelocity(float dt){
    for (auto& particle: particles){
        particle->changeVelocity(particle->getVelocity() + particle->getFext() * dt/particle->getMass());
    }
}

void Context::updateExpectedPosition(float dt){
    for (auto& particle: particles){
        particle->changeExpectedPos(particle->getPos() + particle->getVelocity()*dt);
    }
}

void Context::addStaticContactConstraints(){
    staticConstraints.clear();
    for (auto& collider: colliders){
        for (auto& particle: particles){
            std::optional<StaticConstraint> constraint = collider->checkContact(*particle);
            if (constraint) {
                staticConstraints.push_back(std::make_unique<StaticConstraint>(*constraint));
            }
        }
    }
    for (auto& particle1: particles){
        for (auto& particle2: particles){
            std::optional<StaticConstraint> constraint = particle1->checkContact(*particle2);
            if (constraint) {
                staticConstraints.push_back(std::make_unique<StaticConstraint>(*constraint));
            }
        }
    }
}

void Context::enforceStaticGroundConstraint(const StaticConstraint& constraint,Particle& particle){
    particle.changeExpectedPos(particle.getExpectedPos() + constraint.getDelta());
}

void Context::projectConstraints(){
    for (auto& constraint: staticConstraints){
        enforceStaticGroundConstraint(*constraint,*constraint->getParticle());
    }
}

void Context::updateVelocityAndPosition(float dt){
    for (auto& particle: particles){
        particle->changeVelocity((particle->getExpectedPos() - particle->getPos())*1/dt);
        particle->changePos(particle->getExpectedPos());
    }
}

