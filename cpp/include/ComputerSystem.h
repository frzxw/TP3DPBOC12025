#pragma once

// Utilities
#include "../utils/Date.cpp"

// Base classes
#include "../component/Component.cpp"
#include "../component/Hardware.cpp"
#include "../component/Software.cpp"

// Interfaces
#include "../interfaces/Bootable.cpp"
#include "../interfaces/Connectable.cpp"
#include "../interfaces/Executable.cpp"
#include "../interfaces/Upgradable.cpp"

// Hardware Components
// -- Processor
#include "../hardware/processor/CPU.cpp"

// -- Memory
#include "../hardware/memory/RAM.cpp"

// -- Storage
#include "../hardware/storage/StorageDevice.cpp"
#include "../hardware/storage/HDD.cpp"
#include "../hardware/storage/SSD.cpp"

// -- Expansion Cards
#include "../hardware/expansion/ExpansionCard.cpp"
#include "../hardware/expansion/GraphicsCard.cpp"
#include "../hardware/expansion/NetworkCard.cpp"
#include "../hardware/expansion/SoundCard.cpp"

// -- Cooling
#include "../hardware/cooling/Cooling.cpp"
#include "../hardware/cooling/AirCooling.cpp"
#include "../hardware/cooling/LiquidCooling.cpp"

// -- Power
#include "../hardware/power/PowerSupply.cpp"

// -- Motherboard
#include "../hardware/motherboard/Motherboard.cpp"

// -- Peripherals
#include "../hardware/peripheral/Peripheral.cpp"
#include "../hardware/peripheral/Monitor.cpp"
#include "../hardware/peripheral/Keyboard.cpp"
#include "../hardware/peripheral/Mouse.cpp"

// Software Components
#include "../software/Firmware.cpp"
#include "../software/BIOS.cpp"
#include "../software/Driver.cpp"
#include "../software/Application.cpp"
#include "../software/GameEngine.cpp"
#include "../software/OperatingSystem.cpp"
#include "../software/Utility.cpp"

// Computer System
#include "../computer/Computer.cpp"