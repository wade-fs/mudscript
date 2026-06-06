#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "段雲的臥房");
  set ("long", @LONG

剛至房中，便被眼前金碧輝煌的裝潢所吸引, 這兒便是段雲的寢室,
牆上所掛的字畫無一不是當世名家或歷代大師所作, 在這所懸掛的珍
品, 便是大內皇宮所藏, 只怕也遠遠不及。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "south" : (: look_door,     "south" :),
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"np23",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/duan-wife.c" : 1,
]));
  set("light_up", 1);

 create_door("south","雕花紫檀木門","north",DOOR_CLOSED);
  setup();
}
void init()
{
        add_action("do_search", "search");
        add_action("do_turn", "turn");
}
int do_search()
{
        object who;
        who = this_player();
        if(who->query("now_start")==1)
{
        tell_object(who,"\n你四處摸索，發現﹝床板﹞好像可以翻轉。\n\n");
}
else
        tell_object(who,"葉靈說道：你在做什麼???想當賊嗎?????\n");
        return 1;
}
int do_turn(string str)
{
       object who = this_player();
        if(who->query("now_start")==1)
        {
       if(str=="床板")
       {
       tell_object(who,"\n你起動機關，結果一股腦的跌了進去。\n\n");
        who->move("/open/ping/questsfan/room1");
       tell_room(this_object(),who->query("name")+"不知啟動了什麼機關, 突然消失了。\n");
        }
        return 1;
}
else
        return 0;
}

