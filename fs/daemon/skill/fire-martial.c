inherit SKILL;
#include <ansi.h>
void sword(object me, object victim, object weapon, int damage);

mapping *action = ({
//1
        (["action":"
        $N手結" + HIW + "『" + HIR + "火神印" + HIW + "』" + NOR + ",手勢迅速的翻化
           猶如數十個手掌各自結出手印

             " + HIW + "$N大喊一聲---" + HIG + "[" + HIR + "火拳" + HIG + "]" + NOR + "
                       " + HIR + "_
                ～～～" + HIR + "(" + HIY + "@" + HIR + ")" + HIR + "
                       ^" + NOR + "
頓時火光乍現,一個小火球從$N的手中延伸出來,飛向$n!\n",
        "dodge":-20,
        "parry":-30,
        "force":200,
        "damage":200,
        "damage_type":"瘀傷",
        ]),
//2
        (["action":"
        $N手結" + HIW + "『" + HIR + "火神印" + HIW + "』" + NOR + ",手勢迅速的翻化
           猶如數十個手掌各自結出手印

             " + HIW + "$N大喊一聲---" + HIG + "[" + HIR + "火焰箭雨" + HIG + "]" + NOR + "
                  " + HIG + ">" + NOR+YEL + "--------" + HIR + ">" + NOR + "
                  " + HIG + ">" + NOR+YEL + "------" + HIY + "@" + NOR+YEL + "-" + HIR + ">" + NOR + "
                  " + HIG + ">" + NOR+YEL + "--------" + HIR + ">" + NOR + "
$N雙手的火焰幻化成數十枝的火焰箭,每一隻火焰箭彷彿
有生命一般的,紛紛飛向$n。\n",
        "dodge":-30,
        "parry":-50,
        "force":400,
        "damage":400,
        "damage_type":"刺傷",
        ]),
//3
        (["action":"
        $N手結" + HIW + "『" + HIR + "火神印" + HIW + "』" + NOR + ",手勢迅速的翻化
           猶如數十個手掌各自結出手印

             " + HIW + "$N大喊一聲---" + HIG + "[" + HIR + "火炮" + HIG + "]" + NOR + "
                        　　　 " + HIR + "＿" + NOR + "
                   " + HIW + "～～～～　" + HIR + "〔" + HIY + "＠" + HIR + "〕" + NOR + "
                   " + HIW + "～～～～" + HIR + "（" + HIY + "＠" + HIC + "※" + HIY + "＠" + HIR + "）" + NOR + "           
                   " + HIW + "～～～～  " + HIR + "〔" + HIY + "＠" + HIR + "〕" + NOR + "
                               " + HIR + "==" + NOR + "
$N身體彷彿被一顆巨大的火球包圍著
突然間,火球飄離了$N的身體急速的衝向$n!!\n",
        "dodge":-50,
        "parry":-50,
        "force":800,
        "damage":800,
        "damage_type":"灼傷",
        ]),
//4
        (["action":"
        $N手結" + HIW + "『" + HIR + "火神印" + HIW + "』" + NOR + ",手勢迅速的翻化
           猶如數十個手掌各自結出手印

             " + HIW + "$N大喊一聲---" + HIG + "[" + HIR + "焰浪" + HIG + "]" + NOR + "
                                 " + HIR + "︵︵︵" + NOR + "
                        " + RED + "～～～ " + HIR + "（" + HIY + "●●●" + HIR + "） " + NOR+RED + "～～～" + NOR + "
                        " + RED + "～～～" + HIR + "（" + HIY + "○" + HIC + "◎◎" + HIY + "○" + HIR + "）" + NOR+RED + "～～～" + NOR + "
                        " + RED + "～～～" + HIR + "（" + HIY + "○" + HIC + "◎◎" + HIY + "○" + HIR + "）" + NOR+RED + "～～～" + NOR + "
                        " + RED + "～～～ " + HIR + "（" + HIY + "●●●" + HIR + "） " + NOR+RED + "～～～" + NOR + "
                                " + HIR + " ︶︶︶" + NOR + "
$N的雙手冒出熊熊的火焰,一股火焰海浪衝出$N的雙手撲向了$n!!\n",
        "dodge":-50,
        "parry":-80,
        "force":1000,
        "damage":1000,
        "damage_type":"灼傷",
        ]),
//5
        (["action":"
        $N手結" + HIW + "『" + HIR + "火神印" + HIW + "』" + NOR + ",手勢迅速的翻化
           猶如數十個手掌各自結出手印

             " + HIW + "$N大喊一聲---" + HIG + "[" + HIR + "火星結界" + HIG + "]" + NOR + "
                                " + HIR + "★
                        　　　★" + HIY + "☆" + HIR + "★
                        　★★" + HIY + "☆☆☆" + HIR + "★★
                        　　★" + HIY + "☆☆☆" + HIR + "★
                        　★ ★" + HIY + "☆☆" + HIR + "★ ★      
                                ★" + NOR + "
$N的雙手在空中繪畫出一個巨大的星型圖,彷彿一顆巨大的燃燒之星
一般,閃耀著亮眼的火光,圍繞在$n的身旁!!\n",
        "dodge":-100,
        "parry":-100,
        "force":1500,
        "damage":1500,
        "damage_type":"灼傷",
        ]),
//6
        (["action":"
        $N手結" + HIW + "『" + HIR + "火神印" + HIW + "』" + NOR + ",手勢迅速的翻化
           猶如數十個手掌各自結出手印

             " + HIW + "$N大喊一聲---" + HIG + "[" + HIR + "火神秘劍" + HIG + "]" + NOR + "

                　" + HIG + "Λ" + HIW + "＿＿＿＿＿＿＿＿＿＿＿＿＿＿
        " + HIW + "⊿" + HIR + "＝＝＝＝" + HIG + "∥" + HIM + "ΩΩΩΩΩΩΩΩΩΩΩΩΩΩ ...
        " + HIY + "﹂" + HIR + "√﹌﹌﹌" + HIG + "∥" + HIM + "ζτζτζτζτζτζτζτ
                　" + HIG + "Ξ" + NOR + "
$N的手掌心中,緩緩的浮現一把火焰之劍...\n",
        "dodge":-100,
        "parry":-100,
        "force":1500,
        "damage":1500,
        "post_action":  (:sword:),
        "damage_type":"灼傷",
        ]),
});

void sword(object me,object victom,object weapon,int damage)
{
int sk=(int)me->query_skill("fire-martial");
        message_vision(HIR + "$N緊握劍柄，劍身四周冒出了魔物正虎視眈眈的看著$n\n\n" + NOR,me,victom);
        message_vision(HIY + "$N突然之間使出" + HIG + "〔" + HIW + "光斬" + HIG + "〕" + HIY + "以迅雷不及掩耳之勢往$n身上砍去。\n\n" + NOR,me,victom);
        if( random(sk) > random(victom->query_skill("dodge")/5) )
        {
                message_vision(HIM + "$N的" + HIG + "[" + HIR + "火神秘劍" + HIG + "]" + HIM + "已經在$n的胸口刺了一道深可見骨的傷口！\n\n" + NOR,me,victom);
                victom->receive_wound("kee",sk);
                COMBAT_D->report_status(victom, 1);
                COMBAT_D->report_status(victom, 1);
                COMBAT_D->report_status(victom, 1);
                for( int i = 1 ; i < 4 ; i++ )
                {
                        message_vision(HIW + "劍光一閃, " + HIG + "[" + HIR + "火神秘劍" + HIG + "]" + HIW + "隨著飛濺的鮮血起舞, 順勢橫劈一刀\n" + NOR,victom);
                        victom->receive_wound("kee",sk/i);
                        COMBAT_D->report_status(victom, 1);
                        COMBAT_D->report_status(victom, 1);
                        COMBAT_D->report_status(victom, 1);
                }
        message_vision(HIC + "\n『咻』的一聲, $N迅速的將" + HIG + "[" + HIR + "火神秘劍" + HIG + "]" + HIC + "收回掌心中!!\n" + NOR,me);
        me->start_busy(1);
        }
   else
    {
        message_vision(
        HIC + "$N一見劍光異常急急忙忙往後跳開, 躲開了這致命的一擊。\n" + NOR,victom);
        me->start_busy(2);
     }
}

int practice_skill(object me)
{
        return notify_fail("此武學無法自我練習。\n");
}

mapping query_action()
{
        return action[random(sizeof(action))];
}

int valid_enable(string usage)
{
        return (usage=="unarmed"||usage=="parry");
}

int valid_learn(object me)
{
        return notify_fail("這項進能無法學習。\n");
}

