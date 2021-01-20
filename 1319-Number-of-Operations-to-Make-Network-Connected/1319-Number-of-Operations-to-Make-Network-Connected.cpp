class Solution {
private:
    int *computerSet;
    
    void SetInit(int n) {
        for (int i = 0; i < n; ++i) {
            computerSet[i] = i;
        }
    }
    
    int SetFind(int n) {
        if (computerSet[n] == n) {
            
            return n;
        }
        
        computerSet[n] = SetFind(computerSet[n]);
        
        return computerSet[n];
    }
    
    void SetUnion(int x, int y) {
        int set1, set2;
        
        set1 = SetFind(x);
        set2 = SetFind(y);
        
        if (set1 != set2)
            computerSet[set1] = set2;
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int i;
        int nbNeedCables = 0;

        /* No computer. */
        if (n <= 0)
            return 0;
        
        /* The number of cables is not enough. */
        if (connections.size() < n - 1)
            return -1;

        computerSet = (int *)malloc(n * sizeof(int));
        if (!computerSet) {
            nbNeedCables = -1;
            
            goto exit;
        }

        SetInit(n);
        
        for (i = 0; i < connections.size(); ++i) {
            SetUnion(connections[i][0], connections[i][1]);
        }
        
        for (i = 0; i < n; ++i) {
            if (computerSet[i] == i)
                ++nbNeedCables;
        }
        
        --nbNeedCables;

exit:
        if (computerSet) free(computerSet);

        return nbNeedCables;
    }
};