#include <disjset>

void Initialize(DisjSet S){
	
}

SetType Find(ElementType X, DisjSet S){
	if(S[X] <= 0)
		return X;
	else
		return S[X] = Find(S[X], S);
}

SetType SimpleFind(ElementType X, DisjSet S){
	if(S[X] <= 0)
		return X;
	else
		return SimpleFind(S[X], S);
}

void UnionByHeight(DisjSet S, SetType Root1, SetType Root2){
	if(S[Root2] < S[Root1])//Root2 is deeper
		S[Root1] = Root2;
	else{
		if(S[Root2] == S[Root1])
			--S[Root1];//update height
		S[Root2] = Root1;
	}
}

void UnionBySize(DisjSet S, SetType Root1, SetType Root2){
	if(S[Root1] <= S[Root2]){//Root1 is larger
		S[Root2] = Root1;
		S[Root1] = Root1 + Root2;
	}
	else{
		S[Root1] = Root2;
		S[Root2] = Root1 + Root2;
	}
}

void Union(DisjSet S, SetType Root1, SetType Root2){
	S[Root2] = Root1;
}

int main(int argc, char** argv) {
	
	return 0;
}
