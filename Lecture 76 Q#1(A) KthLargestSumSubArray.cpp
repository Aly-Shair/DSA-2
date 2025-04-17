//Approach # 1
class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        
        vector<int> sumStore;
        
        for(int i = 0; i < N; i++){
            int sum = 0;
            for(int j = i; j < N; j++){
                sum += Arr[j];
                sumStore.push_back(sum);
            }
        }
        
        sort(sumStore.begin(), sumStore.end(), greater<int>());

        return sumStore[K-1];
    }
};
