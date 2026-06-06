
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "鎖妖塔五樓--");
  set ("long", @LONG
你發現這兒的景緻忽然一變，強烈的白色映入你眼簾，只是地上鬼火處處，
藍燄汪汪，跳來跳去，陰風一掠之下，更是忽東忽西，時隱時現，饒是綠林豪客
，江湖梟雄處此，也不免要膽戰心寒，拔腿而逃。你看到通往六樓的梯子近在咫
尺，不禁有一股衝動想趕快上去！
。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"tower5-1",
  "up" : __DIR__"tower6-1",
]));
        set("no_transmit",1);
  setup();
}
int valid_leave(object me, string dir)
{
        if( dir=="up" )
        message("system",
 HIW + "\n\t武林之中傳來一道消息 : " + HIY + ""+this_player()->name()+"" + HIW + "勇闖" + HIR + "鎖妖塔" + HIW + "第六層了 !!\n" + NOR,users());
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
       tell_object(ob,HIR + "～鬼影幢幢～你覺得胸中一陣翻滾，忽然一道血箭從你的嘴裡噴了出來。\n" + NOR);
       ob->add("kee",-100);
       call_out("fire_wound", 3,ob);
}


void reset()
{
        ::reset();
        delete("go_north");
}




