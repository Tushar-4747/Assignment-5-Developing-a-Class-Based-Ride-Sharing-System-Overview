# 🚗 Ride Sharing System - C++ Implementation

## 📋 Overview

This project is a class-based **Ride Sharing System** implemented in **C++**, designed for an academic assignment. It showcases object-oriented programming (OOP) principles including **encapsulation**, **inheritance**, and **polymorphism** through the simulation of real-world entities such as rides, drivers, and riders.

The system supports the following:
- Creating different types of rides (Standard and Premium)
- Assigning rides to drivers
- Requesting rides by riders
- Displaying detailed ride and user information
- Demonstrating polymorphic behavior through virtual methods

---

## 🧱 Object-Oriented Features

### ✅ Encapsulation
- **Driver** and **Rider** classes maintain private ride lists (`assignedRides` and `requestedRides`) and expose public methods (`addRide()` and `requestRide()`) to manage them.

### ✅ Inheritance
- **StandardRide** and **PremiumRide** inherit from the base class **Ride**, reusing and extending core ride properties and behaviors.

### ✅ Polymorphism
- `fare()` and `rideDetails()` are virtual functions overridden in derived classes.
- A list of base class pointers (`Ride*`) is used to demonstrate runtime polymorphism.

---

## 🧩 Class Structure

### 📦 Ride (Base Class)
- Attributes: `rideID`, `pickupLocation`, `dropoffLocation`, `distance`
- Methods: `fare()`, `rideDetails()`

### 🚕 StandardRide (Derived from Ride)
- Overrides: `fare()`, `rideDetails()`

### 🚘 PremiumRide (Derived from Ride)
- Overrides: `fare()`, `rideDetails()`

### 👨‍✈️ Driver
- Attributes: `driverID`, `name`, `rating`
- Private: `assignedRides`
- Methods: `addRide()`, `getDriverInfo()`

### 👤 Rider
- Attributes: `riderID`, `name`
- Private: `requestedRides`
- Methods: `requestRide()`, `viewRides()`

---

## ▶️ Sample Usage

```cpp
// Sample creation and interaction:
Ride* r1 = new StandardRide("R001", "A", "B", 5.0);
Driver d1("D123", "Alice", 4.9);
d1.addRide(r1);

Rider rider1("U101", "Bob");
rider1.requestRide(r1);

// Display info
d1.getDriverInfo();
rider1.viewRides();


📁 File Structure

📦 RideSharingSystem_CPP
├── main.cpp              # Main C++ source code
├── README.md             # Project overview and documentation
├── screenshots/          # Screenshots of output and code
📎 References (APA 7)
Lippman, S. B., Lajoie, J., & Moo, B. E. (2012). C++ Primer (5th ed.). Addison-Wesley.

Meyers, S. (2005). Effective C++ (3rd ed.). Addison-Wesley.

Stroustrup, B. (2013). The C++ Programming Language (4th ed.). Addison-Wesley.

🔗 GitHub Repository