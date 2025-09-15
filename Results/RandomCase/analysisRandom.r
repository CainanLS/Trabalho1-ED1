data <- read.csv("./BenchmarkRandom.csv")

bench_seq <- data[data[, "tipo"] == "S", ]
bench_it <- data[data[, "tipo"] == "I", ]
bench_req <- data[data[, "tipo"] == "R", ]

x <- 1:max(bench_seq[, "qtdElementos"])


png("RandomSequential.png")

plot(bench_seq[, "qtdElementos"], bench_seq[, "tempo"],
     xlab = "n° de elementos", ylab = "Tempo em nanosegundos",
     main = "Tempo de processamento da Busca Sequencial",
     type = "b", col = "blue", pch = 16)

par(new = TRUE)

plot(x, x, col = "red", type = "l",
     axes = FALSE, xlab = "", ylab = "")

legend("topleft", legend = c("Resultado", "Expectativa"),
       col = c("blue", "red"), pch = c(16, 17))


png("RandomIterative.png")

plot(bench_it[, "qtdElementos"], bench_it[, "tempo"],
     xlab = "n° de elementos", ylab = "Tempo em nanosegundos",
     main = "Tempo de processamento da Busca Binária Iterativa",
     type = "b", col = "blue", pch = 16)

par(new = TRUE)

plot(x, log(x), col = "red", type = "l",
     axes = FALSE, xlab = "", ylab = "")

legend("topleft", legend = c("Resultado", "Expectativa"),
       col = c("blue", "red"), pch = c(16, 17))


png("RandomRescursive.png")

plot(bench_req[, "qtdElementos"], bench_req[, "tempo"],
     xlab = "n° de elementos", ylab = "Tempo em nanosegundos",
     main = "Tempo de processamento da Busca Binaria Recursiva",
     type = "b", col = "blue", pch = 16)

par(new = TRUE)

plot(x, log(x), col = "red", type = "l",
     axes = FALSE, xlab = "", ylab = "")

legend("topleft", legend = c("Resultado", "Expectativa"),
       col = c("blue", "red"), pch = c(16, 17))

dev.off()