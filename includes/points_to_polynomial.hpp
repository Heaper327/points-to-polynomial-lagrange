#ifndef POINTS_TO_POLYNOMIAL_HPP
#define POINTS_TO_POLYNOMIAL_HPP

#include <stdexcept>
#include <vector>

/**
 * @brief Find the unique polynomial of degree n-1 that passes through all n
 * points given to this function.
 *
 * @param points A vector of points that the returned polynomial is fitted to.
 * Must contain at least 2 points, and no two point can share the same
 * x-coordinate.
 * @exception invalid_argument Thrown when the given points do not meet the two
 * requirements above.
 * @return std::vector<double> The coefficients of the polynomial that fits the
 * given points, starting with the coefficient of the lowest degree term.
 * (e.g. [1, 2, 3] corresponds to the polynomial 3x^2 + 2x + 1)
 */
std::vector<double> PointsToPolynomial(std::vector<double> points);

#endif