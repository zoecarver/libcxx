#include<compare>

int add (int a, int b) { return a + b; }

int main()
{
    int n = 2;
    auto f = std::bind_front(add, n);
    assert(f(3) == 5);
}