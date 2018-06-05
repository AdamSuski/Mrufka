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
    private Timer timer = new Timer();
    List<Ant> ants = new ArrayList<Ant>();
    Board board = new Board(150);
    boolean pause = true;
    Color[] colors = {Color.LIGHTGREY, Color.GREY};
    String handling;

    public void mainLoop(GraphicsContext gc, Button startButton, Button pauseButton, Button stopButton){


        ants.add(new Ant(100,100,Board.Direction.West,"LR"));

        timer.scheduleAtFixedRate(new TimerTask() {
            @Override
            public void run() {
                Platform.runLater(new Runnable() {
                    @Override
                    public void run() {
                        if(!pause) {
                            for (Ant insect : ants) {
                                int tmpX = insect.getAntX();
                                int tmpY = insect.getAntY();
                                drawAnt(gc, insect.getAntX()*4, insect.getAntY()*4,Color.GREY);
                                insect.antMovement(board.getPointsBoard(insect.getAntX(), insect.getAntY()));
                                board.setOneValuePointsBoard(tmpX,tmpY,board.getPointsBoard(tmpX,tmpY)+1);
                                drawAnt(gc, insect.getAntX()*4, insect.getAntY()*4,Color.RED);
                            }
                        }
                    }
                });
            }
        },0,100);

        startButton.setOnAction( e -> pause = false);
        pauseButton.setOnAction( e -> pause = true);
        stopButton.setOnAction( e -> clearBoard());
    }

    private void drawAnt(GraphicsContext gc, int x, int y, Color color){
        gc.setFill(color);
        gc.fillRect( x, y,4,4);
    }

    public void changeHandling (String handling) {
        this.handling = handling;
        for(Ant ant: ants)
        {
            ant.setHandling(handling);
        }
        board.adjustToHandling(handling.length());
    }

    public void clearBoard(){

    }

    public void addAnt(int x,int y,Board.Direction direction){
        ants.add(new Ant(x,y,direction,handling));
    }

}
