public class Circle {
    double radius;
    Point point;
    public Circle(Point point, double radius) {
        this.point = point;
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public Point getPoint() {
        return point;
    }

    public void setPoint(Point point) {
        this.point = point;
    }

    @Override
    public String toString() {
        return "Circle{" +
                "radius=" + radius +
                ", point:" + " x= " + point.getX() +
                " y= " + point.getY() +
                '}';
    }

    public double P_Circle(){
        return 2*Math.PI*radius;
    }

    public double S_Circle(){
        return Math.PI*radius*radius;
    }
}
