# geant4
A repository to store installation processes and simulations of geant4.

## Installation Steps on MacOS (Sequoia 15.5)

### Preparation 
Install Homebrew if you haven't yet:
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
Then run:
```
echo 'eval "$(/opt/homebrew/bin/brew shellenv)"' >> ~/.zprofile
eval "$(/opt/homebrew/bin/brew shellenv)"
```

Update/upgrade brew:
```bash
brew update
brew upgrade
```

Install necessary packages: 
```bash
brew install cmake gcc expat qt libxmu openmotif libxrandr libxinerama libxcursor libxi libx11 xquartz
brew install openjdk
sudo ln -sfn $(brew --prefix)/opt/openjdk /Library/Java/JavaVirtualMachines/openjdk
```


Prepare directories to install geant4:
```bash
cd $HOME
mkdir geant4
mkdir root
```

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
cd B1_build
cmake ../B1
make -j10
```
Then, execute the compiled project:
```bash
./exampleB1
```


