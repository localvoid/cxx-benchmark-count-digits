#!/usr/bin/env Rscript

require(ggplot2)
require(plyr)

out <- commandArgs(trailingOnly = TRUE)[1]

raw_data <- read.csv("stdin")
d <- ddply(raw_data, .(Size, Name, Digits), summarize,
           Time = median(Time))


for(i in unique(d$Size)) {
  png(filename=paste(out, i, ".png", sep="_"), width=600, height=400)

  p <- ggplot(d[d$Size==i,], aes(x=Digits, y=Time, colour=Name)) +
         geom_line() +
         scale_x_discrete() +
         scale_colour_brewer(palette="Set1") +
         labs(title=paste("Integer size:", i, "bits")) +
         theme_bw()
  print(p)

  dev.off()
}

