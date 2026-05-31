// 增加幻靈七訣針 by Inwish   2001/04/08
// 增加靈轉絕情針 by Inwish   2001/10/06
// 本為god的技能 此調整為小mob使用的威力 by blazakira 2010/05/08

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void create() { seteuid(getuid()); }

void sp1(object me, object victim, object weapon, int damage);
void sp2(object me, object victim, object weapon, int damage);
void sp3(object me, object victim, object weapon, int damage);
void sp4(object me, object victim, object weapon, int damage);
void sp5(object me, object victim, object weapon, int damage);
void sp6(object me, object victim, object weapon, int damage);
void sp7(object me, object victim, object weapon, int damage);
void sp8(object me, object victim, object weapon, int damage);
void sp9(object me, object victim, object weapon, int damage);
void sp10(object me, object victim, object weapon, int damage);
void sp11(object me, object victim, object weapon, int damage);
void sp12(object me, object victim, object weapon, int damage);
void seven(object me, object victim,object weapon, int damage);

mapping *action = ({
//1
  ([ "action":"$N素手一拈﹐起手式"HIR"『穿針引線』"NOR"手中$w緩緩劃出，輕輕鬆鬆向$n刺去!!",
        "dodge": -70,
        "parry": -70,
        "damage": 60,
        "force": 100,
        "damage_type":  "刺傷",
        "post_action":                (: sp1 :),
  ]),
//2
  ([ "action":"$N一招"HIC"『補補綴綴』"NOR"手中$w去勢無定﹐不知要刺向$n何處，難以捉摸!!",
        "dodge": -40,
        "parry": -15,
        "damage": 100,
        "force": 90,
        "damage_type": "刺傷",
        "post_action":                (: sp2 :),
  ]),
//3
  ([ "action":"$N舞姿嫚妙﹐舞出"HIM"『針黹黻黼』"NOR"渾身放出一股魔力，誘使$n自投羅網!!",
        "dodge": -40,
        "parry": -40,
        "damage": 80,
        "force":  100,
        "damage_type":  "刺傷",
        "post_action":                (: sp3 :),
  ]),
//4
  ([ "action":"$N窺準一個空隙，使出"HIC"『風起雲湧刺』"NOR"激起風雷之聲向$n$l全力刺去!!",
        "dodge": -50,
        "parry": -30,
        "damage": 90,
        "force": 150,
        "damage_type": "刺傷",
        "post_action":                (: sp4 :),
  ]),
//5
  ([ "action":"$N面帶媚笑，使出"HIB"『針繡鴦鴦雙相依』"NOR"一針一線溫柔的朝$n遍身縫去!!",
        "dodge": -35,
        "parry": -20,
        "damage": 90,
        "force": 120,
        "damage_type": "刺傷",
        "post_action":                (: sp5 :),
  ]),
//6
  ([ "action":"$N率意而施, 一招"HIR"『潑墨一葦織』"NOR"射出了千百道針氣欲將$n罩於其下!!",
        "dodge": -50,
        "parry": -30,
        "damage": 95,
        "force": 120,
        "damage_type": "刺傷",
        "post_action":                (: sp6 :),
  ]),
//7
  ([ "action":"$N憶起傷心往事﹐以情御"HIM"『寫意粗石針』"NOR"以必死的氣勢向$n快速衝去!!",
        "dodge": -30,
        "parry": -20,
        "damage": 95,
        "force":  130,
        "damage_type":  "刺傷",
        "post_action":                (: sp7 :),
  ]),
//8
  ([ "action":"$N提氣輕身，"HIR"『急針亂穿線』"NOR"，織出一片漫天針網，緊緊地將$n裹住!!",
        "dodge": -50,
        "parry": -20,
        "damage": 95,
        "force": 160,
        "damage_type":  "刺傷",
        "post_action":                (: sp8 :),
  ]),
//9
  ([ "action":"$N內勁流轉﹐"HIC"『密刺亂雨繡』"NOR"，一時漫天針影，針氣濔漫不住地往$n逼攻而去!!",
        "dodge": -30,
        "parry": -20,
        "damage": 95,
        "force": 160,
        "damage_type":  "刺傷",
        "post_action":                (: sp9 :),
  ]),
//10
  ([ "action":"$N身形一緩，"HIB"『慧針續斷情』"NOR"，全身不帶一絲殺意，柔柔地朝$n飄去!!",
        "dodge": -50,
        "parry": -70,
        "damage": 95,
        "force": 160,
        "damage_type":  "刺傷",
        "post_action":                (: sp10 :),
  ]),
//11
  ([ "action":"$N內勁流轉，狂亂技"HIM"『神針亂繡』"NOR"，化為千萬，氣勁漫空揮灑全往$n直攻而去!!",
        "parry": -70,
        "damage": 150,
        "dodge": -70,
        "force": 150,
        "damage_type":  "刺傷",
        "post_action" :  (: sp11 :),
  ]),
//12
  ([ "action":HIC"$N身形急轉，針法隨身形愈使愈快，"HIM"『 "HBRED+HIY"～靈 轉 絕 情 針～"NOR+HIM" 』"HIC"在靈氣和針法相互配合下向$n"HIC"急刺而去!!"NOR,
        "parry": -70,
        "damage": 150,
        "dodge": -90,
        "force": 200,
        "damage_type":  "刺傷",
        "post_action" :  (: sp12 :),
  ]),
//13
  ([ "action":HIC"$N"HIC"靈氣流轉，靈力不斷升高之際，一招"HIW"『 ～ "HIY"幻"HIM"靈"HIC"七"HIG"訣"HIR"針"HIW" ～ 』"HIC"揚手而起，一時靈光四起!!"NOR,
        "parry": -70,
        "damage": 120,
        "dodge": -90,
        "force": 250,
        "damage_type":  "刺傷",
        "post_action" :  (: seven :),
  ]),
});

void sp1(object me, object victim, object weapon, int damage)
{
  object ob;
  int magic,stabber,exp,ena,mam,spi,fsk,tim;
//  me=this_player();
  if(!me || !victim) return;
  magic = (int)(me->query_skill("magic")); //假設為100
  stabber = (int)(me->query_skill("stabber")); //假設為100
  tim = (int)(me->query_function("fight")/10);
//假設為100/10=10 //暫以修羅鬥氣(fight)替代

//  me->add("mapower",random(2)+1); //功能不明 暫取消
  if( !ob = present("puppet",me)  )
  {
    if ( damage = 0 ) 
    {
      message_vision("$N一擊不中,順勢一個側身跨步, 閃到$n身側, 反手併指成錐, 一個鶴嘴狠狠啄中$n心窩 !\n", me,victim);
      victim->receive_wound("kee",stabber,me); //dam=100
      COMBAT_D->report_status(victim,1);
    } else {
      message_vision("$N一擊得手, 趁$n心神不定之時, 悄悄暗施如絲"HIC"斷續勁"NOR"牽制$n的動作!!\n", me, victim);
      victim->start_busy(random(2)+1);
    }   
  } else {
    message_vision(HIM"魔偶娃娃"NOR"受$N靈力驅動, 飛離而出, 直奔$n身前, 一口咬向$n頸側, 嚇的$n魂飛魄散 !\n", me,victim);
    victim->receive_wound("kee",magic*tim,me); //dam=1000
    victim->receive_wound("gin",magic,me); //dam=100
    victim->receive_wound("sen",magic,me); //dam=100
    COMBAT_D->report_status(victim,1);
    victim->start_busy(random(2)+1);
  }
}

void sp2(object me, object victim, object weapon, int damage)
{
  int magic,stabber,exp,ena,mam,spi,fsk,tim;
//  me=this_player();
  if(!me || !victim) return;
  stabber = (int)(me->query_skill("stabber")); //假設為100
  tim = (int)(me->query_function("fight")/10); //假設為100/10=10 //暫以修羅鬥氣(fight)替代

//  me->add("mapower",random(2)+1); //功能不明 暫取消
  if (me->query("combat_exp") > random(1200000) && damage = 0 ) 
  {
    message_vision("$n被$N如雨般的攻勢所惑, 楞了一楞, $N到見機不可失, 順勢再加一擊 !\n", me,victim); 
    victim->receive_damage("kee", stabber*tim); //dam=1000
    COMBAT_D->report_status(victim);
  }
}

void sp3(object me, object victim, object weapon, int damage)
{
  int magic,stabber,exp,ena,mam,spi,fsk,tim;
//  me=this_player();
  if(!me || !victim) return;
  stabber = (int)(me->query_skill("stabber")); //假設為100
  tim = (int)(me->query_function("fight")/10); //假設為100/10=10 //暫以修羅鬥氣(fight)替代

//  me->add("mapower",random(2)+1); //功能不明 暫取消
  if (me->query("combat_exp") > random(1200000) && damage = 0 ) 
  {
    message_vision("$N暗使迴勁將手中武器射出, 噗的一聲在$n身上刺出了一個血肉模糊的血窟窿 !\n",me,victim);
    victim->receive_damage("kee", stabber*tim); //dam=1000
    COMBAT_D->report_status(victim);
  } else {
    message_vision("$N暗使迴勁將手中武器射出, 可惜被$n發現, 閃了過去, 只輕輕的劃過皮肉!!\n",me,victim);
    victim->receive_damage("kee", stabber); //dam=100
    COMBAT_D->report_status(victim);
  }
}

void sp4(object me, object victim, object weapon, int damage)
{
  int magic,stabber,exp,ena,mam,spi,fsk,tim;
//  me=this_player();
  if(!me || !victim) return;
  mam = (int)(me->query_skill("dremagic")); //假設為100 //暫以dremagic替代
  spi = (int)(me->query("spi")); //假設為35
  tim = (int)(me->query_function("fight")/10); //假設為100/10=10
//暫以修羅鬥氣(fight)替代

//  me->add("mapower",random(2)+1); //功能不明 暫取消
  if(me->query_temp("fire_tooth") == 1 || me->query_temp("ma-needle") == 1)
  {
    if( random(mam) > random(100) )
    {
      message_vision(HIG"$N手中"+weapon->name()+""HIG"感受到$N的靈性與法力, 不住震動, 忽然泛閃紅光, 自$N手上如電脫手飛向天際\n"NOR,me,victim);
      message_vision(HIY"$N的"+weapon->name()+""HIY"吸蝕了$N的精血, 喚醒隱伏其中的龍魂, 只見東方飛來一頭巨獸, 振翅聲有如雷響 !\n"NOR,me,victim);
      message_vision(HIG"$N竟喚來了隱伏於極東的龍王"HIY"ㄧ"HIG"吐出來自宇宙的巨燄"HIR""HIW"欲消滅眼前一切 !\n"NOR,me,victim);
      victim->receive_wound("kee",3000,me); 
      victim->apply_condition("burn",random(tim)+10);
      COMBAT_D->report_status(victim,1);
    } else {
      message_vision(HIR"$N手中"+weapon->name()+""HIR"吸蝕了$N的精血, 喚醒了隱伏其中的龍魂, 登時風雲變色, 火龍再現!\n"NOR,me,victim); 
      message_vision(HIR"甦醒的火龍狂性大發, 不住向四方噴火, 燒燬了每一件物, 焦臭味四起, 令人作嘔 !\n"NOR,me,victim);
      victim->receive_wound("kee",tim*(5*spi),me); //dam=10*10*35=3500 改為10*5*35=1750
      victim->apply_condition("burn",random(tim)+5);
      COMBAT_D->report_status(victim,1);
    }
  } else {
    message_vision("$n被$N手中發出的風雷之聲所攝, 獃立當地, 完全不曉閃避, 被$N趁機急速一擊命中 !\n",me,victim);
    victim->apply_condition("burn",random(2)+3);
    victim->receive_wound("kee",tim*(2*spi),me); //dam=10*5*35=1750 改為10*2*35=700
    COMBAT_D->report_status(victim,1);
  }
}

void sp5(object me, object victim, object weapon, int damage)
{
  int magic,stabber,exp,ena,mam,spi,fsk,tim;
//  me=this_player();
  if(!me || !victim) return;
  magic = (int)(me->query_skill("magic")); //假設為100
  mam = (int)(me->query_skill("dremagic")); //假設為100 //暫以dremagic替代
  tim = (int)(me->query_function("fight")/10); //假設為100/10=10

//  me->add("mapower",random(3)+1); //功能不明 暫取消
  if(me->query_temp("ma-needle") == 1)
  {
    if ( random(mam) > random(40) )
    {
      message_vision(HIC"$N將自身的靈力法力注入"+weapon->name()+""HIC", 奉獻給天神, 請求水神宓妃現身幫助 !!\n"NOR,me,victim);
      message_vision(HIB"空氣間忽然無端端起了個漩渦, 將$n深陷於中, 轉得昏頭轉向,不知東南西北 !\n"NOR,me,victim);
      victim->start_busy(3);
      victim->receive_damage("sen",magic); //dam=100
      victim->receive_damage("gin",magic); //dam=100
      victim->receive_damage("kee",tim*magic); //dam=1000
      COMBAT_D->report_status(victim);
    } else {
      message_vision(""+weapon->name()+""NOR"受到$N內力激發, 泛出了一片淡藍色的"HIB"情霧"NOR"遮斷了$n的五覺 !\n",me,victim);
      victim->start_busy(2);
    }
  } else {
    message_vision("$N以無限的情意圍繞著$n, 看來$n已深深的沉醉在其中了!!\n",me,victim);
    victim->start_busy(1);
  }
}

void sp6(object me, object victim, object weapon, int damage)
{
  int magic,stabber,exp,ena,mam,spi,fsk,tim;
//  me=this_player();
  if(!me || !victim) return;
  mam = (int)(me->query_skill("dremagic")); //假設為100 //暫以dremagic替代
  fsk = (int)(me->query_skill("force")); //假設為400
  tim = (int)(me->query_function("fight")/10); //假設為100/10=10 //暫以修羅鬥氣(fight)替代

//  me->add("mapower",random(3)+1); //功能不明 暫取消
  if(me->query_temp("ma-needle") == 1)
  {
    if ( random(mam) > random(40) )
    {
       message_vision(HIC"$N手中"+weapon->name()+""HIC"受$N內力催使, 裂成千萬淡藍晶片, 飛散於空中, 氣溫急劇下降 !\n"NOR,me,victim);
       message_vision(HIC"飛散於空中的千萬晶片在$N的內力御駕下, 開始流轉成圈, 形成鑽石塵爆收縮 !\n"NOR,me,victim);
       message_vision(HIR"$n被晶片圍擊, 瞬間已被擊中數千下, 只見冰屑血沫齊飛, 連血液也凝結成冰 !\n"NOR,me,victim);
       victim->receive_wound("kee",tim*fsk,me); //dam=4000
       victim->apply_condition("freeze",random(5)+5);
       victim->start_busy(1);
       COMBAT_D->report_status(victim,1);
    } else {
      message_vision(""+weapon->name()+""NOR"感受到$N的法力, 將空氣中的水氣凝結成冰, 急速落下對$n進行攻擊 !\n",me,victim);
      victim->receive_damage("kee", fsk,me); //dam=400
      victim->apply_condition("freeze",random(3)+3);
      COMBAT_D->report_status(victim);
    }
  } else {
    message_vision("$N攻擊時帶起的勁風未消, 有如利刃般在$n身上割出了幾道約莫半尺的傷口 !\n",me,victim);
    victim->receive_damage("kee",fsk,me); //dam=400
    victim->apply_condition("freeze",random(1)+1);
    COMBAT_D->report_status(victim);
  }
}

void sp7(object me, object victim, object weapon, int damage)
{
  int magic,stabber,exp,ena,mam,spi,fsk,tim;
//  me=this_player();
  if(!me || !victim) return;
  spi = (int)(me->query("spi",1)); //假設為35
  tim = (int)(me->query_function("fight")/10); //假設為100/10=10 //暫以修羅鬥氣(fight)替代

//  me->add("mapower",random(3)+1); //功能不明 暫取消
  if (me->query("combat_exp",1) > 1000000 && random(me->query("spi",1))>15 )
  {
    message_vision("$N情緒激動難以自制, 竟不顧己身安危, 捨身全力向$n撞去 ! $n被這一撞, 吐了一口鮮血 !\n",me,victim);
    victim->receive_damage("kee",tim*(10*spi),me); //dam=10*10*35=3500
    COMBAT_D->report_status(victim);
  } else {
    message_vision("$n被$N這股勢死的氣勢所攝，目瞪口呆，傻傻的站著，完全忘了要閃躲$N的攻擊。 \n", me, victim);
    victim->receive_damage("kee",tim*(3*spi),me); //dam=10*3*35=1050
    victim->start_busy(1);
    COMBAT_D->report_status(victim);
  }
}

void sp8(object me, object victim, object weapon, int damage)
{
  int magic,stabber,exp,ena,mam,spi,fsk,tim;
//  me=this_player();
  if(!me || !victim) return;
  stabber = (int)(me->query_skill("stabber")); //假設為100
  tim = (int)(me->query_function("fight")/10); //假設為100/10=10 //暫以修羅鬥氣(fight)替代

//  me->add("mapower",random(3)+1); //功能不明 暫取消
  if(me->query_temp("ma-needle") == 1)
  {
    message_vision("$N手握"+weapon->name()+"指指點點, 凝氣成鑣, 射出"HIG"七星奪命鑣"NOR"連取$n七處要害\n",me,victim);
    message_vision("\t\t"HIC"★"HIW"≡≡≡"HIC"★"HIW"≡≡≡\n"NOR,me,victim);
    message_vision("\t      "HIC"★"HIW"≡≡≡      "HIC"★"HIW"≡≡≡\n"NOR,me,victim);
    message_vision("\t\t\t\t"HIC"★"HIW"≡≡≡"HIC"★"HIW"≡≡≡"HIC"★"HIW"≡≡≡\n"NOR,me,victim);
    message_vision("$n被氣鑣所發出耀眼的光茫所惑閃躲不及, 連被打中七下, 鮮血淋漓, 生命垂危 !\n",me,victim);
    victim->receive_wound("kee", tim*(3*stabber),me); //dam=10*3*100=3000
    COMBAT_D->report_status(victim,1);
  } else {
    message_vision(HIR"$N暗暗散出數條無形氣勁向$n飛去，偷偷的射中了$n, 造成了數個不小的瘡口！\n"NOR ,me,victim);
    victim->receive_damage("kee",tim*stabber,me); //dam=10*100=1000
    COMBAT_D->report_status(victim);
  }
}

void sp9(object me, object victim, object weapon, int damage)
{
  int magic,stabber,exp,ena,mam,spi,fsk,tim;
//  me=this_player();
  if(!me || !victim) return;
  stabber = (int)(me->query_skill("stabber")); //假設為100
  tim = (int)(me->query_function("fight")/10); //假設為100/10=10 //暫以修羅鬥氣(fight)替代

//  me->add("mapower",random(3)+1); //功能不明 暫取消
  if ((me->query("spi",1)>random(40))&&(me->query("combat_exp",1)> 1200000))
  {
    message_vision(HIW"$N密針亂繡, 有如化身成千手觀音, 在身前聚成一顆閃亮的電光球, 向$n砸去 !!\n"NOR,me,victim);
    message_vision(HIR"光球在$n面前猛然爆開, 千萬針氣化電氣在$n各處要害對穿而出 ,鮮血濺了一地!!\n"NOR,me,victim);
    victim->receive_damage("kee",tim*(3*stabber),me); //dam=10*3*100=3000
    victim->apply_condition("thunder",random(3)+3);
    COMBAT_D->report_status(victim);
  } else {
    message_vision("$N手中指指點點猶帶電勁, 以迅雷不及掩耳之速在$n正面各處柔軟要害猛力扎了一下 !!\n",me,victim);
    victim->receive_damage("kee",tim*stabber,me); //dam=10*100=1000
    victim->apply_condition("thunder",random(1)+1);
    COMBAT_D->report_status(victim);
  }
}

void sp10(object me, object victim, object weapon, int damage)
{
//  me=this_player();
  if(!me || !victim) return;
//  me->add("mapower",random(3)+1); //功能不明 暫取消
  if( me->query_per() > random(125) )
  {
    message_vision(HIB"$n被你媚惑之術中的迷魂法所惑, 氣血逆流, 失神落魄, 不知所措 !!\n"NOR,me,victim);
    victim->apply_condition("hart",random(4)+3); //走火入魔(misforce)會使內力變零 所以改內傷
    message_vision(HIW"$n一時經脈走岔因而氣血逆流, 全身內息不受控制, 四處亂竄, 已然走火入魔 !!\n"NOR,me,victim);
    victim->start_busy(2);
  } else {
    message_vision("$n被你溫柔情意所惑, 氣血逆行, 走火入魔, 猛吐了一口瘀血 !!\n",me,victim);
    victim->apply_condition("hart",random(2)+1);
    victim->start_busy(1);
  }
}

void sp11(object me, object victim, object weapon, int damage)
{
  int magic,stabber,exp,ena,mam,spi,tim;
//  me=this_player();
  if(!me || !victim) return;
  stabber = (int)(me->query_skill("stabber")); //假設為100

  if( wizardp(me) )
  {
    tell_object(me,"威力stabber現在「"HIM+stabber+NOR"」\n");
  }

//  me->add("mapower",random(3)+1); //功能不明 暫取消
  if (damage > 0)
  {
    int val;
    val = (int)(me->query_per()/2); //假設為80/2
    if (random(stabber+val) > 85 ) //假設為100+80/2
    {
      message_vision("$N素手一拈﹐起手式"HIR"『穿針引線』"NOR"手緩緩劃出，輕輕鬆鬆向$n要害刺去, 刺中$n左腿 ! \n",me,victim);
      victim->receive_wound("kee",stabber,me); //dam=100
      COMBAT_D->report_status(victim,1);
    }
    if (random(stabber+val) > 90 ) 
    {
      message_vision("$N舞姿嫚妙﹐舞出"HIM"『針黹黻黼』"NOR"渾身放出一股魔力，誘使$n自投羅網 ,撞上$N武器 !\n",me,victim);
      victim->receive_wound("kee",stabber*2,me); //dam=100*2
      COMBAT_D->report_status(victim,1);
    }
    if (random(stabber+val) > 95 ) 
    {
      message_vision("$N窺準一個空隙，使出"HIC"『風起雲湧刺』"NOR"激起風雷之聲向$n全力刺去, 命中$n右手 !\n",me,victim); 
      victim->receive_wound("kee",stabber*3,me); //dam=100*3
      COMBAT_D->report_status(victim,1);
    }
    if (random(stabber+val) > 100 ) 
    {
      message_vision("$N面帶媚笑，使出"HIB"『針繡鴦鴦雙相依』"NOR"一針一線溫柔的朝$n遍身縫去,織的$n遍體鱗傷 !\n",me,victim);
      victim->receive_wound("kee",stabber*4,me); //dam=100*4
      COMBAT_D->report_status(victim,1);
    }
    if (random(stabber+val) > 105 ) 
    {
      message_vision("$N率意而施, 一招"HIR"『潑墨一葦織』"NOR"射出了千百道針氣將$n罩於其下, 射出千百瘡口 !\n",me,victim);
      victim->receive_wound("kee",stabber*5,me); //dam=100*5
      COMBAT_D->report_status(victim,1);
    }
    if (random(stabber+val) > 110 ) 
    {
      message_vision("$N提氣輕身，"HIR"『急針亂穿線』"NOR"，織出一片漫天針網，緊緊地將$n裹住, 留下無數傷口 !\n",me,victim);
      victim->receive_wound("kee",stabber*6,me); //dam=100*6
      COMBAT_D->report_status(victim,1); 
    } 
    if (random(stabber+val) > 115 ) 
    {
      message_vision("$N內勁流轉﹐"HIC"『密刺亂雨繡』"NOR"，一時滿天針影，氣勁漫空全往$n而去, $n哀嚎不斷 !\n",me,victim);
      victim->receive_wound("kee",stabber*7,me); //dam=100*7
      COMBAT_D->report_status(victim,1);
    }
    if (random(stabber+val) > 120 ) 
    {
      message_vision("$N身形一緩，"HIB"『慧針續斷情』"NOR"，全身不帶一絲殺意，柔柔地朝$n飄去, 輕輕的傷了$n !\n",me,victim);
      victim->receive_wound("kee",stabber*8,me); //dam=100*8
      COMBAT_D->report_status(victim,1);
    }
    if (random(stabber+val) > 125 ) 
    {
      message_vision("$N身形急轉，針法隨身形愈使愈快，"HIM"『靈轉絕情針』"NOR"在靈氣和針法相互配合下向$n急刺而去!!\n",me,victim);
      victim->receive_wound("kee",stabber*9,me); //dam=100*9
      COMBAT_D->report_status(victim,1);
    }
  }
  COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}

void sp12(object me, object victim, object weapon, int damage)
{
//增加連擊訊息 by blazakira
  object *enemy;
  int i,j,pow,ext,magic,stabber,exp,ena,mam,spi,fsk,tim;
//  me=this_player();
  if(!me || !victim) return;
  magic = (int)(me->query_skill("magic")); //假設為100
  stabber = (int)(me->query_skill("stabber")); //假設為100
  exp = (int)(me->query("combat_exp")/20000); //假設為10000000/10000=1000 威力弱化1/2
  ena = (int)(me->query("mana_factor")); //假設為0 目前沒有指令能用?? //atman_factor 以enchant做取代
  mam = (int)(me->query_skill("dremagic")); //假設為100 //暫以dremagic替代
  spi = (int)(me->query("spi")); //假設為35
  fsk = (int)(me->query_skill("force")/2); //假設為400 威力弱化1/2
  tim = (int)(me->query_function("fight")/20); //假設為100/10=10 //暫以修羅鬥氣(fight)替代 //次數減少二分之一 /10 > /20
  ext = (int)(me->query("combat_exp")/1000000); //假設為10000000/1000000=10

//  me->add("mapower",random(5)+2); //功能不明 暫取消

  if( interactive(victim) )
  {
    pow=(int)(((mam+ena+exp)*tim)/80); //pow=(100+0+1000)*10/80=12+125=137
  } else {
    pow=(int)(((mam+ena+exp+stabber+spi+fsk+magic)*tim)/20); //pow=(100+0+1000+100+35+400+100)*10/10=1735 威力弱化為1035 //再除以二 從/10 -> /20
  }

  if( wizardp(me) )
  {
    tell_object(me,"威力pow現在「"HIM+pow+NOR"」\n");
  }

  enemy = me->query_enemy();
  for(i=0; i<sizeof(enemy); i++)
//此為範圍技
  {
    if( !enemy[i] ) continue;
    for( j=0; j <= tim; j++ ) //tim=10 //既然是範圍技 而且是小mob用的 次數就別那麼多了吧 或是威力別那麼強
    {
      switch(j)
      {
        case 0:
          message_vision(HBYEL"第一針 『"HIY"一朝春盡紅顏老，花落人亡兩不知"NOR+HBYEL"』。\n"NOR, me, victim);
          break;
        case 1:
          message_vision(HBYEL"第二針 『"HIY"人生愁恨何能免，銷魂獨我情何限"NOR+HBYEL"』。\n"NOR, me, victim);
          break;
        case 2:
          message_vision(HBYEL"第三針 『"HIY"山河破碎風拋絮，身世飄零雨打萍"NOR+HBYEL"』。\n"NOR, me, victim);
          break;
        case 3:
          message_vision(HBYEL"第四針 『"HIY"今夜月明人盡望，不知愁思在誰家"NOR+HBYEL"』。\n"NOR, me, victim);
          break;
        case 4:
          message_vision(HBYEL"第五針 『"HIY"世事茫茫難自料，春愁黯黯獨成眠"NOR+HBYEL"』。\n"NOR, me, victim);
          break; 
        case 5:
          message_vision(HBYEL"第六針 『"HIY"江山代有才人出，各領風騷數百年"NOR+HBYEL"』。\n"NOR, me, victim);
          break;
        case 6:
          message_vision(HBYEL"第七針 『"HIY"長久後浪推前浪，一代新人換舊人"NOR+HBYEL"』。\n"NOR, me, victim);
          break;
        case 7:
          message_vision(HBYEL"第八針 『"HIY"鬥魔無生魂"NOR+HBYEL"』。\n"NOR, me, victim);
          break;
      }
      if(enemy[i]->query("kee") > 0 && random(me->query("combat_exp")*ext) > random(enemy[i]->query("combat_exp")))
      {
        enemy[i]->receive_wound("kee",pow*(j+1),me); //max_dam=17350 威力弱化為1035*(1~10)
        enemy[i]->receive_wound("gin",pow,me); //max_dam=1735
        enemy[i]->receive_wound("sen",pow,me); //max_dam=1735
        COMBAT_D->report_status(enemy[i],1);
      } else {
        enemy[i]->receive_wound("kee",pow,me); //max_dam=1735
        enemy[i]->receive_wound("gin",(int)(pow/2),me); //max_dam=1735/2=867.5
        enemy[i]->receive_wound("sen",(int)(pow/2),me); //max_dam=1735/2=867.5
        COMBAT_D->report_status(enemy[i],1);
      }
    }
    enemy[i]->start_busy((int)(tim/2));
  }
  COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}

void seven(object me, object victim,object weapon, int damage)
{
  object *enemy;
  int i,j,dam,tsk,ext,hit,magic,stabber,exp,ena,mam,spi,fsk,tim;
//  me=this_player();
  if(!me || !victim) return;
  enemy = me->query_enemy();

  magic = (int)(me->query_skill("magic")); //假設為100
  stabber = (int)(me->query_skill("stabber")); //假設為100
  exp = (int)(me->query("combat_exp")/10000); //假設為10000000/10000=1000
  ena = (int)(me->query("mana_factor")); //假設為0 目前沒有指令能用?? //atman_factor 以enchant做取代
  mam = (int)(me->query_skill("dremagic")); //假設為100 //暫以dremagic替代
  spi = (int)(me->query("spi")); //假設為35
  fsk = (int)(me->query_skill("force")); //假設為400
  ext = (int)(me->query("combat_exp")/1000000); //假設為10000000/1000000=10
  hit = (int)(this_player()->query_function("fight")/5); //假設為20 //暫以修羅鬥氣(fight)替代
  ext = (int)(this_player()->query("combat_exp")/1000000); //假設為10000000/1000000=10
  tsk = (int)(victim->query("combat_exp")/500000); //假設為10000000/500000=20

  if( interactive(victim) )
  {
    dam = (int)(((mam+ena+exp)*hit)/(80+tsk)); //dam=(100+0+1000)*20/(80+20)=220
  } else {
    dam = (int)(((mam+ena+exp+stabber+spi+fsk)*hit)/100); //dam=(100+0+1000+100+35+400)*20/10=3270 威力太強 因而減弱1/10=327
  }

  if( wizardp(me) )
  {
    tell_object(me,"基本威力dam現在「"HIM+dam+NOR"」\n");
  }

  if( ext < 2 ) ext = 1;
  if( ext > 7 ) ext = 7;
  if( tsk < 1 ) tsk = 1;

//  me->add("mapower",random(5)+2); //功能不明 暫取消

  if ( random(45) > 10 )
  {
    message_vision(sprintf(HIM"
　　　　靈 － 光 － 隨 － 手 － 起"HIY"◎"HIM"靈 － 針 － 幻 － 七 － 式
      \n"NOR),me,victim );
    victim->receive_wound("kee",(int)(dam*tsk),me); //單一強力攻擊 //max_dam=3270*20=65400
    COMBAT_D->report_status(victim,1);
    for(i=1;i<=ext;i++) //應該是從1開始
    {
      switch(i)
      {
        case 1 :
          message_vision(HIC"
	      ..    ..                                  ..    .. 
	      '\\    /'                                  '\\    /'
	        \\\\//                                      \\\\//      
	   _.__\\\\\\///__._"HBBLU+HIC"☆第一式 － 靈引星移幻無邊☆"NOR+HIC"_.__\\\\\\///__._ 
	    '  ///\\\\\\  '                              '  ///\\\\\\  ' 
	        //\\\\                                      //\\\\     
	      ./    \\.                                  ./    \\.    
	      ''    ''                                  ''    ''  
            \n"NOR,me,victim);
          break;
        case 2 :
          message_vision(HIY"
	       x  .  x                                  x  .  x
	     . _\\/ \\/_ .                              . _\\/ \\/_ .
	      \\  \\ /  /                                \\  \\ /  /    
	    -==>: X :<==-"HBGRN+HIY"☆第二式 － 靈生四像幻無常☆"NOR+HIY"-==>: X :<==-  
	      / _/ \\_ \\                                / _/ \\_ \\   
	     '  /\\ /\\  '                              '  /\\ /\\  ' 
	       x  '  x                                  x  '  x 
            \n"NOR,me,victim);
          break;
        case 3 :
          message_vision(HIR"
	      .      .                                  .      .
	      _\\/  \\/_                                  _\\/  \\/_
	       _\\/\\/_                                    _\\/\\/_
	   _\\_\\_\\/\\/_/_/_"HBRED+HIR"☆第三式 － 靈動殘月幻無量☆"NOR+HIR"_\\_\\_\\/\\/_/_/_
	    / /_/\\/\\_\\ \\                              / /_/\\/\\_\\ \\
	       _/\\/\\v_                                    _/\\/\\_
	       /\\  /\\                                    /\\  /\\
	      '      '                                  '      '
            \n"NOR,me,victim);
          break;
        case 4 :
          message_vision(HIG"
	       _    _                                    _    _ 
	      /_/  \\_\\                                  /_/  \\_\\ 
	        \\\\//                                      \\\\//    
	    /\\_\\\\><//_/\\ "HBYEL+HIG"☆第四式 － 靈滅眾生幻無悲☆"NOR+HIG" /\\_\\\\><//_/\\
	    \\/ //><\\\\ \\/                              \\/ //><\\\\ \\/
	       _//\\\\_                                    _//\\\\_
	      \\_\\  /_/                                  \\_\\  /_/
            \n"NOR,me,victim);
          break;
        case 5 :
          message_vision(HIB"
	          .                                        .       
	          :                                        :       
	    '.___/x\\___.'                            '.___/x\\___.' 
	      \\x \\ / x/                                \\x \\ / x/    
	       >--X--<   "HBCYN+HIB"☆第五式 － 靈成魑魅幻無形☆"NOR+HIB"   >--X--<
	      /x_/ \\_x\\                                /x_/ \\_x\\
	    .'   \\x/   '.                            .'   \\x/   '.
	          :                                        :
	          '                                        '
            \n"NOR,me,victim);
          break;
        case 6 :
          message_vision(HIM"
	      ._    _.                                  ._    _.   
	      (_)  (_)                                  (_)  (_)   
	       .\\::/.                                    .\\::/.    
	   _.=._\\\\//_.=._"HBMAG+HIY"☆第六式 － 靈錯陰陽幻無極☆"NOR+HIM"_.=._\\\\//_.=._
	    '=' //\\\\ '='                              '=' //\\\\ '='  
	       '/::\\'                                    '/::\\'    
	      (_)  (_)                                  (_)  (_)    
	      '      '                                  '      ' 
            \n"NOR,me,victim);
          break;
        case 7 :
          message_vision(HIC"
	    <> \\  / <>                                  <> \\  / <>
	    \\_\\/  \\/_/                                  \\_\\/  \\/_/
	       \\\\//                                        \\\\//
	 _<>_\\_\\<>/_/_<>_"HBWHT+HIC"☆第七式 － 靈亂乾坤幻無定☆"NOR+HIC"_<>_\\_\\<>/_/_<>_
	  <> / /<>\\ \\ <>                              <> / /<>\\ \\ <>
	     _ //\\\\ _                                    _ //\\\\ _
	    / /\\  /\\ \\                                  / /\\  /\\ \\
	    <> /  \\ <>                                  <> /  \\ <>
            \n"NOR,me,victim);
          break;
      }
      for(j=0;j < sizeof(enemy);j++) //額外攻擊 亦是範圍技
      {
        if( !enemy[j] ) continue;
        message_vision(HIR"$N的針力蘊含無限靈力向$n"HIR"刺去，$n"HIR"的生命正一點一滴消散中!!\n"NOR,me,enemy[j]);
//        enemy[j]->add("kee",-(int)(dam)*(j+1)); //max_dam=3270  //威力改逐漸增強=327*(1~10)
        enemy[j]->receive_damage("kee",(int)(dam)*(j+1),me);
//        enemy[j]->add("gin",-(int)(dam*tsk/100)); //max_dam=3270*20/100=654 //威力減弱=327*20/100=65.4
        enemy[j]->receive_damage("gin",(int)(dam*tsk/100),me);
//        enemy[j]->add("sen",-(int)(dam*tsk/100)); //max_dam=3270*20/100=654 //威力減弱=327*20/100=65.4
        enemy[j]->receive_damage("sen",(int)(dam*tsk/100),me);
        enemy[j]->add("force",-(int)(dam*tsk/500)); //max_dam=3270*20/500=130 //威力減弱=327*20/500=13
        enemy[j]->apply_condition("magickee",random(tsk)+10);
        enemy[j]->start_busy(1);
        COMBAT_D->report_status(enemy[j]);
        if( enemy[j]->query("force") < 0 )
        {
          enemy[j]->set("force",0);
        }
      }
    }
  } else {
    message_vision(HIR"$N只覺靈性不足無法使出幻靈七訣針，一時無法將靈力釋放!!\n"NOR,me,victim);
    victim->receive_wound("kee",(int)(dam),me); //max_dam=3270
    victim->apply_condition("magickee",random(tsk)+10);
    victim->start_busy(1);
    COMBAT_D->report_status(victim,1);
  }
}

mapping query_action(object me, object weapon)
{
  int ski,mai,exi,mau;
  ski = (int)(this_player()->query_skill("mob-needle",1)); //改為新名稱 假設為150
  mai = (int)(this_player()->query_skill("dremagic",1)); //假設為100 //暫以dremagic替代
  exi = (int)(this_player()->query("combat_exp",1)/500000); //假設為10000000/500000=20
  mau = (int)(this_player()->query_function("fight")); //假設為100 //暫以修羅鬥氣(fight)替代

  if ( ski < 12 )
    return action [random(2)];
  else if ( ski < 24 )
    return action [random(3)];
  else if ( ski < 36 )
    return action [random(4)];
  else if ( ski < 60 )
    return action [random(5)];
  else if ( ski < 72 )
    return action [random(6)];
  else if ( ski < 84 )
    return action [random(7)];
  else if ( ski < 96 )
    return action [random(8)];
  else if ( ski < 108 )
    return action [random(9)];
  else if ( ski < 120 )
    return action [random(10)];
  else if ( ski < 140 )
    return action [random(11)];
  else if ( ski >= 150 && mai < 80 && mau < 30 )
//將mai=dremagic限制 原始200 //暫以dremagic替代
    return action [random(12)];
  else if ( ski >= 150 && mai < 160 && mau < 50 )
 //mai原始300
    return action [random(13)];
  else if ( ski >= 150 && mai < 200 && mau < 100  )
//mai原始500
    return action [random(6)+7];
  else if ( ski >= 150 && mai >= 200 && mau >= 100 && (random(mai)+exi > 100) )
//mai原始500 //機率約20%
    return action [random(3)+10];
  else
    return action [random(13)];
}

int valid_enable(string usage)
{
  if(this_player()->query_skill("mob-needle",1) >= 100) //改為新名稱 假設為150
  {
    return (usage=="unarmed"||usage=="stabber")||(usage=="parry");
  }
  return (usage=="stabber")||(usage=="parry");
}

int practice_skill(object me)
{
  if( (int)me->query("kee") < 30 )
    return notify_fail("體力不夠囉,休息一下再繼續練吧.\n");
  me->receive_damage("kee", 30);
  return 1;
}
/*
string perform_action_file(string action)
{
  return CLASS_D("needlegirl")+"/be-needle/"+action;
}
*/
