#include <combat.h>
#include <ansi.h>
void movedown(object me,object target,object weapon,int damage);
inherit SKILL;
mapping *action = ({
// 1
(["action":HIW"$N側身橫鋤，一招"+HIC"「橫雲斷峰」"HIW+"，手持$w"+HIW+"向$n$l橫劈過去。"NOR,
        "damage":       30,
        "dodge":        5,
        "parry":         -5,
        "force":        160,
        "damage_type":  "砍傷",
        ]),
// 2
(["action":HIW"$N翻身迴力，手中$w"+HIW+"斜引，一招"+HIR"「歸雁嘯長空」"HIW+"，刀鋒從半空中直瀉而下。"NOR,
           "damage":           60,
           "dodge":           10,
           "parry":            -10,
           "force":            160,
           "damage_type":  "劈傷"
          ]),
// 3
(["action":HIW"$N背轉身子，一招"+HIB"「夜戰八方」"HIW+"，手中$w"+HIW+"迅無倫比的砍向$n$l。"NOR,
           "damage":      80,
           "dodge":          5,
           "parry":         -10,
           "force":          160,
        "damage_type":  "砍傷"
           ]),
// 4
(["action":HIW"$N使出"+HIM"「春雲乍展」"HIW+"，手中$w"+HIW+"悄無聲的劃向$n$l，看似輕如柳絮，卻是式中套式，招裡藏招。"NOR,
        "damage":          80,
        "dodge":        20,
        "parry":        -20,
        "force":        160,
                "damage_type": "割傷"
            ]),
// 5
(["action":HIW"$N腳尖一點，翩如飛鳥般的躍起一丈多高，使一招"+HIG"「天神倒掛」"HIW+"，由上而下劈往$n的$l。"NOR,
        "damage":    100,
        "dodge":        20,
        "parry":        -20,
        "force":        160,
        "damage_type": "劈傷"
        ]),
// 6
(["action":HIW"$N微一吐勁，力貫刀鋒，一招"+HIY"「劈石開山」"HIW+"往$n$l直劈而下。"NOR,
        "damage":       100,
        "force":        160,
        "parry":        -20,
        "dodge":        10,
        "damage_type": "劈傷"
        ]),
// 7
(["action":HIW"$N刀隨身轉，寒光閃處，一招"+HIC"「倒灑金錢」"HIW+"，攻往$n$l。"NOR,
        "damage":       130,
        "parry":        -10,
        "dodge":        10,
        "force":        160,
        "damage_type": "劈傷"
        ]),
// 8
(["action":HIW"$N氣沉丹田，一招"+HIG"「氣撼九重天」"HIW+"，刀勢籠罩八方，$n頓感氣息翻湧，胸口不暢。"NOR,
        "damage":       130,
        "force":        160,
        "parry":        -10,
        "dodge":        10,
        "post_action":          (: movedown :),
        "damage_type":  "砍傷"
        ]),
// 9
(["action":HIW"$N手中$w"+HIW+"一晃，一招"+HIR"「雪擁籃關」"HIW+"，往$n$l直刺而去。"NOR,
        "damage":       160,
        "force":        160,
        "parry":        -10,
        "dodge":        20,
        "damage_type":  "刺傷"
        ]),
// 10
(["action":HIW"$N移步測身，使出一招"+HIB"「游龍繞步」"HIW+"，身行變化莫測，攻向$n$l。"NOR,
        "damage":       160,
        "dodge":        100,
        "parry":        -20,
        "force":        160,
        "damage_type":  "刺傷"
        ]),
});
int valid_learn(object me)
{
        object ob;
        if( (int)me->query("max_force") < 100)
        return notify_fail("你的內力不夠，沒有辦法練紫金六陽刀法。\n");
        if( (string)me->query_skill_mapped("force")!= "sixforce")
                return notify_fail("紫金六陽刀法必須配合六陽心法才能練。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade")
                return notify_fail("你必須先找一把刀才能練刀法。\n");
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="blade")||(usage=="parry")|| usage == "secondary_blade" || usage == "third_blade";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

void movedown(object me,object target, object weapon,int damage)
{
if(me->query("force")<20) return;
if(70>=random(100)) {
        me->add("force",-20);
        message_vision(
        HIG "$N使出「橫掃六合」，刀光四面舖開，把$n的整個身形籠罩在刀光之下！\n"NOR,me,target);
      message_vision(GRN"結果$n氣息一岔，登時動彈不得！\n"NOR,me,target);
           target->start_busy(1);
          }
           else {
      message_vision(GRN "結果$n往後一躍，躲了過去。\n"NOR,me,target);
}
}

string perform_action_file(string action)
{
if(this_player()->query_skill_mapped("blade")=="gold-blade") {
        return CLASS_D("blademan")+"/gold-blade/"+action;
}
}
