#ifndef PLANCOLLIDER_H
#define PLANCOLLIDER_H

#include "collider.h"

/**
 * @brief Represents a planar collider in the simulation.
 *
 * The `PlanCollider` class models an infinite plane used for detecting
 * and resolving collisions with particles in the simulation. It inherits
 * from `Collider` and provides specific implementations for rendering
 * and contact detection.
 */
class PlanCollider : public Collider {
private:
    Vec2 point;   ///< A point on the plane.
    Vec2 normal;  ///< The normal vector of the plane.

public:
    /**
     * @brief Constructs a new `PlanCollider` object.
     *
     * @param point A point on the plane.
     * @param normal The normal vector of the plane.
     */
    PlanCollider(Vec2 point, Vec2 normal);

    /**
     * @brief Default destructor for the `PlanCollider`.
     */
    ~PlanCollider() override = default;

    /**
     * @brief Renders the planar collider using a `QPainter`.
     *
     * Draws a visual representation of the plane on the rendering area.
     *
     * @param p The `QPainter` used for rendering.
     */
    void draw(QPainter& p) const override;

    /**
     * @brief Checks for contact between a particle and the plane.
     *
     * Determines if a particle intersects with the plane and, if so,
     * calculates the necessary correction as a `StaticConstraint`.
     *
     * @param particle The particle to check for contact.
     * @return A `std::optional<StaticConstraint>` containing the constraint
     *         if a contact is detected, or `std::nullopt` otherwise.
     */
    std::optional<StaticConstraint> checkContact(Particle& particle) const override;
};

#endif // PLANCOLLIDER_H
