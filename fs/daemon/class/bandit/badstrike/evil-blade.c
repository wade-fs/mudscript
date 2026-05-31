//調整強度及增加天魔霸刀 by frequency 2004 Sep
//將receive_wound的攻擊參數補上攻擊方之參數 by blazakira 2011/7/2

#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;

int perform(object me, object target)
{
  int skill, level, bellpower, force, damage, i, j, blade, level2;
  object *enemy, wea1;
  blade = me->query_skill("unarmed");
  skill = me->query("functions/evil-blade/level");
  level = skill / 30;
  if(level > 3) level = 3;
  level2 = random(level);
  bellpower = me->query("bellicosity")/20;
  if(bellpower > 300) //by chan fix 
    bellpower=300;
  force = me->query("force");
  enemy = me->query_enemy();
  i = sizeof(enemy);
  j = i;
  target = offensive_target(me);
  wea1 = me->query_temp("weapon");
  if(me->query("family/family_name")!="惡人谷")
    return notify_fail("你不是惡人谷的，所以不能用。\n");
  if( me->query_skill_mapped("force")!="badforce" || 
      me->query_skill_mapped("unarmed")!="badstrike" || 
     (wea1 && wea1->query("skill_type")!="unarmed") )
    return notify_fail("只有在空手使用惡霸掌及惡化魔功\時才能發出天魔刀。\n");
  if( me->query_skill("badstrike",1)<20 )
    return notify_fail("你的惡霸掌技巧不足。\n");
  if( me->query_skill("badforce",1)<20 )
    return notify_fail("你的內功\不夠深厚，無法聚氣成刀。\n");
  if( force<90 ) return notify_fail("你的內力不足以聚起天魔刀芒。\n");
  if( !me->is_fighting(target) )
    return notify_fail("天魔刀只能在戰鬥中使用。\n");

  if( !target || !me->query_enemy()) return notify_fail("你現在並沒有交戰對象可打。\n");
  if( level2 == 2 && me->query_skill("ghost-steps",1)<50 ) level=1;
  switch( level2 )
  {
    case 0:
      message_vision(HIW"\t$N"HIW"將內勁聚於雙掌，祭起十成功\力之『"+HIR"天魔刀"+HIW"』！\n\n\t只見$N"HIW"掌中逐漸形成兩個耀眼刀環，倏地向$n"HIW"疾射而去！\n\n"NOR,me,target);
      me->add("force", -50);
      if ( 80<random(100) )
      {
        message_vision(HIM"只見$N"HIM"刀勢雖猛，但似乎欠缺準頭，連$n"HIM"的衣服都沒沾到。\n"NOR,me,target);
        me->start_busy(1);
        return 1;
      }
      damage = skill*5+bellpower;
      target->receive_wound("kee", damage, me);
      message_vision(HIC"$n"HIC"閃避不及，被$N"HIC"的天魔刀芒貫體而過，當場血流如注！\n"NOR,me,target);
      me->start_busy(1);
      break;
    case 1:
      message_vision(HIW"\t$N"HIW"雙掌合十，高舉過頂，順勢運起『"+HIR"大天魔刀"+HIW"』\n\n\t只見$N"HIW"雙掌的天魔刀勁合而為一，形成一個巨大刀環。\n\n\t突然間$N"HIW"真氣一提，舉起大天魔刀向$n"HIW"直劈而下！\n\n"NOR,me,target);
      me->add("force", -65);
      if( 80<random(100) )
      {
        message_vision(HIM"只見$N"HIM"刀勢雖猛，但似乎欠缺準頭，連$n"HIM"的衣服都沒沾到。\n"NOR,me,target);
        me->start_busy(1);
        return 1;
      }
      damage = skill*7+bellpower;
      target->receive_wound("kee", damage, me);
      message_vision(HIC"$n"HIC"閃避不及，被$N"HIC"的巨大刀環當場擊中，口中鮮血狂噴而出！\n"NOR,me,target);
      me->start_busy(1);
      break;
    case 2:
      message_vision(HIW"\t$N"HIW"身形一變，施展出幽冥身法幻化為四個分身，將$n"HIW"團團圍住。\n\n\t只見$N"HIW"四個身形同時聚起連串天魔刀，準備使出惡霸掌中最強一式\n\n\t\t\t『"+HIR"天魔亂舞"+HIW"』\n\n\t霎時間$N"HIW"八掌齊發，滿天刀芒向四周狂射而出！\n\n\n"NOR,me,target);
      me->add("force", -90);
      damage = skill*7+bellpower;
      while(i--) {
        if(!enemy[i]) continue;
        if (80>random(100))
        {
          enemy[i]->receive_wound("kee", damage, me);
          message_vision(HIC"$N"HIC"一個失守，只好照單全收，霎時間刀芒如雨點般落在$N"HIC"身上！\n"NOR,enemy[i]);
        } else {
          message_vision(HIM"只見$N"HIM"狼狽的從漫天刀網中鑽了出來，不過倒是沒受什麼傷。\n"NOR,enemy[i]);
        }
      }
      me->start_busy(1);
      break;
  }
  if(level2 > 0 && me->query("combat_exp") > 2*random(target->query("combat_exp")) && me->query("combat_exp") > 900000)
  {
    message_vision(HIR"\n\t強招過後，$N目露兇光，瘋狂鬥心復又引發出神阻殺神、佛阻殺佛的滅世極招：



"HIC"     ═══╦═══  "HIB" ╭═══╩═══╯"HIM"  ╰═══╦═══╯ "YEL"╰══╦════╮
"HIC"           ║        "HIB" ║ ╦╬╦  ╦╬╦ "HIM"  ╭═╦═╬═╦═╮ "YEL"      ║        ║
"HIC"   ════╬════"HIB" ║ ╭╯═╦══╮ "HIM"  ═╬═╬═╭══╮ "YEL"      ║        ║ 
"HIC"         ╭╯╮      "HIB" ║ ╠══╬══╣ "HIM"  ╰═╦═╯╠══╣ "YEL"      ║        ║
"HIC"       ╭╯  ╰╮    "HIB" ║ ╰══╬══╯ "HIM"  ══╬══╠══╣ "YEL"    ╭╯        ║
"HIC"   ╰═╯      ╰═╯"HIB" ╯ ╰══╯══╝ "HIM"      ║    ╯    ╯ "YEL"╰═╯      ╰═╯
               \n\n"NOR,me);

    me->add("force", -150);
    damage = blade*6 + bellpower;
    while(j--) {
      if(!enemy[j]) continue;
      if (50>random(100) || target->is_busy())
      {
        enemy[j]->receive_wound("kee", damage, me);
        message_vision(HIG"無悔刀勢赫然貫穿了$N的護體罡\氣，在身後留下一道長長血痕。\n"NOR,enemy[j]);
      } else {
        message_vision(HIW"$N完全被狂霸的刀勢所鎮攝住，動彈不得。\n"NOR,enemy[j]);
        enemy[j]->start_busy(random(2)+1);
      }
      COMBAT_D->report_status(enemy[j]);
    }
    me->start_busy(1);
  }else{COMBAT_D->report_status(target);}
                   
  if (me->query("functions/evil-blade/level") < 130) {
    function_improved("evil-blade",random(700));
  }
  return 1;
}

