package testAccenture;

import java.util.List;

public class TesteProgT {
	
	/***
    PROBLEMA 1

    Dada uma string representando um numero em algarismos romanos, converte-la
    para um inteiro convencional.

    Considere somente numeros cuja saida correspondente seja menor ou igual a
    3999.

    Observacao: a representacao da entrada sera sempre em letras maiusculas.

    Seguem os valores de cada algarismo romano:
    * I = 1
    * V = 5
    * X = 10
    * L = 50
    * C = 100
    * D = 500
    * M = 1000

    Exemplos:
    1. "I" -> 1
    2. "III" -> 3
    3. "XVII" -> 17
    4. "CMXCII" -> 992
    5. "MMMCIV" -> 3104
    ***/
    public int problema1(String romano){
		
		char Rom[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
		int valor[] = {1,5,10,50,100,500,1000};
		int soma = 0;
		int anterior = 0;		
		char letra = ' ';
				
		for( int i = 0; i < romano.length(); i++) {
			letra = romano.charAt(i);
			for(int j = 0; j < Rom.length; j ++) {
				if(letra == Rom[j]) {
					soma = soma + valor[j];
					if(anterior < valor[j]) {
						soma = soma - anterior*2;
					}
					anterior = valor[j];
				}
			}
		}
		System.out.println("Valor em números naturais: " + soma);
	    return 0;
    }
	

    /*** 
     * PROBLEMA 2
     * 
     * Seja 'l' uma lista de inteiros ordenados de tamanho 1M, e 'v' um valor inteiro
     * determine se o valor v existe ou não nessa lista utilizado no máximo 20 comparações.
     * Faça uma função que imprima no console o número de comparações utilizadas e se o 
     * o valor v foi ou não encontrado na lista.
     */
    void problema2(int l[], int v){
        int flag = 0;
		    int base = 0;		
		    int corte = l.length;
		    corte = corte/2;
		    base = corte;
		    
		    for(int iter=0; iter < 20; iter++) {
			    if(v >= l[base]) {
				    base = base+corte;	
				    flag = 0;
			    }else {
				    base = base-corte;
				    flag = 1;
			    }
			    corte = corte/2;
		    }
		    if(v == l[base-flag]) System.out.println("O numero " + v+ " está presente na lista");
		    else System.out.println("O numero " + v +"  não está presente na lista");
      }

    
    /*** 
     * PROBLEMA 3
     * 
     * Seja 'm' uma string que representa uma expressão matemática envolvendo os operadores 
     * '+', '-', '*' e '/' construa uma função que determina o resultado da expressão.
     * exemplo: 5 + 4 * 3 = 17
     */
    double problema3(String m)
    {
        return .0;
    }
    
    
    /*** 
     * PROBLEMA 4
     * É uma variante do problema 3 e sua resposta contempla resultado para as duas questões.
	 * 
	 *
     * Seja 'm' uma string que representa uma expressão matemática envolvendo os operadores 
     * '+', '-', '*' , '/', '(' e ')' construa uma função que determina o resultado da expressão.
     * exemplo: 5 + 4 * (3 + 2) = 25
     */

   	public static int E(String equacao, int i) {
		
		i = T(equacao, i);
		i = Elinha(equacao, i);
		return i;
	}
	
	public static int T(String equacao, int i) {
		F(equacao, i);
		Tlinha(equacao, i);
		return i;
	}
	
	public static int F(String equacao, int i) {
		if(equacao.charAt(i) >= 48 || equacao.charAt(i) <= 57) {
			i++;
		}
		else if(equacao.charAt(i) == '(') {
			i++;
			i = E(equacao,i);
			if (equacao.charAt(i) == ')'){
				i++;
			}
		}
		return i;
	}
	
	public static int Elinha(String equacao, int i) {
		if(equacao.charAt(i) == '+') {
			i++;
			i = T(equacao, i);
			i = Elinha(equacao, i);
		}
		else if(equacao.charAt(i) == '-') {
			i++;
			i = T(equacao, i);
			i = Elinha(equacao, i);
		}
		return i;
	}
	
	public static int Tlinha(String equacao, int i) {
		if(equacao.charAt(i) == '*') {
			i++;
			i = F(equacao, i);
			i = Tlinha(equacao, i);
		}
		else if(equacao.charAt(i) == '/') {
			i++;
			i = F(equacao, i);
			i = Tlinha(equacao, i);
		}
		return i;
	}
	
	
	public static void problema4(String m) {
		
		StringTokenizer aux = new StringTokenizer(m, " ");
		String equacao = new String();
		int i =0;
		while(aux.hasMoreTokens()){
			equacao += aux.nextToken();					
		}
		
		E(equacao, i);
	}
    
    
    

public static void main(String[] args) {
		
		System.out.printf("Hello!");
	}
}
