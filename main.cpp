
#include <iostream>
#define N_Max 1000

class BigInt {
    unsigned char m_value[1000];
    short m_size = 0;

    public:
    BigInt() = default;
    
    BigInt(const std::string& value) {
        size_t len = value.length();
        for(int i=0;i<len;i++)
            m_value[i] = value[len-i-1] - '0';
        for(int i=len;i<N_Max;i++) {
            m_value[i] = 0;
        }
        m_size = len;
    }

    BigInt& operator+=(const BigInt& other) {
    int carry = 0;
    int max_size = std::max(m_size, other.m_size);

    for (int i = 0; i < max_size || carry; ++i) {

        unsigned char a = (i < m_size) ? m_value[i] : 0;
        unsigned char b = (i < other.m_size) ? other.m_value[i] : 0;
        
        int sum = a + b + carry;
        carry = sum / 10;
        m_value[i] = sum % 10;

        if (i >= m_size)
            m_size = i + 1;

    }

    if (carry) {
        m_value[m_size] = carry;
        m_size++;
    }

    return *this;
}

    BigInt operator+(const BigInt& other){
        BigInt result(*this);
        result += other;    
        return result;
    }

    BigInt& operator*=(const BigInt& other) {
        BigInt result;
        result.m_size = m_size + other.m_size;
        for (int i = 0; i < result.m_size; ++i)
            result.m_value[i] = 0;

        for (int i = 0; i < m_size; ++i) {
            for (int j = 0; j < other.m_size; ++j) {
                result.m_value[i + j] += m_value[i] * other.m_value[j];
            }
        }
        int carry = 0;
        for (int i = 0; i < result.m_size; ++i) {
            int digit = result.m_value[i] + carry;
            result.m_value[i] = digit % 10;
            carry = digit / 10;
        }
        if (carry) {
            result.m_value[result.m_size] = carry;
            result.m_size++;
        }
        while (result.m_size > 1 && result.m_value[result.m_size - 1] == 0) {
            --result.m_size;
        }

        *this = result;
        return *this;
    }


    BigInt operator*(const BigInt& other) const {
        BigInt result(*this);
        result *= other;
        return result;
    }

    bool operator<(const BigInt& other) const {
        if (m_size < other.m_size)
            return true;
        if (m_size > other.m_size) {
            return false;

        for (int i = m_size - 1; i >= 0; --i) {
            if (m_value[i] < other.m_value[i])
                return true;
            if (m_value[i] > other.m_value[i])
                return false;
            }
            
            return false;
        }
    }

    bool operator>(const BigInt& other) const {
        return other < *this;
    }

    bool operator==(const BigInt& other) const {
        if (m_size != other.m_size) {
            return false;
        }
        for (int i = 0; i < m_size; ++i) {
            if (m_value[i] != other.m_value[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const BigInt& other) const {
        return !(*this == other);
    }


    friend std::ostream& operator<<(std::ostream& out, const BigInt& other);
};

std::istream& operator>>(std::istream& in, BigInt& other) { // Ввод
    std::string s;
    in >> s;
    other = BigInt(s);
    return in;
}

std::ostream& operator<<(std::ostream& out, const BigInt& other) { // Вывод
    for(int i=0; i<other.m_size; i++) {
        out << static_cast<short>(other.m_value[other.m_size - i - 1]);
    }
    return out;
}

int main() {
    BigInt x;
    std::cin >> x;
    BigInt y;
    std::cin >> y;

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    BigInt sum = x + y;
    std::cout << "x + y = " << sum << std::endl;

    BigInt product = x * y;
    std::cout << "x * y = " << product << std::endl;

    if (x < y) {
        std::cout << "x < y" << std::endl;
    }

    if (x > y) {
        std::cout << "x > y" << std::endl;
    }

    if (x == y) {
        std::cout << "x == y" << std::endl;
    } else {
        std::cout << "x != y" << std::endl;
    }

    x += y;
    std::cout << "x += y: x = " << x << std::endl;

    x *= y;
    std::cout << "x *= y: x = " << x << std::endl;

    return 0;
}