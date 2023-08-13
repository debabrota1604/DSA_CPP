#include <iostream>
#include <vector>
#include <string>

// Adapter Pattern

// Adaptee (The incompatible class)
class LegacyLibrary {
public:
    void doSomethingOld() {
        std::cout << "LegacyLibrary: Doing something old..." << std::endl;
    }
};

// Target (The desired interface)
class NewInterface {
public:
    virtual void doSomethingNew() = 0;
};

// Adapter (The adapter class)
class LegacyAdapter : public NewInterface {
private:
    LegacyLibrary legacy;

public:
    void doSomethingNew() override {
        std::cout << "LegacyAdapter: Adapted the old functionality to the new interface. ";
        legacy.doSomethingOld();
    }
};

// Decorator Pattern

// Component (The basic interface)
class Coffee {
public:
    virtual double getCost() = 0;
    virtual std::string getDescription() = 0;
};

// Concrete Component (The base class)
class SimpleCoffee : public Coffee {
public:
    double getCost() override {
        return 2.0;
    }

    std::string getDescription() override {
        return "Simple Coffee";
    }
};

// Decorator (The abstract decorator class)
class CoffeeDecorator : public Coffee {
protected:
    Coffee* wrappedCoffee;

public:
    CoffeeDecorator(Coffee* coffee) : wrappedCoffee(coffee) {}

    double getCost() override {
        return wrappedCoffee->getCost();
    }

    std::string getDescription() override {
        return wrappedCoffee->getDescription();
    }
};

// Concrete Decorator (The specific decorator class)
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    double getCost() override {
        return CoffeeDecorator::getCost() + 0.5;
    }

    std::string getDescription() override {
        return CoffeeDecorator::getDescription() + ", Milk";
    }
};

// Proxy Pattern

// Subject (The common interface)
class Image {
public:
    virtual void display() = 0;
};

// Real Subject (The real implementation)
class RealImage : public Image {
private:
    std::string filename;

public:
    RealImage(const std::string& file) : filename(file) {
        loadImageFromDisk();
    }

    void display() override {
        std::cout << "Displaying image: " << filename << std::endl;
    }

    void loadImageFromDisk() {
        std::cout << "Loading image: " << filename << std::endl;
    }
};

// Proxy (The proxy class)
class ImageProxy : public Image {
private:
    RealImage* realImage;
    std::string filename;

public:
    ImageProxy(const std::string& file) : filename(file), realImage(nullptr) {}

    void display() override {
        if (!realImage) {
            realImage = new RealImage(filename);
        }
        realImage->display();
    }
};

// Bridge Pattern

// Implementor (The interface for bridge classes)
class Device {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

// Concrete Implementor (The specific bridge class)
class TV : public Device {
public:
    void turnOn() override {
        std::cout << "TV: Turning ON..." << std::endl;
    }

    void turnOff() override {
        std::cout << "TV: Turning OFF..." << std::endl;
    }
};

// Concrete Implementor (The specific bridge class)
class Radio : public Device {
public:
    void turnOn() override {
        std::cout << "Radio: Turning ON..." << std::endl;
    }

    void turnOff() override {
        std::cout << "Radio: Turning OFF..." << std::endl;
    }
};

// Abstraction (The interface for the client)
class RemoteControl {
protected:
    Device* device;

public:
    RemoteControl(Device* dev) : device(dev) {}

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

// Refined Abstraction (The specific client class)
class BasicRemote : public RemoteControl {
public:
    BasicRemote(Device* dev) : RemoteControl(dev) {}

    void turnOn() override {
        std::cout << "BasicRemote: Pressing the ON button..." << std::endl;
        device->turnOn();
    }

    void turnOff() override {
        std::cout << "BasicRemote: Pressing the OFF button..." << std::endl;
        device->turnOff();
    }
};

// Facade Pattern

// Subsystem classes (Complex subsystem to be hidden)
class CPU {
public:
    void start() {
        std::cout << "CPU: Starting..." << std::endl;
    }

    void stop() {
        std::cout << "CPU: Stopping..." << std::endl;
    }
};

class Memory {
public:
    void load() {
        std::cout << "Memory: Loading data..." << std::endl;
    }

    void unload() {
        std::cout << "Memory: Unloading data..." << std::endl;
    }
};

class HardDrive {
public:
    void read() {
        std::cout << "HardDrive: Reading data..." << std::endl;
    }

    void write() {
        std::cout << "HardDrive: Writing data..." << std::endl;
    }
};

// Facade (Simplifies the interface for the client)
class ComputerFacade {
private:
    CPU cpu;
    Memory memory;
    HardDrive hardDrive;

public:
    void start() {
        std::cout << "ComputerFacade: Starting the computer..." << std::endl;
        cpu.start();
        memory.load();
        hardDrive.read();
    }

    void stop() {
        std::cout << "ComputerFacade: Stopping the computer..." << std::endl;
        cpu.stop();
        memory.unload();
        hardDrive.write();
    }
};

// Composite Pattern

// Component (The base class)
class FileSystem {
public:
    virtual void showInfo() = 0;
};

// Leaf (The individual class)
class File : public FileSystem {
private:
    std::string name;

public:
    File(const std::string& n) : name(n) {}

    void showInfo() override {
        std::cout << "File: " << name << std::endl;
    }
};

// Composite (The container class)
class Folder : public FileSystem {
private:
    std::string name;
    std::vector<FileSystem*> files;

public:
    Folder(const std::string& n) : name(n) {}

    void addFile(FileSystem* file) {
        files.push_back(file);
    }

    void showInfo() override {
        std::cout << "Folder: " << name << std::endl;
        for (FileSystem* file : files) {
            file->showInfo();
        }
    }
};

int main() {
    // Adapter Pattern
    NewInterface* adapter = new LegacyAdapter();
    adapter->doSomethingNew();
    delete adapter;

    // Decorator Pattern
    Coffee* simpleCoffee = new SimpleCoffee();
    Coffee* coffeeWithMilk = new MilkDecorator(simpleCoffee);
    std::cout << "Cost: $" << coffeeWithMilk->getCost() << std::endl;
    std::cout << "Description: " << coffeeWithMilk->getDescription() << std::endl;
    delete coffeeWithMilk;
    delete simpleCoffee;

    // Proxy Pattern
    Image* image = new ImageProxy("test.jpg");
    image->display();
    delete image;

    // Bridge Pattern
    Device* tv = new TV();
    RemoteControl* remote = new BasicRemote(tv);
    remote->turnOn();
    remote->turnOff();
    delete remote;
    delete tv;

    Device* radio = new Radio();
    remote = new BasicRemote(radio);
    remote->turnOn();
    remote->turnOff();
    delete remote;
    delete radio;

    // Facade Pattern
    ComputerFacade computer;
    computer.start();
    computer.stop();

    // Composite Pattern
    FileSystem* file1 = new File("file1.txt");
    FileSystem* file2 = new File("file2.jpg");
    FileSystem* folder1 = new Folder("Folder 1");
    folder1->addFile(file1);
    folder1->addFile(file2);

    FileSystem* file3 = new File("file3.cpp");
    FileSystem* file4 = new File("file4.docx");
    FileSystem* folder2 = new Folder("Folder 2");
    folder2->addFile(file3);
    folder2->addFile(file4);

    FileSystem* root = new Folder("Root");
    root->addFile(folder1);
    root->addFile(folder2);

    root->showInfo();

    delete root;

    return 0;
}


/*
This single C++ code showcases all the structural patterns - Adapter, Decorator, Proxy, Bridge, Facade, and Composite. Each pattern is applied to different classes, and the main function demonstrates the usage of these patterns. When you run this code, you will see the output illustrating how each pattern works. This example provides a comprehensive overview of different structural patterns in a single codebase.
*/