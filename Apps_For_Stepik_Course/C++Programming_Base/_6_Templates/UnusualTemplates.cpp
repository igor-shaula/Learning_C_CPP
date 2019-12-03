/* template parameters can be:
 * types,
 * int values, - must be defined during compilation time
 * pointers or references with external linking,
 * other templates
 */

#include <cstddef>

// sample of using integer values as parameters - matrix multiplication:
template<class T, size_t N, size_t M>
struct Matrix {
    // ...
    T &operator()(size_t i, size_t j) { return data_[M * j + i]; }
private:
    T data_[N * M];
};
// as we know - only matrix with equal dimensions can be multiplied - so we define this rule by setting types (M)
template<class T, size_t N, size_t M, size_t K>
Matrix<T, N, K> operator*(Matrix<T, N, M> const &a, Matrix<T, M, K> const &b);

int main() {
    return 0;
}