#pragma once

#include <iostream>
#include <istream>
#include <vector>

template<typename type, unsigned short N, unsigned short M>
class matrix {
private:
    type m_matrix[N][M];
    unsigned short row = N;
    unsigned short column = M;

    template<typename type, unsigned short N, unsigned short M>
    friend std::ostream& operator<<(std::ostream& out, const matrix<type, N, M>& current);

    template<typename type, unsigned short N, unsigned short M>
    friend std::istream& operator>> (std::istream& in, matrix<type, N, M>& current);
public:
    matrix() = default;

    matrix(const matrix& current) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                m_matrix[i][j] = current.m_matrix[i][j];
            }
        }
    }

    matrix& operator= (const matrix<type, N, M>& current) {
        if (this != &current) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    m_matrix[i][j] = current.m_matrix[i][j];
                }
            }
        }
        return *this;
    }

    type determinant() {

        if (N == M && M == 2) {
            return static_cast<type>(m_matrix[0][0] * m_matrix[1][1] - m_matrix[1][0] * m_matrix[0][1]);
        }
        else if (N == M && M == 3) {
            return static_cast<type>(m_matrix[0][0] * m_matrix[1][1] * m_matrix[2][2] + m_matrix[1][0] * m_matrix[0][2] * m_matrix[2][1] + m_matrix[0][1] * m_matrix[2][0] * m_matrix[1][2] - m_matrix[0][2] * m_matrix[1][1] * m_matrix[2][0] - m_matrix[0][0] * m_matrix[1][2] * m_matrix[2][1] - m_matrix[2][2] * m_matrix[0][1] * m_matrix[1][0]);
        }
        else if (N == M && M == 1) {
            return static_cast<type>(m_matrix[0][0]);
        }
    }

    matrix& operator+= (const matrix<type, N, M>& rightMatrix) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                m_matrix[i][j] += rightMatrix.m_matrix[i][j];
            }
        }
        return *this;
    }
    matrix operator+ (const matrix<type, N, M>& rightMatrix) {
        matrix<type, N, M> tempMatrix = *this;
        tempMatrix += rightMatrix;
        return tempMatrix;
    }

    type get(unsigned short i, unsigned short j) const {
        return m_matrix[i][j];
    }

    type& set(unsigned short i, unsigned short j) {
        return m_matrix[i][j];
    }

    template<unsigned short U, unsigned short V>
    matrix<type, N, V> operator* (const matrix<type, U, V>& rightMatrix) {
        matrix<type, N, V> tempMatrix{};
        if (M == U) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < V; j++) {
                    tempMatrix.set(i, j) = 0;
                    for (int u = 0; u < M; u++) {
                        tempMatrix.set(i, j) += m_matrix[i][u] * rightMatrix.get(u, j);
                    }
                }
            }
        }
        return tempMatrix;
    }

    matrix& operator++ () {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                m_matrix[i][j]++;
            }
        }
    }

    type& at(unsigned int firstIndex, unsigned int secondIndex) {
        if (firstIndex < N && secondIndex < M) {
            return m_matrix[firstIndex][secondIndex];
        }
        std::abort();

    }
};

template<typename type, unsigned short N, unsigned short M>
std::istream& operator>>(std::istream& in, matrix<type, N, M>& current) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            in >> current.m_matrix[i][j];
        }
    }
    return in;
}

template<typename type, unsigned short N, unsigned short M>
std::ostream& operator<<(std::ostream& out, const matrix<type, N, M>& current) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            out << current.m_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return out;
}



