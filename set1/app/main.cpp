#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

std::vector<unsigned int> countRandomFrequencies(
    unsigned int count,
    const std::vector<unsigned int>& weights)
{
    std::vector<unsigned int> frequencies(std::accumulate(weights.begin(), weights.end(), 0), 0); // sets zeros
    
    // sets up random device and engin
    std::random_device device;
    std::default_random_engine engine{device()};
    // sets up uniform destribution 
    std::uniform_int_distribution<unsigned int> dist{0, static_cast<unsigned int>(std::accumulate(weights.begin(), weights.end(),0)) - 1};

    for (std::size_t i = 0; i < count; i++)
    {
        int currentRandomNum = dist(engine);
        // determine to which the number should be added
        frequencies.at(currentRandomNum)++;
        
    }
    
    std::vector<unsigned int> weighted_frequencies(weights.size(), 0);
    std::size_t indexCounter = 0;
    for (std::size_t i = 0; i < weights.size(); i++)
    {
        for (std::size_t j = 0; j < weights.at(i); j++)
        {
            weighted_frequencies[i] += frequencies[indexCounter];
            indexCounter++;
        }
    }

    return weighted_frequencies;
    
}


int main()
{
    std::vector<unsigned int> weights{1, 2, 1, 2, 1, 2};
    std::vector<unsigned int> frequencies = countRandomFrequencies(999999, weights);
    std::for_each(frequencies.begin(), frequencies.end(), [](unsigned int i){std::cout << i/10000 << std::endl;});
    
    return 0;
}

