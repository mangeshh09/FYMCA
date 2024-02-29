function asyncFunction() {

    return new Promise((resolve,reject)=>
     {
        setTimeout(()=>
        {
            let success = true;
            if(success){
                console.log('4 sec');
                resolve();                                             
            }
            else {
                reject();
            }
        },4000);

        setTimeout(()=>
        {
            let success = true;
            if(success){
                console.log('1 sec');
                resolve();                                             
            }
            else {
                reject();
            }
        },1000);
    });     
}

asyncFunction()
.then(result=>{
    console.log("Resolve executed successfully");
})

.catch(error=>{
    console.log("Reject executed  successfully");
});