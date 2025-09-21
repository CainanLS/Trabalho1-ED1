# Best case scenario
data <- read.csv("./BestCase/BenchmarkBestCase.csv")

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