//改變wear形式為int wear() (參考殺意魔戒) by blazakira 2011/7/20
//提高使用次數 拉長暴掉的時間 減少玩家的麻煩 by blazakira 2011/7/25

#include <armor.h>
#include <ansi.h>
inherit FINGER;
inherit SSERVER;

void create()
{
  set_name(HIW"淨"HIC"水"HIY"光"HIM"之戒"NOR,({"light-ring"}));
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit","只");
    set("value", 0);
    set("material","gem");
    set("long","一眼看去即能帶給人無比安祥感覺的不可思議之戒。\n(可藉由輸入：checkenergy light-ring來查詢剩餘能量。)\n");
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_steal",1);
  }
  setup();
  set("armor_prop/magic",  3);
  set("armor_prop/spells", 3);
  set("armor_prop/literate", 3);
  set("armor_prop/force", 7);
  set("armor_prop/armor", 7);
  set("wear_msg",HIG"戴上了$n"HIG"，光明、純潔的力量在$N"HIG"身旁形成一道護壁。\n"NOR);
  set("unequip_msg",GRN"$N"GRN"脫下了$n"GRN"，身旁的護壁逐漸淡去消逝。\n"NOR);
}

void init()
{
  add_action("do_check","checkenergy");
}

int do_check(string str)
{
  object ob=this_object(),me=environment(ob);
  if(!str || str != ob->query("id")) return 0;
  if(me->query("use_light_ring")<70)
    tell_object(me,ob->query("name")+HIG"裡蘊含光明、純潔的力量"HIW"【相當充沛】"HIG"。\n"NOR);
  else if(me->query("use_light_ring")<150)
    tell_object(me,ob->query("name")+HIG"裡蘊含光明、純潔的力量"HIY"【似乎有些減少】"HIG"。\n"NOR);
  else if(me->query("use_light_ring")<270)
    tell_object(me,ob->query("name")+HIG"裡蘊含光明、純潔的力量"HIR"【很明顯少了很多】"HIG"。\n"NOR);
  else
    tell_object(me,ob->query("name")+HIG"裡蘊含光明、純潔的力量"RED"【相當稀少】"HIG"，似乎就要壞掉一樣。\n"NOR);
  return 1;
}

int query_autoload()
{
  return 1;
}

int wear()
{
  object me;
  int result = ::wear();
  if( query("equipped"))
  {
    me=environment();
//    message_vision(HIG"戴上了$n"HIG"，光明、純潔的力量在$N"HIG"身旁形成一道護壁。\n"NOR,me,this_object());
    me->set_temp("anti_condition",1);
    set_heart_beat(1);
  }
  return result;
}

int unequip()
{
  object me=environment();
  int result = ::unequip();
  if( !query("equipped") )
  {
//    message_vision(GRN"$N"GRN"脫下了$n"GRN"，身旁的護壁逐漸淡去消逝。\n"NOR,me,this_object());
    me->delete_temp("anti_condition");
    set_heart_beat(0);
  }
  return result;
}

void heart_beat()
{
  object enemy,me=environment();
  int i;

  if( !this_object() || !me || !objectp(me) || !query("equipped") )
  {
    if(me) me->delete_temp("anti_condition");
    set_heart_beat(0);
    return;
  }
  if( query("equipped") && me->is_busy() )
  {
    enemy = offensive_target(me); //對手
    if(enemy && enemy->query("class")=="scholar" && userp(enemy)) i = 5; //獎勵書生 //對手是書生時 減少解定機率
    else i = 10;
    if(!userp(me)) i = 35; //非玩家時 提高解定機率
    if(i > random(100) && me->is_fighting())
    {
      me->delete_busy();
      me->add("use_light_ring",1);
      message_vision(HIC+"\n一股沁涼潔淨的氣息突然湧現，將$N"HIC"一時的滯澀及時衝破。\n"+NOR,me);
      if(random(me->query("use_light_ring")) >= 300 || !userp(me) && random(me->query("use_light_ring")) >= 10) //提高次數為30倍 減少玩家的麻煩 by blazakira
      {
        me->set("use_light_ring",0);
        me->delete_temp("anti_condition");
        message_vision(HIW"\n淨"HIC"水"HIY"光"HIM"之戒"HIR"的靈力消耗殆盡，『啪』的一聲灰飛湮滅。\n"NOR,me);
        destruct(this_object());
      }
    }
  }
  return;
}
