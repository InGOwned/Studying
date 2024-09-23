### 1. Определение переменной

Переменная - это именованная область памяти, в которой хранятся данные определенного типа. Переменная позволяет хранить, изменять и использовать данные в программе.

### 2. Основные типы данных в C++

* Целочисленные типы:
    * Знаковые: int, short, long, long long
    * Беззнаковые: unsigned int, unsigned short, unsigned long, unsigned long long
* Вещественные типы: float, double, long double
* Символьные типы: char
* Логический тип: bool

### 3. Размеры типов данных в байтах

| Тип данных               | Размер (байты) |
|---------------------------|----------------|
| int                     | 4              |
| short                   | 2              |
| long                    | 4 или 8        |
| long long               | 8              |
| unsigned int            | 4              |
| unsigned short          | 2              |
| unsigned long           | 4 или 8        |
| unsigned long long      | 8              |
| float                   | 4              |
| double                  | 8              |
| long double             | 8 или 16       |
| char                    | 1              |
| bool                    | 1              |

### 4. Минимальные и максимальные значения типов данных

| Тип данных               | Мин. значение | Макс. значение |
|---------------------------|---------------|----------------|
| int                     | -2147483648   | 2147483647     |
| short                   | -32768        | 32767          |
| long                    | -2147483648   | 2147483647     |
| long long               | -9223372036854775808 | 9223372036854775807 |
| unsigned int            | 0             | 4294967295     |
| unsigned short          | 0             | 65535          |
| unsigned long           | 0             | 4294967295     |
| unsigned long long      | 0             | 18446744073709551615 |
| float                   | 1.17549e-38   | 3.40282e+38    |
| double                  | 2.22507e-308  | 1.79769e+308   |
| long double             | 3.3621e-4932  | 1.18973e+4932  |
| char                    | -128          | 127            |
| wchar_t                 | 0             | 65535          |
| char16_t                | 0             | 65535          |
| char32_t                | 0             | 4294967295     |
| bool                    | false         | true           |

[Помощь с типами](https://en.cppreference.com/w/cpp/language/types) <br>
[Шпаргалка по MD](https://github.com/sandino/Markdown-Cheatsheet/blob/master/README.md#images)
