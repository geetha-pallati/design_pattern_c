# design_pattern_c

# Singleton Pattern in C

    In C, Singleton is implemented using
    static variables + controlled access functions
    static variable → created once

    Return same instance every time

 # Factory 
    1.A Base Struct containing function pointers (our "Interface").
    2.Concrete Structs that represent specific objects.
    3.A Factory Function that returns a pointer to the base struct, initialized with the correct functions.
    4. This pattern is widely used in Embedded Systems and Linux Kernel development. 
        For example:VFS (Virtual File System): A common read() or write() interface that acts differently depending on whether you are accessing an EXT4, NTFS, or FAT32 drive.
    6.Device Drivers: A generic open() function that creates a specific driver instance based on the hardware connected.   