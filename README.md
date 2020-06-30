# finite_state_machine (raw version)

main feature is:

    void fsm_moore (void) {
      void (* state) (void) = fsm_state()->state;
      fsm_set_state(fsm_state()->next_state);
      state();
    }
