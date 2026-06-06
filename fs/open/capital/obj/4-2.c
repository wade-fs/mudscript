#include <weapon.h>
#include <combat.h>
inherit BLADE;
object ob=this_object();
void create()
{
	set_name("寶刀『紅袖』",({"red-sleeve blade","blade"}));
	set_weight(10000);
        if( clonep() )
          set_default_object(__FILE__);
        else 
        {
          set("unit","把");
      	  set("long","\n『紅袖』﹐刀鋒是透明的﹐刀身緋紅﹐像透明的玻璃鑲裹著緋紅色的骨脊﹐刀略短﹐刀彎處如絕代佳人的纖腰﹐讓人一見鐘情﹐一見難忘。\n");
          set("value", 100);
          set("material","blacksteel");
	}
	init_blade(1);
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
          if(exp<=0)    exp=5000;
          else          exp=5000+exp/10;
          if( random(exp) > random(20000) && random(3)==0 && me->query_kar()>random(30) )
          {
            message_vision("\n$N手中 "+ob->query("name")+" 漾出一片刀光, 如同夢一般之間, $n的傷口便激出一道血泉。\n\n",me,enemy[i]);
	    enemy[i]->apply_condition("bleeding", 50);
	    enemy[i]->add("kee",-20);
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
	"一陣耀眼的1;5;33m光芒。\n",me);
	set_name("寶刀『紅袖』",({"red-sleeve blade","blade"}));                                                       
  	set("wield_msg","\n$N手上忽然多了一把$n﹐刀光漾映一片水紅﹐刀揮動時還帶著一種像音籟般的清吟﹐還掠起微微的香氣。\n\n");
	set("unwield_msg","\n$N手上的$n像一抹夕暉﹐像一場細雨﹐忽然自手上消失無蹤。\n\n");
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
