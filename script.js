function myf() {
    let text1 = document.getElementsByClassName("glavTravelPro");
    let footer = document.getElementsByClassName("stolb");
    document.body.classList.toggle("night");
    text1[0].classList.toggle("nightText");
    for (let i = 0; i < footer.length; i++) {
        footer[i].classList.toggle("nightText");
    }
}
let swithTheme = document.getElementById("nightVision");
swithTheme.addEventListener("click", myf);


function del() {
    div.remove();
}

let object = document.getElementById("travelPro");
let div = document.createElement('div');
let divClose = document.createElement('button');
let p = document.createElement("p");
p.innerHTML= "addStolb";
div.classList.toggle("stolb");
divClose.classList.toggle("closeJS");
const el = document.querySelector(".footer");
div.append(p);
 p = document.createElement("p");
p.innerHTML= "addStolb";
div.append(p);
 p = document.createElement("p");
p.innerHTML= "addStolb";
div.append(p);
 p = document.createElement("p");
p.innerHTML= "addStolb";
div.append(p);
div.append(divClose);
el.append(div);
div.id = 'div-02';

div = document.getElementById("div-02");
divClose.addEventListener("click", del);
