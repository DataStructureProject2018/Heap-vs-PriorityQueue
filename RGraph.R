# Reading the queue file, and saving each line in a vector
queue <- file("queueFile.txt",open="r")
lineQueue <-readLines(queue)
close(queue)

# Reading the heap file, and saving each line in a vector
heap <- file("heapFile.txt",open="r")
lineHeap <-readLines(heap)
close(heap)

# For index purposes
i <- 1
j <- 1

#Declaring the empty arrays that will hold the coordinates
queuex <- c(0)
queuey <- c(0)
heapx <- c(0)
heapy <- c(0)

# Placing each value in its respective array
while(i <= length(lineHeap)){
  heapx[j] <- as.numeric(lineHeap[i])
  heapy[j] <- as.numeric(lineHeap[i+1])
  queuex[j] <- as.numeric(lineQueue[i])
  queuey[j] <- as.numeric(lineQueue[i+1])
  i <- i+2
  j <- j+1
}

# Plotting queue graph
plot(queuex, queuey, type="p", col="blue", ann = FALSE, bg="blue", pch=21:21)
# Plotting heap graph
lines(heapx, heapy, type="p", col="red", pch=21:21, bg="red")

# Adding Titles
title(main="Heap vs Priority Queue", col.main="red", font.main=4)
title(xlab="Numero Escolhido", col.lab=rgb(0,0.5,0))
title(ylab="Quantidade de comparacoes", col.lab=rgb(0,0.5,0))

# Adding the Legend
legend("topright", c("PQueue","Heap"), cex=0.8, 
       col=c("blue","red"), pch=21:21, lty=1:1, ) 
legend("topleft", c("Max Queue","Max Heap", "Min Queue",
                    "Min Heap", max(queuey), max(heapy),
                    min(queuey), min(heapy)),
       cex=0.8, ncol = 2, text.width = 2000)
