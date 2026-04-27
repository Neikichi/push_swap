# push_swap — Stack Sorting with Limited Operations

> **42KL Core — Module 2**

`push_swap` sorts a list of integers using **two stacks** (`a` and `b`) and a limited set of stack operations, outputting the minimum sequence of operations needed to sort stack `a` in ascending order. A `checker` binary (bonus) can verify that a given sequence of operations correctly sorts the input.

---

## 📁 Project Structure

```
m2/push_swap/
├── include/
│   └── push_swap.h      # Structs, typedefs, all function prototypes
├── src/
│   ├── main.c           # Entry point — argument parsing and program flow
│   ├── push_swap.c      # Algorithm dispatcher (simple/iterative/quicksort)
│   ├── push_swap1.c / push_swap2.c  # Simple sorts (2, 3, 5 elements)
│   ├── ps_is.c          # Iterative sort (≤ 100 elements)
│   ├── ps_qs.c / ps_qs2.c / ps_pivot.c  # Quicksort variant (> 100 elements)
│   ├── op_utils.c / op_utils2.c   # Stack operation implementations
│   ├── stacks_utils.c–3 # Stack initialisation, validation, cleanup
│   ├── swap_utils.c–3   # Swap operation helpers
│   └── print_utils.c    # Debug printing
├── bonus/               # Checker program source
├── libft/               # Bundled libft
├── Makefile
└── arg.sh               # Helper script to generate random test arguments
```

---

## 🔢 Stack Operations

All operations are printed to **stdout**, one per line:

| Operation | Effect |
|---|---|
| `sa` | Swap top two elements of stack `a` |
| `sb` | Swap top two elements of stack `b` |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of `b` onto `a` |
| `pb` | Push top of `a` onto `b` |
| `ra` | Rotate `a` upward (first → last) |
| `rb` | Rotate `b` upward |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse-rotate `a` (last → first) |
| `rrb` | Reverse-rotate `b` |
| `rrr` | `rra` and `rrb` simultaneously |

---

## 🧠 Algorithm

The algorithm adapts based on input size for optimal move counts:

| Input size | Strategy |
|---|---|
| 1–3 elements | **Simple sort** — hardcoded optimal sequences |
| 4–5 elements | **Extended simple sort** — push then simple sort top 3 |
| 6–100 elements | **Iterative sort** — greedy insertion-like approach |
| > 100 elements | **Quicksort variant** — pivot-based partitioning across stacks |

### Quicksort Overview (> 100 elements)

1. Find a median pivot using `quicksort()` on a copy of the array.
2. Push elements smaller than the pivot to stack `b` in two passes.
3. Recurse on the top half of `a` and bottom of `b`.
4. Push everything back to `a` in sorted order.

---

## 🔧 Data Structures

```c
typedef struct s_stacks {
    t_list *a;     // Stack A (linked list)
    t_list *b;     // Stack B (linked list)
    t_list *ds;    // Sorted reference copy
    t_list *ea;    // End of stack A
    t_list *eb;    // End of stack B
    int     size;  // Total number of elements
    t_op    op;    // Operation buffering (for optimisation)
} t_stacks;
```

Each `t_list` node stores an integer value with an associated **normalised index** (rank 0 to N-1), making comparisons O(1) without repeated searching.

---

## 🚀 Usage

### push_swap (mandatory)

```bash
# Sort a list of numbers and print operations
./push_swap 3 2 1 4 5

# Using a variable
ARG="4 67 3 87 23"; ./push_swap $ARG

# Pipe to wc to count operations
./push_swap $(./arg.sh 100) | wc -l
```

### checker (bonus)

```bash
# Verify that operations produce a sorted stack
./push_swap 3 2 1 | ./checker 3 2 1
# Output: OK (sorted) or KO (not sorted)

# Manual input
./checker 3 2 1
sa
pa
^D
```

---

## 📊 Performance Targets

| Input size | Expected max operations |
|---|---|
| 3 numbers | ≤ 3 |
| 5 numbers | ≤ 12 |
| 100 numbers | ≤ 700 |
| 500 numbers | ≤ 5500 |

---

## ⚠️ Error Handling

| Condition | Output |
|---|---|
| Non-integer argument | `Error\n` to stderr |
| Duplicate values | `Error\n` to stderr |
| Integer overflow | `Error\n` to stderr |
| Already sorted | No output (0 operations) |
| Empty input | No output |

---

## 🛠️ Build

The project uses a plain `Makefile` — no cmake or `compile_flags.txt` required.

```bash
# Build push_swap
make

# Build push_swap + checker (bonus)
make bonus

# Clean
make clean
make fclean
make re
```

---

## 📝 Notes

- Arguments can be passed as separate words (`./push_swap 3 2 1`) or as a single quoted string (`./push_swap "3 2 1"`).
- The `arg.sh` script generates `N` random non-repeating integers for testing: `./arg.sh 500`.
- A `checker_linux` binary is included as a reference checker for Linux systems.
- The iterative sort uses normalised indices (ranks) rather than raw values to simplify comparisons and reduce the number of operations.
