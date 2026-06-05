//改變wear形式為int wear() (參考殺意魔戒) by blazakira 2011/7/24

#include <armor.h>
#include <ansi.h>
inherit FINGER;
inherit SSERVER;

void create()
{
  set_name(HIB + "魔龍睛戒" + NOR,({"mdragon-ring"}));
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit","件");
    set("value", 0);
    set("material","gem");
    set("long","此戒為魔龍眼睛所製成，有強大防護力。\n");
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_steal",1);
    set("wear_msg",HIB + "戴上了魔龍睛戒後，一股邪惡的力量籠罩了$N" + HIB + "。\n" + NOR);
    set("unequip_msg",HIB + "$N" + HIB + "脫下了魔龍睛戒邪惡的力量頓時消失。\n" + NOR);
  }
  setup();
  set("armor_prop/move",  2);
  set("armor_prop/dodge", 3);
  set("armor_prop/parry", 4);
  set("armor_prop/force", 5);
  set("armor_prop/armor", 10);
}

int query_autoload()
{
  return 1;
}

int wear()
{
  object me;
  int ret = ::wear();
  if( query("equipped"))
  {
    me=environment();
    if(!me->query_temp("have_basic_skill")) {
      if(me->query("class")=="blademan")  me->add_temp("apply/blade", 5);
      if(me->query("class")=="fighter")   me->add_temp("apply/unarmed",5);
      if(me->query("class")=="swordsman") me->add_temp("apply/sword",5);
      if(me->query("class")=="scholar")   me->add_temp("apply/stabber",5);
      if(me->query("class")=="bandit")    me->add_temp("apply/unarmed",5);
      if(me->query("class")=="marksman")  me->add_temp("apply/archery", 5);
      if(me->query("class")=="prayer")    me->add_temp("apply/unarmed",5);
      if(me->query("class")=="poisoner")  me->add_temp("apply/whip",5);
      if(me->query("class")=="taoist")    me->add_temp("apply/whip",5);
      if(me->query("class")=="killer")    me->add_temp("apply/throwing",5);
      if(me->query("class")=="doctor")    me->add_temp("apply/stabber", 5);
      if(me->query("class")=="bonze")     me->add_temp("apply/unarmed",5);
      if(me->query("class")=="officer")   me->add_temp("apply/dagger",5);
      if(me->query("class")=="dancer")    me->add_temp("apply/unarmed",5);
      me->set_temp("have_basic_skill",1);
    }
    set_heart_beat(1);
  }
  return ret;
}

int unequip()
{
  object me = environment();
  int ret = ::unequip();
  if( !query("equipped") )
  {
    if(me->query_temp("have_basic_skill")==1) {
      if(me->query("class")=="blademan")  me->add_temp("apply/blade", -5);
      if(me->query("class")=="fighter")   me->add_temp("apply/unarmed",-5);
      if(me->query("class")=="swordsman") me->add_temp("apply/sword",-5);
      if(me->query("class")=="scholar")   me->add_temp("apply/stabber",-5);
      if(me->query("class")=="bandit")    me->add_temp("apply/unarmed",-5);
      if(me->query("class")=="marksman")  me->add_temp("apply/archery", -5);
      if(me->query("class")=="prayer")    me->add_temp("apply/unarmed",-5);
      if(me->query("class")=="poisoner")  me->add_temp("apply/whip",-5);
      if(me->query("class")=="taoist")    me->add_temp("apply/whip",-5);
      if(me->query("class")=="killer")    me->add_temp("apply/throwing",-5);
      if(me->query("class")=="doctor")    me->add_temp("apply/stabber", -5);
      if(me->query("class")=="bonze")     me->add_temp("apply/unarmed",-5);
      if(me->query("class")=="officer")   me->add_temp("apply/dagger",-5);
      if(me->query("class")=="dancer")    me->add_temp("apply/unarmed",-5);
      me->delete_temp("have_basic_skill");
    }
    set_heart_beat(0);
  }
  return ret;
}

/*
void init()
{
  add_action("do_wear","wear");
  add_action("do_remove","remove");
}

int do_wear(string str)
{
  if(str=="all" || str=="mdragon-ring")
  {
    ::wear();
    if( query("equipped") )
    {
      me=environment();
      if(!living(me)) me=this_player();
      if(!me) me=previous_object();
      if(me)
        message_vision(HIB + "戴上了魔龍睛戒後，一股邪惡的力量籠罩了$N。\n" + NOR,me);
      set_heart_beat(1);
    }
    if(me)
      if(!me->query_temp("have_basic_skill")) {
        if(me->query("class")=="blademan")  me->add_temp("apply/blade", 5);
        if(me->query("class")=="fighter")   me->add_temp("apply/unarmed",5);
        if(me->query("class")=="swordsman") me->add_temp("apply/sword",5);
        if(me->query("class")=="scholar")   me->add_temp("apply/stabber",5);
        if(me->query("class")=="bandit")    me->add_temp("apply/unarmed",5);
        if(me->query("class")=="marksman")  me->add_temp("apply/archery", 5);
        if(me->query("class")=="prayer")    me->add_temp("apply/unarmed",5);
        if(me->query("class")=="poisoner")  me->add_temp("apply/whip",5);
        if(me->query("class")=="taoist")    me->add_temp("apply/whip",5);
        if(me->query("class")=="killer")    me->add_temp("apply/throwing",5);
        if(me->query("class")=="doctor")    me->add_temp("apply/stabber", 5);
        if(me->query("class")=="bonze")     me->add_temp("apply/unarmed",5);
        if(me->query("class")=="officer")   me->add_temp("apply/dagger",5);
        if(me->query("class")=="dancer")    me->add_temp("apply/unarmed",5);
        me->set_temp("have_basic_skill",1);
      }
  }
}

int do_remove(string str)
{
  if(str=="mdragon-ring"||str=="all") {
    if(!me) me=environment();
    if(!living(me)) me=this_player();
    if(!me) me=previous_object();

    if( query("equipped") )
    {
      if(me)
        message_vision(HIB + "$N脫下了魔龍睛戒邪惡的力量頓時消失。\n" + NOR,me);
      set_heart_beat(0);
    }
    if(me->query_temp("have_basic_skill")==1) {
      if(me->query("class")=="blademan")  me->add_temp("apply/blade", -5);
      if(me->query("class")=="fighter")   me->add_temp("apply/unarmed",-5);
      if(me->query("class")=="swordsman") me->add_temp("apply/sword",-5);
      if(me->query("class")=="scholar")   me->add_temp("apply/stabber",-5);
      if(me->query("class")=="bandit")    me->add_temp("apply/unarmed",-5);
      if(me->query("class")=="marksman")  me->add_temp("apply/archery", -5);
      if(me->query("class")=="prayer")    me->add_temp("apply/unarmed",-5);
      if(me->query("class")=="poisoner")  me->add_temp("apply/whip",-5);
      if(me->query("class")=="taoist")    me->add_temp("apply/whip",-5);
      if(me->query("class")=="killer")    me->add_temp("apply/throwing",-5);
      if(me->query("class")=="doctor")    me->add_temp("apply/stabber", -5);
      if(me->query("class")=="bonze")     me->add_temp("apply/unarmed",-5);
      if(me->query("class")=="officer")   me->add_temp("apply/dagger",-5);
      if(me->query("class")=="dancer")    me->add_temp("apply/unarmed",-5);
      me->delete_temp("have_basic_skill");
    }
  }
}
*/
void heart_beat()
{
  object enemy,me;
  int mexp,texp;
  int i,kar,cor,spi,cps,itt,per;
  me = environment(this_object());
  if( !objectp(me) || !query("equipped") )
  {
    set_heart_beat(0);
    return;
  }
  kar = me->query_kar();  // 為避免因戰功eq及邪靈導致過高的值影響門派平衡  將這些值最高限定max 35
  cor = me->query_cor();
  cps = me->query_cps();
  spi = me->query_spi();
  itt = me->query_int();
  per = me->query_per();
  if(kar > 35) kar = 35;
  if(cor > 35) cor = 35;
  if(cps > 35) cps = 35;
  if(spi > 35) spi = 35;
  if(itt > 35) itt = 35;
  if(per > 35) per = 35;
  mexp = me->query("combat_exp");
  if( me->is_fighting()&&query("equipped")&&me->is_busy() )
  {
    enemy = offensive_target(me);
    if(enemy){
      texp = enemy->query("combat_exp");
      if(enemy->query("class")=="scholar" && userp(enemy)) mexp=mexp*3/4;
      if(!userp(enemy)) mexp=mexp*1.5;
      if(mexp-texp<0) mexp=30;
      else if(mexp-texp>=5000000) mexp=80; //自己的exp比對手高時
      else if(mexp-texp>=4000000) mexp=70;
      else if(mexp-texp>=3000000) mexp=60;
      else if(mexp-texp>=2000000) mexp=50;
      else if(mexp-texp>=1000000) mexp=40;
      else mexp=35;
      if(mexp>random(100)) { //mexp%(百分之mexp的機率)
        if(random(cor+cps+itt+per) > 85-random(kar*2+spi)) //因為玩家都不重視per只設10  所以加入per影響  為了公平將75改為85
        {
          me->delete_busy();
          message_vision(HIW+"\n魔龍睛戒忽然散發出一股邪惡的力量，使$N" + HIW + "衝開了身上被封之穴道。\n"+NOR,me);
        }
      }
    }
  }
  return;
}
