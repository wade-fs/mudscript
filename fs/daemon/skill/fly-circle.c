//飛亂 by bss
//皇城mob專用，不開放
//排版 by blazakira 2011/10/6

#include <ansi.h>
#include <combat.h>
inherit SKILL;

void sp1(object me, object victim, object  weapon, int damage);
void sp2(object me, object victim, object  weapon, int damage);

mapping *action = ({
(["action":
"$N秀腕圈轉，絕技"HIY"「飛亂」"NOR"之"BLINK+HIG"「華落繽紛」"NOR"施起，畫出千朵眩目甚已的綠芒氣旋，
攻向$n，正當$n封住了此招攻勢時，$N不忙不慌，皓腕再扭，左手$w轉了方向，擊向$n腰
部，右手$w則維持原狀，打算硬拼$n。",
        "damage":       300,
        "dodge":        -100,
        "parry":        -100,
        "force":        300,
        "damage_type" : "擊傷",
        "post_action":  (:call_other,__FILE__,"damage_weapon":),
]),
(["action":
"$N將$w抽回，轉身，左手$w下壓，右手$w去徒然離手旋飛，舞繞於浮空中的碧綠光暈，迷
濛濛的罩向$n眼前，正是"HIY"「飛亂」"NOR"之"BLINK+HIR"「碧華千炫」"NOR"，$n連忙收腿，閃過$w的下擊，
$N的臉上浮現了一絲微笑，左手$w趁著右手$w矇蔽$n的雙目時，有如電光火石般的飄砸$n。",
        "damage":       300,
        "dodge":        -100,
        "parry":        -100,
        "force":        300,
        "damage_type" : "砸傷",
        "post_action":  (:call_other,__FILE__,"damage_weapon":),
]),
(["action":
"$N臉色肅然，手中$w貫入強勁真氣，使出"HIY"「飛亂」"NOR"之"BLINK+HIB"「飛璧擲亂」"NOR"兩手$w離手飛出，灑出滿天碧綠的光輝，
$N的一對$w像爭逐花蜜般的狂蜂浪蝶滿天遊走，發出刺耳的呼嘯聲，忽現忽隱，時遠時近，
有時若來自九天之外，有時則似有十八層地獄最底的一層傳上來，使$n覺得自己身在虛無飄渺
的環境，竟完全的忘記了要閃躲這從天而降的一擊。",
        "damage":       300,
        "dodge":        -100,
        "parry":        -100,
        "force":        300,
        "damage_type" : "砸傷",
        "post_action":  (:call_other,__FILE__,"damage_weapon":),
        "post_action":  (:sp1:),
]),
(["action":
"$N雙手作出了一個曼妙無比的姿勢，往上一翹，立時多出了一對直徑約尺半的$w，來自無
方，像隔空取物般突然又奇怪的出現，$w交擊，發出使人神搖魄蕩的一擊後，$w像有靈性的
分左右發出，以驚人的速度繞著圈，向$n攻去，正是"HIY"「飛亂」"NOR"之"BLINK+HIC"「華芒萬丈」"NOR"，
同時$N兩掌像一對追逐嘻戲的蝴蝶般，在美麗的酥胸前幻化出妙相紛呈的嬌姿美態。",
        "damage":       300,
        "dodge":        -100,
        "parry":        -100,
        "force":        300,
        "damage_type" : "砸傷",
        "post_action":  (:call_other,__FILE__,"damage_weapon":),
        "post_action":  (:sp2:),
  ]),
});

int valid_learn(object me)
{
  return 1;
}

int valid_enable(string usage)
{
  return (usage=="dagger");
}

mapping query_action(object me, object weapon)
{
  return action[random(sizeof(action))];
}

void sp1(object me, object victim, object  weapon, int damage)
{
  int skill= me->query_skill("fly-circle", 1);
  if(70 > random(100))
  {
    message_vision(HIY"$N被$n"HIY"劃破空氣所產生的聲音所影響，失去了反制能力，任人宰割\n"NOR,victim,weapon);
//    COMBAT_D->report_status(victim, 1);
    message_vision(HIR"$N慘被$n"HIR"所擊中，「哇」地一聲吐出了一口鮮血！！！\n"NOR,victim,weapon);
    victim->receive_damage("kee",(skill* 3),me);
    COMBAT_D->report_status(victim);
    victim->start_busy(1);
  }
  else
  {
    message_vision("$N像完全沒有聽到聲音一般，展開身法，躲過了似從天外飛來的$n。\n",victim,weapon);
  }
}

void sp2(object me, object victim, object  weapon, int damage)
{
  int skill= me->query_skill("fly-circle", 1);
  if(90 > random(100))
  {
    message_vision(HIY"\n$N的精神落到$n纖美白析的手上，忽然發現$n正以獨特的手法，使酥胸不斷的高低起浮，\n"+
    "\t$N的眼神被這誘人的景像所吸引，不自覺的陷入了$n的媚術，離死不遠了。\n"NOR,victim,me);
    victim->receive_damage("kee",(skill* 3),me);
    COMBAT_D->report_status(victim);
    victim->start_busy(random(1)+1);
  }
  else
  {
    message_vision("$N完全不理$n所做出的美妙姿態，深深的吸了一口氣，躲過了這致命的一擊。\n",victim,me);
  }
}
