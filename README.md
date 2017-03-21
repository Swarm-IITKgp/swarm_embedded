# swarm_embedded
Arduino codes for low level control

Requirements for building:
- Arduino IDE 1.6+
- Add 'ros_lib' to Arduino libraries
- Open swarm.ino and compile

Requirements for running the code:
- ROS Indigo

How to run:
```sh
$ roscore
$ rosrun rosserial_python serial_node.py /dev/ttyACM0
```
