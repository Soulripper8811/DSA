/**
 * @param {number[]} nums
 * @return {number[]}
 */
var getSneakyNumbers = function(nums) {
    let numberObj={};
    let ans=[];
    for(let i=0;i<nums.length;i++){
        if(numberObj.hasOwnProperty(nums[i])){
            ans.push(nums[i])
            if(ans.length===2){
                break;
            }
        }
        else{
            numberObj[nums[i]]=true;
        }
    }
    return ans;
};