//調整訊息 by blazakira 2011/7/28

#include <armor.h>
#include <ansi.h>
inherit EQUIP;
object me=this_player();
int cor,kar,intt,spi,cps;
void create()
{
  set_name(HIY"血魔戒"NOR,({"bloodring","ring"}) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit","件");
    set("value", 0);
    set("material","gem");
    set("long","此為血魔以血肉所做成的戒指..似乎有強大的力量。\n");
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_get",1);
    set("armor_type","finger");
    set("armor_prop/armor",20);
//    set("wear_msg",HIC"戴上$n"HIC"……$n"HIC"因吸收$N"HIC"身上血氣而光芒四射。\n"NOR);
//    set("unequip_msg",YEL"$N脫下了$n"HIC"……$N"YEL"身上的血光頓時消失。\n"NOR);
  }
  setup();
}

void init()
{
  add_action("do_wear","wear");
  add_action("do_remove","remove");
}

int do_wear(string str)
{
  ::wear();
  if( query("equipped") )
  {
    kar = me->query_kar(1);
    cor = me->query_cor(1);
    cps = me->query_cps(1);
    spi = me->query_spi(1);
    intt = me->query_int(1);
    message_vision(HIC"戴上血魔戒……血魔戒因吸收$N"HIC"身上血氣而光芒四射。\n"NOR,me);
    set_heart_beat(1);
  }
}

int do_remove(string str)
{
  if(str=="swordmaster ring" || str=="all" || str=="ring")
    if( query("equipped") )
    {
      message_vision(YEL"$N脫下了血魔戒……$N"YEL"身上的血光頓時消失。\n"NOR,me);
      set_heart_beat(0);
    }
}

void heart_beat()
{
  object *enemy;

  int i;
  if( !objectp(me) )
  {
    set_heart_beat(0);
    return;
  }

  if( me->is_fighting()&&query("equipped")&&me->is_busy() )
  {
    enemy=me->query_enemy();
    i=random(sizeof(enemy));

    if( random(cor+cps+spi) > 100-random(kar+intt) )
    {
      me->delete_busy();
      message_vision(HIR+"\n血魔戒發出強烈血光頓時血氣籠罩$N"HIR"全身……$N"HIR"吸收血氣之後精神為之一振。\n\n"+NOR,me);
    }
  }
  return;
}
