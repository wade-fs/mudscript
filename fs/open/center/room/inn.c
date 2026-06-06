#include <ansi.h>
#include	"/open/open.h"

inherit ROOM;

void create ()
{
  set ("short", "中央驛站");
  set ( "long", @long
這兒就是最最出名的驛站, 鑣局的車隊, 來往於沙漠的駱駝隊, 甚
至是牛馬騾車, 幾乎只要你叫得出名字的交通工具這兒都有。
long);

  set("objects", ([ /* sizeof() == 1 */
  "/open/center/npc/sale_girl" : 1,
"/open/center/npc/info-spy" : 1,
]));
  set("no_kill",1);
  set("no_magic",1);
  set("no_fight",1);

	set("outdoors", "/open/main");
	set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"road2",
	"south" : __DIR__"road3",
	"up"	: "/open/common/room/inn",
	"north" : __DIR__"road1",
	"east" : __DIR__"road4",
	"down" : "/open/wiz/donate",
]));

  setup();
  call_other("/obj/board/start_b", "???");
}

