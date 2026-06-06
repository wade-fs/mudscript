#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "時空雕像館");
        set("long", @LONG
為了讓所有的人更了解曾經為這個狂想世界努力過的天神們，所
以特別建造了這座雕像館，讓人們在遊戲歡娛之時，也能在此感謝他
們所付出的一切時間和心血，也要感謝您花時間來參觀。

接著站立在你眼前的雕像是  【 耐吉(nike) 】

LONG);


        set("exits", ([ 
//      "north" : __DIR__"bssroom",
        "south" : __DIR__"cgyroom",
        ]) );

        set("objects", ([
        "/open/main/statue/npc/nike-statue": 1,
        ])); 

        set("outdoors", "/open/main" );
        set("no_fight",1);
        set("no_kill",1);

        setup();
}

