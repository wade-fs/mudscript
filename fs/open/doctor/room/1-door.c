#include <room.h>
inherit ROOM;
void create()
{
        set("short","玄關");
        set("long",@LONG
這裡是銀針門的玄關，往裡面 (open door)走，則是銀針門的診療
室，外面則是銀針門的木人或銅人場，木人場裡到處都是習武強身或辨
識穴道的弟子。

LONG);
        set("item_desc", ([ /* sizeof() == 1 */
      "north" : (: look_door,     "north" :),
]));

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"8",           
        "south":__DIR__"16",        

        ]) );

        set("objects",([ /* sizeof() == 1 */
  "/open/doctor/npc/duty" : 2,       

]));
        
        set("light_up", 1);
        create_door("north","紅木刻紋大門", "south",DOOR_CLOSED);
  setup();
}


