template<T>
class sharePtr{

    sharePtr(){};
    ~sharePtr(){};

    //浅copy 智能指针的copy函数
    void sharePtr(const sharePtr<T> & cp){
        ptr=cp.ptr;
        use_count=cp.use_count;
        *(use_count)++;
        cout<<"ook"<<endl;
    }
    //浅copy，智能指针的赋值函数
    sharePtr<T> & opertor=(const sharePtr<T> &rhs){
        
        //先留住rhs，保证use_count大于0
        ++(*rhs.use_count);
        if(--(*use_count)==0){
            delete ptr;
            delete use_count;
            cout<<"delete left"<<endl;
        }

        ptr=rhs.ptr;
        use_count=rhs.use_count;

    }
    T* ptr;
    int *use_count;
};