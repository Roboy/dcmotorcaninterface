### Description ###
The muscleDriverCANInterface is a command line interface for low-level communication with the dc motors via CAN.
It works through driver library canlib. 

### Dependencies ###
install libcanlib (on linux) via:

```
#!bash
cd path/to/muscledrivercaninterface/lib
tar -xvzf linuxcan.tar.gz
cd linuxcan
make
sudo make install
```
### Build steps ###

```
#!bash
cd path/to/muscledrivercaninterface
cmake .
make
```