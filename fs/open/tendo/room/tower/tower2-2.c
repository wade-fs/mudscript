inherit ROOM;
#include <ansi.h>
void create()
{
  set ("short", "鎖妖塔二樓--");
  set ("long", @LONG
踏入這兒給你的第一個印象，還是那片惱人的暗紅色，和著地上斑斑的
血跡，使你覺得這兒充滿一片血腥，不禁有一股衝動想要往回走。
LONG);
 
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tower2-3",
  "north" : __DIR__"tower2-1",
]));
 set("objects", ([ /* sizeof() == 1 */
"/open/tendo/room/tower/npc/yama" : 1,
]));
        set("no_transmit",1);
  setup();
}
int valid_leave(object me, string dir) {
  if(dir=="west"&&present("yama",environment(me))) {
  return notify_fail("幻變千手吼道: 想過去！先殺了我再說吧！\n");
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


