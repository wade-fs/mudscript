#include <room.h>
inherit ROOM;

void create()
{
	set("short","土之試煉場");
	set("long",@LONG
	放眼望去盡是無盡的黃土，四周根本寸草不生。
	連風都沒有的感覺，有著一種淒涼的感覺。
	四周有的只是無盡的黃土，無邊無涯，有人能自己離去嗎？
	有一個土之屍魂人在此處把守，沒有兩把刷子，還是盡快放棄這一個任務吧！
	否則死在這裡，可能連裝備沒機會撿回來了！
	唯一的脫離用的東西可能就是卷軸了！！！
LONG);
      
set("objects",([
    "/open/killer/headkill/npc/e_ghost":1,
		]));
	set("light_up",10);
        setup();
}
