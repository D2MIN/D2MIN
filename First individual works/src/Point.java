public class Point {
    private double x, y;
    Point(double x, double y){
        this.x = x;
        this.y = y;
    }

    Point(){
        this.x = 0;
        this.y = 0;
    }

    public String toString() {
        return "Point{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }


}
