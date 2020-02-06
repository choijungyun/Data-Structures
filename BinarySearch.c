int Bsearch(int arr[], int len, int target)
{
    int first = 0; //탐색 대상의 시작 인덱스 값
    int last = len - 1; //탐색 대상의 마지막 인덱스 값
    int mid;

    while (first <= last)
    {
        mid = (first + last) / 2;    //탐색 대상의 중앙을 찾는다.
        if (target == arr[mid]) return mid; //시간 복잡도 영향
        else
        {
            if (target < arr[mid])
                last = mid - 1;
            else
                first = mid + 1;
        }
    }
    return -1; //찾지 못했을 때 '-1' 반환
}

/*
    1) first<=last인 경우?
    -> 겹치는 경우도 아직 탐색의 대상이기 때문이다.

    2) mid-1? mid+1?
    -> 검사했던 값은 다시 검사할 필요가 없기 때문에 지나친다.
    -> first <= mid <= last가 항상 성립하기 때문에 -1,+1을 해주지 않으면 무한 loop에 빠지게 된다.

    3) 시간 복잡도?
    -> target==arr[mid] 부분이 시간 복잡도에 영향을 준다.
    -> 최악의 경우 logN의 시간 복잡도를 가진다.
    -> 최악의 경우는 모든 비교를 다해보는 경우이다.

*/