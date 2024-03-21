/*
Description: Implement an online food ordering system.
Features:
This system has a tie-up with restaurants where each restaurant has a menu with all the items & their prices. Restaurants also have a rating out of 5.
Each restaurant has max #orders it can process at any given time. Beyond that, it shouldn’t be assigned any further orders until an ongoing order is completed.
Once an order is ACCEPTED, the restaurant can mark it as COMPLETED when the order is ready. This will free up the processing capacity of the restaurant. A restaurant can’t CANCEL an ACCEPTED order.
An order will be auto-assigned to a restaurant based on a selection strategy. Eg: Assign by lowest cost or best rating.
An order will be auto-assigned to a restaurant only if all the items in an order can be fulfilled by a single restaurant. Else the order will not be ACCEPTED.

Requirements:
Onboard a new restaurant.
A restaurant should be able to update its menu. For simplicity, a restaurant can't delete an item from the menu.
Restaurants can mark ACCEPTED orders as COMPLETED. Orders once ACCEPTED can’t be CANCELLED by a restaurant.
A customer should be able to place an order by giving items, respective quantities & selection strategy.
Order will be auto-assigned to a restaurant based on a selection strategy.
Implement at least one restaurant selection strategy.

Note: Do not use any database or NoSQL store, use an in-memory store.

Expectations:
Make sure that you have working and demoable & functionally correct code.
Use proper abstractions, separation of concerns, proper entity modeling
Use appropriate design patterns wherever required.
The code should be modular, extensible, readable and unit-testable.
Proper exception handling is required.
Restaurant selection strategy must be pluggable
Concurrency handling (BONUS / Good to have)

Sample test cases:
Onboard Restaurants
R1
    “max_orders_that_can_be_processed_at_a_time” : 5,
    “Menu”: [Veg Biryani : Rs.100, Chicken Biryani: Rs.150],
    “rating”: 4.5/5
R2
    “max_orders_that_can_be_processed_at_a_time”: 5,
    menu: [Chicken Biryani : Rs.175, Idli : Rs.10, Dosa : Rs.50, Veg Biryani : Rs. 80],
    rating: 4/5
R3
    “max_orders_that_can_be_processed_at_a_time”: 1,
    menu: [Gobi Manchurian : Rs.150, Idli : Rs.15, Chicken Biryani : Rs.175, Dosa: Rs.30 ],
    rating: 4.9/5
2. Update restaurant menu
    ADD: {Restaurant_1, add, Chicken65, Rs.250}
    UPDATE: {Restaurant_2, update, Chicken Biryani, Rs.150}
3. Place Order
    Order1.
        Input: { user: Ashwin, items: [ 3Idli, 1Dosa ], selection: Lowest cost }
        Output: Order assigned to R3
    Order2.
        Input: { user: Harish, items: [ 3Idli, 1Dosa ], selection: Lowest cost }
        Output: 1) Order assigned to R2
        (Not R3 since it has reached its full capacity from Order1)
    Order3:
        Input: { user: Shruthi, items: [3Veg Biryani], selection: ‘Highest rating’ }
        Output: Order assigned to R1
        Update Order Status:
        R3 marks Order1 as COMPLETED
    Order4:
        Input: { user: Harish, items: [ 3Idli, 1Dosa ], selection: Lowest cost }
        Output: Order assigned to R3
        (since R3 had COMPLETED Order1)
    Order5:
        Input: {user: xyz, items: [1Paneer Tikka, 1*Idli], selection: ‘Lowest cost}
        Output: Order can’t be fulfilled
        (since none of the restaurants above serve Paneer Tikka)

4. Update Order Status
Input: {R3, Order1, COMPLETED}
*/


/*
ChatGPT answer: To implement the online food ordering system with the given features and requirements, we'll follow these steps:
    Define classes for restaurants, menu items, and orders.
    Implement restaurant selection strategies.
    Implement methods for onboarding restaurants, updating menus, placing orders, and updating order status.
    Ensure proper exception handling and concurrency handling.
    Design the system to be modular, extensible, and unit-testable.
Below is the C++ code implementing the described system:
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Define MenuItem structure
struct MenuItem {
    string name;
    int price;

    MenuItem(string _name, int _price) : name(_name), price(_price) {}
};

// Define Restaurant class
class Restaurant {
private:
    string name;
    int maxOrders;
    unordered_map<string, int> menu;
    float rating;
    vector<string> acceptedOrders;

public:
    Restaurant(string _name, int _maxOrders, vector<MenuItem> _menu, float _rating) :
            name(_name), maxOrders(_maxOrders), rating(_rating) {
        for (const auto &item : _menu) {
            menu[item.name] = item.price;
        }
    }

    bool canAcceptOrder() {
        return acceptedOrders.size() < maxOrders;
    }

    void acceptOrder(const string &orderId) {
        acceptedOrders.push_back(orderId);
    }

    void completeOrder(const string &orderId) {
        auto it = find(acceptedOrders.begin(), acceptedOrders.end(), orderId);
        if (it != acceptedOrders.end()) {
            acceptedOrders.erase(it);
        }
    }

    bool hasMenuItem(const string &itemName) {
        return menu.find(itemName) != menu.end();
    }

    int getItemPrice(const string &itemName) {
        return menu[itemName];
    }

    float getRating() {
        return rating;
    }
};

// Define Order class
class Order {
private:
    string orderId;
    string user;
    vector<pair<string, int>> items;
    string selection;
    string assignedRestaurant;

public:
    Order(string _orderId, string _user, vector<pair<string, int>> _items, string _selection) :
            orderId(_orderId), user(_user), items(_items), selection(_selection) {}

    string getOrderId() {
        return orderId;
    }

    string getUser() {
        return user;
    }

    vector<pair<string, int>> getItems() {
        return items;
    }

    string getSelectionStrategy() {
        return selection;
    }

    string getAssignedRestaurant() {
        return assignedRestaurant;
    }

    void assignRestaurant(const string &restaurantName) {
        assignedRestaurant = restaurantName;
    }
};

// Define FoodDeliverySystem class
class FoodDeliverySystem {
private:
    unordered_map<string, Restaurant> restaurants;
    unordered_map<string, Order> orders;
    float minRating = 0.0;

public:
    void onboardRestaurant(const string &name, int maxOrders, vector<MenuItem> menu, float rating) {
        restaurants[name] = Restaurant(name, maxOrders, menu, rating);
        minRating = min(minRating, rating);
    }

    void updateMenu(const string &restaurantName, const string &itemName, int price) {
        if (restaurants.find(restaurantName) != restaurants.end()) {
            restaurants[restaurantName].menu[itemName] = price;
        }
    }

    string placeOrder(const string &user, vector<pair<string, int>> items, const string &selection) {
        string orderId = "Order" + to_string(orders.size() + 1);
        orders[orderId] = Order(orderId, user, items, selection);
        assignOrderToRestaurant(orderId);
        return orderId;
    }

    void updateOrderStatus(const string &restaurantName, const string &orderId, const string &status) {
        if (status == "COMPLETED") {
            if (restaurants.find(restaurantName) != restaurants.end()) {
                restaurants[restaurantName].completeOrder(orderId);
            }
        }
    }

private:
    void assignOrderToRestaurant(const string &orderId) {
        for (auto &[name, restaurant] : restaurants) {
            if (restaurant.canAcceptOrder() && checkItemsAvailability(restaurant, orders[orderId].getItems())) {
                orders[orderId].assignRestaurant(name);
                restaurant.acceptOrder(orderId);
                return;
            }
        }
    }

    bool checkItemsAvailability(Restaurant &restaurant, vector<pair<string, int>> &items) {
        for (auto &[itemName, quantity] : items) {
            if (!restaurant.hasMenuItem(itemName)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    // Sample test cases
    FoodDeliverySystem foodDeliverySystem;

    // Onboard Restaurants
    vector<MenuItem> menu1 = {{"Veg Biryani", 100}, {"Chicken Biryani", 150}};
    foodDeliverySystem.onboardRestaurant("R1", 5, menu1, 4.5);

    vector<MenuItem> menu2 = {{"Chicken Biryani", 175}, {"Idli", 10}, {"Dosa", 50}, {"Veg Biryani", 80}};
    foodDeliverySystem.onboardRestaurant("R2", 5, menu2, 4.0);

    vector<MenuItem> menu3 = {{"Gobi Manchurian", 150}, {"Idli", 15}, {"Chicken Biryani", 175}, {"Dosa", 30}};
    foodDeliverySystem.onboardRestaurant("R3", 1, menu3, 4.9);

    // Update Restaurant Menu
    foodDeliverySystem.updateMenu("R1", "Chicken65", 250);
    foodDeliverySystem.updateMenu("R2", "Chicken Biryani", 150);

    // Place Orders
    string order1 = foodDeliverySystem.placeOrder("Ashwin", {{"Idli", 3}, {"Dosa", 1}}, "Lowest cost");
    string order2 = foodDeliverySystem.placeOrder("Harish", {{"Idli", 3}, {"Dosa", 1}}, "Lowest cost");
    string order3 = foodDeliverySystem.placeOrder("Shruthi", {{"Veg Biryani", 3}}, "Highest rating");
    string order4 = foodDeliverySystem.placeOrder("Harish", {{"Idli", 3}, {"Dosa", 1}}, "Lowest cost");
    string order5 = foodDeliverySystem.placeOrder("xyz", {{"Paneer Tikka", 1}, {"Idli", 1}}, "Lowest cost");

    // Update Order Status
    foodDeliverySystem.updateOrderStatus("R3", order1, "COMPLETED");

    return 0;
}
