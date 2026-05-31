#include <weapon.h>
#include <ansi.h>
#include <combat.h>
inherit BLADE;
object ob=this_object();
void create()
{
	set_name("妖刀『村雨』",({"evil-mblade","blade"}));
	set_weight(300);
set("mblade-mark",1);
        set("no_sell",1);
      set("no_get",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_auc",1);
        if( clonep() )
          set_default_object(__FILE__);
        else 
        {
          set("unit","把");
set("long","妖刀『村雨』，刀鋒透明，刀身緋藍，像透明的雨點鑲在緋藍色的骨脊，刀略長，刀彎處有突出的小尖刃，臨陣殺敵有種莫名快感。\n");
          set("value", 100);
          set("material","crimsonsteel");
	}
	init_blade(1);
  	setup();
}	
void init()
{
        add_action("do_blood","blood");
        add_action("do_power","power");
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
	message_vision("[31m$N緩緩的用"+name+"往手腕處一劃, 鮮血如泉湧般淋遍整把"+name+"。\n
一會兒, 鮮血已被"+name+"吸乾殆盡,而"+name+"也旦然的發出一陣耀眼的[1;5;33m光芒[0;31m。[0m\n",me);
set_name(HIB"妖"BLU"刀"HIR"『"HIG"村"HIW"雨"HIR"』"NOR,({"evil-mblade","blade"}));
set("wield_msg","\n$N手上忽然多了一把$n，刀光漾映一片沁藍，刀揮動時還帶著一種像陰靈般的呻吟。\n\n");
set("unwield_msg","\n$N手上的$n像七月半猛鬼出關，忽然自手上消失無蹤。\n\n");
	set("weapon_prop/damage",100);
	set("value", 100);
	set("blooded",1);
set("mblade-mark",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
     set("no_get",1);
        set("no_drop",1);
        set("no_auc",1);
        me->set("kee",1);
        me->set("gin",1);
        me->set("sen",1);
        setup();
	return 1;
}

int do_power(string str)
{
        object weapon,me;
        me=this_player();
        if(me->query("evil-mblade") != 1)
        return notify_fail("你無法駕御此刀。\n");
        if(!objectp(weapon=me->query_temp("weapon"))
        || (string)weapon->query("skill_type")!="blade")
          return notify_fail("要有刀才能用聚魂術。\n");
   if(ob->query("blooded")!=1)
   return notify_fail("要先用血(blood)餵你的刀唷！\n");
        if(weapon->query_temp("evil-mblade")==1)
          return notify_fail("你已經在用了。\n");
        message_vision(
  HIR "$N以刀祭天，頓時陰靈凝聚於$n"+HIR+"。\n"NOR,me,weapon);
me->add_temp("apply/damage",100);
me->add_temp("apply/attack",100);
me->add_temp("apply/armor",100);
me->add_temp("apply/defense",100);
        weapon->set_temp("evil-mblade",1);
me->start_call_out((:call_other,__FILE__,"remove_effect",weapon,me:),me->query_skill("blade",1));
        return 1;
}
void remove_effect(object weapon,object me)
{
me->add_temp("apply/damage",-100);
me->add_temp("apply/attack",-100);
me->add_temp("apply/armor",-100);
me->add_temp("apply/defense",-100);
weapon->delete_temp("evil-mblade");
message_vision(HIW"陰風徐徐的陰靈，頓時從$n"+HIW+"飛散開來。\n"NOR,me,weapon);
}
int query_autoload()
{
	return 1;
}
