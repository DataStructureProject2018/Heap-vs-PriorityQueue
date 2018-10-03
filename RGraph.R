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

# Variabels to help the Bubble Sort
aux <- 0
n <- length(lineHeap)/2

## Sorting queuex and heapx and changing queuey and heapy when necessary
for(i in 1:(n-1)){
  for(j in 1:(n-i)){
    if(heapx[j+1]<heapx[j])
    {
      aux <- heapx[j]
      heapx[j] <- heapx[j+1]
      heapx[j+1] <- aux

      # WE NEED TO CHANGE THE heapy ALSO

      aux <- heapy[j]
      heapy[j] <- heapy[j+1]
      heapy[j+1] <- aux
    }
    if(queuex[j+1]<queuex[j])
    {
      aux <- queuex[j]
      queuex[j] <- queuex[j+1]
      queuex[j+1] <- aux

      # WE NEED TO CHANGE THE queuey ALSO

      aux <- queuey[j]
      queuey[j] <- queuey[j+1]
      queuey[j+1] <- aux
    }
  }
}
# Plotting queue graph
plot(queuex, queuey, type="p", col="blue", ann = FALSE, pch=21:21)
# Plotting heap graph
lines(heapx, heapy, type="p", col="red", pch=21:21)

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
