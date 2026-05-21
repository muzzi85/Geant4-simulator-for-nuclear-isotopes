# ☢️ Geant4 Nuclear Isotope Simulation Framework

![image](https://github.com/user-attachments/assets/c25365dc-d29e-4e41-8e78-08b8d29b4905)

![image](https://github.com/user-attachments/assets/fe993a89-e9f3-426d-9305-4aa8acd89ce2)


A Geant4-based Monte Carlo simulation framework for modelling nuclear isotope interactions, gamma-ray transport, detector response, and energy spectrum generation using C++.

This project explores radiation physics, particle transport, and detector modelling for nuclear engineering and scientific computing applications.

---

# 🚀 Project Overview

This simulator was developed using **Geant4**, a widely used particle physics simulation toolkit for modelling the interaction of radiation with matter.

The framework enables:

* Gamma-ray spectrum generation
* Nuclear isotope simulation
* Detector geometry modelling
* Radiation transport analysis
* Monte Carlo particle tracking
* Energy deposition studies

The project demonstrates applied scientific computing using:

* C++
* Geant4 physics engines
* custom detector geometries
* particle interaction modelling

---

# 🧠 Scientific Problem

Accurate modelling of radiation behaviour is critical in:

* nuclear instrumentation
* medical physics
* detector design
* radiation shielding
* gamma spectroscopy
* scientific research

Experimental testing of nuclear systems can be expensive and time consuming.

Monte Carlo simulation allows researchers and engineers to:

* simulate particle interactions
* estimate detector response
* generate gamma spectra
* study radiation propagation
* validate experimental setups

before physical implementation.

---

# ⚛️ Simulation Features

## 🔹 Gamma-Ray Transport

Simulates gamma particle propagation through detector materials and shielding geometries.

## 🔹 Detector Geometry Modelling

Custom detector and shielding geometries built using Geant4 volumes and material definitions.

## 🔹 Energy Deposition Analysis

Tracks deposited energy inside sensitive detector regions.

## 🔹 Monte Carlo Particle Simulation

Uses probabilistic particle interaction models to simulate realistic nuclear behaviour.

## 🔹 Spectrum Generation

Produces gamma spectra and histogram outputs for analysis and visualization.

## 🔹 Material Interaction Modelling

Supports simulation of:

* absorption
* scattering
* attenuation
* secondary particle interactions

---

# 🏗️ Detector Geometry

The simulation includes cylindrical detector geometries and layered structures representing:

* detector cores
* shielding materials
* sensitive detector regions
* isotope emission zones

The visualizations below demonstrate the detector geometry and interaction regions generated using Geant4 visualization tools.

---

# 🔬 Monte Carlo Simulation Workflow

```text
Nuclear Isotope Source
          ↓
Particle Emission
          ↓
Geant4 Physics Engine
          ↓
Material Interactions
          ↓
Detector Energy Deposition
          ↓
Gamma Spectrum Generation
          ↓
ROOT / Histogram Analysis
```

---

# 📊 Example Outputs

The simulator generates:

* detector geometry visualizations
* gamma-ray interaction traces
* energy deposition histograms
* gamma spectra
* particle transport outputs

Example outputs include:

* cylindrical detector simulations
* shielding interaction studies
* radiation propagation analysis

---

# ⚡ Technical Highlights

## Physics & Simulation

* Monte Carlo radiation simulation
* Gamma transport modelling
* Nuclear isotope interaction analysis
* Particle tracking
* Detector response simulation

## Engineering

* Scientific computing in C++
* Geant4 detector construction
* Sensitive detector implementation
* Modular simulation design
* Physics list configuration

## Visualization & Analysis

* ROOT histogram plotting
* Spectrum visualization
* Detector geometry rendering
* Interaction path visualization

---

# 🛠️ Technology Stack

| Category             | Technology                 |
| -------------------- | -------------------------- |
| Physics Engine       | Geant4                     |
| Programming Language | C++                        |
| Build System         | CMake                      |
| Visualization        | ROOT                       |
| Simulation Method    | Monte Carlo                |
| Domain               | Nuclear Physics Simulation |

---

# 📈 Applications

This type of simulation can support:

## Nuclear Engineering

* detector system design
* shielding analysis
* isotope studies

## Medical Physics

* radiation therapy research
* imaging system simulation

## Scientific Research

* particle interaction analysis
* gamma spectroscopy
* radiation transport studies

## Education & Training

* nuclear physics learning
* detector modelling demonstrations

---

# 📂 Repository Structure

```text
src/                → simulation source files
include/            → detector and physics headers
*.mac               → Geant4 macro execution files
plot*.C             → ROOT plotting scripts
CMakeLists.txt      → CMake build configuration
GNUmakefile         → alternative build system
```

---

# ▶️ Running the Simulation

## Build

```bash
mkdir build
cd build
cmake ..
make
```

## Run

```bash
./Hadr06
```

## Execute Macro

```bash
/control/execute vis.mac
```

---

# 📊 Visualization

The simulation supports Geant4 visualization for:

* detector geometry rendering
* particle trajectory display
* interaction tracking
* radiation path analysis

ROOT scripts are also included for:

* histogram analysis
* gamma spectrum plotting
* detector response evaluation

---

# 🔮 Future Improvements

Potential future enhancements include:

* advanced detector geometries
* isotope libraries
* GPU-accelerated simulations
* AI-assisted spectrum analysis
* real detector calibration integration
* distributed simulation workloads

---

# ⚠️ Copyright & License

Copyright © 2026 Mustafa Alhamdi. All rights reserved.

This repository and its contents are provided for educational, research, and portfolio purposes only.

Unauthorized copying, redistribution, commercial usage, or reproduction of this codebase without explicit permission is prohibited.

Third-party libraries and frameworks used in this project remain subject to their respective licenses.

---

# 👨‍💻 Author

Built as a scientific computing and nuclear simulation project exploring:

* Monte Carlo methods
* radiation transport physics
* detector modelling
* Geant4 simulation systems
* high-performance C++ scientific engineering
