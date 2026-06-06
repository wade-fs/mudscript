#include <weapon.h>
inherit SWORD;
object ob=this_object();
void create()
{
	set_name("神劍『血河』",({"blood-river sword","sword"}));
	set_weight(10000);
        if( clonep() )
          set_default_object(__FILE__);
        else 
        {
          set("unit","把");
	  set("long","\n『血河』﹐劍身凹凸不平﹐劍鋒其鈍無比﹐劍脊彎曲﹐劍尖歪斜﹐如果說有出色之處﹐便是這把劍隱隱透出紅光。\n");
          set("value", 10);
          set("material","blacksteel");
        }
	init_sword(1);      
        setup();
}
void init()
{
	add_action("do_blood","blood");
	set_heart_beat(1);
}
void heart_beat()
{
        int i,exp;
        object me=environment(this_object());
        object *enemy;
        if( me->is_fighting() && ob->query("equipped")=="wielded" && ob->query("blooded") )
	{
	  enemy=me->query_enemy();
          i=random(sizeof(enemy));
	  exp=me->query("combat_exp")-enemy[i]->query("combat_exp");
	  if(exp<=0)	exp=5000;
	  else		exp=5000+exp/10;
	  if( random(exp) > random(20000) && random(4)==0 && me->query_kar()>random(30) )
	  {
            message_vision("\n$N手中 "+ob->query("name")+" 突然化成滿室耀眼紅光籠罩住$n。\n\n",me,enemy[i]);
            enemy[i]->add("kee",-100);
            COMBAT_D->report_status(enemy[i]);
	  }
	}
}
int do_blood(string str)
{
	object me=this_player();
	string name=ob->query("name");
	if( str != ob->query("id") )
	  return notify_fail("請鍵入武器全名。\n");
	if( ob->query("blooded") )
	  return notify_fail("這把武器已得到你的犧牲。\n");
	if( ob->query("equipped") == "wielded" )
	  return notify_fail("請先將武器卸下。\n");
	message_vision("$N緩緩的用"+name+"往手腕處一劃, 鮮血如泉湧般淋遍整把"+
	name+"。\n不一會兒, 鮮血已被"+name+"吸乾殆盡, 而"+name+"也旦然的發出"+
	"一陣耀眼的光芒。\n",me);
	set_name("神劍『血河』",({"blood-river sword","sword"}));
	set("weapon_prop/damage",99);
	set("value", 100000);
	set("wield_msg","\n$N緩緩的拔出$n﹐劍作龍吟﹐清脆悅耳。一種乍看令人心動﹐細看足以讓人心血賁動的紅光﹐自劍身透了出來。\n\n");
	set("unwield_msg","\n$N將$n收入厚套古鞘之內﹐霎那間有如太陽西下般﹐滿地紅光但然消失。\n只見劍鞘卻隱然透漾著血紅﹐一如人體裡的血脈一般流動。\n\n");
	set("blooded",1);
	setup();
	call_out("wake_up",4);
	me->unconcious();
	return 1;
}
void wake_up()
{
	object who=this_player();
	who->remove_call_out("revive");
	who->revive();
}
