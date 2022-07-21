/*
2 Descricao do Algoritmo: Fazer tavela de distribuição e histograma.
3 Nome da Disciplina: Algoritmos e Programação de Computadores
4 Nome Professor: Leonair Neves
5 Descricao do Algoritmo: Trabalho 2
6 Nome da Disciplina: Algoritmos e Programação de Computadores
7 Nome Professor: Leonair Neves
8 Nome Aluno: João Vitor Monteiro de Souza
9 Turma: VE1
10 RGA: 201621901004
11 Data Entrega: 28/02/2018
12 */
13
14 #include <stdio.h>
15 #include <stdlib.h>
16 #include <math.h>
17 #include <locale.h>
18 #include <conio2.h>
19
20 void variancia(float SQ, float s, int N, float *var)
21 {
22 *var=SQ/(N-1);
23 }
24 float desvio_padrao(float var)
25 {
26 float desvio_padrao;
27 desvio_padrao = sqrt(var);
28
29 return desvio_padrao;
30 }
31 int main()
32 {
33 int
vet[20],amost,primeiro,cont,menor,i,aux,N,med,l,c,CI,CS,FI,FCA,g,h,y,a,linha,b,d,x,moda,z,
j;
34 float
K,ATC,AT,Med_Amost,soma,dist[5][8],XI,FR,FCI,FCS,fi,mat[20][4],desvio,quad,SQ,s,dpa=0,var=0
;
35
36 setlocale(LC_ALL,"");
37 for(amost=0; amost<=19; amost++)
38 {
39 printf("Insira a classificacao final do campeonato brasileiro:\n");
40 scanf("%d",&vet[amost]);
41 }
42
43 primeiro = 0;
44 cont = 1;
45 while (cont <=20)
46 {menor = primeiro;
47 for(i = primeiro + 1; i < 20; i++)
48 {if(vet[menor] > vet[i])
49 {menor = i;
50 }
51 }
52 aux = vet[primeiro];
53 vet[primeiro] = vet[menor];
54 vet[menor] = aux;
55 primeiro = primeiro + 1;
56 cont++;
57
58 }
59 N=amost;
60 K=sqrt(N);
61 K=ceil(K);
62 AT=vet[19]-vet[0];
63 ATC=AT/K;
64 ATC=ceil(ATC);
65 soma=0;
66 for(x=0;x<20;x++)
67 {
68 soma=soma+vet[x];
69 }
70 soma=soma/20;
71 Med_Amost=soma;
72 printf("%.2f", Med_Amost);
73 med=(vet[9]+vet[10])/2;
74 for(l=0;l<=5;l++)
75 {
76 for(c=0;c<=8;c++)
77 {
78 if(c==0 && l==0)
79 {
80 CI=vet[0];

81 dist[l][c] = CI;
82 }else if(c == 0){
83 CI=CS + 1;
84 dist[l][c] = CI;
85 }
86
87 if(c==1)
88 {
89 CS=(CI+ATC)-1;
90 dist[l][c] = CS;
91 }
92 if(c==2)
93 {
94 FI=0;
95 for(i=0;i<20;i++)
96 {
97 if(vet[i]>=CI && vet[i]<=CS)
98 {
99 FI+=1;
100 }
101 }
102 dist[l][c] = FI;
103 }
104 if(c==3)
105 {
106 XI=(float)(CI+CS)/2;
107 dist[l][c] = XI;
108 }
109 if(c==4)
110 {
111 FR=(float)(FI*100)/N;
112 dist[l][c] = FR;
113 }
114 if(c==5)
115 {
116 if(l == 0)
117 FCA=FI;
118 else
119 FCA=FI+dist[l-1][c];
120 dist[l][c] = FCA;
121 }
122 if(c==6)
123 {
124 FCI=CI-0.5;
125 dist[l][c] = FCI;
126 }
127 if(c==7)
128 {
129 FCS=CS+0.5;
130 dist[l][c] = FCS;
131 }
132 }
133 }
134 system("cls");
135 printf(" \n Amostra\n");
136 for(l=0;l<20;l++)
137 { if(l==0)
138 { printf(" ");
139 }
140 if(l==20-1)
141 {printf("%d", vet[l]);
142 }else{
143 printf("%d-", vet[l]);
144 }
145 }
146 printf(" \n\n Distribuição de Frequência \n");
147 printf("CI |CS |FI| XI | FR |FCA|FCI | FCS \n");
148 for(l=0;l<5;l++){
149 for(c=0;c<8;c++){
150
151 if(c==0)
152 { printf("%.0f ",dist[l][c]);
153 }
154 if(c==1)
155 { printf(" %.0f ",dist[l][c]);
156 }
157 if(c==2)
158 { printf(" %.0f ",dist[l][c]);
159 }
160 if(c==3)
161 { printf(" %.1f ",dist[l][c]);
162 }
163 if(c==4)
164 { printf("%.2f%% ",dist[l][c]);

165 }
166 if(c==5)
167 { printf(" %.0f ",dist[l][c]);
168 }
169 if(c==6)
170 { printf("%.1f ",dist[l][c]);
171 }
172 if(c==7)
173 { printf(" %.1f ",dist[l][c]);
174 }
175 if(l==0 && c==5)
176 { printf(" ");
177 }
178 if(l==4 && c==4)
179 { printf(" ");
180
181 }
182 }
183 printf("\n");
184 }
185 printf("\n");
186 printf("\n Histograma:");
187 l=0;
188 while (l<5)
189 {
190 c=0;
191 while (c<8)
192 {
193 if(c==2)
194 {
195 a=20;
196 FI = dist[l][c];
197 if(l==0)
198 {
199 textcolor(7);
200 textbackground(7);
201 b=25;
202 }
203 if(l==1)
204 {
205 textbackground(1);
206 textcolor(1);
207 b=28;
208 }
209 if(l==2)
210 {
211 textcolor(14);
212 textbackground(14);
213 b=31;
214 }
215 if(l==3)
216 {
217 textcolor(12);
218 textbackground(12);
219 b=34;
220 }
221 if(l==4)
222 {
223 textcolor(10);
224 textbackground(10);
225 b=37;
226 }
227 for(d=0;d<FI;d++)
228 {
229 gotoxy(b,a);
230 printf("%c%c%c",178,178,178);
231
232
233 a--;
234 }
235 gotoxy(b,a);
236 textbackground(0);
237 printf(" %d",FI);
238
239
240
241 }
242 c++;
243 }
244 l++;
245 }
246 /*for(linha=1;linha<=5;linha++)
247 {
248 textcolor(7);

249 gotoxy(10,17-linha);
250 printf("%c%c%c",178,178,178);
251 }
252 for(linha=1;linha<=5;linha++)
253 {
254 textcolor(1);
255 gotoxy(13,17-linha);
256 printf("%c%c%c",178,178,178);
257 }
258 for(linha=1;linha<=6;linha++)
259 {
260 textcolor(14);
261 gotoxy(16,17-linha);
262 printf("%c%c%c",178,178,178);
263 }
264 for(linha=1;linha<=3;linha++)
265 {
266 textcolor(12);
267 gotoxy(19,17-linha);
268 printf("%c%c%c",178,178,178);
269 }
270 for(linha=1;linha<=1;linha++)
271 {
272 textcolor(10);
273 gotoxy(22,17-linha);
274 printf("%c%c%c",178,178,178);
275 }
276 gotoxy(10,13-linha);
277 textcolor(7);
278 printf(" %d",5);
279
280 gotoxy(13,13-linha);
281 textcolor(1);
282 printf(" %d",5);
283
284 gotoxy(16,12-linha);
285 textcolor(14);
286 printf(" %d",6);
287
288 gotoxy(19,15-linha);
289 textcolor(12);
290 printf(" %d",3);
291
292 gotoxy(22,17-linha);
293 textcolor(10);
294 printf(" %d",1);*/
295
296 printf("\n\n\n\n\n\n\n");
297 textcolor(15);
298
299 for(l=0;l<20;l++)
300 { for(c=0;c<4;c++)
301 { if(c==0)
302 {
303 mat[l][c]= vet[l];
304 }
305
306 if(c==1)
307 {
308 mat[l][c] = Med_Amost;
309 }
310
311 if(c==2)
312 {
313 desvio=vet[l]-Med_Amost;
314 mat[l][c]= desvio;
315 }
316
317 if(c==3)
318 {
319 quad=(desvio*desvio);
320 mat[l][c] = quad;
321 }
322 }
323 }
324 textcolor(4);
325 textbackground(15);
326 printf(" TABELA \n");
327 textcolor(0);
328 textbackground(12);
329 printf(" X ");
330 textcolor(15);
331 textbackground(1);
332 printf(" Média ");

333 textcolor(0);
334 textbackground(8);
335 printf(" Desvio ");
336 textcolor(15);
337 textbackground(13);
338 printf(" Quadrado \n");
339 for(l=0;l<20;l++)
340 { for(c=0;c<4;c++)
341 { if(c==0)
342 { textcolor(0);
343 textbackground(12);
344 printf(" %.0f ", mat[l][c]);
345 }
346
347 if(c==1)
348 { textcolor(15);
349 textbackground(1);
350 printf(" %.2f ",mat[l][c]);
351 }
352
353 if(c==2)
354 { textcolor(0);
355 textbackground(8);
356 printf(" %.2f ", mat[l][c]);
357 }
358
359 if(c==3)
360 { textcolor(15);
361 textbackground(13);
362 printf(" %.4f ",mat[l][c]);
363 }
364 if(c==1 && l>=10 && l<=19)
365 { printf(" ", mat[l][c]);
366 }
367 if(c==2 && l>=2 && l<=19)
368 { printf(" ", mat[l][c]);
369 }
370 if(c==2 && l>=0 && l<=15)
371 { printf(" ", mat[l][c]);
372 }
373 if(c==2 && l>=0 && l<=19)
374 { printf(" ", mat[l][c]);
375 }
376 if(c==1 && l>=0 && l<=9)
377 { printf(" ", mat[l][c]);
378 }
379 if(c==2 && l>=10 && l<=19)
380 { printf(" ", mat[l][c]);
381 }
382 }printf("\n");
383 }
384 textcolor(15);
385 textbackground(0);
386 SQ=0;
387 for(l=0;l<20;l++)
388 {SQ=SQ+mat[l][3];
389 }
390 printf("\nSomatória do quadrado: %.1f\n",SQ);
391 variancia(SQ,s,N,&var);
392 printf("Variância Amostral: %.3f\n", var);
393 dpa=desvio_padrao(var);
394 printf("Desvio Padrão Amostral: %.2f\n", dpa);
395 moda=0;
396 h=0;
397 z=0;
398 N=20;
399 for (i=0;i<N;i++)
400 {
401 for (j=0;j<N;j++)
402 {
403 if (vet[i] == vet[j])
404 z=z+1;
405 }
406 if (z > h)
407 {
408 h=z;
409 moda=vet[i];
410 }
411 z=0;
412 j=0;
413 }
414 printf("Moda: %d\n\n",moda);
415 textcolor(15);
416 system("pause");

417 return 0;
418
}
