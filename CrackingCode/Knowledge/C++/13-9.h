#include <iostream>

using namespace std;

template <typename T>
class SmartPointer{
private:
  T *ref;
  unsigned int *refCount;
public:
  SmartPointer(T *ref) :
  ref(ref)
  {
    refCount = new unsigned int(1);
  }
  SmartPointer(SmartPointer<T> &sp) {
    ref = sp.ref;
    refCount = sp.refCount;
    (*refCount)++;
  }
  SmartPointer<T> & operator=(const SmartPointer<T> &sp) {
    if (this != &sp) {
      ref = sp.ref;
      refCount = sp.refCount;
      (*refCount)++;
    }
    return *this;
  }
  void reset() {
    (*refCount)--;
    if (*refCount == 0){
      delete ref;
      delete refCount;
      ref = nullptr;
      refCount = nullptr;
    }
  }

 /* ~SmartPointer(){
    if (refCount != nullptr) {
      (*refCount)--;
      if(*refCount == 0 && ref != nullptr){
        delete ref;
      }
    }
    if (refCount != nullptr)
      delete refCount;
  }*/
  T* getRef() const{
    return ref;
  }
  int getRefCount() const {
    return *refCount;
  }
};
