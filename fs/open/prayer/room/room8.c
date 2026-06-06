// Room: /u/r/rence/room/room8.c

#include <room.h>
#include "/open/open.h"

inherit ROOM;

void create()
{
        set("short","七殺塔第五層出口");
        set("long",@LONG
這裡是七殺塔第五層的出口,只見在出口處有一目露精
光的中年男子站立著,一付殺氣騰騰的樣子......... 
在牆上掛著一付扁額(picture):
          
          「瀧山三強者之一...任戎衝」

LONG);
        set("outdoor", "/u/k/kael/room/");
        set("exits", ([ /* sizeof() == 4 */
        "傷門":__DIR__"room2",
        "景門":__DIR__"room3",
        "開門":__DIR__"room4",
        "休門":__DIR__"room5",
	"up" : "/u/k/kael/room/tower6",
        ]) );
        set("objects",([ /* sizeof() == 1 */
  "/u/k/kael/npc/jen4-1.c" : 1,
]));
  setup();
}
int valid_leave(object me, string dir)
{
	if(dir=="up"&&present("zon-jon jen",environment(me)))
return notify_fail("任戎衝伸手一攔 ,說道:要想上樓,先打敗我再說!\n");
	return ::valid_leave(me,dir);
}









