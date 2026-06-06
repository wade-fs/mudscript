
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "鎖妖塔五樓--");
  set ("long", @LONG
來到這裡，你忽然發現地上佈滿一層灰，連剛剛樓梯的把手上，也滿是灰塵，你
想能上到五層樓的人，一定是少之又少。這兒的景色依舊單調：深藍色的牆壁、無窗
格局，唯一令你感到不一樣的，是少了剛剛那一股肅殺之氣。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tower5-2",
  "east" : __DIR__"tower5-3",
  "down" : __DIR__"tower4-2",
]));
 set("objects", ([ /* sizeof() == 1 */
"/open/tendo/room/tower/npc/goblin" : 1,
]));
        set("no_transmit",1);
  setup();
}
int valid_leave(object me, string dir) {
  if(dir=="west"&&present("goblin",environment(me))) {
  return notify_fail("血掌蟠妖吼道：想過去！先殺了我再說吧！\n");
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


