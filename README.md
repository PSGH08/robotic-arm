# 🤖 Robotic Arm – Team Golden Dragon

This repository contains the code and design files for the **Robotic Arm** project developed by **Team Golden Dragon**. As the **lead programmer**, I was responsible for developing the arm’s core control system, servo coordination, and motion logic, ensuring reliable and precise manipulation capabilities.

---

## 🧭 Project Overview

This project aims to design and build a programmable **robotic arm** capable of performing articulated tasks such as gripping, lifting, and positioning objects. It serves as a platform for understanding robotic kinematics, control algorithms, and servo motor integration.

### Project Goals:

- 🔁 **Multi-axis Movement**: Achieve accurate motion across multiple degrees of freedom.
- 🧠 **Servo Coordination**: Develop logic to coordinate timed and smooth servo motor actuation.
- 🧰 **Mechanical Modularity**: Build a frame that supports easy upgrades and redesigns.
- 🎮 **Manual & Automated Modes**: Enable both user-controlled and pre-programmed movement sequences.

---

## 🛠️ Technical Specifications

### Hardware

- **Microcontroller**: Arduino Uno R3  
- **Actuators**: 4–6 high-torque servo motors  
- **Structure**: Custom lightweight arm with claw end-effector  
- **Power Supply**: External power adapter suitable for simultaneous servo operation  

### Software

- **Language**: Arduino C++  
- **Motion Logic**: Time-based control + position sequencing  
- **User Interface**: Serial monitor for command input & real-time testing  
- **Features**:
  - Manual joint movement mode  
  - Predefined movement patterns  
  - Basic inverse kinematics experiments (WIP)

---

## 📁 Repository Structure

```
Robotic-Arm/
├── Arduino_Code/              # Main control programs (joint, claw, sequence control)
├── CAD_Designs/               # Mechanical design files (STLs, Fusion360, etc.)
├── Documentation/             # Diagrams, instructions, and team notes
└── README.md                  # This file
```

---

## 🎯 Achievements

- 🧠 Developed a responsive multi-servo control program.
- 🛠️ Designed and tested custom 3D-printed structural components.
- 🔄 Integrated both manual and pre-programmed movement options.
- 🤖 Demonstrated functional pick-and-place tasks in live demos.

---

## 📄 License

This project is licensed under the [MIT License](LICENSE). Feel free to explore, adapt, and improve upon it.

---

## 🤝 Credits & Acknowledgments

👥 **Team Golden Dragon**  
- 🧑‍💻 Lead Programmer: *[Your Name]*  
- 🤖 Mechanical Design: *[Team Member]*  
- 🔧 Assembly & Testing: *[Team Member]*  

🙏 Thanks to our mentors and fellow competitors at RoboCup for feedback and inspiration.
