# Best case scenario
data <- read.csv("./BestCase/BenchmarkBestCase.csv")
inv <- read.csv("./Inverted/Inverted.csv")

best_seq <- data[data[, "tipo"] == "S", ]
best_it <- data[data[, "tipo"] == "I", ]
best_req <- data[data[, "tipo"] == "R", ]

# Worst Case Scenario
data <- read.csv("./WorstCase/BenchmarkWorstCase.csv")

worst_seq <- data[data[, "tipo"] == "S", ]
worst_it <- data[data[, "tipo"] == "I", ]
worst_req <- data[data[, "tipo"] == "R", ]

data <- read.csv("./RandomCase/BenchmarkRandom.csv")

rand_seq <- data[data[, "tipo"] == "S", ]
rand_it <- data[data[, "tipo"] == "I", ]
rand_req <- data[data[, "tipo"] == "R", ]

png("analysisAll.png")

plot(inv[, "qtdElementos"], inv[, "tempo"],
     xlab = "n° de elementos", ylab = "Tempo em nanosegundos",
     main = "Tempo de processamento Best Case",
     type = "b", col = "blue", pch = 16)

par(new = TRUE)

plot(best_seq[, "qtdElementos"], best_seq[, "tempo"],
     xlab = "", ylab = "", axes = FALSE,
     type = "b", col = "red", pch = 15)

par(new = TRUE)

plot(best_it[, "qtdElementos"], best_it[, "tempo"],
     xlab = "", ylab = "", axes = FALSE,
     type = "b", col = "#5d0081", pch = 14)

par(new = TRUE)

plot(best_req[, "qtdElementos"], best_req[, "tempo"],
     xlab = "", ylab = "", axes = FALSE,
     type = "b", col = "#b3b300", pch = 13)


legend("topright", legend = c("Inverter", "Sequencial", "Iterativo", "Recursivo"),
       col = c("blue", "red", "#5d0081", "#b3b300"), pch = c(16, 15, 14, 13))