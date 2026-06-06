inherit ROOM;
#include <ansi.h>
void create()
{
set("short", "松林");
set("long", @LONG
由於此處松樹高大茂密，幾乎將陽光都遮蓋住了，似乎令人覺得
遍體生寒，將此地多增加了幾許的神秘感，兩旁樹木緩緩擺動，似乎
是在叫人不要再繼續前進。
LONG
);
set("exits",([ /* sizeof() == 2*/
"down" : __DIR__"tree1.c",
"up" : __DIR__"tree3.c", 
]));
set("objects", ([ /* sizeof() == 2 */
"/open/tendo/room/tower/npc/genies.c" : 2,
]));
set("outdoors",1);
setup();
}


