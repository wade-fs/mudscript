#include <room.h>
inherit ROOM;

void create()
{
	set("short","風之試煉場");
	set("long",@LONG
	許多的龍捲風環繞著這一個試煉場，強烈的旋風令你站不住腳。
	唯一只有在試煉場中的石版上，你才感到較弱的風力。
	有一個風之屍魂人在此處把守，沒有兩把刷子，還是盡快放棄這一個任務吧！
	否則死在這裡，可能連裝備沒機會撿回來了！

LONG);
      
set("objects",([
    "/open/killer/headkill/npc/w_ghost":1,
		]));
	set("light_up",10);
        setup();
}
