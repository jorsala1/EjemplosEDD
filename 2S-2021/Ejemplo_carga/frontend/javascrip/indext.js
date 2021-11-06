
function login(){
    username = document.getElementById("Username").value
    password = document.getElementById("Password").value
    alert(username +" , "+ password)
    localStorage.setItem("json", "prueba storage");
    
}

function getStorage(){
    json_user = localStorage.getItem("json");
    alert(json_user)
}

function agregar(){
    var dato = document.getElementById("valor").value
    var ad = document.getElementById("ad").value

    var data = JSON.stringify({
        "dato": dato,
        "ad":ad
    });

    if(dato != ""){
        if(ad !=""){
            fetch('http://localhost:3000/agregar', {
                method: 'post',
                headers: {
                'Content-Type': 'application/json'
                },
                body: data
            })
                .then(response => response.json())
                .then(data => {
                    console.log(data)
                alert(data.response)
            });
        }else{
            fetch('http://localhost:3000/insertar', {
                method: 'post',
                headers: {
                'Content-Type': 'application/json'
                },
                body: data
            })
                .then(response => response.json())
                .then(data => {
                    console.log(data)
                alert(data.response)
            });
        }
    }
    

    
}

function agregar_ad(){
    var dato = document.getElementById("valor").value
    var data = JSON.stringify({
        "dato": dato
    });

    fetch('http://localhost:3000/insertar', {
        method: 'post',
        headers: {
          'Content-Type': 'application/json'
        },
        body: data
      })
        .then(response => response.json())
        .then(data => {
            console.log(data)
          alert(data.response)
        });
}

function graficar(){
    fetch('http://localhost:3000/graficar', {
        method: 'get',
        headers: {
          'Content-Type': 'application/json'
        }
      })
        .then(response => response.json())
        .then(data => {
            console.log(data)
          alert(data.response)
          img= data.img 
          document.getElementById("img").innerHTML= "<img src=\"data:image/png;base64,"+img+"\" >"
          console.log(img)
        });

}

//carga de archivos
function readSingleFile(e) {
    var file = e.target.files[0];
    if (!file) {
      return;
    }
    var reader = new FileReader();
    reader.onload = function(e) {
      var contents = e.target.result;
      displayContents(contents);
    };
    reader.readAsText(file);
  }
  
  function displayContents(contents) {
    var element = document.getElementById('carga');
    element.innerHTML = contents;
  }
  
  document.getElementById('file-input')
    .addEventListener('change', readSingleFile, false);

    function cargar(){
        var dato = document.getElementById("carga").value
        var data = dato;
    
        fetch('http://localhost:3000/cargarEstudiantes', {
            method: 'post',
            headers: {
              'Content-Type': 'application/json'
            },
            body: data
          })
            .then(response => response.json())
            .then(data => {
                console.log(data)
              alert(data.response)
            });
    }