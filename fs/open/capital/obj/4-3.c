#include <weapon.h>
#include <combat.h>
inherit BLADE;
object ob=this_object();
void create()
{
	set_name("魔刀『不應』",({"should-not blade","blade"}));
	set_weight(10000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit","把");
      	  set("long","\n『不應』,刀身無顏色﹐黯淡無光﹐但瞧在每個人眼裡﹐卻都有不同顏色有的發出亮烈的黑光﹐有的如青電﹐有的如赭血﹐有的竟是五彩光華﹐目為之炫。\n");
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
        int i,exp,count;
        object me=environment(this_object());
        object *enemy;
        if( me->is_fighting() && ob->query("equipped")=="wielded" && ob->query("blooded") )
        {
          enemy=me->query_enemy();
					if(!sizeof(enemy)) return ;
          i=random(sizeof(enemy));
          exp=me->query("combat_exp")-enemy[i]->query("combat_exp");
          if(exp<=0)    exp=5000;
          else          exp=5000+exp/10;
          if( random(exp) > random(20000) && random(5)==0 && me->query_kar()>random(30) )
          {
            message_vision("\n$N手中 "+ob->query("name")+" 不安的抖動起來, 散發出可怕的魔力, 摧動出$N無窮的戰意直指$n。\n\n",me,enemy[i]);
	    for(count=0;count<5;count++)
	    {
	      message_vision(ob->query("name")+"引領著$N的手做出瘋狂攻擊!!\n",me);
	      COMBAT_D->do_attack(me,enemy[i],ob, TYPE_QUICK);
	    }
	  }
	}
}	
int do_blood(string str)
{
        object me=this_player();
        object ob=this_object();
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
	set_name("魔刀『不應』",({"should-not blade","blade"}));
	set("wield_msg","\n$N抽出$n﹐一刀在手﹐整個人的戰志都似被帶動﹐發出瘋狂的攻擊﹐殺力大增。\n\n");
	set("unwield_msg","$N將手上$n放開﹐整個人洩了一口氣﹐緩緩的將$n收起。\n\n");
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
