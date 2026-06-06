
inherit ROOM;
#include <ansi.h>
void create()
{
  set ("short", "鎖妖塔七樓--");
  set ("long", @LONG
這裏是武威七殺塔的倒數第二層，站在這裡，你有一種說不出的緊張感，一旁的小窗
子還不斷吹進微風；你忽然發現牆角陰暗處站著一個身形高大的人，你猜想他大概就是這
間房間的主人，或者是這個塔的主人！？
LONG);

 
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tower6-2",
  "east" : __DIR__"tower7-2",
  "south" : __DIR__"tower7-3",
]));
 set("objects", ([ /* sizeof() == 1 */
"/open/tendo/room/tower/npc/towerking" : 1,
]));
        set("no_transmit",1);
        set("no_smash",1);
        set("no_dest",1);

  setup();
}
int valid_leave(object me, string dir) {
  if(dir=="east"&&present("tower king",environment(me))) {
  return notify_fail("鎮塔明王大叫：想上去，想殺了我再說吧！\n");
  } 
 return 1;
}
void init()
{
        if( !previous_object()
        ||      !userp(previous_object()) )
                return;
      call_out( "fire_wound", 5,previous_object());
}

void fire_wound(object ob)
{
        if( !ob || !present(ob) ) return;
       tell_object(ob,HIR + "～鬼影幢幢～你覺得胸中一陣翻滾，忽然一道血箭從你的嘴裡噴了出來。\n" + NOR);
       ob->add("kee",-100);
       call_out("fire_wound", 5,ob);
}


void reset()
{
        ::reset();
        delete("go_north");
}



