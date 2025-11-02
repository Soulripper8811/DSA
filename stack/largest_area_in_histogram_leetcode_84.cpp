// passes the 93/99 test cases


// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int maxValue=0;
//         for(int i=0;i<heights.size();i++){
//             int curr=heights[i];
//             int left=i;
//             int right=i;
//            while(left>0 && heights[left-1]>=curr){
//             left--;
//            }
//             while(right<heights.size()-1 && heights[right+1]>=curr){
//                 right++;
//             }
//             int area=heights[i]* (right-left+1);
//             maxValue=max(maxValue,area);
//         }
//         return maxValue;

//     }
// };



    class Solution {
    private:
    vector<int>nextSmallerElement(vector<int> arr,int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(s.top()!= -1 &&arr[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;

    }
    vector<int>prevSmallerElement(vector<int> arr,int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(s.top()!= -1 &&arr[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;

    }
    public:
        int largestRectangleArea(vector<int>& heights) {
            int n=heights.size();

            vector<int> next(n);
            next=nextSmallerElement(heights,n);
            vector<int> prev(n);
            prev=prevSmallerElement(heights,n);
            int area =INT_MIN;
            for(int i=0;i<n;i++){
                int len=heights[i];
                if(next[i]==-1){
                    next[i]=n;
                }
                int  b=next[i]-prev[i]-1;
                int newArea=len*b;
                area=max(area,newArea);
            }
            return area;
        }
    };