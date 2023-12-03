#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>

template<typename T>
void PrintListResults(std::string label, std::vector<T> const& vec)
{
    std::cout << std::endl << label << ":" << std::endl;
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
        std::sort(colours.begin(), colours.end());
        
        // Create new vectors and assign the sizes 
        unsigned splitSize = std::count_if(colours.begin(), colours.end(), [](std::string s) { return s < "p"; });
        std::vector<std::string> colours1(splitSize), colours2(colours.size() - splitSize);

        std::partition_copy(colours.begin(), colours.end(), colours1.begin(), colours2.begin(), [](std::string s) { return s < "p"; });

        PrintListResults("Split vectors alphabetically part 1", colours1);
        PrintListResults("Split vectors alphabetically part 2", colours2);
    }
    {
        std::vector<std::string> colours{"red", "green", "white", "blue", "orange", "green", "orange", "black", "purple"};
        // 2) alle elementen UPPERCASE te maken.
       
        for (std::string& s : colours) {
            std::transform(s.begin(), s.end(), s.begin(),
                [](unsigned char c) { return std::toupper(c); });
        }

        PrintListResults("Make strings uppercase", colours);
    }
    {
        std::vector<std::string> colours{"red", "green", "white", "blue", "orange", "green", "orange", "black", "purple"};
        // 3) alle dubbele te verwijderen

        std::sort(colours.begin(), colours.end());
        colours.erase(std::unique(colours.begin(), colours.end()), colours.end());

        PrintListResults("Remove duplicate elements", colours);
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

        std::cout << std::endl << "Even or uneven:" << std::endl;
        // One line heel mooi :3
        std::for_each(numbers.begin(), numbers.end(), [](const double& n) { std::cout << n << ' ' << ((bool)((int)n % 2 == 0) ? "Even" : "Oneven") << std::endl; });
    }

    {
        std::vector<double> numbers{10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635};
        // 3) de som, het gemiddelde, en het product van alle getallen te berekenen

        double sum, avarage, product;

        sum = accumulate(numbers.begin(), numbers.end(), 0);
        avarage = sum / numbers.size();
        product = std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies<int>());

        std::cout << std::endl << "Sum, avarage and product:" << std::endl;
        std::cout << sum << std::endl;
        std::cout << avarage << std::endl;
        std::cout << product << std::endl;
    }

    return 0;  
}