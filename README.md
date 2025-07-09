# geant4
A repository to store installation processes and simulations of geant4.

## Installation Steps on MacOS (Sequoia 15.5)

### Root Installation

### geant4 Installation

## Running an example
Assuming there is a geant4 directory in your home directory, copy an example (say B1) from the following examples directory:
```bash
$HOME/geant4/geant4-v11.2.1-install/share/Geant4/examples/basic
```
Then, paste the B1 folder in your geant4 directory and do the following (only for the first time you are running the example, later on it can be executed directly): 
```bash
cd B1
mkdir B1_build
cmake ../B1
make -j10
```
Then, execute the compiled project:
```bash
./exampleB1
```


