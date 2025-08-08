package AcessControl;

public class A {
    private int num;
    String name;
    int[] arr;

    /*
    By default it means that we are not able to acess it outside the package

     */

    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
    }

    public A(int num, String name) {
        this.num = num;
        this.name = name;
        this.arr = new int[34];
    }
}
