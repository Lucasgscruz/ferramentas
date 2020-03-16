import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class CrosswordPuzzle_Java {
	// verifica se o resultado encontrado pelo angoritmo é valido
	static boolean checkResult(ArrayList<Palavra> solucao, String[] legenda) {
		int contador = 0;
	
		String aux1 = null;
		String aux2 = null;
		
		for(int i=0; i < solucao.size(); i++) {
			for(int j=0; j<legenda.length; j++) {
				aux1 = solucao.get(i).getPalavra();
				aux2 = legenda[j];

				if(aux1.equals(aux2)) {
					contador = contador+1;
				}
			}
		}
		
		if(contador == legenda.length)
			return true;
		return false;
	}
	
	static ArrayList<Palavra> findWords(char[][]grade) {
		ArrayList<Palavra> words = new ArrayList<Palavra>();
		String aux = new String();
		int cont = 0;
		
		//palavras na horizontal
		for(int i=0; i<10; i++) {
			aux = "";
			for(int j=0; j<10; j++) {
				words.add(new Palavra());
				while(grade[i][j] != '+') {
					aux += grade[i][j];
					words.get(cont).getLetras().add(new Letra());
					words.get(cont).getLetras().get(words.get(cont).getLetras().size()-1).setI(i);
					words.get(cont).getLetras().get(words.get(cont).getLetras().size()-1).setJ(j);
					words.get(cont).getLetras().get(words.get(cont).getLetras().size()-1).
					setLetra(grade[i][j]);
					j++;
					if(j == 10) break;
				}
				if(aux.length() > 1) {
					words.get(cont).setPalavra(aux);
					cont++;
					break;
				}
				else {
					words.get(cont).getLetras().clear();
				}
				aux = "";
			}
		}
		
		//palavras na vertical
		for(int j=0; j<10; j++) {
			aux = "";
			for(int i=0; i<10; i++) {
				words.add(new Palavra());
				while(grade[i][j] != '+') {
					aux += grade[i][j];
					words.get(cont).getLetras().add(new Letra());
					words.get(cont).getLetras().get(words.get(cont).getLetras().size()-1).setI(i);
					words.get(cont).getLetras().get(words.get(cont).getLetras().size()-1).setJ(j);
					words.get(cont).getLetras().get(words.get(cont).getLetras().size()-1).setLetra(grade[i][j]);
					i++;
					if(i == 10) break;
				}
				if(aux.length() > 1) {
					words.get(cont).setPalavra(aux);
					cont++;
					break;
				}
				else {
					words.get(cont).getLetras().clear();
				}
				aux = "";
			}
		}
		
		for(int i=0; i < words.size(); i++) {
			if(words.get(i).getLetras().size() <= 1) {
				words.remove(i);
				i = 0;
			}
		}
		return words;
	}
	
	static void replaceWords(char[][]grade, String[] legenda, ArrayList<Palavra> gabarito ) {
		int numWords = gabarito.size();
		int[] escolhas = new int[numWords];
		int cont = 0;
		int index = 0;
		
		for(int i=0; i<escolhas.length; i++)
			escolhas[i] = 9999;
		
		while(cont < numWords) {
			do {
				index = new Random().nextInt(numWords);
				for(int i=0; i<escolhas.length; i++) {
					if(escolhas[i] == index) {
						index = new Random().nextInt(numWords);
						i = 0;
					}
				}
				
			}while(legenda[index].length() != gabarito.get(cont).getPalavra().length());
			
			escolhas[cont] = index;

			for(int i=0; i<legenda[index].length(); i++) {
				grade[gabarito.get(cont).getLetras().get(i).getI()]
					 [gabarito.get(cont).getLetras().get(i).getJ()] = legenda[index].charAt(i);
			}
			cont++;			
		}
	}
	
	// converte vertor de String para matriz de char
	static char[][] convertToMatrix(String[] entrada) {
		char[][] grade = new char[10][10];
		for(int i=0; i<10; i++)
    		for(int j=0; j<10; j++) 
    			grade[i][j] = entrada[i].charAt(j);
		return grade;
	} 
	
	static String[] convertToString(char[][]grade) {
		String [] solucao = new String[10];
		int pos = 0;
		
		for(int i=0; i<10; i++) {
			solucao[pos] = Character.toString(grade[i][0]);
			for(int j=1; j<10; j++) {
				solucao[pos] += grade[i][j];
			}
			pos++;
		}		
		return solucao;
	}
	
    static String[] crosswordPuzzle(String[] crossword, String hints) {
        // Complete this function
    	boolean fim = false;
    	char[][] grade = new char[10][10];
    	
    	StringTokenizer aux = new StringTokenizer(hints, ";");
    	String[] legenda = new String[aux.countTokens()]; 
    	for(int i=0; i < legenda.length; i++) {    	
    		legenda[i] = aux.nextToken();
    	}
    	
    	
    	// converte crossword para matriz de char
    	grade = convertToMatrix(crossword);
    	ArrayList<Palavra> gabarito = null;
    	    	
    	while(fim == false) {
    		gabarito = null;
    		
    		gabarito = findWords(grade);
    		replaceWords(grade, legenda, gabarito);
    		
    		gabarito = null;
    		gabarito = findWords(grade);
    		fim = checkResult(gabarito, legenda);
    	}
    	
    	crossword = convertToString(grade);    	
     	return crossword;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String[] crossword = new String[10];
        for(int crossword_i = 0; crossword_i < 10; crossword_i++){
            crossword[crossword_i] = in.next();
        }
        String hints = in.next();
        String[] result = crosswordPuzzle(crossword, hints);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + (i != result.length - 1 ? "\n" : ""));
        }
        System.out.println("");


        in.close();
    }
}
