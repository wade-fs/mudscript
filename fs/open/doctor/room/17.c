#include <room.h>
inherit ROOM;
void create()
{
        set("short","木人場");
        set("long", @LONG

    牆壁上貼滿了人體的穴道圖和解說，以便弟子門熟記，想正式成
為銀針門入意門弟子，必須先熟記這些穴位，看！那不是有兩三個弟
子在那兒喃喃自語，好像背的挺認真的嘛！

LONG
        );
        set("outdoors", 1);
        set("exits", ([ /* sizeof() == 3 */
        "east":__DIR__"16",
        "south":__DIR__"21",         
        "west":__DIR__"18",

        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/doctor/npc/trainee1" : 1,              
  "/open/doctor/npc/trainee2" : 1,           

]));

  setup();
}


