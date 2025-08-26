data <- read.csv("../BenchmarkRandom.csv")

bench_seq <- data[data[, "tipo"] == "S", ]

pdf("resultRandom.pdf")

plot(bench_seq[, "qtdElementos"], bench_seq[, "tempo"],
     xlab = "n° de elementos", ylab = "Tempo em microssegundos",
     main = "Tempo de processamento da Busca Sequencial", type = "b")

bench_it <- data[data[, "tipo"] == "I", ]

plot(bench_it[, "qtdElementos"], bench_it[, "tempo"],
     xlab = "n° de elementos", ylab = "Tempo em microssegundos",
     main = "Tempo de processamento da Busca Binária Iterativa", type = "b")

bench_req <- data[data[, "tipo"] == "R", ]

plot(bench_req[, "qtdElementos"], bench_req[, "tempo"],
     xlab = "n° de elementos", ylab = "Tempo em microssegundos",
     main = "Tempo de processamento da Busca Binaria Recursiva", type = "b")


# Best case scenario
data <- read.csv("../BenchmarkBestCase.csv")

bench_seq <- data[data[, "tipo"] == "S", ]

pdf("resultBest.pdf")

plot(bench_seq[, "qtdElementos"], bench_seq[, "tempo"],
     xlab = "n° de elementos", ylab = "Tempo em microssegundos",
     main = "Tempo de processamento da Busca Sequencial", type = "b")

bench_it <- data[data[, "tipo"] == "I", ]

plot(bench_it[, "qtdElementos"], bench_it[, "tempo"],
     xlab = "n° de elementos", ylab = "Tempo em microssegundos",
     main = "Tempo de processamento da Busca Binária Iterativa", type = "b")

bench_req <- data[data[, "tipo"] == "R", ]

plot(bench_req[, "qtdElementos"], bench_req[, "tempo"],
     xlab = "n° de elementos", ylab = "Tempo em microssegundos",
     main = "Tempo de processamento da Busca Binaria Recursiva", type = "b")


# Worst Case Scenario
data <- read.csv("../BenchmarkWorstCase.csv")

bench_seq <- data[data[, "tipo"] == "S", ]

pdf("resultWorst.pdf")

plot(bench_seq[, "qtdElementos"], bench_seq[, "tempo"],
     xlab = "n° de elementos", ylab = "Tempo em microssegundos",
     main = "Tempo de processamento da Busca Sequencial", type = "b")

bench_it <- data[data[, "tipo"] == "I", ]

plot(bench_it[, "qtdElementos"], bench_it[, "tempo"],
     xlab = "n° de elementos", ylab = "Tempo em microssegundos",
     main = "Tempo de processamento da Busca Binária Iterativa", type = "b")

bench_req <- data[data[, "tipo"] == "R", ]

plot(bench_req[, "qtdElementos"], bench_req[, "tempo"],
     xlab = "n° de elementos", ylab = "Tempo em microssegundos",
     main = "Tempo de processamento da Busca Binaria Recursiva", type = "b")

dev.off()