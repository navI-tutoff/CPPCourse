#include <numeric>
#include <cassert>
#include <iostream>
#include <valarray>
#include <vector>

struct Fraction {
public:
    Fraction() {
        _numerator = 0;
        _denominator = 1;
    }

    Fraction(const int &numerator, const int &denominator) {
        if (numerator == 0) {
            _numerator = 0;
            _denominator = 1;
        } else if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0) {
            _numerator = numerator < 0 ? numerator : -numerator;
            _denominator = std::abs(denominator);
        } else if (numerator < 0 && denominator < 0) {
            _numerator = -numerator;
            _denominator = -denominator;
        } else {
            _numerator = numerator;
            _denominator = denominator;
        }

        fractionReduction();
    }

    int getNumerator() {
        return _numerator;
    }

    int getDenominator() {
        return _denominator;
    }

    friend std::ostream &operator<<(std::ostream &out, const Fraction &fraction);

    friend std::istream &operator>>(std::istream &in, Fraction &fraction);

    Fraction operator+(const Fraction &other) const {
        Fraction res;
        int _lcm = std::lcm(_denominator, other._denominator);
        res._numerator = _numerator * (_lcm / _denominator) +
                         other._numerator * (_lcm / other._denominator);
        res._denominator = _lcm;

        res.fractionReduction();
        return res;
    }

//    Fraction operator-(const Fraction &other) const {
//        Fraction res;
//        int _lcm = std::lcm(_denominator, other._denominator);
//        res._numerator = _numerator * (_lcm / _denominator) - other._numerator * (_lcm / other._denominator);
//        res._denominator = _lcm;
//
//        res.fractionReduction();
//        return res;
//    }

    /// через плюс
    Fraction operator-(const Fraction &other) const {
        Fraction res;
        int _lcm = std::lcm(_denominator, other._denominator);
        res._numerator = _numerator * (_lcm / _denominator) + other._numerator * -1 * (_lcm / other._denominator);
        res._denominator = _lcm;

        res.fractionReduction();
        return res;
    }

    Fraction operator*(const Fraction &other) const {
        Fraction res;
        res._numerator = _numerator * other._numerator;
        res._denominator = _denominator * other._denominator;

        res.fractionReduction();
        return res;
    }

    Fraction operator/(const Fraction &other) const {
        Fraction res;
        res._numerator = _numerator * other._denominator;
        res._denominator = _denominator * other._numerator;

        res.fractionReduction();
        return res;
    }

private:
    int _numerator;
    int _denominator;

    void fractionReduction() {
        int _gcd = std::gcd(_numerator, _denominator);
        _numerator /= _gcd;
        _denominator /= _gcd;
    }
};

std::ostream &operator<<(std::ostream &out, const Fraction &fraction) {
    try {
        if (fraction._denominator == 0) {
            throw std::string("Denominator is zero!");
        }
        if (fraction._denominator == 1) {
            out << fraction._numerator;
        } else {
            out << fraction._numerator << '/' << fraction._denominator;
        }
    } catch (const std::string &s) {
        std::cerr << s;
    }
    return out;
}

std::istream &operator>>(std::istream &in, Fraction &fraction) {
    in >> fraction._numerator >> fraction._denominator;
    return in;
}

void test_fractionDefault() {
    Fraction fraction;
    assert(fraction.getNumerator() == 0);
    assert(fraction.getDenominator() == 1);
}

void test_fractionReduction() {
    Fraction fraction(2, 4);
    assert(fraction.getNumerator() == 1);
    assert(fraction.getDenominator() == 2);
}

void test_fractionIsNegative_numeratorIsNegative() {
    Fraction fraction(-4, 2);
    assert(fraction.getNumerator() == -2);
    assert(fraction.getDenominator() == 1);
}

void test_fractionIsNegative_denominatorIsNegative() {
    Fraction fraction(4, -2);
    assert(fraction.getNumerator() == -2);
    assert(fraction.getDenominator() == 1);
}

void test_fractionIsNegative() {
    test_fractionIsNegative_numeratorIsNegative();
    test_fractionIsNegative_denominatorIsNegative();
}

void test_fractionIsPositive_bothArePositive() {
    Fraction fraction(6, 3);
    assert(fraction.getNumerator() == 2);
    assert(fraction.getDenominator() == 1);
}

void test_fractionIsPositive_bothAreNegative() {
    Fraction fraction(-2, -3);
    assert(fraction.getNumerator() == 2);
    assert(fraction.getDenominator() == 3);
}

void test_fractionIsPositive() {
    test_fractionIsPositive_bothArePositive();
    test_fractionIsPositive_bothAreNegative();
}

void test_numeratorIsZero() {
    Fraction fraction(0, 42);
    assert(fraction.getDenominator() == 1);
}

void test_fractionStructure() {
    test_fractionDefault();
    test_fractionReduction();
    test_fractionIsNegative();
    test_fractionIsPositive();
    test_numeratorIsZero();
}

//     MATERIAL POINT

struct MaterialPoint {
public:
    explicit MaterialPoint(const double &speed = 0, const double &acceleration = 0) {
        _position = 0;
        _speed = speed;
        _acceleration = acceleration;
    }

    void setSpeed(const double &speed) {
        _speed = speed;
    }

    void setAcceleration(const double &acceleration) {
        _acceleration = acceleration;
    }

    double getPosition() const {
        return _position;
    }

    double getSpeed() const {
        return _speed;
    }

    double getAcceleration() const {
        return _acceleration;
    }

    void move(const int &duration) {
        if (_acceleration != 0) {
            _position = _speed * duration + (_acceleration * std::pow(duration, 2)) / 2;
            _speed += _acceleration * duration;
        } else {
            _position += _speed * duration;
        }
    }

private:
    double _position;
    double _speed;
    double _acceleration;
};

void test_materialPoint_constructor_allAreZero() {
    MaterialPoint point;
    assert(point.getPosition() == 0);
    assert(point.getSpeed() == 0);
    assert(point.getAcceleration() == 0);
}

void test_materialPoint_constructor_accelerationIsZero() {
    MaterialPoint point(2);
    assert(point.getPosition() == 0);
    assert(point.getSpeed() == 2);
    assert(point.getAcceleration() == 0);
}

void test_materialPoint_constructor_bothNotZero() {
    MaterialPoint point(2, 1);
    assert(point.getPosition() == 0);
    assert(point.getSpeed() == 2);
    assert(point.getAcceleration() == 1);
}

void test_materialPoint_constructor() {
    test_materialPoint_constructor_accelerationIsZero();
    test_materialPoint_constructor_allAreZero();
    test_materialPoint_constructor_bothNotZero();
}

void test_materialPoint_setSpeed() {
    MaterialPoint point(2);
    point.setSpeed(4);
    assert(point.getSpeed() == 4);
}

void test_materialPoint_setAcceleration() {
    MaterialPoint point(2, 3);
    point.setAcceleration(2);
    assert(point.getAcceleration() == 2);
}

void test_materialPoint_move() {
    MaterialPoint point(0, 0.9);
    point.move(7);
    assert(point.getSpeed() == 6.3);
    assert(point.getPosition() == 22.05);
}

void test_materialPoint() {
    test_materialPoint_constructor();
    test_materialPoint_setSpeed();
    test_materialPoint_setAcceleration();
    test_materialPoint_move();
}

///    BitSet

struct BitSet {
    BitSet() = default;

    explicit BitSet(int32_t maxValue) : _maxValue(maxValue), _values(0), _power(0) {
        if (maxValue > _MAX_VALUE_SUPPORTED)
            throw std::invalid_argument("maxValue can not be larger than MAX_VALUE_SUPPORTED");
    }

    explicit BitSet(const std::vector<int> &set) {
        for (const auto &x: set) {
            insert(x);
        }
    }

    bool empty() const {
        return _values == 0;
    }

    bool find(unsigned x) const {
        return _values >> x & 1;
    }

    void insert(unsigned x) {
        if (x > _MAX_VALUE_SUPPORTED) {
            throw std::invalid_argument("This value is larger than MAX_VALUE_SUPPORTED");
        }

        if (!find(x)) {
            _values |= 1 << x;
            _power++;
        }
    }

    void erase(uint32_t x) {
        if (x > _MAX_VALUE_SUPPORTED) {
            throw std::invalid_argument("This value even isn't exist");
        }

        if (find(x)) {
            _values &= ~(1 << x);
            _power--;
        }
    }

    bool operator==(BitSet &other) const {
        return _values == other._values;
    }

    bool operator!=(BitSet &other) const {
        return _values != other._values;
    }

    bool isSubset(const BitSet &subset) const {
        return _values == (subset._values & _values);
    }

    static bool isSubset(const BitSet &subset, const BitSet &set) {
        return (subset._values | set._values) == set._values;
    }

    static BitSet union_(const BitSet &lhs, const BitSet &rhs) {
        return BitSet(lhs._values | rhs._values);
    }

    static BitSet intersection_(const BitSet &lhs, const BitSet &rhs) {
        return BitSet(lhs._values & rhs._values);
    }

    static BitSet difference_(const BitSet &lhs, const BitSet &rhs) {
        return BitSet(lhs._values & ~rhs._values);
    }

    static BitSet symmetricDifference_(const BitSet &lhs, const BitSet &rhs) {
        return BitSet(lhs._values & ~rhs._values | rhs._values & ~lhs._values);
    }

    static BitSet complement_(const BitSet &set) {
        return BitSet(~set._values);
    }

    friend std::ostream &operator<<(std::ostream &out, const BitSet &set);

private:
    // максимальное поддерживаемое значение битсетом как таковым
    static const int _MAX_VALUE_SUPPORTED = 31;
    // максимальное поддерживаемое значение
    // для создаваемой структуры
    const int _maxValue = _MAX_VALUE_SUPPORTED;
    // поле для хранения значений
    uint32_t _values = 0;
    // мощность множества
    unsigned _power = 0;

    unsigned getPower() const {
        return _power;
    }

    explicit BitSet(const uint32_t &values) {
        _values = values;
        _power = getPower();
    }
};

std::ostream &operator<<(std::ostream &out, const BitSet &set) {
    out << '{';
    bool isEmpty = true;
    for (int i = 0; i <= set._maxValue; i++) {
        if (set.find(i)) {
            out << i << ", ";
            isEmpty = false;
        }
    }

    if (isEmpty) {
        std::cout << "}\n";
    } else {
        std::cout << "\b\b}\n";
    }

    return out;
}

///    TESTS BITSET

void test_BitSet_empty_isEmpty() {
    BitSet set;
    assert(set.empty() == 1);
}

void test_BitSet_empty_notEmpty() {
    BitSet set({1, 8});
    assert(set.empty() == 0);
}

void test_BitSet_empty() {
    test_BitSet_empty_isEmpty();
    test_BitSet_empty_notEmpty();
}

void test_BitSet_find_elementExist() {
    BitSet set({5, 6});
    assert(set.find(5) == 1);
}

void test_BitSet_find_elementAbsent() {
    BitSet set({4, 7});
    assert(set.find(5) == 0);
}

void test_BitSet_find() {
    test_BitSet_find_elementExist();
    test_BitSet_find_elementAbsent();
}

void test_BitSet_insert_test1() {
    BitSet set({4, 7});
    set.insert(1);
    BitSet awaitedSet({1, 4, 7});
    assert(set == awaitedSet);
}

void test_BitSet_insert_test2() {
    BitSet set;
    set.insert(24);
    set.insert(30);
    BitSet awaitedSet({24, 30});
    assert(set == awaitedSet);
}

void test_BitSet_insert() {
    test_BitSet_insert_test1();
    test_BitSet_insert_test2();
}

void test_BitSet_erase_test1() {
    BitSet set({1, 2, 3});
    set.erase(3);
    BitSet awaitedSet({1, 2,});
    assert(set == awaitedSet);
}

void test_BitSet_erase_test2() {
    BitSet set;
    set.insert(2);
    set.erase(2);
    BitSet awaitedSet;
    assert(set == awaitedSet);
}

void test_BitSet_erase() {
    test_BitSet_erase_test1();
    test_BitSet_erase_test2();
}

void test_BitSet_isSubset_true() {
    BitSet set({1, 2, 3, 4});
    BitSet subset({1, 4});
    assert(BitSet::isSubset(subset, set) == 1);
}

void test_BitSet_isSubset_false() {
    BitSet set({1, 2, 3});
    BitSet subset({1, 4});
    assert(BitSet::isSubset(subset, set) == 0);
}

void test_BitSet_isSubset() {
    test_BitSet_isSubset_true();
    test_BitSet_isSubset_false();
}

void test_BitSet_union() {
    BitSet set1({1, 2, 3});
    BitSet set2({3, 4, 5});
    BitSet gottenSet = BitSet::union_(set1, set2);
    BitSet awaitedSet({1, 2, 3, 4, 5});
    assert(awaitedSet == gottenSet);
}

void test_BitSet_intersection() {
    BitSet set1({1, 2, 3, 4});
    BitSet set2({3, 4, 5, 6});
    BitSet gottenSet = BitSet::intersection_(set1, set2);
    BitSet awaitedSet({3, 4});
    assert(awaitedSet == gottenSet);
}

void test_BitSet_difference() {
    BitSet set1({1, 2, 3, 4});
    BitSet set2({3, 4, 5, 6});
    BitSet gottenSet = BitSet::difference_(set1, set2);
    BitSet awaitedSet({1, 2});
    assert(awaitedSet == gottenSet);
}

void test_BitSet_symmetricDifference() {
    BitSet set1({1, 2, 3, 4});
    BitSet set2({3, 4, 5, 6});
    BitSet gottenSet = BitSet::symmetricDifference_(set1, set2);
    BitSet awaitedSet({1, 2, 5, 6});
    assert(awaitedSet == gottenSet);
}

void test_BitSet_complement() {
    std::vector<int> v1;
    for (int i = 0; i < 31; i++) {
        v1.push_back(i);
    }

    BitSet set(v1);
    BitSet complementSet = BitSet::complement_(set);
    BitSet awaitedComplementSet;
    awaitedComplementSet.insert(31);

    assert(awaitedComplementSet == complementSet);
}

void test_BitSet() {
    test_BitSet_empty();
    test_BitSet_find();
    test_BitSet_insert();
    test_BitSet_erase();
    test_BitSet_isSubset();
    test_BitSet_union();
    test_BitSet_intersection();
    test_BitSet_difference();
    test_BitSet_symmetricDifference();
    test_BitSet_complement();
}

///   PrefixSum

struct PrefixSum {
    PrefixSum(const int *a, size_t n) {
        prefixSum_.push_back(0);
        prefixSum_.push_back(a[0]);
        for (int i = 1; i < n; i++) {
            prefixSum_.push_back(a[i] + prefixSum_.back());
        }
    }

    explicit PrefixSum(const std::vector<int> &a) {
        prefixSum_.push_back(0);
        prefixSum_.push_back(a[0]);
        for (int i = 1; i < a.size(); i++) {
            prefixSum_.push_back(a[i] + prefixSum_.back());
        }
    }

    // возвращает сумму элементов от l до r, не включая r.
    // например, для массива 1, 3, 5
    // запрос getSum(0, 2) должен возвращать 1 + 3 = 4;
    long long getSum(int l, int r) const {
        return prefixSum_[r] - prefixSum_[l];
    }

    // данный запрос должен каким-то образом,
    // без хранения старого массива
    // обновлять префиксный массив так, как будто мы
    // заменили i-ый элемент старого массива на v
    void set(size_t i, int v) {
        long long necessaryEl = getSum(i, i + 1);
        long long difference = v - necessaryEl;
        for (size_t j = i + 1; j < prefixSum_.size(); j++) {
            prefixSum_[j] += difference;
        }
    }

    std::vector<int> getPrefixSum() {
        return prefixSum_;
    }

    friend std::ostream &operator<<(std::ostream &out, const PrefixSum &prefixSum);

private:
    std::vector<int> prefixSum_;
};

std::ostream &operator<<(std::ostream &out, const PrefixSum &prefixSum) {
    for (auto &x: prefixSum.prefixSum_) {
        out << x << ' ';
    }
    out << '\n';

    return out;
}

void test_PrefixSum_constructor() {
    PrefixSum array({1, 2, 3});
    std::vector<int> awaitedPrefSum{0, 1, 3, 6};

    assert(array.getPrefixSum() == awaitedPrefSum);
}

void test_PrefixSum_getSum() {
    PrefixSum array({5, 7, 2, 4});

    assert(array.getSum(0, 2) == 12);
}

void test_PrefixSum_set_test1() {
    PrefixSum array({4, 7, 8});
    array.set(0, 2);
    std::vector<int> awaitedPrefSum{0, 2, 9, 17};

    assert(array.getPrefixSum() == awaitedPrefSum);
}

void test_PrefixSum_set_test2() {
    PrefixSum array({4, 7, 8});
    array.set(2, -2);
    std::vector<int> awaitedPrefSum{0, 4, 11, 9};

    assert(array.getPrefixSum() == awaitedPrefSum);
}

void test_PrefixSum_set() {
    test_PrefixSum_set_test1();
    test_PrefixSum_set_test2();
}

void test_PrefixSum() {
    test_PrefixSum_constructor();
    test_PrefixSum_getSum();
    test_PrefixSum_set();
}

int main() {
    test_PrefixSum();

    return 0;
}