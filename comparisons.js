console.log("2" > 1); // this will return true because js will convert this string into a number

// null value is always >= 0 because comparison operators like >= <= convert null into a 0

// === this is strict check, it will not only check the values but their data types as well

// Primitive :
// String, Number, Boolean, Null, Undefined, Symbol, BigInt

// Non Primitive or reference type :
// Array, Objects, Functions

// javascript is a dynamically typed language
// a symbol is used to make an element unique
// objects are inside curly braces with key value pairs

let myObj = {
    name : "Shashank",
    age : 20
}

// the typeof operator gives object as result for any null value

// Types of memory :
// Stack and Heap memory

// all the primitive types use stack memory, non primitive use heap memory
// when we access a primitive data type we get a copy of the original, when we access the non primitive one we get a reference

