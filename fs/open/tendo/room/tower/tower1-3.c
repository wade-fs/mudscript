
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "鎖妖塔一樓");
  set ("long", @LONG
一進到這兒，你就被突如其來的的敵人所攻擊。你定了定神後，注意到這間房間
到處都是乾掉的血漬，四周的牆壁也都佈滿了打鬥過的痕跡。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tower1-2",
  "up" : __DIR__"room2",
]));

        set("no_transmit",1);
  setup();
}
int valid_leave(object me, string dir)
{
        if( dir=="up" )
        message("system",
 HIW"\n\t武林之中傳來一道消息 : "HIY""+this_player()->name()+""HIW"勇闖"HIR"鎖妖塔"HIW"第二層了 !!\n"NOR,users());
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


