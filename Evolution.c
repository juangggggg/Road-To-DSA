
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POPULATION 10
#define LENGTH 8

// Generate a random individual
void initialize(char population[POPULATION][LENGTH + 1]) {

    for (int i = 0; i < POPULATION; i++) {
        for (int j = 0; j < LENGTH; j++) {
            population[i][j] = rand() % 2 + '0';
        }

        population[i][LENGTH] = '\0';
    }
}

// Calculate fitness
int fitness(char individual[]) {

    int score = 0;

    for (int i = 0; i < LENGTH; i++) {
        if (individual[i] == '1') {
            score++;
        }
    }

    return score;
}

// Select the best individual
int selectBest(char population[POPULATION][LENGTH + 1]) {

    int best = 0;

    for (int i = 1; i < POPULATION; i++) {
        if (fitness(population[i]) > fitness(population[best])) {
            best = i;
        }
    }

    return best;
}

// Mutation
void mutate(char individual[]) {

    int position = rand() % LENGTH;

    if (individual[position] == '0') {
        individual[position] = '1';
    } else {
        individual[position] = '0';
    }
}

int main() {

    srand(time(NULL));

    char population[POPULATION][LENGTH + 1];

    initialize(population);

    for (int generation = 1; generation <= 10000; generation++) {

        int best = selectBest(population);

        printf("Generation %d: %s | Fitness: %d\n",
                generation,
                population[best],
                fitness(population[best]));

        // Check if solution is found
        if (fitness(population[best]) == LENGTH) {
            printf("\nSolution Found: %s\n", population[best]);
            break;
        }

        // Keep the best individual
        char nextPopulation[POPULATION][LENGTH + 1];

        for (int i = 0; i < POPULATION; i++) {
            for (int j = 0; j <= LENGTH; j++) {
                nextPopulation[i][j] = population[best][j];
            }

            // Create variations
            if (i != 0) {
                mutate(nextPopulation[i]);
            }
        }

        // Replace old population
        for (int i = 0; i < POPULATION; i++) {
            for (int j = 0; j <= LENGTH; j++) {
                population[i][j] = nextPopulation[i][j];
            }
        }
    }

    return 0;
}
