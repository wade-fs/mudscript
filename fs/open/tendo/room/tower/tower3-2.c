
inherit ROOM;
#include <ansi.h>
void create()
{
  set ("short", "鎖妖塔三樓--");
  set ("long", @LONG
來到了這兒，你發現這裡一定經歷過相當慘烈的戰鬥，除了四布的血印以及滿牆
的掌印，還有一股股濕穢的黴味；你發覺牆角還有幾具殘缺的骷骨，你想這一些一定
是犧牲在這裡的強者們。
LONG );

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"tower3-1",
  "east" : __DIR__"tower3-3",
]));
 set("objects", ([ /* sizeof() == 1 */
"/open/tendo/room/tower/npc/villain" : 1,
]));
        set("no_transmit",1);
  setup();
}
int valid_leave(object me, string dir) {
  if(dir=="east"&&present("villain",environment(me))) {
  return notify_fail("血面羅剎吼道: 想過去！先殺了我再說吧！\n");
  } 
 return 1;
}
void init()
{
        if( !previous_object()
        ||      !userp(previous_object()) )
                return;
      call_out( "fire_wound", 6,previous_object());
}

void fire_wound(object ob)
{
        if( !ob || !present(ob) ) return;
       tell_object(ob,HIR + "～鬼影幢幢～你覺得胸中一陣翻滾，忽然一道血箭從你的嘴裡噴了出來。\n" + NOR);
       ob->add("kee",-100);
       call_out("fire_wound", 6,ob);
}


void reset()
{
        ::reset();
        delete("go_north");
}


