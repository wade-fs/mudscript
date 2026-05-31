#include <ansi.h>
#include <armor.h>
inherit NECK;
inherit F_SAVE;
inherit F_AUTOLOAD;
object user;

string inputstr,verb;

void create()
{
set_name("[1;36m幸運鍊條[0m",({"lucky-neck"}));
  set_weight(3000);
  if( clonep() )
                set_default_object(__FILE__);
        else {
  set("long","一條泛著藍光，看來有不可思議力量的項鍊。\n");
  set("unit", "條");
  set("material","steal");
  set("value",10000);
  set("no_sell", 1);
  set("no_give",1);
  set("no_get",1);
  set("no_put",1);
  set("no_auc",1);
  set("no_drop",1);
  set("armor_prop/armor", 10);
 }

  setup();
}

void init()
{
        if( this_player()==environment() )
        add_action("do_steal","steal");
        add_action("do_wear","wear");
        add_action("do_wear","we");
        add_action("do_remove","rem");
        add_action("do_remove","remove");
}

int do_steal(string arg)
{
  int bs,gs,co,ka;
  string ob,player;
  object obj, npc, me;
  me = this_player();
  co = (me->query_con());
  ka = (me->query_kar());
  if(!arg)
  return notify_fail("steal <物品> from <人物>\n");
  if ( me->is_fighting())
  return notify_fail("[1;33m你在戰鬥，不能偷！[0m\n");
  if(sscanf(arg, "%s from %s",ob,player) != 2)
  return notify_fail("沒人啦！還偷？？\n");
  if (me->query("class")!="bandit")
  return notify_fail("不是壞人別想偷！\n");
  if (me->query("quests/steal")!=1)
  return notify_fail("還不會跑，就想學飛？\n");
  if (me->query_skill("steal",1) < 1 )
  return notify_fail("你還沒學到有關偷東西的基本常識！\n");
      if ( !(npc = present(player, environment (me))) )
        return notify_fail ("沒這個"+arg+"\n");
  if(wiz_level(npc)>0) return notify_fail("想偷大神的東西﹐下輩子吧。\n");
  if (!(obj=present(ob, npc)))
    return notify_fail ("沒這個東西: "+ob+".\n");
  if (obj->query("no_steal"))
  return notify_fail ("這東西你可不能動！\n");
  if (random(259)>((me->query_skill("steal",1))+(me->query_kar())))
{
  if ((npc->query("bellicosity")) < (me->query("bellicosity"))*3/2)
 {
  npc->kill_ob(me);
  me->start_busy(1);
  message_vision("[1;31m有人想偷你的東西，使你怒不可抑！！！[0m\n",npc);
  return notify_fail("[1;33m哇勒！沒偷到東西還被人砍！！！[0m\n");
 }
  else if (random((npc->query_spi()))-random((me->query_kar())) > 0)
 {
  npc->kill_ob(me);
  me->start_busy(1);
  message_vision("[1;31m有人想偷你東西，卻被你抓個正著！[0m\n",npc);
  return notify_fail("[1;33m哎呀！偷東西被抓到囉！[0m\n");
 }
  else return notify_fail("[1;35m你失敗囉！！！[0m\n");
}

  obj->move(me);

  message_vision ("[1;32m$N偷了[1;37m"+npc->query("name")+"[1;32m的[1;36m"+ob+"[0m\n", me);

  return 1;
}

int do_wear(string str)
{

     object user;
     user = this_player();
if(str=="lucky-neck")
  {
     if (user->query("marks/kar",1))
    {
     //message_vision("[1;36m一道藍光籠罩著$N，$N感到將有幸運的事情發生！[0m\n",user);
     }
     if (user->query_temp("karup",1)) 
     return notify_fail("你已穿上了！\n");
     else {
     wear();
     if( query("equipped") )
     {
      user = this_player();
     message_vision("[1;36m一道藍光籠罩著$N，$N感到將有幸運的事情發生！[0m\n",user);
     }
    }
  }
}
int wear() {
  if(::wear()) {
    user = environment();
    if(!user->query("marks/kar",1)) {
      user->add_temp("apply/kar",5);
      user->add("max_force",-500);
      user->set_temp("karup",1);
      user->set("marks/kar",1);
    }
      return 1;
  }
  return 0;
}
int do_remove(string str)
{
if(str=="lucky-neck" || str == "all")
     if( query("equipped") )
     {
      user = this_player();
if(user->query("marks/kar",1)) {
      message_vision("[1;37m$N除掉了頸上的項鍊，那種幸運的感覺已不再！[0m\n",user);
     }
}
}
int unequip()
{
  if(query("equipped"))
  {
    if(!user) user = environment();
    if(user->query("marks/kar",1)) {
      if(user->query_temp("karup")) {
          user->add_temp("apply/kar",-5);
      }
      user->add("max_force",500);
      user->delete_temp("karup");
      user->delete("marks/kar");
    }
  }
  return ::unequip();
}
int query_autoload ()
{
  return 1;
}
/*
void die()
{
        object user;
        string *name;

        user=this_player();

  if (user->die())
  {
  if( query("equipped") )
  {
        user->add("kar",-5);
        user->add("max_force",500);
        user->delete_temp("karup");
  }
        user->set("marks/kardie",1);
  }

        return;
}
*/
