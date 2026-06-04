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
([ "action":"$N素手一拈﹐起手式" + HIR + "『穿針引線』" + NOR + "手中$w緩緩劃出，輕輕鬆鬆向$n刺去!!",
        "dodge": -70,
        "parry": -70,
        "damage": 60,
        "force": 100,
        "damage_type":  "刺傷",
        "post_action":                (: sp1 :),
]),
//2
([ "action":"$N一招" + HIC + "『補補綴綴』" + NOR + "手中$w去勢無定﹐不知要刺向$n何處，難以捉摸!!",
        "dodge": -40,
        "parry": -15,
        "damage": 100,
        "force": 90,
        "damage_type": "刺傷",
        "post_action":                (: sp2 :),
]),
//3
([ "action":"$N舞姿嫚妙﹐舞出" + HIM + "『針黹黻黼』" + NOR + "渾身放出一股魔力，誘使$n自投羅網!!",
        "dodge": -40,
        "parry": -40,
        "damage": 80,
        "force":  100,
        "damage_type":  "刺傷",
        "post_action":                (: sp3 :),
]),
//4
([ "action":"$N窺準一個空隙，使出" + HIC + "『風起雲湧刺』" + NOR + "激起風雷之聲向$n$l全力刺去!!",
        "dodge": -50,
        "parry": -30,
        "damage": 90,
        "force": 150,
        "damage_type": "刺傷",
        "post_action":                (: sp4 :),
]),
//5
([ "action":"$N面帶媚笑，使出" + HIB + "『針繡鴦鴦雙相依』" + NOR + "一針一線溫柔的朝$n遍身縫去!!",
        "dodge": -35,
        "parry": -20,
        "damage": 90,
        "force": 120,
        "damage_type": "刺傷",
        "post_action":                (: sp5 :),
]),
//6
([ "action":"$N率意而施, 一招" + HIR + "『潑墨一葦織』" + NOR + "射出了千百道針氣欲將$n罩於其下!!",
        "dodge": -50,
        "parry": -30,
        "damage": 95,
        "force": 120,
        "damage_type": "刺傷",
        "post_action":                (: sp6 :),
]),
//7
([ "action":"$N憶起傷心往事﹐以情御" + HIM + "『寫意粗石針』" + NOR + "以必死的氣勢向$n快速衝去!!",
        "dodge": -30,
        "parry": -20,
        "damage": 95,
        "force":  130,
        "damage_type":  "刺傷",
        "post_action":                (: sp7 :),
]),
//8
([ "action":"$N提氣輕身，" + HIR + "『急針亂穿線』" + NOR + "，織出一片漫天針網，緊緊地將$n裹住!!",
        "dodge": -50,
        "parry": -20,
        "damage": 95,
        "force": 160,
        "damage_type":	"刺傷",
        "post_action":                (: sp8 :),
]),
//9
([ "action":"$N內勁流轉﹐" + HIC + "『密刺亂雨繡』" + NOR + "，一時漫天針影，針氣濔漫不住地往$n逼攻而去!!",
        "dodge": -30,
        "parry": -20,
        "damage": 95,
        "force": 160,
        "damage_type":  "刺傷",
        "post_action":                (: sp9 :),
]),
//10
([ "action":"$N身形一緩，" + HIB + "『慧針續斷情』" + NOR + "，全身不帶一絲殺意，柔柔地朝$n飄去!!",
        "dodge": -50,
        "parry": -70,
        "damage": 95,
        "force": 160,
        "damage_type":	"刺傷",
        "post_action":                (: sp10 :),
]),
//11
([ "action":"$N內勁流轉，狂亂技" + HIM + "『神針亂繡』" + NOR + "，化為千萬，氣勁漫空揮灑全往$n直攻而去!!",
        "parry": -70,
        "damage": 150,
        "dodge": -70,
        "force": 150,
        "damage_type":  "刺傷",
        "post_action" :  (: sp11 :),
]),
//12
([ "action":HIC + "$N身形急轉，針法隨身形愈使愈快，" + HIM + "『 " + HBRED+HIY + "～靈 轉 絕 情 針～" + NOR+HIM + " 』" + HIC + "在靈氣和針法相互配合下向$n" + HIC + "急刺而去!!" + NOR,
        "parry": -70,
        "damage": 150,
        "dodge": -90,
        "force": 200,
        "damage_type":  "刺傷",
        "post_action" :  (: sp12 :),
]),
//13
([ "action":HIC + "$N" + HIC + "靈氣流轉，靈力不斷升高之際，一招" + HIW + "『 ～ " + HIY + "幻" + HIM + "靈" + HIC + "七" + HIG + "訣" + HIR + "針" + HIW + " ～ 』" + HIC + "揚手而起，一時靈光四起!!" + NOR,
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
	magic = (me->query_skill("magic"));
	stabber = (me->query_skill("stabber"));
	tim = (me->query_function("magicpower")/10);

	me->add("mapower",random(2)+1);
	if( !ob = present("puppet",me)  )
	{
	  if ( damage = 0 ) 
	  {
	  message_vision("$N一擊不中,順勢一個側身跨步, 閃到$n身側, 反手併指成錐, 一個鶴嘴狠狠啄中$n心窩 !\n", me,victim);
	  victim->receive_wound("kee", stabber);
	  }else{
	  message_vision("$N一擊得手, 趁$n心神不定之時, 悄悄暗施如絲" + HIC + "斷續勁" + NOR + "牽制$n的動作!!\n", me, victim);
	  victim->start_busy(random(2)+1);
	  }   
	}else{
	message_vision(HIM + "魔偶娃娃" + NOR + "受$N靈力驅動, 飛離而出, 直奔$n身前, 一口咬向$n頸側, 嚇的$n魂飛魄散 !\n", me,victim);
	victim->receive_wound("kee",magic*tim);   
	victim->receive_wound("gin",magic);
	victim->receive_wound("sen",magic);
	victim->start_busy(random(2)+1); 
	}
}

void sp2(object me, object victim, object weapon, int damage)
{
	int magic,stabber,exp,ena,mam,spi,fsk,tim;

	stabber = (me->query_skill("stabber"));
	tim = (me->query_function("magicpower")/10);

	me->add("mapower",random(2)+1);
	if (me->query("combat_exp") > random(1200000) && damage = 0 ) 
	{
	message_vision("$n被$N如雨般的攻勢所惑, 楞了一楞, $N到見機不可失, 順勢再加一擊 !\n", me,victim); 
	victim->receive_damage("kee", stabber*tim);
	}
}

void sp3(object me, object victim, object weapon, int damage)
{
	int magic,stabber,exp,ena,mam,spi,fsk,tim;

	stabber = (me->query_skill("stabber"));
	tim = (me->query_function("magicpower")/10);

	me->add("mapower",random(2)+1);
	if (me->query("combat_exp") > random(1200000) && damage = 0 ) 
	{
	message_vision("$N暗使迴勁將手中武器射出, 噗的一聲在$n身上刺出了一個血肉模糊的血窟窿 !\n",me,victim);
	victim->receive_damage("kee", stabber*tim);
	}else{
	message_vision("$N暗使迴勁將手中武器射出, 可惜被$n發現, 閃了過去, 只輕輕的劃過皮肉!!\n",me,victim);
	victim->receive_damage("kee", stabber);
	}
}

void sp4(object me, object victim, object weapon, int damage)
{
	int magic,stabber,exp,ena,mam,spi,fsk,tim;
//	me=this_player();

	mam = (me->query_skill("mamagic"));
	spi = (me->query_spi());
	tim = (me->query_function("magicpower")/10);

	me->add("mapower",random(2)+1);
	if( me->query_temp("ma-needle") == 1 )
	{
	  if( random(mam) > random(500) )
	  {
	  message_vision(HIG + "$N手中"+weapon->name()+"" + HIG + "感受到$N的靈性與法力, 不住震動, 忽然泛閃紅光, 自$N手上如電脫手飛向天際\n" + NOR,me,victim);
	  message_vision(HIY + "$N的"+weapon->name()+"" + HIY + "吸蝕了$N的精血, 喚醒隱伏其中的龍魂, 只見東方飛來一頭巨獸, 振翅聲有如雷響 !\n" + NOR,me,victim);
	  message_vision(HIG + "$N竟喚來了隱伏於極東的龍王" + HIY + "ㄧ" + HIG + "吐出來自宇宙的巨燄" + HIR + "" + HIW + "消滅了眼前一切 !\n" + NOR,me,victim);
	  victim->receive_wound("kee", 3000);
	  victim->apply_condition("burn", random(tim)+10);
	  COMBAT_D->report_status(victim);
	  }else{
	  message_vision(HIR + "$N手中"+weapon->name()+"" + HIR + "吸蝕了$N的精血, 喚醒了隱伏其中的龍魂, 登時風雲變色, 火龍再現!\n" + NOR,me,victim); 
	  message_vision(HIR + "甦醒的火龍狂性大發, 不住向四方噴火, 燒燬了每一件物, 焦臭味四起, 令人作嘔 !\n" + NOR,me,victim);
	  victim->receive_wound("kee", 2000 );
	  victim->apply_condition("burn", random(tim)+5);
	  COMBAT_D->report_status(victim);
	  }
	}else{
	message_vision("$n被$N手中發出的風雷之聲所攝, 獃立當地, 完全不曉閃避, 被$N趁機急速一擊命中 !\n",me,victim);  
	victim->apply_condition("burn", random(2)+3);
	victim->receive_wound("kee", tim*(5*spi) );
	}
}

void sp5(object me, object victim, object weapon, int damage)
{
	int magic,stabber,exp,ena,mam,spi,fsk,tim;

	magic = (me->query_skill("magic"));
	mam = (me->query_skill("mamagic"));
	tim = (me->query_function("magicpower")/10);

	me->add("mapower",random(3)+1);
	if(me->query_temp("ma-needle") == 1)
	{
	  if ( random(mam) > random(200) )
	  {
	  message_vision(HIC + "$N將自身的靈力法力注入"+weapon->name()+"" + HIC + ", 奉獻給天神, 請求水神宓妃現身幫助 !!\n" + NOR,me,victim);
	  message_vision(HIB + "空氣間忽然無端端起了個漩渦, 將$n深陷於中, 轉得昏頭轉向,不知東南西北 !\n" + NOR,me,victim);
	  victim->start_busy(1);
	  victim->receive_damage("sen",magic);
	  victim->receive_damage("gin",magic);
	  victim->receive_damage("kee",tim*magic);
	  }else{
	  message_vision(""+weapon->name()+"" + NOR + "受到$N內力激發, 泛出了一片淡藍色的" + HIB + "情霧" + NOR + "遮斷了$n的五覺 !\n",me,victim);
	  victim->start_busy(1);
	  }
	}else{
	message_vision("$N以無限的情意圍繞著$n, 看來$n已深深的沉醉在其中了!!\n",me,victim);
	victim->start_busy(1);
	}
}

void sp6(object me, object victim, object weapon, int damage)
{
	int magic,stabber,exp,ena,mam,spi,fsk,tim;

	mam = (me->query_skill("mamagic"));
	fsk = (me->query_skill("force"));
	tim = (me->query_function("magicpower")/10);

	me->add("mapower",random(3)+1);
        if(me->query_temp("ma-needle") == 1)
        {
          if ( random(mam) > random(200) )
          {
          message_vision(HIC + "$N手中"+weapon->name()+"" + HIC + "受$N內力催使, 裂成千萬淡藍晶片, 飛散於空中, 氣溫急劇下降 !\n" + NOR,me,victim);
          message_vision(HIC + "飛散於空中的千萬晶片在$N的內力御駕下, 開始流轉成圈, 形成鑽石塵爆收縮 !\n" + NOR,me,victim);
          message_vision(HIR + "$n被晶片圍擊, 瞬間已被擊中數千下, 只見冰屑血沫齊飛, 連血液也凝結成冰 !\n" + NOR,me,victim);
          victim->receive_wound("kee", tim*10+fsk);
          victim->apply_condition("freeze", random(5)+5);
          victim->start_busy(1);
          COMBAT_D->report_status(victim);
          }else{
          message_vision(""+weapon->name()+"" + NOR + "感受到$N的法力, 將空氣中的水氣凝結成冰, 急速落下對$n進行攻擊 !\n",me,victim);
          victim->receive_damage("kee", fsk);
          victim->apply_condition("freeze", random(3)+3);
          COMBAT_D->report_status(victim);
          }
        }else{
        message_vision("$N攻擊時帶起的勁風未消, 有如利刃般在$n身上割出了幾道約莫半尺的傷口 !\n",me,victim);
        victim->receive_damage("kee", fsk);
        victim->apply_condition("freeze", random(1)+1);
        COMBAT_D->report_status(victim);
        }
}


void sp7(object me, object victim, object weapon, int damage)
{
	int magic,stabber,exp,ena,mam,spi,fsk,tim;

	spi = (me->query_spi());
	tim = (me->query_function("magicpower")/10);

	me->add("mapower",random(3)+1);
        if (me->query("combat_exp",1) > 1000000 && random(me->query_spi())>15 )
        {
        message_vision("$N情緒激動難以自制, 竟不顧己身安危, 捨身全力向$n撞去 ! $n被這一撞, 吐了一口鮮血 !\n",me,victim);
        victim->receive_damage("kee",tim*spi);
        COMBAT_D->report_status(victim);
        }else{
        message_vision("$n被$N這股勢死的氣勢所攝，目瞪口呆，傻傻的站著，完全忘了要閃躲$N的攻擊。 \n", me, victim);
        victim->receive_damage("kee",tim+(3*spi));
        victim->start_busy(1);
        }
}

void sp8(object me, object victim, object weapon, int damage)
{
	int magic,stabber,exp,ena,mam,spi,fsk,tim;

	stabber = (me->query_skill("stabber"));
	tim = (me->query_function("magicpower")/10);

	me->add("mapower",random(3)+1);
        if(me->query_temp("ma-needle") == 1)
        {
        message_vision("$N手握"+weapon->name()+"指指點點, 凝氣成鑣, 射出" + HIG + "七星奪命鑣" + NOR + "連取$n七處要害\n",me,victim);
        message_vision("\t\t" + HIC + "★" + HIW + "≡≡≡" + HIC + "★" + HIW + "≡≡≡\n" + NOR,me,victim);
        message_vision("\t      " + HIC + "★" + HIW + "≡≡≡      " + HIC + "★" + HIW + "≡≡≡\n" + NOR,me,victim);
        message_vision("\t\t\t\t" + HIC + "★" + HIW + "≡≡≡" + HIC + "★" + HIW + "≡≡≡" + HIC + "★" + HIW + "≡≡≡\n" + NOR,me,victim);
        message_vision("$n被氣鑣所發出耀眼的光茫所惑閃躲不及, 連被打中七下, 鮮血淋漓, 有生命垂危之憂 !\n",me,victim);
        victim->receive_wound("kee", 3*stabber);
        COMBAT_D->report_status(victim, 1);
        }else{
        message_vision(HIR + "$N暗暗散出數條無形氣勁向$n飛去，偷偷的射中了$n, 造成了數個不小的瘡口！\n" + NOR ,me,victim);
        victim->receive_damage("kee",stabber);
        COMBAT_D->report_status(victim, 1);
        }
}

void sp9(object me, object victim, object weapon, int damage)
{
	int magic,stabber,exp,ena,mam,spi,fsk,tim;

	stabber = (me->query_skill("stabber"));
	tim = (me->query_function("magicpower")/10);

	me->add("mapower",random(3)+1);
        if ((me->query_spi()>random(40))&&(me->query("combat_exp",1)> 1200000))
        {
        message_vision(HIW + "$N密針亂繡, 有如化身成千手觀音, 在身前聚成一顆閃亮的電光球, 向$n砸去 !!\n" + NOR,me,victim);
        message_vision(HIR + "光球在$n面前猛然爆開, 千萬針氣化電氣在$n各處要害對穿而出 ,鮮血濺了一地!!\n" + NOR,me,victim);
        victim->receive_damage("kee",3*stabber);
        victim->apply_condition("thunder", random(3)+3);
        COMBAT_D->report_status(victim, 1);
        }else{
        message_vision("$N手中指指點點猶帶電勁, 以迅雷不及掩耳之速在$n正面各處柔軟要害猛力扎了一下 !!\n",me,victim);
        victim->receive_damage("kee",stabber);
        victim->apply_condition("thunder", random(1)+1);
        COMBAT_D->report_status(victim, 1);
        }
}

void sp10(object me, object victim, object weapon, int damage)
{

	me->add("mapower",random(3)+1);
        if( me->query_per() > random(125) )
        {
        message_vision(HIB + "$n被你媚惑之術中的迷魂法所惑, 氣血逆流, 失神落魄, 不知所措 !!\n" + NOR,me,victim);
        victim->apply_condition("misforce", random(4)+3);
        message_vision(HIW + "$n一時經脈走岔因而氣血逆流, 全身內息不受控制, 四處亂竄, 已然走火入魔 !!\n" + NOR,me,victim);
		  if( victim->query_busy() < 2 )
          victim->start_busy(1);
        }else{
        message_vision("$n被你溫柔情意所惑, 氣血逆行, 走火入魔, 猛吐了一口瘀血 !!\n",me,victim);
        victim->apply_condition("misforce", random(2)+1);
        }
}

void sp11(object me, object victim, object weapon, int damage)
{
	int magic,stabber,exp,ena,mam,spi,tim;

	stabber = (me->query_skill("stabber"));

	me->add("mapower",random(3)+1);
	if (damage > 0)
	{
	int val;
	val = (me->query_per()/2);
	  if (random(stabber+val) > 85 ) 
      {
      message_vision("$N素手一拈﹐起手式" + HIR + "『穿針引線』" + NOR + "手緩緩劃出，輕輕鬆鬆向$n要害刺去, 刺中$n左腿 ! \n",me,victim);
      victim->receive_wound("kee",stabber/5 );
      COMBAT_D->report_status(victim, 1);
      }
      if (random(stabber+val) > 90 ) 
      {
      message_vision("$N舞姿嫚妙﹐舞出" + HIM + "『針黹黻黼』" + NOR + "渾身放出一股魔力，誘使$n自投羅網 ,撞上$N武器 !\n",me,victim);
      victim->receive_wound("kee",stabber/4 );
      COMBAT_D->report_status(victim, 1);
      }
      if (random(stabber+val) > 95 ) 
      {
      message_vision("$N窺準一個空隙，使出" + HIC + "『風起雲湧刺』" + NOR + "激起風雷之聲向$n全力刺去, 命中$n右手 !\n",me,victim); 
      victim->receive_wound("kee",stabber/3 );
      COMBAT_D->report_status(victim, 1);
      }
      if (random(stabber+val) > 100 ) 
      {
      message_vision("$N面帶媚笑，使出" + HIB + "『針繡鴦鴦雙相依』" + NOR + "一針一線溫柔的朝$n遍身縫去,織的$n遍體鱗傷 !\n",me,victim);
      victim->receive_wound("kee",stabber/2 );
      COMBAT_D->report_status(victim, 1);
      }
      if (random(stabber+val) > 105 ) 
      {
      message_vision("$N率意而施, 一招" + HIR + "『潑墨一葦織』" + NOR + "射出了千百道針氣將$n罩於其下, 射出千百瘡口 !\n",me,victim);
      victim->receive_wound("kee",stabber );
      COMBAT_D->report_status(victim, 1);
      }
      if (random(stabber+val) > 110 ) 
      {
      message_vision("$N提氣輕身，" + HIR + "『急針亂穿線』" + NOR + "，織出一片漫天針網，緊緊地將$n裹住, 留下無數傷口 !\n",me,victim);
      victim->receive_wound("kee",stabber*12/10 );
      COMBAT_D->report_status(victim, 1); 
      } 
      if (random(stabber+val) > 115 ) 
      {
      message_vision("$N內勁流轉﹐" + HIC + "『密刺亂雨繡』" + NOR + "，一時滿天針影，氣勁漫空全往$n而去, $n哀嚎不斷 !\n",me,victim);
      victim->receive_wound("kee",stabber*13/10 );
      COMBAT_D->report_status(victim, 1);
      }
      if (random(stabber+val) > 120 ) 
      {
      message_vision("$N身形一緩，" + HIB + "『慧針續斷情』" + NOR + "，全身不帶一絲殺意，柔柔地朝$n飄去, 輕輕的傷了$n !\n",me,victim);
      victim->receive_wound("kee",stabber*14/10 );
      COMBAT_D->report_status(victim, 1);
      }
      if (random(stabber+val) > 125 ) 
      {
      message_vision("$N身形急轉，針法隨身形愈使愈快，" + HIM + "『靈轉絕情針』" + NOR + "在靈氣和針法相互配合下向$n急刺而去!!\n",me,victim);
      victim->receive_wound("kee",stabber*15/10 );
      COMBAT_D->report_status(victim, 1);
	  }
	}
	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}

void sp12(object me, object victim, object weapon, int damage)
{
	object *enemy;
	int i,j,pow,ext,magic,stabber,exp,ena,mam,spi,fsk,tim;
	magic = (me->query_skill("magic"));
	stabber = (me->query_skill("stabber"));
	exp = (me->query("combat_exp")/10000);
	ena = (me->query("atman_factor"));
	mam = (me->query_skill("mamagic"));
	spi = (me->query_spi());
	fsk = (me->query_skill("force"));
	tim = (me->query_function("magicpower")/10);
	ext = (me->query("combat_exp")/1000000);

	me->add("mapower",random(5)+2);

	if( interactive(victim) )
	{
	pow=((mam+ena+exp+tim)/80);
	}else{
	pow=((mam+ena+exp+stabber+spi+fsk+magic+tim)/10);
	}

	enemy = me->query_enemy();
	for(i=0; i<sizeof(enemy); i++)
	{
	  if( !enemy[i] )	continue;
	  for( j=0; j < tim; j++ )
	  {
	    if(enemy[i]->query("kee") > 0 && random(me->query("combat_exp")*ext) > random(enemy[i]->query("combat_exp")))
	    {
        enemy[i]->receive_wound("kee",pow);
	    enemy[i]->receive_wound("gin",pow);
	    enemy[i]->receive_wound("sen",pow);
        COMBAT_D->report_status(enemy[i]);
	    }else{
        enemy[i]->receive_wound("kee",pow/2);
	    enemy[i]->receive_wound("gin",pow/2);
	    enemy[i]->receive_wound("sen",pow/2);
        COMBAT_D->report_status(enemy[i]);
	    }
	  }
	  if( enemy[i]->query_busy() < 2 )
	  enemy[i]->start_busy(1);

	}
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}

void seven(object me, object victim,object weapon, int damage)
{
	object *enemy;
	int i,j,dam,tsk,ext,hit,magic,stabber,exp,ena,mam,spi,fsk,tim;
	enemy = me->query_enemy();

	magic = (me->query_skill("magic"));
	stabber = (me->query_skill("stabber"));
	exp = (me->query("combat_exp")/10000);
	ena = (me->query("atman_factor"));
	mam = (me->query_skill("mamagic"));
	spi = (me->query_spi());
	fsk = (me->query_skill("force"));
	ext = (me->query("combat_exp")/1000000);
	hit = (me->query_function("magicpower")/5);
	ext = (me->query("combat_exp")/1000000);
	tsk = (victim->query("combat_exp")/500000);

	if( interactive(victim) )
	{
	dam = ((mam+ena+exp+hit)/(80+tsk));
	}else{
	dam = ((mam+ena+exp+stabber+spi+fsk+hit)/10);
	}

	if( ext < 2 )	ext = 1;
	if( ext > 7 )	ext = 7;
	if( tsk < 1 )	tsk = 1;

	me->add("mapower",random(5)+2);

	if ( random(45) > 10 )
	{
	message_vision(sprintf(HIM + "
　　　　靈 － 光 － 隨 － 手 － 起" + HIY + "◎" + HIM + "靈 － 針 － 幻 － 七 － 式
	\n" + NOR),me,victim );
	victim->receive_wound("kee",(dam*tsk));
	  for(i=0;i<=ext;i++)
	  {
	  switch(i)
	  {
		case 1 :
		message_vision(HIC + "
	      ..    ..                        ..    .. 
	      '\\    /'                        '\\    /'
	        \\\\//                            \\\\//      
	   _.__\\\\\\///__._" + HBBLU+HIC + "☆靈引星移幻無邊☆" + NOR+HIC + "_.__\\\\\\///__._ 
	    '  ///\\\\\\  '                    '  ///\\\\\\  ' 
	        //\\\\                            //\\\\     
	      ./    \\.                        ./    \\.    
	      ''    ''                        ''    ''  
		\n" + NOR,me,victim);
	  break;
        	case 2 :
		message_vision(HIY + "
	       x  .  x                        x  .  x
	     . _\\/ \\/_ .                    . _\\/ \\/_ .
	      \\  \\ /  /                      \\  \\ /  /    
	    -==>: X :<==-" + HBGRN+HIY + "☆靈生四像幻無常☆" + NOR+HIY + "-==>: X :<==-  
	      / _/ \\_ \\                      / _/ \\_ \\   
	     '  /\\ /\\  '                    '  /\\ /\\  ' 
	       x  '  x                        x  '  x 
		\n" + NOR,me,victim);

         break;
		case 3 :
		message_vision(HIR + "
	      .      .                        .      .
	      _\\/  \\/_                        _\\/  \\/_
	       _\\/\\/_                          _\\/\\/_
	   _\\_\\_\\/\\/_/_/_" + HBRED+HIR + "☆靈動殘月幻無量☆" + NOR+HIR + "_\\_\\_\\/\\/_/_/_
	    / /_/\\/\\_\\ \\                    / /_/\\/\\_\\ \\
	       _/\\/\\_                          _/\\/\\_
	       /\\  /\\                          /\\  /\\
	      '      '                        '      '
		\n" + NOR,me,victim);

          break;
		case 4 :
		message_vision(HIG + "
	       _    _                          _    _ 
	      /_/  \\_\\                        /_/  \\_\\ 
	        \\\\//                            \\\\//    
	    /\\_\\\\><//_/\\ " + HBYEL+HIG + "☆靈滅眾生幻無悲☆" + NOR+HIG + " /\\_\\\\><//_/\\
	    \\/ //><\\\\ \\/                    \\/ //><\\\\ \\/
	       _//\\\\_                          _//\\\\_
	      \\_\\  /_/                        \\_\\  /_/
		\n" + NOR,me,victim);

          break;
		case 5 :
		message_vision(HIB + "
	          .                              .       
	          :                              :       
	    '.___/x\\___.'                  '.___/x\\___.' 
	      \\x \\ / x/                      \\x \\ / x/    
	       >--X--<   " + HBCYN+HIB + "☆靈成魑魅幻無形☆" + NOR+HIB + "   >--X--<
	      /x_/ \\_x\\                      /x_/ \\_x\\
	    .'   \\x/   '.                  .'   \\x/   '.
	          :                              :
	          '                              '
		\n" + NOR,me,victim);

          break;
		case 6 :
		message_vision(HIM + "
	      ._    _.                        ._    _.   
	      (_)  (_)                        (_)  (_)   
	       .\\::/.                          .\\::/.    
	   _.=._\\\\//_.=._" + HBMAG+HIY + "☆靈錯陰陽幻無極☆" + NOR+HIM + "_.=._\\\\//_.=._
	    '=' //\\\\ '='                    '=' //\\\\ '='  
	       '/::\\'                          '/::\\'    
	      (_)  (_)                        (_)  (_)    
	      '      '                        '      ' 
		\n" + NOR,me,victim);

          break;
		case 7 :
		message_vision(HIC + "
	    <> \\  / <>                        <> \\  / <>
	    \\_\\/  \\/_/                        \\_\\/  \\/_/
	       \\\\//                              \\\\//
	 _<>_\\_\\<>/_/_<>_" + HBWHT+HIC + "☆靈亂乾坤幻無定☆" + NOR+HIC + "_<>_\\_\\<>/_/_<>_
	  <> / /<>\\ \\ <>                    <> / /<>\\ \\ <>
	     _ //\\\\ _                          _ //\\\\ _
	    / /\\  /\\ \\                        / /\\  /\\ \\
	    <> /  \\ <>                        <> /  \\ <>
		\n" + NOR,me,victim);

          break;
          }
	    for(j=0;j < sizeof(enemy);j++)
	    {
	    if( !enemy[j] )	continue;
	    message_vision(HIR + "$N的針力蘊含無限靈力向$n" + HIR + "刺去，$n" + HIR + "的生命正一點一滴消散中!!\n" + NOR,me,enemy[j]);
	    enemy[j]->add("kee",-dam*3/2);
	    enemy[j]->add("force",-dam*3);
	    enemy[j]->add("gin",-dam);
	    enemy[j]->add("sen",-dam);
	    enemy[j]->apply_condition("magickee",random(tsk)+10);
		  if( enemy[j]->query_busy() < 2 )
		  enemy[j]->start_busy(1);
	    COMBAT_D->report_status(enemy[j]);
		  if( enemy[j]->query("force") < 0 )
		  {
	      enemy[j]->set("force",0);
	      }
	    }
	  }
	}else{
	message_vision(HIR + "$N只覺靈性不足無法使出幻靈七訣針，一時無法將靈力釋放!!\n" + NOR,me,victim);
	victim->receive_wound("kee",(dam));
	victim->apply_condition("magickee",random(tsk)+10);
	COMBAT_D->report_status(victim,1);
	}
}

mapping query_action(object me, object weapon)
{
	int ski,mai,exi,mau;
	ski = me->query_skill("god-needle",1);
	mai = me->query_skill("mamagic",1);
	exi = me->query("combat_exp",1)/500000;
	mau = me->query_function("magicpower");

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
	else if ( ski >= 150 && mai < 200 && mau < 30 )
		return action [random(12)];
	else if ( ski >= 150 && mai < 300 && mau < 50 )
		return action [random(13)];
	else if ( ski >= 150 && mai < 500 && mau < 100  )
		return action [random(6)+7];
	else if ( ski >= 150 && mai >= 500 && mau >= 100 && (random(mai)+exi > 100) )
		return action [random(3)+10];
	else
		return action [random(13)];

}

int valid_enable(string usage)
{
        if(this_player()->query_skill("god-needle",1) >= 100)
        {
        return (usage=="unarmed"||usage=="stabber")||(usage=="parry");
        }
        return (usage=="stabber")||(usage=="parry");
}

int practice_skill(object me)
{
        if( me->query("kee") < 30 )
        return notify_fail("體力不夠囉,休息一下再繼續練吧.\n");
        me->receive_damage("kee", 30);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("needlegirl")+"/god-needle/"+action;
}

