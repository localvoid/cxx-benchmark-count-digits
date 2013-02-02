#!/usr/bin/env Rscript

require(ggplot2)
require(plyr)

out <- commandArgs(trailingOnly = TRUE)[1]

raw_data <- read.csv("stdin")
d <- ddply(raw_data, .(Size, Name, Digits), summarize,
           Time = median(Time))

pdf(file=out)

for(i in unique(d$Size)) {
  p <- ggplot(d[d$Size==i,], aes(x=Digits, y=Time, colour=Name)) +
         geom_line() +
         scale_y_continuous(limits=c(0, max(d$Time))) +
         scale_x_discrete() +
         scale_colour_brewer(palette="Set1") +
         labs(title=paste("Integer size:", i, "bits")) +
         theme_bw()
  print(p)
}

dev.off()