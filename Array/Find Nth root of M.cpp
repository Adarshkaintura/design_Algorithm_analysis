	int NthRoot(int n, int m)
	{
	    if(n==1){
	        return m;
	    }
	    if(m==1){
	        return 1;
	    }
	    int l=2;
	    int h=m-1;
	    int ans=-1;
	   while (l <= h) {
            int md = l + (h - l) / 2;
            long long an = 1; // Use long long to prevent overflow

            // Calculate md^n without using pow to avoid precision issues
            for (int i = 0; i < n; ++i) {
                an *= md;
                if (an > m) {
                    break; // No need to continue if we already exceed m
                }
            }

            if (an == m) {
                return md;
            } else if (an < m) {
                l = md + 1;
            } else {
                h = md - 1;
            }
        }

        return ans;
	}  
