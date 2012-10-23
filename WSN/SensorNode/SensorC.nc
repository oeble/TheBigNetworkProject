module SensorAppC {
    uses {
        interface SplitControl as SensorControl;
        interface InterruptWithData as DataIn;
    }
}
implementation {

  event void SensorControl.startDone(error_t err) {
        if (err == SUCCESS) {
          printf("SensorControl.startDone: TOS_NODE_ID == %d\n", TOS_NODE_ID);
          fflush(stdout);
        }else {
            call SensorControl.start();
        }
    }

    event void SensorControl.stopDone(error_t err) {
        // do nothing
    }

}
