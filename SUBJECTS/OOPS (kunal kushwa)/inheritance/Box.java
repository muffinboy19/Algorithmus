package inheritance;

public  class Box {
    double l;
    double h;
    double w;

    public Box(){
    // this is the defualt constructer
        this.l = -1;
        this.h   = -1;
        this.w = -1;
    }
    // for creating a square ... thi
    // htis is going ot be sedperaet constuctor
    public Box(double side){
        this.w = side;
        this.h = side;
        this.l = side;

        // now this has become a cube
    }


    /// this is called copy constructer
    public Box(Box old){
        this.h = old.h;
        this.l = old.l;
        this.w = old.w;
    }

    public Box(double l, double h, double w) {
        this.l = l ;
        this.w  = w;
        this. h = h;
    }
}
