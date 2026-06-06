//極毒無比，細如牛毛，極為少見，取自血變，因此數量很少
#include <weapon.h>
#include <ansi.h>
inherit THROWING;
void create()
{
     set_name("黑血神針",({"black blood","blood","black"}));
     set_weight(1);
     if( clonep() )
         set_default_object(__FILE__);
     else {
       set("unit","支");
       set("base_unit","支");
       set("long","傳說中只存在於飄花宮的致毒武器，只有極少數暗器高手會使用\n
                    你可以用shot將黑血神針射出去");
       set("light_up",-1);
       set("value",1000);
       set("no_sell",1);
       set ("no_drop",1);
       set("material", "silver");
       set("wield_msg","$N拿起$n,心中十分興奮，這就是天下至毒--黑血神針\n");
       set("unwield_msg", "$N將$n放入金製護套，以免誤傷自己\n");
     }
      init_throwing(10);
      set_amount(1);
      setup();
}
void init()
{
    if( this_player()==environment() )
    {
       add_action("black_shot","shot");
    }
}

int black_shot(string arg)
{
   int sk;
   object ob,me,target;
   string str;
   me = this_player();
   ob = this_object();
   sk=me->query_skill("throwing",1);
   if( !arg )
       return notify_fail("你想射空氣呀﹖\n");
   if (me->query("class") != "killer")
	return 0;
   target = present(arg, environment(me)); 
    if(!target) return notify_fail("找不到敵人!!\n");
   if( target->query("no_kill") ) 
       return notify_fail("這傢伙你不能動就是不能動。\n");
   if( !wizardp(me) && environment(me)->query("no_fight") )
       return notify_fail("這裡禁止戰鬥。\n");
   if( !target->is_character() || target->is_corpse() )
       return notify_fail("看清楚點,它並不是活物。\n");
   if( target == me ) 
       return notify_fail("殺手目前還沒有，練屍魂人的打算啦！不要找死啦！\n");
   message_vision("$N把身上的黑血神針往$n的身上射了過去。\n\n",me,target);
   if( random(sk) > random(target->query_skill("dodge",1)/2))
   {
        message_vision(HIM "$N一個不留意,被黑血神針刺中了！\n" NOR,target);
        target->apply_condition("blood",sk/10);
        add_amount(-1);
        return 1;
   }
   else
   {
        message_vision(
        HIC "$N急急忙忙往後跳開, 被黑血神針嚇出了一深冷汗。\n" NOR,target);
        add_amount(-1);
        return 1;
   }
}

int wield()
{
 object me=this_player();

 if(me->query_skill_mapped("throwing") != "rain-throwing")
 {
	tell_object(me,"殺手專用武器，你不是殺手，所以你不會用！\n");
        return 0;
 }
 if(me->query_skill("throwing",1) < 80 )
 {
 	tell_object(me,"小朋友，暗器手法練好一點，再用吧！\n");
        return 0;
 }
}
