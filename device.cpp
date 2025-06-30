/*
 * File: device
 * Author: Kilian | ItwenzyI
 * Created: 30.06.2025
 * Description: 
 */
//

#include <string>
#include <iostream>


class Device {
private:
    std::string name_;
    int id_;
    const double storage_;

    public:

    Device(std::string& name, const int id, const double storage) 
    : name_(name), id_(id), storage_(storage) {}

    ~Device() = default;

    const std::string& getName() const {
        return name_;
    }

    int getID() const {
        return this->id_;
    }

    double getStorage() const {
        return this->storage_;
    }

    void print() const {
        std::cout << "Name: " << name_ << " ID: " << id_ << " Storage: " << storage_ << std::endl;
    }


};

void printDeviceInfo(const Device& d) {
    std::cout << "Name: " << d.getName() << " ID: " << d.getID() << " Storage: " << d.getStorage() << std::endl;
}

int main() {
    std::string name = "Name";
    const Device const_device(name, 21, 21.0);
    Device device(name, 64, 64.0);
    const Device* zeiger_device = &device;
    Device* const zeiger_device2 = &device;
    const_device.print();
    zeiger_device->print();
    zeiger_device2->print();
    printDeviceInfo(device);

}