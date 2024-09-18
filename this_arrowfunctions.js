// this keyword is used to apply current context
// eg:
const person = {
    name:"Shashank",
    age:20,

    message: function(){
        console.log(`${this.name} welcome`);
        console.log(this);
    }
}
person.message();

const arrow_function = () => {
    console.log("arrow function");
}
