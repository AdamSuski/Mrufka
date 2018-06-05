package projectlangtonant;

import java.awt.*;
import java.io.Console;

import projectlangtonant.Board.Direction;

public class Ant {
    private Point position;
    private Board.Direction headingDirection;
    private String handling;
    private boolean dead = false;

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
        if(getAntX()<0 || getAntX()>150 || getAntY()<0 || getAntY()>150) {
            dead = true;
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

    public void antMovement( int value ){
        if(value>handling.length()-1)
            value=0;
        if(!dead) makeStep(handling.charAt(value));
    }
}
