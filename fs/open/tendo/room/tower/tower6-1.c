inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "鎖妖塔六樓--");
  set ("long", @LONG
你來到了是鎖妖塔的倒數第三層，房內一片漆黑，伸手五指不辨，呆
立半盞，漸可分辨房內景物，你感覺這樓比剛剛素淨，不過地上零零散散
的擺著七八個骷髏，和一堆堆的白骨，上面燐光閃爍，乍見之下恍如鬼火
一般，忽然你發現房間的角落有一隻老妖怪站在那兒，對著你嘆息。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"tower6-2",
  "west" : __DIR__"tower6-3",
  "down" : __DIR__"tower5-2",
]));
 set("objects", ([ /* sizeof() == 1 */
"/open/tendo/room/tower/npc/butcher" : 1,
]));
        set("no_transmit",1);
  setup();
}
int valid_leave(object me, string dir) {
  if(dir=="east"&&present("butcher",environment(me))) {
  return notify_fail("生死一屠吼道：想過去！先殺了我再說吧！\n");
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
       tell_object(ob,HIR"～鬼影幢幢～你覺得胸中一陣翻滾，忽然一道血箭從你的嘴裡噴了出來。\n"NOR);
       ob->add("kee",-100);
       call_out("fire_wound", 5,ob);
}


void reset()
{
        ::reset();
        delete("go_north");
}



