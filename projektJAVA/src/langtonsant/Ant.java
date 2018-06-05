package langtonsant;

import java.awt.Point;

public class Ant {

    public Ant(Point startingPosition)
    {
        this.position = startingPosition;
        this.headingDirection = Direction.South;
    }

    private Point position;
    private Direction headingDirection;
    private int howOld = 0;

    private enum  Direction {
        North,South,West,East;
    }

    public void makeStep(char instruction) {
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

    public Point getPosition() {
        return position;
    }

    public int getHowOld() {
        return howOld;
    }

    public void increaseHowOld() {
        howOld++;
    }
}


