public class RoboSimples extends RoboAbstrato {
	RoboSimples(String n, int px, int py, short d) {
		super(n, px, py, d);
	}

	public void mudaDirecao(short direcao) {
		if (direcao < 45 || direcao > 315)
			super.mudaDirecao((short) 0);
		else if (direcao > 45 && direcao < 135)
			super.mudaDirecao((short) 90);
		else if (direcao > 135 && direcao < 225)
			super.mudaDirecao((short) 180);
		else
			super.mudaDirecao((short) 270);
	}

	public void move(int passos) {
		switch (direcaoAtual()) {
		case 0:
			moveX(+passos);
			break;
		case 90:
			moveY(+passos);
			break;
		case 180:
			moveX(-passos);
			break;
		case 270:
			moveY(-passos);
			break;
		}
	}
}