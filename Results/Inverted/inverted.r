data <- read.csv("./Inverted.csv")

png("Inverted.png")

x <- 1:max(data)

plot(data[, "qtdElementos"], data[, "tempo"],
    xlab = "nº de elementos", ylab = "Tempo em nanosegundos",
    main = "Tempo de processamento da Inversão de Array\n O(n)",
    type = "b", col = "blue", pch = 16)

par(new = TRUE)

plot(x, x, col = "red", type = "l",
    axes = FALSE, xlab = "", ylab = "")

legend("topleft", legend = c("Resultado", "Expectativa"),
        col = c("blue", "red"), pch = c(16, 17))

dev.off()