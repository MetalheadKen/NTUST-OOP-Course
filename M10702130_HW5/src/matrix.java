public class matrix {
	private int size;
	private int [][] data;
	
	public matrix() {
		this.size = 1;
		this.data = new int [size][size];
	}
	
	public matrix(int size) {
		this.size = size;
		this.data = new int [size][size];
	}
	
	public matrix(matrix m) {
		this.size = m.size;
		this.data = m.data.clone();
	}
	
	public void setElement(int x, int y, int value) {
		this.data[x][y] = value;
	}
	
	public int getElement(int x, int y) {
		return this.data[x][y];
	}
	
	public void printSelf() {
		for (int i = 0; i < this.size; i++) {
			for (int j = 0; j < this.size; j++) {
				System.out.print(this.data[i][j] + " ");
			}
			System.out.println();
		}
	}
}
