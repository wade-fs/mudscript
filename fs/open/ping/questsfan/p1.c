#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "段王府大廳");
  set ("long", @LONG
這兒四周乾乾淨淨的, 只見大廳中央擺著一張陳年烏木的圓桌, 北
邊一張檀木蟠龍椅上坐著一人, 雙眼不怒而威, 自然有一股帝王的威嚴
, 想必便是平南城中, 段王府裡, 獨一無二的平南王--「段雲」是也。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"np13.c",
  "north" : __DIR__"np23.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/daemon/class/scholar/master_duan" : 1,
]));
  set("valid_startroom", 1);

  setup();
call_other("/obj/board/duan_b.c","???");
}


void init()
{
        add_action("do_search", "search");
}

int do_search()
{
        object who;
        who = this_player();

        tell_object(who,"\n你掀起暗扣, 一轉身, 隱沒在暗門之後。\n\n");
        who->move(__DIR__"np20");
        tell_room(this_object(),who->query("name")+"不知啟動了什麼機關, 突然消失在大廳之中。\n");
        return 1;
}
