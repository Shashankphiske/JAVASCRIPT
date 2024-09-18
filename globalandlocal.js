let a = 10
var b = 20
const c = 30

if (true){
    let a = 30
    var b = 10
    const c = 20
}

console.log(a)
console.log(b)
console.log(c)
// when we use var data variable it doesnt respect the local and global scope
// it can be accessed anywhere