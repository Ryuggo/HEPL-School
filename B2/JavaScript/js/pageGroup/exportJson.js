function Export_File() {
    let columns = [];
    let rows = [];
    
    var doc = new jsPDF('p', 'pt');

    for(var key in jsonObject[0])
        columns.push(key);


    for(i = 0; i < jsonObject.length; i++) {
        let tmp = [];
        for(var key in jsonObject[i])
            tmp.push(jsonObject[i][key]);
        rows.push(tmp);
    }
    
    doc.autoTable(columns, rows, {
        pageBreak: "always"
    });
    
    doc.save("Groupe d'Etudiants.pdf");
}