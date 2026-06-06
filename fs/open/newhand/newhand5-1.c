#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIG + "狂想空間特色說明房間" + NOR);
  set ("long","這裏的房間是介紹狂想空間的一些小特色!!!
  特色一：請打help 公式。狂想的戰鬥公式及其他重要的屬性公式都在裏面!!!
  特色二：大俠制度,exp在三百萬以上時將成為大俠!!!可以自創自己招式!!!
  特色三：幫派的制度!!!
  特色四：特色常常在增加，請打help news可以隨時看到新的公佈事項!!!!
                \n");
  set("exits", ([
  "northwest" : __DIR__"newhand",
  "southeast" : __DIR__"newhand",
               ]));
  set("light_up", 1);
  setup();
}

