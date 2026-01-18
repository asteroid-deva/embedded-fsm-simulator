#ifndef FSM_H
#define FSM_H

typedef enum {
    STATE_INIT,
    STATE_IDLE,
    STATE_READY,
    STATE_RUNNING,
    STATE_FAULT,
    STATE_RECOVERY,
    STATE_SHUTDOWN
} system_state_t;

typedef enum {
    EVT_NONE,
    EVT_INIT_DONE,
    EVT_CHECKS_OK,
    EVT_START,
    EVT_STOP,
    EVT_FAULT,
    EVT_RECOVER,
    EVT_RECOVERY_DONE
} system_event_t;

system_state_t fsm_handle_event(system_state_t current_state,
                                system_event_t event);

const char* state_to_str(system_state_t state);

#endif
