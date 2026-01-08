# design_pattern_c

# Singleton Pattern in C

    In C, Singleton is implemented using
    static variables + controlled access functions
    static variable → created once

    Return same instance every time

 # Factory pattern in  C
    1.A Base Struct containing function pointers (our "Interface").
    2.Concrete Structs that represent specific objects.
    3.A Factory Function that returns a pointer to the base struct, initialized with the correct functions.
    4. This pattern is widely used in Embedded Systems and Linux Kernel development. 
        For example:VFS (Virtual File System): A common read() or write() interface that acts differently depending on whether you are accessing an EXT4, NTFS, or FAT32 drive.
    6.Device Drivers: A generic open() function that creates a specific driver instance based on the hardware connected.   

# Strategey pattern in c
    The Strategy Pattern is a behavioral design pattern that lets you define a family of algorithms, put each one into a separate class/struct, and make their objects interchangeable.

    In simpler terms: instead of using a massive if-else or switch block to decide how to perform a task, you plug in a specific "strategy" at runtime.
    The Strategy Concept
        Imagine a Navigation App. It can calculate a route for walking, driving, or public transport. Without the Strategy Pattern, you'd have one giant function with complex logic for every mode of transport. With the Strategy Pattern, you have three separate "strategies," and the app simply picks the one it needs.

# Observer Pattern in c
    The Observer Pattern is a behavioral design pattern used to create a subscription mechanism. It allows multiple objects (Observers) to "listen" to another object (the Subject) and get notified automatically whenever that subject changes its state.

    In C, we implement this using an array of function pointers inside the Subject.

    1. The Core Concept
        Think of a YouTube Channel.
        The Subject is the Channel.
        The Observers are the Subscribers.
        When the Channel uploads a video (state change), it loops through its list of Subscribers and sends a notification.
