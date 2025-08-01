// Debugging in C++ with Visual Studio Code
// Exercise 02_02
// Printing Variable Values, by Eduardo Corpeño

#include <iostream>

class Battery{
private:
    double charge;
    double normalDrain;
    double lowPowerDrain;

    static constexpr double lowPoweModeThreshold {20};
public:
    Battery(double capacity, double normalDrain, double lowPowerDrain)
    : charge(capacity), normalDrain(normalDrain), lowPowerDrain(lowPowerDrain) {}

    void simulateUsage(int hours){
        for(int i = 1; i <= hours; i++){
            if(charge < 0){
                charge = 0; // Prevent negative charge
            }
            else if(charge > lowPoweModeThreshold){
                charge -= normalDrain;  // Normal power usage
            }
            else{
                charge -= lowPowerDrain; // Reduced drain in power-saving mode
            }
            std::cout<<"Current hour: "<<i <<" Charge: "<<charge<<std::endl;
        }
    }

    double getCharge() const { return charge; }
};

int main(){
    double batteryCapacity = 100.0; // 100% battery
    double normalDrain = 5.0;       // Normal power usage (5% per hour)
    double lowPowerDrain = 2.0;     // Power-saving mode (2% per hour)
    int hours = 24;                 // Simulate 24 hours of usage

    Battery myBattery(batteryCapacity, normalDrain, lowPowerDrain);
    myBattery.simulateUsage(hours);

    std::cout << "Battery charge after " << hours << " hours: "
              << myBattery.getCharge() << "%" << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}
