const {calc} = require("./build/Release/addon.node");

function celciusToFahrenheit(){
    let celcius = +document.getElementById('celcius').value;
    let fahrenheit = (celcius* 9/5) + 32;
    document.getElementById('fahrenheit').value = fahrenheit;

}

function fahrenheitToCelcius(){
    let fahrenheit = +document.getElementById('fahrenheit').value;
    let celcius = calc(fahrenheit);
    document.getElementById('celcius').value = celcius;
}
