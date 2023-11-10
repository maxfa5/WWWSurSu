function myf() {
    let text1 = document.getElementsByClassName("glavTravelPro");
    let footer = document.getElementsByClassName("stolb");
    // this.classList.toggle("night");
    // this.classList.toggle("day");
    document.body.classList.toggle("night");
    text1[0].classList.toggle("nightText");
    for (let i = 0; i < footer.length; i++) {
        footer[i].classList.toggle("nightText");
    }
}
let swithTheme = document.getElementById("nightVision");
swithTheme.addEventListener("click", myf);
