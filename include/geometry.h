#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include <cmath>

template <class T> struct Vec2 {
    union {
        struct {T u, v;};
        struct {T x, y;};
        T raw[2];
    };

    // Default Constructor, set u and v to 0
    Vec2() : u(0), v(0) {}
    // Constructor with 2 parameters
    Vec2(T _u, T _v) : u(_u), v(_v) {}
    // Overload addition operator
    inline Vec2<T> operator +(const Vec2<T> &V) const { return Vec2<T>(u + V.u, v + V.v); }
    // Overload subtraction operator
    inline Vec2<T> operator -(const Vec2<T> &V) const { return Vec2<T>(u - V.u, v - V.v); }
    // Overload multiplication operator
    inline Vec2<T> operator *(double d) const { return Vec2<T>(u * d, v * d); }
    // Overload printing operator
    template <class > friend std::ostream& operator<<(std::ostream&s, Vec2<T>&v);
};

template <class T> struct Vec3 {
    union {
        struct {T x, y, z;};
        struct {T ivert, iuv, inorm;};
        T raw[3];
    };
    Vec3() : x(0), y(0), z(0) {}
    Vec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
    // Overload Addition Operation
    inline Vec3<T> operator +(const Vec3<T> &V) const { return Vec3<T>(x + V.x, y + V.y, z + V.z); }
    // Overload Subtraction Operation
    inline Vec3<T> operator -(const Vec3<T> &V) const { return Vec3<T>(x - V.x, y - V.y, z - V.z); }
    // Overload Multiplication Operation for Vector
    inline T operator *(const Vec3<T> &V) const { return x * V.x + y * V.y + z * V.z; }
    // Overload Multiplication Operation for Double
    inline Vec3<T> operator *(const double d) const { return Vec3<T>(x * d, y * d, z * d); }
    // Don't know what this function does yet
    inline Vec3<T> operator ^(const Vec3<T> &V) const { return Vec3<T>(y*V.z - z*V.y, z*V.x - x*V.z, x*V.y - y*V.x); }
    // Calculate the norm of the Vector
    double norm () const { return std::sqrt(x*x + y*y + z*z); }
    // Convert to vector with norm l
    Vec3<T> & normalize(T l=1) { *this = (*this)*(l/norm()); return *this; }
    // Overload Printing Operator
    template <class > friend std::ostream& operator<<(std::ostream& s, Vec3<T>& v);
};

typedef Vec2<double> Vec2f;
typedef Vec2<int> Vec2i;
typedef Vec3<double> Vec3f;
typedef Vec3<int> Vec3i;

template <class T> std::ostream& operator<<(std::ostream& s, Vec2<T>& v)
{
    s << "(" << v.x << ", " << v.y << ")\n";
    return s;
}

template <class T> std::ostream& operator<<(std::ostream& s, Vec3<T>& v)
{
    s << "(" << v.x << ", " << v.y << ", " << v.z << ")\n";
    return s;
}

#endif //__GEOMETRY_H__
