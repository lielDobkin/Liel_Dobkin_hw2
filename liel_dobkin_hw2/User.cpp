#include "User.h"
#include <iostream>

/*
  Initializes the User object with the given parameters.
  param userId The unique ID of the user.
  param userName The username of the user.
  param userAge The age of the user.
 */
void User::init(unsigned int userId, std::string userName, unsigned int userAge)
{
    id = userId;
    username = userName;
    age = userAge;
    devices = new DevicesList(); // Dynamically allocate memory for the devices list
    devices->init(); // Initialize the devices list
}

/*
  Clears the User object, releasing any dynamically allocated memory.
  Prints a message indicating the ID of the user being cleared.
 */
void User::clear()
{
    std::cout << "Clearing User object with ID: " << id << std::endl;
    delete devices;  // Release dynamically allocated memory for the devices list
    devices = nullptr; // Avoid dangling pointer
}

/*
  Returns the ID of the user.
 */
unsigned int User::getID() const
{
    return id;
}

/*
  Returns the username of the user.
 */
std::string User::getUserName() const
{
    return username;
}

/*
  Returns the age of the user.
 */
unsigned int User::getAge() const
{
    return age;
}

/*
  Returns a reference to the devices list associated with the user.
  return Reference to the user's DevicesList object.
  throws std::runtime_error if the devices list is uninitialized.
 */
DevicesList& User::getDevices() const
{
    if (!devices) {
        throw std::runtime_error("Devices list is uninitialized.");
    }
    return *devices;
}

/*
  Adds a new device to the user's devices list.
  param newDevice The device to be added.
  If the devices list is uninitialized, it will be initialized before adding the device.
 */
void User::addDevice(Device newDevice)
{
    if (devices == nullptr)
    {
        devices = new DevicesList();  // Initialize the devices list if it is null
        devices->init();
    }
    devices->add(newDevice); // Add the device to the list
}

/*
  Checks if all devices in the user's devices list are active.
  return True if all devices are active, false otherwise.
 */
bool User::checkIfDevicesAreOn() const
{
    DeviceNode* current = nullptr;
    if (devices == nullptr)
    {
        return false;  // Return false if the devices list is uninitialized or empty
    }

    current = devices->get_first(); // Start with the first node in the list
    while (current != nullptr) {
        // Check if the current device is inactive
        if (!current->get_data().isActive()) 
        {
            return false; // If any device is inactive, return false
        }
        current = current->get_next(); // Move to the next nodeZ
    }

    return true; // All devices are active
}
