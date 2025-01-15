#ifndef COLLIDER_H
#define COLLIDER_H

#include "staticconstraint.h"
#include <optional>
#include <QPainter>

/**
 * @brief Base class for colliders in the simulation.
 *
 * Represents an abstract interface for objects that can detect collisions
 * with particles and optionally apply constraints to resolve those collisions.
 */
class Collider {
public:
    /**
     * @brief Default constructor for Collider.
     */
    Collider() = default;

    /**
     * @brief Virtual destructor for Collider.
     *
     * Ensures proper cleanup of derived classes.
     */
    virtual ~Collider() = default;

    /**
     * @brief Draws the collider on a given painter.
     *
     * Derived classes should override this method to implement their specific
     * drawing behavior.
     *
     * @param p The QPainter object used for rendering.
     */
    virtual void draw(QPainter& p) const {}

    /**
     * @brief Checks for a contact between the collider and a particle.
     *
     * Determines if the given particle is in contact with the collider and,
     * if so, returns a `StaticConstraint` to resolve the contact.
     *
     * Derived classes should override this method to implement their specific
     * collision detection logic.
     *
     * @param particle The particle to check for contact.
     * @return A `std::optional<StaticConstraint>` containing the contact constraint
     *         if a collision is detected, or `std::nullopt` otherwise.
     */
    virtual std::optional<StaticConstraint> checkContact(Particle& particle) const {
        return std::nullopt;
    }
};

#endif // COLLIDER_H
