
public class RB_Root {
	private static final boolean RED = true;
	private static final boolean BLACK = false;
	private RB_Node nodeNULL;
	private RB_Node root;
	private RB_Node theLowest;
	private int number;
	
	public RB_Root(){
		this.nodeNULL = new RB_Node(null, BLACK, null, null, null);
		this.root = this.nodeNULL;
		this.theLowest = this.nodeNULL;
		this.number = 0;
	}
	
	private void setLowestValue(){
		RB_Node t = this.root;
		if(t != this.nodeNULL){
			while(t.getLeft() != this.nodeNULL)
				t = t.getLeft();
		}
		this.theLowest = t;
	}
	
	public CFS_task getLowestValue(){
		return this.theLowest.getTask();
	}
	
	private void leftRotate(RB_Node x){
		RB_Node y = x.getRight();
		x.setRight(y.getLeft());
		if(y.getLeft() != this.nodeNULL)
			y.getLeft().setParent(x);
		y.setParent(x.getParent());
		if(x.getParent()==this.nodeNULL)
			this.root = y;
		else if (x == x.getParent().getLeft())
			x.getParent().setLeft(y);
		else x.getParent().setRight(y);
		y.setLeft(x);
		x.setParent(y);
	}
	
	private void rightRotate(RB_Node x){
		RB_Node y = x.getLeft();
		x.setLeft(y.getRight());
		if(y.getRight() != this.nodeNULL)
			y.getRight().setParent(x);
		y.setParent(x.getParent());
		if(x.getParent()==this.nodeNULL)
			this.root = y;
		else if (x == x.getParent().getRight())
			x.getParent().setRight(y);
		else x.getParent().setLeft(y);
		y.setRight(x);
		x.setParent(y);
	}
	
	private void rbInsertFixup (RB_Node z){
		while(z.getParent().getColor() == RED){
			if(z.getParent() == z.getParent().getParent().getLeft()){
				RB_Node y = z.getParent().getParent().getRight();
				if(y.getColor() == RED){
					z.getParent().setColor(BLACK);
					y.setColor(BLACK);
					z.getParent().getParent().setColor(RED);
					z = z.getParent().getParent();
				}
				else{
					if (z == z.getParent().getRight()){
						z = z.getParent();
						leftRotate(z);
					}
					z.getParent().setColor(BLACK);
					z.getParent().getParent().setColor(RED);
					rightRotate(z.getParent().getParent());
				}
			}
			else {
				RB_Node y = z.getParent().getParent().getLeft();
				if(y.getColor() == RED){
					z.getParent().setColor(BLACK);
					y.setColor(BLACK);
					z.getParent().getParent().setColor(RED);
					z = z.getParent().getParent();
				}
				else{
					if (z == z.getParent().getLeft()){
						z = z.getParent();
						rightRotate(z);
					}
					z.getParent().setColor(BLACK);
					z.getParent().getParent().setColor(RED);
					leftRotate(z.getParent().getParent());
				}
			}
		}
		this.root.setColor(BLACK);
	}
	
	private void rbInsert(RB_Node z){
		RB_Node y = this.nodeNULL;
		RB_Node x = this.root;
		while(x != this.nodeNULL){
			y = x;
			if(z.getTask().getVirtualTime() < x.getTask().getVirtualTime())
				x = x.getLeft();
			else x = x.getRight();
		}
		z.setParent(y);
		if(y == this.nodeNULL)
			this.root = z;
		else if (z.getTask().getVirtualTime() < y.getTask().getVirtualTime())
			y.setLeft(z);
		else y.setRight(z);
		z.setLeft(this.nodeNULL);
		z.setRight(this.nodeNULL);
		z.setColor(RED);
		rbInsertFixup(z);
		setLowestValue();
		this.number++;
	}
	
	private RB_Node treeMinimum(RB_Node t){
		while(t.getLeft() != this.nodeNULL)
			t = t.getLeft();
		return t;
	}
	
	private void rbTransplant(RB_Node u, RB_Node v){
		if(u.getParent() == this.nodeNULL)
			this.root = v;
		else if (u == u.getParent().getLeft())
			u.getParent().setLeft(v);
		else u.getParent().setRight(v);
		v.setParent(u.getParent());
	}
	
	private void rbDeleteFixup(RB_Node x){
		RB_Node w;
		while(x != this.root && x.getColor() == BLACK){
			if(x == x.getParent().getLeft()){
				w = x.getParent().getRight();
				if(w.getColor() == RED){
					w.setColor(BLACK);
					x.getParent().setColor(RED);
					leftRotate(x.getParent());
					w = x.getParent().getRight();
				}
				if(w.getLeft().getColor() == BLACK && w.getRight().getColor() == BLACK){
					w.setColor(RED);
					x = x.getParent();
				}
				else{
					if (w.getRight().getColor() == BLACK){
						w.getLeft().setColor(BLACK);
						w.setColor(RED);
						rightRotate(w);
						w = x.getParent().getRight();
					}
					w.setColor(x.getParent().getColor());
					x.getParent().setColor(BLACK);
					w.getRight().setColor(BLACK);
					leftRotate(x.getParent());
					x = this.root;
				}
			}
			else{
				w = x.getParent().getLeft();
				if(w.getColor() == RED){
					w.setColor(BLACK);
					x.getParent().setColor(RED);
					rightRotate(x.getParent());
					w = x.getParent().getLeft();
				}
				if(w.getLeft().getColor() == BLACK && w.getRight().getColor() == BLACK){
					w.setColor(RED);
					x = x.getParent();
				}
				else{
					if (w.getLeft().getColor() == BLACK){
						w.getLeft().setColor(BLACK);
						w.setColor(RED);
						leftRotate(w);
						w = x.getParent().getLeft();
					}
					w.setColor(x.getParent().getColor());
					x.getParent().setColor(BLACK);
					w.getLeft().setColor(BLACK);
					rightRotate(x.getParent());
					x = this.root;
				}
			}
		}
		x.setColor(BLACK);
	}
	
	private void rbDelete (RB_Node z){
		RB_Node y = z;
		RB_Node x;
		boolean y_originalColor = y.getColor();
		if(z.getLeft() == this.nodeNULL){
			x = z.getRight();
			rbTransplant(z, z.getRight());			
		}
		else if (z.getRight() == this.nodeNULL){
			x = z.getLeft();
			rbTransplant(z, z.getLeft());
		}
		else{
			y = treeMinimum(z.getRight());
			y_originalColor = y.getColor();
			x = y.getRight();
			if(y.getParent() == z)
				x.setParent(y);
			else{
				rbTransplant(y, y.getRight());
				y.setRight(z.getRight());
				y.getRight().setParent(y);
			}
			rbTransplant(z, y);
			y.setLeft(z.getLeft());
			z.getLeft().setParent(y);
			y.setColor(z.getColor());
		}
		if(y_originalColor == BLACK)
			rbDeleteFixup(x);
		setLowestValue();
		this.number--;
	}
	
	private RB_Node searchValue(CFS_task task){
		RB_Node aux = this.root;
		while(aux != this.nodeNULL){
			if(aux.getTask() == task)
				return aux;
			if(task.getVirtualTime() > aux.getTask().getVirtualTime())
				aux = aux.getRight();
			else aux = aux.getLeft();
		}
		return this.nodeNULL;
	}
	
	private void printRBRecursive(RB_Node node){
		if(node!=this.nodeNULL){
			printRBRecursive(node.getLeft());
			System.out.println(node.getTask().getVirtualTime());
			printRBRecursive(node.getRight());
		}
	}
	
	public boolean isEmpty(){
		if(this.root == this.nodeNULL)
			return true;
		else return false;
	}
	
	public void deleteNodeByTask(CFS_task task){
		RB_Node aux = searchValue(task);
		if(aux != this.nodeNULL)
			rbDelete(aux);
		else
			System.out.println("Valor não encontrado");
	}

	public void insertNodeByTask(CFS_task task){
		RB_Node aux = new RB_Node(task, RED, this.nodeNULL, this.nodeNULL, this.nodeNULL);
		rbInsert(aux);
	}
	
	public int getNumber(){
		return this.number;
	}
	
	public void printRB(){
		printRBRecursive(this.root);
	}
}