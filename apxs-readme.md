# Running APXS Simulation

If the repo is missing in remote, do the following:
```
git clone git@github.com:nyuad-astroparticle/apxs.git
```

Else, 
```
cd $HOME/Desktop/apxs;
git pull 
```

To run the simulation after making all necessary changes, inside the build directory:
```
./apxs -g ./geometry/new_geom/output.gdml -m ./macros/test_new_geom.mac
```


