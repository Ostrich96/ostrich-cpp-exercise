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
        // increase capacity
        void reserve(int newCapacity){
            //if newCapacity is smaller than current size, return;
            if(newCapacity < theSize){
                return;
            }
            Object *newArray = new Object[newCapacity];//creat new array
            for(int i = 0; i < theSize; i++){
                newArray[k] = std::move(objects[k]); //move rvalue
            }
            theCapacity = newCapacity;
            std::swap(objects,newArray);// swap the pointer
            delete[]newArray;
        }
        void resize(int newSize){
            if(newSize > theCapacity){
                reserve(newSize*2)//keep the capacity twice as much as the size
            }
            theSize = newSize;
        }
        Object &operator [](int index){
            return objects[index];
        }
        const Object & operator[](int index)const{// first const: return value is const; second const: not able to change objects;
            return objects[index];
        }

        bool empty()const{
            return theSize == 0;
        }
        void push_back(const Object & x){
            if(theSize == theCapacity){
                reserve(theCapacity*2+1);
            }
            objects[theSize++] = x;
        }
        void push_back(Object && x){
            if(theSize == theCapacity){
                reserve(theCapacity*2+1);
            }
            objects[theSize++] = std::move(x);
        }
        void pop_back(){
            --theSize;
        }
        const Object & back()const{
            return objects[theSize-1];
        }
        typedef Object* iterator;
        typedef const Object* const_iterator;

        iterator begin(){
            return &objects[0];
        }
        const_iterator begin()const{
            return &objects[0];
        }
        iterator end(){
            return &objects[theSize];
        }
        const_iterator end()const {
            return &objects[theSize];
        }
        static const int SPARE_CAPACITY = 16;

    private:
        int theSize;
        int theCapacity;
        Object* objects;
};