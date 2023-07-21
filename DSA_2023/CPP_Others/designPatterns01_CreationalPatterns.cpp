#include <iostream>
#include <string>
#include <vector>

// Singleton Pattern

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void showMessage() {
        std::cout << "Singleton: Hello, I am a singleton object." << std::endl;
    }

private:
    Singleton() {}  // Private constructor to prevent direct instantiation.
};

// Factory Method Pattern

// Product
class Product {
public:
    virtual void showInfo() = 0;
};

// Concrete Products
class ConcreteProductA : public Product {
public:
    void showInfo() override {
        std::cout << "Product A" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void showInfo() override {
        std::cout << "Product B" << std::endl;
    }
};

// Creator (The Factory)
class Creator {
public:
    virtual Product* createProduct() = 0;
};

// Concrete Creators
class ConcreteCreatorA : public Creator {
public:
    Product* createProduct() override {
        return new ConcreteProductA();
    }
};

class ConcreteCreatorB : public Creator {
public:
    Product* createProduct() override {
        return new ConcreteProductB();
    }
};

// Abstract Factory Pattern

// Abstract Products
class AbstractProductX {
public:
    virtual void showInfoX() = 0;
};

class AbstractProductY {
public:
    virtual void showInfoY() = 0;
};

// Concrete Products
class ConcreteProductX1 : public AbstractProductX {
public:
    void showInfoX() override {
        std::cout << "Product X1" << std::endl;
    }
};

class ConcreteProductX2 : public AbstractProductX {
public:
    void showInfoX() override {
        std::cout << "Product X2" << std::endl;
    }
};

class ConcreteProductY1 : public AbstractProductY {
public:
    void showInfoY() override {
        std::cout << "Product Y1" << std::endl;
    }
};

class ConcreteProductY2 : public AbstractProductY {
public:
    void showInfoY() override {
        std::cout << "Product Y2" << std::endl;
    }
};

// Abstract Factory
class AbstractFactory {
public:
    virtual AbstractProductX* createProductX() = 0;
    virtual AbstractProductY* createProductY() = 0;
};

// Concrete Factories
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductX* createProductX() override {
        return new ConcreteProductX1();
    }

    AbstractProductY* createProductY() override {
        return new ConcreteProductY1();
    }
};

class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductX* createProductX() override {
        return new ConcreteProductX2();
    }

    AbstractProductY* createProductY() override {
        return new ConcreteProductY2();
    }
};

// Prototype Pattern

// Prototype
class Prototype {
public:
    virtual Prototype* clone() const = 0;
};

// Concrete Prototypes
class ConcretePrototypeA : public Prototype {
public:
    Prototype* clone() const override {
        return new ConcretePrototypeA(*this);
    }

    void showInfo() {
        std::cout << "Prototype A" << std::endl;
    }
};

class ConcretePrototypeB : public Prototype {
public:
    Prototype* clone() const override {
        return new ConcretePrototypeB(*this);
    }

    void showInfo() {
        std::cout << "Prototype B" << std::endl;
    }
};

// Builder Pattern

// Product (Complex Object to be constructed)
class Product {
public:
    void setPartA(const std::string& partA) {
        this->partA = partA;
    }

    void setPartB(const std::string& partB) {
        this->partB = partB;
    }

    void showInfo() {
        std::cout << "Product: " << partA << " " << partB << std::endl;
    }

private:
    std::string partA;
    std::string partB;
};

// Builder (Abstract builder class)
class Builder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual Product* getResult() = 0;
};

// Concrete Builder (The specific builder class)
class ConcreteBuilder : public Builder {
private:
    Product* product;

public:
    ConcreteBuilder() {
        product = new Product();
    }

    void buildPartA() override {
        product->setPartA("Part A");
    }

    void buildPartB() override {
        product->setPartB("Part B");
    }

    Product* getResult() override {
        return product;
    }
};

// Director (Controls the construction process)
class Director {
public:
    Product* construct(Builder* builder) {
        builder->buildPartA();
        builder->buildPartB();
        return builder->getResult();
    }
};

// Object Pool Pattern

// Object
class Object {
public:
    void reset() {
        // Reset the object's state to its initial state.
    }
};

// Object Pool (Maintains a pool of objects)
class ObjectPool {
private:
    std::vector<Object*> pool;
    int maxSize;

public:
    ObjectPool(int size) : maxSize(size) {
        for (int i = 0; i < maxSize; ++i) {
            pool.push_back(new Object());
        }
    }

    Object* acquireObject() {
        if (!pool.empty()) {
            Object* obj = pool.back();
            pool.pop_back();
            return obj;
        }
        return nullptr; // Pool is empty
    }

    void releaseObject(Object* obj) {
        if (pool.size() < maxSize) {
            obj->reset();
            pool.push_back(obj);
        }
    }
};

int main() {
    // Singleton Pattern
    Singleton& singleton = Singleton::getInstance();
    singleton.showMessage();

    // Factory Method Pattern
    Creator* creatorA = new ConcreteCreatorA();
    Product* productA = creatorA->createProduct();
    productA->showInfo();

    Creator* creatorB = new ConcreteCreatorB();
    Product* productB = creatorB->createProduct();
    productB->showInfo();

    // Abstract Factory Pattern
    AbstractFactory* factory1 = new ConcreteFactory1();
    AbstractProductX* productX1 = factory1->createProductX();
    AbstractProductY* productY1 = factory1->createProductY();
    productX1->showInfoX();
    productY1->showInfoY();

    AbstractFactory* factory2 = new ConcreteFactory2();
    AbstractProductX* productX2 = factory2->createProductX();
    AbstractProductY* productY2 = factory2->createProductY();
    productX2->showInfoX();
    productY2->showInfoY();

    // Prototype Pattern
    Prototype* prototypeA = new ConcretePrototypeA();
    Prototype* clonedA = prototypeA->clone();
    clonedA->showInfo();

    Prototype* prototypeB = new ConcretePrototypeB();
    Prototype* clonedB = prototypeB->clone();
    clonedB->showInfo();

    // Builder Pattern
    Director director;
    Builder* builder = new ConcreteBuilder();
    Product* constructedProduct = director.construct(builder);
    constructedProduct->showInfo();

    // Object Pool Pattern
    ObjectPool objectPool(5);
    Object* obj1 = objectPool.acquireObject();
    Object* obj2 = objectPool.acquireObject();
    if (obj1 && obj2) {
        std::cout << "Two objects acquired from the pool." << std::endl;
    }
    objectPool.releaseObject(obj1);
    objectPool.releaseObject(obj2);
    std::cout << "Two objects released back to the pool." << std::endl;

    return 0;
}
