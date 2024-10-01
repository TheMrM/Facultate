#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXCHARLENGTH 30

struct Car
{
    char brand[MAXCHARLENGTH];
    char model[MAXCHARLENGTH];
    unsigned short int manufacturingYear;
    unsigned short int cityMpg;
    unsigned short int highwayMpg;
    double averageMpg;
};

bool check_string(const char str[])
{
    int length = strlen(str);

    if (length > MAXCHARLENGTH)
    {
        return false;
    }

    for (int i = 0; i < length; i++)
    {
        if (str[i] == ' ')
        {
            return true;
        }
    }
    return false;
}

void readCar(FILE *f, struct Car *car)
{
    // Assuming the manufacturingYear, cityMpg, highwayMpg are all unsigned short
    // and the format in the file matches "Brand Model Year CityMPG HighwayMPG"
    if (fscanf(f, "%s %s %hu %hu %hu", car->brand, car->model, &car->manufacturingYear, &car->cityMpg, &car->highwayMpg) == 5)
    {
        car->averageMpg = (car->cityMpg + car->highwayMpg) / 2.0;
    }
}

void printCar(FILE *f, struct Car car)
{
    fprintf(f, "%s %s %hu %hu %hu Average MPG: %.2f\n", car.brand, car.model, car.manufacturingYear, car.cityMpg, car.highwayMpg, car.averageMpg);
}

struct Car maxMpg(struct Car m1, struct Car m2, struct Car m3)
{
    struct Car maximumAverageMpg = m1;
    if (m2.averageMpg > maximumAverageMpg.averageMpg)
    {
        maximumAverageMpg = m2;
    }
    if (m3.averageMpg > maximumAverageMpg.averageMpg)
    {
        maximumAverageMpg = m3;
    }
    return maximumAverageMpg;
}

int main()
{
    FILE *fin = fopen("car.in", "r");
    if (!fin)
    {
        fprintf(stderr, "fopen failed in file %s!\n", __FILE__);
        exit(EXIT_FAILURE);
    }

    struct Car m1, m2, m3;

    readCar(fin, &m1);
    readCar(fin, &m2);
    readCar(fin, &m3);

    fclose(fin);

    struct Car maximumAverageMpg = maxMpg(m1, m2, m3);

    FILE *fout = fopen("Car.out", "w");
    if (!fout)
    {
        fprintf(stderr, "fopen failed in file %s!\n", __FILE__);
        exit(EXIT_FAILURE);
    }

    printCar(fout, m1);
    printCar(fout, m2);
    printCar(fout, m3);

    fprintf(fout, "Car with the highest average MPG is: %s %s\n", maximumAverageMpg.brand, maximumAverageMpg.model);

    fclose(fout);
    return 0;
}