import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class M10702130_HW5 {

	public static void main(String[] args) {
		// obtain the matrix size from user
		int size;
		Scanner keyIn = new Scanner(System.in);
		
		System.out.println("Please input the size of the square matrix.");
		size = keyIn.nextInt();

		// create the matrix object
		matrix m = new matrix(size);

		// assign the values to the created matrix
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
			{
				if (i == j)
					m.setElement(i, j, 10);
				else
					m.setElement(i, j, 1);
			}

		// show the matrix on the screen
		System.out.println("m = ");
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				System.out.print(m.getElement(i, j) + " ");

			System.out.println();
		}


		//testing standard constructors
		matrix[] mArr1 = new matrix[10];	//calling default constructor
		//matrix[] mArr2[5];					//calling default constructor
		matrix m1;							//calling default constructor
		matrix m2 = new matrix(m);			//calling copy constructor
		//matrix m3 = matrix(m);				//calling copy constructor

		//Java doesn't support operator overloading
		m1 = m;								//calling copy assignment operator


		//show the testing matrix objects
		System.out.println("m1 = ");
		m1.printSelf();
		System.out.println("*m2 = ");
		m2.printSelf();
		//System.out.println("m3 = ");
		//m3.printSelf();


		// delete the dynamic allocated object
		//delete m;
		//delete[] mArr1;
		//delete m2;
	}
}
