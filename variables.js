const accountId = 12;
let accountEmail = "ssp@gmmail.com";
var accountPass = "12345";
accountCity = "Pune";

// we cannot change the value of const variable
// we use let rather than var because var had issues of scopes, let solves this issue
// the 4th one is just a way that we can also use

console.table([accountEmail, accountId, accountPass, accountCity]); // prints in tabular format