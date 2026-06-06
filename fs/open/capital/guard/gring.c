//made by bss
//king 身上的ring
//二版,king can call 3 隻,ppl just can call one
//增加判斷對手是否set("no_gring",1),如果是則不呼叫mob出來 modify by cyw at 91/04/03
//改變使用者的判定為me = environment(this_object()) 與 wear形式為int wear() (參考殺意魔戒) by blazakira 2011/7/20

#include <ansi.h>
#include <armor.h>
inherit EQUIP;

void create()
{
  set_name(HBRED+HIY + "護衛戒指" + NOR ,({"guard ring", "ring"}));
  set_weight(2500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","一只可以於戰鬥中請出護衛幫忙戰鬥的指戒，閃爍著奇異的金色光芒。\n");
    set("unit", "件");
    set("value",500000);
    set("material","gold");
    set("armor_type","finger");
    set("armor_prop/armor",7);
    set("no_sell",1);
    set("no_sec",1);
    set("no_put",1);
    set("wear_msg","$N戴上了$n，剎那間四週金光大作。\n");
    set("unequip_msg","$N脫下了$n，奇異的金光也隨之消逝。\n");
  }
  setup();
}

void init()
{
  add_action("do_drop","drop");
  add_action("do_drop","auc");
  add_action("do_drop","give");
}

int wear()
{
  int ret = ::wear();
  if( query("equipped"))
  {
    set_heart_beat(1);
  }
  return ret;
}

int unequip()
{
  int ret = ::unequip();
  if( !query("equipped") )
  {
    set_heart_beat(0);
  }
  return ret;
}

int do_drop(string str)
{
  object user=environment();
  if(str=="ring" || str="guard ring" || str=="all")
    if( query("equipped") )
    {
      message_vision("$N脫下了$n，奇異的金光也隨之消逝。\n",user,this_object());
      set_heart_beat(0);
    }
}

void heart_beat()
{
  object mob,*enemy,user=environment();
  int i,j,k;
  if( !objectp(user) )
  {
    set_heart_beat(0);
    return;
  }
  if(user->is_fighting()){
    enemy=user->query_enemy();
    j=sizeof(enemy);
    k=0;
    for(i=0;i<j;i++){
      if(enemy[i]->query("no_gring",1))	{
        k++;
        break;
      }
    }
  }

  if( user->is_fighting() && query("equipped") && k==0)
  {
    if(user->query("capital_king"))
    {
      if(!user->query_temp("have_guard"))
      {
        mob=new(__DIR__"guard");
        mob->set("title",user->query("name")+"的護衛");
        mob->set("combat_exp",user->query("combat_exp"));
        mob->move(environment(user));
        mob->invocation(user);
        mob=new(__DIR__"guard1");
        mob->set("title",user->query("name")+"的護衛");
        mob->set("combat_exp",user->query("combat_exp"));
        mob->move(environment(user));
        mob->invocation(user);
        mob=new(__DIR__"guard2");
        mob->set("title",user->query("name")+"的護衛");
        mob->set("combat_exp",user->query("combat_exp"));
        mob->move(environment(user));
        mob->invocation(user);
      }
    }
    else
    {
      if(!user->query_temp("have_guard"))
      {
        switch(random(3))
        {
          case 0:
            mob=new(__DIR__"guard");
            mob->set("title",user->query("name")+"的護衛");
            mob->set("combat_exp",user->query("combat_exp"));
            mob->move(environment(user));
            mob->invocation(user);
            break;
          case 1:
            mob=new(__DIR__"guard1");
            mob->set("title",user->query("name")+"的護衛");
            mob->set("combat_exp",user->query("combat_exp"));
            mob->move(environment(user));
            mob->invocation(user);
            break;
          case 2:
            mob=new(__DIR__"guard2");
            mob->set("title",user->query("name")+"的護衛");
            mob->set("combat_exp",user->query("combat_exp"));
            mob->move(environment(user));
            mob->invocation(user);
            break;
        }
      }
    }
  }
  return;
}
