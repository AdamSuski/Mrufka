package projectlangtonant;

import java.awt.*;

public class Board {
    private int[][] pointsBoard;
    private int handlingLenght;
    public Board(int x) {
        this.pointsBoard = new int[x][x];
        setEachValueOnBoard(0);
    }

    public int getPointsBoard(int x, int y) {
        return pointsBoard[x][y];
    }

    public void setOneValuePointsBoard(int x, int y, int value) {
        if(value > handlingLenght-1) value = 0;
        this.pointsBoard[x][y] = value;
    }

    public void setEachValueOnBoard(int value){
        for(int i=0; i<pointsBoard.length; i++){
            for(int j=0; j<pointsBoard.length; j++)
                pointsBoard[i][j]=value;
        }
    }

    public void adjustToHandling(int handlingLenght){
        this.handlingLenght = handlingLenght;
        for(int i=0; i<pointsBoard.length; i++){
            for(int j=0; j<pointsBoard.length; j++) {
                if (pointsBoard[i][j] > handlingLenght - 1)
                {
                    pointsBoard[i][j] = pointsBoard[i][j] % (handlingLenght-1);
                }
            }
        }
    }

    public  enum  Direction {
        North,South,West,East;
    }
}
