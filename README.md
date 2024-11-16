# CPlus-Application Backend

## Overview

Welcome to the CPlus-Application Backend project! This is a C++ backend application designed to handle photo capturing, storage, and management for our photo application. The backend communicates with the frontend to provide seamless photo operations.

## Features

- **Photo Capture**: Capture photos directly from connected devices.
- **Photo Storage**: Store photos efficiently in a local or cloud-based storage.
- **Photo Management**: Manage photo metadata and facilitate retrieval.

## Prerequisites

To build and run this project, you'll need:

- **C++ Compiler**: GCC or Clang
- **CMake**: To manage the build process
- **Boost Libraries**: For additional C++ functionality
- **OpenCV**: For handling image capture and processing
- **libcurl**: For network operations

## Installation

### Install Dependencies

```sh
# Update package list
sudo apt update

# Install C++ compiler and CMake
sudo apt install g++ cmake

# Install Boost libraries
sudo apt install libboost-all-dev

# Install OpenCV
sudo apt install libopencv-dev

# Install libcurl
sudo apt install libcurl4-openssl-dev

## Build the Project

```bash
# Clone the repository
git clone https://github.com/LesterCerioli/CPlus-Application.git
cd CPlus-Application

# Create a build directory
mkdir build
cd build

# Generate build files using CMake
cmake ..

# Build the project
make
```

# Usage

To run the backend server:

```bash
./CPlus-Application
```

# Configuration

Configuration options can be adjusted in the config.json file located in the root directory. You can specify settings such as storage paths, network ports, and more.

# License

This project is licensed under the MIT License. See the LICENSE file for details.

## Contact

For any inquiries or support, please contact us at [email@example.com](mailto:lesterlucasit@hotmail.com). You can also connect with us on [LinkedIn](https://www.linkedin.com/in/lester-cerioli-83300a81/).
