// Last updated: 6/20/2026, 5:07:34 PM
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double MinAngle = minutes * 6;
        double HourAngle = (hour %12) * 30 + minutes *0.5;
        double diff = abs(HourAngle - MinAngle) ;
        return min(diff, 360.0 - diff);
    }
};