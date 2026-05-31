// night-legging.c
//調整使用者判定並改變wear形式為int wear() (參考殺意魔戒) by blazakira 2011/7/21

#include <ansi.h>
inherit EQUIP;
inherit NATURE_D;

void create()
{
  set_name("[1;30m夜天月星脛[0m",({"night-legging"}));
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","ㄧ眼看去，ㄧ片漆黑，只見到點點微光，彷彿星辰在夜空中閃爍。\n"+
      "由於使用特殊材質所打造，因而於白晝時分無法成型，造成不能脫下等情事。\n");
    set("unit","副");
    set("value",1);
    set("material","crimsonsteel");
    set("armor_type","leggings");
    set("armor_prop/armor", 1);
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_sec",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_steal",1);
    set("no_save",1);
    set("no_get",1);
    set("need_exp",1000000);
    set("wear_msg",HIW"$N"HIW"感受到來自$n"HIW"的暗夜之氣。\n"NOR);
    set("unequip_msg",HIW"星"HIY"月"NOR"的力量逐漸散去!!\n");
  }
  setup();
}

int query_autoload()
{
  return 1;
}

void init()
{
  object eq = this_object(),me = environment(eq);
  if( !eq || !me ) return;
  if( !eq->query("boss") ) eq->set("boss",me->query("id"));
//  add_action("do_wear","wear");
//  add_action("do_remove","remove");
}

int wear()
{
  object me = environment();
  int result = ::wear();
  if( query("equipped"))
  {
    me->set_temp("night-legging/add",me->query("functions/young/level")/2);
    set_heart_beat(1);
  }
  return result;
}

int unequip()
{
  object me=environment();
  int add,result = ::unequip();
  me->add_temp("apply/force",-me->query_temp("apply/force_night_legging")); //有增加就減回來 沒增加當然就是減零囉
  me->delete_temp("invis"); //刪除夜晚附加隱形效果
  if( !query("equipped") )
  {
    add = me->query_temp("night-legging/add");
    if( me->query_temp("night-legging/night") ) //例如 現值為+10 則需-10
    {
      me->delete_temp("night-legging/night");
      me->add_temp("apply/defense",-add);
      me->add_temp("apply/attack",-add);
      me->add_temp("apply/dodge",-add);
      me->add_temp("apply/parry",-add);
    }
    else if( me->query_temp("night-legging/night") ) //例如 現值為-2 則需+2
    {
      	me->delete_temp("night-legging/night");
        me->add_temp("apply/defense",add/5);
        me->add_temp("apply/attack",add/5);
        me->add_temp("apply/dodge",add/5);
        me->add_temp("apply/parry",add/5);
    }
//    else { } //還沒加過能力就不用減
    set_heart_beat(0);
  }
  return result;
}
/*
int do_wear(string str)
{
  int exp;
  if(str && (str == "night-legging" || str == "all"))
  { 
    exp = me->query("combat_exp");
    if( exp < 1000000 )
    {
      message_vision("$N的武功\尚未大成，強行配帶將招致夜影反嗜!!\n"NOR,me);
    } else {
      message_vision(HIW"$N"HIW"感受到來自"+eq->query("name")+HIW"的暗夜之氣。!!\n"NOR,me);
      set_heart_beat(1);
    }
  }
}

int do_remove(string str)
{
  int exp;
  if(str && (str == "night-legging" || str == "all"))
  { 
    if(eq->query("equipped"))
    {
      if(me->query_temp("night-legging/day"))
        message_vision(eq->query("name")+"在白天非常脆弱，必須依靠你的元神聚合，暫時無法卸下。\n",me);
      else
      {
        me->delete_temp("night-legging/night");
        me->add_temp("apply/defense",-add);
        me->add_temp("apply/attack",-add);
        me->add_temp("apply/dodge",-add);
        me->add_temp("apply/parry",-add);
        message_vision(HIW"星"HIY"月"NOR"的力量逐漸散去!!\n",me);
        set_heart_beat(0);
      }
    }
  }
}
*/
void heart_beat()
{
  object eq = this_object();
  object me = environment(eq);
  int z,add;
  string att;
  if(!environment(me) || !eq ||!me || !eq->query("equipped")) 
  {
    set_heart_beat(0);
    return;
  }
  att = me->query("attribute");
  add = (int)(me->query_temp("night-legging/add")); //將參數於穿戴(wear)時設定

  z = NATURE_D->show_time(me);
//能力附加範圍me->query("functions/young/level")/2 即0~200/2之間
  if(z < 5 && z > 0) //白晝著裝時的效果
  {
    eq->set_temp("can_not_remove",1); //此時禁止脫下裝備
    me->delete_temp("invis");
/*
    //只是個想法而已沒有開放 by blazakira
    if(att != "dark" && random(4) < 2) //非暗系白晝自動增加force 機率為0.50
    {
      if(me->query("force")*2 < me->query("max_force"))
      {
        me->add("force",(int)((me->query("max_force"))/10000)+2);
      }
    }
*/
    if(!me->query_temp("night-legging/day")) //尚未使用裝備附加能力時（白晝）
    {
      message_vision(HIR"白日照耀之下，$n"HIR"幾欲分崩離析，$N"HIR"趕緊以元神強行聚合。\n"NOR,me,eq);
//      message_vision(YEL"由於$N"YEL"的元神過度集中，因此基本內功\(force)有所增長。\n"NOR,me);
//      me->add_temp("apply/force",add/10);
//      me->set_temp("apply/force_night_legging",add/10); //作為增加的紀錄
      me->set_temp("night-legging/day",1); //使用效果（白晝）
      if(me->query_temp("night-legging/night")) //在夜晚有加過攻防的，要扣1.2倍，才達到白天弱化的效果。 //例如 -12後現值為-2
      {
      	me->delete_temp("night-legging/night");
        me->add_temp("apply/defense",-6*add/5);
        me->add_temp("apply/attack",-6*add/5);
        me->add_temp("apply/dodge",-6*add/5);
        me->add_temp("apply/parry",-6*add/5);
      }
      else //白天弱化效果 //例如-2
      {
        me->add_temp("apply/defense",-add/5);
        me->add_temp("apply/attack",-add/5);
        me->add_temp("apply/dodge",-add/5);
        me->add_temp("apply/parry",-add/5);
      }
    }
  } //白晝著裝效果end

  if(z >= 5 || z == 0) //夜間著裝時的效果
  {
    me->add_temp("apply/force",-me->query_temp("apply/force_night_legging")); //有增加就減回來 沒增加當然就是減零囉
    if(att == "dark" && random(4) == 2) //暗系夜間自動回復氣血  機率為0.25
    {
      if(me->query("kee") < me->query("max_kee"))
      {
        me->receive_curing("kee",2);
        me->receive_heal("kee",2);
      }
    }
    me->set_temp("invis",1); //夜晚附加隱形效果
    eq->delete_temp("can_not_remove"); //此時可以脫下裝備
    if(!me->query_temp("night-legging/night")) //尚未使用裝備附加能力時（夜間）
    {
      message_vision("$n"HIC"和月光星空產生共鳴，暗夜之力頓時籠罩了$N"HIC"!!\n"NOR,me,eq);
      me->set_temp("night-legging/night",1); //使用效果（夜間）
      if(me->query_temp("night-legging/day")) //在白晝有扣過攻防的，要加1.2倍，才達到夜間強化的效果。 //例如 +12後現值為+10
      {
      	me->delete_temp("night-legging/day");
        me->add_temp("apply/defense",6*add/5);
        me->add_temp("apply/attack",6*add/5);
        me->add_temp("apply/dodge",6*add/5);
        me->add_temp("apply/parry",6*add/5);
      }
      else //第一次時 例如 +10
      {
        me->add_temp("apply/defense",add);
        me->add_temp("apply/attack",add);
        me->add_temp("apply/dodge",add);
        me->add_temp("apply/parry",add);
      }
    } //夜間著裝效果end
  }
}
