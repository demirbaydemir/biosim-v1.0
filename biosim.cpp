#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// Define constants for trait ranges and thresholds
int NUM_GENERATIONS = 5;
int ORGANISM_COUNT = 50;
int TRAIT_COUNT = 3;

const double minSize = 1.0;
const double maxSize = 10.0;
const double minSpeed = 1.0;
const double maxSpeed = 10.0;
const double minReproductionRate = 0.1;
const double maxReproductionRate = 1.0;
const double minthresholdSpeed = 3.0;
const double maxthresholdSpeed = 12.0;
const double minthresholdSize = 3.0;
const double maxthresholdSize = 7.0;
const double thresholdRepoduction = 0.842;
const double minMutation = -3.01;
const double maxMutation = 3.01;

const int NUM_GENES = TRAIT_COUNT;  // Number of genes in an organism's genome. Each gene effects 1 trait.
const double minTraitValue = 1.0;
const double maxTraitValue = 10.0;

// Function to generate random values within a range
double getRandomValueInRange(double min, double max) {
    return min + static_cast<double>(rand()) / RAND_MAX * (max - min);
}

// Function to get a random mutation value within a range
double getRandomMutationValue(double min, double max) {
    return getRandomValueInRange(min, max);
}

// Organism class
class Organism {
public:
    vector<double> genome;
    double size;
    double speed;
    double reproductionRate;

    Organism() {
        for (int i = 0; i < NUM_GENES; i++)
        {
            genome.push_back(getRandomValueInRange(minTraitValue, maxTraitValue));
        }
        size = getRandomValueInRange(minSize, maxSize);
        speed = getRandomValueInRange(minSpeed, maxSpeed);
        reproductionRate = getRandomValueInRange(minReproductionRate, maxReproductionRate);
    }

    void mutate() {
        // int randomGeneIndex = getRandomValueInRange(0, genome.size() - 1);
        genome[0] += getRandomMutationValue(minMutation, maxMutation);
        genome[1] += getRandomMutationValue(minMutation, maxMutation);    
        genome[2] += getRandomMutationValue(minMutation, maxMutation);    


        size *= (genome[0] / 10);
        speed *= (genome[1] / 10);
        reproductionRate *= (genome[2] / 10);
        // Mutating each trait one by one

        // size += getRandomMutationValue(minMutation, maxMutation);

        // Implement similar mutations for other traits...
    }

    Organism reproduce() {
        Organism offspring;
        offspring.size = this->size;
        offspring.speed = this->speed;
        offspring.reproductionRate = this->reproductionRate;
        offspring.genome = this->genome;
        offspring.mutate();
        return offspring;
    }
};

// Population class
class Population {
public:
    vector<Organism> organisms;

    void initializePopulation(int size) {
        for (int i = 0; i < size; ++i) {
            Organism newOrganism;
            organisms.push_back(newOrganism);
        }
    }

    void naturalSelection() {
        for (int i = 0; i < organisms.size(); ++i) {
            if (organisms[i].speed < minthresholdSpeed || organisms[i].speed > maxthresholdSpeed || organisms[i].size > maxthresholdSize || organisms[i].size < minthresholdSize) {
                organisms.erase(organisms.begin() + i); // Erase the i'th organism
                organisms.shrink_to_fit();
                --i; // When you erase from vector, elements shifts
            }
        }
        // Implement reproduction of fitter organisms...
        // Only depends on speed for now
    }

    // Other methods for managing the population...
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed for random number generation

    Population population;
    population.initializePopulation(ORGANISM_COUNT); // Initialize population 
    cout << "Population initialized succesfully.\n";

    // Simulate evolution over multiple generations
    for (int generation = 0; generation < NUM_GENERATIONS; ++generation) {
        // Implement evolution steps: natural selection, reproduction, etc.
        for (int i = 0; i < population.organisms.size(); i++)
        {  
            if (population.organisms[i].reproductionRate > thresholdRepoduction)
            {
                population.organisms.push_back(population.organisms[i].reproduce());
            }
        }
        population.naturalSelection();
        // Implement reproduction of fitter organisms...
    }

    cout << "Printing the results...\n";

    // Output final population statistics, visualize, etc.
    for (int i = 0; i < population.organisms.size(); ++i) {
        cout << "Organism " << i + 1 << " Traits: " << endl;
        cout << "Size: " << population.organisms[i].size << endl;
        cout << "Speed: " << population.organisms[i].speed << endl;
        cout << "Reproduction Rate: " << population.organisms[i].reproductionRate << endl;
        cout << "Genome: ";
        for (int j = 0; j < NUM_GENES; ++j) {
            cout << population.organisms[i].genome[j] << " ";
        }
        cout << endl << "-----------------------------" << endl;
    }

    // cout << "Population size: " << population.organisms.size() << endl; 

    return 0;
}
