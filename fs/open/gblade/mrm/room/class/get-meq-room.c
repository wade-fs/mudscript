// 打敗 sa and can get meq 之 room by swy
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short",HIC + "『武天至聖』的收藏室" + NOR);
set ("long",@LONG

你走到了一處盡是堆滿奇珍異寶的地方但確沒有一件
寶物引起你的注意，突然你看見滿堆寶物中有一處竟
發出藍光，讓你好奇的想上前觀看(look_for)

LONG);
  set("light_up",1);
  set("exits", ([
"south":"/open/gblade/mrm/room/class/r11.c",
]));
set("no_transmit",1); 
  setup();
}

void init()
{
add_action("get_meq","look_for");
}
int get_meq()
{
object me=this_player(),mid;
object ob;
ob=present("mdragon-eq",me); 
if( !me->query("max_standby"))
		{
		 me->set("max_standby",50);
        }
if(me->query_temp("can-get-meq")==1)
{
if(!ob) {
me->delete_temp("can-get-meq");
me->set("new-by-swy",1);
message_vision(HIW + "$N找了找發現了$N最須要的『魔龍裝備』。\n" + NOR,me);
mid=new("/autoload/blademan/mdragon.c");
mid->set("boss",me->query("id"));
mid->move(me);
log_file("mblade/get-meq", sprintf("(%s)得到魔龍防具 時間是 %s\n",
me->query("id"),ctime(time())));
return 1;
} else if(me->query("t_standby")<me->query("max_standby")){
message_vision(HIW + "$N找了找發現了$N最須要的二隻替身。\n" + NOR,me); 
me->delete_temp("can-get-meq");
me->add("standby",2);
me->add("t_standby",2);
log_file("mblade/get-standby", sprintf("(%s)得到二隻替身 時間是 %s\n", 
me->query("id"),ctime(time()))); 
return 1; 
}
else message_vision(HIW + "你的替身已達可使用的上限不能再加囉。\n" + NOR,me);
} else {
message_vision(HIR + "$N貪心的去找了找卻誤觸機關，被機關吸去大半的血。\n" + NOR,me);
me->add("eff_kee",-1000);
me->add("kee",-1000);
return 1;
}
}
