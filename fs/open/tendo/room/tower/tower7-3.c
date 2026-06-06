
inherit ROOM;
#include <ansi.h>
void create()
{
  set ("short", "鎖妖塔七樓--");
  set ("long", @LONG
這裡是鎖妖塔裡的倒數第二層，在這裡你完全看不到外面的狀況，顯得相
當地詭異，空氣之中還瀰漫著一股白霧，更添了幾分神秘氣息，說不定你該考
慮回頭，或許現在還來得及。
LONG);

 
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"tower7-1",
]));
       set("no_transmit",1);
  setup();
}

void init()
{
        if( !previous_object()
        ||      !userp(previous_object()) )
                return;
      call_out( "fire_wound", 3,previous_object());
}

void fire_wound(object ob)
{
        if( !ob || !present(ob) ) return;
       tell_object(ob,HIR + "～鬼影幢幢～你覺得胸中一陣翻滾，忽然一道血箭從你的嘴裡噴了出來。\n" + NOR);
       ob->add("kee",-100);
       call_out("fire_wound", 3,ob);
}




