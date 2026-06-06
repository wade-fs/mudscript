// by Alucard 2009/08
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
#include "tunnel_msg.c"
void create () {
        set("short","幽暗隧道");
		set("long", (: printf_msg :) );
        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
		set("no_scale",1);
		set("no_chome",1);
        set("light_up",-1);
        set("exits", ([
            "westup" :  __DIR__"tunnel_10",
			"southeast" :  __DIR__"tunnel_08",   
      ]));
        setup();
}

void init()
{
  object me;
  me = this_player();
  if(userp(me)) call_out("do_damage",1,this_player());
  if(me->query_temp("quest/return_sha") && me->query_temp("quest/return_sha")<8) me->start_busy(1);  //讓ppl不能一直往前衝
  return ;
}

void do_damage(object me)
{
  object eq;
  int gin,kee,sen;
  me = this_player();
  eq = present("fire-turtle shield",me);
  gin = me->query("max_gin");
  kee = me->query("max_kee");
  sen = me->query("max_sen");
  
  message_vision(HIR + " 四周天花板、牆縫突然射出一道帶著魔性的血氣。\n" + NOR,me);
  if(me->query_temp("quest/return_sha") && me->query_temp("quest/return_sha")>7)   //回程時不再受限
  {
   message_vision(HIW + " $N憶及前次經驗，早已有所準備，從容閃過。\n" + NOR,me);
   return;
  }
  if(!me->query_temp("quest/return_sha") || me->query_temp("quest/return_sha")<7)  //防止玩家以不正當方式進入
  {
   message_vision(HIW + " $N未經云許\進入本派重地，遭到先人遺留劍意破體，當場慘死!!\n" + NOR,me);
   me->die();
   return;
  }
   if(!eq)
   {
    message_vision(HIM + " $N防備不及，慘遭貫體而過。\n" + NOR,me);
	me->start_busy(1);
	me->receive_wound("gin",(50+gin)/3);
	me->receive_wound("kee",(50+kee)/3);
	me->receive_wound("sen",(50+sen)/3);
   } else {
    message_vision(HIG + " $N身上的"+eq->query("name")+HIG + "獸性大發，及時為主人擋下這致命一擊，隨即灰飛湮滅。\n" + NOR,me);
	destruct(present("fire-turtle shield",me));
          }
   return ;
}
