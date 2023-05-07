
# PS-Study
this repository is for me to record my PS studies.  

<br>

- Record when each algorithm is used.
- Record representative codes of each algorithm for me.



<br><br>


## Rules for Varaible Declaration
- Express the role of variable cleary.
- Use well-known words to construct variable name.
- Follow the rules of programming language.
	- Follow partially for PS speed.
	- Be careful not to use reserved words in the language

<br>

#### Noun
- 배열이나 공간
	- 1차원 배열: `array(arr)`, `list(lst)`
	- 2차원 배열(행렬): `array(arr)`, `matrix`
	- 3차원 배열: `array(arr)`
	- 정보를 나타낼 때: `info`
	- 배열 원소명에 `s`붙이기: ( ex) `nodes` )
	- 간단하거나 그 의미가 명확하면 자료형 앞 글자 따거나 줄이기
		- 벡터(vector): `v`, `vt`
		- 리스트(list): `l`, `lst`
		- 셋(set): `s`, `st`
		- 튜플(tuple): `t`, `tp`
		- 스택(stack): `s`, `st`
		- 큐(queue): `q`, `que`
		- 덱(deque): `d`, `dq`
		- 맵(map): `m`, `mp`
		- 딕셔너리(dictionary): `d`, `dict`, `dct`
		- 트리(tree): `t`, `tree`
		- 페어(pair): `p`, `pr`


- 처리/방문을 나타내는 배열
	- 처리: `processed`, `checked`, `check`
	- 방문: `visited`, `visit`
	- 사용중임을 나타낼 때: `used`

- (1개 이상의) 쌍
	- 1개: `x`
	- 2개: `a b`
		- 좌표: `x y`
		- 몫/나머지: `p q`
	- 3개: `a b c`
		- 좌표: `x y z`
		- 그래프 간선: `a b w`
	- 4개: `a b c d`
		- 상하좌우: `up(u) down(d) left(l) right(r)`
- 결과를 나타낼 때: `res`, `ans`
	- 함수의 리턴값: `ret`  


- 최대/최소값: `max(mx) min(mn)`
- 하나의 지점: `x`, `node`, `element`
- 하나의 값: `x`, `value(val)`
- 경로: `path`
- 거리: `dist`
- 점: `dot`
- 최적의 값: `best`
- 숫자: `num`, `n`
- 개수: `count`, `cnt`, `num`
- 크기: `amount`, `size`, `sz`
- 길이: `length`, `len`
- 합, 총량: `sum`, `total`, `all`


<br>


#### Adjective
- 인접한: `adj`, `next`
- ~한(주로 함수에 쓰임): `do`, `is`
- 최대/최소: `max(mx) min(mn)`
<br>

#### Verb
- 일반적인 이름: `func`, `f`
- 탐색에 관한 이름: `search`
	- 깊이우선탐색: `dfs`
	- 너비우선탐색: `bfs`
- 합치다: `merge`, `combine`
- 바꾸다, 변환하다: `change`, `convert`, `a_to_b`, `a2b`
