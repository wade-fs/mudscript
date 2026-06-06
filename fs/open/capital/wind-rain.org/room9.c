// by roger
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short","牌樓前");
set ("long", @LONG
    這裡已到了湖的盡頭，眼前是「金風細雨樓」的牌樓，圍牆後面
有座巨大的樓，在湖畔霧氣迷濛下，外表濛濛晃晃，分不清是曙色、
黎明，還是醒的邊緣。誰又知道，曾經有多少權謀在樓裡策畫，有多
少不為人知的江湖傳聞在裡面，有多少身懷絕技的人為此樓效命?
LONG);



  set("exits", ([
            "east"  : __DIR__"room8",
            "enter"  : __DIR__"1",
                ]));

       

        setup();
}
