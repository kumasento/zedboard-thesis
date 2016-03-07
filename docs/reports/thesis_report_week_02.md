# Thesis Report: Week #2

本周完成的任务：
1. 熟悉了一整套Zedboard应用开发的流程，包括：
	- 利用Vivado IP Integrator创建硬件设计
	- 利用Xilinx SDK编写软件设计，与综合好的硬件交互
	- 编译，上传bitstream与serial console
	- 实现的代码已经上传到[Github](https://github.com/kumasento/zedboard-thesis/tree/lab3/examples/2014_zynq_labs/lab3)，并在硬件实验室中测试成功。
2. 阅读了一些机器学习在FPGA上实现的材料，包括：
	- [Machine Learning on FPGA, Jason Cong](http://cadlab.cs.ucla.edu/~cong/slides/HALO15_keynote.pdf)
	- [Optimizing FPGA-based Accelerator Design for DeepConvolutional Neural Networks, C. Zhang](http://cadlab.cs.ucla.edu/~cong/slides/fpga2015_chen.pdf)
	- 以及其他两篇Zedboard集群的论文

第三周计划：
1. 继续熟悉学习Zedboard，主要了解一下几种功能：
	- **更复杂的逻辑**：比如如何在Zedboard上实现向量点乘、基本的图像处理算法？
	- **数据流**：如何创建更通用的AXI GPIO？（非按钮）
	- 可以通过学习这些材料：
		1. [EE328V, Fall 2014](http://users.ece.utexas.edu/~gerstl/ee382v_f14/labs/project/Board_Tutorial.htm)
		2. [ECE522](http://ece-research.unm.edu/jimp/codesign/)
2. 尝试了解Caffe等深度学习框架的实现，看看有没有机会做些改动或者简化。

从第四周开始正式进入论文的算法编写，希望能在两周内完成基于单块Zedboard的算法的基础实现。