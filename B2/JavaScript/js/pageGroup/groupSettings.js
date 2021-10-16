var jsonObject;

var listStudent;
var nbGroup = 0;
var nbStudent = 0;
var nbStudentMin = 0;

var groups;

var names;

var roles;

var criteres;


function Generate() {
    Count_Group();

    Detect_Name();

    Detect_Roles();

    Detect_Criteres();

    Create_Group();

    Create_JSON();

    Show_Data();
}


function Detect_Min() {
    listStudent = Object.keys(rowObject).length;

    nbStudent = document.getElementById("nbppl").value;
    nbGroup = Math.ceil(listStudent / nbStudent);
    nbStudentMin = nbStudent - Math.floor(listStudent / nbGroup);

    let elt = document.getElementById("average");

    elt.min = nbStudentMin;
    elt.value = nbStudentMin;
}
function Count_Group() {
    if(rowObject != null)
        listStudent = Object.keys(rowObject).length;

    if(document.getElementById("nbA").checked == true) {
        nbGroup = document.getElementById("nbgrp").value;
        if(50 < nbGroup) {
            nbGroup = 50;
            document.getElementById("nbgrp").value = 50;
        }
        nbStudentMin = Math.floor(listStudent / nbGroup);
        nbStudent = Math.ceil(listStudent / nbGroup);
    } else {
        nbStudent = document.getElementById("nbppl").value;
        if(100 < nbStudent) {
            nbStudent = 100;
            document.getElementById("nbppl").value = 100;
        }
        nbGroup = Math.ceil(listStudent / nbStudent);
        nbStudentMin = nbStudent - document.getElementById("average").value;
    }
}

function Detect_Name() {
    names = [];
    let elt = document.getElementsByClassName("names");

    for(i = 0; i < nbGroup; i++) {
        if(i < elt.length)
            names.push(elt[i].firstChild.firstChild.textContent);
        else
            names.push(i+1);
    }
}

function Detect_Roles() {
    let elt = document.getElementsByClassName("roles");
    roles = [];

    for(i = 0; i < elt.length; i++) {
        let item = {};
        item["Role"] = elt[i].firstChild.firstChild.textContent;
        item["Qtt"] = elt[i].firstChild.lastChild.value;

        roles.push(item);
    }
}

function Detect_Criteres() {
    criteres = [];
    let elt = document.getElementsByClassName("criteres");

    for(i = 0; i < elt.length; i++)
        if(elt[i].lastChild.value == "sep") {
            criteres[elt[i].lastChild.id] = [];
            for(j = 0; j < listStudent; j++)
                if(rowObject[j][elt[i].lastChild.id] != "")
                    criteres[elt[i].lastChild.id][criteres[elt[i].lastChild.id].length] = rowObject[j];
        }
    
    criteres["None"] = [];
    for(i = 0; i < listStudent; i++) {
        let ok = true;
        for(var key in criteres)
            if(key != "None" && rowObject[i][key] != "") {
                ok = false;
                break;
            }
        
        if(ok == true)
            criteres["None"][criteres["None"].length] = rowObject[i];
    }
}

function Create_Group() {
    groups = [];

    for(i = 0; i < nbGroup; i++)
        if(!groups[i])
            groups[i] = [];

    let j = 0;
    for(var key in criteres)
        if(key != "None") {
            for(k = 0; k < criteres[key].length; k++) {
                if(!groups[j])
                    groups[j] = [];

                if(groups[j].length < nbStudent)
                    groups[j][groups[j].length] = criteres[key][k];
                else
                    j++;
            }
            j++;
        }

    for(i = 0; i < criteres["None"].length; i++)
        while(1) {
            let rand = Math.floor(Math.random() * nbGroup);

            if(!groups[rand])
                groups[rand] = [];

            if(groups[rand].length < nbStudent) {
                groups[rand][groups[rand].length] = criteres["None"][i];
                break;
            }
        }

// Balance Group
    for(i = 0; i < nbGroup; i++) {
        for(k = 0; k < nbGroup && groups[i].length < nbStudentMin; k++) {
            if(nbStudentMin < groups[k].length) {
                let ok = true;
                for(var key in criteres)
                    if(key != "None" && groups[k][groups[k].length-1][key] != "") {
                        ok = false;
                        break;
                    }
                
                if(ok == true) {
                    groups[i][groups[i].length] = groups[k][groups[k].length-1];
                    groups[k].splice(groups[k].length-1, 1); 
                }
            }
        }
    }
}

function Create_JSON() {
    jsonObject = [];
    for(i = 0; i < nbGroup; i++) {
        let r = [];
        for(k = 0; k < roles.length; k++)
            r[k] = 0;

        for(j = 0; j < groups[i].length; j++) {
            let item = {};

            // Nom des groupes
            item["Groupe"] = names[i];

            // Infos des Etudiants
            for(var key in groups[i][j])
                item[key] = groups[i][j][key];

            // Rajouter les rôles
            for(k = 0; k < roles.length; k++) {
                let rand = Math.floor(Math.random() * (groups[i].length - j - (roles[k].Qtt - 1)) + 1);
                if(rand < 1)
                    rand = 1;
                //(rand < 1)?rand = 1: null;

                if(rand == 1 && r[k] < roles[k].Qtt) {
                    item[roles[k].Role] = "x";
                    r[k]++;
                } else
                    item[roles[k].Role] = "";
            }

            jsonObject.push(item);
        }
    }
    //console.log(jsonObject);
}

function Show_Data() {
// Show Students Groups
    document.getElementById("student_list").innerHTML = "";

    let button = "<div class='student_group_name' onclick='ShowStudent(this);'>"

    for(i = 0; i < nbGroup; i++)
        document.getElementById("student_list").innerHTML += "<div>" + button + "<h5>" + names[i] + "_</h5>-- " + groups[i].length + "</div><div class='student_group'></div></div>";

    for(i = 0, k = 0; i < nbGroup; i++, k = j)
        for(j = k; j < groups[i].length + k; j++)
            document.getElementsByClassName("student_group")[i].innerHTML += "<div>" + jsonObject[j].Nom + " " + jsonObject[j].Prénom + "</div>";

    document.getElementsByClassName("student_group")[0].style.display = "block";


// Show Export Button
    document.getElementById("export").classList.add("btn");
    document.getElementById("export").classList.add("div-btn");
    document.getElementById("export").textContent = "Exporter";
}