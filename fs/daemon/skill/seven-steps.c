// change bye adam..
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
        
"\n$n使出『"HIW"蛇行訣"NOR"』身行一晃，如蛇行般輕靈，滑過$N的身旁，躲過了$N的攻擊！\n",
        
"\n$n使出『"HIG"鶴沖天"NOR"』身形如鶴，飛身沖上雲端，輕易的閃過$N的攻擊！\n",
        
"\n$n施展『"HIM"鷹凌霄"NOR"』$n好比飛鷹，繞著$N身子左盤又旋，兜圈急轉，趁隙發招！\n",
        
"\n$n施展『"HIY"鳳蝶舞"NOR"』把$N的攻勢，借勁一送，結果$N的攻勢如沈入大海一般！\n",
        
"\n$n施展『"HIB"龍吟行"NOR"』氣運單田，發出龍吟氣功\護體，把$N的攻勢，輕易瓦解！\n",
        
"\n$n施展『"HIR"麟蹤火"NOR"』只見$n全身如火焚身般，如火麒麟附體，大顯神威，$N的攻勢完全無用！\n",
        
"\n$n施展『"HIC"虎躍衝"NOR"』$n有如猛虎一般兇猛，動作靈活，結果把$N的攻勢，視若無睹！\n",
});

int valid_enable(string usage) {
        return (usage=="dodge")||(usage=="move");

}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if((int)me->query("kee")<5)
                return notify_fail("你的氣不夠﹐不能練七靈馭風訣 。\n");
        me->receive_wound("kee",5);
        return 1;
}
