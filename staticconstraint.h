#ifndef STATICCONSTRAINT_H
#define STATICCONSTRAINT_H

#include "vec2.h"
#include "particle.h"

/**
 * @brief Represents a static constraint between a particle and a static object.
 *
 * The `StaticConstraint` structure stores information about a detected constraint,
 * such as the displacement required to resolve the contact (`delta`) and the particle
 * affected by the constraint.
 */
struct StaticConstraint {
private:
    Vec2 delta;          ///< Displacement vector required to resolve the constraint.
    Particle* particle;  ///< Pointer to the particle affected by the constraint.

public:
    /**
     * @brief Constructs a new `StaticConstraint`.
     *
     * @param delta The displacement vector required to resolve the constraint.
     * @param particle Pointer to the particle affected by the constraint.
     */
    StaticConstraint(Vec2 delta, Particle* particle);

    /**
     * @brief Default destructor for `StaticConstraint`.
     */
    ~StaticConstraint() = default;

    /**
     * @brief Copy constructor for `StaticConstraint`.
     *
     * Creates a new `StaticConstraint` by copying the values from another instance.
     *
     * @param other The `StaticConstraint` to copy from.
     */
    StaticConstraint(const StaticConstraint& other);

    /**
     * @brief Copy assignment operator for `StaticConstraint`.
     *
     * Copies the values from another `StaticConstraint` instance to this instance.
     *
     * @param other The `StaticConstraint` to copy from.
     * @return A reference to this `StaticConstraint` instance.
     */
    StaticConstraint& operator=(const StaticConstraint& other);

    /**
     * @brief Retrieves the displacement vector (`delta`) of the constraint.
     *
     * @return A constant reference to the displacement vector.
     */
    const Vec2& getDelta() const;

    /**
     * @brief Retrieves the particle associated with the constraint.
     *
     * @return A pointer to the particle affected by the constraint.
     */
    Particle* getParticle();
};

#endif // STATICCONSTRAINT_H
