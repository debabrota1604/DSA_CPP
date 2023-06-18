class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int res=0, topup=5;
        while(mainTank>0){
            res+=10;
            topup--;
            mainTank--;
            if(topup==0 && additionalTank>0){
                mainTank++; 
                additionalTank--;
                topup+=5;
            }
        }
        return res;
    }
};
