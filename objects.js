// singleton object : there are no more than 1 instance of this object
// when we declare an object not like a literal
// from a constructor then a singleton

// there are key and value pairs inside an object
// object literals

const mysym  = Symbol("s1");
const jsUser = {
    name : "Shashank", // when we write name the system processes it like a string : "name"
    age : 20,
    city : "pune",
    [mysym] : "key" // this is how we use symbol as a key in js
}
 //Object.create : singleton method

// to access the values :
console.log(jsUser.name);
console.log(jsUser["name"]);
console.log(jsUser[mysym]);

//to add changes
jsUser.name = "Phiske";

// to prevent changing the values inside an object :
Object.freeze(jsUser);

const myUser = {
    name : "shashank",
    age : 20
}

// to add a function to our object :
myUser.functionname = function(){
    console.log(`Hello, ${myUser.name}`); //or console.log(this.name);
}
myUser.functionname(); // this will use the function
// myUser.functionname : this will only return the function reference

// singleton object : 
// const user = new Object();

// we can also chain our objects : objects inside another object (if the value is from an api then add ? at its end)
// ? specifies that if the value is present then only do the operation

const obj1 = {
    1:"a",
    2:"b"
}
const obj2 = {
    3:"c",
    4:"d"
}
const obj3 = Object.assign({}, obj1, obj2); // this will add all the key:value pairs in the object obj3
// {} is the target and all others are the source

// const obj3 = {...obj1, ...obj2}

// we can separate keys in an array using : Object.keys(objectname);
// we can separate values like : Object.values(objectname)
// we can convert our key:value in an array and add it to array of key:values pairs : Object.entries(objectname)
// we can check if a property exists in an object :
console.log(obj1.hasOwnProperty('1'));

// another way to access properties of our object
const {name,age} = myUser; // this is called object destructuring
console.log(name)

// json values returned by an api is also an object
/*
{ // this is how a json response looks

    "name":"shashank",
    "age":20,
    "surname":"phiske"

}
*/