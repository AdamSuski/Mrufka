package langtonsant;

import javafx.application.Platform;

import java.util.List;
import java.util.Timer;
import java.util.TimerTask;

public class MakeSomeStepsAnt {

    private List <Character> handling;
    private List <Ant> ants;
    private Timer timer = new Timer();
    private long timerPeroid;

    public MakeSomeStepsAnt()
    {
        timerPeroid = 100;
        timer.scheduleAtFixedRate(new TimerTask() {
            @Override
            public void run() {
                Platform.runLater(new Runnable() {
                    @Override
                    public void run() {
                        for(Ant ant:ants) {
                            ant.makeStep('A');
                        }
                    }
                });
            }
        }, 0, timerPeroid);
    }



}
