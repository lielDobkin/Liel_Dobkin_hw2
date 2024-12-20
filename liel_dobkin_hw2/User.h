#pragma once
#include "DeviceList.h"
#include <string>

class User
{
public:
	//--methods--

	void init(unsigned int id, std::string username, unsigned int age);

	void clear();

	unsigned int getID() const;

	std::string getUserName() const;

	unsigned int getAge() const;

	DevicesList& getDevices() const;

	void addDevice(Device newDevice);

	bool checkIfDevicesAreOn() const;



private:
	//--fields--
	unsigned int id;
	std::string username; 
	unsigned int age;
	DevicesList* devices;
};

