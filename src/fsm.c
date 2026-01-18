#include "fsm.h"

system_state_t fsm_handle_event(system_state_t current_state,
                                system_event_t event)
{
    switch (current_state)
    {
        case STATE_INIT:
            if (event == EVT_INIT_DONE)
                return STATE_IDLE;
            break;

        case STATE_IDLE:
            if (event == EVT_CHECKS_OK)
                return STATE_READY;
            break;

        case STATE_READY:
            if (event == EVT_START)
                return STATE_RUNNING;
            else if (event == EVT_FAULT)
                return STATE_FAULT;
            break;

        case STATE_RUNNING:
            if (event == EVT_FAULT)
                return STATE_FAULT;
            else if (event == EVT_STOP)
                return STATE_SHUTDOWN;
            break;

        case STATE_FAULT:
            if (event == EVT_RECOVER)
                return STATE_RECOVERY;
            break;

        case STATE_RECOVERY:
            if (event == EVT_RECOVERY_DONE)
                return STATE_IDLE;
            break;

        case STATE_SHUTDOWN:
            break;
    }

    return current_state;
}

const char* state_to_str(system_state_t s)
{
    switch (s) {
        case STATE_INIT: return "INIT";
        case STATE_IDLE: return "IDLE";
        case STATE_READY: return "READY";
        case STATE_RUNNING: return "RUNNING";
        case STATE_FAULT: return "FAULT";
        case STATE_RECOVERY: return "RECOVERY";
        case STATE_SHUTDOWN: return "SHUTDOWN";
        default: return "UNKNOWN";
    }
}
