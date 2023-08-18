#include <iostream>
#include <vector>
#include <algorithm>

// Custom Object
class Person {
public:
    std::string name;
    int age;

    Person(const std::string& n, int a) : name(n), age(a) {}
};

// Comparator function to sort Persons based on age in ascending order
bool sortByAgeAsc(const Person& a, const Person& b) {
    return a.age < b.age;
}

// Comparator function to sort Persons based on age in descending order
bool sortByAgeDesc(const Person& a, const Person& b) {
    return a.age > b.age;
}

int main() {
    // Create a vector of Person objects
    std::vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 40},
        {"David", 22},
        {"Eva", 35}
    };

    // Sort the vector of Person objects by age in ascending order
    std::sort(people.begin(), people.end(), sortByAgeAsc);

    // Print the sorted list
    std::cout << "Sorted by age in ascending order:" << std::endl;
    for (const auto& person : people) {
        std::cout << person.name << " - " << person.age << " years" << std::endl;
    }

    // Sort the vector of Person objects by age in descending order
    std::sort(people.begin(), people.end(), sortByAgeDesc);

    // Print the sorted list
    std::cout << "\nSorted by age in descending order:" << std::endl;
    for (const auto& person : people) {
        std::cout << person.name << " - " << person.age << " years" << std::endl;
    }

    return 0;
}
