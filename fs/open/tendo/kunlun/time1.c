//時之迴廊 by frequency
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIW + "雲內" + HIY + "‧" + HIC + "時ソ迴廊" + NOR);
  set ("long", @LONG
這裡是四周被雲霧所包圍的奇異空間，強風的怒嚎聲只能在外面
憤怒的咆哮著，雖然感覺暫時免於被吹落地面的危險，但身旁的空間
總是隱隱散發出不協調的感覺，彷彿違背著什麼永恆不變的道理而存
在著般，看得更仔細點，前方的空間似乎正扭曲著，而時間的流動也
毫無章法，好像空間和時間正無邊無際擴張一樣。
LONG);

  set("exits", ([
  "east" : __DIR__"time2.c",
  "out" : __DIR__"cloud.c",

               ]));
  set("no_transmit",1);
  setup();
}

void init()
{
 object me = this_player();
 if(me->query("attribute") != "wind" && random(3) == 1)
  {
    message_vision(HIG + "扭曲的時空將你送返最初到達世上的地方。\n" + NOR,me);
    me->move("/open/common/room/inn.c");
  }
}

