#include <room.h>
inherit ROOM;

void create()
{
	set("short","火之試煉場");
	set("long",@LONG
	四周被熊熊的烈火所包圍，有一個火之屍魂人在此處把守
	如果沒有兩把刷子，還是盡快放棄這一個任務吧！
	否則死在這裡，可能連裝備沒機會撿回來了！
	因為這裡四周除了熊熊的烈火之外。根本沒有任何通路。
	唯一的脫離用的東西可能就是卷軸了！！！
LONG);
      
set("objects",([
    "/open/killer/headkill/npc/f_ghost":1,
		]));
	set("light_up",10);
        setup();
}
