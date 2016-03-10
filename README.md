KUKA IO
=======

**This is a WIP documentation on the setup and usage of KUKA IO modules**

### IO Bus and Modules
Industrial IO Modules come in different filed buses depending on the KRC setup. DeviceNet, Profibus and EtherCat standards are available depending on the KRC. Most KRC use Beckhoff modules. Most common modules are digital IN, digital OUT, analog IN and analog OUT.

### KRC IO Configuration

**Important notice:** Digital IO can be accessed individually as bits or can be addressed together as byte, representing the 8 IO on a module as a single value.

#### KR C3 and below

Configuration is defined on the **iosys.ini** file at `KRC/ROBOTER/INIT/iosys.ini`. Documentation is provided at the end of the same file. See an example [iosys.ini](https://github.com/pral2a/KUKAIO/blob/master/iosys.ini). 

##### Inputs and Outputs syntax

###### Input

* INB means "input byte" (8-bit)
* INW means "input word" (16-bit)
* IND means "input double-word" (32-bit)

###### Output

* OUTB means "output byte" (8-bit)
* OUTW means "output word" (16-bit)
* OUTD means "output double-word" (32-bit)

*For example: `INB0` is "input byte 0" (inputs 1..8) and `INB1` is "input byte 1" (inputs 9..16)*

#### KR C4 and after

Configuration can be done using the **[WorkVisual](http://www.kuka-robotics.com/en/products/software/engineering_environment/start.htm)** software from KUKA, accessing the robot KRC via LAN. By knowing the Robot KRC LAN IP we can download the configuration on our local WorkVisual software. KRC bus structure is provided as a tree structure on the GUI. The IO Mapping tool is used to assign bus modules addresses to the KRC IOs.

<img src="https://cdn.rawgit.com/pral2a/f3b4760431761dd8f8b5/raw/8328068b7a6263a7c4b5ec4e0ece5c993d3e6896/iokuka.png" alt="KUKA WorkVisual" style="width: 100%"/>

### Basic Arduino tests

Simple bidirectional communication between KUKA industrial IO modules and Arduino. Optocouplers are used to isolate both circuits for safety and to deal with the two different logic voltage levels: Arduino 5V and KUKA IO's 24V. *This is a basic test circuit and should not be use for production.*

<img src="https://cdn.rawgit.com/pral2a/f3b4760431761dd8f8b5/raw/475fd338bac6361e841c92580f9526984fc2a7fa/kuka_arduino_basic.png" alt="KUKA WorkVisual" style="width: 100%"/>

Download the [Fritzing](https://github.com/pral2a/KUKAIO/blob/master/kuka_arduino_basic.fzz)

Download also the Arduino example [firmware](https://github.com/pral2a/KUKAIO/tree/master/kuka_io_firmware) 

#### Arduino Shield

We recommend the Electan Relay Control shield in order to simplify the work on the optocoupler circuit below. This provides 8 digital 0-24V outputs and 4 digital optoucoupled 0-24V inputs.

http://www.electan.com/relay-control-shield-optoisolator-p-3266-en.html

### KRC Buses

This is a short introduction to the KRC buses for internal and external communication with the robot.

*This information must be always checked against the robot KRC original documentation* 

#### Kuka buses
* **KCB** Kuka Controller Bus (used for robot motion)
* **KSB** Kuka System Bus (used for connecting smartPad and robots together for purpose of roboteam)

#### User buses
* **KEB** *port X65* Kuka Expansion Bus (adding EtherCat I/O, or through EtherCat adding legacy busses like DeviceNet and ProfiBus)
* **KLI**  *port X66* Kuka Line Interface (used for connecting to everything else: PLCs, safety PLC, Work Visual machine, ProfiNet, EthernetIP, Kuka Ethernet XML)
* **KONI** Kuka Options Network Interface (currently used for robot guidance using CV)
* **KSI** *port X69* Kuka Service Interface (Robot servicing by KUKA)