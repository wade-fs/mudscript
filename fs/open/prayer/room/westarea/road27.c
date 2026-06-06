//open/prayer/room/westarea/road27.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西域東部的三叉路口. 北邊是往開陽門, 南邊是往陣勢門.
	聖火教三大絕學之一的渾天心法並不是每個人都能學習的,
	據說要得到渾天水晶之後才能夠修練!!渾天水晶共有六隻
	之多, 其中的白水晶是記載基礎的一至五層內功\心法.
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
       	"north":__DIR__"road24",	//街道
	"south":__DIR__"road32",	//街道
	"west":__DIR__"road28",		//街道
 
        ]) );
        set("no_fight", 0);
        
  setup();
}
