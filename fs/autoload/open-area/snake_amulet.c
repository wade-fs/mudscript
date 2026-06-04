//缺少天道 補上效果為spells by blazakira 2010/10/29
inherit ITEM;
#include <ansi.h>

void create()
{
  set_name(HIG + "青蛇護符" + NOR,({"snake amulet","amulet","snake-amulet"}));
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","
蛇神的護符，是蛇寨的鎮寨之寶，由蛇郎君所隨身
攜帶的稀世珍寶，此法寶會隨著使用者的不同，而
有不同的功\效，傳聞此物件乃是邪靈界的某位邪靈
所製作而成的。
[使用方法 : pray amulet ,divest amulet ]
\n");

  set("light_up",-1);
  set("value",100000);
  set("unit","張");
  set("no_put",1);
  set("no_drop",1);
//  set("no_get",1);
  set("no_sell",1);
  set("no_auc",1);
  set("no_give",1);
  set("no_steal",1);
  }

  setup();
}

void init()
{
  object me,ob;
  me=this_player();
  ob=this_object();

  add_action("do_pray","pray");
  add_action("do_divest","divest");
  if( !ob->query("boss") )
  {
    ob->set("boss",me->query("id"));
  }
}

int do_pray(string arg)
{
  object ob,me;

  me = this_player();
  ob = this_object();

  if( !arg )
    return 0;

  arg=lower_case(arg);
  if( !ob = present(arg,me) )
    return 0;
  if( ob != this_object() )
    return 0;

  if( me->query_temp("snake/pray_snake_amulet") )
    return notify_fail("你已經在使用"+ob->name(1)+"。\n");

  (int)me->add_temp("apply/force",5);
  if( me->query("class") == "swordsman" ) (int)me->add_temp("apply/sword",10);
  if( me->query("class") == "blademan" ) (int)me->add_temp("apply/blade",10);
  if( me->query("class") == "marksman" ) (int)me->add_temp("apply/archery",10);
  if( me->query("class") == "dancer" ) (int)me->add_temp("apply/magic",10);
  if( me->query("class") == "taoist" ) (int)me->add_temp("apply/spells",10);
  if( me->query("class") == "beggar" ) (int)me->add_temp("apply/staff",10);
  if( me->query("class") == "prayer" || me->query("class") == "fighter" || me->query("class") == "bandit" ) 
    (int)me->add_temp("apply/unarmed",10);
  if( me->query("class") == "killer" )
  {
    (int)me->add_temp("apply/dagger",10);
    (int)me->add_temp("apply/throwing",10);
  }
  if( me->query("class") == "scholar" || me->query("class") == "doctor")
    (int)me->add_temp("apply/stabber",10);
  if( me->query("class") == "poisoner" ) (int)me->add_temp("apply/whip",10);

  message_vision(HIY + "$N對了$n"+HIY+"開始祈禱...$n"+HIY+"發出強烈的光芒。\n" + NOR,me,ob);
  ob->set("name",HIW + "( 閃爍 )" + NOR+HIG + "青蛇護符" + NOR);
  me->set_temp("snake/pray_snake_amulet",1);
  return 1;
}

int do_divest(string arg)
{
  object ob,me;

  me = this_player();
  ob = this_object();

  if( !arg )
    return 0;

  arg=lower_case(arg);
  if( !ob = present(arg,me) )
    return 0;
  if( ob != this_object() )
    return 0;

  if( !me->query_temp("snake/pray_snake_amulet") )
    return notify_fail("你並沒有使用"+ob->name(1)+"。\n");
  (int)me->add_temp("apply/force",-5);
  if( me->query("class") == "swordsman" ) (int)me->add_temp("apply/sword",-10);
  if( me->query("class") == "blademan" ) (int)me->add_temp("apply/blade",-10);
  if( me->query("class") == "beggar" ) (int)me->add_temp("apply/staff",-10);
  if( me->query("class") == "marksman" ) (int)me->add_temp("apply/archery",-10);
  if( me->query("class") == "dancer" ) (int)me->add_temp("apply/magic",-10);
  if( me->query("class") == "taoist" ) (int)me->add_temp("apply/spells",-10);
  if( me->query("class") == "prayer" || me->query("class") == "fighter" || me->query("class") == "bandit" ) 
    (int)me->add_temp("apply/unarmed",-10);
  if( me->query("class") == "killer" )
  {
    (int)me->add_temp("apply/dagger",-10);
    (int)me->add_temp("apply/throwing",-10);
  }
  if( me->query("class") == "scholar" || me->query("class") == "doctor")
    (int)me->add_temp("apply/stabber",-10);
  if( me->query("class") == "poisoner" ) (int)me->add_temp("apply/whip",-10);
  message_vision("$N解除了$n的使用。\n",me,ob);
  ob->set("name",HIG + "青蛇護符" + NOR);
  me->delete_temp("snake/pray_snake_amulet",1);
  return 1;
}

int query_autoload()
{
  return 1;
}
