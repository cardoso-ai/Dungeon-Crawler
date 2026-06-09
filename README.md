# 🗡️ A Lenda do Cristal Sombrio

> *Um dungeon crawler em C, desenvolvido como projeto da disciplina de Programação I — Engenharia de Computação.*

---

## 📖 História

O reino de **Eldoria** vivia em paz graças ao **Cristal da Aurora**, uma gema mágica que mantinha as trevas afastadas. Mas numa noite fatídica, o necromante **Valdrak** roubou o cristal e o levou para as profundezas da **Masmorra das Sombras**.

Você, o último guardião de Eldoria, parte da vila de **Arenor** em direção à masmorra. Três andares de perigo te aguardam. No fundo, Valdrak espera... e o cristal deve ser recuperado.

---

## 🎮 Como Jogar

### Controles

| Tecla | Ação |
|-------|------|
| `w` | Mover para cima |
| `a` | Mover para a esquerda |
| `s` | Mover para baixo |
| `d` | Mover para a direita |
| `i` | Interagir com objeto à frente |
| `o` | Atacar |
| `q` | Sair para o menu |

### Objetivo

1. Fale com o ferreiro na vila e escolha sua arma
2. Entre na masmorra e explore os 3 andares
3. Colete chaves, abra portas e destrua caixas
4. Derrote o boss final **Valdrak** e recupere o Cristal da Aurora

### Sistema de Vidas

- Você começa com **3 vidas**
- Perde 1 vida ao tocar em espinhos ou inimigos
- Ao perder todas as vidas → **Game Over**
- Ao derrotar Valdrak → **Vitória**

---

## ⚔️ Armas

| Arma | Área de Ataque |
|------|---------------|
| **Espada** | 3×2 células à frente do jogador |
| **Arco e Flecha** | Linha reta, 4 células à frente |
| **Cajado** | 8 células ao redor do jogador |

---

## 🗺️ Estrutura do Jogo

| Fase | Mapa | Descrição |
|------|------|-----------|
| Vila de Arenor | 10×10 | Escolha sua arma com o ferreiro |
| Andar 1 | 10×10 | Tutorial: chaves, portas e caixas |
| Andar 2 | 15×15 | Espinhos, botões e monstros vagantes |
| Andar 3 | 25×25 | Desafio final com o boss Valdrak |

---

## 🔣 Símbolos do Mapa

| Símbolo | Significado |
|---------|-------------|
| `^ < v >` | Jogador (indica a direção que está olhando) |
| `*` | Parede (intransponível) |
| `#` | Espinho (mata ao pisar) |
| `k` | Caixa (destruível com ataque) |
| `O` | Botão (interagir com `i`) |
| `D` | Porta fechada |
| `@` | Chave (coletada ao pisar) |
| `=` | Porta aberta |
| `L` | Escada (próxima fase) |
| `X` | Monstro Tipo 1 (movimento aleatório) |
| `Y` | Monstro Tipo 2 (persegue o jogador) |
| `Z` | Boss Final — Valdrak |
| `N` | NPC (ferreiro da vila) |
| `.` | Chão livre |

---

## 🤖 Inimigos

- **Monstro Tipo 1 `X`** — Move-se aleatoriamente a cada turno
- **Monstro Tipo 2 `Y`** — Persegue o jogador pela diferença de posição
- **Boss Valdrak `Z`** — A cada 3 turnos se **teletransporta** para o canto mais longe do jogador e **invoca espinhos** ao redor; nos outros turnos persegue

---

## 🛠️ Como Compilar e Executar

### GCC (Linux/Mac)
```bash
gcc -o dungeon Definitivo_Dungeon.c
./dungeon
```

### Falcon C++ (Windows)
Abra o arquivo `Definitivo_Dungeon.c` no Falcon C++, compile e execute normalmente.

---

## 🧑‍💻 Tecnologias

- Linguagem: **C**
- I/O: `printf` / `getchar`
- Sem ponteiros, structs, strings ou arquivos
- Conceitos usados: variáveis, `if/else`, `while`, `for`, `goto`, funções, vetores e matrizes

---

## 🤖 Uso de IA Generativa

Este projeto utilizou IA generativa (Claude - Anthropic) como **ferramenta de auxílio no desenvolvimento**, especialmente para estruturar o código, depurar bugs de buffer de entrada no Falcon C++ e organizar a lógica dos mapas. Todo o código foi revisado, compreendido e validado pelos integrantes da equipe.

---

## 👥 Desenvolvedores

- [Everaldo Cardoso Silva]
- [Andrey Diego Damasceno Nascimento]
- [João Gabriel Valadares Texeira]

---

*Disciplina: Programação I — Engenharia de Computação*
