#include <room.h>
inherit ROOM;

void create()
{
	set("short","水之試煉場");
	set("long",@LONG
	你幾乎不敢相信你的眼睛，因為這一個試煉場，居然是在水底？
	四周只有著清澈的海水所包圍著，但是，海水居然不會吞沒此處？
	但是，看到一旁的石碑上刻著『天才小渡建造』，你以明白了一切。
	水之屍魂人在此處把守，如果沒有兩把刷子，還是盡快放棄這一個任務吧！
	否則死在這裡，可能連裝備沒機會撿回來了！
LONG);
      
set("objects",([
    "/open/killer/headkill/npc/i_ghost":1,
		]));
	set("light_up",10);
        setup();
}
