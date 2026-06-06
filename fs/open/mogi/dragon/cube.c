//by Casey
inherit ROOM;
#include <ansi.h>

void create()
{
set ("short", HIC + "後段入口結界" + NOR);
	set( "build", 18 );
set ("long","自從炎龍谷主收服了黃金甲龍後 ,由於群龍無首四處為
亂 ,因而谷主在此封印住一道強力結界 ,希望與世隔絕 ,且
能保護谷中弟子免於強力龍族的侵害。前方似有似無的紅光 ,
但是卻見結界似乎遭強力的魔力所衝破 ...

");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
               set("exits",([ /* sizeof() == 1 */
           
            "north" : __DIR__"d-11",
            "enter" : __DIR__"bc",
      ]));

 set("outdoors", "/u/p");
        setup();
}




