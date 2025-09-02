#include <stdio.h>
#include <math.h>

// Car structure definition
struct Car {
    char make[20];
    char model[20];
    int year;
    int speed;
    int x;
    int y;
    int z;
};

// Function to accelerate the car
void accelerate(struct Car *car, int speed_increment) {
    car->speed += speed_increment;
}

// Function to brake the car
void brake(struct Car *car, int speed_decrement) {
    car->speed -= speed_decrement;
}

// Function to move the car
void move(struct Car *car) {
    double radians = M_PI / 180 * car->speed; // Convert speed to radians for direction
    car->x += (int)(cos(radians) + 0.5); // Round to nearest integer
    car->y += (int)(sin(radians) + 0.5); // Round to nearest integer
    car->z += (int)(sin(radians) + 0.5); // Round to nearest integer
}

// Function to detect collision between two cars
int detect_collision(struct Car *car1, struct Car *car2) {
    int distance = sqrt(pow(car1->x - car2->x, 2) + pow(car1->y - car2->y, 2) + pow(car1->z - car2->z, 2));
    if (distance < 1) { // Assuming collision occurs when distance is less than 1 unit
        return 1; // Collision detected
    }
    else {
        return 0; // Collision not detected
    }
}

// Function to calculate time to collision between two cars
double time_to_collision(struct Car *car1, struct Car *car2) {
    int distance = sqrt(pow(car1->x - car2->x, 2) + pow(car1->y - car2->y, 2) + pow(car1->z - car2->z, 2));
    double time = (double)distance / car1->speed; // Assuming both cars maintain constant speed
    return time;
}

int main() {
    // Test with dummy data
    struct Car car1 = {"Hyundai", "Creta", 2021, 60, 0, 0, 0};
    struct Car car2 = {"Maruti", "Alto", 2019, 40, 10, 10, 10};

    printf("Initial positions:\n");
    printf("Car 1: x = %d, y = %d, z = %d\n", car1.x, car1.y, car1.z);
    printf("Car 2: x = %d, y = %d, z = %d\n", car2.x, car2.y, car2.z);

    printf("Detect collision: %d\n", detect_collision(&car1, &car2));
    printf("Time to collision: %lf\n", time_to_collision(&car1, &car2));

    accelerate(&car1, 20);
    brake(&car2, 10);

    move(&car1);
    move(&car2);

    printf("New positions after movement:\n");
    printf("Car 1: x = %d, y = %d, z = %d\n", car1.x, car1.y, car1.z);
    printf("Car 2: x = %d, y = %d, z = %d\n", car2.x, car2.y, car2.z);
    printf("Detect collision: %d\n", detect_collision(&car1, &car2));
    printf("Time to collision: %f\n", time_to_collision(&car1, &car2));

    return 0;
}
