#ifndef MYSORT_H
#define MYSORT_H
#define MAXSIZE 20
typedef int KeyType;
typedef char InfoType; 
typedef struct {
	KeyType key;
	InfoType otherinfo;
}RedType;
typedef struct {
	RedType r[MAXSIZE + 1];
	int length;
}SqList;

void InsertSort(SqList &L) {
	int i{};
	int j{};
	for (i = 2; i <= L.length; ++i) {
		if (L.r[i].key < L.r[i - 1].key) {
			L.r[0] = L.r[i];
			for (j = i - 1; L.r[0].key < L.r[j].key;--j ) {
				L.r[j + 1] = L.r[j];
			}
		}
		L.r[j] = L.r[0];
	}
}

void BInsertSort(SqList &L) {
	int i{};
	for (i = 2; i <= L.length; ++i) {
		L.r[0] = L.r[i];
		int low = 1;
		int high = i - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (L.r[0].key < L.r[mid].key) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		for (j = i - 1; i >= high + 1; --j) {
			L.r[j + 1] = L.r[j];
		}
		L.r[high + 1] = L.r[0];
	}
}
#endif // !MYSORT_H
