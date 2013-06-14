#ifndef _Vector2f_Vector2f_h_
#define _Vector2f_Vector2f_h_

class Vector2f {
    public:
        float x;
        float y;

        Vector2f() : x{0}, y{0} {};
        Vector2f(float const& _x, float const& _y) : x{_x}, y{_y} {};
        Vector2f(float const& _x, float const& _y, bool const& isUnit) : x{_x}, y{_y} { if(isUnit) toUnit(); };
        Vector2f(Vector2f const& v, bool const& isUnit) : x{v.x}, y{v.y} { if(isUnit) toUnit(); };
        
      /*Vector2f(Vector2f const& v) : x{v.x}, y{v.y} {};
        ~Vector2f() {};

        Vector2f& operator=(Vector2f const& other);

        friend void swap(Vector2f& first, Vector2f& second);
        Vector2f(Vector2f&& v) { swap(*this, v); };*/
        

        float getMagnitudeSquared() const;
        float getMagnitude() const;

        Vector2f& toUnit();
        Vector2f  getUnit() const { Vector2f v(*this); return v.toUnit(); };

        Vector2f& toRightNormal();
        Vector2f& toLeftNormal();
        Vector2f  getRightNormal() const { Vector2f v(*this); return v.toRightNormal(); };
        Vector2f  getLeftNormal()  const { Vector2f v(*this); return v.toLeftNormal();  };

        Vector2f& toNormal() { return toRightNormal();  };
        Vector2f getNormal() const { return getRightNormal(); };

        Vector2f& toUnitNormal() { toNormal(); return toUnit(); };
        Vector2f getUnitNormal() const { auto v = getNormal(); return v.toUnit(); };

        float   dotProduct(Vector2f const& v) const;
        float crossProduct(Vector2f const& v) const; // right-handed cross product

        Vector2f& operator+=(Vector2f const& v); // vector addition
        Vector2f& operator-=(Vector2f const& v);
        Vector2f& operator*=(float const& s); // scalar multiplication 

        float operator*(Vector2f const& v) const { return dotProduct(v); };
        float operator^(Vector2f const& v) const { return crossProduct(v); };

            float& operator[](int const& idx);
            float  operator[](int const& idx) const;
   /* float const& operator[](int const& idx) const { return operator[](idx); }; */ 

        Vector2f operator-() const { return Vector2f(-x, -y); }; // negation

        friend Vector2f operator+(Vector2f lhs, Vector2f const& rhs) { lhs += rhs; return lhs; };
        friend Vector2f operator-(Vector2f lhs, Vector2f const& rhs) { lhs -= rhs; return lhs; };
        friend Vector2f operator*(float const& lhs, Vector2f rhs) { rhs *= lhs; return rhs; };
        friend Vector2f operator*(Vector2f lhs, float const& rhs) { lhs *= rhs; return lhs; };
};

#endif
