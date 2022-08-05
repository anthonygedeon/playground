#include <iostream>

int main() {
        // brace init
        //int width {5};
        //int height = { 6 };
        //int depth {};
        //int dim{4.5};
        //int dim_1(4.5);
        //int dim_2 = 4.5;

        
        int test { 0 }; // explicit 0 init
        int test_1 {}; // zero init
        std::cout << test_1 << std::endl;
        std::cout << test << std::endl;


        int a{}, b(1);
        
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        
        // assignment
        int var;
        var = 5;
        
        // initialization
        int var_1 = 5;

        return 0;
}
