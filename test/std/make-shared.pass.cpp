#include<memory>

struct A
{
    static int count;

    A() {++count;}
    A(const A&) {++count;}
    ~A() {--count;}
};

int A::count = 0;

int main()
{
    {
        using T = A[];
        std::shared_ptr<T> ptr0 = std::make_shared<T>(8);
        assert(A::count == 8);

        std::shared_ptr<T> ptr1 = std::allocate_shared<T>(std::allocator<T>(), 8);
        assert(A::count == 8);
    }
    assert(A::count == 0);

    {
        using T = A[8];
        std::shared_ptr<T> ptr0 = std::make_shared<T>();
        assert(A::count == 8);

        std::shared_ptr<T> ptr1 = std::allocate_shared<T>(std::allocator<T>());
        assert(A::count == 8);
    }
    assert(A::count == 0);

    {
        using T = int[];
        std::shared_ptr<T> ptr0 = std::make_shared<T>(8, 42);
        std::shared_ptr<T> ptr1 = std::allocate_shared<T>(std::allocator<T>(), 8, 42);

        for (unsigned i = 0; i < 8; ++i)
        {
            assert((*ptr0)[i] == 42);
            assert((*ptr1)[i] == 42);
        }
    }

    {
        using T = int[8];
        std::shared_ptr<T> ptr0 = std::make_shared<T>(42);
        std::shared_ptr<T> ptr1 = std::allocate_shared<T>(std::allocator<T>(), 42);

        for (unsigned i = 0; i < 8; ++i)
        {
            assert((*ptr0)[i] == 42);
            assert((*ptr1)[i] == 42);
        }
    }

    {
        using T = int[][2];
        std::shared_ptr<T> ptr0 = std::make_shared<T>(8, {4, 2});
        std::shared_ptr<T> ptr1 = std::allocate_shared<T>(std::allocator<T>(), 8, {4, 2});

        for (unsigned i = 0; i < 8; ++i)
        {
            assert((*ptr0)[i][0] == 4);
            assert((*ptr1)[i][0] == 4);
            assert((*ptr0)[i][1] == 2);
            assert((*ptr1)[i][1] == 2);
        }
    }

    {
        using T = int[8][2];
        std::shared_ptr<T> ptr0 = std::make_shared<T>({4, 2});
        std::shared_ptr<T> ptr1 = std::allocate_shared<T>(std::allocator<T>(), {4, 2});

        for (unsigned i = 0; i < 8; ++i)
        {
            assert((*ptr0)[i][0] == 4);
            assert((*ptr1)[i][0] == 4);
            assert((*ptr0)[i][1] == 2);
            assert((*ptr1)[i][1] == 2);
        }
    }
}