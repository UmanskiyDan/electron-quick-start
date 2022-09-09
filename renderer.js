// var addon = require('bindings')('addon.node');
// import { CelToFarh } from "./build/Release/addon.node";
// const addon = require('./build/Release/addon');
// import addon from './build/Release/addon.node';

function celciusToFahrenheit(){
    let celcius = +document.getElementById('celcius').value;
    let fahrenheit = (celcius* 9/5) + 32;
    document.getElementById('fahrenheit').value = fahrenheit;
}

function fahrenheitToCelcius(){
    let fahrenheit = +document.getElementById('fahrenheit').value;
    let celcius = globalThis.TempConvert.CelToFarh(fahrenheit);    
    document.getElementById('celcius').value = celcius;
}