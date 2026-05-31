#include <combat.h>
#include <ansi.h>
inherit F_SPELL;
inherit SSERVER;
int count;
string *ATTACK_MSG=({
HIW"      $N閉上雙眼，口中唸道『創世之力，隨之震裂』四周的空氣突然沉重了起來\n"NOR,
HIW"      $N手中結印，地面突然浮現巨大八卦之陣，由陣心向外擴散一鼓強大的重力 \n"NOR,
HIW"      $N揮動手中超級法寶盤古幡，天頂居然顯現四相圖，使得四中空氣劇烈無比\n"NOR,

});

int again(object me,object target);
int cast(object me,object target)
{
        int i, dam, dam1, j;
        object *all = me->query_enemy();
        object who = this_player();
        object weapon = me->query_temp("weapon");
        if(!me->query("quest/taoist_one",1))
          return notify_fail("你並不會此咒術啊!!\n");
        if(me->is_busy()) 
          return notify_fail("你現在無法唸咒!!\n");
        if(!me->is_fighting())
          return notify_fail("重力倍增只能在戰鬥中使用。\n");
        if(me->query_temp("use_gravity"))
          return notify_fail("你的重力倍增之術已經施放, 無法再度施放!!\n");
        if( me->query("family/family_name") != "天道派")
          return notify_fail("閣下不是術士是不能使用的！！\n");
        if(me->query("class") != "taoist")
          return notify_fail("這法術只有道士用的出來！！\n");
        if(!weapon || weapon->query("id") != "peagod-pean" ||weapon->query("real_mark")!=1)
          return notify_fail("使用此法術需要裝備使用盤古幡才可以!!\n");
        if(me->query("atman") < 500)
          return notify_fail("你的靈力不足。\n");
        if(me->query("mana") < 500)
          return notify_fail("你的法力不足。\n");
//****************************************************************************//
        count = 0;
        me->add("atman",-300);
        me->add("mana",-300);   
        message_vision(
    HIR"        $N大喊 - 通天法寶盤古幡啊!!讓世人見識看看你的力量吧!!\n

   "HIG"                $N"HIY"緊閉雙眼, 口中念念有詞, 四周突然發出巨響\n\n
   "HIW"                      ◤"HIC"驚動大地  隨我道來"HIW"◢\n\n"NOR,me);
  

        me->start_busy(random(2));
        me->start_call_out((: call_other, __FILE__, "again",me,target:),1);
        return 1;
}

int again(object me,object target)
{
  int i,action,value,n,t, damage;
  int fun = me->query("spells/gravity/level");
  object *enemy,room;
  value=fun/10+random(fun/10);
  n=value+1;
  room=environment(me);
  enemy=me->query_enemy(room);
  count ++;
  action = random(3);
        if(fun < 30)
          {t = 3;}
          else if(80<fun&&fun<30)
          {t = 2;}
          else {t =1;}
        if ((int)me->query("mana",1) < 500) 
        {
          me->delete_temp("use_gravity");
          message_vision(HIR"\n$N法力不足, 無法繼續使用重力倍增之術!!\n"NOR,me);
          return 1;
        }
        if(count> n || !me->is_fighting())
        {
          me->delete_temp("use_gravity");
          message_vision(HIR"\n$N大地在一片震動當中回歸元始, 重力倍增的效果消失了!!\n"NOR,me);
          return 1;
        }
        damage = value*100+random(500);
        if(damage > 2000) {damage = 2000;}
        me->set_temp("use_gravity",1);
        message_vision("\n"+ATTACK_MSG[action]+"\n",me);
        message_vision("                                "HIB"元"HIG"始"HIY"天"HIR"尊"HIW"˙"BYEL""HIW"盤古現世\n\n"NOR,me);
        message_vision(HIY"  忽然有股金色光芒包圍著$N,四周重力加倍了!!極其可怕重壓往四周擴散, 大地一片碎裂!!\n\n"NOR,me);
          me->add("atman",-500-random(300));
          me->add("mana",-300-random(200));
        for(i=0;i<sizeof(enemy);i++)
          {
          enemy[i]->start_busy(1);
          enemy[i]->receive_wound( "kee" ,damage);
          enemy[i]->receive_wound( "sen" ,damage/3);
          enemy[i]->receive_wound( "gin" ,damage/3);
          COMBAT_D->report_status(enemy[i]);
          }            
        if( fun < 100 )
        spell_improved ("gravity", random(100)+100);
        call_out("again",t,me);
        return 1;
}







