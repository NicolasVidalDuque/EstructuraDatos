def verificarDiagonales(matrix):
    for i in range(len(matrix)-1):
        if (matrix[i][i] != matrix[i+1][i+1]):
            return False
    return True


def esCapicua(arr):
    return arr == arr[::-1]


def diferenciaListas(a, b):
    hTable = {}
    result = []
    for i in b:
        hTable[i] = False
    for i in a:
        if (i not in hTable):
            result.append(i)
        else:
            if (hTable[i]):
                result.append(i)
            hTable[i] = True
    return result

def inputListas():
    data = {}
    iterations = int(input('Ejecuciones: '))
    for i in range(iterations):
        data['A{}'.format(i)] = input('ListaA: ').split(" ")[1:]
        data['B{}'.format(i)] = input('ListaB: ').split(" ")[1:]

    for i in range(iterations):
        print(diferenciaListas(data['A{}'.format(i)], data['B{}'.format(i)]))


def mostrarPrimos(n):
    resultPrime = []
    sumPrime = []
    for i in range(2,n):
        j = 2
        prime = True
        while (j<i and prime):
            if (i % j == 0):
                prime = False
            j+=1
        if prime:
            resultPrime.append(i)
            if(sum(sumaDigitos(i)) in resultPrime):
                sumPrime.append(i)
            print(i)
    print(sumPrime)

def sumaDigitos(n):
    digits = []
    while (n>0):
        digits.append(n%10)
        n = n//10 
    return digits

def sumarValoresMatriz(mat, arr):
    total = 0
    for coordinate in arr:
        x = coordinate[0]
        y = coordinate[1]
        if (x in mat):
            total += returnValue(mat[x],y)
    return total

def returnValue(arr, target):
    for element in arr:
        if element[0] == target:
            return element[1]
    return 0