public class RB_Node {
	private RB_Node left;
	private RB_Node right;
	private RB_Node parent;
	private boolean color;
	private CFS_task task;
	
	public RB_Node(CFS_task task, boolean color, RB_Node parent, RB_Node left, RB_Node right){
		this.left = left;
		this.right = right;
		this.task = task;
		this.color = color;
		this.parent = parent;
	}

	public RB_Node getLeft() {
		return left;
	}

	public void setLeft(RB_Node left) {
		this.left = left;
	}

	public RB_Node getRight() {
		return right;
	}

	public void setRight(RB_Node right) {
		this.right = right;
	}

	public RB_Node getParent() {
		return parent;
	}

	public void setParent(RB_Node parent) {
		this.parent = parent;
	}

	public boolean getColor() {
		return color;
	}

	public void setColor(boolean color) {
		this.color = color;
	}

	public CFS_task getTask() {
		return this.task;
	}

	public void setData(CFS_task task) {
		this.task = task;
	}
	
}
