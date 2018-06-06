package projectlangtonant;

import java.awt.*;

/**
 *  Klasa zajmujaca sie obsluga tablicy po ktorej poruszaja sie mrowki
 */
public class Board {
    /**
     * Tablica 2 wymiarowa po ktorej poruszaja sie mrowki
     */
    private int[][] pointsBoard;
    /**
     *  Długosc sterownia ustawionego domyslnie lub przez uzytkownika
     */
    private int handlingLenght;

    /**
     * Konstruktor klasy board
     * @param x rozmiar planszy
     */
    public Board(int x) {
        this.pointsBoard = new int[x][x];
        setEachValueOnBoard(0);
    }

    /**
     * Metoda dostepowa get na konkretny punkt planszy ( x, y )
     * @param x pozycja x punktu, ktorego chcemy poznac wartosc
     * @param y pozycja y punktu, ktorego chcemy poznac wartosc
     * @return wartosc tablicy, która kryje się pod miejscem (x,y)
     */
    public int getPointsBoard(int x, int y) {
        return pointsBoard[x][y];
    }

    /**
     * Ustawia wartosc value na porządanej pozycji (x,y)
     * @param x pozycja x, ktorej chcemy zmienic wartosc
     * @param y pozycja y, ktorej chcemy zmienic wartosc
     * @param value wartosc na jaka chcemy zmienic dane pole na planszy
     */
    public void setOneValuePointsBoard(int x, int y, int value) {
        if(value > handlingLenght-1) value = 0;
        this.pointsBoard[x][y] = value;
    }

    /**
     * Ustawia value na kazdym polu na planszy
     * @param value wartosc jaka chcemy ustawic na kazdym polu na planszy
     */
    public void setEachValueOnBoard(int value){
        for(int i=0; i<pointsBoard.length; i++){
            for(int j=0; j<pointsBoard.length; j++)
                pointsBoard[i][j]=value;
        }
    }

    /**
     * Zmienia wartosc na planszy tak, zeby zgadzala sie ze sterowaniem
     * @param handlingLenght dlugosc instrukcji sterowania
     */
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

    /**
     * Metoda dostepowa get na rozmiar planszy
     * @return zwraca rozmiar planszy
     */
    public int getSize(){
        return pointsBoard.length;
    }

    /**
     * Zwyczajny enum dla latwiejszego okreslenia kierunku mrowki.
     *
     * Nazwa kierunku odpowiada angielskim słowom określającym kierunek.
     */
    public  enum  Direction {
        North,South,West,East
    }
}
