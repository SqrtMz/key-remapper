Remap keyboard keys location or remap to a virtual controller.

Create the file `/etc/udev/rules.d/99-key-remapper-controller.rules` with the next content for the virtual controller to be detected as a controller:
```
SUBSYSTEM=="input", KERNEL=="event*", ATTRS{name}=="Key Remapper Virtual Controller", ENV{ID_INPUT_JOYSTICK}="1", ENV{ID_INPUT_KEYBOARD}="0", ENV{ID_INPUT_KEY}="0"
```

After creating the file, reload the rules by executing:
```
sudo udevadm control --reload-rules
sudo udevadm trigger
```
