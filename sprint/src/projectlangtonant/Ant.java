package projectlangtonant;

import java.awt.*;
import java.io.Console;

import projectlangtonant.Board.Direction;

public class Ant {
    private Point position;
    private Board.Direction headingDirection;
    private String handling;

    public Ant(int x, int y, Direction direction, String handling) {
        this.position = new Point (x,y);
        this.headingDirection = direction;
        this.handling = handling;
    }

    public Point getPosition() {
        return position;
    }

    public int getAntX(){
        return position.x;
    }

    public int getAntY(){
        return position.y;
    }

    public void setAntX(int value){ //to tak naprawde nie jest set tylko dodawanie
        position.x += value;
    }

    public void setAntY(int value){ //to tak naprawde nie jest set tylko dodawanie
        position.y += value;
    }

    public void setPoint(Point point) {
        this.position = point;
    }

    public String getHandling() {
        return handling;
    }

    public void setHandling(String handling) {
        this.handling = handling;
    }

    private void ifOutOfBoardChangeXY(){
        if(getAntX()<0){
            setAntX(150);
        }
        else if (getAntX()>150){
            setAntX(-150);
        }
        if(getAntY()<0){
            setAntY(150);
        }
        else if (getAntY()>150){
            setAntY(-150);
        }
    }



    private void makeStep(char instruction) {
        switch (this.headingDirection) {
            case North:
                if (instruction == 'L') {
                    headingDirection = Direction.West;
                    position.x -= 1;
                } else if (instruction == 'R') {
                    headingDirection = Direction.East;
                    position.x += 1;
                }
                break;
            case East:
                if (instruction == 'L') {
                    headingDirection = Direction.North;
                    position.y += 1;
                } else if (instruction == 'R') {
                    headingDirection = Direction.South;
                    position.y -= 1;
                }
                break;
            case West:
                if (instruction == 'L') {
                    headingDirection = Direction.South;
                    position.y -= 1;
                } else if (instruction == 'R') {
                    headingDirection = Direction.North;
                    position.y += 1;
                }
                break;
            case South:
                if (instruction == 'L') {
                    headingDirection = Direction.East;
                    position.x += 1;
                } else if (instruction == 'R') {
                    headingDirection = Direction.West;
                    position.x -= 1;
                }
                break;
        }

    }

    public int antMovement( int value ){
        int handlingPosition = value;
        value++;
        if(handlingPosition>handling.length()-1)
            handlingPosition=0;

        makeStep(handling.charAt(handlingPosition));
        return value;
    }
}
