# STM32F103 LED Animation Control with Custom Startup, Linker Script, and Makefile

## Overview

This project demonstrates LED animation control on the STM32F103 microcontroller by utilizing a custom startup file, linker script, and makefile. It’s designed to provide a deep understanding of bare-metal programming and embedded systems development, bypassing the use of traditional IDEs.

## Project Structure

- **Startup File:** Manages core initialization, interrupt vector table configuration, and RAM section initialization.
- **Linker Script:** Defines memory layout and manages code/data sections.
- **Makefile:** Automates the build process, including library compilation, linking, and flashing.

## Features

- Custom **startup file** for hardware initialization.
- Custom **linker script** for memory organization.
- **Makefile** for build automation, flashing, and cleaning.
- Integration with **OpenOCD** for debugging.
- **PUTTY** for serial communication.

## Tools Used

- **Git Bash**: Command-line terminal for building and flashing.
- **Arm GNU Toolchain**: Compilation toolchain.
- **OpenOCD**: Debugging and flashing server.
- **PUTTY**: Serial communication client.

## Getting Started

### Prerequisites

Ensure you have the following tools installed:

- Arm GNU Toolchain
- Git Bash (or equivalent terminal)
- OpenOCD
- PUTTY (optional for serial communication)

### Setting Up

1. **Clone the repository:**

    ```bash
    git clone https://lnkd.in/dTv6d_R9
    cd STM32F103_LED_Animation
    ```

2. **Install required tools and ensure they are in your system’s PATH.**

### Building the Project

To build the project, navigate to the project directory and run:

```bash
make all
```

To flash the firmware to the STM32F103 board, follow these steps:

1. **Connect the STM32F103 board to your computer using a suitable programmer/debugger (e.g., ST-Link).**

2. **Ensure that OpenOCD is properly installed and accessible from your command line.**

3. **Run the following command to flash the firmware:**

    ```bash
    make load
    ```

   This command will:
   - Start the OpenOCD server.
   - Flash the compiled binary to the STM32F103 microcontroller.

   If you encounter any issues with the flashing process, ensure that OpenOCD is configured correctly for your hardware setup and that the microcontroller is properly connected.

### Cleaning the Project

To remove all compiled object files and binaries, use the following command:

```bash
make clean

## Project Breakdown
```

- **startup/**: Custom startup file defining system initialization routines and memory setup.
  - **startup_stm32f103.s**: Assembly file for initial system setup and interrupt vector table configuration.

- **ld/**: Linker script that specifies memory layout and manages code/data placement.
  - **stm32f103.ld**: Linker script for organizing memory and section placement.

- **Makefile**: Automates the build, flash, and clean processes.
  - **Makefile**: Defines build rules, toolchain commands, and targets for compiling, linking, flashing, and cleaning.

## How It Works

1. **Startup File:** 
   - Initializes the STM32F103 microcontroller by setting up the vector table and configuring RAM sections (.data and .bss).
   - Ensures that the system is properly initialized before executing the main application.

2. **Linker Script:** 
   - Defines the memory layout of the microcontroller, specifying where different sections of the code and data should be placed in memory.
   - Helps in managing the available flash and RAM resources efficiently.

3. **LED Control Logic:** 
   - Implements functions to control and animate LEDs connected to the GPIO ports.
   - Provides various animation patterns and effects for visual output.

4. **Makefile:** 
   - Manages the entire build process by compiling the source code, linking with the custom linker script, and generating the final binary.
   - Automates flashing the firmware to the microcontroller using OpenOCD and cleaning build artifacts.


[![LinkedIn POST](https://img.shields.io/badge/-Youssef%20Hamed-0077B5?style=for-the-badge&logo=Linkedin&logoColor=white)]((https://www.linkedin.com/feed/update/urn:li:activity:7240313318282825728/))


