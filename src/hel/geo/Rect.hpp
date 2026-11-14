#ifndef HEL_GEO_RECT_HPP
#define HEL_GEO_RECT_HPP

#include <hel/math/Vector2.hpp>

namespace hel { namespace geo {

class Rect {
public:
    Rect();
    Rect(float minY, float maxY, float minX, float maxX);
    Rect(const Rect& rOther);

    ~Rect(); // weak

    void set(float, float, float, float); // weak
    void trans(float x, float y);
    const math::Vector2 getCenter() const;
    float getWidth() const;
    float getHeight() const;
    bool isInclude(float x, float y) const;
    bool isIntersect(const Rect& rOther) const;
    void adjustAspectShrink(float arg1);
    void transInternal(const Rect& rOther);
    void margeUnion(const Rect& rOther);
private:
    float mMinY;
    float mMaxY;
    float mMinX;
    float mMaxX;
};

} // geo
} // hel
#endif
