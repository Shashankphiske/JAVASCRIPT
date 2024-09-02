// toFixed : to define numbers after a decimal
const score = new Number(100);
const num = 29.34234234;

console.log(score.toFixed(2)); // will have 2 0 after the decimal
console.log(num.toPrecision(3)); // it will apply precision on 3 values that is 29.3 but if 123.something then 123 is three values
                                 // so answer will be 123

const hundreds = 1000000000;
console.log(hundreds.toLocaleString()); // will return the value with commas, bu default it is us styled

// we have a math object in js
