#ifndef HEL_POINTER_WRAPPER_HPP
#define HEL_POINTER_WRAPPER_HPP

#include <types.h>

namespace hel {
namespace common {

template <typename T>
class PointerWrapper {
public:
    //NOTE: Merged into nw4r::g3d::LightObj::LightObj()
    PointerWrapper() {
        mPointer = nullptr;
    }

    inline void set(T& ptr) {
        mPointer = &ptr;
    }

    //NOTE: Merged into nw4r::g3d::LightObj::LightObj()
    void unset() {
        mPointer = nullptr;
    }

    inline T& getRef() const {
        return *mPointer;
    }

    inline T* getPtr() {
        return mPointer;
    }

    bool wasSet() const {
        return mPointer != nullptr;
    }

    bool isEmpty() const {
        return mPointer == nullptr;
    }
    
    void operator=(const PointerWrapper<T>& pOther) {
        mPointer = pOther.mPointer;
    }

    bool operator!=(const PointerWrapper<T>& pOther) {
        return mPointer != pOther.mPointer;
    }

    inline T* operator->()
    {
        return getPtr();
    }

    inline T& operator*()
    {
        return getRef();
    }

private:
    /* 0x0 */ T* mPointer;
};

} // common
} // hel

#endif
