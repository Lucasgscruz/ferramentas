import java.util.ArrayList;

public class Palavra {
	private ArrayList<Letra> letras = new ArrayList<Letra>();
	private String palavra = new String();
	
	public ArrayList<Letra> getLetras() {
		return letras;
	}
	public void setLetras(ArrayList<Letra> letras) {
		this.letras = letras;
	}
	public String getPalavra() {
		return palavra;
	}
	public void setPalavra(String palavra) {
		this.palavra = palavra;
	}	
}
