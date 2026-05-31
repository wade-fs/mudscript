// 射手末日驚天 by Alucard 2009/Sep
//將receive_wound的攻擊參數補上攻擊方之參數 by blazakira 2011/7/19

#include <ansi.h>
#include <enemy_def.h>
inherit SSERVER;
inherit F_FUNCTION;

int perform(object me, object target)
{
  int k,hurt,skill,level,fforce,iforce,gin,sen,kee,time,num;
  string att_w,att_e,arrow;
  object ob,wp;

  skill=me->query_skill("archery");
  fforce=me->query_skill("fireforce",1);
  iforce=me->query_skill("iceforce",1);
  level=me->query("functions/break-sun/level");
  wp = me->query_temp("weapon");

  if(me->query("class")!="marksman"&&me->query("id")!="alucard") return notify_fail("你的職業無法使用此技能。\n");
  if( !me->is_fighting() ) return notify_fail("破日驚天只能在戰鬥中使用。\n");
  if(!target) target = offensive_target(me);
  att_e = define_enemy(target);
  if(!wp || (string)wp->query("skill_type")!="archery") return notify_fail("要裝備弓才能用吧。\n");
  num = wp->query("arrow/amount");
  if(num<100) return notify_fail("你弓上的箭枝太少，無法使出此招。\n");
  if( skill < 165 ) return notify_fail("你的箭技不夠出色。\n"); 
  if (me->query_skill_mapped("archery")!="god-shooting") return notify_fail("不用流星箭訣怎發動破日驚天?\n");
  if(!target) return notify_fail("你目前沒有敵人!!\n");
  if( target == me ) return notify_fail("你想自宮嗎!?\n");
  if( me->query("force") < 1500) return notify_fail("你的內力不夠。\n");
  if(!me->query("break-sun")) return notify_fail("你還不會操縱五行之氣。\n");
  att_w = wp->query("arrow/attr");
  if(!att_w) return notify_fail("你所使用的箭無法發揮破日驚天威力。\n");
  arrow = wp->query("arrow/name");
  if(!iforce) iforce=0; 
  if(!fforce) fforce=0;
  if(random(level)>94 || (level>94 && wizardp(me)) || me->query("break-sun")>1) //最大招發動機率，在fun練滿時為0.5%
  {
    message_vision(HIW"\n$N將"HIR"極火功\"HIW"與"HIC"冰心訣"HIW"同時谷摧至極限，縱聲高喊：\n\n
  
  \t\t\t「"HIR"天火焚身"HIW"～"HIC"玄冰滅世"HIW"～"HIM"弓神附體"HIW"～"HIY"箭嵐再現"HIW"～」\n
                      
  "HIM"箭神"HIG"后羿"HIW"的身影依稀出現在$N身後，$n以為眼花，揉揉雙眼，再睜開時，滿天箭矢已飛至面前!!\n\n"NOR,me,target);
    time = 2+(level-95);
    skill=me->query_skill("archery",1);
    hurt = 2*(skill*5+fforce+iforce+level*3);
    /*以下為一般mob之傷害計算
    標準archery 120以及fireforce iceforce 231之ppl，最大可打到14*(231+231+600+300)=19068
    若將fireforce iceforce學到277  archery練到400   最大可打到7*2*(277+277+2000+300)=39956*/
    if((!target->query_temp("no_die_soon") && !target->query_temp("no_badroar_max") && !target->query_temp("todie")) || userp(target))
    for(k=0;k<time;k++)
    {
      message_vision(HIY"融合"HIW"冰"HIR"火"HIY"兩極神功\的無匹箭氣，瞬間貫穿了$n的身體!!\n"NOR,me,target);
      target->receive_wound("kee",hurt,me);  
    } else {//以下為不云許dieup、maxbadroar之非玩家敵人傷害計算 打30%
      gin = 3*target->query("max_gin")/70;
      kee = 3*target->query("max_kee")/70;
      sen = 3*target->query("max_sen")/70;
      for(k=0;k<7;k++)
      {
        message_vision(HIY"融合"HIW"冰"HIR"火"HIY"兩極神功\的無匹箭氣，瞬間貫破$n的身體!!\n"NOR,me,target);
        target->receive_wound("gin",gin,me);
        target->receive_wound("kee",kee,me);
        target->receive_wound("sen",sen,me);
      }
      if(userp(me)) me->set("force",me->query("force")/3);
    }
    COMBAT_D->report_status(target);
    if(num<1052)
      num = num/20;
    else num = num-1000;
    if(userp(me)) wp->set("arrow/amount",num);
  }
  else if(random(skill) < 24)
  {
    message_vision(HIB"\n$N嚐試發動箭雨，但箭技不夠熟練，以致於天地靈氣潰散四逸。\n"NOR,me);
    num = num-10;
    wp->set("arrow/amount",num);
  }
  else
  {
    hurt = 20*skill;
    message_vision(CYN"\n$N高喊："HIW"「"HIY"箭雨！"HIW"」
"+arrow+CYN"直指$n"CYN"，這招正是"HIM"箭神"HIG"后羿"CYN"的傳說奧義\n\n
                        "HIM"《"HBYEL""HIB"破"NOR"～"HBBLU""HIY"日"NOR"～"HBGRN""HIW"驚"NOR"～"BRED""HIC"天"NOR"～"HIM"》\n\n
  "CYN"箭頭未至，箭勁已如巨浪般席捲而至。\n\n"NOR,me,target);

    if(att_w == "fire")
    {
      if(att_e == "gold" && level > 60) 
      {
        message_vision(HIR"箭上強烈的焰氣摜破了$n的氣海，$n感到氣血翻騰，五內俱焚!!\n"NOR,me,target);
        hurt = 3*hurt;
        hurt = hurt/2;
      } else message_vision(HIR"箭上強烈的焰氣燒灼著$n的身體，$n感到氣血翻騰，炙熱難當!!\n"NOR,me,target);
      if(49<random(level)) target->apply_condition("burn",2+random(level/25));
    }

    if(att_w == "gold")
    {
      if(att_e == "wood" && level > 60) 
      {
        message_vision(HIY"高硬度的銳利箭頭摜破了$n的氣海，$n感到氣血翻騰，腹痛如絞!!\n"NOR,me,target);
        hurt = 3*hurt;
        hurt = hurt/2;
      } else message_vision(HIY"高硬度的銳利箭頭在$n身上劃出無數割痕，$n頓時遍體鱗傷，!!\n"NOR,me,target);
      if(49<random(level)) target->apply_condition("bleeding",2+random(level/25));
    }

    if(att_w == "wood")
    {
      if(att_e == "soil" && level > 60) 
      {
        message_vision(HIG"箭上木靈彷彿得到生命般鑽入$n的氣海，吸收了$n的內勁，接著破體而出!!\n"NOR,me,target);
        hurt = 3*hurt;
        hurt = hurt/2;
      } else message_vision(HIG"箭上木靈彷彿得到生命般鑽入$n的氣海，吸收了內勁，$n感到一陣噁心。!!\n"NOR,me,target);
    }

    if(att_w == "soil")
    {
      if(att_e == "water" && level > 60) 
      {
        message_vision(YEL"$n感到渾厚氣牆隨著箭頭襲來，運勁強抗卻如入泥沼，接著被氣牆重重轟中!!\n"NOR,me,target);
        hurt = 3*hurt;
        hurt = hurt/2;
      } else message_vision(YEL"$n感到渾厚氣牆隨著箭頭襲來，難以抵擋，被撞個正著!!\n"NOR,me,target);
    }

    if(att_w == "water")
    {
      if(att_e == "fire" && level > 60) 
      {
        message_vision(HIW"箭頭挾帶的水氣驟轉為強烈凍氣，$n的內勁有如受到冰封，頓時暈頭轉向!!\n"NOR,me,target);
        hurt = 3*hurt;
        hurt = hurt/2;
      } else message_vision(HIW"箭頭挾帶的水氣驟轉為強烈凍氣，$n頓時全身發抖，臉色發白!!\n"NOR,me,target);
      if(49<random(level)) target->apply_condition("cold",2+random(level/25));
    }
    if(random(level) > 69)
    {
      message_vision(HIB"箭上竟塗有失傳秘藥「蒙汗」，$n頓時內息滯空!!\n"NOR,me,target);   
      target->apply_condition("block_sweat",2+random(level/20));
    }
    target->receive_wound("kee",hurt,me);
    COMBAT_D->report_status(target);
    me->set("force",me->query("force")*3/4);
    num = num-10;
    wp->set("arrow/amount",num);
  }
  me->start_busy(1);
  if(wizardp(me)) write("damage is"+hurt+"\n");
  if( level < 100 ) function_improved ("break-sun",100);
  return 1;
}
