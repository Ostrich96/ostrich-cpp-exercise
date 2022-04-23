#include<algorithm>

template<typename Object>
class myVector{
    public:
    /*
    constructor: the Capacity add a SPARE_CAPACITY inorder to be large than theSize
    */
        explicit myVector(int initSize = 0): theSize(initSize),theCapacity(initSize+ SPARE_CAPACITY)
        {
            objects = new Objects[ theCapacity]
        }
        // copy constuctor, objects(nullptr)
        myVector(const myVector& rhs):theSize(rhs.theSize),theCapacity(rhs.theCapacity),objects(nullptr){
            objects = new Object[theCapacity];
            for(int k = 0; k < theSize; k++){
                objects[k] = rhs.objects[k];
            }
        }
        // operator= using swap()
        myVector& operator=(const myVector& rhs){
            myVector copy = rhs;
            std::swap(*this, copy);
            return *this;
        }
        myVector& operator=(myVector && rhs){
            std::swap(theSize,rhs.theSize);
            std::swap(theCapacity,rhs.theCapacity);
            std::swap(objects , rhs.objects);

            return *this
        }
        
        // destructor
        ~myVector(){
            delete[] objects;
        }
        // moving constructor
        myVector(myVector&& rhs):theSize(theSize),theCapacity(theCapacity),objects(rhs.objects){=
            rhs.theSize = 0;
            rhs.objects = nullptr;
            rhs.theCapacity = 0;
        }



    private:
        int theSize;
        int theCapacity;
        Object* objects;
};