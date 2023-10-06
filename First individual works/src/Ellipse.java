public class Ellipse {
    double a,b;
    Circle circle;
    public Ellipse(double a, double b, Circle circle) {
        this.a = a;
        this.b = b;
        this.circle = circle;
    }

    public double getA() {
        return a;
    }

    public void setA(double a) {
        this.a = a;
    }

    public double getB() {
        return b;
    }

    public void setB(double b) {
        this.b = b;
    }

    public Circle getCircle() {
        return circle;
    }

    public void setCircle(Circle circle) {
        this.circle = circle;
    }

    @Override
    public String toString() {
        return "Ellipse{" +
                "a=" + a +
                ", b=" + b +
                ", circle=" + circle +
                '}';
    }

    public double P_Ellipse(){
        return 2*Math.PI*Math.sqrt((a*a+b*b)/2);
    }

    public double S_Ellipse(){
        return a*Math.PI*b;
    }
}
