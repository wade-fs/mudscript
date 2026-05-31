//cure staff by frequency
//調整使用者參數為environment() by blazakira 2011/7/24

#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
  set_name(HIW "治療之杖" NOR,({"cure staff","staff"}));
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit","根");
    set("value",0);
    set("no_put",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_sell",1);
    set("no_auc",1);
    set("no_give",1);
    set("no_steal",1);
    set("sharp",10);
    set("material","crimsonsteel");
    set("long","由天界掉落人世間的奇異之杖。\n使用方法：請在戰鬥中打 cure。\n"NOR);
  }
  init_staff(0);
  set("weapon_prop/dodge", 15);
  set("weapon_prop/parry", 15);
  setup();
}

void init()
{
  add_action("do_perform","cure");
}

void heart_beat()
{
  object *target,room,me=environment();
  int i,j,spi,per,kar;
  if( !objectp(me) || !query("equipped") ) {
    set_heart_beat(0);
    return;
  }
  spi=me->query_spi();
  per=me->query_per();
  kar=me->query_kar();
  room= environment(me);
  target = me->query_enemy(room);
  i=sizeof(target);
  if(query("equipped") && random(90) < kar+spi+per) 
  {
    me->add_temp("recover_q",-1);
    if(me->query_temp("recover_q")!=0)
    {
      for(j=0;j<i;j++)
      {
        message_vision(HIW"\n一道白光由$N"HIW"手中的治療之杖射向$n"HIW"，$n"HIW"發現傷勢逐漸復原了。\n"NOR,me,target[j]);
        target[j]->receive_curing("kee",200);
        target[j]->receive_heal("kee",200);
        COMBAT_D->report_status(target[j]);
      }
    } else {          
      set_heart_beat(0);
      message_vision(HIB"\n$N"HIB"注入治療之杖的能源已經用盡，"HIW"白色聖光"HIB"逐漸黯淡下來。\n"NOR,me);
    }
  }
  return;
}

int do_perform()
{
  object *target,room, me = environment() ;
  int i,j;

  room= environment(me);
  target = me->query_enemy(room);
  i=sizeof(target);
  set_heart_beat(1);
  if(me->is_fighting() && me->query("force") > 100)
  {
    me->set_temp("recover_q",7);
    for(j=0;j<i;j++)
    {
      target[j]->receive_curing("kee",(target[j]->query("max_kee"))/10);
      target[j]->receive_heal("kee",(target[j]->query("max_kee"))/10);
      me->add("force",-100);
      me->start_busy(1);
      message_vision(HIY"\n$N"HIY"潛運內力，緩緩送入治療之杖，只見治療之杖"HIW"白光"HIY"大盛，\n"
        "沐浴在"HIW"白色聖光"HIY"下的$n"HIY"感覺有如重生。\n"NOR,me,target[j]);
      COMBAT_D->report_status(target[j]);
    }
  } else {
    return notify_fail("治療之杖的威力只能在戰鬥中發揮喔!!");
  }
  return 1;
}

int query_autoload()
{
  return 1;
}
