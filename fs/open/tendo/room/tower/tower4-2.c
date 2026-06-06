
inherit ROOM;
#include <ansi.h>
void create()
{
  set ("short", "鎖妖塔四樓--");
  set ("long", @LONG
你眼前有一個大梯子，你想又是往上推進一樓的時刻了。由於疲累的關係，你對
四週的景致也無心注意，你只覺得四週的暗藍色比剛剛的都還要來得深、也還要來沈
。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"room4",
  "north" : __DIR__"tower4-1",
]));
        set("no_transmit",1);
  setup();
}
int valid_leave(object me, string dir)
{
        if( dir=="up" )
        message("system",
 HIW"\n\t武林之中傳來一道消息 : "HIY""+this_player()->name()+""HIW"勇闖"HIR"鎖妖塔"HIW"第五層了 !!\n"NOR,users());
        return ::valid_leave(me, dir);
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
       tell_object(ob,HIR"～鬼影幢幢～你覺得胸中一陣翻滾，忽然一道血箭從你的嘴裡噴了出來。\n"NOR);
       ob->add("kee",-100);
       call_out("fire_wound", 3,ob);
}


void reset()
{
        ::reset();
        delete("go_north");
}



