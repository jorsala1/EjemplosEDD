
function login(){
    username = document.getElementById("Username").value
    password = document.getElementById("Password").value
    alert(username +" , "+ password)
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
          document.getElementById("img").innerHTML= "<img src=\"data:image/png;base64,"+img+"\">"
          console.log(img)
        });

}