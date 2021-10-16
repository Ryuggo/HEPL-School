function ListNames(data) {
    let elt = document.getElementById("student_list");
    elt.innerHTML = "";

    for(i = 0; i < Object.keys(data).length; i++)
        elt.innerHTML += "<div>" + data[i].Nom + " " + data[i].Prénom + "</div>";
}

function ListCriteres(data) {
    let elt = document.getElementById("criteres");
    elt.innerHTML = "";

    let option1 = '<option value="no" selected>Ne pas prendre en compte</option>';
    let option2 = '<option value="sep">Réunir ensemble</option>';

    for(var key in data[0])
        if(key != "Nom" && key != "Prénom")
            elt.innerHTML += '<div class="criteres"><label for="' + key + '"><h6>' + key + ' : </h6></label>' + '<select id="' + key + '" >' + option1 + option2 + '</select></div>';
}