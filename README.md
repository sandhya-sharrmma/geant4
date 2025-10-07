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
For installing all the development dependencies, run this:
```
brew install cmake git expat qt@5 xerces-c libomp tbb openssl && \
brew install --cask xquartz
```

Visit this website and copy the accurate release link from the list:
https://root.cern/releases/release-63604/ 

Go to the root directory and download the accurate version:
```
cd $HOME/root
wget https://root.cern/download/root_v6.36.04.macos-15.6-arm64-clang170.tar.gz
```
NOTE: the link is for macOS specifically

Untar the downloaded .tar.gz file:
```
tar -xvzf root_v6.36.04.macos-15.6-arm64-clang170.tar.gz
```

Verify the installation:
```
source $HOME/root/root/bin/thisroot.sh
root 
```

After typing root, this appears:
<img width="508" height="181" alt="image" src="https://github.com/user-attachments/assets/6498bf81-099f-4703-a0e3-beb8532aacee" />

To quit root type .q 


### geant4 Local Installation

Go to geant4 directory:
```
cd $HOME/geant4
```
Visit the geant4 website to get the accurate download link according to the OS being used: https://geant4.web.cern.ch/download/11.3.2.html

Use the link under 'Binary releases' according to the OS:
```
wget https://cern.ch/geant4-data/releases/lib4.11.3.p02/Darwin-clang17.0.0-Sequoia.tar.gz (remove) 

wget https://gitlab.cern.ch/geant4/geant4/-/archive/v11.3.2/geant4-v11.3.2.tar.gz
```

Untar the file:
```
tar -xvzf Darwin-clang17.0.0-Sequoia.tar.gz
```

Go to the directory created and create a new directory within:
```
cd Geant4-11.3.2-Darwin/
mkdir build
cd build
```

Compile the code using ccmake GUI:
```
ccmake ..
```
<img width="636" height="851" alt="image" src="https://github.com/user-attachments/assets/b3d47161-ca72-4b10-b713-3bfdaa5dfd68" />

Press 'c' to configure and then 'e' to exit. 

The following will be shown: 
<img width="533" height="372" alt="Screenshot 2025-10-03 at 4 41 35 PM" src="https://github.com/user-attachments/assets/fa81b2fd-77c6-44df-b0a2-4dfa8e8ee379" />

Change it to the following:
<img width="573" height="377" alt="image" src="https://github.com/user-attachments/assets/e7b61b7c-1be9-471e-917d-5bca1c5bc9ff" />

Here, the GEANT4_INSTALL_PREFIX should be <path_where_is_geant4>/geant4.v11.3.2-install 

In case of an error such as this:
<img width="1236" height="1006" alt="image" src="https://github.com/user-attachments/assets/57fe1cad-ccc5-4d4f-9945-1998190f081d" />

Run the following in the build directory:
```
cmake .. \
  -DCMAKE_INSTALL_PREFIX=$HOME/geant4/geant4-v11.3.2-install \
  -DGEANT4_INSTALL_DATA=ON \
  -DGEANT4_USE_QT=ON \
  -DGEANT4_USE_RAYTRACER_X11=ON \
  -DCMAKE_PREFIX_PATH="$(brew --prefix qt@5)"
```

Repeat the 'ccmake ..' step and press 'c' followed by 'g' to generate.

Then, run:
```
make -j4
```
And:
```
make install
```

Check if everything is installed correctly:
```
cd /Users/ss14729/geant4/geant4-v11.3.2-install/bin
source geant4.sh
```

Create your source file to run geant4 each time (from your home):
```
cd
nano SetupGeant4.sh
```

Write the following:
echo '** Setup ROOT6 **'
source $HOME/root/root/bin/thisroot.sh
echo '** Setup GEANT4 **'
source $HOME/geant4/geant4-v11.3.2-install/bin/geant4.sh
echo 'GOOD WORK :))'

Test the .sh file:
```
source SetupGeant4.sh
```

This should be printed:
<img width="147" height="51" alt="image" src="https://github.com/user-attachments/assets/d2246959-52ba-4dbf-a745-560fadfe8949" />



## Running an example
First, setup geant4:

```
source SetupGeant4.sh
```

Assuming there is a geant4 directory in your home directory, copy an example (say B1) from the following examples directory:

```bash
cp $HOME/geant4/geant4-v11.3.2-install/share/Geant4/examples/basic/B1 .
```

Then, paste the B1 folder in your geant4 directory and do the following (only for the first time you are running the example, later it can be executed directly): 
```
cd B1
mkdir B1_build
cd B1_build
```

If cmake has not been installed or system cannot find homebrew:
```
echo 'eval "$(/opt/homebrew/bin/brew shellenv)"' >> ~/.zprofile
eval "$(/opt/homebrew/bin/brew shellenv)"
```

Then: 
```
cmake ..
```

***Debugging Corner***
If there is an error such as this:
<img width="764" height="355" alt="image" src="https://github.com/user-attachments/assets/bafac1ac-30a7-4e9f-bcc0-55079b981981" />

Run the following:
```
source $HOME/geant4/geant4-v11.3.2-install/bin/geant4.sh
cmake "$HOME/geant4/B1/build"   -DCMAKE_PREFIX_PATH="$(brew --prefix qt@5)"
```

Then:
```
make -j10
```

Then, execute the compiled project:
```bash
./exampleB1
```


