#include <iostream>
#include <utility>
#include <string>

template <typename T1, typename T2>
struct Pair {
    T1 first;
    T2 second;

    Pair(const T1 &a, const T2 &b) : first(a), second(b) {}
};

template <typename T1, typename T2>
Pair<T1, T2> make_pair(const T1 &a, const T2 &b) {
    return Pair<T1, T2>(a, b);
}

int main() {

   auto p = make_pair(10, std::string("Ten"));

   std::cout << "First " << p.first << std::endl;
   std::cout << "Second " << p.second << std::endl;

   return 0;
}