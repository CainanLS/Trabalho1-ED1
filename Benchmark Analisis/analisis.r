data <- read.csv("../benchmark.csv")
print(data)

bench_seq <- data[data[, "tipo"] == "S", ]
print(bench_seq)

bench_it <- data[data[, "tipo"] == "I", ]
print(bench_it)

bench_req <- data[data[, "tipo"] == "R", ]
print(bench_req)