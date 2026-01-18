#include <stdio.h>
#include "fsm.h"

int main(void)
{
    system_state_t state = STATE_INIT;

    system_event_t test_events[] = {
        EVT_INIT_DONE,
        EVT_CHECKS_OK,
        EVT_START,
        EVT_FAULT,
        EVT_RECOVER,
        EVT_RECOVERY_DONE,
        EVT_CHECKS_OK,
        EVT_START,
        EVT_STOP
    };

    int count = sizeof(test_events) / sizeof(test_events[0]);

    printf("Starting FSM Test\n\n");

    for (int i = 0; i < count; i++) {
        printf("Event %d | %s -> ",
               test_events[i],
               state_to_str(state));

        state = fsm_handle_event(state, test_events[i]);

        printf("%s\n", state_to_str(state));
    }

    return 0;
}
