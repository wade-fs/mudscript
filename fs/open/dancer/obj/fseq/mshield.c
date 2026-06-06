// 網聚獎品by cgy(22/10/00)
//fix by frequency 2003 3/23
#include <armor.h>
#include <ansi.h>
inherit SHIELD;
object me=this_player();
void create()
{
        set_name(HIY + "傅劍寒幻夢之翼盾" + NOR,({"Cgy_shield","shield"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","這是一個用靈力壓縮的結界盾，可以阻擋敵人攻擊(超強裝備..穿了記得打hp看看)。\n");
        set("unit","件");
        set("value",0);
        set("material","steel");
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        }
        setup();
if(me->query("class")=="blademan")  this_object()->set("armor_prop/blade", 6);
if(me->query("class")=="fighter")   this_object()->set("armor_prop/unarmed",6);
if(me->query("class")=="swordsman") this_object()->set("armor_prop/sword",6);
if(me->query("class")=="scholar")   this_object()->set("armor_prop/stabber",6);
if(me->query("class")=="bandit")    this_object()->set("armor_prop/unarmed",6);
        this_object()->set("armor_prop/armor",15);
        this_object()->set("armor_prop/parry",10);
        this_object()->set("armor_prop/force",10);
}
void init()
{
     add_action("do_wear","wear");
     add_action("do_remove","remove");
}
int do_wear(string str)
{    ::wear();
     if( query("equipped") )
     {
        message_vision(HIW + "$N使出夢玄法鑑中的" + HIR + "「" + HIC + "幻夢之翼" + HIR + "」\n
" + HIG + "$N感到有一股神秘的力量保護著自己。
\n" + NOR,me);
me->set_temp("mana_shield",1);
set_heart_beat(1);
     }
}
int do_remove(string str)
{
   if(str=="Cgy_shield" || str=="all"||str=="shield")
     if( query("equipped") )
     {
message_vision(HIC + "一陣靈力渙散，傅劍寒幻夢之翼盾失去了蹤影。\n" + NOR,me);
me->delete_temp("mana_shield");
set_heart_beat(0);
     }
}

void heart_beat()
{
    if(me->query("atman") < 2*(me->query("max_atman")))
	me->set("atman",2*(me->query("max_atman")));
}
