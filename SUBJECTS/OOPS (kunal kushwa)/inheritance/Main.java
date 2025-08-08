package inheritance;

public class Main {
    public  static  void main(String[] args){
        Box ish = new Box(3);
        Box osh = new Box(ish);
        System.out.println(ish.l +  " " + ish.w + " " + ish.h );
        BoxWeight kesh = new BoxWeight();
        System.out.println(osh.l +  " " + osh.w + " " + osh.h );
        System.out.println(kesh.l +  " " + kesh.w + " " + kesh.weight );

        ish.greeting(); // does not require a need of ojbect
        Box.greeting();// see no objecg required




        ///////////////////////////////



        Box b1 = new Box(3.0);
        Box b2 = new BoxWeight(3.0,3.0,3.0,3.0);
        b1.greeting();
        b2.greeting();
        Box.greeting();
        BoxWeight.greeting();
        // YOU cannot be ovverwrittne you can only inherti the static method

        /*
        Here we declatred a Box type object but assined it
        a boxWeigh instace which is the chluid class of hte
        Box parent class
         */
        Box box5 = new BoxWeight();
       // System.out.println(box5 .l +  " " + box5.w + " " + box5.weight );
        /*
        The above logic would not work as
        it is not the ojbcet type we give
        but the refrence varibale type that derteminces
        what we will be able to acess or not
        so here we can acerss w ,l , h
        but not the wiegih as for it the box5 is Box whcih does
        not have a the weight declaration
         */

        /*
        Tjhe opp also do not work as
        the paretn class has no idea about the child class
        when oppostie we are calling the child class constructer
        and since parent class has not idea for it thus it is giving the error

         */



        /// super
        /*
        1.                   when you write the super keyword in the parent class
            it will point to the java implkemetioan of the object class ()
        2. super means direclty above it
        3. to calll the const4ructer
        4. can be used as "this" but onluy the parent class paramter for
        5. used to acces the parent class declartion direclty
           which are the ones direclty agbove it
         */
    }
}
