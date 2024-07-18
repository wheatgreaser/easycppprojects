#include <iostream>
#include <vector>
#include <cmath>

// Function to perform Jacobi rotation on a symmetric matrix
void jacobiRotate(std::vector<std::vector<double>>& A, std::vector<double>& eigenvector, int p, int q, int n) {
    double theta = 0.0;
    double tan_phi = 0.0;

    // Compute theta
    if (std::abs(A[p][q]) > 1e-10) {
        theta = 0.5 * std::atan2(2 * A[p][q], A[q][q] - A[p][p]);
        tan_phi = std::tan(theta);
    } else {
        theta = 3.14159265358979323846 / 4.0; // Use the alternative value of pi
        tan_phi = 1.0;
    }

    // Compute elements of rotation matrix R
    double cos_theta = std::cos(theta);
    double sin_theta = std::sin(theta);
    double cos_phi = 1.0 / std::sqrt(1.0 + tan_phi * tan_phi);
    double sin_phi = tan_phi * cos_phi;

    // Apply similarity transformation on columns p and q
    for (int i = 0; i < n; ++i) {
        if (i != p && i != q) {
            double A_ip = A[i][p];
            double A_iq = A[i][q];
            A[i][p] = A_ip * cos_theta - A_iq * sin_theta;
            A[p][i] = A[i][p];
            A[i][q] = A_iq * cos_theta + A_ip * sin_theta;
            A[q][i] = A[i][q];
        }
    }

    // Update diagonal elements
    double A_pp = A[p][p];
    double A_qq = A[q][q];
    A[p][p] = A_pp * cos_theta * cos_theta - 2.0 * A[p][q] * cos_theta * sin_theta + A_qq * sin_theta * sin_theta;
    A[q][q] = A_qq * cos_theta * cos_theta + 2.0 * A[p][q] * cos_theta * sin_theta + A_pp * sin_theta * sin_theta;
    A[p][q] = 0.0;  // Off-diagonal elements are set to zero
    A[q][p] = 0.0;

    // Update eigenvector
    double v_p = eigenvector[p];
    double v_q = eigenvector[q];
    eigenvector[p] = v_p * cos_theta - v_q * sin_theta;
    eigenvector[q] = v_q * cos_theta + v_p * sin_theta;
}

// Function to perform Jacobi method to find eigenvalues and eigenvectors
std::vector<double> findEigenvector(const std::vector<std::vector<double>>& matrix, double eigenvalue) {
    int n = matrix.size();
    std::vector<std::vector<double>> A = matrix;  // Copy of the input matrix

    // Initialize eigenvector (start with [1, 0, 0, ...])
    std::vector<double> eigenvector(n, 0);
    eigenvector[0] = 1.0;

    // Jacobi iterations
    const int maxIterations = 1000;
    const double tolerance = 1e-10;
    int iter = 0;
    while (iter < maxIterations) {
        // Find maximum off-diagonal element
        double maxOffDiag = 0.0;
        int p = 0, q = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (std::abs(A[i][j]) > maxOffDiag) {
                    maxOffDiag = std::abs(A[i][j]);
                    p = i;
                    q = j;
                }
            }
        }

        // Check convergence
        if (maxOffDiag < tolerance) {
            break;
        }

        // Perform Jacobi rotation on A and eigenvector
        jacobiRotate(A, eigenvector, p, q, n);

        ++iter;
    }

    // Normalize eigenvector
    double norm = 0.0;
    for (int i = 0; i < n; ++i) {
        norm += eigenvector[i] * eigenvector[i];
    }
    norm = std::sqrt(norm);
    for (int i = 0; i < n; ++i) {
        eigenvector[i] /= norm;
    }

    return eigenvector;
}

int main() {
    // Example 3x3 symmetric matrix
    std::vector<std::vector<double>> matrix = {
        {0.2, 0.6, 0.2},
        {0.3, 0, 0.7},
        {0.5, 0, 0.5}
    };

    std::vector<double> eigenvector = findEigenvector(matrix, 1.0);

    // Print the eigenvector as a row vector
    std::cout << "Eigenvector corresponding to eigenvalue 1 as a row vector:" << std::endl;
    std::cout << "[ ";
    for (double elem : eigenvector) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
