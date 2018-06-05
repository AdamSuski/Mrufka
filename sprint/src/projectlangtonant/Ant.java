package projectlangtonant;

import java.awt.*;

public class Ant {
    private Point point;
    private int direction;
    private String handling;

    public Ant(int x, int y, int direction, String handling) {
        this.point = new Point (x,y);
        this.direction = direction;   //N 8; E 6; W 4; S 2
        this.handling = handling;
    }

    public Point getPoint() {
        return point;
    }

    public int getAntX(){
        return point.x;
    }

    public int getAntY(){
        return point.y;
    }

    public void setAntX(int value){ //to tak naprawde nie jest set tylko dodawanie
        point.x += value;
    }

    public void setAntY(int value){ //to tak naprawde nie jest set tylko dodawanie
        point.y += value;
    }

    public void setPoint(Point point) {
        this.point = point;
    }

    public int getDirection() {
        return direction;
    }

    public void setDirection(int direction) {
        this.direction = direction;
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

    private void makeStepR(){
       if( getDirection()==8 ){
           setAntX(1);
           setDirection(6);
       }
       else if( getDirection()==6 ){
           setAntY(1);
           setDirection(2);
       }
       else if( getDirection()==2){
           setAntX(-1);
           setDirection(4);
       }
       else if( getDirection()==4 ){
           setAntY(-1);
           setDirection(8);
       }
        ifOutOfBoardChangeXY();
    }

    private void makeStepL(){
        if( getDirection()==8 ){
            setAntX(-1);
            setDirection(4);
        }
        else if( getDirection()==6 ){
            setAntY(-1);
            setDirection(8);
        }
        else if( getDirection()==2){
            setAntX(1);
            setDirection(6);
        }
        else if( getDirection()==4 ){
            setAntY(1);
            setDirection(2);
        }
        ifOutOfBoardChangeXY();
    }

    public int antMovement( int value ){
        int handlingPosition = value;
        value++;
        if(handlingPosition>handling.length()-1)
            handlingPosition=0;
        if(handling.charAt(handlingPosition) == 'R'){
            makeStepR();
        }
        else{
            makeStepL();
        }
        return value;
    }
}
