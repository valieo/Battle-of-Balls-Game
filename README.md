# Battle-of-Balls-Game
仿球球大作战小游戏 C++课程作业

## 开发工具和语言
C++、VS2019、acclib库

## 玩法介绍
### 基本功能
游戏中共有8个敌人、20个精灵和无数糖果，玩家扮演一个球精灵，需要不停地奔跑，获取糖果让自己变得更大，才能对抗那些更强的敌人，寻找并消灭所有敌人即可获得胜利。

游戏开始时，玩家具有3秒的无敌时间，此时敌人不会对玩家造成伤害。3秒之后，比玩家弱的敌人遇到玩家后会逃跑，比玩家强的敌人遇到玩家会追击，精灵的运动则不受玩家影响，玩家可据此区分敌人与精灵。

玩家可以吃掉所有比自己小的物体（包括敌人、精灵、糖果）来让自己变得更大，当玩家消灭掉8个敌人后即可获得胜利，反之，玩家被敌人吃掉后即失败。 游戏中的糖果被吃掉后过一段时间会再次出现，因此不用担心把糖果吃完。

所有会动的物体（玩家控制的小球、精灵、敌人）在碰到地图边界后均会被反弹而改变速度方向，可以据此将敌人困在地图边界的角落，从而消灭敌人。
![game1](https://user-images.githubusercontent.com/84364367/123515708-14c39800-d6cb-11eb-8f00-0525c8ad6f92.jpg)


### 按键操作
- 控制主角移动：鼠标左键或右键
- 重新开始游戏：R键
- 暂停游戏：P键
- 关闭或开启背景音乐：M键（或者鼠标点击游戏窗口右上角的Music按钮）

### 游戏中的坐标体系
![image](https://user-images.githubusercontent.com/84364367/123515657-d7f7a100-d6ca-11eb-8efc-c26474024c26.png)

### 效果展示
![image](https://user-images.githubusercontent.com/84364367/123515715-2147f080-d6cb-11eb-938c-728ce8444fbe.png)

