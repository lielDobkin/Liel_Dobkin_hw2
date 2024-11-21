#include "Device.h"
#include <iostream>


/* Get the operating system of the device.
   return The name of the operating system as a string.
*/
std::string Device::getOS() const
{
	return device;
}

/*
   Check if the device is currently active.
   return True if the device is active, false if it is inactive.
 */
bool Device::isActive() const
{
	return active;
}

/*
   Check if the device is currently turned on (active).
   return True if the device is on (active), false if it is off (inactive).
 */
void Device::activate()
{
	active = true;
}

/*
  Check if the device is currently turned off (inactive).
  return True if the device is on (active), false if the device is off (inactive).
 */
void Device::deactivate()
{
	active = false;
}

/*
  Initialize the device with its ID, type, and operating system.
  param id The unique identifier for the device.
  param type The type of the device (e.g., PHONE, PC).
  param os The operating system the device is running (e.g., "Windows10").
 */
void Device::init(unsigned int id, DeviceType type, std::string os)
{
	Device::id = id;
	Device::type = type;
	device = os;
	active = true;
}


/*
  Retrieve the unique identifier of the device.
  return The ID of the device.
 */
unsigned int Device::getID() const
{
	return id;
}

/**
  Retrieve the type of the device.
  return The device type (e.g., PHONE, PC, LAPTOP, TABLET).
 */
DeviceType Device::getType() const
{
	return type;
}

