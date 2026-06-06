
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "鎖妖塔一樓--");
  set ("long", @LONG
來到這裡，你發現殺氣越來越濃，由於緊張的關係。四周的景緻你也無心看顧，
只覺得映入眼廉的是一片片的暗紅色，你不禁感到有些頭暈。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"tower1-1",
  "east" : __DIR__"tower1-3",
]));
  set("objects", ([ /* sizeof() == 1 */
"/open/tendo/room/tower/npc/monster" : 1,
]));

        set("no_transmit",1);
  setup();
}
  int valid_leave(object me, string dir) {
  if(dir=="east"&&present("monster",environment(me))) {
  return notify_fail("陰陽怪叟吼道: 想過去！先殺了我再說吧！\n");
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


