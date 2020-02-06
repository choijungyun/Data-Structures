int Bsearch(int arr[], int len, int target)
{
    int first = 0; //Ž�� ����� ���� �ε��� ��
    int last = len - 1; //Ž�� ����� ������ �ε��� ��
    int mid;

    while (first <= last)
    {
        mid = (first + last) / 2;    //Ž�� ����� �߾��� ã�´�.
        if (target == arr[mid]) return mid; //�ð� ���⵵ ����
        else
        {
            if (target < arr[mid])
                last = mid - 1;
            else
                first = mid + 1;
        }
    }
    return -1; //ã�� ������ �� '-1' ��ȯ
}

/*
    1) first<=last�� ���?
    -> ��ġ�� ��쵵 ���� Ž���� ����̱� �����̴�.

    2) mid-1? mid+1?
    -> �˻��ߴ� ���� �ٽ� �˻��� �ʿ䰡 ���� ������ ����ģ��.
    -> first <= mid <= last�� �׻� �����ϱ� ������ -1,+1�� ������ ������ ���� loop�� ������ �ȴ�.

    3) �ð� ���⵵?
    -> target==arr[mid] �κ��� �ð� ���⵵�� ������ �ش�.
    -> �־��� ��� logN�� �ð� ���⵵�� ������.
    -> �־��� ���� ��� �񱳸� ���غ��� ����̴�.

*/