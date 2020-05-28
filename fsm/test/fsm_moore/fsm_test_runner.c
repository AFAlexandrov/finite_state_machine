#include "unity_fixture.h"

TEST_GROUP_RUNNER (fsm_moore) {
	RUN_TEST_CASE (fsm_moore, create);
	RUN_TEST_CASE (fsm_moore, set_state);
	RUN_TEST_CASE (fsm_moore, delete);
	RUN_TEST_CASE (fsm_moore, apply_state_exec_initial_state);
	RUN_TEST_CASE (fsm_moore, apply_state_set_next_state_as_initial);
	RUN_TEST_CASE (fsm_moore, call_create_from_state);
	RUN_TEST_CASE (fsm_moore, apply_state_after_reinit);
	RUN_TEST_CASE (fsm_moore, circle_works);
}