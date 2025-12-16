# Cobertura de Código em C com gcov, gcovr e lcov

Curso de Residência Tecnológica para o Setor Automotivo (SWT3)

Tutorial prático de cobertura de código em C utilizando **gcov**, **gcovr** e **lcov**, com e sem o uso de framework de testes (**Unity Test Framework**).
Autora: Eryca F. de Moura e Silva

---
## Tutorial

O tutorial completo em HTML está disponível via **GitHub Pages**:

**https://erycaaf.github.io/tutorial-gcov-lcov-gcovr/**
---

## Visão geral

Este projeto tem como objetivo demonstrar, de forma **didática e reproduzível**, como medir cobertura de código em projetos escritos em C, abordando:

* Instrumentação de código com o GCC
* Geração de dados de cobertura com gcov
* Consolidação e visualização de cobertura com gcovr e lcov
* Execução de testes sem framework
* Execução de testes com Unity Test Framework
* Automação de todo o fluxo por meio de Makefile

---

## Estrutura do projeto

* **src/**: código-fonte do módulo de exemplo
* **test/**: testes unitários (com e sem Unity)
* **docs/**: tutorial HTML publicado via GitHub Pages
* **Makefile**: automação de build, execução e cobertura

---

## Ferramentas utilizadas

* **GCC / gcov** – instrumentação e coleta de dados de cobertura
* **gcovr** – geração de relatórios (terminal, HTML, XML, JSON)
* **lcov / genhtml** – relatórios HTML detalhados
* **Unity Test Framework** – framework de testes unitários em C
---

## Pré-requisitos

* GCC instalado
* Python (para gcovr)
* Sistema Linux ou WSL (recomendado para uso do lcov)

## Observações importantes

* Os arquivos `.gcda` só são gerados **após a execução** do binário de testes
* Utilize sempre `-O0` para evitar problemas de otimização na cobertura
* Execute `make clean` antes de novos testes para garantir resultados corretos
