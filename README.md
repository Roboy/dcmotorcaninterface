### Description ###
The dcmotorCANInterface is a command line interface for low-level communication with the dc motors via CAN.
It works through driver library [canlib](http://www.kvaser.com/downloads/) 

### Dependencies ###
install libcanlib (on linux) via:

```
#!bash
cd path/to/dcmotorCANInterface/lib
tar -xvzf linuxcan.tar.gz
cd linuxcan
make
sudo make install
```
### Build steps ###

```
#!bash
cd path/to/dcmotorCANInterface
cmake .
make
```