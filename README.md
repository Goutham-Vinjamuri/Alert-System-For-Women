# 🛡️ Women Safety Alert System

A real-time **Women Safety Alert System** built using **Arduino Uno**, **SIM900A GSM Module**, **NEO-6M GPS Module**, **16×2 I2C LCD**, **Push Button**, and **Buzzer**.

The system is designed to provide immediate assistance during emergencies. When the emergency button is pressed, the Arduino retrieves the user's live GPS coordinates, generates a Google Maps location link, activates a buzzer, and sends an emergency SMS containing the location to predefined emergency contacts. The alert remains active until a **STOP** SMS command is received.

---

# 🚀 Features

* Emergency push-button activation
* Live GPS location tracking
* Google Maps location link generation
* SMS alerts using GSM module
* Sends alerts to multiple emergency contacts
* Audible buzzer alarm
* 16×2 LCD status display
* Remote alert cancellation using **STOP** SMS
* Automatic GPS validation before sending alerts

---

# 🛠 Hardware Used

* Arduino Uno
* SIM900A GSM Module
* NEO-6M GPS Module
* 16×2 I2C LCD Display
* Push Button
* Active Buzzer
* Jumper Wires
* Breadboard
* Power Supply

---

# 📚 Software Used

* Arduino IDE
* TinyGPS++
* SoftwareSerial
* LiquidCrystal_I2C

---

# 📂 Libraries

```cpp
SoftwareSerial
TinyGPS++
LiquidCrystal_I2C
```
---
<img width="1200" height="1600" alt="1" src="https://github.com/user-attachments/assets/cea7f923-1690-4337-be03-830bdc4a4862" />

---

---

# ⚙ Working

1. System powers on.
2. LCD displays **System Ready**.
3. User presses the emergency button.
4. Buzzer turns ON.
5. GPS module searches for a valid location.
6. Arduino creates a Google Maps URL.
7. GSM module sends an emergency SMS to stored contacts.
8. LCD displays **Alert Sent**.
9. System continuously monitors incoming SMS.
10. If a **STOP** message is received:

    * Buzzer turns OFF.
    * Alert mode is disabled.
    * LCD displays **Alert Stopped**.
    * System returns to **System Ready**.

---

# 📱 Sample SMS

```
EMERGENCY!

https://maps.google.com/?q=16.506174,80.648015
```

---

# 💻 Code Highlights

* SoftwareSerial for GSM and GPS communication
* TinyGPS++ for GPS parsing
* Google Maps URL generation
* SMS transmission using AT Commands
* LCD status monitoring
* Remote STOP command handling
* Emergency state management using a boolean flag

---

# 📌 Future Improvements

* ESP32 with Wi-Fi support
* Mobile application integration
* Cloud database logging
* SOS call feature
* Rechargeable battery backup
* Real-time location tracking
* Fall detection sensor
* Voice activation
* IoT dashboard

---

# 🎯 Applications

* Women Safety
* Student Safety
* Elderly Monitoring
* Personal Emergency Assistance
* Field Worker Protection

---

# 📖 Learning Outcomes

* Arduino Programming
* Embedded Systems
* GSM Communication
* GPS Integration
* Serial Communication
* AT Commands
* Hardware Interfacing
* Real-Time Embedded Applications

---

# 👨‍💻 Author

**Vinjamuri Goutham**

B.Tech – Electronics and Communication Engineering

VIT-AP University

Interested in Embedded Systems, IoT, Robotics, and Automation.

⭐ If you found this project useful, consider giving it a Star.
