#include<__smart_ptr>
#include<iostream>

static int deleters_called = 0;
static int count = 42;

struct Foo
{
    int val = count++;
    ~Foo() {
        val = -1;
        deleters_called++;
    }
};

void
test()
{
    std::__smart::shared_ptr<Foo> sp(new Foo());
    std::__smart::shared_ptr<Foo> sp1(sp);
    assert((*sp1).val == 42);
    assert((*sp).val == 42);
}

int main()
{
    test();

    assert(deleters_called == 1);
}