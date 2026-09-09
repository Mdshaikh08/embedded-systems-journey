# Embedded Systems Journey

A self-designed, day-by-day path from C fundamentals to embedded software engineering 

This repo is my learning log: every folder is a working day, every commit is real progress (bugs included). It's not a tutorial I copied — it's the record of me building each concept from scratch, debugging it myself, and writing it down.

## Roadmap

| Phase | Focus | Status |
|---|---|---|
| **1 — Core Foundations** | C fundamentals: pointers, structs/unions/bitfields, memory management, data structures, state machines, GDB, compilation pipeline | ✅ Complete |
| **2 — Microcontrollers & Hardware** | Bare-metal on the NXP FRDM-MCXN236 (Cortex-M33): GPIO, interrupts, timers/PWM, ADC/DAC, UART/SPI/I²C, linker scripts, NXP eIQ TinyML | 🔜 In progress |
| **3 — RTOS, Linux & Systems** | FreeRTOS, embedded Linux drivers, Yocto/Buildroot, POSIX, OpenCV/ONNX computer vision on ARM Linux | Planned |
| **4 — GPU, Drivers & Debugging** | PCIe, GPU driver architecture, C++ for embedded, advanced debugging, TensorRT/Qualcomm AI Engine | Planned |
| **5 — Specialization** | Targeted prep for specific companies/roles | Planned |

## Phase 1 — What's Inside

Each folder covers one day's concept, built from a mix of guided exercises and self-driven extras once a concept clicked. Folders are named `NN_Concept_EmbeddedContext` to show both the C mechanism and why it matters for embedded work.

**Core language:** pointer arithmetic, double pointers & 2D traversal, struct padding & unions, bitfields & bitwise macros, dynamic memory (malloc/calloc/realloc + the three classic memory bugs), function pointers & dispatch tables, volatile/const/static, endianness & alignment, the preprocessor, multi-file project structure, the full compilation pipeline (preprocess → compile → assemble → link), Makefiles.

**Data structures & patterns:** singly linked lists, circular buffers, stacks & queues (array-based), finite state machines via function-pointer tables, sorting/searching with Big-O reasoning, custom string handling, file I/O.

**Tooling:** GDB (breakpoints, backtrace, frame navigation), Git workflow (feature branch → commit → push → merge → delete, one new concept per day).

**Concurrency:** race conditions and critical sections, demonstrated on both a plain counter and a simulated GPIO register — directly informed by reading real NXP MCXN236 SDK source (`GPIO_Type`, `PSOR`/`PCOR`/`PDDR`, CMSIS `__I`/`__O`/`__IO` volatility macros).

## Capstone Project

**[UART Protocol Parser](https://github.com/Mdshaikh08/UART-Protocol-Parser)** — a ring-buffer-backed, FSM-driven packet parser (header/length/payload/checksum framing) using a function-pointer dispatch table, tested against valid, corrupt, and partial byte streams. Pulled out into its own repo since it's the piece that best demonstrates everything Phase 1 was building toward. See that repo for the full write-up.

## Hardware

- NXP FRDM-MCXN236 (Cortex-M33, 150 MHz) — primary board for Phase 2 onward
- MCUXpresso IDE + MCXN236 SDK

