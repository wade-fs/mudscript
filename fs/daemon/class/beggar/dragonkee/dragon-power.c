inherit F_FUNCTION;
inherit SSERVER;
#include <ansi.h>
#include <combat.h>
#include "/open/open.h" 


string *ATTACK_MSG=({
BLU + "$N雙手成拱, 武儒辰興, 正為降龍護身氣勁之 ---- \n" + NOR,
RED + "$N手劃八卦, 氣滿池田, 莫央二穴, 轉身一道降龍護身氣勁之 ---- \n" + NOR,
HIR + "$N身形似風, 一手一道真武劃風, 正是降龍護身氣勁中之---- 。\n" + NOR,
HIG + "$N一道真氣自掌中游出, 氣勁之逼$n, 口中喊道降龍護身氣勁中之 ---- 。\n" + NOR,
});

int count;
int again(object me);
int perform(object me,object target)
{
        int i, dam, dam1, j;
        object *all = me->query_enemy();
        object who = this_player();
        count=0;
        if(me->is_busy()) 
        return notify_fail("你現在無法使用降龍真氣!!\n");
        if(!me->is_fighting())
        return notify_fail("降龍真氣只能在戰鬥中使用。\n");
        if(me->query_temp("dragon_kee"))
        return notify_fail("你正運起降龍護身真氣, 此時是不可以運起的!!\n");
        if( me->query("family/family_name") != "丐幫")
        return notify_fail("你不是丐幫不能用喔！！^_^\n");
        me->add("force",-500);
        me->start_busy(1);
        call_out("again",4,me);
        return 1;
}


int again(object me)
{
        int i,range,action;
        int fun=me->query("functions/dragon-kee/level");
        int n=fun/10;
        object *all = me->query_enemy();
        count ++;
        range = me->query("functions/dragon-kee/level")/10;
        if( range > sizeof(ATTACK_MSG) )
        range = sizeof(ATTACK_MSG);
        action = random(range);

        if(count>n) 
        {
          me->delete_temp("dragon_kee");
          return 1;
        }

        me->set_temp("dragon_kee",1);
        message_vision("\n"+ATTACK_MSG[action]+"\n",me);
            for(i=0;i<sizeof(all);i++)
            {
                if(random(100) <40)
                {
                  message_vision(HIR + "『狂龍舞蒼天』 ---- 氣勁打在$n身上, 讓$n狂痛不已" + NOR,me,all[i] );
                  all[i]->receive_wound( "kee" ,300);
                  all[i]->receive_damage("sen",fun*3+50,me);
                  all[i]->receive_damage("gin",fun*3+50,me);
                  COMBAT_D->report_status( all[i] );
                 function_improved("dragon-power",random(100));
                } 
                else  if(41<= random(100) <60)
                {
                  message_vision(HIY + "『真龍昇破天』 ---- 氣勁封鎖注$n的行動了!!!" + NOR,me,all[i] );
                 me->start_busy(1);
                 function_improved("dragon-power",random(100));
                }
                else if(61<=random(100) <70)
                {
                 message_vision(HIC + "『血龍斥片天』 ---- 降龍氣勁打亂了$n的氣脈運行!!!" + NOR,me,all[i] );
                  all[i]->add("force",-1000);
                 function_improved("dragon-power",random(100));
                }
                else 
                {               
                message_vision( HIY + "『青龍躍碧天』 ---- 轉身一跳, 避開了降龍氣勁﹗" + NOR , me ,all[i] );
                 function_improved("dragon-power",random(30));
                }
            }
            call_out("again",4,me);
        return 1;
}




