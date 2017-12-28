
public class Funcionario {
	private String sobreNome;
	private String nome;
	private double salarioHora;
	private int anosNaEmpresa;
	public Funcionario (String sobreNome, String nome, double salarioHora, int anosNaEmpresa){
		this.sobreNome = sobreNome;
		this.nome = nome;
		this.salarioHora = salarioHora;
		this.anosNaEmpresa = anosNaEmpresa;
	}
	public static void funcionarios (Funcionario vetor[], int X){
		for (int i = 0; i < vetor.length; i++){
			if (vetor[i].anosNaEmpresa >= X){
				System.out.println("Nome: " + vetor[i].nome);
				System.out.println("Sobrenome: " + vetor[i].sobreNome);
				System.out.println("Salário: " + vetor[i].salarioHora);
			}
		}
	}

	public String getSobreNome() {
		return sobreNome;
	}
	public void setSobreNome(String sobreNome) {
		this.sobreNome = sobreNome;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public double getSalarioHora() {
		return salarioHora;
	}
	public void setSalarioHora(double salarioHora) {
		this.salarioHora = salarioHora;
	}
	public int getAnosNaEmpresa() {
		return anosNaEmpresa;
	}
	public void setAnosNaEmpresa(int anosNaEmpresa) {
		this.anosNaEmpresa = anosNaEmpresa;
	}
}