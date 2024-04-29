namespace A {
	void F_Swap(int idx1, int idx2, int* TargetArray)
	{
		int temp;
		temp = TargetArray[idx1];
		TargetArray[idx1] = TargetArray[idx2];
		TargetArray[idx2] = temp;
	}

	void F_InitializeArray(int* TargetArray, int Size)
	{
		for (int cur = 1; cur <= Size; cur++)
		{
			TargetArray[cur] = cur;
		}
	}
}

