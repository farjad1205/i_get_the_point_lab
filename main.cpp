#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
    double x, y;

public:
    Point(double x_val = 0, double y_val = 0) : x(x_val), y(y_val) {}

    double operator-(const Point &other) const
    {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }

    bool operator==(const Point &other) const
    {
        return (x == other.x && y == other.y);
    }

    bool operator!=(const Point &other) const
    {
        return !(*this == other);
    }

    Point operator/(const Point &other) const
    {
        double midX = (x + other.x) / 2.0;
        double midY = (y + other.y) / 2.0;
        return Point(midX, midY);
    }

    Point operator*(double scalar) const
    {
        return Point(x * scalar, y * scalar);
    }

    friend Point operator*(double scalar, const Point &p)
    {
        return Point(p.x * scalar, p.y * scalar);
    }

    Point &operator++()
    {
        x++;
        return *this;
    }

    Point operator++(int)
    {
        Point temp = *this;
        y++;
        return temp;
    }

    Point &operator--()
    {
        x--;
        return *this;
    }

    Point operator--(int)
    {
        Point temp = *this;
        y--;
        return temp;
    }

    double &operator[](int index)
    {
        if (index == 0)
            return x;
        else if (index == 1)
            return y;
        else
            throw out_of_range("Index must be 0 or 1");
    }

    friend istream &operator>>(istream &in, Point &p)
    {
        in >> p.x >> p.y;
        return in;
    }

    friend ostream &operator<<(ostream &out, const Point &p)
    {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
};

int main()
{
    Point p1(3.2, 9.8);
    Point p2(5.5, -1.2);

    cout << "distance = " << p1 - p2 << endl;
    cout << "equal " << (p1 == p2) << endl;
    cout << "not equal " << (p1 != p2) << endl;
    cout << "midpoint = " << (p1 / p2) << endl;

    cout << "p1 * 2 = " << (p1 * 2) << endl;
    cout << "2 * p2 = " << (2 * p2) << endl;

    cout << "++p1 = " << ++p1 << endl;
    cout << "p1++ = " << p1++ << " (after: " << p1 << ")" << endl;
    cout << "--p1 = " << --p1 << endl;
    cout << "p1-- = " << p1-- << " (after: " << p1 << ")" << endl;

    cout << "p1[0] (x): " << p1[0] << ", p1[1] (y): " << p1[1] << endl;

    Point p3;
    cout << "Enter point (x y): ";
    cin >> p3;
    cout << "You entered: " << p3 << endl;

    return 0;
}
