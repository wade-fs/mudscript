#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "地牢");
  set ("long", @LONG
又濕又黑的地牢中 ,真是不太好過 ,滿地的積水 ,隨便一動就踩的滿
腳污泥 ,再加上那些噁心至極的小生物 ,令你不得不為那些整日關在
這不適人居的地方的人難過 .你忽然感到四周有異 ,可以用(search)
看看哪裡有問題 .


LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room21.c",
  "west" : __DIR__"path13.c",
]));
  create_door("east",HIY "黃色鐵門"NOR, "west", DOOR_CLOSED);

  set("light_up", 0);
  set("valid_startroom", 1);

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

        tell_object(who,"\n你腳底突然開了一個大洞 ,你一不小心 ,摔了下去。\n\n");
     who->move("/open/poison/room/room23.c");
        tell_room(this_object(),who->query("name")+"不知啟動了什麼機關, 突然消失
在地牢之中。\n");
        return 1;
}
