#include <iostream>

// Converts light years to kilometers.
long lYearsToKM(int lightYears)
{
    return lightYears * 9460000000000;
}

// Converts light years to miles.
long lYearsToMiles(int lightYears)
{
    return lightYears * 5880000000000;
}

// Returns input (light years) over earth distance from sun.
long lYearsToEarthSunDistance(int lightYears)
{
    int earthDistanceFromSun{ 149600000 }; // kilometers
    return lYearsToKM(lightYears) / earthDistanceFromSun;
}

// Returns input (light years) over the distance
// that can be traveled by the fastest spacecraft
// in a single year.
int yearsToTravel(int lightYears)
{
    // https://www.guinnessworldrecords.com/world-records/66135-fastest-spacecraft-speed
    int ParkerTopSpeed{ 586800 }; // km/hour
    int parkerTopSpeed{ ParkerTopSpeed * 24 * 365 }; // km/year
    return lYearsToKM(lightYears) / ParkerTopSpeed;
}

int main()
{
    // Print application title.
    std::cout << "Light years converter." << std::endl;
    // Print application description.
    // In C/C++, sequences of literal strings get concatenated (joined) implicitly.
    // https://softwareengineering.stackexchange.com/questions/254984/on-concatenating-adjacent-string-literals
    std::cout << "In astronomy, a light year is the distance that light "
        "travels in a vacuum in one Julian year (365.25 days).\n";
        "This application converts light years to various units of length.\n";

    // Get user input
    int lightYears{};
    std::cout << "Please enter number of light years: ";
    std::cin >> lightYears;

    // Calculate and print result
    std::cout << lightYears << " light years(s) is approximately equivalent to:\n"
        << lYearsToKM(lightYears) << " Kilometers.\n"
        << lYearsToMiles(lightYears) << " Miles.\n"
        << lYearsToEarthSunDistance(lightYears)
        << " times the distance between the Earth and the Sun.\n";
        "-----------------------------------------------------\n";

    // Nice extra piece of information.
    std::cout << "By the fastest speed ever achieved by a spacecraft, "
        "it takes about " << yearsToTravel(lightYears) << " years to travel "
        << lightYears << " light year(s) through space." << std::endl;

    return 0;
}
