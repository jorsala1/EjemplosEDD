from analizador.lexico import tokens

# dictionary of names
names = {}

def p_statement_group(t):
    'statement : LQUESTION TELEMENTS RQUESTION elementos LQUESTION DOLAR TELEMENTS RQUESTION'
    #print('ok')
    #print(t[4])
    t[0]=t[4]
def p_elementos_group(t):
    """elementos : elementos elemento
                 | elemento
    """
    try:
        t[1].append(t[2])
        t[0]=t[1]
    except:
        t[0]=[]
        t[0].append(t[1])

def p_elemento(t):
    'elemento : LQUESTION TELEMENT  tipoElemento RQUESTION items LQUESTION DOLAR TELEMENT RQUESTION'
    
    obj = {
        "type": t[3],
        "atributos":t[5]
    }
    t[0]=obj
    # print("\n -> ")
    #print(obj)
    #print("\n")

def p_tipoElemento(t):
    """tipoElemento : TTYPE EQUALS NORMSTRING
    """
    t[0]= t[3].replace("\"","")

def p_items(t):
    """items : items item
             | item
    """
    try:
        t[1].append(t[2])
        t[0]=t[1]
    except:
        t[0] =[]
        t[0].append(t[1])


def p_item(t):
    """item : LQUESTION TITEM tipeItem EQUALS valueItem DOLAR RQUESTION
    """
    ob ={
        t[3].replace("'",""):t[5]
    }

    t[0]=ob 
    
    #print("\n -> ")
    #print(ob)
    #print("\n")

def p_valueItem(t):
    """valueItem : NORMSTRING
                 | NUMBER
                 """
    t[0] = t[1]

def p_tipeItem(t):
    """tipeItem : TCARNET
                | TDPI
                | TNOMBRE
                | TCARRERA
                | TPASSWORD
                | TCREDITOS
                | TEDAD
                | TDESCRIPCION
                | TMATERIA
                | TFECHA
                | THORA
                | TESTADO
                """
    t[0]=t[1]

def p_error(t):
    print("Syntax error at '%s'" % t.value)

import ply.yacc as yacc
parser = yacc.yacc()