const express = require('express');
const app = express();

app.get('/', (req, res) => {
    res.send("Welcome to MCA DEPARTMENT");
});

app.post('/postdata', (req, res) => {
    res.send("Received a POST request");
});


app.listen(4000, () => {
    console.log("Listening to port 4000");
});
