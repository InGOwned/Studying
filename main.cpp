#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T, int N, int M>
class Matrix {
    static_assert(N <= 3 && M <= 3, "Размеры матрицы должны быть <= 3");
private:
    T data[N][M];

public:
    Matrix() {
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                data[i][j] = T();
    }

    Matrix(const Matrix& other) {
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                data[i][j] = other.data[i][j];
    }

    Matrix& operator=(const Matrix& other) {
        if(this != &other)
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < M; ++j)
                    data[i][j] = other.data[i][j];
        return *this;
    }

    friend istream& operator>>(istream& in, Matrix& mat) {
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                in >> mat.data[i][j];
        return in;
    }

    friend ostream& operator<<(ostream& out, const Matrix& mat) {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j)
                out << mat.data[i][j] << " ";
            out << endl;
        }
        return out;
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix& operator+=(const Matrix& other) {
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                data[i][j] += other.data[i][j];
        return *this;
    }

    template<int K>
    Matrix<T, N, K> operator*(const Matrix<T, M, K>& other) const {
        Matrix<T, N, K> result;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < K; ++j)
                for(int l = 0; l < M; ++l)
                    result(i, j) += data[i][l] * other(l, j);
        return result;
    }

    Matrix operator*(const T& scalar) const {
        Matrix result;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                result.data[i][j] = data[i][j] * scalar;
        return result;
    }

    Matrix& operator*=(const T& scalar) {
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                data[i][j] *= scalar;
        return *this;
    }

    Matrix& operator++() {
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                ++data[i][j];
        return *this;
    }

    Matrix operator++(int) {
        Matrix temp = *this;
        ++(*this);
        return temp;
    }

    T determinant() const {
        static_assert(N == M, "Определитель существует только для квадратных матриц");
        if constexpr(N == 1)
            return data[0][0];
        else if constexpr(N == 2)
            return data[0][0]*data[1][1] - data[0][1]*data[1][0];
        else if constexpr(N == 3)
            return data[0][0]*data[1][1]*data[2][2] + 
                   data[0][1]*data[1][2]*data[2][0] + 
                   data[0][2]*data[1][0]*data[2][1] - 
                   data[0][2]*data[1][1]*data[2][0] - 
                   data[0][1]*data[1][0]*data[2][2] - 
                   data[0][0]*data[1][2]*data[2][1];
    }

    T& operator()(int i, int j) {
        if(i < 0 || i >= N || j < 0 || j >= M)
            throw out_of_range("Индекс за пределами матрицы");
        return data[i][j];
    }

    const T& operator()(int i, int j) const {
        if(i < 0 || i >= N || j < 0 || j >= M)
            throw out_of_range("Индекс за пределами матрицы");
        return data[i][j];
    }
};

int main() {
    Matrix<int, 2, 2> mat1;
    mat1(0, 0) = 1; mat1(0, 1) = 2;
    mat1(1, 0) = 3; mat1(1, 1) = 4;

    Matrix<int, 2, 2> mat2;
    mat2(0, 0) = 5; mat2(0, 1) = 6;
    mat2(1, 0) = 7; mat2(1, 1) = 8;

    // Сложение
    auto sum = mat1 + mat2;
    cout << "Sum:\n" << sum;

    // Прибавление
    mat1 += mat2;
    cout << "mat1 after +=:\n" << mat1;

    // Умножение матриц
    auto product = mat1 * mat2;
    cout << "Product:\n" << product;

    // Инкремент
    ++mat2;
    cout << "mat2 after ++:\n" << mat2;

    // Определитель
    cout << "Determinant mat1: " << mat1.determinant() << endl;

    return 0;
}
