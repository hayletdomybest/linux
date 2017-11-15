set transparency=11 
"set background=dark 
syntax on
syntax enable
set mouse=a
set mousehide
set encoding=utf-8
scriptencoding utf-8
set backup 


inoremap { {}<ESC>i
inoremap {<CR> {<CR>}<ESC>O
set cursorline 
set number
set autoindent 
set smartindent 
set cindent 
set softtabstop=4 
set shiftwidth=4 
set tabstop=4 
set expandtab 
set softtabstop=4 
colorscheme desert 
set showmatch 
set ruler 
set incsearch 
set hlsearch 
set guioptions-=T 
set showcmd
set guifont=Menlo:h15 
set lines=55 
set columns=100
set whichwrap=b,s,<,>,[,] 
set scrolloff=3 
set history=1000 
set autowrite 
set guioptions-=m 
set ignorecase 
filetype plugin indent on 
filetype plugin on 
filetype on 
set cmdheight=2 

autocmd BufWritePost $MYVIMRC source $MYVIMRC

"set nocompatible

set wildmenu
