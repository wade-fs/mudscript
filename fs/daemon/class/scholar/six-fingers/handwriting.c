#include <ansi.h>
#include <combat.h>
inherit F_FUNCTION;
inherit SSERVER;
int fun,range,action,force_cost,k;
string *ATTACK_MSG=({
BLU + "$N手動筆書康有為之《廣藝舟雙楫》, 頗有新意, 靈動之貌急點$n。\n" + NOR,
RED + "$N手寫明朝之《永樂大典》, 體格極嚴, 楷則固定, 一股僵硬之風撲向$n。\n" + NOR,
YEL + "$N手點丹青, 字書趙佶之《瘦金體》, 獨樹一格之風, 凜然一股氣度直逼$n。\n" + NOR,
GRN + "$N規矩的臨出歐陽詢之《九成宮醴泉銘》, 用筆結字法度嚴謹, 定下$n之一舉一動。\n" + NOR,
CYN + "$N流彩書出《蘭亭集序》, 字字真情之作, 精彩動人, 意象綿延至$n全身。\n" + NOR,
HIB + "$N寫出北魏龍門石窟《魏靈藏》, 字徑兩尺, 洋洋灑灑, 有山河之勢, 直壓$n而去。\n" + NOR,
HIR + "$N身形似風, 雙手同時畫出「二爨」,《爨寶子碑》、《爨龍顏碑》, 字勢奇峭飛動、丰姿飄定, 前後之姿圍困住$n。\n" + NOR,
HIY + "$N臨募出書聖王右軍之《十七帖》, 隱含「草」的飛動馳騁之勢, 揮灑意趣一筆草如亂絮般將$n緊緊箍住。\n" + NOR,
HIG + "$N工整的寫出鐘繇之《宣示表》, 卓見有樹之勢, 一新楷書之寫意, 準確的連繫至$n胸前大穴之中。\n" + NOR,
HIC + "$N臨風點出《乙瑛碑》, 蠶頭燕尾, 由圓轉方, 每一撇、每一捺均扣準$n周身大穴。\n" + NOR,
HIC + "$N手書《玉箸篆》, 字瘦硬婉, 猶如一無形刻石重壓在$n身上, 無法掙扎。\n" + NOR,
HIW + "$N當空一書, 表現出一種莊嚴肅穆的廟堂風格, 氣勢渾穆、高遠凝重, 《西周金文》之筆勢已將$n牢牢禁制。\n" + NOR,
HIW + "$N身形突然一鈍, 手若刻碑, 隱隱若雷之聲, 赫然是失傳已久之遠古《甲骨殷契》, 筆勢籠罩$n周身大穴。\n" + NOR
});
int sp_perform(object me);//打全體，所以不用傳target
int perform(object me, object target)
{
        int six;
        object weapon;
        weapon= me->query_temp("weapon");
        fun=me->query("functions/handwriting/level");
        if(fun<=35) k=2;
        if(fun>=36&&fun<=70) k=3;
        if(fun>=71) k=4;
        range = me->query_skill("six-fingers",1)+me->query_skill("literate",1)+me->query("functions/handwriting/level")/15;
        if( range > sizeof(ATTACK_MSG) )
          range = sizeof(ATTACK_MSG);
        action = random(range);
        six = (me->query_skill("six-fingers",1))/10;
        force_cost = 30;
        if( !me->query_skill("literate") )
          return notify_fail("你的學識不足。\n");
        if( !me->is_fighting(target) )
          return notify_fail("你只能在戰鬥中使出「臨書點穴」。\n");
        if(target)
         if( target == me )
          return notify_fail("不能對付自己呀!!\n");
        if( me->query("force") < 100 )
          return notify_fail("你的內力不夠。\n");
        if(weapon&&weapon->query("skill_type")!="stabber"&&weapon->query("skill_type")!="unarmed")
          return notify_fail("'雞絲'不對喔。\n");
        if(me->query("family/family_name")!="段家")
          return notify_fail("不是段家不能用。\n");
//臨書點穴解迷後可加強功能 by bss
        if(me->query("marks/handwriting") && //解過臨書點穴
           me->query("marks/linpo-steps") && //解過凌波微步
           (me->query_skill_mapped("dodge") == "linpo-steps") && //使用凌波微步
           fun >= 100 ) //fun 100以上
           return sp_perform(me);
        if( !target )
          target = offensive_target(me);
        if(!target) return notify_fail("可能是精神錯亂的關系,你竟然找不到敵人!!\n");
        if(target->is_busy())
          return notify_fail("臨書點穴無法點正在忙亂的人\n");
        message_vision("\n"+ATTACK_MSG[action]+"\n",me,target);
        if(80>random(100))
        {
          message_vision(HIW + "$N成功\的將$n給封鎖住了!!!\n" + NOR,me,target);
          target->start_busy(k);
          if(me->query("functions/handwriting/level")>=100 && 60 > random(100)){
            target->apply_condition("blockade",3);
            message_vision(HIR + "$N施展一陽指中的點穴法﹐反手點中$n的膻中大穴。\n" + NOR,me,target);
          }
          if ( (random(10) >8 ) && me->query("force_factor",1) > 9)
          {
            message_vision(HIR + "$N見機不可失 , 急運真氣向$n狂攻而去!!!\n" + NOR,me,target);
            me->set_temp("super",1);
          }
          if(me->query_function("handwriting")<100)
          {
            function_improved("handwriting",random(800));
          }
        }
        else
        {
          message_vision("可惜$N失敗了..\n",me);
          if(me->query_function("handwriting")<100)
          {
            function_improved("handwriting",random(500));
          }
        }
        me->add("force",-force_cost);
        me->start_busy(1);
        return 1;
}
int sp_perform(object me)
{
    int level;
    int i,flag,chance,EnemyInBusy;
    object *enemy;

    level=(int)((fun-100)/10)+1;
    if(level > 4) level=4;

    enemy=me->query_enemy();
    if(sizeof(enemy) < 1)
      return notify_fail("可能是精神錯亂的關系,你竟然找不到敵人!!\n");
    if(sizeof(enemy) < level) level=sizeof(enemy);
    if(fun == 150) {
      level = sizeof(enemy);
    }
    flag=0;
    EnemyInBusy = 0;
    for(i=0;i<level;i++)
    {
      if(!enemy[i]) continue;
      if(environment(me) != environment(enemy[i])) continue;
      if(enemy[i]->is_busy()) {
        EnemyInBusy++;
        continue;
      }
      flag++;
      action=random(range);
      message_vision("\n" + HIY + "$N" + HIY + "施展" + HIC + "「凌波微步」" + HIY + "，走遍全場，對$n" + HIY + "施展臨書點穴之術。\n" + NOR,me,enemy[i]);
      message_vision(ATTACK_MSG[action]+"\n",me,enemy[i]);
      if(80>random(100) || fun == 150)
      {
        message_vision(HIW + "$N成功\的將$n給封鎖住了!!!\n" + NOR,me,enemy[i]);
        enemy[i]->start_busy(k);
        if(me->query("functions/handwriting/level")>=100 && 60 > random(100))
        {
          enemy[i]->apply_condition("blockade",3);
          message_vision(HIR + "$N施展一陽指中的點穴法﹐反手點中$n的膻中大穴。\n" + NOR,me,enemy[i]);
        }
        chance=10;
        if(fun == 150) chance=4;
        else if(fun >= 140) chance=6;
        else chance=8;
        if ( ( random(10) > chance ) && me->query("force_factor",1) > 9)
        {
          message_vision(HIR + "$N見機不可失 , 急運真氣向$n狂攻而去!!!\n" + NOR,me,enemy[i]);
          me->set_temp("super",1);
          COMBAT_D->do_attack(me,enemy[i],me->query_temp("weapon"));
        }
        if(me->query("functions/handwriting/level")<150)
        {
          function_improved("handwriting",(fun * (random(5)+1)) + random(1000));
        }
      }
      else
      {
        message_vision("可惜$N失敗了..\n",me);
        if(me->query("functions/handwriting/level")<150)
        {
          function_improved("handwriting",random(1000));
        }
      }
    }
    if(!flag) {
      if (EnemyInBusy) {
        return notify_fail("敵人無法動彈，趕快攻擊啊!!\n");
      }
      else {
        return notify_fail("可能是精神錯亂的關系,你竟然找不到敵人!!\n");
      }
    }
    else
    {
      me->add("force",-(30*flag));
      if (fun < 150 || me->query("marks/six-fingers")!=3 || me->query_skill("six-fingers",1) < 100) {
        me->start_busy(1);
      }
    }
    return 1;
}
