#!/usr/bin/env Rscript

require(ggplot2)
require(plyr)

out <- commandArgs(trailingOnly = TRUE)[1]

raw_data <- read.csv("stdin")
d <- ddply(raw_data, .(Size, Name, Digits), summarize,
           Time = median(Time))


for(i in unique(d$Size)) {
  png(filename=paste0(paste(out, i, sep="_"), ".png"), width=800, height=600)

  p <- ggplot(d[d$Size==i,], aes(x=Digits, y=Time, colour=Name)) +
         geom_line() +
         scale_x_discrete() +
         labs(title=paste("Integer size:", i, "bits")) +
         theme_bw()
  print(p)

  dev.off()
}

