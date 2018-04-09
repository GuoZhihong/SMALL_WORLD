jack：
12/03/2018 main 第12行 加了测试用的regionList1
	   第86行 regionList1被赋值maploader 
14/03/2018 main85行map对象
	   123行 重复conquer方法
	   player411行传入参数map变成指针 解决了两个玩家共同操作一个map值没有被修改的问题
	   player442-451行把输入检查抽出方法在115，139，151行 输入检查问题解决 
	   ？遗留问题 除了第一轮之后还可以把水区占领 应该写个方法 解决除了特殊技能以外 都不能占领 （解决！）

15/03/2018 main里面mainloop换成我自己的 还有后面的score
	   player里加了若干方法 conquere 整体都改了 遗留问题：conquer整体逻辑要深入看，缺少 redistribution，score方法肯定有问题

16/03/2018 player里加了若干方法 conquere 整体都改了加了用户选择要用多少token占地现在完全conquer没问题 遗留问题：（1）但是中间判断条件enable那个有可能有问题（特殊能力什么的）（3）score方法肯定有问题,			 （4）色子不变,