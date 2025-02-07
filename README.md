# SysTick Timer & NVIC Drivers

This project focuses on implementing **SysTick Timer** and **Nested Vectored Interrupt Controller (NVIC) drivers** for ARM Cortex-M microcontrollers. The implementation provides fundamental experience with these critical system components for embedded applications.

---

## Features

- **SysTick Timer Implementation:**
  - Configurable **time interval** for periodic interrupts.
  - Supports **one-shot** and **periodic mode** operations.
  - Uses **callback functions** for user-defined actions on each timer tick.

- **NVIC Driver Implementation:**
  - Enables **interrupt handling** for various peripherals.
  - Implements **interrupt priority management**.
  - Provides **APIs for enabling/disabling interrupts** dynamically.

---

## Project Structure

```
SysTick-NVIC-Drivers/
│-- src/        # Source code for SysTick and NVIC drivers
│-- inc/        # Header files for driver APIs
│-- docs/       # Documentation and implementation details
│-- examples/   # Sample usage of SysTick and NVIC drivers
│-- README.md   # Project description and usage details
```

---

## How to Use

1. Clone this repository:
   ```sh
   git clone https://github.com/ibucz/SysTick-NVIC-Drivers.git
   ```
2. Include the **SysTick** and **NVIC** driver files in your project.
3. Configure the SysTick timer by calling:
   ```c
   SysTick_Init(time_ms, callback_function);
   ```
4. Enable and configure interrupts using NVIC APIs:
   ```c
   NVIC_EnableIRQ(IRQn);
   NVIC_SetPriority(IRQn, priority_level);
   ```
5. Compile and flash onto the **ARM Cortex-M** microcontroller.

---

## License

This project is licensed under the **MIT License**.

---

## Contributors
- [Your Name](https://github.com/ibucz)

Feel free to contribute to this project by submitting issues or pull requests! 🚀

