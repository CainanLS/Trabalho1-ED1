# Best case scenario
data <- read.csv("./BenchmarkBestCase.csv")

bench_seq <- data[data[, "tipo"] == "S", ]
bench_it <- data[data[, "tipo"] == "I", ]
bench_req <- data[data[, "tipo"] == "R", ]

x <- 1:max(bench_seq[, "qtdElementos"])


png("BestSequential.png")

plot(bench_seq[, "qtdElementos"], bench_seq[, "tempo"],
     xlab = "n° de elementos", ylab = "Tempo em nanosegundos",
     main = "Tempo de processamento da Busca Sequencial\nBest Case - O(1)",
     type = "b", col = "blue", pch = 16, ylim = c(0, max(bench_seq[, "tempo"]) * 2))

par(new = TRUE)

abline(h = median(bench_seq[, "tempo"]), col = "red")

legend("topleft", legend = c("Resultado", "Expectativa"),
       col = c("blue", "red"), pch = c(16, 17))


png("BestIterative.png")

plot(bench_it[, "qtdElementos"], bench_it[, "tempo"],
     xlab = "n° de elementos", ylab = "Tempo em nanosegundos",
     main = "Tempo de processamento da Busca Binária Iterativa\nBest Case - O(1)",
     type = "b", col = "blue", pch = 16, ylim=c(0, (max(bench_it[, "tempo"]) * 2)))

par(new = TRUE)

abline(h = median(bench_it[, "tempo"]), col = "red")

legend("topleft", legend = c("Resultado", "Expectativa"),
       col = c("blue", "red"), pch = c(16, 17))


png("BestRecursive.png")

plot(bench_req[, "qtdElementos"], bench_req[, "tempo"],
     xlab = "n° de elementos", ylab = "Tempo em nanosegundos",
     main = "Tempo de processamento da Busca Binaria Recursiva\nBest Case - O(1)",
     type = "b", col = "blue", pch = 16, ylim=c(0, (max(bench_req[, "tempo"]) * 2)))

par(new = TRUE)

abline(h = median(bench_req[, "tempo"]), col = "red")

legend("topleft", legend = c("Resultado", "Expectativa"),
       col = c("blue", "red"), pch = c(16, 17))

dev.off()