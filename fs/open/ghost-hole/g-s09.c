//暗之神殿 by frequency
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "暗之神殿");
  set ("long", @LONG
在這條寬大地底宮殿的兩側，豎立著無數雕工精細的圖騰，
儘管這些圖案的美麗不容置疑，但卻也隱隱散發出死亡及邪惡的
氣息，彷彿並非我們所熟悉的這個世界的產物。路在此由南筆直
的向北延伸過去。
LONG);

  set("exits", ([
  "north" : "/open/ghost-hole/g-s08",
  "south" : "/open/ghost-hole/g-s01",
               ]));
  set("no_transmit",1);
  setup();
}

void init()
{
 object me = this_player();
 if(me->query("attribute") != "dark")
  {
    me->add("gin",-2*(me->query("max_gin"))/5);
    me->add("kee",-2*(me->query("max_kee"))/5);
    me->add("sen",-2*(me->query("max_sen"))/5);
  }
}
