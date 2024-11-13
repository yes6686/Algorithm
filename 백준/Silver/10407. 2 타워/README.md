# [Silver III] 2 타워 - 10407 

[문제 링크](https://www.acmicpc.net/problem/10407) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

수학, 정수론

### 제출 일자

2024년 11월 13일 19:47:34

### 문제 설명

<p>2 타워의 높이 H는<mjx-container class="MathJax" jax="CHTML" display="true" style="font-size: 109%; position: relative;"><mjx-math display="true" class="MJX-TEX" aria-hidden="true" style="margin-left: 0px; margin-right: 0px;"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.413em;"><mjx-texatom size="s" texclass="ORD"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.363em;"><mjx-texatom size="s" texclass="ORD"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.363em;"><mjx-texatom texclass="ORD"><mjx-msup><mjx-mo class="mjx-n"><mjx-c class="mjx-c22C5"></mjx-c></mjx-mo><mjx-script style="vertical-align: 0.363em;"><mjx-texatom texclass="ORD"><mjx-msup><mjx-mo class="mjx-n"><mjx-c class="mjx-c22C5"></mjx-c></mjx-mo><mjx-script style="vertical-align: 0.363em;"><mjx-texatom texclass="ORD"><mjx-mo class="mjx-n"><mjx-c class="mjx-c22C5"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-msup></mjx-texatom></mjx-script></mjx-msup></mjx-texatom></mjx-script></mjx-msup></mjx-texatom></mjx-script></mjx-msup></mjx-texatom></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="block"><math xmlns="http://www.w3.org/1998/Math/MathML" display="block"><msup><mn>2</mn><mrow data-mjx-texclass="ORD"><msup><mn>2</mn><mrow data-mjx-texclass="ORD"><msup><mn>2</mn><mrow data-mjx-texclass="ORD"><msup><mo>⋅</mo><mrow data-mjx-texclass="ORD"><msup><mo>⋅</mo><mrow data-mjx-texclass="ORD"><mo>⋅</mo><mn>2</mn></mrow></msup></mrow></msup></mrow></msup></mrow></msup></mrow></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\[2^{2^{2^{\cdot^{\cdot^{\cdot 2}}}}}\]</span></mjx-container>에서 숫자 2가 나타나는 횟수로 정의된다. 2 타워의 값은 해당 표현식의 값으로 정의된다. 예를 들어, 높이 1의 2 타워 값은 2이고, 높이 2의 2 타워 값은 4이며, 높이 4의 2 타워 값은<mjx-container class="MathJax" jax="CHTML" display="true" style="font-size: 109%; position: relative;"><mjx-math display="true" class="MJX-TEX" aria-hidden="true" style="margin-left: 0px; margin-right: 0px;"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.413em;"><mjx-texatom size="s" texclass="ORD"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.363em;"><mjx-texatom size="s" texclass="ORD"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.363em;"><mjx-texatom texclass="ORD"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-msup></mjx-texatom></mjx-script></mjx-msup></mjx-texatom></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c36"></mjx-c><mjx-c class="mjx-c35"></mjx-c><mjx-c class="mjx-c35"></mjx-c><mjx-c class="mjx-c33"></mjx-c><mjx-c class="mjx-c36"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="block"><math xmlns="http://www.w3.org/1998/Math/MathML" display="block"><msup><mn>2</mn><mrow data-mjx-texclass="ORD"><msup><mn>2</mn><mrow data-mjx-texclass="ORD"><msup><mn>2</mn><mrow data-mjx-texclass="ORD"><mn>2</mn></mrow></msup></mrow></msup></mrow></msup><mo>=</mo><mn>65536</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\[2^{2^{2^{2}}} = 65536\]</span></mjx-container>이므로 높이 5의 2 타워 값은 2<sup>65536</sup>이며 이 값은 2003...6736이고 다 쓰기에는 여백이 부족하다.</p>

<p>H의 값이 커짐에 따라 2 타워의 값이 너무 커지므로, 우리는 이 값을 3으로 나눈 나머지만이 궁금하다.</p>

### 입력 

 <p>입력의 첫째 줄에 높이 H가 주어진다. (1 ≤ H ≤ 10<sup>100</sup>)</p>

### 출력 

 <p>첫째 줄에 높이가 H인 2 타워의 값을 3으로 나눈 나머지를 출력하라.</p>

