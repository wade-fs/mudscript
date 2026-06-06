#include <room.h>
// #include "../../open.h"
inherit ROOM;

void create ()
{
  set("short","洞穴入口");
  set ("long", @LONG
這裡是黑牙聯﹐眼前所見的﹐正是武林一大殺手組織的的主席
「葉秀殺」﹐相傳此人是一啞吧﹐但武功之強﹐非凡人可知﹐此外
在身旁的是他的弟子﹐也是武林中響當當的殺手。


以上是當年的敘述，經歷了當年的那場戰役之後，如今人事已非。
在你眼前的是一片殘破，根本沒人居住的景象，
身邊的許\多白骨想必是當年慘死在此處的黑牙聯殺手。
LONG);

  set("exits", ([ /* sizeof() == 3 */
	"out":__DIR__"r2",
	"east":__DIR__"r4",
	"north":__DIR__"blackwiz",
]));
/*
  set("objects",([
	"/daemon/class/killer/master_yar":1,
        "/open/main/obj/torch" : 1,
        ]));
  set("valid_startroom", 1);
*/
  setup();
//  call_other("/obj/board/killer_b","???");
}
