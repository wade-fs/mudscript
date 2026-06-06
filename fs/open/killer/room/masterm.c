#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set("short","總壇大廳");
	set( "build", 840 );
  set ("long", @LONG
這裡是黑牙聯總壇大廳，並沒有特別的裝飾，但有一個人高高坐在其上。
眼前所見的﹐正是武林一大殺手組織的的主席---葉秀殺
相傳此人是一啞吧﹐但武功之強﹐非凡人可知﹐此外在身旁的是他的弟子﹐
也是武林中響當當的殺手。如果想殺他還是先看看自己的份量吧。。。。
三樓是殺手出任務時可以拿裝備的地方，但是必須先問過葉秀殺才可以。
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
	"south":__DIR__"ru3",
    "up":__DIR__"misrm1",
  "east":__DIR__"ru4",
  "west":__DIR__"ru5",
 "north":__DIR__"bedrm",
]));

  set("objects",([
  "/daemon/class/killer/master_yar.c" : 1,
        "/open/main/obj/torch" : 1,
        ]));
  set("valid_startroom", 1);
  setup();
}
