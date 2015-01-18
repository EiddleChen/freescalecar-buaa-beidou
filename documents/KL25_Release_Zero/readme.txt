本目录是KL25核心模块以及USBDM调试器和USB2RS232模块的软件，代码和说明

其中

KL25核心板说明书 包含了KL25的核心板的电气说明，尺寸，接插件定义和名称
USBDM SWD说明书  包含了USBDM的使用帮助和接插件定义以及固件升级的说明
USBDM驱动和软件  包含了安装USBDM需要的软件和驱动程序
测试用目标代码   包含了用于测试KL25核心板工作是否正常的目标代码
                 其中，1_MMA8541.s19  烧写到KL25核心板，会看到LED2,3,4,5根据KL25核心板XYZ轴位置不同而点亮
				       2_USB CDC.s19  烧写到KL25核心板，并且使用USB电缆连接KL25核心板到PC，会识别到一个CDC的串口，使用到的驱动是cdc.inf
					   3_LED UART.s19 烧写到KL25核心板，会看到LED2,3,4,5跑马灯闪烁，并且UART0,1,2分别输出U1，U2，U3以及回车换行的字符串
			     测试用的目标代码可以用来验证核心板的工作状态。
示范样例工程     包含了产生测试用目标代码的源代码工程，使用Codewarrior 10.3beta编译
原理图			 包含了KL25核心板的原理图文件以及PCB文件的PDF格式
USB2RS232驱动    包含了USB2RS232模块的驱动程序

感谢来自于  Lucerne University of Applied Sciences and Arts 的 Erich Styger 的杰出工作，源代码和说明
源代码中有一部分代码是源自 Erich 的工作。

感谢 pgo 的关于USBDM的杰出工作，图纸和帮助
USBDM调试器的部分工作是源于 pgo 的无私工作和奉献。

Codewarrior 10.3beta
请到Freescale公司网站下载

薛涛				
于  2012年10月25日凌晨，清华大学刘卿楼502房间，北京
010-62789104
gbe.tao.xue@gmail.com
http://www.tsinghua-freescale.net