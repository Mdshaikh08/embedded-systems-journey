# Modular UART Protocol Parser (FSM Implementation)

This project has been extracted into a standalone showcase repository to maintain modularity and highlight bare-metal architecture practices outside the primary learning monorepo.

**Dedicated Repository:** [Link to Standalone UART Parser](https://github.com/Mdshaikh08/UART-Protocol-Parser)

### Overview

A deterministic, byte-by-byte UART packet parser designed for resource-constrained microcontrollers. Implements an event-driven Finite State Machine (FSM) utilizing an indexed function-pointer jump table to achieve O(1) state transitions without nested branching.

### Architectural Highlights

* **State Machine Mechanics:** Function pointer dispatch table replacing branching `switch/case` logic.
* **Memory Placement:** Lookup table declared `static const` to force placement into Flash/ROM (`.rodata`), preventing SRAM waste and mitigating runtime pointer corruption.
* **Frame Validation:** Fixed header synchronization, dynamic payload extraction, and XOR frame check sequence verification.
* **Encapsulation:** Complete decoupling of public interface definitions from internal state handler routines.

Navigate to the [dedicated repository](https://github.com/Mdshaikh08/UART-Protocol-Parser) for the complete source code, test runner implementation, and build instructions.