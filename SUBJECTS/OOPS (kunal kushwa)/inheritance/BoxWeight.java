package inheritance;

import org.w3c.dom.ls.LSOutput;

public class BoxWeight extends  Box{
    double weight = 332.0f;

    public BoxWeight(){
        this.weight = -1;
    }
    public BoxWeight(double l , double h, double w,double weight){
        super(l,h,w);
        //  here we are goign to calsl the parent class
        // constuctor

        /*
        the super is used here to intili9ze the values
        from the parent class
         */
        this.weight = weight;
    }
    // it wont be able to acess the private
    /*
    decareaiotn fo hte parent class only the pulic declration would
    be allowed
     */
    static  void greeting(){
        /*
        it does not make sene to ovveriede any static function in the child class
        as it would run despite any presene of an ojbect if it is being inherited
         */
        System.out.println("Hey I am in the BoxWeight Class");
    }
    BoxWeight(BoxWeight ish){
        super(ish);
        /// this is true because it will itlize all teh box tupes things
        //
        weight = ish.weight;
    }


}
