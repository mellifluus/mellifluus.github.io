const analysis = document.querySelectorAll('.algo_analysis');

analysis.forEach(item => {
  const [code, txt] = item.querySelectorAll('pre');

  code.addEventListener('scroll', () => {
    txt.scrollTop = code.scrollTop;
    txt.scrollLeft = code.scrollLeft;
  });
  
  txt.addEventListener('scroll', () => {
    code.scrollTop = txt.scrollTop;
    code.scrollLeft = txt.scrollLeft;
  });
})