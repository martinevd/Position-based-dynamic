#ifndef VEC2_H
#define VEC2_H

/**
 * @brief Represents a 2D vector with floating-point components.
 *
 * The `Vec2` class provides basic vector operations, such as addition,
 * subtraction, scalar multiplication, normalization, and dot product.
 * It is used in simulations for representing positions, velocities, forces, etc.
 */
class Vec2 {
private:
    float x; ///< The x-coordinate of the vector.
    float y; ///< The y-coordinate of the vector.

public:
    /**
     * @brief Constructs a new 2D vector with specified components.
     *
     * @param x The x-coordinate of the vector.
     * @param y The y-coordinate of the vector.
     */
    Vec2(float x, float y);

    /**
     * @brief Copy constructor for `Vec2`.
     *
     * Creates a new vector by copying the components of another vector.
     *
     * @param other The vector to copy.
     */
    Vec2(const Vec2& other);

    /**
     * @brief Default destructor for `Vec2`.
     */
    ~Vec2() = default;

    /**
     * @brief Gets the x-coordinate of the vector.
     *
     * @return The x-coordinate of the vector.
     */
    float getx() const;

    /**
     * @brief Sets the x-coordinate of the vector.
     *
     * @param newx The new value for the x-coordinate.
     */
    void setx(float newx);

    /**
     * @brief Gets the y-coordinate of the vector.
     *
     * @return The y-coordinate of the vector.
     */
    float gety() const;

    /**
     * @brief Sets the y-coordinate of the vector.
     *
     * @param newy The new value for the y-coordinate.
     */
    void sety(float newy);

    /**
     * @brief Adds another vector to this vector and returns the result.
     *
     * @param other The vector to add.
     * @return A new vector that is the sum of this vector and `other`.
     */
    Vec2 operator+(const Vec2& other) const;

    /**
     * @brief Subtracts another vector from this vector and returns the result.
     *
     * @param other The vector to subtract.
     * @return A new vector that is the difference between this vector and `other`.
     */
    Vec2 operator-(const Vec2& other) const;

    /**
     * @brief Multiplies this vector by a scalar and returns the result.
     *
     * @param scalar The scalar to multiply with.
     * @return A new vector that is this vector scaled by `scalar`.
     */
    Vec2 operator*(float scalar) const;

    /**
     * @brief Divides this vector by a scalar and returns the result.
     *
     * @param scalar The scalar to divide by.
     * @return A new vector that is this vector scaled by `1/scalar`.
     * @throw std::runtime_error if `scalar` is zero.
     */
    Vec2 operator/(float scalar) const;

    /**
     * @brief Assigns the values of another vector to this vector.
     *
     * @param other The vector to copy.
     * @return A reference to this vector.
     */
    Vec2& operator=(const Vec2& other);

    /**
     * @brief Adds another vector to this vector in-place.
     *
     * @param other The vector to add.
     * @return A reference to this vector after addition.
     */
    Vec2& operator+=(const Vec2& other);

    /**
     * @brief Compares this vector with another for equality.
     *
     * @param other The vector to compare with.
     * @return True if both vectors have the same components, false otherwise.
     */
    bool operator==(const Vec2& other) const;

    /**
     * @brief Calculates the norm of the vector.
     *
     * @return The norm of the vector.
     */
    float norm() const;

    /**
     * @brief Normalizes the vector (scales it to unit length).
     *
     * @return A new vector that is the normalized version of this vector.
     * @throw std::runtime_error if the vector has a norm of zero.
     */
    Vec2 normalize() const;

    /**
     * @brief Computes the dot product of this vector with another.
     *
     * @param other The vector to compute the dot product with.
     * @return The dot product of this vector and `other`.
     */
    float dot(const Vec2& other) const;

    /**
     * @brief Prints the components of the vector to the console.
     *
     * Used for debugging purposes.
     */
    void print() const;
};

#endif // VEC2_H
