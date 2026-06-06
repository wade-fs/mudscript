
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "鎖妖塔八樓--");
  set ("long", @LONG
這是鎖妖塔中的最後一層，看了看四周，心中深感不可思議，周圍
盡是一堆堆的白骨，白骨旁散落著一堆堆的武器及裝備，室內到處瀰漫
著一種說不出的詭異氣氛，時有聽到動物慘叫的聲音，時而聞到濃厚的
血腥味道令你不寒而顫。西側的牆角似乎擺了一張架子 (shelf)，看起
來真不協調。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
"shelf" : "一張長滿灰塵的架子，不過似乎可以推的樣子。
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tower7-2",
]));
       set("no_transmit",1);

  setup();
}

void init()
{
add_action ("do_push","push");
}

int do_push (string str)
{
  object        me;
   if (!str || (str != "shelf" && str != "兵器架"&& str != "架子"))
return notify_fail("哇咧．．沒事不要亂推！\n");

  me = this_player();
    message_vision("地上突然出現一個洞，你來不及跳開便摔了下去!!\n", me);

    me->move(__DIR__"tower8-1.c");
    tell_room(environment(me), sprintf ("%s像顆石頭般摔了下來 .\n",
     me->short()), me);
  return 1;
}


