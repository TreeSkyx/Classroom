public class Stopwatch {
    /* Privte data fields of startTime and endTime */
    private long startTime;
    private long endTime;

    /* Create Construtor and Method */

    //  set startTime to the current time 
    Stopwatch(){
    }

    //  Reset startTime to the current time 
    public void start(){
        startTime = System.currentTimeMillis();
    }

    //  Reset endTime to the current time
    public void stop(){
        endTime = System.currentTimeMillis();
    }

    // get the elapsed time
    public long getElapsedTime(){
        return getEndTime() - getStartTime();
    }

    public long getStartTime(){
        return startTime;
    }

    public long getEndTime(){
        return endTime;
    }
}
