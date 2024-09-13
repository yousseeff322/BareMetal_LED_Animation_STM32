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
