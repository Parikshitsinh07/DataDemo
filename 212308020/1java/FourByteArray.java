//18 Working with Byte Array
class Array3d{
    public static void main(String[] agrs) {
		byte array2[] = new byte[4];
		array2[0] = 11;
		byte array[][][] = {{{4,5,6},{1,2,3},{5,7,8}},
							{{2,0,5},{9,8,7},{4,4,3}},
							{{0,0,0},{1,1,1},{2,2,2}}};
		//Print Array useing For Loop
		for(int i =0 ; i < 3 ; i++){
			for(int j = 0 ; j < 3; j++){
				for(int k = 0 ; k < 3 ; k++){
					System.out.print(array[i][j][k] + ",");
				}
			}
			System.out.println("");
		}/*
		System.out.print(array[0][0][0] + ",");
		System.out.print(array[0][0][1] + ",");
		System.out.print(array[0][0][2] + ",");
		System.out.print(array[0][1][0] + ",");
		System.out.print(array[0][1][1] + ",");
		System.out.print(array[0][1][2] + ",");
		System.out.print(array[0][2][0] + ",");
		System.out.print(array[0][2][1] + ",");
		System.out.println(array[0][2][2] + ",");
		
		System.out.print(array[1][0][0] + ",");
		System.out.print(array[1][0][1] + ",");
		System.out.print(array[1][0][2] + ",");
		System.out.print(array[1][1][0] + ",");
		System.out.print(array[1][1][1] + ",");
		System.out.print(array[1][1][2] + ",");
		System.out.print(array[1][2][0] + ",");
		System.out.print(array[1][2][1] + ",");
		System.out.println(array[1][2][2] + ",");
		
		System.out.print(array[2][0][0] + ",");
		System.out.print(array[2][0][1] + ",");
		System.out.print(array[2][0][2] + ",");
		System.out.print(array[2][1][0] + ",");
		System.out.print(array[2][1][1] + ",");
		System.out.print(array[2][1][2] + ",");
		System.out.print(array[2][2][0] + ",");
		System.out.print(array[2][2][1] + ",");
		System.out.println(array[2][2][2] + ",");*/
	}
}