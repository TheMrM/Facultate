function toggleMenu () {
    var el = document.getElementById("mobile");
    if (el.style.display == "block") {
        el.style.display = "none";
        document.body.style.overflow = "auto";
    } 
    else
    {
        el.style.display = "block";
        document.body.style.overflow = "hidden";
    }
}