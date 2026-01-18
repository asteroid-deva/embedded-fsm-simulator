# Embedded FSM Simulator

A host-tested finite state machine (FSM) designed to model and validate
embedded system behavior before hardware integration.

## Motivation

In safety-critical embedded and robotics systems, incorrect state transitions
can lead to undefined or unsafe behavior. This project demonstrates how
FSM-based control logic can be validated deterministically on a host machine
before deploying to microcontrollers.

## System States

- INIT
- IDLE
- READY
- RUNNING
- FAULT
- RECOVERY
- SHUTDOWN

## Event-Driven Design

The FSM reacts only to explicit events:

- EVT_INIT_DONE
- EVT_CHECKS_OK
- EVT_START
- EVT_STOP
- EVT_FAULT
- EVT_RECOVER
- EVT_RECOVERY_DONE

Illegal transitions are prevented by design.

## Architecture

- FSM logic is isolated from hardware
- Events are generated externally
- State transitions are deterministic
- No dynamic memory allocation
- No blocking delays

## Testing Strategy

The FSM is validated using a host-based test harness that feeds predefined
events and prints state transitions. This allows logic verification without
hardware dependencies.

## How to Build and Run

```bash
gcc test/fsm_test.c src/fsm.c -Iinclude -o fsm_test
./fsm_test
