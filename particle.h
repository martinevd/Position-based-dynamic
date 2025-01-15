#ifndef PARTICLE_H
#define PARTICLE_H

#include "vec2.h"
#include <optional>
#include <QPainter>

/**
 * @brief Forward declaration of `StaticConstraint`.
 *
 * This avoids circular dependencies between `Particle` and `StaticConstraint`.
 */
class StaticConstraint;

/**
 * @brief Represents a particle in the simulation.
 *
 * The `Particle` class models a point-like object with physical properties
 * such as position, velocity, radius, and mass. It supports interactions
 * with other particles and colliders in the simulation.
 */
class Particle {
private:
    Vec2 pos;               ///< Current position of the particle.
    Vec2 expected_pos;      ///< Predicted position of the particle (used for constraint resolution).
    Vec2 velocity;          ///< Current velocity of the particle.
    Vec2 fext;              ///< External forces applied to the particle.
    float radius;           ///< Radius of the particle.
    float mass;             ///< Mass of the particle.

public:
    /**
     * @brief Constructs a new `Particle` object.
     *
     * @param pos Initial position of the particle.
     * @param vel Initial velocity of the particle.
     * @param rad Radius of the particle.
     * @param mass Mass of the particle.
     */
    Particle(Vec2 pos, Vec2 vel, float rad, float mass);

    /**
     * @brief Default destructor for the `Particle`.
     */
    ~Particle() = default;

    /**
     * @brief Gets the current position of the particle.
     *
     * @return A constant reference to the particle's position.
     */
    const Vec2& getPos() const;

    /**
     * @brief Sets a new position for the particle.
     *
     * @param newPos The new position to assign.
     */
    void changePos(const Vec2& newPos);

    /**
     * @brief Gets the predicted position of the particle.
     *
     * @return A constant reference to the particle's expected position.
     */
    const Vec2& getExpectedPos() const;

    /**
     * @brief Updates the predicted position of the particle.
     *
     * @param newExpectedPos The new predicted position to assign.
     */
    void changeExpectedPos(const Vec2& newExpectedPos);

    /**
     * @brief Gets the current velocity of the particle.
     *
     * @return A constant reference to the particle's velocity.
     */
    const Vec2& getVelocity() const;

    /**
     * @brief Sets a new velocity for the particle.
     *
     * @param newVelocity The new velocity to assign.
     */
    void changeVelocity(const Vec2& newVelocity);

    /**
     * @brief Gets the external force acting on the particle.
     *
     * @return A constant reference to the external force vector.
     */
    const Vec2& getFext() const;

    /**
     * @brief Resets the external forces acting on the particle to zero.
     */
    void resetFext();

    /**
     * @brief Updates the external force acting on the particle.
     *
     * @param newFext The new external force to assign.
     */
    void changeFext(const Vec2& newFext);

    /**
     * @brief Updates the external force acting on the particle using an r-value reference.
     *
     * @param newFext The new external force to assign (moved).
     */
    void changeFext(Vec2&& newFext);

    /**
     * @brief Gets the radius of the particle.
     *
     * @return The radius of the particle.
     */
    float getRadius() const;

    /**
     * @brief Gets the mass of the particle.
     *
     * @return The mass of the particle.
     */
    float getMass() const;

    /**
     * @brief Renders the particle using a QPainter.
     *
     * Draws the particle as a filled circle on the specified painter.
     *
     * @param p The `QPainter` used for rendering.
     */
    void draw(QPainter& p) const;

    /**
     * @brief Checks for contact between this particle and another particle.
     *
     * Determines if the particles are in contact and, if so, returns
     * a `StaticConstraint` describing the necessary correction.
     *
     * @param other The other particle to check contact with.
     * @return A `std::optional<StaticConstraint>` containing the constraint
     *         if a contact is detected, or `std::nullopt` otherwise.
     */
    std::optional<StaticConstraint> checkContact(Particle& other);
};

#endif // PARTICLE_H
