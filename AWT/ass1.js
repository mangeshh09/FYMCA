const arr1=[1,2,3,4,5];
const arr2=[5,4,3,2,1];
const arr3=[1,3,2,5,4];
function checkarray(arr)
{
    let ascending=true;
    let descending=true;
    for(let i=0;i<arr.length-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            ascending=false;
        }
        if(arr[i]<arr[i+1])
        {
            descending=false;
        }
    }
    if(ascending){
        return 1;
    }
    else if(descending)
    {
        return -1;
    }else{
        return 0;
    }
}
console.log("This Array"+arr1+" is ascending ="+checkarray(arr1));
console.log("This Array " +arr2+" is descending ="+ checkarray(arr2));
console.log("This Array "+arr3+" is unsorted ="+checkarray(arr3));