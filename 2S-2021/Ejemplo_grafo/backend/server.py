from flask import Flask, request,jsonify
from flask_cors import CORS
import base64 #para convertir la imagen y responderla al frontend
from EDD import grafo

app=Flask(__name__)
app.config['CORS_HEADERS'] = 'Content-Type'
cors = CORS(app)

grafo1= grafo()

@app.route('/insertar', methods=['POST'])
def insertar():
    if request.method == 'POST':
        valor = request.json['dato']
        grafo1.insertar(valor)
        response = jsonify({'response': 'se agrego el '+valor})
        print("metodo post")
        return response

@app.route('/agregar', methods=['POST'])
def agregar():
    if request.method == 'POST':
        valor = request.json['dato']
        ad = request.json['ad']
        grafo1.agregar_adyasente(valor,ad)
        response = jsonify({'response': 'se agrego: -'+valor+' -> '+ad})
        print("metodo post")
        return response
    
@app.route('/graficar', methods=['GET'])
def prueba():
    grafo1.graficar()
    b64_string=""
    with open("graph-g.png", "rb") as img_file:
        b64_string = base64.b64encode(img_file.read())

    #print(str(b64_string.decode('utf-8')))
    response = jsonify({'response': 'se grafico', 'img': str(b64_string.decode('utf-8'))})

    return response

if __name__ == '__main__':
    app.run(port=3000, debug=True)