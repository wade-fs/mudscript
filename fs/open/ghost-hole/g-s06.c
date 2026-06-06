#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",YEL"幽冥"BLU"秘洞"NOR);
        set("long",@LONG
      
    哇！好大的洞穴，好多的生死蝶 (butterfly)在
裡頭翩翩飛舞，看來是洞穴中的氣息吸引生死蝶飛向
此處，由於生死蝶的關係，洞穴內異常的光亮。你正
覺得不可思議之時，只見一條人影飛快的衝向你，他
正是死靈界之主——死靈骨魔。
       
LONG);
        set("exits", ([
        "out":__DIR__"g-s05",
        ]) );
        set("objects",([
        "/open/ghost-hole/npc/ghost-king.c":1,
        ]));
        set("light_up",1);
        set("no_transmit",1);
        setup();
}
void init()
{
      call_out("do_check",1,this_player()); 
}
void do_check(object me)
{
if(!me) return ;
      if(!me->query_temp("ghost-quest/cankill-king" ) && userp(me) && living(me)) {
        message_vision(HIW"\n天神搖搖頭對$N說道：你這個愛用偷吃步的傢伙，滾回家去吧！\n"NOR,me);
        me->move(me->query("startroom"));
        me->set( "clan/out","/open/center/room/inn");
      }else  
      me->set_temp("check_ok",1);
}

