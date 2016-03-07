# Zynq Paper Read Note

## Introduction

This paper has introduced Zynq cluster (Zedwulf) to solve **communication-bound** sparse graph algorithm. This solution has better performance in both computation and power effiency.

Zynq is a Xilinx commodity SoC, with an ARM CPU and a programmable FPGA logic on board. CPU and FPGA share data through ACP/AXI and memories. Zedwulf has 32 Zynq boards, each of them connected to each other through ethernet and a center switch.

## Zedwulf

A cluster of Zynq boards, connected through center switch. Detailed profiling results could be found in section II.

Generally speaking, Zedwulf has no advantage than common x86 devices, except power consumption(Table 1).

## Algorithm

Neuron network algorithm. Each Zynq node will hold many neurons and share data with other nodes. Each neuron will read information from same-board neurons or other-board neurons.

## Result

Looks good in the energy efficiency.
