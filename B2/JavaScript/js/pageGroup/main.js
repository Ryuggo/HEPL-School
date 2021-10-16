function Group_NumberA() {
    document.querySelector("input#nbgrp").disabled = false;
    document.getElementById("nbgrp_text").style.color = "black";

    document.querySelector("input#nbppl").disabled = true;
    document.getElementById("nbppl_text").style.color = "gray";
    document.querySelector("input#average").disabled = true;
    document.getElementById("average_text").style.color = "gray";

    Show_Group_Names();
}

function Group_NumberB() {
    document.querySelector("input#nbgrp").disabled = true;
    document.getElementById("nbgrp_text").style.color = "gray";

    document.querySelector("input#nbppl").disabled = false;
    document.getElementById("nbppl_text").style.color = "black";
    document.querySelector("input#average").disabled = false;
    document.getElementById("average_text").style.color = "black";

    Show_Group_Names();
}



function Add_Custom(ev, typeName, typeList, type) {
    ev.preventDefault();

    let elt = document.getElementById(typeList);

    let txt = document.getElementById(typeName).value;
    if(!!txt.trim()) {
        let label = '<label>Nombre par groupe : </label><input type="number" min="1" value="1"></input>'
        let button = '<button onclick="Remove_Custom(event, this);">X</button>';

        if(type == "roles")
            elt.innerHTML += '<div class="roles"><div><h6>' + txt + '</h6>' + label + '</div>' + button + '</div>';
        else {
            elt.innerHTML += '<div class="names"><div><h6>' + txt + '</h6></div>' + button + '</div>';

            Not_Enough_Names();
        }

        document.getElementById(typeName).value = null;
    }
}

function Remove_Custom(ev, elt) {
    if(ev)
        ev.preventDefault();

    let delElt = elt.parentElement;
    elt.parentElement.parentElement.removeChild(delElt);

    Not_Enough_Names();
}



function Show_Group_Names() {
// Remove old Names
    while(document.getElementsByClassName("names").length != 0)
        Remove_Custom(null, document.getElementsByClassName("names")[0].lastChild);

    Count_Group();

    Generate_Names();

    let button = '<button onclick="Remove_Custom(event, this);">X</button>';

    for(i = 0; i < nbGroup; i++)
        document.getElementById("names_list").innerHTML += '<div class="names"><div><h6>' + names[i] + '</h6></div>' + button + '</div>';

    Not_Enough_Names();
}

function Generate_Names() {
    names = [];
    if(document.getElementById("group_name").value == "col") {
        names.push("Bleu", "Rouge", "Blanc", "Noir", "Jaune", "Vert", "Orange", "Rose", "Violet", "Gris", "Brun");
        names.sort(()=> Math.random() - 0.5);
        names.sort(()=> Math.random() - 0.5);
    } else
        for(i = 1; i <= nbGroup; i++)
            names.push(i);
}

function Not_Enough_Names() {
    let names = document.getElementsByClassName("names");
    if(names.length < nbGroup)
        document.getElementById("error_names").style.display = "block";
    else
        document.getElementById("error_names").style.display = "none";
}



function ShowStudent(elt) {
    if(elt.nextSibling.style.display == "block")
        elt.nextSibling.style.display = "none";
    else
        elt.nextSibling.style.display = "block";
}