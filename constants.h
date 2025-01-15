#ifndef CONSTANTS_H
#define CONSTANTS_H

/**
 * @file constants.h
 * @brief Defines global constants used throughout the simulation.
 *
 * This file contains constants for physical parameters and simulation settings
 */

/**
 * @brief Gravitational acceleration (m/s²).
 *
 * Represents the gravitational constant used in the simulation.
 */
#define g 9.8

/**
 * @brief Maximum allowed speed for particles (units/s).
 *
 * Serves as a cap on particle velocity to prevent unrealistic behaviors.
 */
#define max_speed 60

/**
 * @brief Time step duration for the simulation (ms).
 *
 * Used to control the frequency of updates in the simulation loop.
 */
#define tau 16.0

#endif // CONSTANTS_H
