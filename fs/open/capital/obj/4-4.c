#include <weapon.h>
#include <combat.h>
inherit SWORD;
object ob=this_object();
void create()
{
	set_name("奇劍『挽留』",({"stay sword","sword"}));
        set_weight(10000);
        if( clonep() )
          set_default_object(__FILE__);
        else 
        {
          set("unit","把");
	  set("long","\n『挽留』﹐整把劍身是直的﹐只有劍的把手是彎的﹐彎如半月﹐令人懷疑要如何持劍。上頭刻著\n"+
	"		 「挽留天涯挽留人,挽留歲月挽留你」。\n");
          set("value", 100);
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
        int i,exp,count;
        object me=environment(this_object());
        object *enemy;
        if( me->is_fighting() && ob->query("equipped")=="wielded" && ob->query("blooded") )
        {
          enemy=me->query_enemy();
          i=random(sizeof(enemy));
          exp=me->query("combat_exp")-enemy[i]->query("combat_exp");
          if(exp<=0)    exp=5000;
          else          exp=5000+exp/10;
          if( random(exp) > random(20000) && random(2)==0 && me->query_kar()>random(30) )
          {
	    message_vision("$N手上 "+ob->query("name")+" 幻化出一片炫麗迷惘, 而$n好似失了神似的呆立不動。\n\n",me,enemy[i]);
	    enemy[i]->start_busy(10);
	    enemy[i]->add("kee",-10);
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
	set_name("奇劍『挽留』",({"stay sword","sword"}));
	set("wield_msg","\n$N突然拔出$n﹐只覺得又快、又奇、又絕﹐三分驚豔﹐三分瀟灑﹐三分惆悵﹐加上一分的不可一世。\n\n");
	set("unwield_msg","$N將$n收起﹐只覺得忽然之間若有所失。\n\n");
	set("weapon_prop/damage",99);
        set("value", 100000);
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
