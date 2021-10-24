const express=require('express');
const app=express();


app.get("/",(req,res)=>{
    
    res.json({"msg":"Hello, World!"});
});


//starting the server at specified port
const port = process.env.PORT || 8080;
app.listen(port,()=>{
    console.log(`Server running at port ${port}`.brightYellow.underline);
})
