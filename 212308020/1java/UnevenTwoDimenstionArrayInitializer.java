//21 Array with different no. of column in each and every row
class UnevenTwoDimenstionArrayInitializer{
    public static void main(String[] agrs) {
		//Declare,allocate,initialize
			int MyArray[][] = {{33,71},{-16,45,50,-7},{99}};
			//Display Lengths Of the Array and its Element
			System.out.println("MyArray.Length = "+MyArray.length);
			System.out.println("MyArray[0].Length = "+MyArray[0].length);
			System.out.println("MyArray[1].Length = "+MyArray[1].length);
			System.out.println("MyArray[2].Length = "+MyArray[2].length);
			//Display using For loop
			for(int i = 0 ; i < MyArray.length ; i++){
				for(int j = 0 ;j <MyArray[i].length ; j++){
					System.out.println(MyArray[i][j]);
				}
			}/*
			//Display Element
			System.out.println(MyArray[0][0]);
			System.out.println(MyArray[0][1]);
			System.out.println(MyArray[1][0]);
			System.out.println(MyArray[1][1]);
			System.out.println(MyArray[1][2]);
			System.out.println(MyArray[1][3]);
			System.out.println(MyArray[2][0]);
			*/
	}
}