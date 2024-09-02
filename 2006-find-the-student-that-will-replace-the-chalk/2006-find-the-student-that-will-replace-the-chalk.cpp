class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(int i=0;i<chalk.size();i++){
            sum+=chalk[i];
        }
        cout<<sum<<" ";
        k=k%sum;
        cout<<k;
        int i;
        for(i=0;i<chalk.size();i++){
            if(chalk[i]>k) break;
            k-=chalk[i];
        }
        return i;
    }
};