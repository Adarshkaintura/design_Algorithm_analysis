int minSteps(int d) {
        d=abs(d);
        int step=0;
        int sum=0;
        while(sum<d || abs(sum-d)%2!=0){
            step++;
            sum+=step;
        }
        return step;
    }
