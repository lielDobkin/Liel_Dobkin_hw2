#pragma once
#include <string>

///////////////////////////////////////////////////////////
/*														 //
	These definitions are used for tests,                //
	you can add your own, but please do not delete any.  //
*/														 //
enum DeviceType { PHONE, PC, LAPTOP, TABLET };		     //

// Predefined operating system identifiers
#define UbuntuOS "UbuntuLinux"                           //						
#define RedHatOS "RedHatLinux"							 //
#define MacOS "MacOS"									 //
#define IOS "IOS"										 //
#define WINDOWS7 "Windows7"                              //
#define WINDOWS10 "Windows10"                            //
#define WINDOWS11 "Windows11"                            //
#define ANDROID "Android"                                //
														 //
/// ///////////////////////////////////////////////////////

/*
 This class encapsulates the details and operations for a device,
 including initialization, activation state management, and
 retrieving device details such as ID, type, and OS.
 */
class Device
{
public:
	//--methods--
	/*
	 Initialize the device with an ID, type, and OS.
	 param id The unique identifier for the device.
	 param type The type of device (e.g., PHONE, PC).
	 param os The operating system of the device (e.g., "Windows10").
	 */
	void init(unsigned int id, DeviceType type, std::string os);

	/*
	 Get the ID of the device.
	 return The unique identifier of the device.
	 */
	unsigned int getID() const;

	/*
	 Get the type of the device.
	 return The device type (e.g., PHONE, PC).
	 */
	DeviceType getType() const;

	/*
	 Get the operating system of the device.
	 return The operating system as a string.
	 */
	std::string getOS() const;

	/*
	 Check if the device is active.
	 return True if the device is active, false otherwise.
	 */
	bool isActive() const;

	/*
	 Activate the device.
	 */
	void activate();

	/*
	 Deactivate the device.
	*/
	void deactivate();

private:
	//--fields--
	std::string device; // The name or description of the device.
	DeviceType type;    // The type of the device.
	unsigned int id;    // The unique identifier for the device.
	bool active;        // The activation state of the device.
};
