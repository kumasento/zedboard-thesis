# Zynq Bootstrap Notes (1)

@(Thesis)[Zynq, Vivado, ZynqBootstrapNote]

## 1. 如何连接Zynq与Linux PC

(暂略)

## 2. 如何实现基础Zynq设计

### 2.1 Zynq应用架构

Zynq是ARM CPU与FPGA的平台，二者通过AXI进行通信。AXI(Advanced eXtensible Interface)是一种协议，属于[ARM AMBA](www.amba.com)，是一种类似于PCIe的总线(bus)设计。

| 应用架构名称 	|  CPU		| FPGA		| 通信方式 		|
| :--------  	| --------:	| :------: 	| :-----: 		|
| 一般应用   		| x86 		| 各种厂商  	| PCIe或以太网	|
| Zynq应用		| ARM		| Xilinx	| AXI			|

在设计Zynq应用时，一般分为如下模块：
1. 设计硬件逻辑(Vivado HLS)
2. 设计软件逻辑(高级语言)
3. **嵌入AXI的适配器(Adapter)**来通信(IP core与通信库)

### 2.2 基础Zynq应用

参考教程中的[lab3](http://users.ece.utexas.edu/~gerstl/ee382v_f14/soc/vivado/Vivado_lab03.pdf)，该应用实现了如下功能：
1. SW8 switches的读取
2. BTNS5 的读取

**大致实现步骤如下**：
1. Vivado中：
	1. 插入[Processing System 7](http://www.xilinx.com/products/intellectual-property/processing_system7.html) IP
	2. 插入AXI GPIO IP，并且与SW8绑定
	3. 插入AXI GPIO IP，并且与BTNS5绑定
	4. 进行IP组件之间的链接，并且将GPIO接口暴露到外部以进行读写
2. 打开Xilinx SDK：
	1. 写好main函数，其中包含GPIO的driver的初始化，以及读取函数和打印函数，以显示字符；
	2. 将FPGA bitstream program到板子上
	3. 启动应用，使用板子上的按钮进行交互

几个可能会出现的问题：
1. Program的时候要准备链接到PROG接口，而不是UART接口（这个是用来进行Serial Console链接的）
2. 该应用必须要求Linux不能boot，否则会出现MMU访问的问题（主要是Linux会控制内存访问的区间）
