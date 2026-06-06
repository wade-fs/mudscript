#include <ansi.h>
#include <localtime.h>
inherit NPC;
inherit SSERVER;


void create()
{
    set_name(HIR"聖"HIW"誕"NOR"老人" ,({"santa"}) );
    set("long","聖誕老人駕著馬車送禮物啦！\n");
  set("gender","女性");
  set("combat_exp",2900000);
  set("no_kill",1);
set("no_fight",1);
set_temp("roared",1);
  set("age",1021);
  set("cor",32);
  set("str",20);
  set("kar",100);

  set("kee",4900);
  set("max_kee",4900);
  set("sen",2200);
  set("max_sen",2200);
  set("gin",2500);
  set("max_gin",2500);
  set("force",4200);
  set("max_force",4200);
  set("bellicosity",4000);
  set("chat_chance_combat", 25);
  set_temp("apply/armor",400);
  set_temp("apply/damage",180);
  set("force_factor",20);
  set_skill("dodge",300);
  set_skill("parry",300);
  set_skill("move",300);

  set_skill("unarmed",280);
  set("attribute","fire");
  set("chat_chance",20);
  set("chat_msg",({
        HIY"聖誕老人說道：新年快樂~~~呵呵呵~~\n"NOR,
        HIY"聖誕老人說道：聖誕快樂~~~呵呵呵~~\n"NOR,
        HIY"聖誕老人說道：呵呵呵，可以找我要(want)禮物啊~~\n"NOR,

        }));
  setup();
  add_money("gold",20);

}
void init()
{
  add_action("do_want","want");
}
int do_want(string arg)
{
  object me = this_player();
  int *ttime = localtime(time());
  if(ttime[LT_HOUR] > 18 || ttime[LT_HOUR] < 1 )
  {
    if(me->query("new_year") > time())
      return notify_fail("你今天已經領過了哦。\n");
 
    if(me->query("mud_age") < 12*60*60)
    return notify_fail("別想創新 char 來騙吃騙喝。\n");
    if((time() - me->query_temp("login_time")) < 30 * 60 )
      return notify_fail("竟然都來了，多聊聊嘛，等一下再給你。\n");
   me->set("new_year",time() + 60*60*16);
    write(HIC"聖誕老人說道：呵呵呵~~~~~~先祝你新年愉快吧~~~~\n"NOR);
    write(HIW"聖誕老人拿了一個禮物給你。\n"NOR);
    if(me->query("combat_exp") < 2000000)
    {
      write(HIR"聖誕老人說道：難得不見的新人耶，多送你經驗值和潛能吧！\n");
      me->add("combat_exp",50000);
      me->add("potential",30000);
    }
    new(__DIR__+"gift.c")->move(me);
    return 1;
  }
  return notify_fail("時間還沒到，多聊聊天晚點再送給你。\n");
}
