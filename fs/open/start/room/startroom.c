// Room: /open/start/startroom.c
// 本房間 rewrited by wade in 1/2/1996 for chfn 任務

#include "/open/open.h"
inherit ROOM;

string do_search();

void create ()
{
  set ("long", @LONG
這是你的家, 相傳你祖宗十八代都在這兒生活, 祖先們的墳墓也都
就近葬在附近的山丘地上, 村長還勸人到那邊耕種, 你的老祖先們似乎
在那附近種了不少地, 不過到了你這代, 已經沒人願意去種田了, 一來
是因為時局紛亂, 一來是據說有一代祖先找到了不少珍奇異寶, 附近居
民也趨之若騖, 你老爸更在你十四歲那年把你踢出去冒險, 為的就是希
望你能學得一身武功, 帶回一堆寶物.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/start/room/s1",
]));
  set("objects", ([
	START_NPC"papa"		: 1,
  ]) );

  set("light_up", 1);
  set("no_clean_up", 1);
  set("valid_startroom", 1);

  setup();
}

string short()
{
  object	me=this_player();

  return sprintf ("%s的家", me->name());
}
