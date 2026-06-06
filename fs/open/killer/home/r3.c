#include <room.h>
#include "../../open.h"
inherit ROOM;

void create ()
{
  set("short","洞穴入口");
  set ("long", @LONG
這裡是黑牙聯﹐眼前所見的﹐正是武林一大殺手組織的的主席
「葉秀殺」﹐相傳此人是一啞吧﹐但武功之強﹐非凡人可知﹐此外
在身旁的是他的弟子﹐也是武林中響當當的殺手。
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
	"out":__DIR__"r2",
	"east":__DIR__"r4",
	"north":__DIR__"blackwiz",
]));

  set("objects",([
	"/daemon/class/killer/master_yar":1,
        "/open/main/obj/torch" : 1,
        ]));
  set("valid_startroom", 1);
  setup();
  call_other("/obj/board/killer_b","???");
}
