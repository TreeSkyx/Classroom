var i = 0;
function myTimer() {
    postMessage(Date());
}
setInterval(myTimer, 1000); 
