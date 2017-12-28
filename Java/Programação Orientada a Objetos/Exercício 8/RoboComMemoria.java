public class RoboComMemoria extends RoboAbstrato {
	private int passosX;
	private int passosY;

	public void move(int passos) {
		switch (direcaoAtual()) {
		case 0:
			moveX(+passos);
			this.passosX += passos;
			break;
		case 90:
			moveY(+passos);
			this.passosY += passos;
			break;
		case 180:
			moveX(-passos);
			this.passosX -= passos;
			break;
		case 270:
			moveY(-passos);
			this.passosY -= passos;
			break;
		}
	}

	public void retornaAOrigem() {
		System.out.println("Origem: ("
				+ (super.getPosicaoXAtual() - this.passosX) + ", "
				+ (super.getPosicaoYAtual() - this.passosY) + ")");
	}

	public RoboComMemoria(String n, int px, int py, short d) {
		super(n, px, py, d);
		this.passosX = 0;
		this.passosY = 0;
	}

}
