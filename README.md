# isletim_sistemleri_proje2_pipe
prosesler arası pipe haberleşme yöntemi ile 3x3 matris determinantı hesaplayan basit shell programı (Linux platform)

E : simple shell using fork() , exec(), pipe structure to compute determinant of a 3x3 matrix
<h2>3 Progs:</h2>
1.satsutsec :randomly select row/column , send it to pipe</br>
2.kofakhesap2x2 :compute cofactor of elements in selected row/cloumn by remain matrix(2x2), write to pipe, get next element..</br>
3.Determinant3x3 : </br>- let user enter 3x3 matrix</br>- print randomly selected row/column by satsutsec</br>- send elements one by one to kofakhesap2x2</br>- get the result from pipe</br>- sum all results & print determinant</br>- let user enter another 3x3 matrix..
</br>

<h2>Tips:</h2>
<i>Download files</i>
<i>in Terminal : </br>
  >>makeFile (to compile c files) </br>
  >>./determinant3x3 (to run main prog) </br>
  >>enter matrix elements by order 1 to 9 (negative numbers arw allowed) </br>
  >>new determinant computing? (Y/N) </br>
  +screenshots in the<a href= "https://github.com/AlaaMarawi/isletim_sistemleri_proje2_pipe/blob/master/Rapor.pdf"> report</a>.
</i>
</br>

