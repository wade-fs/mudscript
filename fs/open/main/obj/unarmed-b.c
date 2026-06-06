#include <weapon.h>
#include <ansi.h>
inherit UNARMED;
inherit SSERVER;
object user=this_player();
int be,bb,k,sp,qq;
void create()
{
        seteuid(getuid());
        set_name(HIR + "血"+HIB + "影摧"+HIR + "心" + NOR,({"blood-figring"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("long","不知何人曾用它來屠殺過無數百姓，濃厚的血腥味，似乎附有無數怨靈．\n");
                set("value",20000);
                set("material", "steel");
				set("material", "blacksteel");   
                set("weapon_prop/unarmed",10);
        }
        setup();
}
void init()

{
     add_action("do_drop","drop");
     add_action("do_auc","auc");
     add_action("do_wield","wield");
     add_action("do_give","give");
     add_action("do_unwield","unwield");
}
int do_wield(string str)
{
     ::wield();
     if( query("equipped") )
     {
        user = this_player();
message_vision("$N運足五成功\力戴上" + HIR + "血" + HIB + "影摧" + HIR + "心" + NOR + "，臉上微微露出猙獰的面孔。 \n" + NOR,user);
        set_heart_beat(1);
     }
}
int do_drop(string str)
{
   if(str=="blood-figring" || str=="all")
     if( query("equipped") )
     {
message_vision("$N將手上的" + HIR + "血" + HIB + "影摧" + HIR + "心" + NOR + "卸了下來，緩緩的吐出一口陰氣。\n",user);
        set_heart_beat(0);
     }
}
 int do_give(string str)
{
  if(str=="blood-figring" || str=="all")
     if( query("equipped") )
     {
message_vision("$N將手上的" + HIR + "血" + HIB + "影摧" + HIR + "心" + NOR + "卸了下來，緩緩的吐出一口陰氣。\n",user);
        set_heart_beat(0);
     }
}
int do_unwield(string str)
{
  if(!user) user=this_player();
   if(!user) set_heart_beat(0);
    if(!user) return 1;
   if(str=="blood-figring" || str=="all")
     if( query("equipped") )
     {
message_vision("$N將手上的" + HIR + "血" + HIB + "影摧" + HIR + "心" + NOR + "卸了下來，緩緩的吐出一口陰氣。\n",user);
        set_heart_beat(0);
     }
}
int do_auc(string str)
{
  if(str=="blood-figring" || str=="all")
     if( query("equipped") )
     {
message_vision("$N將手上的" + HIR + "血" + HIB + "影摧" + HIR + "心" + NOR + "卸了下來，緩緩的吐出一口陰氣。\n",user);
        set_heart_beat(0);
     }
}
void heart_beat()
{
  object enemy;
  int i;
  if(!user) user=this_player();
  if(!user) user=previous_object();
  if(!user) return ;
  if ( !objectp(user) )
        {

        set_heart_beat(0);
        return;
        }
 if( user->is_fighting() && query("equipped") )
  {
  if (random(10)>5)
    {
     enemy=offensive_target(user);
     if(!enemy) return ;
     if( environment(user) == environment(enemy) )
     message_vision(HIW + "\n一陣陣毒霧從" + HIR + "血" + HIB + "影摧" + HIR + "心" + HIW + "裡散發出來!!\n" + NOR,enemy);  
      if( random(5)<1  )
     {
      message_vision(HIY + "只見$N面露青光，似乎中毒不淺!!\n" + NOR,enemy);  
	  enemy->apply_condition("spring", 3);
      COMBAT_D->report_status(enemy, 0);
     }else
      message_vision(HIC + "只見$N身手不凡，一下躲過了毒霧。\n" + NOR,enemy);
	  }
  }
  return;
}

