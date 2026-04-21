#include<iostream>
using namespace std;

class WorkoutStrategy {
    public:
        virtual void performStrategy(int age, int weight) = 0;
};

class YogaStrategy: public WorkoutStrategy {
    public:
        YogaStrategy() {}
        void performStrategy(int age, int weight) {
            cout << "yoga workout done according to age " << age << " and weight " << weight << " kgs" << endl;
        }
};

class WeightTrainingStrategy: public WorkoutStrategy {
    public:
        WeightTrainingStrategy() {}
        void performStrategy(int age, int weight) {
            cout << "weight training workout done according to age " << age << " and weight " << weight << " kgs" << endl;
        }
};

class Workout {
    private:
        WorkoutStrategy* workoutStrategy;
        int age;
        int weight;
    public:
        Workout(int age, int weight) {
            this->workoutStrategy = nullptr;
            this->age = age;
            this->weight = weight;
        }
        void setWorkoutStrategy(WorkoutStrategy* workoutStrategy) {
            this->workoutStrategy = workoutStrategy;
        }
        void setAge(int age) {
            this->age = age;
        }
        void setWeight(int weight) {
            this->weight = weight;
        }
        void performWorkout() {
            this->workoutStrategy->performStrategy(age, weight);
        }
};

int main() {
    int age = 27;
    int weight = 75;
    Workout* workout = new Workout(27, 75);

    string mood = "yoga";

    if (mood == "yoga") {
        workout->setWorkoutStrategy(new YogaStrategy());
    } else {
        workout->setWorkoutStrategy(new WeightTrainingStrategy());
    }

    // yoga workout done according to age 27 and weight 75 kgs
    workout->performWorkout();

    workout->setWorkoutStrategy(new WeightTrainingStrategy());

    // weight training workout done according to age 27 and weight 75 kgs
    workout->performWorkout();

    workout->setAge(57);

    workout->setWorkoutStrategy(new YogaStrategy());

    // yoga workout done according to age 57 and weight 75 kgs
    workout->performWorkout();

    return 0;
}