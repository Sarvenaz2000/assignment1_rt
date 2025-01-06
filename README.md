# assignment1_rt

# Research Track I - First Assignment
This repository contains the assignment work for the **Research Track** course, completed by: 
**Sarvenaz Ashoori**  
**ID: 6878764**

## Introduction
This repository provides a ROS package that includes two primary nodes:
-  **User Interface node**
-  **Distance Monitor node**
These nodes work together within the **`turtlesim`** simulation environment to create a simple, interactive system for controlling and monitoring two turtles.

## Node Overview

### 1. User Interface Node (user_interface)

This node manages user input and controls the movements of two turtles (`turtle1` and `turtle2`) within the simulation. Its main functionalities include:  
- Adding a second turtle (`turtle2`) to the simulation environment.  
- Allowing the user to:  
   - Choose which turtle to control (`turtle1` or `turtle2`).  
   - Define the linear and angular velocities for the selected turtle.  
- Sending movement commands to the chosen turtle, enabling it to move for one second. Once the movement is complete, the turtle halts, and the interface becomes ready for the next command.

- 
