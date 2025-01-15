#ifndef CONTEXT_H
#define CONTEXT_H

#include <vector>
#include "particle.h"
#include "collider.h"

/**
 * @brief Manages the simulation context.
 *
 * The `Context` class handles the entire physical simulation, including the
 * particles, colliders, and constraints. It provides functionality to update
 * the physical system over time and resolve constraints between objects.
 */
class Context {
public:
    /**
     * @brief Constructs a new simulation context.
     *
     * Initializes empty containers for particles, colliders, and constraints.
     */
    Context();

    /**
     * @brief Default destructor for the Context.
     *
     * Automatically cleans up all dynamically allocated resources (RAII).
     */
    ~Context() = default;

    /**
     * @brief Initializes the context with an example configuration.
     *
     * Sets up predefined particles and colliders for testing or demonstration.
     */
    void initializeExampleConfiguration();

    /**
     * @brief Retrieves the list of particles in the simulation.
     *
     * Provides read-only access to the particles managed by the context.
     *
     * @return A constant reference to the vector of `std::unique_ptr<Particle>`.
     */
    const std::vector<std::unique_ptr<Particle>>& getParticles() const;

    /**
     * @brief Retrieves the list of colliders in the simulation.
     *
     * Provides read-only access to the colliders managed by the context.
     *
     * @return A constant reference to the vector of `std::unique_ptr<Collider>`.
     */
    const std::vector<std::unique_ptr<Collider>>& getColliders() const;

    /**
     * @brief Adds a new particle to the simulation.
     *
     * Transfers ownership of the given particle to the context.
     *
     * @param particle An r-value reference to a `Particle` object.
     */
    void addParticle(Particle&& particle);

    /**
     * @brief Updates the physical system over a time step.
     *
     * Simulates the evolution of the system by applying external forces,
     * resolving constraints, and updating particle positions and velocities.
     *
     * @param dt The time step duration in seconds.
     */
    void updatePhysicalSystem(float dt);

private:
    /// List of particles in the simulation.
    std::vector<std::unique_ptr<Particle>> particles;

    /// List of colliders (e.g., planes, spheres) in the simulation.
    std::vector<std::unique_ptr<Collider>> colliders;

    /// List of static constraints detected in the current frame.
    std::vector<std::unique_ptr<StaticConstraint>> staticConstraints;

    /**
     * @brief Applies external forces to all particles.
     *
     * Calculates forces such as gravity and updates each particle's
     * force accumulator accordingly.
     *
     * @param dt The time step duration in seconds.
     */
    void applyExternalForce(float dt);

    /**
     * @brief Updates the velocity of all particles.
     *
     * Uses the forces applied to particles to calculate their new
     * velocities based on the given time step.
     *
     * @param dt The time step duration in seconds.
     */
    void updateVelocity(float dt);

    /**
     * @brief Computes the expected positions of particles.
     *
     * Calculates the predicted positions of particles based on their
     * current velocities and the given time step.
     *
     * @param dt The time step duration in seconds.
     */
    void updateExpectedPosition(float dt);

    /**
     * @brief Detects and adds static contact constraints.
     *
     * Iterates over all particles and colliders, checking for active
     * collisions and generating constraints to resolve them.
     */
    void addStaticContactConstraints();

    /**
     * @brief Resolves a static ground constraint for a particle.
     *
     * Adjusts the particle's expected position based on the correction
     * specified in the constraint.
     *
     * @param constraint The static constraint to enforce.
     * @param particle The particle affected by the constraint.
     */
    void enforceStaticGroundConstraint(const StaticConstraint& constraint, Particle& particle);

    /**
     * @brief Projects all constraints to resolve collisions.
     *
     * Iterates over the list of constraints and applies corrections
     * to enforce the constraints on the associated particles.
     */
    void projectConstraints();

    /**
     * @brief Updates the final velocity and position of particles.
     *
     * Adjusts particle velocities and positions based on the corrections
     * applied during constraint resolution.
     *
     * @param dt The time step duration in seconds.
     */
    void updateVelocityAndPosition(float dt);
};

#endif // CONTEXT_H
