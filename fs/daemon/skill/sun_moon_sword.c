//仙劍二轉技能 加上解迷因素
//強者較強, 弱者則較連陽弱些
// written by appo@fs 如要翻"烤" 請告知
//強調運起昊玥罡氣的護身氣勁時 攻擊力減半 因為已附加其它功能
//修正訊息錯誤與調整函數對應 by blazakira 2010/12/9
//增加 使用者與對手的存在與否的判斷 與 receive_xxx的攻擊方參數 by blazakira 2011/9/16
//補上使用者或被攻擊方是否存在的判斷 與 使用附攻將會消耗內力的代價 by blazakira 2011/10/3

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void sunmoon1(object me, object victim, object weapon, int damage);
void sunmoon2(object me, object victim, object weapon, int damage);
void sunmoon3(object me, object victim, object weapon, int damage);
void sunmoon4(object me, object victim, object weapon, int damage);
void sunmoon5(object me, object victim, object weapon, int damage);
void sunmoon6(object me, object victim, object weapon, int damage);
void sunmoon7(object me, object victim, object weapon, int damage);
void sunfire(object me, object victim, object weapon, int damage);
int kar,cps,str,cor,int1,spi,per;
int sp_value;

string *parry_msg = ({
  HIW + "\n而$n" + HIW + "手中的長劍一橫，一招" + HIB + "『如日中天』" + NOR + "勢挾千斤往前一推一送，噹的一聲碰出了點點火花反把$N" + HIW + "手中的$w" + HIW + "險些震飛！\n" + NOR,
  HIW + "\n但$n" + HIW + "長劍一轉，順著$N" + HIW + "的$w" + HIW + "以一招" + HIC + "『順流而下』" + NOR + "往$N" + HIW + "的手指削去，$N" + HIW + "大驚失色下急忙收招回架。\n" + NOR,
  HIW + "\n$n" + HIW + "劍走輕靈，手中長劍忽削忽刺一連串的兵器撞擊聲後$n" + HIW + "已將$N" + HIW + "的快招全部化解！\n" + NOR,
  HIW + "\n$n" + HIW + "以快制快，$N" + HIW + "快但$n" + HIW + "更快，連續刺出了七七四十九劍織成一道劍網將$N" + HIW + "的招式盡數盪開！\n" + NOR,  
  HIW + "\n$n" + HIW + "將手中長劍一縮一放，以一招" + HIB + "『如影隨形』" + NOR + "長劍隨$N" + HIW + "的$w" + HIW + "舞動，卸掉$N" + HIW + "的勁力！\n" + NOR,
  HIW + "\n$N" + HIW + "以千軍萬馬之勢攻向$n" + HIW + "，只見$n" + HIW + "不慌不忙以逸待勞" + HIC + "『排山倒海』" + NOR + "，將$N" + HIW + "的攻勢消解在無形中！\n" + NOR,
  HIW + "\n$n" + HIW + "以心制劍，不慌不忙將其武學發揮的淋漓盡致一招" + HIR + "『日月並行』" + NOR + "，將$N" + HIW + "嚇得急忙收招！\n" + NOR,
});

string *unarmed_parry_msg = ({
  "但是被$n格開了。\n",
  "結果被$n擋開了。\n",
});

mapping *action = ({
//1
  (["action"     : HIC + "$N" + HIC + "運起日月兩極氣勁，手中長劍閃閃爍爍，日月絕學起手式【日光月影】隨性而出。" + NOR,
    "parry"      : -120,
    "dodge"      : -120,
    "damage"     : 400,
    "force"      : 400,
    "post_action": (: sunmoon1 :),
    "damage_type": "割傷",
  ]),
//2
  (["action"     : HIC + "$N" + HIC + "運起渾身氣勁，左日--右月，陰陽兩極勁帶動渾身劍氣泛起波波殺意如刃向$n" + HIC + "繞流而去。" + NOR,
    "parry"      : -120,
    "dodge"      : -120,
    "damage"     : 410,
    "force"      : 410,
    "post_action": (: sunmoon2 :),
    "damage_type": "割傷",
  ]),
//3
  (["action"     : HIC + "$N" + HIC + "原地翻身，手腕一抓，$w" + HIC + "已有如怒龍出困般，挾著強猛的功\力筆直射出！" + NOR,
    "parry"      : -120,
    "dodge"      : -120,
    "damage"     : 430,
    "force"      : 430,
    "post_action": (: sunmoon3 :),
    "damage_type": "割傷",
  ]),
//4
  (["action"     : HIC + "$N" + HIC + "電擊般格掠向前，千百條絢燦明亮的" + HIY + "劍芒" + HIC + "，參差不齊的在同一時間，像炸開了一朵"+HIW + "光球"+HIC + "般朝四週飛射掠舞，$n" + HIC + "目光一眩，已身陷其中。" + NOR,
    "parry"      : -120,
    "dodge"      : -120,
    "damage"     : 440,
    "force"      : 440,
    "post_action": (: sunmoon4 :),
    "damage_type": "割傷",
  ]),
//5
  (["action"     : HIC + "$N" + HIC + "一聲大喝，倏然出招，只見天地之間" + HIW + "金芒閃爍" + HIC + "，" + HIR + "火焰遍野" + HIC + "，咻咻的銳氣排空四溢。" + NOR,
    "parry"      : -130,
    "dodge"      : -130,
    "damage"     : 450,
    "force"      : 450,
    "post_action": (: sunmoon5 :),
    "damage_type": "割傷",
  ]),
//6
  (["action"     : HIC + "$N" + HIC + "哼的一聲，運起護身真氣，身上連陽之氣爆然而出瞬間吞沒$n" + HIC + "。" + NOR,
    "parry"      : -130,
    "dodge"      : -130,
    "damage"     : 450,
    "force"      : 450,
    "post_action": (: sunfire :),
    "damage_type": "割傷",
  ]),
//7
  (["action"     : HIC + "隨$N" + HIC + "一收一放，其身體內劍聖之血漸漸沸騰，只聽$N" + HIC + "大喊" + HIW + "劍聖絕式--" + HIB + "『日月並行』" + HIC + "。" + NOR,
    "parry"      : -130,
    "dodge"      : -130,
    "damage"     : 470,
    "force"      : 470,
    "post_action": (: sunmoon6 :),
    "damage_type": "割傷",
  ]),
//8
  (["action"     : HIC + "$N" + HIC + "殺的起勁，不經意的使出日月絕學禁斷技╠═ " + HIY + "昊 陽˙競 月" + HIC + " ═╣，日月之氣充斥四週，直撲$n" + HIC + "。" + NOR,
    "parry"      : -140,
    "dodge"      : -140,
    "damage"     : 500,
    "force"      : 500,
    "post_action": (: sunmoon7 :),
    "damage_type": "割傷",
  ]),
//9
  (["action"     : "$N並非劍客...無法使用此劍術。",
    "force"      : 10,
    "damage"     : 10,
    "damage_type": "白癡傷",
  ]),
});

int valid_learn(object me)
{
  if(!me->query("quest/free_yao",1))
  {
    tell_object(me,"你還不夠資格練日月並行之招...\n");
    return 0;
  }
  if( !me->query_temp("weapon"))
  {
    tell_object(me,"練劍法必需先拿把劍。\n");
    return 0;
  }
  if( (me->query("potential") - me->query("learned_points")) < 25 )
  {
    tell_object(me, "你的潛能不到二十五點，無法練此劍法。\n");
    return 0;
  }
  me->add("potential", -25);
  return 1;
}

int valid_enable(string usage)
{
  return ( usage=="sword" || usage=="parry" );
}

mapping query_action(object me, object *weapon )
{
  int skill_level,limit;
  skill_level = (int)(me->query_skill("sun_moon_sword",1));
  limit= skill_level;
  if( wizardp(me) || me->query_temp("blaz/kon")>0 )
  {
    kar=me->query_kar()+me->query_kar();
    cps=me->query_cps()+me->query_cps();
    str=me->query_str()+me->query_str();
    cor=me->query_cor()+me->query_cor();
    int1=me->query_int()+me->query_int();
    spi=me->query_spi()+me->query_spi();
    per=me->query_per()+me->query_per();
  }
  else {
    kar=me->query_kar();
    cps=me->query_cps();
    str=me->query_str();
    cor=me->query_cor();
    int1=me->query_int();
    spi=me->query_spi();
    per=me->query_per();
  }
  if(me->query("family/family_name")!="仙劍派")
    return action[8];
  if (limit ==100 && me->query("swordskill/sword8")==1)
    return action[random(8)]; //調整random(7)+1為random(8) action=0時 使用第一招 random(8)最高為action[7]
  else if (limit < 15)
    return action[random(1)];
  else if (limit < 30)
    return action[random(2)];
  else if (limit < 45)
    return action[random(3)];
  else if (limit < 60)
    return action[random(4)];
  else if (limit < 75)
    return action[random(5)];
  else if (limit < 90)
    return action[random(6)];
  else return action[random(7)];
}

// 增加解迷影響, 副攻內增加連擊速度
// swordskill/sword1
void sunmoon1(object me, object victim, object weapon, int damage)
{
  if(!me || !victim || me->query("force") < 50) return;
  me->add("force",-50);
  sp_value =6*(str+cor)+cps+kar+spi+int1; //max=6*(35+35)+35+35+35+35=560
  if(me->query_temp("sun-moon")==1) sp_value=sp_value/2; //max=560/2=280
  message_vision(HIC + "$N" + HIC + "劍隨意轉，一招日月兩極劍法【" + HIW + "日 光 月 影" + HIC + "】牽動身上兩極氣勁直逼$n" + HIC + "而去。\n" + NOR,me,victim);
  if( random(me->query("combat_exp")) > random(victim->query("combat_exp"))/7 ) //假設為840 > 840/7
  {
    if(me->query("swordskill/sword1")==1)
    {
      message_vision(HIC + "$N" + HIC + "手中常見劃破$n" + HIC + "的防線，瞬間對$n" + HIC + "造成嚴重的割傷。\n" + NOR,me,victim);
      victim->receive_damage("kee",sp_value,me); //dam=280
      COMBAT_D->report_status(victim);
      if(me && me->query("force") < 20) {
        message_vision(CYN+BYEL + "$N" + CYN+BYEL + "的內力不足以驅動武學連擊。\n" + NOR,me,victim);
        return;
      }
      me->add("force",-20);
      COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    }
    else
    {
      victim->receive_damage("kee",100,me); //dam=100
      message_vision(HIM + "$N" + HIM + "手中常見劃破$n" + HIM + "的防線，但因其無法掌握此招精華所在，因此讓$n" + HIM + "在危急時閃過，僅造成蚊蟲叮咬般的傷害。\n" + NOR,me,victim);
      COMBAT_D->report_status(victim);
    }
  }
  else
  {
    message_vision(sprintf(HIM + "千鈞一髮之際$n" + HIM + "避開了$N" + HIM + "的殺招！\n" + NOR),me,victim);
  }
}

// 增加解迷影響, 副攻內random(10)>8則出現busy
// swordskill/sword2
void sunmoon2(object me, object victim, object  weapon, int damage)
{
  int i,j;
  if(!me || !victim || me->query("force") < 50) return;
  me->add("force",-50);
  sp_value =4*(str+cor)+cps+kar+spi+int1; //max=4*(35+35)+35+35+35+35=420
  if(me->query_temp("sun-moon")==1) sp_value=sp_value/2; //max=420/2=210
  if (me->query("id")=="appo" || me->query("id")=="blazakira") j=10;
  else j=random(10)+1;
  if( random(me->query("combat_exp")) > random(victim->query("combat_exp"))/7 ) //假設為840 > 840/7
  {
    if(me->query("swordskill/sword2")==1)
    {
      message_vision(HIY + "$N" + HIY + "使出日月兩極劍法【" + HIW + "日 月 兩 儀═ 乾 坤 陰 陽 斬" + HIY + "】手中長劍隱隱現現，剎那間對$n" + HIY + "殺出數招。\n" + NOR,me,victim);
      for(i=1;i<=j;i++)
      {
        switch(i)
        {
          case 1:
            message_vision(sprintf(HIC + "$N" + HIC + "使出乾坤陰陽斬第一擊" + HIY + "＜牙    斬＞" + HIC + "，對$n" + HIC + "劈出致命一擊。\n" + NOR),me,victim);
            break;
          case 2:
            message_vision(sprintf(HIC + "$N" + HIC + "使出乾坤陰陽斬第二擊" + HIY + "＜狼    絞＞" + HIC + "，對$n" + HIC + "劈出致命一擊。\n" + NOR),me,victim);
            break;
          case 3:
            message_vision(sprintf(HIC + "$N" + HIC + "使出乾坤陰陽斬第三擊" + HIY + "＜豹\    靳＞" + HIC + "，對$n" + HIC + "劈出致命一擊。\n" + NOR),me,victim);
            break;
          case 4:
            message_vision(sprintf(HIC + "$N" + HIC + "使出乾坤陰陽斬第四擊" + HIY + "＜虎    斷＞" + HIC + "，對$n" + HIC + "劈出致命一擊。\n" + NOR),me,victim);
            break;
          case 5:
            message_vision(sprintf(HIC + "$N" + HIC + "使出乾坤陰陽斬第五擊" + HIY + "＜鳳    舞＞" + HIC + "，對$n" + HIC + "劈出致命一擊。\n" + NOR),me,victim);
            break;
          case 6:
            message_vision(sprintf(HIC + "$N" + HIC + "使出乾坤陰陽斬第六擊" + HIY + "＜龍    破＞" + HIC + "，對$n" + HIC + "劈出致命一擊。\n" + NOR),me,victim);
            break;
          case 7:
            message_vision(sprintf(HIC + "$N" + HIC + "使出乾坤陰陽斬第七擊" + HIY + "＜麒 麟 滅＞" + HIC + "，對$n" + HIC + "劈出致命一擊。\n" + NOR),me,victim);
            break;
          case 8:
            message_vision(sprintf(HIC + "$N" + HIC + "使出乾坤陰陽斬第八擊" + HIY + "＜陰陽無形連牙斬＞" + HIC + "，對$n" + HIC + "劈出致命一擊。\n" + NOR),me,victim);
            break;
          case 9:
            message_vision(sprintf(HIC + "$N" + HIC + "使出乾坤陰陽斬第九擊" + HIY + "＜乾坤無極斬八方＞" + HIC + "，對$n" + HIC + "劈出致命一擊。\n" + NOR),me,victim);
            victim->start_busy(1);
            break;
          case 10:
            message_vision(sprintf(HIC + "$N" + HIC + "使出乾坤陰陽斬最終擊" + HIY + "＜乾坤陰陽震日月＞" + HIC + "，對$n" + HIC + "劈出致命一擊。\n" + NOR),me,victim);
            victim->start_busy(1);
            break;
        }
        message_vision(sprintf(HIB + "乾坤陰陽斬所發出的殺招如影隨行，避無可避，$n" + HIB + "慘遭無情劍招蹂躪！\n" + NOR),me,victim);
        victim->receive_wound("kee",i*10+random(50),me); //dam_max=(1~10)*10+50=55*10+50=600
      }
      COMBAT_D->report_status(victim,1);
    }
    else
    {
      message_vision(HIG + "$N" + HIG + "無法發揮出日月兩極劍法之精隨，雖使出【"+HIW + "日 月 兩 儀═ 乾 坤 陰 陽 斬"+HIG + "】，但雷聲大雨點小，僅發出數道劍氣。\n" + NOR,me,victim);
      victim->receive_damage("kee",sp_value,me); //dam_max=210
      COMBAT_D->report_status(victim);
    }
  }
  else
  {
    message_vision(sprintf(HIM + "千鈞一髮之際$n" + HIM + "避開了$N" + HIM + "的殺招！\n" + NOR),me,victim);
  }
}

// 增加解迷影響, 副攻內增加連擊速度
// swordskill/sword3
void sunmoon3(object me, object victim, object  weapon, int damage)
{
  if(!me || !victim || me->query("force") < 50) return;
  me->add("force",-50);
  sp_value =4*(str+cor)+cps+kar+spi+int1; //max=4*(35+35)+35+35+35+35=420
  if(me->query_temp("sun-moon")==1) sp_value=sp_value/2; //max=420/2=210
  if( random(me->query("combat_exp")) > random(victim->query("combat_exp"))/7 ) //假設為840 > 840/7
  {
    if(me->query("swordskill/sword3")==1)
    {
      message_vision(HIC + "$N" + HIC + "長嘯一聲，手中長劍有如狂龍再現，隨日月絕學【"+HIW + "轉 龍 迴 日"+HIC + "】施展，$N" + HIC + "有如怒海蛟龍一般，身形變換不定，不一會兒以化成一道龍形劍芒直逼$n" + HIC + "。\n" + NOR,me,victim,weapon);
      victim->receive_damage("kee",sp_value,me); //dam=210
      COMBAT_D->report_status(victim);
      if(me && me->query("force") < 20) {
        message_vision(CYN+BYEL + "$N" + CYN+BYEL + "的內力不足以驅動武學連擊。\n" + NOR,me,victim);
        return;
      }
      me->add("force",-20);
      COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    }
    else
    {
      message_vision(HIC + "$N" + HIC + "長嘯一聲，手中長劍有如狂龍再現，隨日月絕學【"+HIW + "轉 龍 迴 日"+HIC + "】施展，$N" + HIC + "有如怒海蛟龍一般，身形變換不定，不一會兒以化成一道龍形劍芒直逼$n" + HIC + "。\n" + NOR,me,victim,weapon);
      victim->receive_damage("kee",sp_value,me); //dam=210
      message_vision(HIM + "隨【" + HIW + "轉 龍 迴 日" + HIM + "】施展後，$N" + HIM + "內氣翻騰，身形頓時慢了下來。\n" + NOR,me,victim,weapon);
      me->start_busy(1);
      COMBAT_D->report_status(victim);
    }
  }
  else
  {
    message_vision(sprintf(HIM + "千鈞一髮之際$n" + HIM + "避開了$N" + HIM + "的殺招！\n" + NOR),me,victim);
  }
}

// 增加解迷影響, 副攻內增加威力
// swordskill/sword4
void sunmoon4(object me, object victim, object weapon, int damage)
{
  if(!me || !victim || me->query("force") < 50) return;
  me->add("force",-50);
  sp_value =6*(str+cor)+cps+kar+spi+int1; //max=6*(35+35)+35+35+35+35=560
  if(me->query_temp("sun-moon")==1) sp_value=sp_value/2; //max=560/2=280
  if(me->query("swordskill/sword4")==1)
  {
    int i,j;
    object room,*target;
    room = environment(me);
    target=me->query_enemy(room);
    i=sizeof(target);
    message_vision(HIC + "$N" + HIC + "殺的興起，一招【" + HIM + "艷 陽 明 月 穿 無 極" + HIC + "】劍意無涯，瞬間以對$n" + HIC + "刺出八八六十四劍。\n" + NOR,me,victim);
    message_vision(HIC + "$N" + HIC + "領悟昊陽競月精華，【" + HIM + "艷 陽 明 月 穿 無 極" + HIC + "】帶動天地精英" + HIW+HBWHT + "靈曜" + NOR+HIC + "，瞬間天地變色，牽動無比狂霸氣勁直擊場中所有敵人。\n" + NOR,me,victim);
    for(j=0;j < i;j++)
    {
      if( random(me->query("combat_exp")) > random(target[j]->query("combat_exp"))/12 ) //假設為840 > 840/12
      {
        if(!target[j]) continue;
        target[j]->receive_damage("kee",sp_value+130,me); //dam=280+130=410
        target[j]->start_busy(1);
        target[j]->receive_wound("kee",sp_value,me); //dam=280
        target[j]->set_temp("no_power",1);
        target[j]->apply_condition("no_power",2);
        message_vision(sprintf(HIR + "$n" + HIR + "完全無法抵擋$N" + HIR + "的殺招，只能眼睜睜的被" + HIW+HBWHT + "靈曜" + NOR+HIR + "所帶來的無比劍氣所吞噬！\n" + NOR),me,target[j]);
        COMBAT_D->report_status(target[j]);
      }
      else
      {
        message_vision(sprintf(HIM + "千鈞一髮之際$n" + HIM + "避開了$N" + HIM + "的殺招！\n" + NOR),me,target[j]);
      }
    }
  }
  else
  {
    object *target;
    target=me->query_enemy();
    message_vision(HIG + "$N" + HIG + "殺的興起，一招【" + HIW + "一 劍 百 轉 ═ 日 月 同 輝" + HIG + "】劍意無涯，瞬間以對$n" + HIG + "刺出八八六十四劍。\n" + NOR,me,target);
    if( random(me->query("combat_exp")) > random(target->query("combat_exp"))/12 ) //假設為840 > 840/12
    {
      target->receive_damage("kee",sp_value,me); //dam=280
      COMBAT_D->report_status(target);
    }
    else
    {
      message_vision(sprintf(HIM + "千鈞一髮之際$n" + HIM + "避開了$N" + HIM + "的殺招！\n" + NOR),me,victim);
    }
  }
}

void sunmoon5(object me, object victim, object  weapon, int damage)
{
  if(!me || !victim || me->query("force") < 50) return;
  me->add("force",-50);
  sp_value =6*(str+cor)+cps+kar+spi+int1; //max=6*(35+35)+35+35+35+35=560
  if(me->query_temp("sun-moon")==1) sp_value=sp_value/2; //max=560/2=280
  message_vision(HIC + "$N" + HIC + "殺意一起，不自覺使出日月殺招【" + HIW + "凌 霄 穿 雲 ═ 斷 虹 削 日" + HIC + "】，$n" + HIC + "面對陰陽兩股氣勁頓時不知如何招架。\n" + NOR,me,victim);
  if( random(me->query("combat_exp")) > random(victim->query("combat_exp"))/7 ) //假設為840 > 840/7
  {
    victim->receive_wound("kee",sp_value+130,me); //dam=280+130=410
    if( weapon->query("id")=="sevensun_sword" || "sun_moon_sword") victim->start_busy(1);
    victim->set_temp("no_power",1);
    victim->apply_condition("no_power",2);
    COMBAT_D->report_status(victim,1);
  }
  else
  {
    message_vision(sprintf(HIM + "千鈞一髮之際$n" + HIM + "避開了$N" + HIM + "的殺招！\n" + NOR),me,victim);
  }
}

// 第五個skill 判斷 swordskill/sunmoon
void sunfire(object me, object victim, object  weapon, int damage)
{
  int skill_level,limit,i;
  if(!me || !victim || me->query("force") < 50) return;
  me->add("force",-50);
  skill_level = (int)(me->query_skill("sun_moon_sword",1));
  limit= skill_level;
  if( random(me->query("combat_exp")) > random(victim->query("combat_exp"))*4 ) //假設為840 > 840*4
  {
    if (me->query("swordskill/sunmoon")==1 )
    {
      sp_value =4*(cps+kar)+str+cor+spi+int1; //max=4*(35+35)+35+35+35+35=420
      if(me->query_temp("sun-moon")==1) sp_value=sp_value/2; //max=420/2=210
      message_vision(sprintf(HIR + "眨眼間，劍鋒泛火，火光漸如燄日逼人，$N" + HIR + "如化祝融全身火紅
驀地一聲大喝" + HIW + "『烈陽氣殺』" + HIR + "，手中長劍猶似火龍摧天，
劍幻千萬火炬直逼$n" + HIR + "而去。\n" + NOR),me,victim);
      if(random(me->query_skill("sword")*3) > random(victim->query_skill("dodge") )) //假設為120*3 >120
      {
        victim->receive_damage("kee",sp_value,me); //dam=210
        victim->apply_condition("hellfire",random(3));
        COMBAT_D->report_status(victim);
        if(me && me->query("force") < 20) {
          message_vision(CYN+BYEL + "$N" + CYN+BYEL + "的內力不足以驅動武學連擊。\n" + NOR,me,victim);
          return;
        }
        me->add("force",-20);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
      }
      else message_vision(HIM + "\n$N" + HIM + "人比劍快，驚險地閃過了這一招。\n" + NOR,victim);
    }
    if (me->query("swordskill/sunmoon")==2 )
    {
      int j,time;
      sp_value = 2*(cor+int1+str+spi+cps+kar); //max=2*(35+35+35+35+35+35)=420
      if(me->query_temp("sun-moon")==1) sp_value=sp_value/2; //max=210
      message_vision(HIC + "$N" + HIC + "收光為暈斂剛成柔，激起身上" + HIY + "『殘陽柔勁』" + HIC + "，瞬間身化殘影落步，劍尖分指$n" + HIC + "。\n" + NOR,me,victim);
      if (!me->query_temp("strike",1))
      {
        time = random(per/10)+random(cor/15);
        me->set_temp("strike",1);
        for(j=0;j<=time;j++)
        {
          message_vision(HIY + "柔勁無鋒，無窮無盡，衍生出無數招式，招招朝著$n" + HIY + "的要穴竄去。\n" + NOR,me,victim);
          victim->receive_damage("kee",sp_value,me); //dam=210
          COMBAT_D->report_status(victim);
          if(me && me->query("force") < 20) {
            message_vision(CYN+BYEL + "$N" + CYN+BYEL + "的內力不足以驅動武學連擊。\n" + NOR,me,victim);
            return;
          }
          me->add("force",-20);
          COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
        }
      }
      else
      {
        message_vision(sprintf(HIR + "殺意無盡，劍招無窮..\n" + NOR),me,victim);
        victim->receive_damage("kee",(int)sp_value/2+50,me); //將參數damage改為sp_value 因為damage數值太模糊了 且有出現負數的可能 by blazakira
        COMBAT_D->report_status(victim);
        if(me && me->query("force") < 20) {
          message_vision(CYN+BYEL + "$N" + CYN+BYEL + "的內力不足以驅動武學連擊。\n" + NOR,me,victim);
          return;
        }
        me->add("force",-20);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
      }
      victim->delete_temp("conti");
      me->delete_temp("strike");
    }
    if (me->query("swordskill/sunmoon")==3 )
    {
      message_vision(HIC + "$N" + HIC + "靈機一動運起身上" + HIY + "『豔陽真氣』" + HIC + "，手中$w" + HIC + "隨之呼應，艷陽光輝無窮無盡射向$n" + HIC + "眉心。\n" + NOR,me,victim);
      sp_value =6*(spi+int1)+cps+kar+str+cor; //max=6*(35+35)+35+35+35+35=560
      if(me->query_temp("sun-moon")==1) sp_value=sp_value/2; //max=560/2=280
      if( random(me->query("combat_exp")) > random(victim->query("combat_exp"))/6 ) //假設為840 > 840/6
      {
        message_vision(HIY + "
        就在同時，$N" + HIY + "心擴天地，懷若宇宙，狂奔的戾氣瞬間平息，$N" + HIY + "與
        天地彷彿結合為一，瑞光豔麗光彩奪目，凝止住全部的的動作
        一式" + HIW + "『豔陽三劍--天地人』" + HIY + "迅如雷光落向$n" + HIY + "。\n" + NOR,me,victim);
        victim->receive_damage("kee",sp_value,me); //dam=280
        victim->set_temp("no_power",1);
        victim->apply_condition("no_power",2);
        COMBAT_D->report_status(victim);
      }
      else message_vision(HIM + "\n$N" + HIM + "人比劍快，驚險地閃過了這一招。\n" + NOR,victim);
    }
    if (me->query("swordskill/sunmoon")==4 )
    {
      sp_value =4*(cps+kar)+str+cor+spi+int1; //max=4*(35+35)+35+35+35+35=420
      if(me->query_temp("sun-moon")==1) sp_value=sp_value/2; //max=420/2=210
      message_vision(HIW + "
劍壓流動，隨著$N" + HIW + "的心念越發強烈，身上" + HIY + "『暖陽罡\氣』" + HIW + "油然而生
剎那間!!天地變色風起雲湧，一輪暖日在空氣之間現形而生
$n" + HIW + "被此情景所震懾，一瞬間已被吞沒於光芒之中。
\n" + NOR,me,victim);
      if(random(me->query_skill("sword")*3) > random(victim->query_skill("dodge") )) //假設為120*3 > 120
      {
        victim->receive_damage("kee",sp_value,me); //dam=210
        victim->apply_condition("tsunami",random(3));
        COMBAT_D->report_status(victim);
        if(me && me->query("force") < 20) {
          message_vision(CYN+BYEL + "$N" + CYN+BYEL + "的內力不足以驅動武學連擊。\n" + NOR,me,victim);
          return;
        }
        me->add("force",-20);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
      }
      else message_vision(HIM + "\n$N" + HIM + "人比劍快，驚險地閃過了這一招。\n" + NOR,victim);
    }
    if (me->query("swordskill/sunmoon")==5 )
    {
      sp_value =4*(cps+kar)+str+cor+spi+int1; //max=4*(35+35)+35+35+35+35=420
      if(me->query_temp("sun-moon")==1) sp_value=sp_value/2; //max=420/2=210
      message_vision(HIW + "
$N" + HIW + "內勁頓轉運起身上" + HIC + "『冬陽寒意』" + HIW + "捲起無數狂霜亂雪，直搗$n" + HIW + "心口。\n" + NOR,me,victim);
      if(random(me->query_skill("sword")*3) > random(victim->query_skill("dodge") )) //假設為120*3 > 120
      {
        victim->receive_damage("kee",sp_value,me); //dam=210
        victim->apply_condition("cold",random(3));
        COMBAT_D->report_status(victim);
        if(me && me->query("force") < 20) {
          message_vision(CYN+BYEL + "$N" + CYN+BYEL + "的內力不足以驅動武學連擊。\n" + NOR,me,victim);
          return;
        }
        me->add("force",-20);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
      }
      else message_vision(HIM + "\n$N" + HIM + "人比劍快，驚險地閃過了這一招。\n" + NOR,victim);
    }
    if (me->query("swordskill/sunmoon")==6)
    {
      sp_value =5*(str+cor+cps)+spi+int1+kar; //max=5*(35+35+35)+35+35+35=630
      if(me->query_temp("sun-moon")==1) sp_value=sp_value/2; //max=630/2=315
      message_vision(HIY + "
瞬間，$N" + HIY + "再收劍入鞘，心凝一式" + HIW + "『朝陽再現』" + HIY + "，迴身飛旋，幾乎是
同時，長劍已離鞘直劃$n" + HIY + "的咽喉。
\n" + NOR,me,victim);
      if( weapon->query("id")=="sun_fire_sword" || "sevensun_sword" || "sun_moon_sword")
      {
        message_vision(HIY + "
靈劍$w" + HIY + "隨著$N" + HIY + "身上『朝陽昊氣』激出無比靈氣，剎那間!劍泛金光
完全照亮了暗影，如千百個太陽在$N" + HIY + "的手中，一齊射出無與倫比的金光，令
$n" + HIY + "根本無法逼視。
\n" + NOR,me,victim,weapon);
        victim->receive_wound("kee",sp_value+80,me); //dam=315+80=395
        victim->start_busy(1);
        COMBAT_D->report_status(victim,1);
      }
      else
      {
        message_vision(HIR + "\n$N" + HIR + "人比劍快，驚險地閃過了這一招，但卻受到了擦傷。\n" + NOR,victim); //有傷害就改紅色吧
        victim->receive_wound("kee",sp_value/3,me); //dam=105
        COMBAT_D->report_status(victim,1);
      }
    }
    if (me->query("swordskill/sunmoon")==7 )
    {
      sp_value =4*(cps+kar)+str+cor+spi+int1; //max=4*(35+35)+35+35+35+35=420
      if(me->query_temp("sun-moon")==1) sp_value=sp_value/2; //max=420/2=210
      message_vision(HIR + "
$N" + HIR + "趁勢翻身飛躍，" + HIW + "『夕陽氣勁』" + HIR + "瞬間爆出，霎時，劍鼓風旋，
連鎖成無數無形風刃。" + NOR,me,victim);
      if(random(me->query_skill("sword")*3) > random(victim->query_skill("dodge") )) //假設為120*3 > 120
      {
        victim->receive_damage("kee",sp_value,me); //dam=210
        COMBAT_D->report_status(victim);
        if(me && me->query("force") < 20) {
          message_vision(CYN+BYEL + "$N" + CYN+BYEL + "的內力不足以驅動武學連擊。\n" + NOR,me,victim);
          return;
        }
        me->add("force",-20);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
      }
      else message_vision(HIM + "\n$N" + HIM + "人比劍快，驚險地閃過了這一招。\n" + NOR,victim);
    }
// quest 完成率100 因此有較高的攻擊力及特攻
    if (me->query("swordskill/sunmoon")==9 )
    {
      sp_value =6*(cps+kar)+str+cor+spi+int1; //max=6*(35+35)+35+35+35+35=560
      if(random(me->query_skill("sword")*4) > random(victim->query_skill("dodge") )) //假設為120*4 > 120
      {
        message_vision(HIW + "$N" + HIW + "緊閉雙眼，身上爆出七色氣芒，交錯飛旋，$N" + HIW + "緩緩舉起配劍，
七色光芒急速會齊於劍尖，就在此時$N縱身一躍，大喝一聲" + HBCYN + "『劍影連陽，七陽連天』" + NOR+HIW + "!!
已聚集的七道光芒瞬間轉換成的七股剛柔並濟的劍虹，滿天劍影，
$n" + HIW + "避無可避只能硬著頭皮接下這驚天動地的一招。\n" + NOR,me,victim);
        victim->receive_wound("kee",sp_value+200,me); //dam=760
        victim->start_busy(2);
        victim->apply_condition("tsunami",random(3));
        COMBAT_D->report_status(victim,1);
      }
      else
      {
        message_vision(HIR + "$N" + HIR + "費盡心思，躲過這驚天動地的一擊，不過亦被其強大的氣勁震傷。\n" + NOR,victim);
        victim->receive_wound("kee",sp_value,me); //dam=560
        COMBAT_D->report_status(victim,1);
      }
    }
  }
}

//第六個skill判斷
//sword5
void sunmoon6(object me, object victim, object  weapon, int damage)
{
  int i,b,k,m;
  if(!me || !victim || me->query("force") < 50) return;
  me->add("force",-50);
  message_vision(HIY + "
$N" + HIY + "劍隨意轉，身上無極劍氣帶動日月兩極勁，將昊陽競月劍意發揮的淋漓盡致，日月絕學隨$N" + HIY + "劍意所動，竟衍生出不同以往的招式!!
" + HIW + "只見$N" + HIW + "吟道：" + HIC + " ◎日無極，昊陽神焰伏魔意  。  月無垠，競月伏濤渡邪念◎" + HIY + "
隨即使出日月絕學至極劍招▲"+HIW + "日 月 並 行"+HIY + "▲
\n" + NOR,me,victim);
  m=50;
  if (per<12) b=3;
  else if (per <= 16) b =4;
  else if (per > 16) b = 5;
  if(me->query("swordskill/sword5")==1)
  {
    for(i=1;i<=b;i++)
    {
      switch(i)
      {
        case 1:
          message_vision(HIB + "$N" + HIB + "隨渾身劍氣使出日月絕學之◆" + HIW + "日 光 月 影" + HIB + "◆。\n" + NOR,me,victim);
          break;
        case 2:
          message_vision(HIB + "$N" + HIB + "隨渾身劍氣使出日月絕學之◆" + HIW + "凌 霄 斷 虹" + HIB + "◆。\n" + NOR,me,victim);
          break;
        case 3:
          message_vision(HIB + "$N" + HIB + "隨渾身劍氣使出日月絕學之◆" + HIW + "轉 龍 迴 日" + HIB + "◆。\n" + NOR,me,victim);
          break;
        case 4:
          message_vision(HIC + "$N" + HIC + "憑本身絕佳之無窮劍意配合日月無極劍氣使出◆" + HIW + "乾 坤 陰 陽 斬" + HIC + "◆。\n" + NOR,me,victim);
          break;
        case 5:
          message_vision(HIY + "$N" + HIY + "隨運起昊陽競月氣勁，發出日月並行最強一擊◆" + HIW + "昊 陽 競 月 兩 極 破" + HIY + "◆。\n" + NOR,me,victim);
          victim->start_busy(1);
        break;
      }
      if( random(me->query("combat_exp")) > random(victim->query("combat_exp"))/10 ) //假設為840 > 840/10
      {
        message_vision(sprintf(HIR + "面對日月雙重絕學，$n" + HIR + "完全無法閃躲，只能任$N" + HIR + "宰割！\n" + NOR),me,victim);
        victim->receive_wound("kee",m*i,me); //dam_max=(1~5)*50=750
        COMBAT_D->report_status(victim,1);
      }
      else
      {
        message_vision(sprintf(HIM + "千鈞一髮之際$n" + HIM + "躲開了$N" + HIM + "的殺招！\n" + NOR),me,victim);
      }
    }
  }
  else
  {
    if( random(me->query("combat_exp")) > random(victim->query("combat_exp"))/10 )
    {
      message_vision(sprintf(HIR + "面對日月雙重絕學，$n" + HIR + "完全無法閃躲，只能任$N" + HIR + "宰割！\n" + NOR),me,victim);
      victim->receive_wound("kee",m*5,me); //dam=250
      COMBAT_D->report_status(victim,1);
    }
    else
    {
      message_vision(sprintf(HIM + "千鈞一髮之際$n" + HIM + "躲開了$N" + HIM + "的殺招！\n" + NOR),me,victim);
    }
  }
}

//第七個skill判斷...
//need swordskill/sword8
void sunmoon7(object me, object victim, object weapon, int damage)
{
  int times;
  if(!me || !victim || me->query("force") < 50) return;
  me->add("force",-50);
  sp_value =5*(str+cor)+cps+kar+spi+int1; //max=5*(35+35)+35+35+35+35=490
  if(me->query_temp("sun-moon")==1) sp_value=sp_value/2; //max=245
  if ((per+kar)<30) times=1;
  if ((per+kar)<50) times=2;
  else times=3;
  if(!victim->query_temp("sword"))
  {
    message_vision(HIR + "藉由日月之氣，$N" + HIR + "對$n" + HIR + "發動強勁的攻勢。\n" + NOR,me,victim);
    victim->add_temp("sword",times);
    victim->receive_wound("kee",sp_value,me); //dam=245
    COMBAT_D->report_status(victim,1);
    if(me && me->query("force") < 20) {
      message_vision(CYN+BYEL + "$N" + CYN+BYEL + "的內力不足以驅動武學連擊。\n" + NOR,me,victim);
      return;
    }
    me->add("force",-20);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    call_out("sunmoon8",1,me,victim,sp_value); //max=245
  }
  else
  {
    message_vision(HBRED + "$N藉由昊陽競月殺陣，再次對$n發動強勁的攻勢。\n" + NOR,me,victim);
    victim->receive_wound("kee",sp_value,me); //dam=245
    COMBAT_D->report_status(victim,1);
    if(me && me->query("force") < 20) {
      message_vision(CYN+BYEL + "$N" + CYN+BYEL + "的內力不足以驅動武學連擊。\n" + NOR,me,victim);
      return;
    }
    me->add("force",-20);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
  }
}

int sunmoon8(object me, object victim, int sunmoon)
{
  if(!me || !victim || me->query("force") < 50) return 1;
  else
  {
    int n,k;
    me->add("force",-50);
    sp_value =8*(str+cor)+cps+kar+spi+int1; //max=8*(35+35)+35+35+35+35=700
    if(me->query_temp("sun-moon")==1) sp_value=sp_value/2; //max=350
    n = victim->query_temp("sword");
    if (per <25)
      sunmoon = sunmoon-random(victim->query("dodge")/3); //假設為245(來自sunmoon7)-120/3=205
    else
      sunmoon = sunmoon-random(victim->query("dodge")/5); //假設為245(來自sunmoon7)-120/5=221
    if(environment(victim) && victim->query_temp("sword")>=1 &&me->is_fighting())
    {
      if (sunmoon <= 0)
      {
        victim->delete_temp("sword");
        message_vision(RED + "$n" + RED + "耗盡真氣真氣抵擋日月絕學的殺招。\n" + NOR,me,victim);
        return 1;
      }
      if(victim->query_temp("sword"))
      {
        switch(random(n)+1)
        {
          case 1: //基本case
            message_vision(HIG + "    $N" + HIG + "頓時領悟日月絕學之精髓配合身上昊陽競月心法使出日月絕學奧義後三式。\n" + NOR,me,victim);
            message_vision(HIG + "       $N" + HIG + "發動日月絕學奧義之第一式〒"+HIY + "開 天 闢 地 ═ 日 光 月 影"+HIG + "〒。\n" + NOR,me,victim);
            message_vision(HIR + "  $N" + HIR + "左手持劍，口中唸了幾個劍訣，只見一道劍芒由右手掌心竄出，瞬間日月黯淡無光！\n" + NOR,me,victim);
            message_vision(HIR + "  轉眼間$N" + HIR + "之氣息完全消失，$n" + HIR + "一個不留神，$N" + HIR + "以雙手握劍之姿虎視眈眈的出現在$n" + HIR + "身後！\n" + NOR,me,victim);
            victim->receive_wound("kee",sp_value+130,me); //dam=350+130=480
            COMBAT_D->report_status(victim,1);
            victim->start_busy(1);
            if(me && me->query("force") < 20) {
              message_vision(CYN+BYEL + "$N" + CYN+BYEL + "的內力不足以驅動武學連擊。\n" + NOR,me,victim);
              return;
            }
            me->add("force",-20);
            COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
            call_out("sunmoon8",1,me,victim,sunmoon);
            break;
          case 2: //容貌一般 加上no_power
            message_vision(HIG + "    $N" + HIG + "頓時領悟日月絕學之精髓配合身上昊陽競月心法使出日月絕學奧義後三式。\n" + NOR,me,victim);
            message_vision(HIG + "       $N" + HIG + "發動日月絕學奧義之第二式〒"+HIW + "昊 陽 震 宇 ═ 覆 月 無 垠"+HIG + "〒。\n" + NOR,me,victim);
            message_vision(HIY + "  $N" + HIY + "大喝一聲，發動身上日月氣勁牽動艷陽昊氣，並藉由艷陽昊氣對$n" + HIY + "發動無情的攻擊！\n" + NOR,me,victim);
            victim->receive_wound("kee",sp_value+130,me); //dam=350+130=480
            victim->set_temp("no_power",1);
            victim->apply_condition("no_power",2);
            COMBAT_D->report_status(victim,1);
            if(me && me->query("force") < 20) {
              message_vision(CYN+BYEL + "$N" + CYN+BYEL + "的內力不足以驅動武學連擊。\n" + NOR,me,victim);
              return;
            }
            me->add("force",-20);
            COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
            call_out("sunmoon8",1,me,victim,sunmoon);
            break;
          case 3: //解quest 後習得 加上連擊&busy(1)
            message_vision(HIG + "    $N" + HIG + "頓時領悟日月絕學之精髓配合身上昊陽競月心法使出日月絕學奧義後三式。\n" + NOR,me,victim);
            message_vision(HIY + "       $N" + HIY + "將天上艷陽皓月兩股至陰至陽之氣吸納入體內，只聽$N" + HIY + "大喊
"+HBCYN + " 昊    。    陽    。    競    。    月    。    破    。    蒼    。    芎！\n" + NOR,me,victim);
            message_vision(HIR + "    $N" + HIR + "發動日月絕學奧義後三式之絕命必殺式〒"+HIW + "長 日 高 掛 ═ 月 下 無 敵"+HIR + "〒。\n" + NOR,me,victim);
            message_vision(HIR + "  $N" + HIR + "將手上長劍收進劍鞘，雙眼泛紅，口中振振有詞，瞬間無數劍芒由$N" + HIR + "身上竄出，劍芒耀眼直逼日月！！\n" + NOR,me,victim);
            message_vision(HIY + "  $n" + HIY + "眼見如此光景..臉色慘白，就在此瞬間$N" + HIY + "帶著劍芒殺陣已迅速逼近$n" + HIY + "！\n" + NOR,me,victim);
            victim->receive_wound("kee",sp_value+200,me); //dam=350+200=550
            COMBAT_D->report_status(victim,1);
            if(me->query("force") < 120) {
              message_vision(CYN+BYEL + "$N" + CYN+BYEL + "的內力不足以驅動武學連擊。\n" + NOR,me,victim);
              return;
            }
            me->add("force",-120); //包含下方的代價
            COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
            for(k=0;k<5;k++)
            {
              COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
            }
            victim->set_temp("no_power",1);
            victim->apply_condition("no_power",2);
            victim->start_busy(2);
            call_out("sunmoon8",1,me,victim,sunmoon);
            break;
        }
      }
    }
    else victim->delete_temp("sword");
  }
}

string perform_action_file(string action)
{
  return CLASS_D("swordsman")+"/sun_moon_sword/"+action;
}
