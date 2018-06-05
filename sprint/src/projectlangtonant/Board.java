package projectlangtonant;

import java.awt.*;

public class Board {
    private int[][] pointsBoard;

    public Board(int x) {
        this.pointsBoard = new int[x][x];
        setEachValueOnBoard(0);
    }

    public int getPointsBoard(int x, int y) {
        return pointsBoard[x][y];
    }

    public void setOneValuePointsBoard(int x, int y, int value) {
        this.pointsBoard[x][y] = value;
    }
    public void setEachValueOnBoard(int value){
        for(int i=0; i<pointsBoard.length; i++){
            for(int j=0; j<pointsBoard.length; j++)
                pointsBoard[i][j]=value;
        }
    }
}
