#include <iostream>
#include <memory>
#include <iterator>
#include <string>
#include <sstream>

template <typename Type>
struct removeconst{
    typedef Type type;
};

template <typename Type>
struct removeconst<const Type>{
    typedef Type type;
};

template <typename InputIterator>
void uninit_copy(InputIterator _dst, InputIterator _begin, InputIterator _end){
    typedef typename std::iterator_traits<InputIterator>::value_type value_type;
    for(;_begin != _end; ++_begin, ++_dst){
        ::new (&*_dst) value_type(*_begin);
    }
}

std::string ver_string(int a, int b, int c) {
    std::ostringstream ss;
    ss << "compiler version: g++ " << a << '.' << b << '.' << c;
    return ss.str();
}

std::string true_cxx_ver =
#ifdef __clang__
    ver_string(__clang_major__, __clang_minor__, __clang_patchlevel__);
#else
    ver_string(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#endif

int main(){
    std::cout << true_cxx_ver << "\n";
    const int a = 100;
    removeconst<const int>::type b = 100;
    b = 300;
    std::cout << "a = " << a << ", b = " << b << "\n";

    std::allocator<int> alloc;
    const size_t n = 10;
    int* p1 = alloc.allocate(n);

    int* temp1 = p1;
    for(int i = 0; i < n; ++i){
        *temp1 = i*4367;
        ++temp1;
    }

    int* temp2 = p1;
    for(int i = 0; i < n; ++i){
        std::cout << *temp2 << " ";
        ++temp2;
    }
    std::cout << "\n";

    int* p2 = alloc.allocate(n);
    uninit_copy(p2, p1, p1+n);

    int* temp3 = p2;
    for(int i = 0; i < n; ++i){
        std::cout << *temp3 << " ";
        ++temp3;
    }
    std::cout << "\n";

    alloc.deallocate(p1, n);
    alloc.deallocate(p2, n);
}
