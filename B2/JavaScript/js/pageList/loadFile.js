var rowObject;
var jsonObject;

function XlsImport(ev) {
    var file = ev.target.files[0];

    var fileName = file.name.split('.').slice(0, -1).join('.');

    if(file) {
        let fileReader = new FileReader();
        fileReader.readAsBinaryString(file);
        
        fileReader.onload = (event)=> {
            let data = event.target.result;
            let workbook = XLSX.read(data, {type:"binary"});

            workbook.SheetNames.forEach(sheet => {
                rowObject = XLSX.utils.sheet_to_row_object_array(workbook.Sheets[sheet]);
                jsonObject = JSON.stringify(rowObject);


                request = new XMLHttpRequest();
                if(!request) {
                    alert('Abandon');
                    return false;
                }

                request.onreadystatechange = function(){
                    if (request.readyState == XMLHttpRequest.DONE)
                        if (request.status == 200) 
                            console.log("Requête terminée");
                    else
                        console.log("Requête en cours");
                }

                request.open("POST", "php/uploadFile.php", true);
                request.setRequestHeader("Content-type", "x-www-form-urlencoded");


// File upload isn't woriking
                var string = "request=" + encodeURIComponent("INSERT INTO jsonFiles VALUES (NULL, '"+ fileName +"', '"+ rowObject +"')");
                request.send(string);
                //console.log(string);

                //request.send("json=" + encodeURIComponent(rowObject) + "&name=" + encodeURIComponent(fileName));


                ListNames(rowObject);
                ListCriteres(rowObject);
            });
            Page_Groups();
        }
    }
}