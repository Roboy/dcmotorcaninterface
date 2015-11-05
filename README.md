### Description ###
The muscleDriverCANInterface is another low-level communication layer, i.e. hardware interface.
It works through driver library canlib.

### Dependencies ###
install libcanlib (on linux) via:

```
#!bash
cd path/to/flexrayusbinterface/lib
tar -xvzf linuxcan.tar.gz
cd linuxcan
make
sudo make install
```
### Build steps ###

```
#!bash
cd path/to/flexrayusbinterface
cmake .
make
```
