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
    Color[] colors = {Color.WHITE, Color.LIGHTGREY, Color.LIGHTBLUE, Color.GREY, Color.ALICEBLUE, Color.BLUE, Color.BEIGE, Color.PINK,Color.GOLD,Color.GOLDENROD};
    String handling;
    GraphicsContext gc;
    int stepCounter = 0;

    public void mainLoop(GraphicsContext gc, Button startButton, Button pauseButton, Button stopButton){

        this.gc = gc;
        ants.add(new Ant(100,100,Board.Direction.West,"LR"));

        timer.scheduleAtFixedRate(new TimerTask() {
            @Override
            public void run() {
                Platform.runLater(new Runnable() {
                    @Override
                    public void run() {
                        if(!pause) {
                            stepCounter++;
                            for (Ant insect : ants) {
                                int tmpX = insect.getAntX();
                                int tmpY = insect.getAntY();
                                drawAnt(insect.getAntX()*4, insect.getAntY()*4,colors[board.getPointsBoard(tmpX,tmpY)]);
                                insect.antMovement(board.getPointsBoard(insect.getAntX(), insect.getAntY()));
                                board.setOneValuePointsBoard(tmpX,tmpY,board.getPointsBoard(tmpX,tmpY)+1);
                                drawAnt(insect.getAntX()*4, insect.getAntY()*4,Color.RED);
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

    private void drawAnt(int x, int y, Color color){
        gc.setFill(color);
        gc.fillRect( x, y,4,4);
    }

    public void changeHandling (String handling) {
        if (handling.length() < 11) {
            this.handling = handling;
            for (Ant ant : ants) {
                ant.setHandling(handling);
            }
            board.adjustToHandling(handling.length());
            for(int i=0; i<board.getSize(); i++){
                for(int j=0; j<board.getSize(); j++) {
                    drawAnt(i*4, j*4,colors[board.getPointsBoard(i,j)]);
                }
            }
        }
    }

    public void clearBoard(){
        boolean tmpPause = pause; //żeby po zrobieniu wrócił do stanu sprzed
        pause = true;   // pause bo robimy dużo operacji
        gc.setFill(colors[0]);
        gc.fillRect( 0, 0, 600, 600);
        for(Ant insect:ants)
        {
            drawAnt(insect.getAntX()*4, insect.getAntY()*4,Color.RED);
        }
        board.setEachValueOnBoard(0);
        pause = tmpPause;
    }

    public void addAnt(int x,int y,Board.Direction direction){
        ants.add(new Ant(x,y,direction,handling));
    }
}
