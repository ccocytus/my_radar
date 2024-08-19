# My Radar: The Air Traffic Control Panel

**My Radar** is a C project that simulates a 2D air traffic control panel, allowing you to visualize and manage air traffic. This project involves rendering aircrafts and control towers on a simulation panel, handling their movements, and managing collisions according to predefined rules.

## Table of Contents
1. [Project Overview](#project-overview)
2. [Features](#features)
3. [Installation](#installation)
4. [Usage](#usage)
    - [Script Generation](#script-generation)
    - [Running the Simulation](#running-the-simulation)
    - [User Interactions](#user-interactions)
5. [Compilation](#compilation)
6. [Project Structure](#project-structure)
7. [Contributing](#contributing)
8. [License](#license)

## Project Overview

In this project, you will create a simulation of air traffic, displaying aircrafts and control towers on a 2D panel. The simulation adheres to strict rules to manage the movements of aircrafts and their interactions with control towers.

### Entities in the Simulation
- **Aircrafts**: Fly from a departure point to a destination, moving in a straight line at a constant speed.
- **Control Towers**: Stationary entities that define control areas on the map where aircrafts can collide without being destroyed.

## Features

- **2D Visualization**: Render aircrafts and control towers on a 1920x1080 panel.
- **Collision Management**: Aircrafts are destroyed upon collision unless within a control tower's area.
- **Script-Based Simulation**: The simulation is driven by a script file detailing the aircrafts and control towers' positions, speeds, and other attributes.
- **Dynamic User Interactions**: Toggle hitbox visibility, sprite visibility, grid, and FPS display during the simulation.

## Installation

To set up the project on your local machine:

1. Clone the repository:
    ```sh
    git clone https://github.com/your-username/my_radar.git
    cd my_radar
    ```

2. Compile the project using the provided Makefile:
    ```sh
    make
    ```

### Usage

### Script Generation

The project includes a Python script located in the `scripts/` directory that can be used to generate simulation files. You can specify the number of towers and planes, as well as the output filename.

To view the script options:

```sh
python scripts/script.py -h
```
## Example command to generate a simulation file:
```sh
python scripts/script.py --towers 50 --planes 9000 --filename simulation.txt
```
This command generates a file named simulation.txt with 50 towers and 9000 planes.

## Running the Simulation
Once you have compiled the project and generated a simulation file, you can run the simulation using the following command:
```sh
./my_radar simulation.txt
```
This will launch the simulation using the data from simulation.txt.

## User Interactions

    ‘L’ key enable/disable hitboxes and areas.
    ‘S’ key enable/disable sprites.
    ‘g’ key enable/disable grids.
    ‘f’ key enable/disable fps.
    ‘Q’ key to quit the program.
## Compilation

The project is compiled using a `Makefile`. It includes several rules:

- `make`: Compile the project.
- `make clean`: Remove object files.
- `make fclean`: Remove object files and the binary.
- `make re`: Recompile the project from scratch.


