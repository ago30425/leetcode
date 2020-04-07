int minEatingSpeed(int* piles, int pilesSize, int H){
    unsigned int left = 1, right = 0, mid;
    unsigned int h;
    int i;
    
    for (i = 0; i < pilesSize; ++i) {
        if (piles[i] > right)
            right = piles[i];
    }

    while (left < right) {
        mid = (left + right) / 2;
        
        h = 0;
        for (i = 0; i < pilesSize; ++i) {
            h += (piles[i] - 1) / mid + 1;
        }
        
        if (h > H)
            left = mid + 1;
        else
            right = mid;
    }
    
    return left;
}