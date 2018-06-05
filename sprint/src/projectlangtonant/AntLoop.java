package projectlangtonant;

import javafx.application.Platform;
import javafx.event.EventHandler;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Button;
import javafx.scene.paint.Color;

import java.awt.event.ActionEvent;
import java.util.ArrayList;
import java.util.List;
import java.util.Timer;
import java.util.TimerTask;

public class AntLoop {
    private Timer timer;
    public void mainLoop(GraphicsContext gc, Button startButton, Button pauseButton, Button stopButton, ){
        List<Ant> ants = new ArrayList<>();
        Board board = new Board(150);
        timer = new Timer();
        timer.scheduleAtFixedRate(new TimerTask() {
            @Override
            public void run() {
                Platform.runLater(new Runnable() {
                    @Override
                    public void run() {
                        for(Ant insect: ants){
                            insect.antMovement(board.getPointsBoard(insect.getAntX(),insect.getAntY()));
                            drawAnt(gc, insect.getAntX() , insect.getAntY());
                        }
                    }
                });

            }
        },0,60);
/*
        startButton.setOnAction( e-> timer.start());
        pauseButton.setOnAction();
        stopButton.setOnAction(new EventHandler<ActionEvent>() {
            @Override public void handle(ActionEvent e) {
                timer.cancel();
            }
        }); */
    }

    private void drawAnt(GraphicsContext gc, int x, int y){
        gc.setFill(Color.RED);
        gc.fillRect( x, y,4,4);
    }
}
