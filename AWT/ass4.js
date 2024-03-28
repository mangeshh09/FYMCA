//Design a simple API using Express.js
const express=require('express');
const app=express();
app.get('/',(req,res)=>{
    res.send("welcome to kkwagh");
});
app.listen(4000,()=>{
    console.log("listening to port 4000");
});
