#include <room.h>
inherit ROOM;
void create()
{
        set("short","木人場");
        set("long", @LONG

    牆壁上貼滿了人體的穴道圖和解說，以便弟子門熟記，想正式成
為銀針門入意門弟子，必須先熟記這些穴位，看！那不是有兩三個弟
子在那兒喃喃自語，好像背得挺認真的嘛！

LONG
        );

        set("outdoors", 1);
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"20",            
        "south":__DIR__"2-door",       
        "west":__DIR__"27",            
        "east":__DIR__"25",         

        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
        "/open/doctor/npc/trainee2" : 1,             
        "/open/doctor/npc/trainee1" : 1,                

]));
        create_door("south","紅木刻紋大門", "north",DOOR_CLOSED);

  setup();
}


