//by frequency
#include <armor.h>
#include <ansi.h>
inherit EQUIP;
inherit SSERVER;
object me = this_player();
object *target,room;
void create()
{
    set_name(HIC + "英雄" + HIY + "腕輪" + NOR,({"Hero Hands","hands"}) );
    set_weight(100);
    if( clonep() )
    set_default_object(__FILE__);
    else
   {
      set("long",HIC + "傳說中的救世之腕，唯有能捨身取義(sacrifice)的英雄才能解放此腕的真實威力。\n" + NOR);
      set("unit", "雙");
      set("value", 9000000);
      set("material","steel");
      set("armor_type","hands");
      set("armor_prop/armor",  10);
      set("armor_prop/parry", 10);
      set("armor_prop/force", 15);
      set("armor_prop/dodge", 10);
      set("armor_prop/attack",10);
      set("no_auc",1);
      set("no_sell",1);
 //     set("no_give",1);
      set("no_put",1);
      set("no_drop",1);
      set("no_get",1);
      set("no_steal",1);
      set("no_save",1); 
      set("wear_msg",HIC + "$N感受到手中中傳入歷代英雄的偉大思想。\n" + NOR);
   }
      setup();
}
void init()
{
     add_action("do_sacrifice","sacrifice");
}
int do_sacrifice()
{
if(!query("equipped")) return notify_fail("沒裝備起來不能用喔!!");
set_heart_beat(1);
message_vision(HIB + "$N聚氣凝神，準備隨時發動全力一擊\n" + NOR,me);
return 1;
}
void heart_beat()
{
int i,j,aa;
if( (me->query("kee") < 2000) || (me->query("gin") < 2000) || (me->query("sen") < 2000) )
if(me->is_fighting() && query("equipped"))
{
      room = environment(me);
      target = me->query_enemy(room);
      i = sizeof(target);
      aa = random(100);
if(aa <= 10)
      {
message_vision(HIW + "
$N自殘己身祭天，施展出由" + HIC + "英雄" + HIY + "腕輪" + HIW + "所領悟出的神聖武技

                           " + HIR + "無 極 天 道
                           
" + CYN + "只見神聖的天火將戰場完全掩蓋\住...\n" + NOR,me);
       command("remove all");
       for(j=0;j<i;j++)
       {
       message_vision(HIM + "$n慘遭天火焚身，瞬間五內焦爛而亡。\n" + NOR,me,target[j]);
       target[j]->die();
       }
       me->set("gin",-1000);
       me->set("eff_gin",-1000);    //最強效果讓ppl跟敵人同歸於盡
       set_heart_beat(0);
      }
if(aa <= 40 && aa > 10)
      {
      	me->set("kee",me->query("max_kee"));
      	me->set("eff_kee",me->query("max_kee"));
      	me->set("gin",me->query("max_gin"));
      	me->set("eff_gin",me->query("max_gin"));
      	me->set("sen",me->query("max_sen"));
      	me->set("eff_sen",me->query("max_sen"));
        message_vision(HIC + "英雄" + HIY + "腕輪" + HIW + "上的英魂以神聖靈力，將$N身上的傷勢完全治癒。\n" + NOR,me);
        COMBAT_D->report_status(me);
        set_heart_beat(0);
        //ppl狀態全回復
        //考慮發展為除本身以外的同房間ppl全回復
      }
if(aa < 100 && aa > 40)
      {
       int gin,kee,sen,mgin,mkee,msen,kk,exp,force,atman,mana;
       gin = me->query("gin");
       kee = me->query("kee");
       sen = me->query("sen");
       mgin = me->query("max_gin");
       mkee = me->query("max_kee");
       msen = me->query("max_sen");
       exp = (me->query("combat_exp"))/400000;
       force = (me->query("max_force")) - (me->query("force"));
       atman = (me->query("max_atman")) - (me->query("atman"));
       mana = (me->query("max_mana")) - (me->query("mana"));
       if(force < 0)  force = 0;
       if(atman < 0)  atman = 0;
       if(atman < 0)  force = 0;
       if(exp < 1) exp = 1;
       kk = exp*((mkee-kee) + (mgin-gin) + (msen-sen) + force + atman + mana);
message_vision(HIW + "$N的救世之心感動了" + HIC + "英雄" + HIY + "腕輪" + HIW + "裡的歷代英魂，
引導$N將全身剩餘生命力集中，使出最後一擊。\n" + NOR,me);
       for(j=0;j<i;j++)
       {
       target[j]->receive_wound("kee",kk);
       message_vision(HIB + "$n直接承受了$N的瀕死一擊，遭到難以想像的重創。\n" + NOR,me,target[j]);
       COMBAT_D->report_status(target[j]);
       //敵重傷害
       }
       me->set("gin",0);
       me->set("eff_gin",1);
       me->set("kee",0);
       me->set("eff_kee",1);
       me->set("sen",0);
       me->set("eff_sen",1);
       me->start_busy(1);
       COMBAT_D->report_status(me);
       set_heart_beat(0);
      }
}
return;
}
int query_autoload()
{
return 1;
}
