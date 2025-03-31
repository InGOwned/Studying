#include <iostream>

class MyVector {
    int* m_arr;
    size_t m_size;
    size_t m_cap;

public:
    MyVector() : m_arr(nullptr), m_size(0), m_cap(0) {}

    MyVector(size_t size, int value) : m_size(size), m_cap(size) {
        m_arr = new int[m_cap];
        for (size_t i = 0; i < m_size; ++i) {
            m_arr[i] = value;
        }
    }

    ~MyVector() {
        delete[] m_arr;
    }

    void push_back(int value) {
        if (m_size >= m_cap) {
            size_t new_cap = m_cap == 0 ? 1 : m_cap * 2;

            int* new_arr = new int[new_cap];
            
            for (size_t i = 0; i < m_size; ++i) {
                new_arr[i] = m_arr[i];
            }
            
            delete[] m_arr;
            m_arr = new_arr;
            m_cap = new_cap;
        }
        m_arr[m_size++] = value;
    }

    void resize(size_t newSize, int value = 0) {
        if (newSize > m_size) {
            reserve(newSize);
            for (size_t i = m_size; i < newSize; ++i) {
                m_arr[i] = value;
            }
        }
        m_size = newSize;
    }

    void reserve(size_t new_cap) {
        if (new_cap <= m_cap) return;
        
        int* new_arr = new int[new_cap];
        for (size_t i = 0; i < m_size; ++i) {
            new_arr[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = new_arr;
        m_cap = new_cap;
    }

    void shrink_to_fit() {
        if (m_size == m_cap) return;
        
        int* new_arr = new int[m_size];
        for (size_t i = 0; i < m_size; ++i) {
            new_arr[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = new_arr;
        m_cap = m_size;
    }

    void insert(size_t index, int value) {
        if (index > m_size) throw std::out_of_range("Index out of range");
        
        push_back(value);
        for (size_t i = m_size - 1; i > index; --i) {
            m_arr[i] = m_arr[i - 1];
        }
        m_arr[index] = value;
    }

    void erase(size_t index) {
        if (index >= m_size) throw std::out_of_range("Index out of range");
        
        for (size_t i = index; i < m_size - 1; ++i) {
            m_arr[i] = m_arr[i + 1];
        }
        --m_size;
    }

    int& operator[](size_t index) {
        return m_arr[index];
    }

    const int& operator[](size_t index) const {
        return m_arr[index];
    }

    int& at(size_t index) {
        if (index >= m_size) throw std::out_of_range("Index out of range");
        return m_arr[index];
    }

    const int& at(size_t index) const {
        if (index >= m_size) throw std::out_of_range("Index out of range");
        return m_arr[index];
    }

    int& front() {
        return m_arr[0];
    }

    const int& front() const {
        return m_arr[0];
    }

    int& back() {
        return m_arr[m_size - 1];
    }

    const int& back() const {
        return m_arr[m_size - 1];
    }

    bool empty() const {
        return m_size == 0;
    }

    size_t size() const {
        return m_size;
    }

    size_t capacity() const {
        return m_cap;
    }

    MyVector(const MyVector&) = delete;
    MyVector& operator=(const MyVector&) = delete;
};

int main() {
    try {
        MyVector vec;
        
        for (int i = 0; i < 10; ++i) {
            vec.push_back(i);
            std::cout << "Added " << i << ": size=" << vec.size() 
                      << " capacity=" << vec.capacity() << std::endl;
        }

        vec.insert(5, 99);
        std::cout << "\nAfter insert at 5: ";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

        vec.erase(5);
        std::cout << "\nAfter erase at 5: ";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

        vec.resize(15, 42);
        std::cout << "\nResized to 15: size=" << vec.size() 
                  << " capacity=" << vec.capacity() << std::endl;

        vec.shrink_to_fit();
        std::cout << "Shrinked: size=" << vec.size() 
                  << " capacity=" << vec.capacity() << std::endl;

        std::cout << "\nFront: " << vec.front()
                  << " Back: " << vec.back()
                  << " At(5): " << vec.at(5) << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}