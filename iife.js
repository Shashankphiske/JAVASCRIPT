// IIFE : immediately invoked function expressions
// to address the problem of pollution of global scope elements we use IIFE

(
    function shashank(){ // named iife
        console.log("IIFE");
    }
)();

(
    (name) => { // unnamed iife
        console.log(`arrow function ${name}`)
    }
)("shashank");

// here first () is the function definition and second () is the function call
// notice that we havent called the function, it is already invoked