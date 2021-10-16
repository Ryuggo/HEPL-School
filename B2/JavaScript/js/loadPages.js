function Page_Lists(ev) {
    document.getElementById('Saved_Lists').style.display = "block";
    document.getElementById('Make_Group').style.display = "none";
}

function Page_Groups() {
    document.getElementById('Saved_Lists').style.display = "none";
    document.getElementById('Make_Group').style.display = "flex";

    Show_Group_Names();
}