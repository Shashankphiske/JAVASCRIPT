// for of loop
const arr = [1,2,3,4,5];
for (const i of arr){
    console.log(i);
}// can also work in strings, arrays etc

// maps : object which stores key, values pairs; it doesnt duplicate an entry; it remembers the order of entry

const map = new Map()
map.set("IN", "INDIA");
map.set("US", "UNITED STATES");
for (const [key, value] of map){
    console.log(key);
}
// map is iterable but object isnt

// for in loop ; object iterable
const myObj = {
    name:"shashank",
    age : 20
}
for(const i in myObj){
    console.log(i)
}

// for each
const myarr = [1,2,3,4,5,6]
myarr.forEach( function (item) {
    console.log(item)
} );
myarr.forEach((i) => {
    console.log(i)
})
// or we can directly enter a function inside forEach which we have declared earlier
// for each doesnt return a value