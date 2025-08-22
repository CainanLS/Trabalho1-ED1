data <- read.csv("../benchmark.csv")

bench_seq <- data[data[, "tipo"] == "S", ]

png("resultSequential.png")

plot(bench_seq[, "qtdElementos"], bench_seq[, "tempo"],
     xlab = "n° de elementos", ylab = "Tempo em microssegundos",
     main = "Tempo de processamento da Busca Sequencial", type = "b")

bench_it <- data[data[, "tipo"] == "I", ]

png("resultIterative.png")

plot(bench_it[, "qtdElementos"], bench_it[, "tempo"],
     xlab = "n° de elementos", ylab = "Tempo em microssegundos",
     main = "Tempo de processamento da Busca Binária Iterativa", type = "b")

bench_req <- data[data[, "tipo"] == "R", ]

png("resultRecursive.png")

plot(bench_req[, "qtdElementos"], bench_req[, "tempo"],
     xlab = "n° de elementos", ylab = "Tempo em microssegundos",
     main = "Tempo de processamento da Busca Binaria Recursiva", type = "b")

dev.off()