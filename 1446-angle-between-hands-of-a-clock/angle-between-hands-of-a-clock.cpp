class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle=(30*hour)-(5.5*(double)minutes);
        
        if(angle<0.0){
            angle=-1.0*angle;
        }
        if(angle>360.0-angle){
            angle=360.0-angle;
        }

        return angle;
    }
};