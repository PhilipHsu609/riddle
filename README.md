# Riddles

Personal solutions to programming puzzle sites, in C++ and Rust.

| Site | Directory | Puzzle path | Make prefix |
|---|---|---|---|
| [Advent of Code](https://adventofcode.com) | `advent-of-code/` | `<year>/DayNN/` | `aoc-` |
| [Project Euler](https://projecteuler.net) | `project-euler/` | `NNNN/` | `euler-` |
| [Everybody Codes](https://everybody.codes) | `everybody-codes/` | `<year>/QuestNN/` | `ec-` |

## Usage

Needs `clang`, `cmake`, `fmt`, and `rustc`.

```bash
make aoc-add DAY=5                  # scaffold (add LANGUAGE=rust for Rust)
make aoc-run DAY=5                  # build and run (YEAR defaults to current)
make euler-run N=12
make ec-run YEAR=2025 QUEST=3
make all | clean | rust-project
```

Each site also works standalone: `cd advent-of-code && make run DAY=5`.
