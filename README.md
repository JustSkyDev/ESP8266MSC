# Master Slave Communication Library for ESP8266

Welcome to the **Master Slave Communication** library for ESP8266! This library is a user-friendly adaptation of the `espnow.h` library, designed to streamline communication between ESP8266 devices in a master-slave configuration.

## 🌟 Key Features

- **Simplified ESP-NOW**: We've simplified the use of ESP-NOW, a protocol developed by Espressif for high-speed, low-power, peer-to-peer wireless communication.
- **Master-Slave Communication**: Our library enables one ESP8266 device (the Master) to control and exchange data with one or more ESP8266 devices (the Slaves).
- **Multi-Device Support**: You can communicate with multiple slave devices simultaneously.
- **Data Types**: Our library supports various data types, including integers, floats, strings, and custom data structures.
- **Easy-to-Use API**: We provide a simple and intuitive API for sending and receiving data, abstracting away the complexities of the `espnow.h` library.

## 📦 Installation

Follow these steps to install the Master Slave Communication library for ESP8266:

[![SaRXx.gif](https://s9.gifyu.com/images/SaRXx.gif)](https://gifyu.com/image/SaRXx)

## 🚀 Usage

Our library provides an easy-to-use API for sending and receiving data. The Master device can send commands or data to the Slave devices, which can respond with data or perform actions based on the received commands.

## 🎯 Applications

This library is perfect for projects such as IoT devices, home automation systems, sensor networks, and other projects requiring inter-ESP8266 communication.

For more detailed information on how to use the Master Slave Communication library, please refer to our included examples and API documentation.

## 📝 Example Code

Here is a simple example of how to use the Master Slave Communication library. This example demonstrates a master device sending a string message to a slave device.

```cpp
#include <ESP8266MSC.h>

// Create an instance of the library
ESP8266MSC msc;

// Add a slave device
uint8_t slave_mac[6] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; // Replace with your slave's MAC address

void setup() {
  // Initialize the library
  msc.init();

  // Set the device role to MASTER
  msc.setRole(MSC_ROLE_MASTER);

  // Add peer connection
  msc.addPeer(slave_mac, MSC_ROLE_SLAVE, 1, NULL, 0);
}

void loop() {
  // Send a message to the slave device
  char message[] = "Hello, Slave!";
  msc.send(slave_mac, (uint8_t *)message, sizeof(message));

  // Wait for a while before sending the next message
  delay(1000);
}

```

In this example, the master device sends a “Hello, Slave!” message to the slave device every second, demonstrating the capability of the library for continuous data transmission.

## 📚 Library Documentation

Here's a quick overview of the functions provided by our library:

```cpp
int ESP8266MSC::init(void); // Initialize the ESP8266MSC
int ESP8266MSC::deInit(void); // Deinitialize the ESP8266MSC
int ESP8266MSC::onReceiveEV(void (*callback)(uint8_t *mac_addr, uint8_t *data, uint8_t length)); // Register a receive callback
int ESP8266MSC::delReceiveEV(void); // Unregister the receive callback
int ESP8266MSC::onSendEV(void (*callback)(uint8_t *mac_addr, uint8_t status)); // Register a send callback
int ESP8266MSC::delSendEV(void); // Unregister the send callback
int ESP8266MSC::send(uint8_t *ba, uint8_t *data, uint8_t length); // Send data
int ESP8266MSC::addPeer(uint8_t *mac_addr, MSC_ROLE role, uint8_t channel, uint8_t *key, uint8_t key_length); // Add a peer
int ESP8266MSC::delPeer(uint8_t *mac_addr); // Delete a peer
int ESP8266MSC::setRole(MSC_ROLE role); // Set the role of the device
int ESP8266MSC::getRole(void); // Get the role of the device
int ESP8266MSC::setPeerRole(uint8_t *mac_addr, MSC_ROLE role); // Set the role of a peer
int ESP8266MSC::getPeerRole(uint8_t *mac_addr); // Get the role of a peer
int ESP8266MSC::setPeerChannel(uint8_t *mac_addr, uint8_t channel); // Set the channel of a peer
int ESP8266MSC::getPeerChannel(uint8_t *mac_addr); // Get the channel of a peer
int ESP8266MSC::setPeerKey(uint8_t *mac_addr, uint8_t *key, uint8_t key_length); // Set the key of a peer
int ESP8266MSC::getPeerKey(uint8_t *mac_addr, uint8_t *key, uint8_t *key_length); // Get the key of a peer
uint8_t *ESP8266MSC::fetchPeer(bool restart); // Fetch a peer
int ESP8266MSC::isPeerExist(uint8_t *mac_addr); // Check if a peer exists
int ESP8266MSC::getCntInfo(uint8_t *all_cnt, uint8_t *encrypt_cnt); // Get connection info
int ESP8266MSC::setKok(uint8_t *key, uint8_t length); // Set the key of the device
```

In addition, our library uses the `MSC_ROLE` enumeration to define the role of a device:

```cpp
enum MSC_ROLE
{
  MSC_ROLE_IDLE = 0,   // The device is idle
  MSC_ROLE_MASTER,     // The device is a master
  MSC_ROLE_SLAVE,      // The device is a slave
  MSC_ROLE_BOTH,       // The device can act as both master and slave
  MSC_ROLE_MAX,        // The maximum value of the enumeration
};
```

## 🎉 Happy Coding!

We hope you find this library useful for your projects. If you have any questions or need further assistance, don’t hesitate to reach out. Remember, the best way to learn is by doing. So, get your hands dirty, start coding, and have fun! Happy coding! 🚀.
