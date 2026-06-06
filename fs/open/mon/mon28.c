inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "雪中小徑");
	set( "build", 42 );
  set ("long", @LONG
前方的小路依舊，刺骨的寒風迎面而來，細細的白雪輕輕地覆蓋
了整條小徑，一般的草木已經不復見，走到這裏，你已經找不到路再
往上走了，你看到一大片的岩石(rock)阻擋了你通往山頂的路，你似
乎必需用爬的才有辦法通往山頂，而在你的前方不遠處，有一個暗淡
無光的圓點，微微的霧氣讓你看不清那兒有什麼。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/pig.c" : 1,
]));
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"mon51",
  "south" : __DIR__"mon32",
  "eastdown" : __DIR__"mon27",
]));

  setup();
}
void init()
{
  add_action ("do_climb","climb");
}

int do_climb (string str)

{
  object        me;
  if (!str || (str != "rock" && str != "岩石"))
    return notify_fail("你爬呀爬呀......你爬了半天還是不幸重重的捽了下來.....\n");

  me = this_player();
  message_vision("$N展開絕世輕功\，依附著岩石，輕輕鬆鬆的登上了攀岩道。\n", me);
  me->move(__DIR__"mon33");


  tell_room(environment(me), sprintf ("%s左足一點，右足一蹬，氣定神閒的登上了攀岩道。\n",
        me->short()), me);
  return 1;
}

