#include <iostream>
#include <string_view>


int main() {

        std::string_view ssv{"sdfj"};
        constexpr std::string_view sv{ssv};
         
        std::string s = static_cast<std::string>(sv); 

        return 0;
}
