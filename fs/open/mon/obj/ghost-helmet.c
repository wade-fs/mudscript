// badhelmet.c by Oda

#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
  set_name(HIY + "妖幻頭帶" + NOR, ({"ghost helmet", "helmet"}));
  set_weight(50);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "千年樹妖–舞風揚所擁有，戴在頭上你的身子只感到一陣輕飄飄的。\n");
    set("unit", "頂");
    set("value", 1000000);
    set("material", "steel");
    set("type", 1); 
    set("no_steal",1);
    set("armor_prop/armor", 15);
    set("armor_prop/dodge", 5);
    set("armor_prop/parry", 5);
    set("armor_prop/attack", 5);
    set("armor_prop/force", 10);
    set("thunder", 100);
    set("wear_msg", HIW + "輕風細雨之中，$n" + HIW + "戴在$N頭上散發出一股暖暖的熱流。\n" + NOR);
    set("unequip_msg", HIW + "$N輕輕的卸下$n" + HIW + "，所產生的暖流也瞬間消散無蹤。\n" + NOR);
  }
  setup();
}

int wear()
{
  object me=environment();
  int result = ::wear();
  if( query("equipped") && !me->query_temp("gh_thunder") )
  {
    me->set_temp("thunder",40); //這是無效的 因為equip.c中 會將set("thunder",xxx);取代me->set_temp("thunder",xxx); by blazakira
    me->set_temp("gh_thunder",1);
  }
  return result;
}

int unequip()
{
  object me=environment();
  int result = ::unequip();
  if( !query("equipped") )
  {
    me->delete_temp("thunder");
    me->delete_temp("gh_thunder");
  }
  return result;
}

/*
void init()
{
  add_action("do_wear","wear");
  add_action("do_remove","remove");
}

int do_wear(string str)
{
  if( str=="all" || str=="ghost helmet" || str == "helmet" )
  {
    ::wear();
    if( query("equipped") )
    {
      if(!me) me=environment();
      if(!living(me)) me=this_player();
      if(!me) me=previous_object();
      if(me)
        me->set_temp("thunder",40);
      message_vision(HIW + "輕風細雨之中﹐" + HIY + "妖幻頭帶" + HIW + "戴在$N頭上散發出一股暖暖的熱流。\n" + NOR,me);
    }
  }
}

int do_remove(string str)
{
  if( str=="ghost helmet" || str=="all" || str=="helmet" ) 
  {
    if( query("equipped") )
    {
      if(!me) me=environment();
      if(!living(me)) me=this_player();
      if(!me) me=previous_object();
      if(me)
      me->delete_temp("thunder");
    }
  }
}
*/
