#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

template<typename T>
void PrintListResults(std::string label, std::vector<T> const& vec)
{
    std::cout << label << ":" << std::endl;
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }
}

int main() {
    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
    {
        std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
        // 1) de vector in 2 nieuwe vectoren te splitsen: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na

        for (std::string& s : colours) {
            std::transform(s.begin(), s.end(), s.begin(),
                [](unsigned char c) { return std::toupper(c); });
        }

        PrintListResults("Make strings uppercase", colours);
    }
    {
        std::vector<std::string> colours{"red", "green", "white", "blue", "orange", "green", "orange", "black", "purple"};
        // 2) alle elementen UPPERCASE te maken.
       
    }
    {
        std::vector<std::string> colours{"red", "green", "white", "blue", "orange", "green", "orange", "black", "purple"};
        // 3) alle dubbele te verwijderen
    }

    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
    {
        std::vector<double> numbers{10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635};
        // 1) alle negatieve elementen te verwijderen
        numbers.erase(
            remove_if(numbers.begin(), numbers.end(), [](double i) { return i < 0; }), 
            numbers.end()
        );

        PrintListResults("Remove negative results", numbers);
    }

    {
        std::vector<double> numbers{10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635};
        // 2) voor alle elementen te bepalen of ze even of oneven zijn
    }

    {
        std::vector<double> numbers{10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635};
        // 3) de som, het gemiddelde, en het product van alle getallen te berekenen
    }

    

    return 0;
}