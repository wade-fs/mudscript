#include <room.h>
inherit ROOM;
void create()
{
        set("short","木人場");
        set("long", @LONG

    一股臭藥味撲鼻而來，但是這種味道對行醫之人來說，可以使他
們更為振奮，而銀針門的弟子們也都以行醫救世為目標，牆上貼了一
些人體的穴位圖。

LONG
        );

        set("outdoors", 1);
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"17",          
        "south":__DIR__"27",          
        "east":__DIR__"20",       

        ]) );
        set("objects",([ /* sizeof() == 2 */
  "/open/doctor/npc/trainee1" : 1,             
  "/open/doctor/npc/trainee2" : 1,            

]));

  setup();
}


