let date = new Date(); // we created a date object

console.log(date);
console.log(date.toString()); // this will make it more elaborate

let mydate = new Date(2024, 0, 1); // here we created a date object with our date
                                   // here 0 is the month, months start from 0 and go to 11
// can also decalre like : "2024-01-1" here we gave the 01 number to the january month
console.log(mydate.toDateString());

let mytime = Date.now(); // this will give current time and date in millisecond
console.log(mytinme);
console.log(mydate.getTime());  // conversion of our date in milliseconds

// .toLocaleString() is used to define our date and time

date.toLocaleString('default', {
    weekday : "long",
    // etc
});