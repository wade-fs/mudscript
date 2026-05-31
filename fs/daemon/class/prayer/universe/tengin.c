// 天驚地動 by xman
// 配合universe裡的sp1到sp5所寫,目的是用來決定發哪一招以及威力多大
// 等級越高越高,能用的招數越多,傷害越大(而且大很多:p)
#include <combat.h>
#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
inherit F_CLEAN_UP;
void tengin(object me, object target);
int perform(object me, object target)
{
        int lv,a,damage;
        lv = me->query("functions/tengin/level",1);
		if(me->query("class")!="prayer")
          return notify_fail("你的職業無法使用此技能。\n");
        if( !me->query("marks/tengin"))
          return notify_fail("你妄催功\力, 試圖凝聚天地之氣, 可是什麼事情也沒發生。\n");
        if( me->query_skill("universe",1)<120 )
          return notify_fail("你的先天乾坤功\還只有幼稚園的程度。\n");
        if( me->query("force")<500 )
          return notify_fail("你的內力不足, 無法凝聚天地之氣。\n");
        if( !target )
          target = offensive_target(me);
        if( !me->is_fighting(target) )
          return notify_fail("天驚地動只能在戰鬥中使用。\n");
        if(!target) return notify_fail("你找不到敵人!!\n");
        message_vision(HIY"

                突然之間, 地面發生強大的地震, 震力強猛, 所有的人
                被震得東歪西倒, 只見$N手指天地, 使出"HIW"

                    『先天乾坤功\』"HIR"
                                    第七絕"HIW"
                                            『"HIC"天"HIG"驚"NOR+YEL"地"HIB"動"HIW"』"HIY"

                此招乃引動九天之威與九地之氣結合而成, 甫一施展, 
                四周旋風亂捲, 嶽動山搖, 施展者身形如陀螺急速旋轉
                乾坤陰陽卦象隱然而出, 勁風凜冽, 氣勁急劇遞增, 仿
                如巨龍狂舞, 將四周的漩渦氣流不斷地聚集擴大!!"NOR"\n\n",me,target);

  damage = 300+lv*20;
  if(80 > random(100))
        {
          me->set_temp("tengin",me->query("env/天驚地動"));
          me->set_temp("tengin_power",damage);
          target->start_busy(1);
          message_vision(HIW"\n
                不久, 九天之氣從天上疾旋而下, 九地之氣從地面飛舞
                而上, 兩股漩渦氣流交接, 匯流成磅礡無比的氣勢!!"NOR"\n\n",me,target);
        }
        else
        {
          message_vision(HIR"\n
                $N無法控制源源不絕的天地之氣在體內狂竄, 只好強行
                收功\, 然而身體已受了嚴重的內傷!!"NOR"\n\n",me,target);
        }
        me->start_busy(1);
        if( lv < 100 )
        function_improved("tengin",random(500));
        return 1;
}

