#ifndef SPHERECOLLIDER_H
#define SPHERECOLLIDER_H

#include "collider.h"

/**
 * @brief Represents a spherical collider in the simulation.
 *
 * The `SphereCollider` class models a spherical object that detects and resolves
 * collisions with particles in the simulation. It inherits from `Collider` and provides
 * specific implementations for rendering and contact detection.
 */
class SphereCollider : public Collider {
private:
    Vec2 center;  ///< The center position of the sphere.
    float radius; ///< The radius of the sphere.

public:
    /**
     * @brief Constructs a new `SphereCollider` object.
     *
     * @param center The center position of the sphere.
     * @param radius The radius of the sphere.
     */
    SphereCollider(Vec2 center, float radius);

    /**
     * @brief Default destructor for the `SphereCollider`.
     */
    ~SphereCollider() override = default;

    /**
     * @brief Renders the spherical collider using a `QPainter`.
     *
     * Draws a visual representation of the sphere on the rendering area.
     *
     * @param p The `QPainter` used for rendering.
     */
    void draw(QPainter& p) const override;

    /**
     * @brief Checks for contact between a particle and the sphere.
     *
     * Determines if a particle intersects with the sphere and, if so,
     * calculates the necessary correction as a `StaticConstraint`.
     *
     * @param particle The particle to check for contact.
     * @return A `std::optional<StaticConstraint>` containing the constraint
     *         if a contact is detected, or `std::nullopt` otherwise.
     */
    std::optional<StaticConstraint> checkContact(Particle& particle) const override;
};

#endif // SPHERECOLLIDER_H
