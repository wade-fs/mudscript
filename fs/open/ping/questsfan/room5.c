// Room: /u/d/dhk/questsfan/room5
inherit ROOM;
#include <ansi.h>
#include <room.h>
void create ()
{
  set ("short", "密道");
  set ("long", @LONG
暗暗的走道中，忽然飄來一陣涼風。這時你心想是出
口到了嗎？你卯足全勁仔細搜索，果然走道的盡頭上方有
一處若隱若現的出口，而且風就好像是從那裡來的。

LONG);
set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room4",
]));

  setup();
}
void init()
{
        add_action("do_search", "search");
}

int do_search()
{
        object who;
        who = this_player();

        tell_object(who,"\n你仔細搜索，終於找到一個隱密的出口。\n\n");
        who->move(__DIR__"room6");
        return 1;
}
