public class RoboABateria extends RoboAbstrato {
	private long energia;

	public RoboABateria(String n, int px, int py, short d, long e) {
		super(n, px, py, d);
		energia = e;
	}

	public void move(int passos) {
		long energiaASerGasta;
		if (direcaoAtual() == 0 || direcaoAtual() == 90
				|| direcaoAtual() == 180 || direcaoAtual() == 270
				|| direcaoAtual() == 360)
			energiaASerGasta = 10 * passos;
		else
			energiaASerGasta = 14 * passos;
		if (energiaASerGasta <= energia) {
			switch (direcaoAtual()) {
			case 0:
				moveX(+passos);
				break;
			case 45:
				moveX(+passos);
				moveY(+passos);

				break;
			case 90:
				moveY(+passos);
				break;
			case 135:
				moveY(+passos);
				moveX(-passos);
				break;
			case 180:
				moveX(-passos);
				break;
			case 225:
				moveX(-passos);
				moveY(-passos);
				break;
			case 270:
				moveY(-passos);
				break;
			case 315:
				moveY(-passos);
				moveX(+passos);
				break;
			}
			energia -= energiaASerGasta;
		}
	}

	public void recarrega(long valor) {
		this.energia += valor;
	}

	public String toString() {
		String resultado = super.toString() + "\n";
		resultado = resultado + "Energia do robô:" + energia;
		return resultado;
	}
}