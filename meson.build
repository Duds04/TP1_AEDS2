project('TP1_AEDS2', 'c')

gtkdep = dependency('gtk+-3.0')

headers = ['include.h', 'ocorrencias.h', 'patricia.h', 'leitura.h', 'palavra.h']

include_dir = include_directories('arquivoC')

arquivoC = ['./arquivoC/ocorrencias.c', './arquivoC/patricia.c', './arquivoC/leitura.c', './arquivoC/palavra.c']

executable('demo', 'main.c', arquivoC, include_directories:include_dir, dependencies : gtkdep, link_args:['-lm'])