package staticPackage;

public class StatickBlock {
    static int a = 4;
    static int b;

    static {

        // this block here is usee to isntialize the static variblie
        // and appraenlty it would run only once

        /*
        More precise defination is that it would run only once
        for the first object that you have created
        after that this block would not run for the subseuqent objects

         */
        System.out.println("iam in teh static block");
        b = a * 5;
    }
    public static void main(String[] args){
        StatickBlock obj = new StatickBlock();
        System.out.println(StatickBlock.a + " " + StatickBlock.b);

        StatickBlock.b += 3;
        StatickBlock obj2 = new StatickBlock();
        System.out.println((StatickBlock.a+" "+StatickBlock.b));
    }

}
