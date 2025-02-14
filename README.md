# BioSim-v1.0

## Overview

**BioSim-v1.0** is a biological evolution simulator developed in C++. It models the process of natural selection, allowing users to observe and analyze evolutionary dynamics over successive generations.

## Features

- **Simulation of Natural Selection:** Models evolutionary processes to study adaptation and survival.
- **Customizable Parameters:** Users can adjust various simulation settings to explore different evolutionary scenarios.
- **Data Output:** Generates data for analysis of evolutionary trends and outcomes.

## Installation

1. **Clone the Repository:**

  ```bash
   git clone https://github.com/demirbaydemir/biosim-v1.0.git
   cd biosim-v1.0
  ```

2. **Compile the Source Code:**
Ensure you have a C++ compiler installed. Then, compile the code using:

  ```bash
   g++ -o biosim biosim.cpp
  ```

2. **Run the Simulator:**
Execute the compiled program:

  ```bash
  ./biosim
  ```

## Usage

Upon running the simulator, it will execute with default parameters. To customize the simulation:

- **Modify Parameters:** Edit the `biosim.cpp` file to adjust simulation settings such as population size, mutation rates, and selection criteria.
- **Recompile:** After making changes, recompile the program as described in the installation steps.

## Contributing

Contributions are welcome! To contribute:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -m 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a Pull Request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
