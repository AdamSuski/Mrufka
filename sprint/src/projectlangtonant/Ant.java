package projectlangtonant;

import java.awt.*;
import java.io.Console;

import projectlangtonant.Board.Direction;

/** Klasa zawierajaca caly algorytm dzialania mrowki
 *
 * Ta klasa odpowiada za powstawanie i zmienianie pozycji mrowki
 */
public class Ant {
    /**
     *  Point, ktory posiada informacje o pozycji mrowki
     */
    private Point position;
    /**
     * Zmienna posiada informacje o aktualnym kierunku mrowki
     */
    private Board.Direction headingDirection;
    /**
     * String, ktory posiada informacje  o aktualnym sterowaniu mrowki
     */
    private String handling;
    /**
     * Zmienna posiada informacje o aktualnym stanie zycia mrowki
     *
     * Oczywiste ze kazda mrowka na poczatku jest zywa, wiec jej smierc jest nieprawda
     * W przypadku uderzenia w sciane boolean jest zmieniany na true
     */
    public boolean dead = false;

    /**
     * Prosty konstruktor mrowki
     *
     * Jest tworzony Point o wspolrzednych (x,y)
     *
     * @param x pozycja x mrowki
     * @param y pozycja y mrowki
     * @param direction kierunek w jakim ustawiona jest mrowka
     * @param handling sterowanie jakie jest ustawione dla mrowki
     */
    public Ant(int x, int y, Direction direction, String handling) {
        this.position = new Point (x,y);
        this.headingDirection = direction;
        this.handling = handling;
    }

    /**
     * Get na pozycje x mrowki
     * @return zwraca pozycje x mrowki
     */
    public int getAntX(){
        return position.x;
    }
    /**
     * Get na pozycje y mrowki
     * @return zwraca pozycje y mrowki
     */
    public int getAntY(){
        return position.y;
    }

    /**
     * Ustawienie sterowania mrowki
     * @param handling nowe sterowanie dla mrowki
     */
    public void setHandling(String handling) {
        this.handling = handling;
    }
    /**
     * Funkcja sprawdza czy mrowka opuscila plansze
     *
     * W przypadku gdy mrowka opusci plansze jej stan ustawiany jest na smierc i przestaje sie poruszac
     */
    private void ifOutOfBoardChangeXY(){
        if(getAntX()<0 || getAntX()>149 || getAntY()<0 || getAntY()>149) {
            dead = true;
        }
    }

    /**
     * Glowna funkcja, ktora odpwiada za zmiane pozycji mrowki
     *
     * Na poczatku sprawdzany jest kierunek w jakim ustawiona jest mrowka.
     * Nastepnie w zaleznosci od kierunku i aktualnej instrukcji sterowania zmienai sie odpowiednia ( x lub y ) pozycja mrowki.
     * Zmianie oczywiscie ulega tez kierunek w jakim znajduje sie mrowka.
     *
     * @param instruction odpowiednia instrukcja wedlug ktorej mrowka sie porusza
     */
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
        /**
         * Sprawdzane jest czy pozycja mrowki znajduje sie poza plansza
         * {@link Ant#ifOutOfBoardChangeXY()}
         */
        ifOutOfBoardChangeXY();
    }

    /**
     * Funkcja wywoluje ruch mrowki
     * @param value aktualny stan pola na ktorym znajduje sie mrowka
     */
    public void antMovement( int value ){
        if(value>handling.length()-1)
            value=0;
        makeStep(handling.charAt(value));
    }

    /**
     * Zwraca wartosc dead
     * @return zwraca wartosc zmiennej dead mrowki {@link Ant#dead}
     */
    public boolean checkIfDead(){
        return dead;
    }
}
