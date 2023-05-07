
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


- (1개 이상의) 쌍 (주로 전역변수로 쓸 때) (재사용 많이 하는 경우)
	- 1개: `x`, `u`
	- 2개: `a b`
		- 좌표: `x y`
		- 몫/나머지: `p q`
		- 세로/가로: `n m`, `row col`, `r c`
	- 3개: `a b c`
		- 좌표: `x y z`
		- 그래프 간선: `a b w`
	- 4개: `a b c d`
		- 상하좌우: `up(u) down(d) left(l) right(r)`
	- 반복문(for)문 변수명: `i j k l ...`
	
- 결과를 나타낼 때: `res`, `ans`
	- 함수의 리턴값: `ret`  

- 인덱스: `index`, `idx`, `i`

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
- 부분: `part`  
- 차이: `diff`
- 시간, 시각: `time`, `t`

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
- 합치다: `merge`, `unite`, `combine`
- 바꾸다, 변환하다: `change`, `convert`, `a_to_b`, `a2b`
- 갱신하다: `update`


#### Commonly used Names(Convention)
- `sy`/`sx`: 시작(start) x, y 좌표를 의미  
- `ey`/`ex`: 끝(end) x, y 좌표를 의미  
- `dp`: 다이나믹프로그래밍(Dynamic Programming) 알고리즘을 사용하는 배열을 의미  
- `psum`: 여기서 `p`는 누적(prefix)를 의미  
- `t`, `T`: 테스트 케이스의 개수나 시간을 의미  
- `q`, `Q`: 쿼리의 개수를 의미
- `MOD`: 문제의 정답이 커서 나눠야 하는 수를 의미
- `MAX`/`MIN`: 문제에서 나올 수 있는(또는 제시한) 최대/최소 값을 의미
- `INF`: 무한대(문제에서 나올 수 있는 최대값보다 큰 값)를 의미 (`-INF`로 -무한대 표현)
- `ll`: `long long`을 줄여서 사용
